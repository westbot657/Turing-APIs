# Turing API Generator
# a magic file that converts the API from rust and generates the API
# for every single other language that's currently supported

import sys, os, re, json
from enum import Enum, auto

LICENSE = "GPL-2.0-only"
AUTHORS = ["Westbot"]

class IMdef:
    def process_macros(self, src:str, macros:list[str], values:list[str]) -> str: ...
    def get_class(self, classname: str): ...
    def get_source(self, mref:str, lang:str) -> None|tuple[str, list[str]]: ...
    def process_from_source(self, mref:str, lang:str, fname:str) -> str: ...

def from_mdef(tp:str, lang:str) -> str:
    match lang:
        case "C" | "C.h":
            match tp:
                case "i32": return "int"
                case "u32": return "unsigned int"
                case "f32": return "float"
                case "str": return "const char*"
                case "bool": return "bool"
                case "void": return "void"
        case "C++" | "C++.h":
            match tp:
                case "i32": return "int"
                case "u32": return "unsigned int"
                case "f32": return "float"
                case "str": return "const char*"
                case "bool": return "bool"
                case "void": return "void"
        case "zig":
            match tp:
                case "i32": return "i32"
                case "u32": return "u32"
                case "f32": return "f32"
                case "str": return "[*:0]const u8"
                case "bool": return "bool"
                case "void": return "void"
        case "lua":
            match tp:
                case "i32": return "int32"
                case "u32": return "uint32"
                case "f32": return "float32"
                case "str": return "cstring"
                case "bool": return "bool"
                case "void": return None
        case "ts":
            match tp:
                case "i32": return "i32"
                case "u32": return "u32"
                case "f32": return "f32"
                case "str": return "string"
                case "bool": return "bool"
                case "void": return "void"
    return tp

def convert_type(tp:str, lang:str) -> str|None:
    match lang:
        case "C" | "C.h" | "wasm.h":
            match tp:
                case "i32": return "int"
                case "u32": return "unsigned int"
                case "f32": return "float"
                case None: return "void"
                case "*const c_char": return "const char*"
                case "*mut c_char": return "void*"
                case "bool": return "bool"
                case "str": return "const char*"
        case "C++" | "C++.h":
            match tp:
                case "i32": return "int"
                case "u32": return "unsigned int"
                case "f32": return "float"
                case None: return "void"
                case "*const c_char": return "char*"
                case "*mut c_char": return "void*"
                case "bool": return "bool"
                case "str": return "char*"
        case "zig":
            match tp:
                case "i32": return "i32"
                case "u32": return "u32"
                case "f32": return "f32"
                case None: return "void"
                case "*mut c_char" | "*const c_char": return "i32"
                case "bool": "bool"
                case "str": return "[*:0]const u8"
        case "ts":
            match tp:
                case "i32": return "i32"
                case "u32": return "u32"
                case "f32": return "f32"
                case None: return "void"
                case "*mut c_char": return "i32"
                case "*const c_char": return "i32"
                case "bool": return "bool"
                case "str": return "string"
                case "int": return "i32"
        case "lua":
            match tp:
                case "i32": return "int32"
                case "u32": return "uint32"
                case "f32": return "float32"
                case None | "void": return None
                case "*mut c_char": return "int32"
                case "*const c_char": return "cstring"
                case "bool": return "boolean"
                case "str": return "string"
        
    if tp not in ["void", "ColorNote", "BombNote", "Arc", "Wall", "ChainHeadNote", "ChainLinkNote", "ChainNote", "Color"]:
        print(f"\n\n\n\033[38;2;255;20;20mUnprocessed type: {tp} ({lang})\033[0m\n\n\n")
    return tp

class Ownership(Enum):
    Owned = auto()
    MutRef = auto()
    Ref = auto()

class Arg:
    def __init__(self, name:str, tp:str, ownership: Ownership):
        self.name = name
        self.tp = tp
        self.ownership = ownership

    @classmethod
    def from_list(cls, data):
        return cls(data[0], data[1], Ownership.Owned)

