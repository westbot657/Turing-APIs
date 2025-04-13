#ifndef TURING_API_HPP
#define TURING_API_HPP

#include "wasm_imports.h"

namespace TuringAPI {

    class ColorNote {
        public:
            explicit ColorNote(float beat);
        
        private:
            int id;

            friend class Beatmap;
        
    };

    class Beatmap {

        public:
            static void addColorNote(ColorNote note);

    };

} // namespace TuringAPI

#endif // TURING_API_HPP