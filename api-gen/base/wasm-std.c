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