class Fn:
    def __init__(self, name:str, args:list[Arg], ret_tp:str):
        self.name = name
        self.args = args
        self.ret_tp = ret_tp

    def match_name(self, regex) -> re.Match|None:
        return re.match(regex, self.name)

    @classmethod
    def from_rust(cls, sig:str, tps:dict[str, str], tps2:dict[str, str]):
        mat = re.match(r"fn +(?P<name>[^\(]+) *\( *(?P<args>(([^:]+) *: *([^,]+),?)*) *\) *(?:-> *(?P<ret>[^;]+))?;", sig) 
        gd = mat.groupdict()
        
        raw_args = [s.strip() for s in gd["args"].split(",") if s.strip() != ""]
        
        args = []
        
        for arg in raw_args:
            nt = arg.split(":")
            n = nt[0].strip()
            t = nt[1].strip()
            args.append(Arg(n, tps.get(t, t), Ownership.Owned))
        
        r = gd["ret"]
        
        return cls(gd["name"], args, tps.get(r, r))

    def as_lang(self, lang:str) -> str:
        args = get_param_def_style(lang, self.args).format_map({"args": build_params(lang, self.args)})
        match lang:
            case "wasm.h":
                return f"extern {convert_type(self.ret_tp, lang)} {self.name}{args};"
            case "zig":
                return f"extern \"env\" fn {self.name}{args} {convert_type(self.ret_tp, lang)};"
            case "ts":
                return f"@external(\"env\", \"{self.name}\")\nexport declare function {self.name}{args}: {convert_type(self.ret_tp, lang)};"
            case "lua":
                ret = convert_type(self.ret_tp, lang)
                return f"local function {self.name}{args}{"" if ret is None else f": {ret}"} <cimport, nodecl, cinclude '<turing_api_lua.h>'> end"

    def generate(self, lang:str, body:str) -> str:
        args = get_args_style(lang, self.args).format_map({"args": build_params(lang, self.args, True)})
        match lang:
            case "C":
                return f"\n{from_mdef(self.ret_tp, lang)} {self.name}{args} {{\n{body}\n}}\n"
            case "C++":
                return f"\n{from_mdef(self.ret_tp, lang)} {self.name}{args} {{\n{body}\n}}\n"
            case "C.h":
                return f"\n{from_mdef(self.ret_tp, lang)} {self.name}{args};\n"
            case "C++.h":
                return f"\n{from_mdef(self.ret_tp, lang)} {self.name}{args};\n"
            case "lua":
                return f"\nglobal function {self.name}{args}: {from_mdef(self.ret_tp, lang)}\n{body}\nend"
            case "zig":
                return f"pub fn {self.name}{args} {from_mdef(self.ret_tp, lang)} {{\n{body}\n}}"
            case "ts":
                return f"export function {self.name}{args}: {from_mdef(self.ret_tp, lang)} {{\n{body}\n}}"
                
            case "wasm.h":
                return ""
        return f"ERROR [Fn.generate()] {lang}  {self.name}"

class Attr:
    def __init__(self, name:str, tp:str, ownership:Ownership):
        self.name = name
        self.tp = tp
        self.ownership = ownership
    
    def as_struct_def(self, lang:str) -> str:
        match lang:
            case "C" | "C.h" | "C++" | "C++.h" | "wasm.h":
                return f"{from_mdef(self.tp, lang)} {self.name};"
            case "ts":
                return f"{self.name}: {from_mdef(self.tp, lang)};"
            case "lua" | "zig":
                return f"{self.name}: {from_mdef(self.tp, lang)}"

class Method:
    def __init__(self, name:str, params:list[Arg], ret_type:str, mref:str, wasm_name:str = ""):
        self.name = name
        self.params = params
        self.ret_type = ret_type
        self.mref = mref
        self.wasm_name = wasm_name
    
    def generate(self, classlike, lang:str) -> str: ...
    
class StaticMethod(Method):
    def __init__(self, name:str, params:list[Arg], ret_type:str, mref:str, wasm_name:str = ""):
        super().__init__(name, params, ret_type, mref, wasm_name)
    
    def generate(self, classlike, lang:str, mdef:IMdef) -> str:
        classlike: Classlike
        args = get_param_def_style(lang, self.params).format_map({"args": build_params(lang, self.params)})
        body = mdef.process_from_source(self.mref, lang, self.wasm_name)
        body = body.replace("\n", "\n    ")
        match lang:
            case "C":
                body = body.replace("\n", "\n    ")
                return f"{convert_type(self.ret_type, lang)} {classlike.classname}_{self.name}{args} {{\n    {body}\n}}"
            case "C.h":
                return f"{convert_type(self.ret_type, lang)} {classlike.classname}_{self.name}{args};"
            case "C++":
                body = body.replace("\n", "\n    ")
                return f"{convert_type(self.ret_type, lang)} {classlike.classname}::{self.name}{args} {{\n    {body}\n}}"
            case "C++.h":
                return f"static {convert_type(self.ret_type, lang)} {self.name}{args};"
            case "wasm.h":
                return "" # no class-related methods in wasm bindings
            case "lua":
                ret = convert_type(self.ret_type, lang)
                return f"function {classlike.classname}.{self.name}{args}{f": {ret}" if ret else ""}\n    {body}\nend\n"
            case "zig":
                ret = convert_type(self.ret_type, lang)
                body = body.replace("\n", "\n        ")
                return f"    pub fn {self.name}{args} {ret} {{\n        {body}\n    }}"
            case "ts":
                ret = convert_type(self.ret_type, lang)
                body = body.replace("\n", "\n    ")
                out = f"    public static {self.name}{args}: {ret} {{\n        {body}\n    }}"
                
                return out
        return ""
    
