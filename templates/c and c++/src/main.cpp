#include "../api/turing_api_cpp.hpp"

/// this macro ensures the function is exported correctly in WebAssembly
/// since Emscripten doesn't export extern "C" functions by default (it seems)
/// - Fern
#define WASM_EXPORT(name) __attribute__((visibility("default"))) __attribute__((used)) __attribute__((export_name(name)))

extern "C" {

WASM_EXPORT("on_load") void on_load() {
  // Called on map start
}

WASM_EXPORT("on_update") void on_update() {
  // Called every frame
}

WASM_EXPORT("on_exit") void on_exit() {
  // Called on map fail/end/quit
}

// Add more hooks as needed

} // extern "C"