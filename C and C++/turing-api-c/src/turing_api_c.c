// Turing API - C
// License: GPL-2.0-only
// Authors: Westbot
// <auto-converted from the rust api />

#include <turing_api_c.h>

// wasm-std.c
#ifndef NULL
#define NULL ((void*)0)
#endif

// Simple memory manager for WebAssembly
#define HEAP_SIZE 65536  // 64 KB heap
static unsigned char heap[HEAP_SIZE];

// Memory block header structure
typedef struct block_header {
    int size;                  // Size of the block (not including header)
    unsigned char used;        // 1 if block is allocated, 0 if free
    struct block_header* next; // Next block in the list
} block_header_t;

// Initialize the first free block to cover the entire heap
static block_header_t* free_list = (block_header_t*)heap;

// Function to initialize the heap
void init_heap() {
    free_list->size = HEAP_SIZE - sizeof(block_header_t);
    free_list->used = 0;
    free_list->next = (block_header_t*) NULL;
}

// Function to find a free block of sufficient size
static block_header_t* find_free_block(int size) {
    // If heap is not initialized, do it now
    if (free_list->size == 0) {
        init_heap();
    }
    
    block_header_t* current = free_list;
    
    while (current) {
        if (!current->used && current->size >= size) {
            return current;
        }
        current = current->next;
    }
    
    return (block_header_t*) NULL; // No suitable block found
}

// Function to split a block if it's much larger than needed
static void split_block(block_header_t* block, int size) {
    // Only split if the difference is large enough to store a new block header plus some data
    if (block->size >= size + sizeof(block_header_t) + 4) {
        block_header_t* new_block = (block_header_t*)((unsigned char*)block + sizeof(block_header_t) + size);
        new_block->size = block->size - size - sizeof(block_header_t);
        new_block->used = 0;
        new_block->next = block->next;
        
        block->size = size;
        block->next = new_block;
    }
}

// Malloc implementation
void* malloc(int size) {
    if (size == 0) {
        return NULL;
    }
    
    // Align size to 8 bytes (common alignment requirement)
    size = (size + 3) & ~3;
    
    block_header_t* block = find_free_block(size);
    if (!block) {
        return NULL; // Out of memory
    }
    
    // Mark the block as used
    block->used = 1;
    
    // Split the block if it's much larger than needed
    split_block(block, size);
    
    // Return pointer to the data area
    return (void*)((unsigned char*)block + sizeof(block_header_t));
}

// Coalesce adjacent free blocks
static void coalesce() {
    block_header_t* current = (block_header_t*)heap;
    
    while (current && current->next) {
        if (!current->used && !current->next->used) {
            // Merge current with next
            current->size += sizeof(block_header_t) + current->next->size;
            current->next = current->next->next;
            // Continue from current position to check for more merges
        } else {
            // Move to next block
            current = current->next;
        }
    }
}

// Free implementation
void free(void* ptr) {
    if (!ptr) {
        return;
    }
    
    // Get the block header
    block_header_t* block = (block_header_t*)((unsigned char*)ptr - sizeof(block_header_t));
    
    // Mark the block as free
    block->used = 0;
    
    // Coalesce adjacent free blocks
    coalesce();
}

// String functions

// Copy a string
char* strcpy(char* dest, const char* src) {
    char* original_dest = dest;
    
    while ((*dest++ = *src++));
    
    return original_dest;
}

// Concatenate strings
char* strcat(char* dest, const char* src) {
    char* original_dest = dest;
    
    // Find the end of dest
    while (*dest) {
        dest++;
    }
    
    // Copy src to the end of dest
    while ((*dest++ = *src++));
    
    return original_dest;
}

// Calculate string length
int strlen(const char* str) {
    const char* s = str;
    
    while (*s) {
        s++;
    }
    
    return s - str;
}
// end wasm-std.c
char* concat_strings(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* result = malloc(len1 + len2 + 1); // +1 for null terminator
    if (result) {
        strcpy(result, str1);
        strcat(result, str2);
    }
    return result;
}

// C class Color

float Color_get_r(Color* self) {
    return _color_get_r(self->ptr);
}

void Color_set_r(Color* self, float r) {
    _color_set_r(self->ptr, r);
}

float Color_get_g(Color* self) {
    return _color_get_g(self->ptr);
}

void Color_set_g(Color* self, float g) {
    _color_set_g(self->ptr, g);
}

float Color_get_b(Color* self) {
    return _color_get_b(self->ptr);
}