class InstanceMethod(Method):
    def __init__(self, name:str, self_param:Arg, params:list[Arg], ret_type:str, mref:str, wasm_name:str=""):
        super().__init__(name, params, ret_type, mref, wasm_name)
        self.self_param = self_param

    def generate(self, classlike, lang:str, mdef:IMdef) -> str:
        classlike: Classlike
        params = [Arg("self", classlike.classname, Ownership.MutRef)] + self.params
        args = get_param_def_style(lang, params).format_map({"args": build_params(lang, params)})
        body = mdef.process_from_source(self.mref, lang, self.wasm_name)
        # print(f"\n\n\033[38;2;20;200;20mbody from mref '{self.mref}':\033[0m\n{body}\n\n")
        match lang:
            case "C":
                body = body.replace("\n", "\n    ")
                return f"{convert_type(self.ret_type, lang)} {classlike.classname}_{self.name}{args} {{\n    {body}\n}}"
            case "C.h":
                return f"{convert_type(self.ret_type, lang)} {classlike.classname}_{self.name}{args};"
            case "C++":
                body = body.replace("\n", "\n    ")
                return f"{convert_type(self.ret_type, lang)} {classlike.classname}::{self.name}{args} {{\n    {body}\n}}"
            case "C++.h":
                return f"static {convert_type(self.ret_type, lang)} {self.name}{args};"
            case "wasm.h":
                return "" # no class-related methods in wasm bindings
            case "lua":
                ret = convert_type(self.ret_type, lang)
                return f"function {classlike.classname}.{self.name}{args}{f": {ret}" if ret else ""}\n    {body}\nend\n"
            case "zig":
                ret = convert_type(self.ret_type, lang)
                body = body.replace("\n", "\n        ")
                return f"    pub fn {self.name}{args} {ret} {{\n        {body}\n    }}"
            case "ts":
                ret = convert_type(self.ret_type, lang)
                body = body.replace("\n", "\n    ")
                out = f"    public static {self.name}{args}: {ret} {{\n        {body}\n    }}"
                
                return out
        return ""
    
    
class Classlike:
    def __init__(self, classname: str, attrs: list[Attr], static_methods: list[StaticMethod], instance_methods: list[InstanceMethod], friend_types:list[str]):
        self.classname = classname
        self.attrs = attrs
        self.static_methods = static_methods
        self.instance_methods = instance_methods
        self.friend_types = friend_types
        
    def generate(self, lang:str, mdef:IMdef) -> str:
        match lang:
            case "C":
                # print(self.classname, self.attrs, self.static_methods, self.instance_methods, self.friend_types)
                # <ret_tp> <classname>_<instance_method>
                # <ret_tp> <classname>_<static_method>
                out = f"// C class {self.classname}\n"
                
                for stat in self.static_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
                
                for stat in self.instance_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
                
                return out
            case "C.h":
                out = ""
                a = [a.as_struct_def(lang) for a in self.attrs]
                if a:
                    out += f"typedef struct {{\n    {"\n    ".join(a)}\n}} {self.classname};\n"
                # typedef struct { <attrs> } <classname>;
                # <ret_tp> <classname>_<instance_method>;
                # <ret_tp> <classname>_<static_method>;
                
                for stat in self.static_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
                
                for stat in self.instance_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
                
                return out
                
            case "C++":
                out = f"// C++ class {self.classname}\n"
            
                for stat in self.static_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
                
                for stat in self.instance_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
            
                return out
            case "C++.h":
                # class <classname> { public: <static/instance methods> private: <attrs> <frind classes> }
                out = f"// C++.h class '{self.classname}'\nclass {self.classname} {{\n    public:\n"
                
                a = [a.as_struct_def(lang) for a in self.attrs]
                if a:
                    out += "        " + ("\n        ".join(a))
                
                for stat in self.static_methods:
                    out += f"\n        {stat.generate(self, lang, mdef)}\n"
                
                for stat in self.instance_methods:
                    out += f"\n        {stat.generate(self, lang, mdef)}\n"
                
                out += "\n};\n"
                
                return out
                
            case "zig":
                # pub const <classname> = struct { <attrs/statics/instance methods> };
                
                a = [a.as_struct_def(lang)  + "," for a in self.attrs]
                
                out = f"pub const {self.classname} = struct {{\n    {"\n    ".join(a)}"
                
                for stat in self.static_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
                
                for stat in self.instance_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
                
                out += "};"
                
                return out
                
            case "ts":
                aout = ""
                aout2 = ""
                args = []
                for a in self.attrs:
                    a2 = a.as_struct_def(lang)
                    aout += f"    {a2}\n"
                    args.append(a2[:-1])
                    aout2 += f"        this.{a.name} = {a.name};\n"
                    
                    
                out = f"class {self.classname} {{\n{aout}\n    constructor({", ".join(args)}) {{\n{aout2}\n    }}\n"
                
                for stat in self.static_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
                
                for stat in self.instance_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
                
                out += "\n}"
                return out
                
            case "lua":
                # global <classname> = @record{ <attrs> }
                # function <classname>.<static/instance method>
                out = f"global {self.classname} = @record{{\n"
                a = [a.as_struct_def(lang) for a in self.attrs]
                if a:
                    out += "    " + ("\n    ".join(a))
                out += "\n}\n"
                
                for stat in self.static_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
                
                for stat in self.instance_methods:
                    out += f"\n{stat.generate(self, lang, mdef)}\n"
                
                    
                return out
            case "wasm.h":
                return "" # no class-gen in wasm.h
        
        print(f"Missing lang: {lang}")


def build_params(lang:str, args:list[Arg], isFromMdef = False) -> str:
    convert = from_mdef if isFromMdef else convert_type
    out = []
    match lang:
        case "C" | "C.h" | "C++" | "C++.h" | "wasm.h":
            for a in args:
                out.append(f"{convert(a.tp, lang)}{"*" if a.ownership in [Ownership.MutRef, Ownership.Ref] else ""} {a.name}")
            return ", ".join(out)
        case "zig" | "ts" | "lua":
            for a in args:
                out.append(f"{a.name}: {convert(a.tp, lang)}")
            return ", ".join(out)

def get_param_def_style(lang:str, args:list[Arg]) -> str:
    match lang:
        case "C" if len(args) == 0:
            return "(void)"
    
    return "({args})"

