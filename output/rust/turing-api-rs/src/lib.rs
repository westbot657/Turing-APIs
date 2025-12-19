
///// Generated Rust API /////
use std::ffi::{CString, CStr, c_char, c_void};


//// Wasm Bindings ////
unsafe extern "C" {
    fn _host_strcpy(location: *const c_char, size: u32);
    fn _test_global(name: *const c_char);
    fn _global_2_test() -> i32;
    fn _my_test(a: i8, b: i16) -> u32;
    fn _my_class_object_func(opaqu: u64, a: i16);
    fn _color_note_set_position(opaqu: u64, x: f32, y: f32, z: f32) -> ();
    fn _color_note_set_orientation(opaqu: u64, x: f32, y: f32, z: f32, w: f32) -> ();
    fn _color_note_clone(opaqu: u64) -> ColorNote;
    fn _log_info(msg: *const c_char);
    fn _log_warn(msg: *const c_char);
    fn _log_critical(msg: *const c_char);
    fn _log_debug(msg: *const c_char);
}

#[unsafe(no_mangle)]
extern "C" fn _turing_api_semver() -> u64 {
    (0u64 << 16) | (8u64 << 8) | 0u64
}
pub const TURING_API_VERSION: &str = "0.8.0";

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


pub struct ColorNote {
    opaqu: u64,
}
impl ColorNote {

    pub fn set_position(&self, x: f32, y: f32, z: f32) -> &Self {
        unsafe { _color_note_set_position(self.opaqu, x, y, z) };
        self
    }

    pub fn set_orientation(&self, x: f32, y: f32, z: f32, w: f32) -> &Self {
        unsafe { _color_note_set_orientation(self.opaqu, x, y, z, w) };
        self
    }

    pub fn clone(&self) -> ColorNote {
        let turing_result = unsafe { _color_note_clone(self.opaqu) };
        ColorNote { opaqu: turing_result }
    }
}

/// used to log messages to the console
pub struct Log {
}
impl Log {
    /// logs `msg` to the console
    pub fn info(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log_info(msg) }
    }
    /// logs `msg` to the console as a warning
    pub fn warn(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log_warn(msg) }
    }
    /// logs `msg` to the console as an error
    pub fn critical(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log_critical(msg) }
    }
    /// logs `msg` to the console when in debug mode
    pub fn debug(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log_debug(msg) }
    }
}



