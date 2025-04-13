
#include "turing_api.h"


ColorNote createColorNote(float beat) {
    ColorNote note;
    note.id = _create_color_note(beat);
    return note;
}


void Beatmap_addColorNote(ColorNote note) {
    _beatmap_add_color_note(note.id);
}



