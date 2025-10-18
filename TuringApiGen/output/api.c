
///// Generated C API /////
#include <stdlib.h>
#include <stdint.h>

//// Wasm Bindings ////
void _host_strcpy(const char* location, uint32_t size);
void _test_global(const char* name);
int32_t _global_2_test();
uint32_t _my_test(int8_t a, int16_t b);



void _my_class_object_func(const void* opaque, int16_t a);
void _log_info(const char* msg);
void _log_warn(const char* msg);
void _log_critical(const char* msg);
void _log_debug(const char* msg);




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
    const void* opaque;
} MyClass;


// MyClass Methods

void objectFunc(MyClass* self, int16_t a) {
    _my_class_object_func(self->opaque, a);
    
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
