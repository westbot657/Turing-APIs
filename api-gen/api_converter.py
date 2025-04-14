# Turing API Generator
# a magic file that converts the API from rust and generates the API
# for every single other language that's currently supported

import sys, os, re, json

SUPPORTED_LANGS = [
    "C", "C++", "Lua", "Rust", "Zig", "TS"
]


TYPES = {
    "C": {
        "i32": "int",
        "u32": "unsigned int",
        "f32": "float",
        "*ptr": "void*",
        "string": "char*",
        "void": "void"
    },
    "Lua": {
        "i32": "int32",
        "u32": "uint32",
        "f32": "float32",
        "*ptr": "int32",
        "string": "int32",
        "void": "void"
    },
    "Rust": {
        "i32": "i32",
        "u32": "u32",
        "f32": "f32",
        "*ptr": "*const c_void",
        "string": "*const c_char",
        "void": "()"
    },
    "Zig": {
        "i32": "i32",
        "u32": "u32",
        "f32": "f32",
        "*ptr": "i32",
        "string": "[*:0]const u8", # may need to have special handling
        "void": "void"
    },
    "TS": {
        "i32": "i32",
        "u32": "u32",
        "f32": "f32",
        "*ptr": "i32",
        "string": "String",
        "void": "void"
    }
}


class Arg:
    def __init__(self, name:str, tp:str):
        self.name = name
        self.tp = tp

class Fn:
    def __init__(self, name:str, args:list[Arg], ret_tp:str):
        self.name = name
        self.args = args
        self.ret_tp = ret_tp


    @classmethod
    def from_rust(cls, sig:str):
        mat = re.match(r"fn +(?P<name>[^\(]+) *\( *(?P<args>(([^:]+) *: *([^,]+),?)*) *\) *(?:-> *(?P<ret>[^;]+))?;", sig) 
        gd = mat.groupdict()
        
        raw_args = [s.strip() for s in gd["args"].split(",") if s.strip() != ""]
        
        args = []
        
        for arg in raw_args:
            nt = arg.split(":")
            n = nt[0].strip()
            t = nt[1].strip()
            args.append(Arg(n, t))
        
        return cls(gd["name"], args, gd["ret"])

    def as_H(self, tps):
        ...

    def as_C(self, tps):
        ...
    
    def as_Cpp(self, tps):
        ...
    
    def as_Zig(self, tps):
        ...
        
    def as_AssemblyScript(self, tps):
        ...
        
    def as_Lua(self, tps):
        ...


class IConstruct:
    def attach(self, lang:str, fns: list[Fn]) -> None: ...
    def generate(self, tps:list[str], fstruct) -> None: ...
    def link(self, lang:str, structs) -> None: ...
    def reset(self) -> None: ...

