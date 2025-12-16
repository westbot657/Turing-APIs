

///// Generated C++ API Header /////
#ifndef TURING_API_HPP
#define TURING_API_HPP
#include <stdint.h>
#include <string>
// skip ffi imports as they're included from wasm.h
#define TURING_API_CPP_SEMVER "0.0.1"

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

class Log {
public:

    void info(std::string& msg);
    void warn(std::string& msg);
    void critical(std::string& msg);
    void debug(std::string& msg);

};

} // namespace turing_api_cpp

#endif // TURING_API_HPP
