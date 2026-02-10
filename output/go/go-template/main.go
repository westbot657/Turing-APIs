package main

import "github.com/westbot657/turing-apis/output/go/turing-api-go"

//export on_load
func on_load() {
    turingapi.Log_info("Hello from Go wasm!")
}

//export on_update
func on_update() {

}

//export on_exit
func on_exit() {

}

