#include "../api/turing_api_cpp.hpp"
#include "glm/ext/vector_float2.hpp"


#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <glm/mat4x4.hpp>               // glm::mat4
#include <glm/vec3.hpp>                 // glm::vec3
#include <glm/vec4.hpp>                 // glm::vec4

/// this macro ensures the function is exported correctly in WebAssembly
/// since Emscripten doesn't export extern "C" functions by default (it seems)
/// - Fern
#define WASM_EXPORT(name) __attribute__((visibility("default"))) __attribute__((used)) __attribute__((export_name(name)))

extern "C" {

WASM_EXPORT("on_load") void on_load() {
  glm::vec2 v2(1.0f, 2.0f);
  glm::vec3 v3(1.0f, 2.0f, 3.0f);

  v2 = v2 + glm::vec2(3.0f, 4.0f);
  v3 = v3 + glm::vec3(3.0f, 4.0f, 5.0f);

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


// unused, only for building
int main() {
    return 0;
}