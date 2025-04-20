// Turing API - C++
// License: GPL-2.0-only
// Authors: Westbot
// <auto-converted from the rust api />

#include <turing_api_cpp.hpp>

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
    char* result = (char*) malloc(len1 + len2 + 1); // +1 for null terminator
    if (result) {
        strcpy(result, str1);
        strcat(result, str2);
    }
    return result;
}

// C++ class Color

float Color::get_r() {
    return _color_get_r(this->ptr);
}

void Color::set_r(float r) {
    _color_set_r(this->ptr, r);
}

float Color::get_g() {
    return _color_get_g(this->ptr);
}

void Color::set_g(float g) {
    _color_set_g(this->ptr, g);
}

float Color::get_b() {
    return _color_get_b(this->ptr);
}

void Color::set_b(float b) {
    _color_set_b(this->ptr, b);
}

float Color::get_a() {
    return _color_get_a(this->ptr);
}

void Color::set_a(float a) {
    _color_set_a(this->ptr, a);
}

void Color::set_rgb(float r, float g, float b) {
    _color_set_rgb(this->ptr, r, g, b);
}

void Color::set_rgba(float r, float g, float b, float a) {
    _color_set_rgba(this->ptr, r, g, b, a);
}

// C++ class Log

void Log::info(char* msg) {
    char* s = concat_strings("info: ", msg);
    _log(s);
    free(s);
}

void Log::warn(char* msg) {
    char* s = concat_strings("warn: ", msg);
    _log(s);
    free(s);
}

void Log::critical(char* msg) {
    char* s = concat_strings("error: ", msg);
    _log(s);
    free(s);
}

void Log::debug(char* msg) {
    char* s = concat_strings("debug: ", msg);
    _log(s);
    free(s);
}

// C++ class Vec2

Vec2 Vec2::from_xy(float x, float y) {
    Vec2 inst = Vec2 {};
    inst.ptr = _vec2_from_xy(x, y);
    return inst;
}

float Vec2::get_x() {
    return _vec2_get_x(this->ptr);
}

float Vec2::get_y() {
    return _vec2_get_y(this->ptr);
}

// C++ class Vec3

Vec3 Vec3::from_xyz(float x, float y, float z) {
    Vec3 inst = Vec3 {};
    inst.ptr = _vec3_from_xyz(x, y, z);
    return inst;
}

float Vec3::get_x() {
    return _vec3_get_x(this->ptr);
}

float Vec3::get_y() {
    return _vec3_get_y(this->ptr);
}

float Vec3::get_z() {
    return _vec3_get_z(this->ptr);
}

// C++ class Vec4

Vec4 Vec4::from_xyzw(float x, float y, float z, float w) {
    Vec4 inst = Vec4 {};
    inst.ptr = _vec4_from_xyzw(x, y, z, w);
    return inst;
}

float Vec4::get_x() {
    return _vec4_get_x(this->ptr);
}

float Vec4::get_y() {
    return _vec4_get_y(this->ptr);
}

float Vec4::get_z() {
    return _vec4_get_z(this->ptr);
}

float Vec4::get_w() {
    return _vec4_get_w(this->ptr);
}

// C++ class Quat

Quat Quat::from_xyzw(float x, float y, float z, float w) {
    Quat inst = Quat {};
    inst.ptr = _quat_from_xyzw(x, y, z, w);
    return inst;
}

float Quat::get_x() {
    return _quat_get_x(this->ptr);
}

float Quat::get_y() {
    return _quat_get_y(this->ptr);
}

float Quat::get_z() {
    return _quat_get_z(this->ptr);
}

float Quat::get_w() {
    return _quat_get_w(this->ptr);
}

