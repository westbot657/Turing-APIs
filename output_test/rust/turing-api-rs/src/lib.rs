///// Generated Rust API /////
use std::ffi::{CString, CStr, c_char, c_void};





//// Core Systems ////
pub mod alg {
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
    
    pub fn _host_strcpy(location: *mut c_char, size: u32);
    pub fn _host_bufcpy(location: *mut c_void, size: u32);
    pub fn _host_f32_enqueue(f: f32);
    pub fn _host_f32_dequeue() -> f32;
    pub fn _host_u32_enqueue(u: u32);
    pub fn _host_u32_dequeue() -> u32;
    
    fn _do_thing(random: Random) -> Something;
    fn _log__debug(msg: *const c_char);
    fn _log__critical(msg: *const c_char);
    fn _log__warn(msg: *const c_char);
    fn _log__info(msg: *const c_char);
    fn _vivify__upload_buffer(buf: *const c_void);
    fn _vivify__get_buffer() -> u32;

}

#[unsafe(no_mangle)]
extern "C" fn _turing_api_semver() -> u64 {
    return (1u64 << 32) | (0u64 << 16) | 0u64;
}

pub static TURING_API_VERSION: &'static str = "1.0.0";


//// Functions ////


pub fn do_thing(random: Random) -> Something {
    unsafe { _do_thing(random) }
}

//// Classes ////
#[repr(C)]
/// Used to log messages to the console
pub struct Log;
impl Log {

    /// Only logs in debug mode
    pub fn debug(msg: &str) {
        let turing_handle = CString::new(msg).unwrap();
        let msg = turing_handle.as_ptr();
        unsafe { _log__debug(msg) };
    }
    /// Highlights red
    pub fn critical(msg: &str) {
        let turing_handle = CString::new(msg).unwrap();
        let msg = turing_handle.as_ptr();
        unsafe { _log__critical(msg) };
    }
    /// Highlights yellow
    pub fn warn(msg: &str) {
        let turing_handle = CString::new(msg).unwrap();
        let msg = turing_handle.as_ptr();
        unsafe { _log__warn(msg) };
    }
    /// Highlights blue
    pub fn info(msg: &str) {
        let turing_handle = CString::new(msg).unwrap();
        let msg = turing_handle.as_ptr();
        unsafe { _log__info(msg) };
    }
    
}
#[repr(C)]
/// Vivify compatibility systems
pub struct Vivify;
impl Vivify {

    /// Uploads a data buffer to beat saber
    pub fn upload_buffer(buf: &[u32]) {
        unsafe { _host_u32_enqueue(buf.len() as u32) };
        let buf = buf.as_ptr() as *mut c_void;
        unsafe { _vivify__upload_buffer(buf) };
    }
    /// Fetches a data buffer from beat saber
    pub fn get_buffer() -> Vec<u32> {
        let turing_result = unsafe { _vivify__get_buffer() };
        let mut turing_buf = vec![0u32; turing_result as usize];
        unsafe { _host_bufcpy(turing_buf.as_mut_ptr() as *mut c_void, turing_result) };
        turing_buf
    }
    
}
#[repr(C)]

pub struct Random {
    pub opaqu: u64,
}
#[repr(C)]

pub struct Something {
    pub opaqu: u64,
}