def get_args_style(lang:str, args:list[Arg]) -> str:
    return "({args})"

class IConstruct:
    def reset(self) -> None: ...
    def attach(self, lang:str, mdef:IMdef, fns: list[Fn]) -> None: ...
    def link(self, lang:str, mdef:IMdef, structs) -> None: ...
    def relink(self, lang:str, mdef:IMdef, structs) -> None: ...
    def generate(self, fstruct, mdef:IMdef) -> None: ...
    def owns_fn(self, fn: Fn) -> bool: ...

class FileConstructor:
    def __init__(self, lang:str):
        self.lang = lang
        self.linkages = []
        self.imports: dict[str, str] = {}
        self.wasm_bindings: list[str] = []
        self.class_like: dict[int, dict[str, str]] = {}
        self.function_like: dict[int, dict[str, str]] = {}
        self._ts_exports = []
    
    def lang_group(self):
        match self.lang:
            case "C" | "C.h": return "C"
            case "C++" | "C++.h": return "C++"
            case "wasm.h": return "C/C++/Lua"
            case "zig": return "Zig"
            case "lua": return "Lua"
            case "ts": return "AsmScript"
        
    def add_functionlike(self, order: int, name: str, src: str):
        if order not in self.function_like.keys():
            self.function_like.update({order: {}})
        
        self.function_like[order].update({name: src})
        
    def add_classlike(self, order:int, name:str, src:str):
        if order not in self.class_like.keys():
            self.class_like.update({order: {}})
        
        self.class_like[order].update({name: src})
    
    def header(self) -> str:
        match self.lang:
            case "wasm.h":
                return "\n#ifndef WASM_IMPORTS_H\n#define WASM_IMPORTS_H\n\n"
            case "C.h":
                return "\n#ifndef TURING_API_H\n#define TURING_API_H\n\n#include <wasm_imports.h>\n"
            case "C++.h":
                return "\n#ifndef TURING_API_HPP\n#define TURING_API_HPP\n\n#include <wasm_imports.h>\n"
            case "C":
                
                with open("./api-gen/base/wasm-std.c", "r+", encoding="utf-8") as f:
                    data = f.read()
                
                return f"\n#include <turing_api_c.h>\n\n{data}\n"
            case "C++":
                
                with open("./api-gen/base/wasm-std.c", "r+", encoding="utf-8") as f:
                    data = f.read()
                
                return f"\n#include <turing_api_cpp.hpp>\n\n{data}\n"
            case "zig":
                return "\nconst std = @import(\"std\");\n"
            case "lua":
                return "\nlocal string = require('string')\n"
        return ""

    def footer(self) -> str:
        match self.lang:
            case "wasm.h":
                return "\n#endif // WASM_IMPORTS_H"
            case "C.h":
                return "\n#endif // TURING_API_H"
            case "C++.h":
                return "\n#endif // TURING_API_HPP"
            case "ts":
                return f"export {{ Beatmap, Log, Color, {", ".join(self._ts_exports)} }}"
        return ""
    
    def prelink(self) -> str:
        match self.lang:
            case "wasm.h":
                return "\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n"
            case "zig":
                return ""
            case "ts":
                return ""
            case "lua":
                return ""
            
        return ""
    
    def postlink(self) -> str:
        
        match self.lang:
            case "wasm.h":
                return "\n\n#ifdef __cplusplus\n}\n#endif\n\n"
            case "zig":
                ...
            case "ts":
                ...
            case "lua":
                ...
        
        return ""
    
    def construct(self, fns: list[Fn], mdef:IMdef, constructs: list[IConstruct], outputs: list[str], build_links: bool = False):
        mdef: Mdef
        
        
        if build_links:
            for fn in fns:
                self.linkages.append(fn.as_lang(self.lang))
        
        for c in constructs:
            c.reset()
            c.attach(self.lang, mdef, fns)
        
        for c in constructs:
            c.link(self.lang, mdef, constructs)
        
        for c in constructs:
            c.relink(self.lang, mdef, constructs)
        
        for c in constructs:
            c.generate(self, mdef)
            
        c = "--" if self.lang == "lua" else "//"
    
        data_out = f"{c} Turing API - {self.lang_group()}\n{c} License: {LICENSE}\n{c} Authors: {", ".join(AUTHORS)}\n{c} <auto-converted from the rust api />\n\n"
        
        data_out += self.header()
        
        if build_links:
            data_out += self.prelink()
            data_out += "\n".join(self.linkages) + "\n"
            data_out += self.postlink()
        
        for imp in self.imports.values():
            data_out += imp + "\n"
        
        for bind in self.wasm_bindings:
            data_out += bind + "\n"
            
        data_out += mdef.static_defs.get(self.lang, "") 
        
        passes = set()
        
        passes.update(self.class_like.keys())
        passes.update(self.function_like.keys())
        
        passes = list(passes)
        passes.sort()
        
        for i in passes:
            for _, c in self.class_like.get(i, {}).items():
                data_out += c + "\n\n"
            
            for _, f in self.function_like.get(i, {}).items():
                data_out += f + "\n\n"
        
        data_out += self.footer()
        
        data_out = re.sub(r"\n\n+", "\n\n", data_out)
        
        for o in outputs:
            print(f"Writing to output: {o}")
            with open(f"{o}", "w+", encoding="utf-8") as f:
                f.write(data_out)
        
    
    @classmethod
    def compile_H(cls, fns, mdef):
        fc = cls("wasm.h")
        outputs = [
            "./C and C++/internal/src/wasm_imports.h",
            "./Lua/turing-api-lua/turing_api_lua.h"
        ]
        
        fc.construct(fns, mdef, Construct._structs, outputs, True)

    @classmethod
    def compile_C(cls, fns, mdef):
        fc = cls("C")
        outputs = [
            "./C and C++/turing-api-c/src/turing_api_c.c"
        ]
        
        fc.construct(fns, mdef, Construct._structs, outputs)
        
        fc = cls("C.h")
        outputs = [
            "./C and C++/turing-api-c/include/turing_api_c.h"
        ]
        
        fc.construct(fns, mdef, Construct._structs, outputs)
    
    @classmethod
    def compile_Cpp(cls, fns, mdef):
        fc = cls("C++")
        outputs = [
            "./C and C++/turing-api-cpp/src/turing_api_cpp.cpp"
        ]
        
        fc.construct(fns, mdef, Construct._structs, outputs)
        
        fc = cls("C++.h")
        outputs = [
            "./C and C++/turing-api-cpp/include/turing_api_cpp.hpp"
        ]
        
        fc.construct(fns, mdef, Construct._structs, outputs)
    
    @classmethod
    def compile_Zig(cls, fns, mdef):
        fc = cls("zig")
        outputs = [
            "./Zig/turing-api-zig/src/root.zig"
        ]
        
        fc.construct(fns, mdef, Construct._structs, outputs, True)
        
    @classmethod
    def compile_AssemblyScript(cls, fns, mdef):
        fc = cls("ts")
        outputs = [
            "./AssemblyScript/turing-api-assemblyscript/turing_api_assemblyscript.ts"
        ]
        
        fc.construct(fns, mdef, Construct._structs, outputs, True)
    
    @classmethod
    def compile_Lua(cls, fns, mdef):
        fc = cls("lua")
        outputs = [
            "./Lua/turing-api-lua/turing_api_lua.nelua"
        ]
        
        fc.construct(fns, mdef, Construct._structs, outputs, True)
        
    @classmethod
    def compile_All(cls, fns, mdef):
        cls.compile_H(fns, mdef)
        cls.compile_C(fns, mdef)
        cls.compile_Cpp(fns, mdef)
        cls.compile_Zig(fns, mdef)
        cls.compile_AssemblyScript(fns, mdef)
        cls.compile_Lua(fns, mdef)


