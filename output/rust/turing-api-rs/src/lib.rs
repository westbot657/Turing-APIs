
///// Generated Rust API /////
use std::ffi::{CString, CStr, c_char, c_void};


//// Wasm Bindings ////
unsafe extern "C" {
    fn _host_strcpy(location: *const c_char, size: u32);
    fn _test_global(name: *const c_char);
    fn _global_2_test() -> i32;
    fn _my_test(a: i8, b: i16) -> u32;
    fn _my_class_object_func(opaqu: u64, a: i16);
    fn _log_info(msg: *const c_char);
    fn _log_warn(msg: *const c_char);
    fn _log_critical(msg: *const c_char);
    fn _log_debug(msg: *const c_char);
}

//// Functions ////

pub fn test_global(name: &str) {
    let turing_handle_name = CString::new(name).unwrap();
    let name = turing_handle_name.as_ptr();
    unsafe { _test_global(name) }
}
pub fn global_2_test() -> i32 {
    unsafe { _global_2_test() }
}
pub fn my_test(a: i8, b: i16) -> String {
    let turing_result = unsafe { _my_test(a, b) };
    let mut turing_str: Vec<u8> = vec![0; turing_result as usize];
    unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
    let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
    turing_str.to_string_lossy().into_owned()
}


//// Classes ////
pub struct MyClass {
    opaqu: u64,
}
impl MyClass {
    pub fn object_func(&self, a: i16) {
        unsafe { _my_class_object_func(self.opaqu, a) }
    }
}

pub struct Log {
}
impl Log {
    pub fn info(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log_info(msg) }
    }
    pub fn warn(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log_warn(msg) }
    }
    pub fn critical(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log_critical(msg) }
    }
    pub fn debug(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log_debug(msg) }
    }
}



