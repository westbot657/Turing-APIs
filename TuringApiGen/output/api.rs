
///// Generated Rust API /////

//// Classes ////



struct MyClass {
    // (no fields)
}
impl MyClass {
    pub fn object_func(&self, a: i16){
        _my_class_object_func(self, a)
    }
}

struct Log {
    // (no fields)
}
impl Log {
    pub fn info(msg: &str){
        _log_info(msg)
    }
    pub fn warn(msg: &str){
        _log_warn(msg)
    }
    pub fn critical(msg: &str){
        _log_critical(msg)
    }
    pub fn debug(msg: &str){
        _log_debug(msg)
    }
}

//// Functions ////

// FIXME: No wasm binding defined for test_global
// FIXME: No wasm binding defined for global_2_test
// FIXME: No wasm binding defined for my_test