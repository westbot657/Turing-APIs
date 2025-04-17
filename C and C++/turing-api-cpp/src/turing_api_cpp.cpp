// Turing API - C++
// License: GPL-2.0-only
// Authors: Westbot
// <auto-converted from the rust api />

#include <turing_api_cpp.hpp>

// wasm-std.c

typedef struct {
    unsigned int size;     // Size of the block (not including header)
    unsigned char used;    // 1 if block is used, 0 if free
} BlockHeader;

#define HEADER_SIZE sizeof(BlockHeader)
#define MEMORY_SIZE 65536  // 64KB of memory
#define MEMORY_START 4     // Start after the 4 bytes for next_free

// Import linear memory from JS environment
extern unsigned char __heap_base;

// Get pointer to the start of usable memory
unsigned char* get_memory_start() {
    return &__heap_base;
}

// Initialize memory management system
void init_memory() {
    unsigned char* memory = get_memory_start();
    
    // Set initial next_free pointer to start of memory
    *((unsigned int*)memory) = MEMORY_START;
    
    // Create initial free block
    BlockHeader* first_block = (BlockHeader*)(memory + MEMORY_START);
    first_block->size = MEMORY_SIZE - MEMORY_START - HEADER_SIZE;
    first_block->used = 0;
}

// Basic malloc implementation
void* malloc(unsigned int size) {
    unsigned char* memory = get_memory_start();
    unsigned int next_free = *((unsigned int*)memory);
    
    // Align size to 4 bytes
    size = (size + 3) & ~3;
    
    // Start from the beginning of memory
    unsigned int current = MEMORY_START;
    
    while (current < MEMORY_SIZE) {
        BlockHeader* header = (BlockHeader*)(memory + current);
        
        // Check if this block is free and large enough
        if (!header->used && header->size >= size) {
            // Is there enough space to split this block?
            if (header->size >= size + HEADER_SIZE + 4) {
                // Split the block
                unsigned int new_block_pos = current + HEADER_SIZE + size;
                BlockHeader* new_block = (BlockHeader*)(memory + new_block_pos);
                new_block->size = header->size - size - HEADER_SIZE;
                new_block->used = 0;
                
                // Update current block
                header->size = size;
            }
            
            // Mark as used
            header->used = 1;
            
            // Update next_free if needed
            if (next_free == current) {
                *((unsigned int*)memory) = current + HEADER_SIZE + header->size;
            }
            
            // Return pointer to the allocated memory
            return memory + current + HEADER_SIZE;
        }
        
        // Move to next block
        current += HEADER_SIZE + header->size;
    }
    
    // Out of memory
    return 0;
}

// Basic free implementation
void free(void* ptr) {
    if (!ptr) return;
    
    unsigned char* memory = get_memory_start();
    unsigned int addr = ((unsigned char*)ptr) - memory;
    
    // Get block header
    BlockHeader* header = (BlockHeader*)(memory + addr - HEADER_SIZE);
    
    // Mark block as free
    header->used = 0;
    
    // Simple coalescing with next block
    unsigned int next_block = addr + header->size;
    if (next_block < MEMORY_SIZE) {
        BlockHeader* next_header = (BlockHeader*)(memory + next_block);
        if (!next_header->used) {
            header->size += HEADER_SIZE + next_header->size;
        }
    }
    
    // Note: We're not coalescing with previous blocks
    // as that would require a doubly-linked list or scanning
    // from the beginning, which is inefficient
}

// Simple strcpy implementation
char* strcpy(char* dest, const char* src) {
    char* original_dest = dest;
    
    while (*src) {
        *dest++ = *src++;
    }
    
    *dest = '\0';  // Null-terminate the string
    return original_dest;
}

// Simple strcat implementation
char* strcat(char* dest, const char* src) {
    char* original_dest = dest;
    
    // Find the end of dest
    while (*dest) {
        dest++;
    }
    
    // Copy src to the end of dest
    while (*src) {
        *dest++ = *src++;
    }
    
    *dest = '\0';  // Null-terminate the string
    return original_dest;
}

// Simple strlen implementation
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

// C++ class Color

float Color::get_a(Color* self) {
    return _color_get_a(self->ptr);
}

void Color::set_a(Color* self, float a) {
    _color_set_a(self->ptr, a);
}

float Color::get_b(Color* self) {
    return _color_get_b(self->ptr);
}

void Color::set_b(Color* self, float b) {
    _color_set_b(self->ptr, b);
}

float Color::get_g(Color* self) {
    return _color_get_g(self->ptr);
}

void Color::set_g(Color* self, float g) {
    _color_set_g(self->ptr, g);
}

float Color::get_r(Color* self) {
    return _color_get_r(self->ptr);
}

void Color::set_r(Color* self, float r) {
    _color_set_r(self->ptr, r);
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
void Beatmap::add_chain_note(ChainNote chain_note) {
    _beatmap_add_chain_note(chain_note.ptr);
}
void Beatmap::remove_chain_note(ChainNote chain_note) {
    _beatmap_remove_chain_note(chain_note.ptr);
}
void Beatmap::add_chain_link_note(ChainLinkNote chain_link_note) {
    _beatmap_add_chain_link_note(chain_link_note.ptr);
}
void Beatmap::remove_chain_link_note(ChainLinkNote chain_link_note) {
    _beatmap_remove_chain_link_note(chain_link_note.ptr);
}
void Beatmap::add_chain_head_note(ChainHeadNote chain_head_note) {
    _beatmap_add_chain_head_note(chain_head_note.ptr);
}
void Beatmap::remove_chain_head_note(ChainHeadNote chain_head_note) {
    _beatmap_remove_chain_head_note(chain_head_note.ptr);
}
void Beatmap::add_wall(Wall wall) {
    _beatmap_add_wall(wall.ptr);
}
void Beatmap::remove_wall(Wall wall) {
    _beatmap_remove_wall(wall.ptr);
}
void Beatmap::add_arc(Arc arc) {
    _beatmap_add_arc(arc.ptr);
}
void Beatmap::remove_arc(Arc arc) {
    _beatmap_remove_arc(arc.ptr);
}
void Beatmap::add_bomb_note(BombNote bomb_note) {
    _beatmap_add_bomb_note(bomb_note.ptr);
}
void Beatmap::remove_bomb_note(BombNote bomb_note) {
    _beatmap_remove_bomb_note(bomb_note.ptr);
}
void Beatmap::add_color_note(ColorNote color_note) {
    _beatmap_add_color_note(color_note.ptr);
}
void Beatmap::remove_color_note(ColorNote color_note) {
    _beatmap_remove_color_note(color_note.ptr);
}

