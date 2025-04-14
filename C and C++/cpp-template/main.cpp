
#include <turing_api_cpp.hpp>


    extern "C" void on_load(void) {

    }

    extern "C" void on_update(float beat) {

        ColorNote note = ColorNote::create(beat);

        Beatmap::addColorNote(note);

    }

    extern "C" void on_exit(void) {

    }