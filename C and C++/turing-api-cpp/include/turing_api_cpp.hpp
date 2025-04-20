// Turing API - C++
// License: GPL-2.0-only
// Authors: Westbot
// <auto-converted from the rust api />

#ifndef TURING_API_HPP
#define TURING_API_HPP

#include <wasm_imports.h>

// C++.h class 'Color'
class Color {
    public:
        int ptr;
        float get_r();

        void set_r(float r);

        float get_g();

        void set_g(float g);

        float get_b();

        void set_b(float b);

        float get_a();

        void set_a(float a);

        void set_rgb(float r, float g, float b);

        void set_rgba(float r, float g, float b, float a);

};

// C++.h class 'Log'
class Log {
    public:

        static void info(char* msg);

        static void warn(char* msg);

        static void critical(char* msg);

        static void debug(char* msg);

};

// C++.h class 'Vec2'
class Vec2 {
    public:
        int ptr;
        static Vec2 from_xy(float x, float y);

        float get_x();

        float get_y();

};

// C++.h class 'Vec3'
class Vec3 {
    public:
        int ptr;
        static Vec3 from_xyz(float x, float y, float z);

        float get_x();

        float get_y();

        float get_z();

};

// C++.h class 'Vec4'
class Vec4 {
    public:
        int ptr;
        static Vec4 from_xyzw(float x, float y, float z, float w);

        float get_x();

        float get_y();

        float get_z();

        float get_w();

};

// C++.h class 'Quat'
class Quat {
    public:
        int ptr;
        static Quat from_xyzw(float x, float y, float z, float w);

        float get_x();

        float get_y();

        float get_z();

        float get_w();

};

// C++.h class 'ColorNote'
class ColorNote {
    public:
        int ptr;
        Color get_color();
        void set_color(Color color);
        Vec3 get_position();
        void set_position(Vec3 position);
        Quat get_orientation();
        void set_orientation(Quat orientation);
};
// C++.h class 'BombNote'
class BombNote {
    public:
        int ptr;
        Color get_color();
        void set_color(Color color);
        Vec3 get_position();
        void set_position(Vec3 position);
        Quat get_orientation();
        void set_orientation(Quat orientation);
};
// C++.h class 'Arc'
class Arc {
    public:
        int ptr;
        Color get_color();
        void set_color(Color color);
        Vec3 get_position();
        void set_position(Vec3 position);
        Quat get_orientation();
        void set_orientation(Quat orientation);
};
// C++.h class 'Wall'
class Wall {
    public:
        int ptr;
        Color get_color();
        void set_color(Color color);
        Vec3 get_position();
        void set_position(Vec3 position);
        Quat get_orientation();
        void set_orientation(Quat orientation);
};
// C++.h class 'ChainHeadNote'
class ChainHeadNote {
    public:
        int ptr;
        Color get_color();
        void set_color(Color color);
        Vec3 get_position();
        void set_position(Vec3 position);
        Quat get_orientation();
        void set_orientation(Quat orientation);
};
// C++.h class 'ChainLinkNote'
class ChainLinkNote {
    public:
        int ptr;
        Color get_color();
        void set_color(Color color);
        Vec3 get_position();
        void set_position(Vec3 position);
        Quat get_orientation();
        void set_orientation(Quat orientation);
};
// C++.h class 'ChainNote'
class ChainNote {
    public:
        int ptr;
        Color get_color();
        void set_color(Color color);
        Vec3 get_position();
        void set_position(Vec3 position);
        Quat get_orientation();
        void set_orientation(Quat orientation);
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
        static void add_color_note(ColorNote color_note);
        static void remove_color_note(ColorNote color_note);
        static ColorNote get_color_note_at_beat(float beat);
        static void add_bomb_note(BombNote bomb_note);
        static void remove_bomb_note(BombNote bomb_note);
        static BombNote get_bomb_note_at_beat(float beat);
        static void add_arc(Arc arc);
        static void remove_arc(Arc arc);
        static Arc get_arc_at_beat(float beat);
        static void add_wall(Wall wall);
        static void remove_wall(Wall wall);
        static Wall get_wall_at_beat(float beat);
        static void add_chain_head_note(ChainHeadNote chain_head_note);
        static void remove_chain_head_note(ChainHeadNote chain_head_note);
        static ChainHeadNote get_chain_head_note_at_beat(float beat);
        static void add_chain_link_note(ChainLinkNote chain_link_note);
        static void remove_chain_link_note(ChainLinkNote chain_link_note);
        static ChainLinkNote get_chain_link_note_at_beat(float beat);
        static void add_chain_note(ChainNote chain_note);
        static void remove_chain_note(ChainNote chain_note);
        static ChainNote get_chain_note_at_beat(float beat);
};

#endif // TURING_API_HPP