void Color_set_b(Color* self, float b) {
    _color_set_b(self->ptr, b);
}

float Color_get_a(Color* self) {
    return _color_get_a(self->ptr);
}

void Color_set_a(Color* self, float a) {
    _color_set_a(self->ptr, a);
}

void Color_set_rgb(Color* self, float r, float g, float b) {
    _color_set_rgb(self->ptr, r, g, b);
}

void Color_set_rgba(Color* self, float r, float g, float b, float a) {
    _color_set_rgba(self->ptr, r, g, b, a);
}

// C class Log

void Log_info(const char* msg) {
    char* s = concat_strings("info: ", msg);
        _log(s);
        free(s);
}

void Log_warn(const char* msg) {
    char* s = concat_strings("warn: ", msg);
        _log(s);
        free(s);
}

void Log_critical(const char* msg) {
    char* s = concat_strings("error: ", msg);
        _log(s);
        free(s);
}

void Log_debug(const char* msg) {
    char* s = concat_strings("debug: ", msg);
        _log(s);
        free(s);
}

// C class Vec2

Vec2 Vec2_from_xy(float x, float y) {
    Vec2 inst;
        inst.ptr = _vec2_from_xy(x, y);
        return inst;
}

float Vec2_get_x(Vec2* self) {
    return _vec2_get_x(self->ptr);
}

float Vec2_get_y(Vec2* self) {
    return _vec2_get_y(self->ptr);
}

// C class Vec3

Vec3 Vec3_from_xyz(float x, float y, float z) {
    Vec3 inst;
        inst.ptr = _vec3_from_xyz(x, y, z);
        return inst;
}

float Vec3_get_x(Vec3* self) {
    return _vec3_get_x(self->ptr);
}

float Vec3_get_y(Vec3* self) {
    return _vec3_get_y(self->ptr);
}

float Vec3_get_z(Vec3* self) {
    return _vec3_get_z(self->ptr);
}

// C class Vec4

Vec4 Vec4_from_xyzw(float x, float y, float z, float w) {
    Vec4 inst;
        inst.ptr = _vec4_from_xyzw(x, y, z, w);
        return inst;
}

float Vec4_get_x(Vec4* self) {
    return _vec4_get_x(self->ptr);
}

float Vec4_get_y(Vec4* self) {
    return _vec4_get_y(self->ptr);
}

float Vec4_get_z(Vec4* self) {
    return _vec4_get_z(self->ptr);
}

float Vec4_get_w(Vec4* self) {
    return _vec4_get_w(self->ptr);
}

// C class Quat

Quat Quat_from_xyzw(float x, float y, float z, float w) {
    Quat inst;
        inst.ptr = _quat_from_xyzw(x, y, z, w);
        return inst;
}

float Quat_get_x(Quat* self) {
    return _quat_get_x(self->ptr);
}

float Quat_get_y(Quat* self) {
    return _quat_get_y(self->ptr);
}

float Quat_get_z(Quat* self) {
    return _quat_get_z(self->ptr);
}

float Quat_get_w(Quat* self) {
    return _quat_get_w(self->ptr);
}