class Construct(IConstruct):
    _structs = []
    
    def __init__(self, struct_id:str):
        self.struct_id = struct_id
    
    # lets the construct collect whatever methods it wants to add details for
    def attach(self, lang:str, mdef, fns: list[Fn]):
        pass #print(f"Attach phase for {self.struct_id} - {lang}")
        
    def generate(self, fstruct: FileConstructor, mdef):
        pass #print(f"Generate phase for {self.struct_id} - {fstruct.lang}")
        
    def link(self, lang:str, mdef, constructs):
        pass #print(f"Link phase for {self.struct_id} - {lang}")
        
    def relink(self, lang:str, mdef, constructs):
        pass #print(f"Relink phase for {self.struct_id} - {lang}")
        
    def reset(self):
        pass #print(f"Reset phase for {self.struct_id}")
        
    def owns_fn(self, fn: Fn) -> bool:
        return False
        
    @classmethod
    def c(cls, child):
        cls._structs.append(child())
        return child

@Construct.c
class BeatmapConstruct(Construct):
    
    def __init__(self):
        super().__init__("Beatmap")
        self.object_adders: list[Fn] = []
        self.object_removers: list[Fn] = []
    
    def owns_fn(self, fn):
        return fn in self.object_adders
    
    def attach(self, lang:str, mdef, fns:list[Fn]):
        for fn in fns:
            if fn.name.startswith("_beatmap_add"):
                self.object_adders.append(fn)
            if fn.name.startswith("_beatmap_remove"):
                self.object_removers.append(fn)
    
    def reset(self):
        self.object_adders.clear()
    
    def generate(self, fstruct, mdef:IMdef):
        cl: Classlike = mdef.get_class("Beatmap")
        
        for sm in cl.static_methods:
            for fn in self.object_adders:
                if fn.name == f"_beatmap_{sm.name}":
                    sm.wasm_name = fn.name
            
            for fn in self.object_removers:
                if fn.name == f"_beatmap_{sm.name}":
                    sm.wasm_name = fn.name
        
        
        out = cl.generate(fstruct.lang, mdef)
        
        fstruct.add_classlike(1, "Beatmap", re.sub(r"\n+", "\n", out))


