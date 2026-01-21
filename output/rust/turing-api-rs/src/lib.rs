
///// Generated Rust API /////
use std::ffi::{CString, CStr, c_char, c_void};


mod alg {
    use crate::*;

    #[cfg(feature = "glam")]
    use glam::{Vec2, Vec3, Vec4, Quat, Mat4};

    #[cfg(feature = "nalgebra")]
    use nalgebra::{Vector2, Vector3, Vector4, Quaternion, Matrix4};

    #[cfg(feature = "nalgebra")]
    pub type Vec2 = Vector2<f32>;
    #[cfg(feature = "nalgebra")]
    pub type Vec3 = Vector3<f32>;
    #[cfg(feature = "nalgebra")]
    pub type Vec4 = Vector4<f32>;
    #[cfg(feature = "nalgebra")]
    pub type Quat = Quaternion<f32>;
    #[cfg(feature = "nalgebra")]
    pub type Mat4 = Matrix4<f32>;

    pub fn dequeue_vec2() -> Vec2 {
        let x = unsafe { _host_f32_dequeue() };
        let y = unsafe { _host_f32_dequeue() };
        Vec2::new(x, y)
    }

    pub fn enqueue_vec2(v: Vec2) -> u32 {
        unsafe {
            _host_f32_enqueue(v.x);
            _host_f32_enqueue(v.y);
        }
        2
    }

    pub fn dequeue_vec3() -> Vec3 {
        let x = unsafe { _host_f32_dequeue() };
        let y = unsafe { _host_f32_dequeue() };
        let z = unsafe { _host_f32_dequeue() };
        Vec3::new(x, y, z)
    }

    pub fn enqueue_vec3(v: Vec3) -> u32 {
        unsafe {
            _host_f32_enqueue(v.x);
            _host_f32_enqueue(v.y);
            _host_f32_enqueue(v.z);
        }
        3
    }

    pub fn dequeue_vec4() -> Vec4 {
        let x = unsafe { _host_f32_dequeue() };
        let y = unsafe { _host_f32_dequeue() };
        let z = unsafe { _host_f32_dequeue() };
        let w = unsafe { _host_f32_dequeue() };
        Vec4::new(x, y, z, w)
    }

    pub fn enqueue_vec4(v: Vec4) -> u32 {
        unsafe {
            _host_f32_enqueue(v.x);
            _host_f32_enqueue(v.y);
            _host_f32_enqueue(v.z);
            _host_f32_enqueue(v.w);
        }
        4
    }

    pub fn dequeue_quat() -> Quat {
        let x = unsafe { _host_f32_dequeue() };
        let y = unsafe { _host_f32_dequeue() };
        let z = unsafe { _host_f32_dequeue() };
        let w = unsafe { _host_f32_dequeue() };
        #[cfg(feature = "nalgebra")]
        return Quat::new(x, y, z, w);
        #[cfg(feature = "glam")]
        Quat::from_xyzw(x, y, z, w)
    }

    pub fn enqueue_quat(v: Quat) -> u32 {
        unsafe {
            #[cfg(feature = "nalgebra")]
            let v = v.coords;
            _host_f32_enqueue(v.x);
            _host_f32_enqueue(v.y);
            _host_f32_enqueue(v.z);
            _host_f32_enqueue(v.w);
        }
        4
    }

    pub fn dequeue_mat4() -> Mat4 {
        let mut arr = [0f32; 16];
        for i in 0..16 {
            arr[i] = unsafe { _host_f32_dequeue() };
        }
        #[cfg(feature = "nalgebra")]
        return Mat4::from_column_slice(&arr);
        #[cfg(feature = "glam")]
        Mat4::from_cols_array(&arr)
    }

    pub fn enqueue_mat4(m: Mat4) -> u32 {
        #[cfg(feature = "nalgebra")]
        let slice = m.as_slice();
        #[cfg(feature = "glam")]
        let slice = m.to_cols_array();

        for v in slice {
            #[cfg(feature = "nalgebra")]
            let v = *v;
            unsafe { _host_f32_enqueue(v) };
        }

        16
    }

}

//// Wasm Bindings ////
unsafe extern "C" {
    fn _host_strcpy(location: *const c_char, size: u32);
    fn _host_f32_enqueue(f: f32);
    fn _host_f32_dequeue() -> f32;
    fn _test_global(name: *const c_char);
    fn _global_2_test() -> i32;
    fn _my_test(a: i8, b: i16) -> u32;
    fn _my_class_object_func(opaqu: u64, a: i16);
    fn _color_note_set_position(opaqu: u64, v: u32) -> ();
    fn _color_note_set_orientation(opaqu: u64, q: u32) -> ();
    fn _color_note_set_transform(opaqu: u64, m: u32) -> ();
    fn _color_note_get_position(opaqu: u64) -> u32;
    fn _color_note_get_orientation(opaqu: u64) -> u32;
    fn _color_note_get_transform(opaqu: u64) -> u32;
    fn _color_note_clone(opaqu: u64) -> u64;
    fn _log_info(msg: *const c_char);
    fn _log_warn(msg: *const c_char);
    fn _log_critical(msg: *const c_char);
    fn _log_debug(msg: *const c_char);
}

#[unsafe(no_mangle)]
extern "C" fn _turing_api_semver() -> u64 {
    (0u64 << 32) | (8u64 << 16) | 0u64
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

/// this is line 1
/// this is line 2
pub struct ColorNote {
    opaqu: u64,
}
impl ColorNote {

    pub fn set_position(&self, v: alg::Vec3) -> &Self {
        let v = alg::enqueue_vec3(v);
        unsafe { _color_note_set_position(self.opaqu, v) };
        self
    }

    pub fn set_orientation(&self, q: alg::Quat) -> &Self {
        let q = alg::enqueue_quat(q);
        unsafe { _color_note_set_orientation(self.opaqu, q) };
        self
    }

    pub fn set_transform(&self, m: alg::Mat4) -> &Self {
        let m = alg::enqueue_mat4(m);
        unsafe { _color_note_set_transform(self.opaqu, m) };
        self
    }

    pub fn get_position(&self) -> alg::Vec3 {
        unsafe { _color_note_get_position(self.opaqu) };
        alg::dequeue_vec3()
    }

    pub fn get_orientation(&self) -> alg::Quat {
        unsafe { _color_note_get_orientation(self.opaqu) };
        alg::dequeue_quat()
    }

    pub fn get_transform(&self) -> alg::Mat4 {
        unsafe { _color_note_get_transform(self.opaqu) };
        alg::dequeue_mat4()
    }

    pub fn clone(&self) -> ColorNote {
        let turing_result = unsafe { _color_note_clone(self.opaqu) };
        ColorNote { opaqu: turing_result }
    }
}

/// used to log messages to the console
/// idk, this is a second line
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