// C class ColorNote
Color ColorNote_get_color(ColorNote* self) {
    Color inst;
    inst.ptr = _color_note_get_color(self->ptr);
    return inst;
}
void ColorNote_set_color(ColorNote* self, Color color) {
    _color_note_set_color(self->ptr, color.ptr);
}
Vec3 ColorNote_get_position(ColorNote* self) {
    Vec3 inst;
    inst.ptr = _color_note_get_position(self->ptr);
    return inst;
}
void ColorNote_set_position(ColorNote* self, Vec3 position) {
    _color_note_set_position(self->ptr, position.ptr);
}
Quat ColorNote_get_orientation(ColorNote* self) {
    Quat inst;
    inst.ptr = _color_note_get_orientation(self->ptr);
    return inst;
}
void ColorNote_set_orientation(ColorNote* self, Quat orientation) {
    _color_note_set_orientation(self->ptr, orientation.ptr);
}
// C class BombNote
Color BombNote_get_color(BombNote* self) {
    Color inst;
    inst.ptr = _bomb_note_get_color(self->ptr);
    return inst;
}
void BombNote_set_color(BombNote* self, Color color) {
    _bomb_note_set_color(self->ptr, color.ptr);
}
Vec3 BombNote_get_position(BombNote* self) {
    Vec3 inst;
    inst.ptr = _bomb_note_get_position(self->ptr);
    return inst;
}
void BombNote_set_position(BombNote* self, Vec3 position) {
    _bomb_note_set_position(self->ptr, position.ptr);
}
Quat BombNote_get_orientation(BombNote* self) {
    Quat inst;
    inst.ptr = _bomb_note_get_orientation(self->ptr);
    return inst;
}
void BombNote_set_orientation(BombNote* self, Quat orientation) {
    _bomb_note_set_orientation(self->ptr, orientation.ptr);
}
// C class Arc
Color Arc_get_color(Arc* self) {
    Color inst;
    inst.ptr = _arc_get_color(self->ptr);
    return inst;
}
void Arc_set_color(Arc* self, Color color) {
    _arc_set_color(self->ptr, color.ptr);
}
Vec3 Arc_get_position(Arc* self) {
    Vec3 inst;
    inst.ptr = _arc_get_position(self->ptr);
    return inst;
}
void Arc_set_position(Arc* self, Vec3 position) {
    _arc_set_position(self->ptr, position.ptr);
}
Quat Arc_get_orientation(Arc* self) {
    Quat inst;
    inst.ptr = _arc_get_orientation(self->ptr);
    return inst;
}
void Arc_set_orientation(Arc* self, Quat orientation) {
    _arc_set_orientation(self->ptr, orientation.ptr);
}
// C class Wall
Color Wall_get_color(Wall* self) {
    Color inst;
    inst.ptr = _wall_get_color(self->ptr);
    return inst;
}
void Wall_set_color(Wall* self, Color color) {
    _wall_set_color(self->ptr, color.ptr);
}
Vec3 Wall_get_position(Wall* self) {
    Vec3 inst;
    inst.ptr = _wall_get_position(self->ptr);
    return inst;
}
void Wall_set_position(Wall* self, Vec3 position) {
    _wall_set_position(self->ptr, position.ptr);
}
Quat Wall_get_orientation(Wall* self) {
    Quat inst;
    inst.ptr = _wall_get_orientation(self->ptr);
    return inst;
}
void Wall_set_orientation(Wall* self, Quat orientation) {
    _wall_set_orientation(self->ptr, orientation.ptr);
}
// C class ChainHeadNote
Color ChainHeadNote_get_color(ChainHeadNote* self) {
    Color inst;
    inst.ptr = _chain_head_note_get_color(self->ptr);
    return inst;
}
void ChainHeadNote_set_color(ChainHeadNote* self, Color color) {
    _chain_head_note_set_color(self->ptr, color.ptr);
}
Vec3 ChainHeadNote_get_position(ChainHeadNote* self) {
    Vec3 inst;
    inst.ptr = _chain_head_note_get_position(self->ptr);
    return inst;
}
void ChainHeadNote_set_position(ChainHeadNote* self, Vec3 position) {
    _chain_head_note_set_position(self->ptr, position.ptr);
}
Quat ChainHeadNote_get_orientation(ChainHeadNote* self) {
    Quat inst;
    inst.ptr = _chain_head_note_get_orientation(self->ptr);
    return inst;
}
void ChainHeadNote_set_orientation(ChainHeadNote* self, Quat orientation) {
    _chain_head_note_set_orientation(self->ptr, orientation.ptr);
}
// C class ChainLinkNote
Color ChainLinkNote_get_color(ChainLinkNote* self) {
    Color inst;
    inst.ptr = _chain_link_note_get_color(self->ptr);
    return inst;
}
void ChainLinkNote_set_color(ChainLinkNote* self, Color color) {
    _chain_link_note_set_color(self->ptr, color.ptr);
}
Vec3 ChainLinkNote_get_position(ChainLinkNote* self) {
    Vec3 inst;
    inst.ptr = _chain_link_note_get_position(self->ptr);
    return inst;
}
void ChainLinkNote_set_position(ChainLinkNote* self, Vec3 position) {
    _chain_link_note_set_position(self->ptr, position.ptr);
}
Quat ChainLinkNote_get_orientation(ChainLinkNote* self) {
    Quat inst;
    inst.ptr = _chain_link_note_get_orientation(self->ptr);
    return inst;
}
void ChainLinkNote_set_orientation(ChainLinkNote* self, Quat orientation) {
    _chain_link_note_set_orientation(self->ptr, orientation.ptr);
}
// C class ChainNote
Color ChainNote_get_color(ChainNote* self) {
    Color inst;
    inst.ptr = _chain_note_get_color(self->ptr);
    return inst;
}
void ChainNote_set_color(ChainNote* self, Color color) {
    _chain_note_set_color(self->ptr, color.ptr);
}
Vec3 ChainNote_get_position(ChainNote* self) {
    Vec3 inst;
    inst.ptr = _chain_note_get_position(self->ptr);
    return inst;
}
void ChainNote_set_position(ChainNote* self, Vec3 position) {
    _chain_note_set_position(self->ptr, position.ptr);
}
Quat ChainNote_get_orientation(ChainNote* self) {
    Quat inst;
    inst.ptr = _chain_note_get_orientation(self->ptr);
    return inst;
}
void ChainNote_set_orientation(ChainNote* self, Quat orientation) {
    _chain_note_set_orientation(self->ptr, orientation.ptr);
}