@Construct.c
class GameObjectConstruct(Construct):
    def __init__(self):
        super().__init__("GameObjects")
        self.constructor_fns: list[Fn] = []
        self.fns: dict[str, dict[str, Fn]] = {
            "color_note": {},
            "bomb_note": {},
            "arc": {},
            "wall": {},
            "chain_head_note": {},
            "chain_link_note": {},
            "chain_note": {}
        }
        
        self.tnames = {
            "color_note": "ColorNote",
            "bomb_note": "BombNote",
            "arc": "Arc",
            "wall": "Wall",
            "chain_head_note": "ChainHeadNote",
            "chain_link_note": "ChainLinkNote",
            "chain_note": "ChainNote"
        }
    
    def owns_fn(self, fn: Fn):
        for (k, v) in self.fns.values().items():
            if v is fn:
                return True
        return False
    
    def attach(self, lang:str, mdef:IMdef, fns: list[Fn]):
        for fn in fns:
            if (m := fn.match_name(r"^_(color_note|bomb_note|arc|wall|chain_head_note|chain_link_note|chain_note)_(.*)$")) is not None:
                self.fns[m.groups()[0]].update({ m.groups()[1]: fn })
            elif fn.match_name(r"_create_(color_note|bomb_note|arc|wall|chain_head_note|chain_link_note|chain_note)"):
                self.constructor_fns.append(fn)

    def generate(self, fstruct:FileConstructor, mdef:IMdef):
        out = ""
        for struct, fns in self.fns.items():
            cname = self.tnames[struct]
            # print(f"bind class {cname}")
            out += "\n" + self.gen(fstruct, mdef, mdef.get_class(cname), fns) + "\n"
            fstruct._ts_exports.append(cname)
        
        fstruct.add_classlike(0, f"{cname}", re.sub(r"\n+", "\n", out))

        for fn in self.constructor_fns:
            rfn = Fn(fn.name[1:], fn.args, self.tnames[fn.name[8:]])
            
            raw = mdef.get_source("constructor_beat", fstruct.lang)
            
            body: str = ""
            if raw:
                body, macros = raw
                body = mdef.process_macros(body, macros, [self.tnames[fn.name[8:]]])
                body = body.replace("~", fn.name)
                body = "    " + body.replace("\n", "\n    ")
            
            src = rfn.generate(fstruct.lang, body)
            fstruct.add_functionlike(0, fn.name, src)


    def gen(self, fstruct:FileConstructor, mdef, classlike: Classlike, fns:dict[str, Fn]):
        
        for name, fn in fns.items():
            for m in classlike.instance_methods:
                if m.name == name:
                    m.wasm_name = fn.name
                    
            for m in classlike.static_methods:
                if m.name == name:
                    m.wasm_name = fn.name
        
        return classlike.generate(fstruct.lang, mdef)
        

@Construct.c
class ExtraClassesConstruct(Construct):
    def __init__(self):
        super().__init__("ExtraClasses")
        self.color_methods: dict[str, Fn] = {}
        self.include = [
            (0, "Color"),
            (0, "Log")
        ]
    
    def attach(self, lang:str, mdef:IMdef, fns:list[Fn]):
        for fn in fns:
            if (m := re.match(r"_color_([gs]et_.*)", fn.name)) is not None:
                m: re.Match
                self.color_methods.update({m.groups()[0]: fn})
    
    def generate(self, fstruct, mdef:IMdef):
        
        color: Classlike = mdef.get_class("Color")
        for m in color.instance_methods:
            m.wasm_name = self.color_methods.get(m.name, Fn("undefined", [], "")).name
        
        for (o, i) in self.include:
            t: Classlike = mdef.class_likes.get(i, None)
            if t:
                src = t.generate(fstruct.lang, mdef)
                fstruct.add_classlike(o, i, src)
        

class ClsBuilder:
    def __init__(self):
        self.name: str|None = None
        self.attrs: list[Attr] = []
        self.static_methods: list[StaticMethod] = []
        self.instance_methods: list[InstanceMethod] = []
        self.friends: list[str] = []
    
    def is_building(self) -> bool:
        return self.name != None
    
    def start(self, name:str):
        self.name = name
    
    def add_attr(self, attr: Attr):
        self.attrs.append(attr)
    
    def add_s_method(self, m: StaticMethod):
        self.static_methods.append(m)

    def add_i_method(self, m: InstanceMethod):
        self.instance_methods.append(m)
        
    def add_friend(self, f: str):
        self.friends.append(f)
    
    def build(self) -> Classlike:
        c = Classlike(self.name, self.attrs, self.static_methods, self.instance_methods, self.friends)
        self.name: str|None = None
        self.attrs: list[Attr] = []
        self.static_methods: list[StaticMethod] = []
        self.instance_methods: list[InstanceMethod] = []
        self.friends: list[str] = []
        return c

