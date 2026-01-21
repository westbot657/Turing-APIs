

///// Generated C++ API Header /////
#ifndef TURING_API_HPP
#define TURING_API_HPP
#include <stdint.h>
#include <string>
// skip ffi imports as they're included from wasm.h
#define TURING_API_CPP_SEMVER "0.8.0"

namespace turing_api_cpp {

uint64_t _turing_api_semver();

//// Functions ////

    
void testGlobal(std::string& name);
    
int32_t global2Test();
    
std::string myTest(int8_t a, int16_t b);
//// Classes ////

class MyClass {
private:
    uint64_t opaqu;

public:
    MyClass(uint64_t ptr);



    
    void objectFunc(int16_t a);
};
/// this is line 1
/// this is line 2
class ColorNote {
private:
    uint64_t opaqu;

public:
    ColorNote(uint64_t ptr);



    
    ColorNote* setPosition(uint32_t v);
    
    ColorNote* setOrientation(uint32_t q);
    
    ColorNote* setTransform(uint32_t m);
    
    uint32_t getPosition();
    
    uint32_t getOrientation();
    
    uint32_t getTransform();
    
    ColorNote clone();
};
/// used to log messages to the console
/// idk, this is a second line
class Log {
public:

    /// logs `msg` to the console
    void info(std::string& msg);
    /// logs `msg` to the console as a warning
    void warn(std::string& msg);
    /// logs `msg` to the console as an error
    void critical(std::string& msg);
    /// logs `msg` to the console when in debug mode
    void debug(std::string& msg);

};

} // namespace turing_api_cpp

#endif // TURING_API_HPP
