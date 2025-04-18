#![feature(prelude_import)]
#[prelude_import]
use std::prelude::rust_2021::*;
#[macro_use]
extern crate std;
use std::any::Any;
use std::cell::RefCell;
use std::collections::HashMap;
use std::ffi::{c_char, CString};
use once_cell::unsync::Lazy;
use paste::paste;
type _Color = i32;
type _ColorNote = i32;
type _BombNote = i32;
type _ChainHeadNote = i32;
type _ChainLinkNote = i32;
type _ChainNote = i32;
type _Arc = i32;
type _Wall = i32;
type _Saber = i32;
type _Vec2 = i32;
type _Vec3 = i32;
type _Vec4 = i32;
type _Quat = i32;
extern "C" {
    fn _create_color_note(beat: f32) -> _ColorNote;
    fn _beatmap_add_color_note(color_note: _ColorNote);
    fn _beatmap_remove_color_note(color_note: _ColorNote);
}
extern "C" {
    fn _color_note_set_position(color_note: _ColorNote, pos: _Vec3);
    fn _color_note_get_position(color_note: _ColorNote) -> _Vec3;
    fn _color_note_set_orientation(color_note: _ColorNote, orientation: _Quat);
    fn _color_note_get_orientation(color_note: _ColorNote) -> _Quat;
}
extern "C" {
    fn _color_note_set_color(color_note: _ColorNote, color: _Color);
    fn _color_note_get_color(color_note: _ColorNote) -> _Color;
}
extern "C" {
    fn _create_bomb_note(beat: f32) -> _BombNote;
    fn _beatmap_add_bomb_note(bomb_note: _BombNote);
    fn _beatmap_remove_bomb_note(bomb_note: _BombNote);
}
extern "C" {
    fn _bomb_note_set_position(bomb_note: _BombNote, pos: _Vec3);
    fn _bomb_note_get_position(bomb_note: _BombNote) -> _Vec3;
    fn _bomb_note_set_orientation(bomb_note: _BombNote, orientation: _Quat);
    fn _bomb_note_get_orientation(bomb_note: _BombNote) -> _Quat;
}
extern "C" {
    fn _bomb_note_set_color(bomb_note: _BombNote, color: _Color);
    fn _bomb_note_get_color(bomb_note: _BombNote) -> _Color;
}
extern "C" {
    fn _create_arc(beat: f32) -> _Arc;
    fn _beatmap_add_arc(arc: _Arc);
    fn _beatmap_remove_arc(arc: _Arc);
}
extern "C" {
    fn _arc_set_position(arc: _Arc, pos: _Vec3);
    fn _arc_get_position(arc: _Arc) -> _Vec3;
    fn _arc_set_orientation(arc: _Arc, orientation: _Quat);
    fn _arc_get_orientation(arc: _Arc) -> _Quat;
}
extern "C" {
    fn _arc_set_color(arc: _Arc, color: _Color);
    fn _arc_get_color(arc: _Arc) -> _Color;
}
extern "C" {
    fn _create_wall(beat: f32) -> _Wall;
    fn _beatmap_add_wall(wall: _Wall);
    fn _beatmap_remove_wall(wall: _Wall);
}
extern "C" {
    fn _wall_set_position(wall: _Wall, pos: _Vec3);
    fn _wall_get_position(wall: _Wall) -> _Vec3;
    fn _wall_set_orientation(wall: _Wall, orientation: _Quat);
    fn _wall_get_orientation(wall: _Wall) -> _Quat;
}
extern "C" {
    fn _wall_set_color(wall: _Wall, color: _Color);
    fn _wall_get_color(wall: _Wall) -> _Color;
}
extern "C" {
    fn _create_chain_head_note(beat: f32) -> _ChainHeadNote;
    fn _beatmap_add_chain_head_note(chain_head_note: _ChainHeadNote);
    fn _beatmap_remove_chain_head_note(chain_head_note: _ChainHeadNote);
}
extern "C" {
    fn _chain_head_note_set_position(chain_head_note: _ChainHeadNote, pos: _Vec3);
    fn _chain_head_note_get_position(chain_head_note: _ChainHeadNote) -> _Vec3;
    fn _chain_head_note_set_orientation(
        chain_head_note: _ChainHeadNote,
        orientation: _Quat,
    );
    fn _chain_head_note_get_orientation(chain_head_note: _ChainHeadNote) -> _Quat;
}
extern "C" {
    fn _chain_head_note_set_color(chain_head_note: _ChainHeadNote, color: _Color);
    fn _chain_head_note_get_color(chain_head_note: _ChainHeadNote) -> _Color;
}
extern "C" {
    fn _create_chain_link_note(beat: f32) -> _ChainLinkNote;
    fn _beatmap_add_chain_link_note(chain_link_note: _ChainLinkNote);
    fn _beatmap_remove_chain_link_note(chain_link_note: _ChainLinkNote);
}
extern "C" {
    fn _chain_link_note_set_position(chain_link_note: _ChainLinkNote, pos: _Vec3);
    fn _chain_link_note_get_position(chain_link_note: _ChainLinkNote) -> _Vec3;
    fn _chain_link_note_set_orientation(
        chain_link_note: _ChainLinkNote,
        orientation: _Quat,
    );
    fn _chain_link_note_get_orientation(chain_link_note: _ChainLinkNote) -> _Quat;
}
extern "C" {
    fn _chain_link_note_set_color(chain_link_note: _ChainLinkNote, color: _Color);
    fn _chain_link_note_get_color(chain_link_note: _ChainLinkNote) -> _Color;
}
extern "C" {
    fn _create_chain_note(beat: f32) -> _ChainNote;
    fn _beatmap_add_chain_note(chain_note: _ChainNote);
    fn _beatmap_remove_chain_note(chain_note: _ChainNote);
}
extern "C" {
    fn _chain_note_set_position(chain_note: _ChainNote, pos: _Vec3);
    fn _chain_note_get_position(chain_note: _ChainNote) -> _Vec3;
    fn _chain_note_set_orientation(chain_note: _ChainNote, orientation: _Quat);
    fn _chain_note_get_orientation(chain_note: _ChainNote) -> _Quat;
}
extern "C" {
    fn _chain_note_set_color(chain_note: _ChainNote, color: _Color);
    fn _chain_note_get_color(chain_note: _ChainNote) -> _Color;
}
extern "C" {
    fn _saber_set_color(saber: _Saber, color: _Color);
    fn _saber_get_color(saber: _Saber) -> _Color;
}
extern "C" {
    fn _get_left_saber() -> _Saber;
    fn _get_right_saber() -> _Saber;
    fn _log(message: *const c_char);
    fn _drop_reference(ptr: *mut c_char);
    fn _vec2_from_xy(x: f32, y: f32) -> _Vec2;
    fn _vec3_from_xyz(x: f32, y: f32, z: f32) -> _Vec3;
    fn _vec4_from_xyzw(x: f32, y: f32, z: f32, w: f32) -> _Vec4;
    fn _quat_from_xyzw(x: f32, y: f32, z: f32, w: f32) -> _Quat;
    fn _color_set_rgb(color: _Color, r: f32, g: f32, b: f32);
    fn _color_set_rgba(color: _Color, r: f32, g: f32, b: f32, a: f32);
}
pub struct Log {}
impl Log {
    pub fn info(message: &str) {
        let s = ::alloc::__export::must_use({
            let res = ::alloc::fmt::format(format_args!("info: {0}", message));
            res
        });
        let c = CString::new(s).unwrap();
        unsafe { _log(c.as_ptr()) };
    }
    pub fn warning(message: &str) {
        let s = ::alloc::__export::must_use({
            let res = ::alloc::fmt::format(format_args!("warning: {0}", message));
            res
        });
        let c = CString::new(s).unwrap();
        unsafe { _log(c.as_ptr()) };
    }
    pub fn error(message: &str) {
        let s = ::alloc::__export::must_use({
            let res = ::alloc::fmt::format(format_args!("error: {0}", message));
            res
        });
        let c = CString::new(s).unwrap();
        unsafe { _log(c.as_ptr()) };
    }
    pub fn debug(message: &str) {
        let s = ::alloc::__export::must_use({
            let res = ::alloc::fmt::format(format_args!("debug: {0}", message));
            res
        });
        let c = CString::new(s).unwrap();
        unsafe { _log(c.as_ptr()) };
    }
}
pub struct Beatmap;
const GLOBAL_MAP: ::std::thread::LocalKey<
    Lazy<RefCell<HashMap<String, Box<dyn Any>>>>,
