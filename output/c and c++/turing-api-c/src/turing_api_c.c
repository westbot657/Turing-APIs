

///// Generated C API /////
#include "turing_api.h"
#include "turing_api_wasm.h"
#include <stdlib.h>
#include <string.h>

uint64_t _turing_api_semver(void) {
    return ((uint64_t)0 << 16) | ((uint64_t)0 << 8) | (uint64_t)1;
}

//// Functions ////

void testGlobal(const char* name) {
    return _test_global(name);
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
    return _my_class_object_func(self->opaqu, a);
}

// class Log

void Log_info(const char* msg) {
    return _log_info(msg);
}
void Log_warn(const char* msg) {
    return _log_warn(msg);
}
void Log_critical(const char* msg) {
    return _log_critical(msg);
}
void Log_debug(const char* msg) {
    return _log_debug(msg);
}




