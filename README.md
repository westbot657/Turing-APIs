# Turing

All Templates and APIs can be found under [output/](./output), each language directory contains a README.md file
explaining how to set up and use the API for that language.  

## Supported languages

You can use this table to pick a language to use for writing scripts  

### Wasm based languages
| Language       | Coding complexity | Build complexity | Notes                                                                                           |
|----------------|-------------------|------------------|-------------------------------------------------------------------------------------------------|
| Rust           | Hard              | Easy             | Natively supports compilation to wasm32-wasip1.                                                 |
| C              | Hard              | Hard             | Build complexity is better on linux or with the zig compiler.                                   |
| C++            | Hard              | Hard             | Also easier on linux or with the zig compiler.                                                  |
| C3             | Moderate          | Moderate         | Similar to C but with some quality of life features                                             |
| Zig            | Moderate          | Easy             | Quite verbose but has very good compatibility for compiling to wasm.                            |
| Go/TinyGo      | Easy              | Easy             | TinyGo is a Go compiler that skips out on features that wasm can't support, such as OS threads. |
| AssemblyScript | Easy              | Easy             | Has some quirks compared to js/ts but is maybe the most friendly if you're coming from js/ts.   |
| Kotlin         | Easy              | Moderate         | Probably best for those familiar with C# or java.                                               |
| C#             | Easy              | Unknown          | Theoretically possible via .NET 8 but untested                                                  |
| Java           | Moderate          | Unknown          | Theoretically possible via TeaVM but untested                                                   |
| Nim*           | Unknown           | Unknown          | API is low priority.                                                                            |
| Odin*          | Unknown           | Unknown          | API is low priority.                                                                            |
| D*             | Unknown           | Unknown          | API is low priority.                                                                            |
| V*             | Unknown           | Unknown          | API is low priority.                                                                            |
| Grain*         | Unknown           | Unknown          | API is low priority.                                                                            |

*These languages haven't been thoroughly evaluated, as they aren't as well known, however you are still able to use them, but you will have to use the raw bindings directly.

### Other supported languages
| Language              | Coding Complexity | Notes                                           |
|-----------------------|-------------------|-------------------------------------------------|
| Lua                   | Easy              | Very easy to use, but may run slower than wasm. |
| JavaScript/TypeScript | Easy              | Not implemented.                                |
| Python                | Easy              | Not implemented.                                |

### Unsupported languages
If your preferred language is not listed in either of the above tables, it's because it's not widely known.  
You have 2 options for getting your language to work:  
1. get it to compile to wasm32 wasi preview 1 (wasm32-wasip1), or wasm32 standalone/freestanding.  
2. See if there's an interpreter for it written in rust, and then create an issue for us to look into it.  
If you get either of these scenarios, make an issue for API support or make a PR adding it yourself.  

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
i.e. `#version 0.1.0`
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
- [x] Zig api
- [x] Zig template
- [x] TinyGo api
- [x] TinyGo template
- [x] Lua api
- [x] Lua template
- [x] Kotlin api
- [x] Kotlin template
- [x] AsmScript api
- [x] AsmScript template
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


# Raw API Bindings
Turing API is not actually needed to interact with Turing, but it does provide a lot of utilities to make it easier.
If your language does not have API support currently, here are the main rules for the typing convention:

### Strings
Strings are complicated as Turing is unable to return a string directly to wasm, instead it will return the string length as a `u32`,
and the guest code is expected to allocate a chunk of memory and call `_host_strcpy(pointer, size)` where the pointer is the location you allocated,
and the size is for sanity checking that you are fetching the correct string.

When passing a string to the host, you must pass a pointer to a null-terminated string.

### Linear Algebra Types
Vec2, Vec3, Vec4, Quat, and Mat4 are passed via `_host_f32_enqueue(f32)` and `_host_f32_dequeue() -> f32` to push/pop each component.
The API wraps this system to use native libraries where possible, each library is shown below

| Language  | Setting           | Libraries | Notes                                                                   |
|-----------|-------------------|-----------|-------------------------------------------------------------------------|
| Rust      | feature: glam     | glam      |                                                                         |
| Rust      | feature: nalgebra | nalgebra  | Can be used instead of glam if you prefer                               |
| C         | default           | cglm      | https://github.com/recp/cglm                                            |
| C++       | default           | glm       | https://github.com/g-truc/glm                                           |
| Zig       | default           | zalgebra  | https://github.com/kooparse/zalgebra                                    |
| Kotlin    | default           | N/A       | TODO: find a pure-kotlin implementation without reliance on jvm systems |
| Go        | default           | N/A       | TODO: find/write a pure-go implementation that can work in tinygo       |
| asmscript | default           | N/A       | TODO: find/write implementation                                         |

### Objects
Unity objects such as notes, walls, etc, are represented with a `u64` opaque pointer. Turing maps this id to the real object, this keeps scripts safe,
by not letting them touch memory directly.

### Expected Exports
currently, Turing will require you to export `_turing_api_semver() -> u64` which must return the semantic version as a packed `u64`:
Major: u32, bit shifted left by 32 into a u64.
Minor: u16, bit shifted left by 16 into a u64.





