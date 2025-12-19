///// Generated Go API /////
package turing_api

// Helper functions for string conversion
func cString(s string) []byte {
    b := []byte(s)
    b = append(b, 0)
    return b
}

func goString(b []byte) string {
    for i, v := range b {
        if v == 0 {
            return string(b[:i])
        }
    }
    return string(b)
}

//// WASM Imports ////
//go:wasmimport env _host_strcpy
func _host_strcpy(location *byte, size uint32)
//go:wasmimport env _test_global
func _test_global(name *byte)
//go:wasmimport env _global_2_test
func _global_2_test() int32
//go:wasmimport env _my_test
func _my_test(a int8, b int16) uint32
//go:wasmimport env _my_class_object_func
func _my_class_object_func(opaqu uint64, a int16)
//go:wasmimport env _log_info
func _log_info(msg *byte)
//go:wasmimport env _log_warn
func _log_warn(msg *byte)
//go:wasmimport env _log_critical
func _log_critical(msg *byte)
//go:wasmimport env _log_debug
func _log_debug(msg *byte)

//export _turing_api_semver
func _turing_api_semver() uint64 {
    return (uint64(0) << 16) | (uint64(8) << 8) | uint64(0)
}

const APIVersion = "0.8.0"

//// Functions ////


func testGlobal(name string) {
    turing_handle_name := cString(name)
    namePtr := &turing_handle_name[0]
    _test_global(namePtr)
}

func global2Test() int32 {
    return _global_2_test()
}

func myTest(a int8, b int16) string {
    turingResult := _my_test(a, b)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], uint32(turingResult))
    return goString(turingStr)
}

//// Classes ////

type MyClass struct {
    opaqu uint64
}



func (self *MyClass) objectFunc(a int16) {
    _my_class_object_func(self.opaqu, a)
}
/// used to log messages to the console
type Log struct {
}

/// logs `msg` to the console
func Log_info(msg string) {
    turing_handle_msg := cString(msg)
    msgPtr := &turing_handle_msg[0]
    _log_info(msgPtr)
}
/// logs `msg` to the console as a warning
func Log_warn(msg string) {
    turing_handle_msg := cString(msg)
    msgPtr := &turing_handle_msg[0]
    _log_warn(msgPtr)
}
/// logs `msg` to the console as an error
func Log_critical(msg string) {
    turing_handle_msg := cString(msg)
    msgPtr := &turing_handle_msg[0]
    _log_critical(msgPtr)
}
/// logs `msg` to the console when in debug mode
func Log_debug(msg string) {
    turing_handle_msg := cString(msg)
    msgPtr := &turing_handle_msg[0]
    _log_debug(msgPtr)
}
