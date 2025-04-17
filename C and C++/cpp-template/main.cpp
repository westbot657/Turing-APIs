
#include <turing_api_cpp.hpp>


extern "C" void on_load(void) {
    Log::info("C++ Script loaded!");
}

extern "C" void on_update(float beat) {

    ColorNote note = create_color_note(beat);

    Beatmap::add_color_note(note);

}

extern "C" void on_exit(void) {

}