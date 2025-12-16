# Turing

## Supported languages

### You can use this table to pick a language to use for writing scripts  
If your preferred language isn't on this list, you can still use it as long as it compiles to wasm32-wasip1 (wasi preview 1)
but if you want full API support, make an issue (or write it yourself and make a PR)  

| Language       | Coding complexity | Build complexity | Notes                                                                                                                     |
|----------------|-------------------|------------------|---------------------------------------------------------------------------------------------------------------------------|
| Rust           | Hard              | Easy             | Natively supports compilation to wasm32-wasip1.                                                                           |
| C              | Hard              | Hard             | Build complexity is better on linux or with the zig compiler.                                                             |
| C++            | Hard              | Hard             | Also easier on linux or with the zig compiler.                                                                            |
| C3             | Moderate          | Moderate         | Similar to C but with some quality of life features                                                                       |
| Zig            | Moderate          | Easy             | Quite verbose but has very good compatibility for compiling to wasm.                                                      |
| Nelua          | Easy              | Hard             | Easier on linux due to C, will be smaller and run faster than the plain lua option.                                       |
| Lua            | Easy              | Hard             | Easier to write than Nelua, but will result in a larger script file and slower runtime due to using an embedded runtime.  |
| Go/TinyGo      | Easy              | Easy             | TinyGo is a Go compiler that skips out on features that wasm can't support, such as OS threads.                           |
| AssemblyScript | Easy              | Easy             | Has some quirks compared to js/ts but is maybe the most friendly if you're coming from js/ts.                             |
| Kotlin         | Easy              | Moderate         | Probably best for those familiar with C# or java.                                                                         |
| Nim*           | Unknown           | Unknown          | API is low priority.                                                                                                      |
| Odin*          | Unknown           | Unknown          | API is low priority.                                                                                                      |
| D*             | Unknown           | Unknown          | API is low priority.                                                                                                      |
| V*             | Unknown           | Unknown          | API is low priority.                                                                                                      |
| Grain*         | Unknown           | Unknown          | API is low priority.                                                                                                      |

*These languages haven't been thoroughly evaluated, as they aren't as well known.


## Unsupported languages
These languages are not supportable, if you find a way to get one of these languages to properly compile to wasm32-wasip1,
open an issue, and it'll be moved to the table above.  

| Language              | Closest alternatives | Reason it's not supported                                                                           |
|-----------------------|----------------------|-----------------------------------------------------------------------------------------------------|
| TypeScript/JavaScript | AssemblyScript       | Can't properly target wasm32-wasip1.                                                                |
| Java                  | Kotlin               | Java's wasm ecosystem is built primarily around js runtimes and emscripten, which don't work here.  |
| C#                    | Kotlin               | C# also heavily relies on emscripten and a js runtime which don't work.                             |
| Python                | Lua/Nelua            | Technically possible, but I can't be bothered to write the very complex build system needed for it. |


# Turing API generator usage

Run the executable for your platform in the command line, with TuringApiGen as the current working directory  

The script will also read these files that are required for generating the APIs:  
- `./api-spec/dissallowed`  
- `./api-spec/type-map`  
- `./templates/**/*.tera`  

The script when run with no args will prompt you for the input file and output directory  
to run the script without user intervention, you can pass them in via the command line args:  
`--input=<...>` which expects the file path to your API spec file.  
`--output=<...>` which expects a directory to dump the output API files in.  


# API spec format

### Version:
`#version <version>`  
i.e. `#version 0.1.0-alpha`
the last line in the spec that specifies a version is the version used in the generated API code

### Classes:
marked as `:Class:`  
`:Global:` is a special case that puts any functions after it into the top-level scope of code

You can also add `[opaque]` into the label to mark the class as a typed pointer referring to a C# class  
i.e.: `:ColorNote [opaque]:`  

### Methods and Functions:
`[::]<name>([<arg>: <type>], ...) -> <return_type> [: <from>]`
If prefixed with `::`, the function is considered static, not taking the class object as an arg, otherwise the first arg is considered to be self/this  
The return type is required  

optionally, `: <from>` can be appended to link the function to a specific wasm binding, otherwise the function name with a prefixed underscore is used.  

### Variables:
`.<name>: <type> `  
adds this attribute to the class (invalid in global scope)  
if the class is opaque, attributes are all *after* the opaque pointer attribute  


# Language template

Language template files (`.tera`) are written in a format called `tera`, a templating system based on `jinja2`  
all templates operate over the following data structures:
```js
api {
    version: "0.0.1",
    semver: {
        major: 0,
        minor: 0,
        patch: 1
    },
    opaque_classes: ["class_name"],
    functions: [
        {
            name: "function_name",
            type: "return_type",
            params: [
                {
                    name: "parameter_name",
                    type: "parameter_type"
                }
            ]
        }
    ],
    classes: [
        {
            is_opaque: bool,
            name: "class_name",
            variables: [
                {
                    name: "attribute_name",
                    type: "attrubite_type"
                }
            ],
            methods: [
                {
                    name: "method_name",
                    type: "return_type",
                    params: [
                        {
                            name: "parameter_name",
                            type: "parameter_type"
                        }
                    ]
                }
            ],
            functions: [
                {
                    name: "function_name",
                    type: "return_type",
                    params: [
                        {
                            name: "parameter_name",
                            type: "parameter_type"
                        }
                    ]
                }
            ]
        }
    ]
}

types { // derived from .api-spec/type-map at runtime
    <lang>: {
        <base_type>: <actual_type>
    }
}

```


# Templating checklist:
- [x] rust api
- [x] rust template
- [x] shared C bindings (used for C, C++, Nelua)
- [x] C api
- [x] C template
- [x] C++ api
- [x] C++ template
- [ ] Zig api
- [ ] Zig template
- [ ] TinyGo api
- [ ] TinyGo template
- [ ] Nelua api
- [ ] Nelua template
- [ ] Lua api
- [ ] Lua template
- [x] Kotlin api
- [x] Kotlin template
- [ ] AsmScript api
- [ ] AsmScript template
- [ ] Nim api
- [ ] Nim template
- [ ] Grain api
- [ ] Grain template
- [ ] Odin api
- [ ] Odin template
- [ ] V api
- [ ] V template
- [ ] D api
- [ ] D template




