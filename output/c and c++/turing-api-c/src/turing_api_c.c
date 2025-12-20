

///// Generated C API /////
#include "turing_api.h"
#include "turing_api_wasm.h"
#include <stdlib.h>
#include <string.h>

uint64_t _turing_api_semver(void) {
    return ((uint64_t)0 << 16) | ((uint64_t)8 << 8) | (uint64_t)0;
}

//// Functions ////

void testGlobal(const char* name) {
    _test_global(name);
}
int32_t global2Test(void) {
    return _global_2_test();
}
char* myTest(int8_t a, int16_t b) {
    uint32_t turing_size = _my_test(a, b);
    if (turing_size == 0) {
        return NULL;
    }
    char* turing_buf = (char*) malloc(turing_size);
    if (!turing_buf) {
        return NULL;
    }
    _host_strcpy(turing_buf, turing_size);
    return turing_buf;
    
}


//// Classes ////
// class MyClass


void MyClass_objectFunc(MyClass* self, int16_t a) {
    _my_class_object_func(self->opaqu, a);
}

// class ColorNote


ColorNote* ColorNote_setPosition(ColorNote* self, float x, float y, float z) {
    _color_note_set_position(self->opaqu, x, y, z);
    return self;
}
ColorNote* ColorNote_setOrientation(ColorNote* self, float x, float y, float z, float w) {
    _color_note_set_orientation(self->opaqu, x, y, z, w);
    return self;
}
ColorNote ColorNote_clone(ColorNote* self) {
    uint64_t turing_result = _color_note_clone(self->opaqu);
    ColorNote turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}

// class Log

void Log_info(const char* msg) {
    _log_info(msg);
}
void Log_warn(const char* msg) {
    _log_warn(msg);
}
void Log_critical(const char* msg) {
    _log_critical(msg);
}
void Log_debug(const char* msg) {
    _log_debug(msg);
}




