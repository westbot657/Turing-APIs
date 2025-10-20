
///// Generated C API Headers /////
#pragma once
#include <stdint.h>

//// Public Functions ////

void testGlobal(const char* name);

int32_t global2Test();

char* myTest(int8_t a, int16_t b);



//// Classes ////

typedef struct {
    const void* opaqu;
} MyClass;




// MyClass Methods

void objectFunc(MyClass* self, int16_t a);


typedef struct {
    // No fields

} Log;

// Log Functions

void Log_info(const char* msg);

void Log_warn(const char* msg);

void Log_critical(const char* msg);

void Log_debug(const char* msg);





