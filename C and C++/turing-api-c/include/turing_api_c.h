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
} ColorNote;
Color ColorNote_get_color(ColorNote* self);
typedef struct {
    int ptr;
} BombNote;
Color BombNote_get_color(BombNote* self);
typedef struct {
    int ptr;
} Arc;
Color Arc_get_color(Arc* self);
typedef struct {
    int ptr;
} Wall;
Color Wall_get_color(Wall* self);
typedef struct {
    int ptr;
} ChainHeadNote;
Color ChainHeadNote_get_color(ChainHeadNote* self);
typedef struct {
    int ptr;
} ChainLinkNote;
Color ChainLinkNote_get_color(ChainLinkNote* self);
typedef struct {
    int ptr;
} ChainNote;
Color ChainNote_get_color(ChainNote* self);

ColorNote create_color_note(float beat);

BombNote create_bomb_note(float beat);

Arc create_arc(float beat);

Wall create_wall(float beat);

ChainHeadNote create_chain_head_note(float beat);

ChainLinkNote create_chain_link_note(float beat);

ChainNote create_chain_note(float beat);

void Beatmap_add_color_note(ColorNote color_note);
void Beatmap_remove_color_note(ColorNote color_note);
void Beatmap_add_bomb_note(BombNote bomb_note);
void Beatmap_remove_bomb_note(BombNote bomb_note);
void Beatmap_add_arc(Arc arc);
void Beatmap_remove_arc(Arc arc);
void Beatmap_add_wall(Wall wall);
void Beatmap_remove_wall(Wall wall);
void Beatmap_add_chain_head_note(ChainHeadNote chain_head_note);
void Beatmap_remove_chain_head_note(ChainHeadNote chain_head_note);
void Beatmap_add_chain_link_note(ChainLinkNote chain_link_note);
void Beatmap_remove_chain_link_note(ChainLinkNote chain_link_note);
void Beatmap_add_chain_note(ChainNote chain_note);
void Beatmap_remove_chain_note(ChainNote chain_note);

#endif // TURING_API_H