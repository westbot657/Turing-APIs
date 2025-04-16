// Turing API - C++
// License: GPL-2.0-only
// Authors: Westbot
// <auto-converted from the rust api />

#ifndef TURING_API_HPP
#define TURING_API_HPP

#include <wasm_imports.h>

// C++.h class 'ColorNote'
class ColorNote {
    public:
        int ptr;
};
// C++.h class 'BombNote'
class BombNote {
    public:
        int ptr;
};
// C++.h class 'Arc'
class Arc {
    public:
        int ptr;
};
// C++.h class 'Wall'
class Wall {
    public:
        int ptr;
};
// C++.h class 'ChainHeadNote'
class ChainHeadNote {
    public:
        int ptr;
};
// C++.h class 'ChainLinkNote'
class ChainLinkNote {
    public:
        int ptr;
};
// C++.h class 'ChainNote'
class ChainNote {
    public:
        int ptr;
};

// C++.h class 'Color'
class Color {
    public:
        int ptr;
};

// C++.h class 'Log'
class Log {
    public:

        static void info(char* msg);

        static void warn(char* msg);

        static void critical(char* msg);

        static void debug(char* msg);

};

ColorNote create_color_note(float beat);

BombNote create_bomb_note(float beat);

Arc create_arc(float beat);

Wall create_wall(float beat);

ChainHeadNote create_chain_head_note(float beat);

ChainLinkNote create_chain_link_note(float beat);

ChainNote create_chain_note(float beat);

// C++.h class 'Beatmap'
class Beatmap {
    public:
        static void add_chain_note(ChainNote chain_note);
        static void remove_chain_note(ChainNote chain_note);
        static void add_chain_link_note(ChainLinkNote chain_link_note);
        static void remove_chain_link_note(ChainLinkNote chain_link_note);
        static void add_chain_head_note(ChainHeadNote chain_head_note);
        static void remove_chain_head_note(ChainHeadNote chain_head_note);
        static void add_wall(Wall wall);
        static void remove_wall(Wall wall);
        static void add_arc(Arc arc);
        static void remove_arc(Arc arc);
        static void add_bomb_note(BombNote bomb_note);
        static void remove_bomb_note(BombNote bomb_note);
        static void add_color_note(ColorNote color_note);
        static void remove_color_note(ColorNote color_note);
};

#endif // TURING_API_HPP