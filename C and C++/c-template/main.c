
#include <turing_api_c.h>

extern void on_load(void) {
    Log_info("Script loaded!");
}

extern void on_update(float beat) {

    ColorNote note = create_color_note(beat+2);

    Beatmap_add_color_note(note);

}

extern void on_exit(void) {

}