class Mdef(IMdef):
    def __init__(self, src:str):
        self.src = src
        self.class_likes: dict[str, Classlike] = {}
        self.definitions: dict[str, dict[str, str]] = {}
        self.definition_macros: dict[str, list[str]] = {}
        self.static_defs: dict[str, str] = {}
        
        # list of frames
        # (macro names, patterns)
        # patterns: list of groups of tokens. each group fills each macro name, recursively
        self._macro_memory: list[ list[str], list[list[str]] ] = []

        lines = src.split("\n")
        
        self.cls_builder = ClsBuilder()
        self.applying_macro = False
        self.parser_state = -1
        
        self.current_mdef: str|None = None
        self.current_mdef_langs: list[str] = []
        self.mdef_src_builder: list[str] = []
        self.current_sources: dict[str, str] = {}
        
        self.current_static_lang = None
        self.current_src = []
        
        self.process_lines(lines)
        
        # print(f"Loaded sources:\n\nclass-like:\n{self.class_likes}\n\n{json.dumps(self.definitions, indent=4)}")
    
    def process_macros(self, src:str, macros:list[str], values:list[str]) -> str:
        for (m, v) in zip(macros, values):
            src = src.replace(m, v)
        return src
    
    def get_class(self, classname: str) -> Classlike|None:
        return self.class_likes.get(classname, None)
    
    def get_source(self, mref:str, lang:str) -> None|tuple[str, list[str]]:
        if mref.startswith("#mdef."):
            mref = mref[6:]
        defs = self.definitions.get(mref)
        if defs:
            src = defs.get(lang, None)
            if src:
                return (src, self.definition_macros.get(mref, []))
        return None
    
    def process_from_source(self, mref:str, lang:str, fname:str) -> str:
        if mref.startswith("#mdef."):
            mref = mref[6:]
        
        values = []
        name = mref
        if (m := re.match(r"([a-zA-Z_][a-zA-Z0-9_]*)(?:\(([^\)]+)\))?", mref)) is not None:
            m: re.Match
            g = m.groups()
            name = g[0]
            vals = g[1]
            if vals:
                values = [v.strip() for v in re.split(r" *, *", vals) if v.strip() != ""]
    
        raw = self.get_source(name, lang) or ["", []]
        src = self.process_macros(raw[0], raw[1], values)
        return src.replace("~", fname)
    
    def process_lines(self, lines:list[str]):
        macro_cache: list = []
        while lines:
            line: str = lines.pop(0)
            if line.startswith("//") or line.strip() == "":
                continue
            
            if line.startswith("#struct-defs"):
                self.parser_state = 0
                continue
            elif line.startswith("#code-defs"):
                self.parser_state = 1
                continue
            elif line.startswith("#static-defs"):
                self.parser_state = 2
                continue
            
            if self.parser_state == 0:
                if (m := re.match(r" *#macro *((?:\$\d+ *)+)", line)) is not None:
                    mframe = [re.split(r" +", m.groups()[0]), []]
                    self._macro_memory = mframe
                    continue
                
                if (m := re.match(r" *#pattern *((# *([^ #]+ *)+)+)", line)) is not None:
                    patterns = [[s2.strip() for s2 in re.split(r" +", s)] for s in re.split(r" *# *", m.groups()[0]) if s.strip() != ""]
                    self._macro_memory[1] += patterns
                    continue
                
                if re.match(r" *#macro apply", line):
                    self.applying_macro = True
                    continue
                
                if re.match(r" *#macro end", line):
                    self.applying_macro = False
                
                if self.applying_macro:
                    macro_cache.append(line)
                    continue
                elif macro_cache:
                    full = "\n".join(macro_cache)
                    macro_cache.clear()
                    keys = self._macro_memory[0]
                    for vals in self._macro_memory[1]:
                        f = full
                        for (k, v) in zip(keys, vals):
                            f = f.replace(k, v)
                        lines = f.split("\n") + lines
                    self._macro_memory = []
                    continue
                    # print(f"macro re-expanded lines to: {json.dumps(lines, indent=4)}")

                if (m := re.match(r"class *([a-zA-Z_][a-zA-Z0-9_]*) *\{", line)) is not None:
                    m: re.Match
                    self.cls_builder.start(m.groups()[0])
                    continue

                if self.cls_builder.is_building():
                    
                    if re.match(r" *} *", line):
                        self.class_likes.update({self.cls_builder.name: self.cls_builder.build()})
                        
                        continue
                    
                    if (m := re.match(r" *([a-zA-Z_][a-zA-Z0-9_]*) *: *([a-zA-Z_][a-zA-Z0-9_]*)", line)) is not None:
                        m: re.Match
                        g = m.groups()
                        n = g[0]
                        t = g[1]
                        a = Attr(n, t, Ownership.Owned)
                        self.cls_builder.add_attr(a)
                        continue
                    
                    if (m := re.match(r" *static *fn *([a-zA-Z_][a-zA-Z0-9_]*) *\(((?:[a-zA-Z_][a-zA-Z0-9_]* *: *[a-zA-Z_][a-zA-Z0-9_]*,? *)+)\) *-> *([a-zA-Z_][a-zA-Z0-9_]*) *(.*)", line)) is not None:
                        m: re.Match
                        g: tuple[str] = m.groups()
                        f_name = g[0]
                        f_args = [Arg.from_list(re.split(r" *: *", ar)) for ar in re.split(r" *, *", g[1].strip().strip(",").strip())]
                        ret = g[2]
                        mref = g[3]
                        
                        self.cls_builder.add_s_method(StaticMethod(f_name, f_args, ret, mref))
                        continue

                    elif (m := re.match(r" *fn *([a-zA-Z_][a-zA-Z0-9_]*) *\(((?:& *(?:mut *)?)? *self),? *((?:[a-zA-Z_][a-zA-Z0-9_]* *: *[a-zA-Z_][a-zA-Z0-9_]*,? *)*)\) *-> *([a-zA-Z_][a-zA-Z0-9_]*) *(.*)", line)) is not None:
                        m: re.Match
                        g: tuple[str] = m.groups()
                        f_name = g[0]
                        self_ownership_rw = g[1].replace(" ", "")
                        self_param = Arg("self", self.cls_builder.name, (Ownership.Owned if self_ownership_rw == "self" else Ownership.MutRef if self_ownership_rw == "&mutself" else Ownership.Ref))
                        f_args = [Arg.from_list(re.split(r" *: *", ar)) for ar in re.split(r" *, *", g[2].strip().strip(",").strip()) if ":" in ar]
                        ret = g[3]
                        mref = g[4]
                        
                        self.cls_builder.add_i_method(InstanceMethod(f_name, self_param, f_args, ret, mref))
                        continue
                    
                    elif (m := re.match(r" *shared *((?:[a-zA-Z_][a-zA-Z0-9_]* *,? *)+)", line)) is not None:
                        m: re.Match
                        shared = [s.strip() for s in re.split(r" *, *", m.groups()[0]) if s.strip() != ""]

                        for f in shared:
                            self.cls_builder.add_friend(f)

            elif self.parser_state == 1:
                if (m := re.match(r"^#([^ \{]+) *\{", line)) is not None:
                    self.current_mdef = m.groups()[0]
                    self.current_mdef_langs.clear()
                    self.mdef_src_builder.clear()
                    continue
                    
                if (m := re.match(r"    ((?:#(?:C|C\+\+|zig|lua|ts),? *)+) *\{", line)) is not None:
                    m: re.Match
                    self.current_mdef_langs = [x.strip("#").strip() for x in re.split(r" *, *", m.groups()[0])]
                    continue
                
                if line.startswith("        "): # 8 spaces aka 2 indents
                    self.mdef_src_builder.append(line[8:])
                    continue
            
                if line.startswith("    }"):
                    src = "\n".join(self.mdef_src_builder)
                    for lang in self.current_mdef_langs:
                        self.current_sources.update({lang: src})
                    self.current_mdef_langs.clear()
                    self.mdef_src_builder.clear()
                    continue
            
                if line.startswith("}"):
                    
                    m: re.Match = re.match(r"([a-zA-Z_][a-zA-Z0-9_]*)(?:\(([^)]+)\))?", self.current_mdef)
                    
                    md = m.groups()[0]
                    macros = [m for m in re.split(r" *, *", (m.groups()[1] or "")) if m != ""]
                    
                    self.definitions.update({md: self.current_sources})
                    if macros:
                        self.definition_macros.update({md: macros})
                    
                    # print(f"Captured sources for {md}: {json.dumps(self.definitions[md], indent=4)} with macros: {json.dumps(self.definition_macros.get(md, [None]))}")
                    
                    self.current_mdef = None
                    self.current_sources = {}
                    continue
            
            elif self.parser_state == 2:
                if line.startswith("#"):
                    self.current_static_lang = line.split(" ", 1)[0].replace("#", "")
                    continue
                
                if line.startswith("    "):
                    self.current_src.append(line[4:])
                    continue
            
                if line.startswith("}"):
                    src = "\n".join(self.current_src)
                    self.static_defs.update({self.current_static_lang: src})
                    
                    # print(f"static source for {self.current_static_lang}:\n{src}\n////////////")
                    self.current_src.clear()
                    self.current_static_lang = None
                    continue