> = {
    #[inline]
    fn __init() -> Lazy<RefCell<HashMap<String, Box<dyn Any>>>> {
        Lazy::new(|| { RefCell::new(HashMap::new()) })
    }
    unsafe {
        ::std::thread::LocalKey::new(const {
            if ::std::mem::needs_drop::<Lazy<RefCell<HashMap<String, Box<dyn Any>>>>>() {
                |init| {
                    #[thread_local]
                    static VAL: ::std::thread::local_impl::LazyStorage<
                        Lazy<RefCell<HashMap<String, Box<dyn Any>>>>,
                        (),
                    > = ::std::thread::local_impl::LazyStorage::new();
                    VAL.get_or_init(init, __init)
                }
            } else {
                |init| {
                    #[thread_local]
                    static VAL: ::std::thread::local_impl::LazyStorage<
                        Lazy<RefCell<HashMap<String, Box<dyn Any>>>>,
                        !,
                    > = ::std::thread::local_impl::LazyStorage::new();
                    VAL.get_or_init(init, __init)
                }
            }
        })
    }
};
pub struct Data;
impl Data {
    pub fn set_temp_value<T: Clone + 'static>(key: &str, v: T) {
        GLOBAL_MAP
            .with(|map| {
                map.borrow_mut().insert(key.to_string(), Box::new(v));
            })
    }
    pub fn get_temp_value<T: Clone + 'static>(key: &str) -> Option<T> {
        GLOBAL_MAP
            .with(|map| {
                map.borrow().get(key).and_then(|v| v.downcast_ref::<T>()).cloned()
            })
    }
    pub fn remove_temp_value(key: &str) {
        GLOBAL_MAP
            .with(|map| {
                map.borrow_mut().remove(key);
            })
    }
}
pub struct ColorNote {
    _inner: _ColorNote,
}
pub fn create_color_note(beat: f32) -> ColorNote {
    unsafe {
        ColorNote {
            _inner: _create_color_note(beat),
        }
    }
}
impl Beatmap {
    pub fn add_color_note(color_note: ColorNote) {
        unsafe {
            _beatmap_add_color_note(color_note._inner);
        }
    }
}
pub struct BombNote {
    _inner: _BombNote,
}
pub fn create_bomb_note(beat: f32) -> BombNote {
    unsafe {
        BombNote {
            _inner: _create_bomb_note(beat),
        }
    }
}
impl Beatmap {
    pub fn add_bomb_note(bomb_note: BombNote) {
        unsafe {
            _beatmap_add_bomb_note(bomb_note._inner);
        }
    }
}
pub struct ChainHeadNote {
    _inner: _ChainHeadNote,
}
pub fn create_chain_head_note(beat: f32) -> ChainHeadNote {
    unsafe {
        ChainHeadNote {
            _inner: _create_chain_head_note(beat),
        }
    }
}
impl Beatmap {
    pub fn add_chain_head_note(chain_head_note: ChainHeadNote) {
        unsafe {
            _beatmap_add_chain_head_note(chain_head_note._inner);
        }
    }
}
pub struct ChainLinkNote {
    _inner: _ChainLinkNote,
}
pub fn create_chain_link_note(beat: f32) -> ChainLinkNote {
    unsafe {
        ChainLinkNote {
            _inner: _create_chain_link_note(beat),
        }
    }
}
impl Beatmap {
    pub fn add_chain_link_note(chain_link_note: ChainLinkNote) {
        unsafe {
            _beatmap_add_chain_link_note(chain_link_note._inner);
        }
    }
}
pub struct ChainNote {
    _inner: _ChainNote,
}
pub fn create_chain_note(beat: f32) -> ChainNote {
    unsafe {
        ChainNote {
            _inner: _create_chain_note(beat),
        }
    }
}
impl Beatmap {
    pub fn add_chain_note(chain_note: ChainNote) {
        unsafe {
            _beatmap_add_chain_note(chain_note._inner);
        }
    }
}
pub struct Arc {
    _inner: _Arc,
}
pub fn create_arc(beat: f32) -> Arc {
    unsafe { Arc { _inner: _create_arc(beat) } }
}
impl Beatmap {
    pub fn add_arc(arc: Arc) {
        unsafe {
            _beatmap_add_arc(arc._inner);
        }
    }
}
pub struct Wall {
    _inner: _Wall,
}
pub fn create_wall(beat: f32) -> Wall {
    unsafe { Wall { _inner: _create_wall(beat) } }
}
impl Beatmap {
    pub fn add_wall(wall: Wall) {
        unsafe {
            _beatmap_add_wall(wall._inner);
        }
    }
}
pub struct Vec2 {
    _inner: _Vec2,
}
pub struct Vec3 {
    _inner: _Vec3,
}
pub struct Vec4 {
    _inner: _Vec4,
}
pub struct Quat {
    _inner: _Quat,
}
pub struct Color {
    _inner: _Color,
}
extern "C" {
    fn _vec2_get_x(vec2: _Vec2) -> f32;
    fn _vec2_set_x(vec2: _Vec2, x: f32);
    fn _vec2_get_y(vec2: _Vec2) -> f32;
    fn _vec2_set_y(vec2: _Vec2, y: f32);
}
impl Vec2 {
    pub fn get_x(&self) -> f32 {
        unsafe { _vec2_get_x(self._inner) }
    }
    pub fn set_x(&self, x: f32) {
        unsafe { _vec2_set_x(self._inner, x) }
    }
    pub fn get_y(&self) -> f32 {
        unsafe { _vec2_get_y(self._inner) }
    }
    pub fn set_y(&self, y: f32) {
        unsafe { _vec2_set_y(self._inner, y) }
    }
}
extern "C" {
    fn _vec3_get_x(vec3: _Vec3) -> f32;
    fn _vec3_set_x(vec3: _Vec3, x: f32);
    fn _vec3_get_y(vec3: _Vec3) -> f32;
    fn _vec3_set_y(vec3: _Vec3, y: f32);
    fn _vec3_get_z(vec3: _Vec3) -> f32;
    fn _vec3_set_z(vec3: _Vec3, z: f32);
}
impl Vec3 {
    pub fn get_x(&self) -> f32 {
        unsafe { _vec3_get_x(self._inner) }
    }
    pub fn set_x(&self, x: f32) {
        unsafe { _vec3_set_x(self._inner, x) }
    }
    pub fn get_y(&self) -> f32 {
        unsafe { _vec3_get_y(self._inner) }
    }
    pub fn set_y(&self, y: f32) {
        unsafe { _vec3_set_y(self._inner, y) }
    }
    pub fn get_z(&self) -> f32 {
        unsafe { _vec3_get_z(self._inner) }
    }
    pub fn set_z(&self, z: f32) {
        unsafe { _vec3_set_z(self._inner, z) }
    }
}
extern "C" {
    fn _vec4_get_x(vec4: _Vec4) -> f32;
    fn _vec4_set_x(vec4: _Vec4, x: f32);
    fn _vec4_get_y(vec4: _Vec4) -> f32;
    fn _vec4_set_y(vec4: _Vec4, y: f32);
    fn _vec4_get_z(vec4: _Vec4) -> f32;
    fn _vec4_set_z(vec4: _Vec4, z: f32);
    fn _vec4_get_w(vec4: _Vec4) -> f32;
    fn _vec4_set_w(vec4: _Vec4, w: f32);
}
impl Vec4 {
    pub fn get_x(&self) -> f32 {
        unsafe { _vec4_get_x(self._inner) }
    }
    pub fn set_x(&self, x: f32) {
        unsafe { _vec4_set_x(self._inner, x) }
    }
    pub fn get_y(&self) -> f32 {
        unsafe { _vec4_get_y(self._inner) }
    }
    pub fn set_y(&self, y: f32) {
        unsafe { _vec4_set_y(self._inner, y) }
    }
    pub fn get_z(&self) -> f32 {
        unsafe { _vec4_get_z(self._inner) }
    }
    pub fn set_z(&self, z: f32) {
        unsafe { _vec4_set_z(self._inner, z) }
    }
    pub fn get_w(&self) -> f32 {
        unsafe { _vec4_get_w(self._inner) }
    }
    pub fn set_w(&self, w: f32) {
        unsafe { _vec4_set_w(self._inner, w) }
    }
}
extern "C" {
    fn _quat_get_x(quat: _Quat) -> f32;
    fn _quat_set_x(quat: _Quat, x: f32);
    fn _quat_get_y(quat: _Quat) -> f32;
    fn _quat_set_y(quat: _Quat, y: f32);
    fn _quat_get_z(quat: _Quat) -> f32;
    fn _quat_set_z(quat: _Quat, z: f32);
    fn _quat_get_w(quat: _Quat) -> f32;
    fn _quat_set_w(quat: _Quat, w: f32);
}
impl Quat {
    pub fn get_x(&self) -> f32 {
        unsafe { _quat_get_x(self._inner) }
    }
    pub fn set_x(&self, x: f32) {
        unsafe { _quat_set_x(self._inner, x) }
    }
    pub fn get_y(&self) -> f32 {
        unsafe { _quat_get_y(self._inner) }
    }
    pub fn set_y(&self, y: f32) {
        unsafe { _quat_set_y(self._inner, y) }
    }
    pub fn get_z(&self) -> f32 {
        unsafe { _quat_get_z(self._inner) }
    }
    pub fn set_z(&self, z: f32) {
        unsafe { _quat_set_z(self._inner, z) }
    }
    pub fn get_w(&self) -> f32 {
        unsafe { _quat_get_w(self._inner) }
    }
    pub fn set_w(&self, w: f32) {
        unsafe { _quat_set_w(self._inner, w) }
    }
}
extern "C" {
    fn _color_get_r(color: _Color) -> f32;
    fn _color_set_r(color: _Color, r: f32);
    fn _color_get_g(color: _Color) -> f32;
    fn _color_set_g(color: _Color, g: f32);
    fn _color_get_b(color: _Color) -> f32;
    fn _color_set_b(color: _Color, b: f32);
    fn _color_get_a(color: _Color) -> f32;
    fn _color_set_a(color: _Color, a: f32);
}
impl Color {
    pub fn get_r(&self) -> f32 {
        unsafe { _color_get_r(self._inner) }
    }
    pub fn set_r(&self, r: f32) {
        unsafe { _color_set_r(self._inner, r) }
    }
    pub fn get_g(&self) -> f32 {
        unsafe { _color_get_g(self._inner) }
    }
    pub fn set_g(&self, g: f32) {
        unsafe { _color_set_g(self._inner, g) }
    }
    pub fn get_b(&self) -> f32 {
        unsafe { _color_get_b(self._inner) }
    }
    pub fn set_b(&self, b: f32) {
        unsafe { _color_set_b(self._inner, b) }
    }
    pub fn get_a(&self) -> f32 {
        unsafe { _color_get_a(self._inner) }
    }
    pub fn set_a(&self, a: f32) {
        unsafe { _color_set_a(self._inner, a) }
    }
}
pub trait UnityConvertible {
    type UnityType;
    fn to_unity_type(self) -> Self::UnityType;
    fn from_unity_type(t: Self::UnityType) -> Self;
}
impl UnityConvertible for glam::Vec2 {
    type UnityType = Vec2;
    fn to_unity_type(self) -> Self::UnityType {
        Vec2 {
            _inner: unsafe { _vec2_from_xy(self.x, self.y) },
        }
    }
    fn from_unity_type(t: Self::UnityType) -> Self {
        glam::Vec2::new(t.get_x(), t.get_y())
    }
}
impl UnityConvertible for glam::Vec3 {
    type UnityType = Vec3;
    fn to_unity_type(self) -> Self::UnityType {
        Vec3 {
            _inner: unsafe { _vec3_from_xyz(self.x, self.y, self.z) },
        }
    }
    fn from_unity_type(t: Self::UnityType) -> Self {
        glam::Vec3::new(t.get_x(), t.get_y(), t.get_z())
    }
}
impl UnityConvertible for glam::Vec4 {
    type UnityType = Vec4;
    fn to_unity_type(self) -> Self::UnityType {
        Vec4 {
            _inner: unsafe { _vec4_from_xyzw(self.x, self.y, self.z, self.w) },
        }
    }
    fn from_unity_type(t: Self::UnityType) -> Self {
        glam::Vec4::new(t.get_x(), t.get_y(), t.get_z(), t.get_w())
    }
}
impl UnityConvertible for glam::Quat {
    type UnityType = Quat;
    fn to_unity_type(self) -> Self::UnityType {
        Quat {
            _inner: unsafe { _quat_from_xyzw(self.x, self.y, self.z, self.w) },
        }
    }
    fn from_unity_type(t: Self::UnityType) -> Self {
        glam::Quat::from_xyzw(t.get_x(), t.get_y(), t.get_z(), t.get_w())
    }
}
impl Color {
    pub fn set_rgb(&self, r: f32, g: f32, b: f32) {
        unsafe { _color_set_rgb(self._inner, r, g, b) };
    }
    pub fn set_rgba(&self, r: f32, g: f32, b: f32, a: f32) {
        unsafe { _color_set_rgba(self._inner, r, g, b, a) };
    }
}
