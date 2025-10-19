
///// Generated C API /////
#include <stdlib>
#include <stdint>
#include "api.wasm.h"

//// Functions ////

void testGlobal(const char* name) {
    _test_global(name);
    
}
int32_t global2Test() {
    return _global_2_test();
    
}
char* myTest(int8_t a, int16_t b) {
    uint32_t _res = _my_test(a, b);
    void* _str = malloc(_res);
    _host_strcpy(_str, _res);
    return _str;
}

//// Classes ////

typedef struct {
    const void* opaqu;
} MyClass;


// MyClass Methods

void objectFunc(MyClass* self, int16_t a) {
    _my_class_object_func(self->opaqu, a);
    
}

typedef struct {
    // No fields
} Log;

// Log Functions

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
