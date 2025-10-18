
///// Generated Rust API /////
use std::ffi::{CString, CStr, c_char, c_void};

unsafe extern "C" {
    fn _host_strcpy(location: *const c_char, size: u32);

    //// Generated bindings ////
    fn _test_global(name: *const c_char);
    fn _global_2_test() -> i32;
    fn _my_test(a: i8, b: i16) -> u32;
    

    
    fn _my_class_object_func(opaque: *const c_void, a: i16);
    fn _log_info(msg: *const c_char);
    fn _log_warn(msg: *const c_char);
    fn _log_critical(msg: *const c_char);
    fn _log_debug(msg: *const c_char);
    

}

//// Functions ////

pub fn test_global(name: &str) {
    let _internal_name = CString::new(name).unwrap();
    let name = _internal_name.as_ptr();
    unsafe { _test_global(name) }
}
pub fn global_2_test() -> i32 {
    let _res = unsafe { _global_2_test() };
    _res
}
pub fn my_test(a: i8, b: i16) -> String {
    let _res = unsafe { _my_test(a, b) };
    let mut _str: Vec<u8> = vec![0; _res as usize];
    unsafe { _host_strcpy(_str.as_mut_ptr() as *mut c_char, _res); }
    let _str = unsafe { CStr::from_ptr(_str.as_ptr() as *const c_char) };
    _str.to_string_lossy().into_owned()
}


//// Classes ////

struct MyClass {
    opaque: *const c_void,
}
impl MyClass {
    pub fn object_func(&self, a: i16) {
        unsafe { _my_class_object_func(self.opaque, a) }
    }
}

struct Log {
    // No fields
}
impl Log {
    pub fn info(msg: &str) {
        let _internal_msg = CString::new(msg).unwrap();
        let msg = _internal_msg.as_ptr();
        unsafe { _log_info(msg) }

    }
    pub fn warn(msg: &str) {
        let _internal_msg = CString::new(msg).unwrap();
        let msg = _internal_msg.as_ptr();
        unsafe { _log_warn(msg) }

    }
    pub fn critical(msg: &str) {
        let _internal_msg = CString::new(msg).unwrap();
        let msg = _internal_msg.as_ptr();
        unsafe { _log_critical(msg) }

    }
    pub fn debug(msg: &str) {
        let _internal_msg = CString::new(msg).unwrap();
        let msg = _internal_msg.as_ptr();
        unsafe { _log_debug(msg) }

    }
}

