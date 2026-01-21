

///// Generated C API Header /////
#ifndef TURING_API_H
#define TURING_API_H
#include <stdint.h>
// skip ffi imports as they're included from wasm.h
#define TURING_API_C_SEMVER "0.8.0"

uint64_t _turing_api_semver(void);

//// Functions ////


void testGlobal(const char* name);

int32_t global2Test(void);

char* myTest(int8_t a, int16_t b);
//// Classes ////

// class MyClass

typedef struct {
    uint64_t opaqu;
} MyClass;




void MyClass_objectFunc(MyClass* self, int16_t a);

// class ColorNote
/// this is line 1
/// this is line 2
typedef struct {
    uint64_t opaqu;
} ColorNote;




ColorNote* ColorNote_setPosition(ColorNote* self, uint32_t v);

ColorNote* ColorNote_setOrientation(ColorNote* self, uint32_t q);

ColorNote* ColorNote_setTransform(ColorNote* self, uint32_t m);

uint32_t ColorNote_getPosition(ColorNote* self);

uint32_t ColorNote_getOrientation(ColorNote* self);

uint32_t ColorNote_getTransform(ColorNote* self);

ColorNote ColorNote_clone(ColorNote* self);

// class Log
/// used to log messages to the console
/// idk, this is a second line
typedef struct Log Log;


/// logs `msg` to the console
void Log_info(const char* msg);
/// logs `msg` to the console as a warning
void Log_warn(const char* msg);
/// logs `msg` to the console as an error
void Log_critical(const char* msg);
/// logs `msg` to the console when in debug mode
void Log_debug(const char* msg);


#endif // TURING_API_H