ColorNote create_color_note(float beat) {
    ColorNote inst;
    inst.ptr = _create_color_note(beat);
    return inst;
}

BombNote create_bomb_note(float beat) {
    BombNote inst;
    inst.ptr = _create_bomb_note(beat);
    return inst;
}

Arc create_arc(float beat) {
    Arc inst;
    inst.ptr = _create_arc(beat);
    return inst;
}

Wall create_wall(float beat) {
    Wall inst;
    inst.ptr = _create_wall(beat);
    return inst;
}

ChainHeadNote create_chain_head_note(float beat) {
    ChainHeadNote inst;
    inst.ptr = _create_chain_head_note(beat);
    return inst;
}

ChainLinkNote create_chain_link_note(float beat) {
    ChainLinkNote inst;
    inst.ptr = _create_chain_link_note(beat);
    return inst;
}

ChainNote create_chain_note(float beat) {
    ChainNote inst;
    inst.ptr = _create_chain_note(beat);
    return inst;
}

// C class Beatmap
void Beatmap_add_color_note(ColorNote color_note) {
    _beatmap_add_color_note(color_note.ptr);
}
void Beatmap_remove_color_note(ColorNote color_note) {
    _beatmap_remove_color_note(color_note.ptr);
}
ColorNote Beatmap_get_color_note_at_beat(float beat) {
    _beatmap_get_color_note_at_beat(beat);
}
void Beatmap_add_bomb_note(BombNote bomb_note) {
    _beatmap_add_bomb_note(bomb_note.ptr);
}
void Beatmap_remove_bomb_note(BombNote bomb_note) {
    _beatmap_remove_bomb_note(bomb_note.ptr);
}
BombNote Beatmap_get_bomb_note_at_beat(float beat) {
    _beatmap_get_bomb_note_at_beat(beat);
}
void Beatmap_add_arc(Arc arc) {
    _beatmap_add_arc(arc.ptr);
}
void Beatmap_remove_arc(Arc arc) {
    _beatmap_remove_arc(arc.ptr);
}
Arc Beatmap_get_arc_at_beat(float beat) {
    _beatmap_get_arc_at_beat(beat);
}
void Beatmap_add_wall(Wall wall) {
    _beatmap_add_wall(wall.ptr);
}
void Beatmap_remove_wall(Wall wall) {
    _beatmap_remove_wall(wall.ptr);
}
Wall Beatmap_get_wall_at_beat(float beat) {
    _beatmap_get_wall_at_beat(beat);
}
void Beatmap_add_chain_head_note(ChainHeadNote chain_head_note) {
    _beatmap_add_chain_head_note(chain_head_note.ptr);
}
void Beatmap_remove_chain_head_note(ChainHeadNote chain_head_note) {
    _beatmap_remove_chain_head_note(chain_head_note.ptr);
}
ChainHeadNote Beatmap_get_chain_head_note_at_beat(float beat) {
    _beatmap_get_chain_head_note_at_beat(beat);
}
void Beatmap_add_chain_link_note(ChainLinkNote chain_link_note) {
    _beatmap_add_chain_link_note(chain_link_note.ptr);
}
void Beatmap_remove_chain_link_note(ChainLinkNote chain_link_note) {
    _beatmap_remove_chain_link_note(chain_link_note.ptr);
}
ChainLinkNote Beatmap_get_chain_link_note_at_beat(float beat) {
    _beatmap_get_chain_link_note_at_beat(beat);
}
void Beatmap_add_chain_note(ChainNote chain_note) {
    _beatmap_add_chain_note(chain_note.ptr);
}
void Beatmap_remove_chain_note(ChainNote chain_note) {
    _beatmap_remove_chain_note(chain_note.ptr);
}
ChainNote Beatmap_get_chain_note_at_beat(float beat) {
    _beatmap_get_chain_note_at_beat(beat);
}

