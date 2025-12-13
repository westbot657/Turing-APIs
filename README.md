# Turing

## Language support

### You can use this table to pick a language to use for writing scripts  
If your preferred language isn't on this list, you can still use it as long as it compiles to wasm32-wasip1 (wasi preview 1) but if you want full API support, make an issue (or write it yourself and make a PR)  

| Language               | Coding complexity | Build complexity | Notes                                |
|------------------------|-------------------|------------------|--------------------------------------|
| Rust                   | Moderate          | Very easy        |                                      |
| C                      | Moderate          | Hard             | build complexity is better on linux  |
| C++                    | Easier ish than C | Hard             | also easier on linux                 |
| Zig                    | Easy              | Easy             |                                      |
| Lua (nelua)            | Easy              | Hard             | easier on linux due to C             |
| Go (tinyGo)            | Easy              | Easy             |                                      |
| TypeScript (AsmScript) | Very easy         | Very easy        |                                      |
| Kotlin                 | Very easy         | Moderate         |                                      |
| Nim*                   | Unknown           | Unknown          | API is low priority                  |
| Odin*                  | Unknown           | Unknown          | API is low priority                  |
| D*                     | Unknown           | Unknown          | API is low priority                  |
| V*                     | Unknown           | Unknown          | API is low priority                  |
| Grain*                 | Unknown           | Unknown          | API is low priority                  |

*These languages haven't been thoroughly evaluated.








# Turing API generator usage

Run the executable for your platform in the command line, with TuringApiGen as the current working directory  

The script will also read these files that are requried for generating the APIs:  
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
    version: "0.0.1-semver",
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
- [x] shared C bindings (used for C, C++, nelua)
- [ ] C api
- [ ] C template
- [ ] C++ api
- [ ] C++ template
- [ ] Zig api
- [ ] Zig template
- [ ] TinyGo api
- [ ] TinyGo template
- [ ] Nelua api
- [ ] Nelua template
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