// C++ class ColorNote
Color ColorNote::get_color() {
    Color inst = Color {};
    inst.ptr = _color_note_get_color(this->ptr);
    return inst;
}
void ColorNote::set_color(Color color) {
    _color_note_set_color(this->ptr, color.ptr);
}
Vec3 ColorNote::get_position() {
    Vec3 inst = Vec3 {};
    inst.ptr = _color_note_get_position(this->ptr);
    return inst;
}
void ColorNote::set_position(Vec3 position) {
    _color_note_set_position(this->ptr, position.ptr);
}
Quat ColorNote::get_orientation() {
    Quat inst = Quat {};
    inst.ptr = _color_note_get_orientation(this->ptr);
    return inst;
}
void ColorNote::set_orientation(Quat orientation) {
    _color_note_set_orientation(this->ptr, orientation.ptr);
}
// C++ class BombNote
Color BombNote::get_color() {
    Color inst = Color {};
    inst.ptr = _bomb_note_get_color(this->ptr);
    return inst;
}
void BombNote::set_color(Color color) {
    _bomb_note_set_color(this->ptr, color.ptr);
}
Vec3 BombNote::get_position() {
    Vec3 inst = Vec3 {};
    inst.ptr = _bomb_note_get_position(this->ptr);
    return inst;
}
void BombNote::set_position(Vec3 position) {
    _bomb_note_set_position(this->ptr, position.ptr);
}
Quat BombNote::get_orientation() {
    Quat inst = Quat {};
    inst.ptr = _bomb_note_get_orientation(this->ptr);
    return inst;
}
void BombNote::set_orientation(Quat orientation) {
    _bomb_note_set_orientation(this->ptr, orientation.ptr);
}
// C++ class Arc
Color Arc::get_color() {
    Color inst = Color {};
    inst.ptr = _arc_get_color(this->ptr);
    return inst;
}
void Arc::set_color(Color color) {
    _arc_set_color(this->ptr, color.ptr);
}
Vec3 Arc::get_position() {
    Vec3 inst = Vec3 {};
    inst.ptr = _arc_get_position(this->ptr);
    return inst;
}
void Arc::set_position(Vec3 position) {
    _arc_set_position(this->ptr, position.ptr);
}
Quat Arc::get_orientation() {
    Quat inst = Quat {};
    inst.ptr = _arc_get_orientation(this->ptr);
    return inst;
}
void Arc::set_orientation(Quat orientation) {
    _arc_set_orientation(this->ptr, orientation.ptr);
}
// C++ class Wall
Color Wall::get_color() {
    Color inst = Color {};
    inst.ptr = _wall_get_color(this->ptr);
    return inst;
}
void Wall::set_color(Color color) {
    _wall_set_color(this->ptr, color.ptr);
}
Vec3 Wall::get_position() {
    Vec3 inst = Vec3 {};
    inst.ptr = _wall_get_position(this->ptr);
    return inst;
}
void Wall::set_position(Vec3 position) {
    _wall_set_position(this->ptr, position.ptr);
}
Quat Wall::get_orientation() {
    Quat inst = Quat {};
    inst.ptr = _wall_get_orientation(this->ptr);
    return inst;
}
void Wall::set_orientation(Quat orientation) {
    _wall_set_orientation(this->ptr, orientation.ptr);
}
// C++ class ChainHeadNote
Color ChainHeadNote::get_color() {
    Color inst = Color {};
    inst.ptr = _chain_head_note_get_color(this->ptr);
    return inst;
}
void ChainHeadNote::set_color(Color color) {
    _chain_head_note_set_color(this->ptr, color.ptr);
}
Vec3 ChainHeadNote::get_position() {
    Vec3 inst = Vec3 {};
    inst.ptr = _chain_head_note_get_position(this->ptr);
    return inst;
}
void ChainHeadNote::set_position(Vec3 position) {
    _chain_head_note_set_position(this->ptr, position.ptr);
}
Quat ChainHeadNote::get_orientation() {
    Quat inst = Quat {};
    inst.ptr = _chain_head_note_get_orientation(this->ptr);
    return inst;
}
void ChainHeadNote::set_orientation(Quat orientation) {
    _chain_head_note_set_orientation(this->ptr, orientation.ptr);
}
// C++ class ChainLinkNote
Color ChainLinkNote::get_color() {
    Color inst = Color {};
    inst.ptr = _chain_link_note_get_color(this->ptr);
    return inst;
}
void ChainLinkNote::set_color(Color color) {
    _chain_link_note_set_color(this->ptr, color.ptr);
}
Vec3 ChainLinkNote::get_position() {
    Vec3 inst = Vec3 {};
    inst.ptr = _chain_link_note_get_position(this->ptr);
    return inst;
}
void ChainLinkNote::set_position(Vec3 position) {
    _chain_link_note_set_position(this->ptr, position.ptr);
}
Quat ChainLinkNote::get_orientation() {
    Quat inst = Quat {};
    inst.ptr = _chain_link_note_get_orientation(this->ptr);
    return inst;
}
void ChainLinkNote::set_orientation(Quat orientation) {
    _chain_link_note_set_orientation(this->ptr, orientation.ptr);
}
// C++ class ChainNote
Color ChainNote::get_color() {
    Color inst = Color {};
    inst.ptr = _chain_note_get_color(this->ptr);
    return inst;
}
void ChainNote::set_color(Color color) {
    _chain_note_set_color(this->ptr, color.ptr);
}
Vec3 ChainNote::get_position() {
    Vec3 inst = Vec3 {};
    inst.ptr = _chain_note_get_position(this->ptr);
    return inst;
}
void ChainNote::set_position(Vec3 position) {
    _chain_note_set_position(this->ptr, position.ptr);
}
Quat ChainNote::get_orientation() {
    Quat inst = Quat {};
    inst.ptr = _chain_note_get_orientation(this->ptr);
    return inst;
}
void ChainNote::set_orientation(Quat orientation) {
    _chain_note_set_orientation(this->ptr, orientation.ptr);
}