class FileConstructor:
    def __init__(self, lang:str):
        self.lang = lang
        self.imports: dict[str, str] = {}
        self.wasm_bindings: list[str] = []
        self.class_like: dict[int, dict[str, str]] = {}
        self.function_like: dict[int, dict[str, str]] = {}
    
    def construct(self, fns: list[Fn], tps: list[tuple[str, str]], constructs: list[IConstruct], outputs: list[str]):
        for c in constructs:
            c.reset()
        
            c.attach(self.lang, fns)
        
        for c in constructs:
            c.link(self.lang, constructs)
        
        for c in constructs:
            c.generate(tps, self)
    
        data_out = ""
        
        for imp in self.imports.values():
            data_out += imp + "\n"
        
        for bind in self.wasm_bindings:
            data_out += bind + "\n"
            
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
        
        for o in outputs:
            with open(f"{o}.gen", "w+", encoding="utf-8") as f:
                f.write(data_out)
        
    
    @classmethod
    def compile_H(cls, fns, tps):
        fc = cls("wasm.h")
        outputs = [
            "./C and C++/internal/src/wasm_imports.h",
            "./Lua/turing-api-lua/turing_api_lua.h"
        ]
        
        fc.construct(fns, tps, Construct._structs, outputs)

    @classmethod
    def compile_C(cls, fns, tps):
        fc = cls("C")
        outputs = [
            "./C and C++/turing-api-c/src/turing_api_c.c"
        ]
        
        fc.construct(fns, tps, Construct._structs, outputs)
        
        fc = cls("C.h")
        outputs = [
            "./C and C++/turing-api-c/include/turing_api_c.h"
        ]
        
        fc.construct(fns, tps, Construct._structs, outputs)
    
    @classmethod
    def compile_Cpp(cls, fns, tps):
        fc = cls("C++")
        outputs = [
            "./C and C++/turing-api-cpp/src/turing_api_cpp.cpp"
        ]
        
        fc.construct(fns, tps, Construct._structs, outputs)
        
        fc = cls("C++.h")
        outputs = [
            "./C and C++/turing-api-cpp/include/turing_api_cpp.hpp"
        ]
        
        fc.construct(fns, tps, Construct._structs, outputs)
    
    @classmethod
    def compile_Zig(cls, fns, tps):
        fc = cls("zig")
        outputs = [
            "./Zig/turing-api-zig/src/root.zig"
        ]
        
        fc.construct(fns, tps, Construct._structs, outputs)
        
    @classmethod
    def compile_AssemblyScript(cls, fns, tps):
        fc = cls("ts")
        outputs = [
            "./AssemblyScript/turing-api-assemblyscript/turing_api_assemblyscript.ts"
        ]
        
        fc.construct(fns, tps, Construct._structs, outputs)
    
    @classmethod
    def compile_Lua(cls, fns, tps):
        fc = cls("lua")
        outputs = [
            "./Lua/turing-api-lua/turing_api_lua.nelua"
        ]
        
        fc.construct(fns, tps, Construct._structs, outputs)
        
    @classmethod
    def compile_All(cls, fns, tps):
        cls.compile_C(fns, tps)
        cls.compile_Cpp(fns, tps)
        cls.compile_Zig(fns, tps)
        cls.compile_AssemblyScript(fns, tps)
        cls.compile_Lua(fns, tps)


class Construct(IConstruct):
    _structs = []
    
    def __init__(self, struct_id:str):
        self.struct_id = struct_id
    
    # lets the construct collect whatever methods it wants to add details for
    def attach(self, lang:str, fns: list[Fn]):
        print(f"Attach phase for {self.struct_id} - {lang}")
        
    def generate(self, tps: list[str], fstruct: FileConstructor):
        print(f"Generate phase for {self.struct_id} - {fstruct.lang}")
        
    def link(self, lang:str, constructs):
        print(f"Link phase for {self.struct_id} - {lang}")
        
    def reset(self):
        print(f"Reset phase for {self.struct_id}")
        
    @classmethod
    def c(cls, child):
        cls._structs.append(child())
        return child

@Construct.c
class BeatmapConstruct(Construct):
    
    def __init__(self):
        super().__init__("Beatmap")
        self.object_adders = []
        
    def attach(self, lang:str, fns:list[Fn]):
        for fn in fns:
            if fn.name.startswith("_beatmap_add"):
                self.object_adders.append(fn)
    
    def reset(self):
        self.object_adders.clear()
    
    def generate(self, tps, fstruct):
        match fstruct.lang:
            case "C": ...
            case "C.h": ...
            case "C++": ...
            case "C++.h": ...
            case "wasm.h": ...
            case "zig": ...
            case "ts": ...
            case "lua": ...


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
                os.remove(f"{f}.gen")
            except:
                pass
        return
    
    if not os.path.exists(path):
        print(f"provided path '{path}' does not exist")
    
    with open(path, "r+", encoding="utf-8") as f:
        data = f.read()
    
    
    type_aliases = [ (m.group(1), m.group(2)) for m in re.finditer(r"(?<=\n)type ([^ ]+) = ([^;]+);", data)]
    
    export_blocks = re.findall(r"extern *\"C\" *\{[^}]*\}", data)
    
    functions: list[str] = []
    
    for export_block in export_blocks:
        
        block = re.sub(r"}$", "", re.sub(r"^extern\s*\"C\"\s*\{", "", export_block))

        functions += [re.sub(r"\n *", " ", m) for m in re.findall(r"fn[^;]+;", block)]

    function_defs = [Fn.from_rust(f) for f in functions]

    FileConstructor.compile_All(function_defs, type_aliases)




if __name__ == "__main__":
    main()