def main():
    
    args = sys.argv
    
    if len(args) < 2:
        print("Please provide the path to the expanded turing-api-rs source code")
        path = input("> ")
    else:
        path = args[1]
        
    if path == "--clean":
        for f in [
            "./C and C++/internal/src/wasm_imports.h",
            "./Lua/turing-api-lua/turing_api_lua.h",
            "./C and C++/turing-api-c/src/turing_api_c.c",
            "./C and C++/turing-api-c/include/turing_api_c.h",
            "./C and C++/turing-api-cpp/src/turing_api_cpp.cpp",
            "./C and C++/turing-api-cpp/include/turing_api_cpp.hpp",
            "./Zig/turing-api-zig/src/root.zig",
            "./AssemblyScript/turing-api-assemblyscript/turing_api_assemblyscript.ts",
            "./Lua/turing-api-lua/turing_api_lua.nelua"
        ]:
            try:
                os.remove(f"{f}")
            except:
                pass
        return
    
    if not os.path.exists(path):
        print(f"provided path '{path}' does not exist")
    
    with open(path, "r+", encoding="utf-8") as f:
        data = f.read()
    
    
    type_aliases = [ (m.group(1), m.group(2)) for m in re.finditer(r"(?<=\n)type ([^ ]+) = ([^;]+);", data)]
    
    types = {}
    types2 = {
        "_ColorNote": "ColorNote",
        "_BombNote": "BombNote",
        "_Arc": "Arc",
        "_Wall": "Wall",
        "_ChainHeadNote": "ChainHeadNote",
        "_ChainLinkNote": "ChainLinkNote",
        "_ChainNote": "ChainNote"
    }
    
    for (t, v) in type_aliases:
        types[t] = v

    
    export_blocks = re.findall(r"extern *\"C\" *\{[^}]*\}", data)
    
    functions: list[str] = []
    
    for export_block in export_blocks:
        
        block = re.sub(r"}$", "", re.sub(r"^extern\s*\"C\"\s*\{", "", export_block))

        functions += [re.sub(r"\n *", " ", m) for m in re.findall(r"fn[^;]+;", block)]

    function_defs = [Fn.from_rust(f, types, types2) for f in functions]

    with open("./api-gen/base/api_defs.txt", "r+", encoding="utf-8") as f:
        mdef = Mdef(f.read())


    FileConstructor.compile_All(function_defs, mdef)




if __name__ == "__main__":
    main()


