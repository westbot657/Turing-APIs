#ifndef TURING_API_H
#define TURING_API_H

#include <wasm_imports.h>

typedef struct {
    int id;
} ColorNote;


ColorNote createColorNote(float beat);

void Beatmap_addColorNote(ColorNote note);


#endif // TURING_API_H