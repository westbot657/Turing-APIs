#ifndef WASM_IMPORTS_H
#define WASM_IMPORTS_H

#ifdef __cplusplus
extern "C" {
#endif

extern int _create_color_note(float beat);
extern void _beatmap_add_color_note(int note_id);


#ifdef __cplusplus
}
#endif

#endif // WASM_IMPORTS_H