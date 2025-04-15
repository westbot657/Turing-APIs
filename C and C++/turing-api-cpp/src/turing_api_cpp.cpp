// Turing API - C++
// License: GPL-2.0-only
// Authors: Westbot

#include <wasm_imports.h>
#include <turing_api_cpp.hpp>

#include <string>

ColorNote ColorNote::create(float beat) {
    int id = _create_color_note(beat);
    ColorNote note = ColorNote {};
    note.id = id;
    return note;
};


void Beatmap::addColorNote(ColorNote note) {
    _beatmap_add_color_note(note.id);
};


