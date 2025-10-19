
# Turing API generator usage

Run the executable for your platform in the command line, with TuringApiGen as the current working directory  

The script will also read these files that are requried for generating the APIs:  
- ./api-spec/dissallowed  
- ./api-spec/type-map  
- ./templates/*.tera  

The script when run with no args will prompt you for the input file and output directory  
to run the script without user intervention, you can pass them in via the command line args:  
`--input=<...>` which expects the file path to your API spec file.  
`--output=<...>` which expects a directory to dump the output API files in.  


# API spec format

### Classes:
marked as `:Class:`  
`:Global:` is a special case that puts any functions after it into the top-level scope of code

Yout can also add `[opaque]` into the label to mark the class as a typed pointer referring to a C# class  
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

Language template files (`.tera`) are written in a format called `tera`, a slightly less advanced version of the `twig` format  
all templates operate over the following data structures:
```json
api {
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


