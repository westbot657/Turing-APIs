

///// Generated C++ API /////
#include "turing_api.hpp"
#include "turing_api_wasm.h"
#include <string>

namespace turing_api_cpp {

uint64_t _turing_api_semver() {
    return ((uint64_t)0 << 16) | ((uint64_t)8 << 8) | (uint64_t)0;
}

//// Functions ////

void testGlobal(std::string& name) {
    return _test_global(name);
}
int32_t global2Test() {
    return _global_2_test();
}
std::string myTest(int8_t a, int16_t b) {
    uint32_t turing_size = _my_test(a, b);
    if (turing_size == 0) {
        return "";
    }
    std::string turing_buf(turing_size, '\0');
    _host_strcpy(const_cast<char*>(turing_buf.data()), turing_size);
    return turing_buf;
    
}
//// Classes ////

// class MyClass

MyClass::MyClass(uint64_t ptr) : opaqu(ptr) {}



void MyClass::objectFunc(int16_t a) {
    return _my_class_object_func(this->opaqu, a);
}

// class Log


void Log::info(std::string& msg) {
    return _log_info(msg);
}
void Log::warn(std::string& msg) {
    return _log_warn(msg);
}
void Log::critical(std::string& msg) {
    return _log_critical(msg);
}
void Log::debug(std::string& msg) {
    return _log_debug(msg);
}


} // namespace turing_api_cpp
