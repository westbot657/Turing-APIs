
///// Generated C++ API Headers /////
#pragma once
#include <string>
#include <vector>
#include <cstring>
#include <cstdint>
#include "api.wasm.h"


//// Functions ////
inline void testGlobal(std::string& name) {
    _test_global(name.c_str());
    }inline int32_t global2Test() {
    return _global_2_test();
    }inline std::string myTest(int8_t a, int16_t b) {
    uint32_t turing_strlen = _my_test(ab);
    std::vector<char> turing_buf(turing_strlen);
    _host_strcpy(turing_buf.data(), turing_strlen);
    return std::string(buf.data());
    }