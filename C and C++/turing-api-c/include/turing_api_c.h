// Turing API - C
// License: GPL-2.0-only
// Authors: Westbot
// <auto-converted from the rust api />

#ifndef TURING_API_H
#define TURING_API_H

#include <wasm_imports.h>

typedef struct {
    int ptr;
} Color;

float Color_get_r(Color* self);

void Color_set_r(Color* self, float r);

float Color_get_g(Color* self);

void Color_set_g(Color* self, float g);

float Color_get_b(Color* self);

void Color_set_b(Color* self, float b);

float Color_get_a(Color* self);

void Color_set_a(Color* self, float a);

void Color_set_rgb(Color* self, float r, float g, float b);

void Color_set_rgba(Color* self, float r, float g, float b, float a);

void Log_info(const char* msg);

void Log_warn(const char* msg);

void Log_critical(const char* msg);

void Log_debug(const char* msg);

typedef struct {
    int ptr;
} Vec2;

Vec2 Vec2_from_xy(float x, float y);

float Vec2_get_x(Vec2* self);

float Vec2_get_y(Vec2* self);

typedef struct {
    int ptr;
} Vec3;

Vec3 Vec3_from_xyz(float x, float y, float z);

float Vec3_get_x(Vec3* self);

float Vec3_get_y(Vec3* self);

float Vec3_get_z(Vec3* self);

typedef struct {
    int ptr;
} Vec4;

Vec4 Vec4_from_xyzw(float x, float y, float z, float w);

float Vec4_get_x(Vec4* self);

float Vec4_get_y(Vec4* self);

float Vec4_get_z(Vec4* self);

float Vec4_get_w(Vec4* self);

typedef struct {
    int ptr;
} Quat;

Quat Quat_from_xyzw(float x, float y, float z, float w);

float Quat_get_x(Quat* self);

float Quat_get_y(Quat* self);

float Quat_get_z(Quat* self);

float Quat_get_w(Quat* self);

typedef struct {
    int ptr;
} ColorNote;
Color ColorNote_get_color(ColorNote* self);
void ColorNote_set_color(ColorNote* self, Color color);
Vec3 ColorNote_get_position(ColorNote* self);
void ColorNote_set_position(ColorNote* self, Vec3 position);
Quat ColorNote_get_orientation(ColorNote* self);
void ColorNote_set_orientation(ColorNote* self, Quat orientation);
typedef struct {
    int ptr;
} BombNote;
Color BombNote_get_color(BombNote* self);
void BombNote_set_color(BombNote* self, Color color);
Vec3 BombNote_get_position(BombNote* self);
void BombNote_set_position(BombNote* self, Vec3 position);
Quat BombNote_get_orientation(BombNote* self);
void BombNote_set_orientation(BombNote* self, Quat orientation);
typedef struct {
    int ptr;
} Arc;
Color Arc_get_color(Arc* self);
void Arc_set_color(Arc* self, Color color);
Vec3 Arc_get_position(Arc* self);
void Arc_set_position(Arc* self, Vec3 position);
Quat Arc_get_orientation(Arc* self);
void Arc_set_orientation(Arc* self, Quat orientation);
typedef struct {
    int ptr;
} Wall;
Color Wall_get_color(Wall* self);
void Wall_set_color(Wall* self, Color color);
Vec3 Wall_get_position(Wall* self);
void Wall_set_position(Wall* self, Vec3 position);
Quat Wall_get_orientation(Wall* self);
void Wall_set_orientation(Wall* self, Quat orientation);
typedef struct {
    int ptr;
} ChainHeadNote;
Color ChainHeadNote_get_color(ChainHeadNote* self);
void ChainHeadNote_set_color(ChainHeadNote* self, Color color);
Vec3 ChainHeadNote_get_position(ChainHeadNote* self);
void ChainHeadNote_set_position(ChainHeadNote* self, Vec3 position);
Quat ChainHeadNote_get_orientation(ChainHeadNote* self);
void ChainHeadNote_set_orientation(ChainHeadNote* self, Quat orientation);
typedef struct {
    int ptr;
} ChainLinkNote;
Color ChainLinkNote_get_color(ChainLinkNote* self);
void ChainLinkNote_set_color(ChainLinkNote* self, Color color);
Vec3 ChainLinkNote_get_position(ChainLinkNote* self);
void ChainLinkNote_set_position(ChainLinkNote* self, Vec3 position);
Quat ChainLinkNote_get_orientation(ChainLinkNote* self);
void ChainLinkNote_set_orientation(ChainLinkNote* self, Quat orientation);
typedef struct {
    int ptr;
} ChainNote;
Color ChainNote_get_color(ChainNote* self);
void ChainNote_set_color(ChainNote* self, Color color);
Vec3 ChainNote_get_position(ChainNote* self);
void ChainNote_set_position(ChainNote* self, Vec3 position);
Quat ChainNote_get_orientation(ChainNote* self);
void ChainNote_set_orientation(ChainNote* self, Quat orientation);

ColorNote create_color_note(float beat);

BombNote create_bomb_note(float beat);

Arc create_arc(float beat);

Wall create_wall(float beat);

ChainHeadNote create_chain_head_note(float beat);

ChainLinkNote create_chain_link_note(float beat);

ChainNote create_chain_note(float beat);

void Beatmap_add_color_note(ColorNote color_note);
void Beatmap_remove_color_note(ColorNote color_note);
ColorNote Beatmap_get_color_note_at_beat(float beat);
void Beatmap_add_bomb_note(BombNote bomb_note);
void Beatmap_remove_bomb_note(BombNote bomb_note);
BombNote Beatmap_get_bomb_note_at_beat(float beat);
void Beatmap_add_arc(Arc arc);
void Beatmap_remove_arc(Arc arc);
Arc Beatmap_get_arc_at_beat(float beat);
void Beatmap_add_wall(Wall wall);
void Beatmap_remove_wall(Wall wall);
Wall Beatmap_get_wall_at_beat(float beat);
void Beatmap_add_chain_head_note(ChainHeadNote chain_head_note);
void Beatmap_remove_chain_head_note(ChainHeadNote chain_head_note);
ChainHeadNote Beatmap_get_chain_head_note_at_beat(float beat);
void Beatmap_add_chain_link_note(ChainLinkNote chain_link_note);
void Beatmap_remove_chain_link_note(ChainLinkNote chain_link_note);
ChainLinkNote Beatmap_get_chain_link_note_at_beat(float beat);
void Beatmap_add_chain_note(ChainNote chain_note);
void Beatmap_remove_chain_note(ChainNote chain_note);
ChainNote Beatmap_get_chain_note_at_beat(float beat);

#endif // TURING_API_H