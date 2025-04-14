
#include <turing_api_c.h>

extern void on_load(void) {

}

extern void on_update(float beat) {

    ColorNote note = createColorNote(beat+2);

    Beatmap_addColorNote(note);

}

extern void on_exit(void) {

}