ColorNote create_color_note(float beat) {
    ColorNote inst = ColorNote {};
    inst.ptr = _create_color_note(beat);
    return inst;
}

BombNote create_bomb_note(float beat) {
    BombNote inst = BombNote {};
    inst.ptr = _create_bomb_note(beat);
    return inst;
}

Arc create_arc(float beat) {
    Arc inst = Arc {};
    inst.ptr = _create_arc(beat);
    return inst;
}

Wall create_wall(float beat) {
    Wall inst = Wall {};
    inst.ptr = _create_wall(beat);
    return inst;
}

ChainHeadNote create_chain_head_note(float beat) {
    ChainHeadNote inst = ChainHeadNote {};
    inst.ptr = _create_chain_head_note(beat);
    return inst;
}

ChainLinkNote create_chain_link_note(float beat) {
    ChainLinkNote inst = ChainLinkNote {};
    inst.ptr = _create_chain_link_note(beat);
    return inst;
}

ChainNote create_chain_note(float beat) {
    ChainNote inst = ChainNote {};
    inst.ptr = _create_chain_note(beat);
    return inst;
}

// C++ class Beatmap
void Beatmap::add_color_note(ColorNote color_note) {
    _beatmap_add_color_note(color_note.ptr);
}
void Beatmap::remove_color_note(ColorNote color_note) {
    _beatmap_remove_color_note(color_note.ptr);
}
ColorNote Beatmap::get_color_note_at_beat(float beat) {
    _beatmap_get_color_note_at_beat(beat);
}
void Beatmap::add_bomb_note(BombNote bomb_note) {
    _beatmap_add_bomb_note(bomb_note.ptr);
}
void Beatmap::remove_bomb_note(BombNote bomb_note) {
    _beatmap_remove_bomb_note(bomb_note.ptr);
}
BombNote Beatmap::get_bomb_note_at_beat(float beat) {
    _beatmap_get_bomb_note_at_beat(beat);
}
void Beatmap::add_arc(Arc arc) {
    _beatmap_add_arc(arc.ptr);
}
void Beatmap::remove_arc(Arc arc) {
    _beatmap_remove_arc(arc.ptr);
}
Arc Beatmap::get_arc_at_beat(float beat) {
    _beatmap_get_arc_at_beat(beat);
}
void Beatmap::add_wall(Wall wall) {
    _beatmap_add_wall(wall.ptr);
}
void Beatmap::remove_wall(Wall wall) {
    _beatmap_remove_wall(wall.ptr);
}
Wall Beatmap::get_wall_at_beat(float beat) {
    _beatmap_get_wall_at_beat(beat);
}
void Beatmap::add_chain_head_note(ChainHeadNote chain_head_note) {
    _beatmap_add_chain_head_note(chain_head_note.ptr);
}
void Beatmap::remove_chain_head_note(ChainHeadNote chain_head_note) {
    _beatmap_remove_chain_head_note(chain_head_note.ptr);
}
ChainHeadNote Beatmap::get_chain_head_note_at_beat(float beat) {
    _beatmap_get_chain_head_note_at_beat(beat);
}
void Beatmap::add_chain_link_note(ChainLinkNote chain_link_note) {
    _beatmap_add_chain_link_note(chain_link_note.ptr);
}
void Beatmap::remove_chain_link_note(ChainLinkNote chain_link_note) {
    _beatmap_remove_chain_link_note(chain_link_note.ptr);
}
ChainLinkNote Beatmap::get_chain_link_note_at_beat(float beat) {
    _beatmap_get_chain_link_note_at_beat(beat);
}
void Beatmap::add_chain_note(ChainNote chain_note) {
    _beatmap_add_chain_note(chain_note.ptr);
}
void Beatmap::remove_chain_note(ChainNote chain_note) {
    _beatmap_remove_chain_note(chain_note.ptr);
}
ChainNote Beatmap::get_chain_note_at_beat(float beat) {
    _beatmap_get_chain_note_at_beat(beat);
}

