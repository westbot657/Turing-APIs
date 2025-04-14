#ifndef TURING_API_HPP
#define TURING_API_HPP

#include <wasm_imports.h>

class ColorNote {
    public:
        static ColorNote create(float beat);
    
    private:
        int id;

        friend class Beatmap;
    
};

class Beatmap {

    public:
        static void addColorNote(ColorNote note);

};


#endif // TURING_API_HPP