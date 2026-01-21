

///// Generated C++ API /////
#include "turing_api.hpp"
#include "turing_api_wasm.h"
#include <string>

namespace turing_api_cpp {

uint64_t _turing_api_semver() {
    return ((uint64_t)0 << 32) | ((uint64_t)8 << 16) | (uint64_t)0;
}

//// Functions ////

void testGlobal(std::string& name) {
    _test_global(name);
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
    _my_class_object_func(this->opaqu, a);
}

// class ColorNote
ColorNote::ColorNote(uint64_t ptr) : opaqu(ptr) {}


ColorNote* ColorNote::setPosition(glm::vec3 v) {
    _color_note_set_position(this->opaqu, v);
    return this;
}
ColorNote* ColorNote::setOrientation(glm::quat q) {
    _color_note_set_orientation(this->opaqu, q);
    return this;
}
ColorNote* ColorNote::setTransform(glm::mat4 m) {
    _color_note_set_transform(this->opaqu, m);
    return this;
}
glm::vec3 ColorNote::getPosition() {
    return _color_note_get_position(this->opaqu);
}
glm::quat ColorNote::getOrientation() {
    return _color_note_get_orientation(this->opaqu);
}
glm::mat4 ColorNote::getTransform() {
    return _color_note_get_transform(this->opaqu);
}
ColorNote ColorNote::clone() {
    uint64_t turing_result = _color_note_clone(this->opaqu);
    return ColorNote(turing_result);
    
}

// class Log

void Log::info(std::string& msg) {
    _log_info(msg);
}
void Log::warn(std::string& msg) {
    _log_warn(msg);
}
void Log::critical(std::string& msg) {
    _log_critical(msg);
}
void Log::debug(std::string& msg) {
    _log_debug(msg);
}


} // namespace turing_api_cpp
