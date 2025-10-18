
///// Generated C API /////
#include <stdint.h>

//// Functions ////
void testGlobal(const char* name) {_test_global(name);
}int32_t global2Test() {return _global_2_test();
}char* myTest(int8_t a, int16_t b) {return _my_test(a, b);
}


//// Classes ////

typedef struct {
    const void* opaque;
} MyClass;

// MyClass methods

void object_func(MyClass* self, int16_t a) {
    _my_class_object_func(self->opaque, a);
}

typedef struct {
    // No fields
} Log;
// Log functions

void info(const char* msg) {
    _log_info(msg);
}

void warn(const char* msg) {
    _log_warn(msg);
}

void critical(const char* msg) {
    _log_critical(msg);
}

void debug(const char* msg) {
    _log_debug(msg);
}




