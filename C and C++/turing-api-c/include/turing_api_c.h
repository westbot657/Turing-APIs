// Turing API - C
// License: GPL-2.0-only
// Authors: Westbot
// <auto-converted from the rust api />

#ifndef TURING_API_H
#define TURING_API_H

#include <wasm_imports.h>

typedef struct {
    int ptr;
} ColorNote;
typedef struct {
    int ptr;
} BombNote;
typedef struct {
    int ptr;
} Arc;
typedef struct {
    int ptr;
} Wall;
typedef struct {
    int ptr;
} ChainHeadNote;
typedef struct {
    int ptr;
} ChainLinkNote;
typedef struct {
    int ptr;
} ChainNote;

typedef struct {
    int ptr;
} Color;

void Log_info(const char* msg);

void Log_warn(const char* msg);

void Log_critical(const char* msg);

void Log_debug(const char* msg);

ColorNote create_color_note(float beat);

BombNote create_bomb_note(float beat);

Arc create_arc(float beat);

Wall create_wall(float beat);

ChainHeadNote create_chain_head_note(float beat);

ChainLinkNote create_chain_link_note(float beat);

ChainNote create_chain_note(float beat);

void Beatmap_add_chain_note(ChainNote chain_note);
void Beatmap_remove_chain_note(ChainNote chain_note);
void Beatmap_add_chain_link_note(ChainLinkNote chain_link_note);
void Beatmap_remove_chain_link_note(ChainLinkNote chain_link_note);
void Beatmap_add_chain_head_note(ChainHeadNote chain_head_note);
void Beatmap_remove_chain_head_note(ChainHeadNote chain_head_note);
void Beatmap_add_wall(Wall wall);
void Beatmap_remove_wall(Wall wall);
void Beatmap_add_arc(Arc arc);
void Beatmap_remove_arc(Arc arc);
void Beatmap_add_bomb_note(BombNote bomb_note);
void Beatmap_remove_bomb_note(BombNote bomb_note);
void Beatmap_add_color_note(ColorNote color_note);
void Beatmap_remove_color_note(ColorNote color_note);

#endif // TURING_API_H