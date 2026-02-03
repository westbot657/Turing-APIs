# How to set up project and compile

Required dependencies:
- TinyGo compiler

Setup instructions:
1. copy the entire `go-template` directory
2. open in an IDE

Compile project:
1. run `tinygo build -target=wasi -opt=z -panic=abort -o script.wasm`