
#include "turing_api.hpp"


namespace TuringAPI {

    ColorNote::ColorNote(float beat) {
        id = _create_color_note(beat);
    };


    void Beatmap::addColorNote(ColorNote note) {
        _beatmap_add_color_note(note.id);
    };

}
