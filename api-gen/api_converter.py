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




# This script takes the rust api's macro-expanded source, and generates the apis for everything else based on it

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


    @classmethod
    def compile_C(cls, fns, tps):
        ...
    
    @classmethod
    def compile_Cpp(cls, fns, tps):
        ...
    
    @classmethod
    def compile_Zig(cls, fns, tps):
        ...
        
    @classmethod
    def compile_AssemblyScript(cls, fns, tps):
        ...
    
    @classmethod
    def compile_Lua(cls, fns, tps):
        ...
        
    @classmethod
    def compile_All(cls, fns, tps):
        cls.compile_C(fns, tps)
        cls.compile_Cpp(fns, tps)
        cls.compile_Zig(fns, tps)
        cls.compile_AssemblyScript(fns, tps)
        cls.compile_Lua(fns, tps)

def main():
    
    args = sys.argv
    
    if len(args) < 2:
        print("Please provide the path to the expanded turing-api-rs source code")
        path = input("> ")
    else:
        path = args[1]
    
    if not os.path.exists(path):
        print(f"provided path '{path}' does not exist")
    
    with open(path, "r+", encoding="utf-8") as f:
        data = f.read()
    
    
    type_aliases = [ (m.group(1), m.group(2)) for m in re.finditer(r"(?<=\n)type ([^ ]+) = ([^;]+);", data)]
    
    export_blocks = re.findall(r"extern *\"C\" *\{[^}]*\}", data)
    
    functions: list[str] = []
    
    for export_block in export_blocks:
        
        block = re.sub(r"}$", "", re.sub(r"^extern\s*\"C\"\s*\{", "", export_block))
        print(block)

        functions += [re.sub(r"\n *", " ", m) for m in re.findall(r"fn[^;]+;", block)]
        
    print(json.dumps(type_aliases, indent=4))
    print(json.dumps(functions, indent=4))

    function_defs = [Fn.from_rust(f) for f in functions]

    Fn.compile_All(function_defs, type_aliases)




if __name__ == "__main__":
    main()


