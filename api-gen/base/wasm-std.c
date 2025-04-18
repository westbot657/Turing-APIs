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