#include "../api/turing_api_cpp.hpp"

extern "C" {

void on_load() {
  // Called on map start
}

void on_update() {
  // Called every frame
}

void on_exit() {
  // Called on map fail/end/quit
}

// Add more hooks as needed

} // extern "C"

int main() { return 0; }