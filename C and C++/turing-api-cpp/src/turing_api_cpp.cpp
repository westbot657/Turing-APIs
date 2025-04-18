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
    free_list->next = NULL;
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
    
    return NULL; // No suitable block found
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
}// C++ class Color

float Color::get_r(Color* self) {
    return _color_get_r(self->ptr);
}

void Color::set_r(Color* self, float r) {
    _color_set_r(self->ptr, r);
}

float Color::get_g(Color* self) {
    return _color_get_g(self->ptr);
}

void Color::set_g(Color* self, float g) {
    _color_set_g(self->ptr, g);
}

float Color::get_b(Color* self) {
    return _color_get_b(self->ptr);
}

void Color::set_b(Color* self, float b) {
    _color_set_b(self->ptr, b);
}

float Color::get_a(Color* self) {
    return _color_get_a(self->ptr);
}

void Color::set_a(Color* self, float a) {
    _color_set_a(self->ptr, a);
}

void Color::set_rgb(Color* self, float r, float g, float b) {
    _color_set_rgb(self->ptr, r, g, b);
}

void Color::set_rgba(Color* self, float r, float g, float b, float a) {
    _color_set_rgba(self->ptr, r, g, b, a);
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

// C++ class ColorNote
Color ColorNote::get_color(ColorNote* self) {
    Color inst = Color {};
    inst.ptr = _color_note_get_color(self->ptr);
    return inst;
}
// C++ class BombNote
Color BombNote::get_color(BombNote* self) {
    Color inst = Color {};
    inst.ptr = _bomb_note_get_color(self->ptr);
    return inst;
}
// C++ class Arc
Color Arc::get_color(Arc* self) {
    Color inst = Color {};
    inst.ptr = _arc_get_color(self->ptr);
    return inst;
}
// C++ class Wall
Color Wall::get_color(Wall* self) {
    Color inst = Color {};
    inst.ptr = _wall_get_color(self->ptr);
    return inst;
}
// C++ class ChainHeadNote
Color ChainHeadNote::get_color(ChainHeadNote* self) {
    Color inst = Color {};
    inst.ptr = _chain_head_note_get_color(self->ptr);
    return inst;
}
// C++ class ChainLinkNote
Color ChainLinkNote::get_color(ChainLinkNote* self) {
    Color inst = Color {};
    inst.ptr = _chain_link_note_get_color(self->ptr);
    return inst;
}
// C++ class ChainNote
Color ChainNote::get_color(ChainNote* self) {
    Color inst = Color {};
    inst.ptr = _chain_note_get_color(self->ptr);
    return inst;
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
void Beatmap::add_bomb_note(BombNote bomb_note) {
    _beatmap_add_bomb_note(bomb_note.ptr);
}
void Beatmap::remove_bomb_note(BombNote bomb_note) {
    _beatmap_remove_bomb_note(bomb_note.ptr);
}
void Beatmap::add_arc(Arc arc) {
    _beatmap_add_arc(arc.ptr);
}
void Beatmap::remove_arc(Arc arc) {
    _beatmap_remove_arc(arc.ptr);
}
void Beatmap::add_wall(Wall wall) {
    _beatmap_add_wall(wall.ptr);
}
void Beatmap::remove_wall(Wall wall) {
    _beatmap_remove_wall(wall.ptr);
}
void Beatmap::add_chain_head_note(ChainHeadNote chain_head_note) {
    _beatmap_add_chain_head_note(chain_head_note.ptr);
}
void Beatmap::remove_chain_head_note(ChainHeadNote chain_head_note) {
    _beatmap_remove_chain_head_note(chain_head_note.ptr);
}
void Beatmap::add_chain_link_note(ChainLinkNote chain_link_note) {
    _beatmap_add_chain_link_note(chain_link_note.ptr);
}
void Beatmap::remove_chain_link_note(ChainLinkNote chain_link_note) {
    _beatmap_remove_chain_link_note(chain_link_note.ptr);
}
void Beatmap::add_chain_note(ChainNote chain_note) {
    _beatmap_add_chain_note(chain_note.ptr);
}
void Beatmap::remove_chain_note(ChainNote chain_note) {
    _beatmap_remove_chain_note(chain_note.ptr);
}

