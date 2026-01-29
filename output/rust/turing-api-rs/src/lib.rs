
///// Generated Rust API /////
use std::ffi::{CString, CStr, c_char, c_void};


mod alg {
    use super::*;

    #[cfg(feature = "glam")]
    pub use glam::{Vec2, Vec3, Vec4, Quat, Mat4};

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
    fn _log__warn(msg: *const c_char);
    fn _log__info(msg: *const c_char);
    fn _log__debug(msg: *const c_char);
    fn _log__critical(msg: *const c_char);
    fn _note_manager__add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: CustomData);
    fn _note_manager__add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: CustomData);
    fn _note_manager__time_to_beat(time: f32) -> f32;
    fn _note_manager__add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: CustomData);
    fn _turinger_game_object_manager__create_object(name: *const c_char) -> u64;
    fn _turinger_game_object_manager__find(name: *const c_char) -> u64;
    fn _turinger_game_object_manager__destroy_object(listener: TuringerGameObject);
    fn _turinger_game_object_manager__instance_get(opaqu: u64) -> u64;
    fn _get_components_in_parent_by_type(opaqu: u64, cs_type: Type, include_inactive: bool) -> u64;
    fn _turinger_game_object__send_message(opaqu: u64, method_name: *const c_char);
    fn _turinger_game_object__get_component_in_parent_by_type(opaqu: u64, cs_type: Type) -> u64;
    fn _turinger_game_object__is_static_get(opaqu: u64) -> bool;
    fn _turinger_game_object__transform_get(opaqu: u64) -> u64;
    fn _turinger_game_object__get_component_in_children_by_type(opaqu: u64, cs_type: Type) -> u64;
    fn _turinger_game_object__get_components_by_type(opaqu: u64, cs_type: Type, results: List1);
    fn _turinger_game_object__active_set(opaqu: u64, value: bool);
    fn _turinger_game_object__broadcast_message(opaqu: u64, method_name: *const c_char);
    fn _turinger_game_object__game_object_get(opaqu: u64) -> u64;
    fn _turinger_game_object__is_static_set(opaqu: u64, value: bool);
    fn _turinger_game_object__add_component(opaqu: u64, component_type: Type) -> u64;
    fn _turinger_game_object__hide_flags_set(opaqu: u64, value: i32);
    fn _turinger_game_object__send_message_upwards(opaqu: u64, method_name: *const c_char);
    fn _turinger_game_object__compare_tag(opaqu: u64, tag: *const c_char) -> bool;
    fn _turinger_game_object__hide_flags_get(opaqu: u64) -> i32;
    fn _turinger_game_object__tag_set(opaqu: u64, value: *const c_char);
    fn _turinger_game_object__get_instance_id(opaqu: u64) -> i32;
    fn _turinger_game_object__layer_get(opaqu: u64) -> i32;
    fn _get_components_in_children_by_type(opaqu: u64, cs_type: Type, include_inactive: bool) -> u64;
    fn _turinger_game_object__layer_set(opaqu: u64, value: i32);
    fn _turinger_game_object__set_active_recursively(opaqu: u64, state: bool);
    fn _turinger_game_object__get_component_index(opaqu: u64, component: Component) -> i32;
    fn _turinger_game_object__get_component_count(opaqu: u64) -> i32;
    fn _turinger_game_object__get_component_at_index(opaqu: u64, index: i32) -> u64;
    fn _turinger_game_object__tag_get(opaqu: u64) -> u32;
    fn _turinger_game_object__active_self_get(opaqu: u64) -> bool;
    fn _turinger_game_object__name_get(opaqu: u64) -> u32;
    fn _turinger_game_object__get_component_by_type(opaqu: u64, cs_type: Type) -> u64;
    fn _turinger_game_object__active_in_hierarchy_get(opaqu: u64) -> bool;
    fn _turinger_game_object__set_active(opaqu: u64, value: bool);
    fn _turinger_game_object__active_get(opaqu: u64) -> bool;
    fn _turinger_game_object__get_component_by_name(opaqu: u64, cs_type: *const c_char) -> u64;
    fn _turinger_game_object__name_set(opaqu: u64, value: *const c_char);
    fn _turinger_game_object__scene_culling_mask_get(opaqu: u64) -> u64;
    fn _turinger_transform__get_component_by_type(opaqu: u64, cs_type: Type) -> u64;
    fn _turinger_transform__look_at(opaqu: u64, world_position: u32);
    fn _turinger_transform__get_instance_id(opaqu: u64) -> i32;
    fn _turinger_transform__tag_get(opaqu: u64) -> u32;
    fn _turinger_transform__local_euler_angles_get(opaqu: u64) -> u32;
    fn _turinger_transform__rotation_get(opaqu: u64) -> u32;
    fn _turinger_transform__world_to_local_matrix_get(opaqu: u64) -> u32;
    fn _turinger_transform__hierarchy_count_get(opaqu: u64) -> i32;
    fn _get_components_in_children_by_type(opaqu: u64, t: Type, include_inactive: bool) -> u64;
    fn _turinger_transform__name_set(opaqu: u64, value: *const c_char);
    fn _turinger_transform__local_rotation_get(opaqu: u64) -> u32;
    fn _turinger_transform__detach_children(opaqu: u64);
    fn _turinger_transform__inverse_transform_point(opaqu: u64, x: f32, y: f32, z: f32) -> u32;
    fn _turinger_transform__get_component_in_children_by_type(opaqu: u64, t: Type, include_inactive: bool) -> u64;
    fn _turinger_transform__transform_get(opaqu: u64) -> u64;
    fn _turinger_transform__lossy_scale_get(opaqu: u64) -> u32;
    fn _turinger_transform__root_get(opaqu: u64) -> u64;
    fn _turinger_transform__get_components_by_type(opaqu: u64, cs_type: Type, results: List1);
    fn _turinger_transform__get_enumerator(opaqu: u64) -> u64;
    fn _turinger_transform__local_scale_set(opaqu: u64, value: u32);
    fn _turinger_transform__child_count_get(opaqu: u64) -> i32;
    fn _turinger_transform__parent_set(opaqu: u64, value: TuringerTransform);
    fn _turinger_transform__get_child(opaqu: u64, index: i32) -> u64;
    fn _turinger_transform__transform_direction(opaqu: u64, x: f32, y: f32, z: f32) -> u32;
    fn _turinger_transform__has_changed_set(opaqu: u64, value: bool);
    fn _turinger_transform__send_message_upwards(opaqu: u64, method_name: *const c_char, value: Object, options: i32);
    fn _turinger_transform__find_child(opaqu: u64, n: *const c_char) -> u64;
    fn _get_components_in_parent_by_type(opaqu: u64, t: Type, include_inactive: bool) -> u64;
    fn _turinger_transform__rotate(opaqu: u64, axis: u32, angle: f32);
    fn _turinger_transform__has_changed_get(opaqu: u64) -> bool;
    fn _turinger_transform__local_position_get(opaqu: u64) -> u32;
    fn _turinger_transform__translate_relative(opaqu: u64, translation: u32, relative_to: TuringerTransform);
    fn _turinger_transform__local_euler_angles_set(opaqu: u64, value: u32);
    fn _turinger_transform__set_local_position_and_rotation(opaqu: u64, local_position: u32, local_rotation: u32);
    fn _turinger_transform__forward_get(opaqu: u64) -> u32;
    fn _turinger_transform__get_sibling_index(opaqu: u64) -> i32;
    fn _turinger_transform__get_component_in_parent_by_type(opaqu: u64, t: Type, include_inactive: bool) -> u64;
    fn _turinger_transform__up_get(opaqu: u64) -> u32;
    fn _turinger_transform__get_component_index(opaqu: u64) -> i32;
    fn _turinger_transform__rotate_around_local(opaqu: u64, axis: u32, angle: f32);
    fn _turinger_transform__translate(opaqu: u64, translation: u32);
    fn _turinger_transform__broadcast_message(opaqu: u64, method_name: *const c_char, parameter: Object, options: i32);
    fn _turinger_transform__euler_angles_set(opaqu: u64, value: u32);
    fn _turinger_transform__send_message(opaqu: u64, method_name: *const c_char, value: Object, options: i32);
    fn _turinger_transform__parent_get(opaqu: u64) -> u64;
    fn _turinger_transform__local_to_world_matrix_get(opaqu: u64) -> u32;
    fn _turinger_transform__get_component_by_name(opaqu: u64, cs_type: *const c_char) -> u64;
    fn _turinger_transform__set_parent(opaqu: u64, parent: TuringerTransform, world_position_stays: bool);
    fn _turinger_transform__rotate_around(opaqu: u64, axis: u32, angle: f32);
    fn _turinger_transform__hierarchy_capacity_set(opaqu: u64, value: i32);
    fn _turinger_transform__up_set(opaqu: u64, value: u32);
    fn _turinger_transform__inverse_transform_direction(opaqu: u64, x: f32, y: f32, z: f32) -> u32;
    fn _turinger_transform__local_scale_get(opaqu: u64) -> u32;
    fn _turinger_transform__transform_vector(opaqu: u64, x: f32, y: f32, z: f32) -> u32;
    fn _turinger_transform__transform_point(opaqu: u64, x: f32, y: f32, z: f32) -> u32;
    fn _turinger_transform__euler_angles_get(opaqu: u64) -> u32;
    fn _turinger_transform__is_child_of(opaqu: u64, parent: TuringerTransform) -> bool;
    fn _turinger_transform__right_set(opaqu: u64, value: u32);
    fn _turinger_transform__get_child_count(opaqu: u64) -> i32;
    fn _turinger_transform__hide_flags_get(opaqu: u64) -> i32;
    fn _turinger_transform__rotate_relative(opaqu: u64, axis: u32, angle: f32, relative_to: i32);
    fn _turinger_transform__rotation_set(opaqu: u64, value: u32);
    fn _turinger_transform__game_object_get(opaqu: u64) -> u64;
    fn _turinger_transform__hierarchy_capacity_get(opaqu: u64) -> i32;
    fn _turinger_transform__set_as_first_sibling(opaqu: u64);
    fn _turinger_transform__right_get(opaqu: u64) -> u32;
    fn _turinger_transform__local_position_set(opaqu: u64, value: u32);
    fn _turinger_transform__forward_set(opaqu: u64, value: u32);
    fn _turinger_transform__name_get(opaqu: u64) -> u32;
    fn _turinger_transform__compare_tag(opaqu: u64, tag: *const c_char) -> bool;
    fn _turinger_transform__set_as_last_sibling(opaqu: u64);
    fn _turinger_transform__position_get(opaqu: u64) -> u32;
    fn _turinger_transform__set_sibling_index(opaqu: u64, index: i32);
    fn _turinger_transform__position_set(opaqu: u64, value: u32);
    fn _turinger_transform__hide_flags_set(opaqu: u64, value: i32);
    fn _turinger_transform__set_position_and_rotation(opaqu: u64, position: u32, rotation: u32);
    fn _turinger_transform__find(opaqu: u64, n: *const c_char) -> u64;
    fn _turinger_transform__tag_set(opaqu: u64, value: *const c_char);
    fn _turinger_transform__local_rotation_set(opaqu: u64, value: u32);
    fn _turinger_transform__inverse_transform_vector(opaqu: u64, x: f32, y: f32, z: f32) -> u32;
    fn _gc_helper__create() -> u64;
    fn _gc_helper__wasm_garbage_collect(opaqu: u64);
    fn _gc_helper__dispose(opaqu: u64);
    fn _gc_helper__invalidate_all_handles(opaqu: u64);
    fn _xr__get_device_tracking_state(node_int: i32) -> i32;
    fn _xr__get_device_name(node_int: i32) -> u32;
    fn _xr__get_device_secondary_button_state(node_int: i32) -> bool;
    fn _xr__get_device_primary_button_state(node_int: i32) -> bool;
    fn _xr__send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32);
    fn _xr__is_device_valid(node_int: i32) -> bool;
    fn _xr__get_device_battery_level(node_int: i32) -> f32;
    fn _xr__get_device_touchpad(node_int: i32) -> u32;
    fn _xr__get_device_grip_value(node_int: i32) -> f32;
    fn _xr__get_device_trigger_value(node_int: i32) -> f32;
    fn _xr__stop_haptics(node_int: i32);
    fn _xr__get_device_thumbstick(node_int: i32) -> u32;
    fn _xr___manager_get(opaqu: u64) -> u64;
    fn _custom_data__create() -> u64;
    fn _list_create() -> u64;
    fn _custom_data__set_string(custom_data: CustomData, key: *const c_char, value: *const c_char);
    fn _custom_data__set_custom_data(custom_data: CustomData, key: *const c_char, value: CustomData);
    fn _custom_data__list_add_string(list: List1, value: *const c_char);
    fn _custom_data__set_custom_data_list(custom_data: CustomData, key: *const c_char, value: List1);
    fn _custom_data__set_float(custom_data: CustomData, key: *const c_char, value: f32);
    fn _custom_data__list_add_int(list: List1, value: i32);
    fn _custom_data__list_add_bool(list: List1, value: bool);
    fn _custom_data__set_int(custom_data: CustomData, key: *const c_char, value: i32);
    fn _custom_data__set_bool(custom_data: CustomData, key: *const c_char, value: bool);
    fn _custom_data__list_add_custom_data_list(list: List1, value: List1);
    fn _custom_data__list_add_float(list: List1, value: f32);
    fn _custom_data__list_add_custom_data(list: List1, value: CustomData);
}

#[unsafe(no_mangle)]
extern "C" fn _turing_api_semver() -> u64 {
    (0u64 << 32) | (1u64 << 16) | 0u64
}
pub const TURING_API_VERSION: &str = "0.1.0";

//// Functions ////



//// Classes ////

pub struct GameObject {
    opaqu: u64,
}
impl GameObject {
}


pub struct Transform {
    opaqu: u64,
}
impl Transform {
}


pub struct TuringScriptManager {
    opaqu: u64,
}
impl TuringScriptManager {
}


pub struct Object {
    opaqu: u64,
}
impl Object {
}


pub struct List1 {
    opaqu: u64,
}
impl List1 {
}


pub struct List {
    opaqu: u64,
}
impl List {
}


pub struct Component {
    opaqu: u64,
}
impl Component {
}


pub struct Type {
    opaqu: u64,
}
impl Type {
}


pub struct IEnumerator {
    opaqu: u64,
}
impl IEnumerator {
}


pub struct Log {
}
impl Log {

    pub fn warn(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log__warn(msg) }
    }

    pub fn info(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log__info(msg) }
    }

    pub fn debug(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log__debug(msg) }
    }

    pub fn critical(msg: &str) {
        let turing_handle_msg = CString::new(msg).unwrap();
        let msg = turing_handle_msg.as_ptr();
        unsafe { _log__critical(msg) }
    }
}


pub struct NoteManager {
}
impl NoteManager {

    pub fn add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: CustomData) {
        unsafe { _note_manager__add_obstacle(beat, duration, line, layer, width, height, custom_data) }
    }

    pub fn add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: CustomData) {
        unsafe { _note_manager__add_color_note(beat, line, layer, color, cut_direction, custom_data) }
    }

    pub fn time_to_beat(time: f32) -> f32 {
        unsafe { _note_manager__time_to_beat(time) }
    }

    pub fn add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: CustomData) {
        unsafe { _note_manager__add_bomb_note(beat, line, layer, custom_data) }
    }
}


pub struct TuringerGameObjectManager {
    opaqu: u64,
}
impl TuringerGameObjectManager {

    pub fn create_object(name: &str) -> TuringerGameObject {
        let turing_handle_name = CString::new(name).unwrap();
        let name = turing_handle_name.as_ptr();
        let turing_result = unsafe { _turinger_game_object_manager__create_object(name) };
        TuringerGameObject { opaqu: turing_result }
    }

    pub fn find(name: &str) -> TuringerGameObject {
        let turing_handle_name = CString::new(name).unwrap();
        let name = turing_handle_name.as_ptr();
        let turing_result = unsafe { _turinger_game_object_manager__find(name) };
        TuringerGameObject { opaqu: turing_result }
    }

    pub fn destroy_object(listener: TuringerGameObject) {
        unsafe { _turinger_game_object_manager__destroy_object(listener) }
    }

    pub fn instance_get(&self) -> TuringerGameObjectManager {
        let turing_result = unsafe { _turinger_game_object_manager__instance_get(self.opaqu) };
        TuringerGameObjectManager { opaqu: turing_result }
    }
}


pub struct TuringerGameObject {
    opaqu: u64,
}
impl TuringerGameObject {

    pub fn get_components_in_parent_by_type(&self, cs_type: Type, include_inactive: bool) -> Component {
        let turing_result = unsafe { _get_components_in_parent_by_type(self.opaqu, cs_type, include_inactive) };
        Component { opaqu: turing_result }
    }

    pub fn send_message(&self, method_name: &str) {
        let turing_handle_method_name = CString::new(method_name).unwrap();
        let method_name = turing_handle_method_name.as_ptr();
        unsafe { _turinger_game_object__send_message(self.opaqu, method_name) }
    }

    pub fn get_component_in_parent_by_type(&self, cs_type: Type) -> Component {
        let turing_result = unsafe { _turinger_game_object__get_component_in_parent_by_type(self.opaqu, cs_type) };
        Component { opaqu: turing_result }
    }

    pub fn is_static_get(&self) -> bool {
        unsafe { _turinger_game_object__is_static_get(self.opaqu) }
    }

    pub fn transform_get(&self) -> TuringerTransform {
        let turing_result = unsafe { _turinger_game_object__transform_get(self.opaqu) };
        TuringerTransform { opaqu: turing_result }
    }

    pub fn get_component_in_children_by_type(&self, cs_type: Type) -> Component {
        let turing_result = unsafe { _turinger_game_object__get_component_in_children_by_type(self.opaqu, cs_type) };
        Component { opaqu: turing_result }
    }

    pub fn get_components_by_type(&self, cs_type: Type, results: List1) {
        unsafe { _turinger_game_object__get_components_by_type(self.opaqu, cs_type, results) }
    }

    pub fn active_set(&self, value: bool) {
        unsafe { _turinger_game_object__active_set(self.opaqu, value) }
    }

    pub fn broadcast_message(&self, method_name: &str) {
        let turing_handle_method_name = CString::new(method_name).unwrap();
        let method_name = turing_handle_method_name.as_ptr();
        unsafe { _turinger_game_object__broadcast_message(self.opaqu, method_name) }
    }

    pub fn game_object_get(&self) -> GameObject {
        let turing_result = unsafe { _turinger_game_object__game_object_get(self.opaqu) };
        GameObject { opaqu: turing_result }
    }

    pub fn is_static_set(&self, value: bool) {
        unsafe { _turinger_game_object__is_static_set(self.opaqu, value) }
    }

    pub fn add_component(&self, component_type: Type) -> Component {
        let turing_result = unsafe { _turinger_game_object__add_component(self.opaqu, component_type) };
        Component { opaqu: turing_result }
    }

    pub fn hide_flags_set(&self, value: i32) {
        unsafe { _turinger_game_object__hide_flags_set(self.opaqu, value) }
    }

    pub fn send_message_upwards(&self, method_name: &str) {
        let turing_handle_method_name = CString::new(method_name).unwrap();
        let method_name = turing_handle_method_name.as_ptr();
        unsafe { _turinger_game_object__send_message_upwards(self.opaqu, method_name) }
    }

    pub fn compare_tag(&self, tag: &str) -> bool {
        let turing_handle_tag = CString::new(tag).unwrap();
        let tag = turing_handle_tag.as_ptr();
        unsafe { _turinger_game_object__compare_tag(self.opaqu, tag) }
    }

    pub fn hide_flags_get(&self) -> i32 {
        unsafe { _turinger_game_object__hide_flags_get(self.opaqu) }
    }

    pub fn tag_set(&self, value: &str) {
        let turing_handle_value = CString::new(value).unwrap();
        let value = turing_handle_value.as_ptr();
        unsafe { _turinger_game_object__tag_set(self.opaqu, value) }
    }

    pub fn get_instance_id(&self) -> i32 {
        unsafe { _turinger_game_object__get_instance_id(self.opaqu) }
    }

    pub fn layer_get(&self) -> i32 {
        unsafe { _turinger_game_object__layer_get(self.opaqu) }
    }

    pub fn get_components_in_children_by_type(&self, cs_type: Type, include_inactive: bool) -> Component {
        let turing_result = unsafe { _get_components_in_children_by_type(self.opaqu, cs_type, include_inactive) };
        Component { opaqu: turing_result }
    }

    pub fn layer_set(&self, value: i32) {
        unsafe { _turinger_game_object__layer_set(self.opaqu, value) }
    }

    pub fn set_active_recursively(&self, state: bool) {
        unsafe { _turinger_game_object__set_active_recursively(self.opaqu, state) }
    }

    pub fn get_component_index(&self, component: Component) -> i32 {
        unsafe { _turinger_game_object__get_component_index(self.opaqu, component) }
    }

    pub fn get_component_count(&self) -> i32 {
        unsafe { _turinger_game_object__get_component_count(self.opaqu) }
    }

    pub fn get_component_at_index(&self, index: i32) -> Component {
        let turing_result = unsafe { _turinger_game_object__get_component_at_index(self.opaqu, index) };
        Component { opaqu: turing_result }
    }

    pub fn tag_get(&self) -> String {
        let turing_result = unsafe { _turinger_game_object__tag_get(self.opaqu) };
        let mut turing_str: Vec<u8> = vec![0; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn active_self_get(&self) -> bool {
        unsafe { _turinger_game_object__active_self_get(self.opaqu) }
    }

    pub fn name_get(&self) -> String {
        let turing_result = unsafe { _turinger_game_object__name_get(self.opaqu) };
        let mut turing_str: Vec<u8> = vec![0; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn get_component_by_type(&self, cs_type: Type) -> Component {
        let turing_result = unsafe { _turinger_game_object__get_component_by_type(self.opaqu, cs_type) };
        Component { opaqu: turing_result }
    }

    pub fn active_in_hierarchy_get(&self) -> bool {
        unsafe { _turinger_game_object__active_in_hierarchy_get(self.opaqu) }
    }

    pub fn set_active(&self, value: bool) {
        unsafe { _turinger_game_object__set_active(self.opaqu, value) }
    }

    pub fn active_get(&self) -> bool {
        unsafe { _turinger_game_object__active_get(self.opaqu) }
    }

    pub fn get_component_by_name(&self, cs_type: &str) -> Component {
        let turing_handle_cs_type = CString::new(cs_type).unwrap();
        let cs_type = turing_handle_cs_type.as_ptr();
        let turing_result = unsafe { _turinger_game_object__get_component_by_name(self.opaqu, cs_type) };
        Component { opaqu: turing_result }
    }

    pub fn name_set(&self, value: &str) {
        let turing_handle_value = CString::new(value).unwrap();
        let value = turing_handle_value.as_ptr();
        unsafe { _turinger_game_object__name_set(self.opaqu, value) }
    }

    pub fn scene_culling_mask_get(&self) -> u64 {
        unsafe { _turinger_game_object__scene_culling_mask_get(self.opaqu) }
    }
}


pub struct TuringerTransform {
    opaqu: u64,
}
impl TuringerTransform {

    pub fn get_component_by_type(&self, cs_type: Type) -> Component {
        let turing_result = unsafe { _turinger_transform__get_component_by_type(self.opaqu, cs_type) };
        Component { opaqu: turing_result }
    }

    pub fn look_at(&self, world_position: alg::Vec3) {
        let world_position = alg::enqueue_vec3(world_position);
        unsafe { _turinger_transform__look_at(self.opaqu, world_position) }
    }

    pub fn get_instance_id(&self) -> i32 {
        unsafe { _turinger_transform__get_instance_id(self.opaqu) }
    }

    pub fn tag_get(&self) -> String {
        let turing_result = unsafe { _turinger_transform__tag_get(self.opaqu) };
        let mut turing_str: Vec<u8> = vec![0; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn local_euler_angles_get(&self) -> alg::Vec3 {
        unsafe { _turinger_transform__local_euler_angles_get(self.opaqu) };
        alg::dequeue_vec3()
    }

    pub fn rotation_get(&self) -> alg::Quat {
        unsafe { _turinger_transform__rotation_get(self.opaqu) };
        alg::dequeue_quat()
    }

    pub fn world_to_local_matrix_get(&self) -> alg::Mat4 {
        unsafe { _turinger_transform__world_to_local_matrix_get(self.opaqu) };
        alg::dequeue_mat4()
    }

    pub fn hierarchy_count_get(&self) -> i32 {
        unsafe { _turinger_transform__hierarchy_count_get(self.opaqu) }
    }

    pub fn get_components_in_children_by_type(&self, t: Type, include_inactive: bool) -> Component {
        let turing_result = unsafe { _get_components_in_children_by_type(self.opaqu, t, include_inactive) };
        Component { opaqu: turing_result }
    }

    pub fn name_set(&self, value: &str) {
        let turing_handle_value = CString::new(value).unwrap();
        let value = turing_handle_value.as_ptr();
        unsafe { _turinger_transform__name_set(self.opaqu, value) }
    }

    pub fn local_rotation_get(&self) -> alg::Quat {
        unsafe { _turinger_transform__local_rotation_get(self.opaqu) };
        alg::dequeue_quat()
    }

    pub fn detach_children(&self) {
        unsafe { _turinger_transform__detach_children(self.opaqu) }
    }

    pub fn inverse_transform_point(&self, x: f32, y: f32, z: f32) -> alg::Vec3 {
        unsafe { _turinger_transform__inverse_transform_point(self.opaqu, x, y, z) };
        alg::dequeue_vec3()
    }

    pub fn get_component_in_children_by_type(&self, t: Type, include_inactive: bool) -> Component {
        let turing_result = unsafe { _turinger_transform__get_component_in_children_by_type(self.opaqu, t, include_inactive) };
        Component { opaqu: turing_result }
    }

    pub fn transform_get(&self) -> Transform {
        let turing_result = unsafe { _turinger_transform__transform_get(self.opaqu) };
        Transform { opaqu: turing_result }
    }

    pub fn lossy_scale_get(&self) -> alg::Vec3 {
        unsafe { _turinger_transform__lossy_scale_get(self.opaqu) };
        alg::dequeue_vec3()
    }

    pub fn root_get(&self) -> TuringerTransform {
        let turing_result = unsafe { _turinger_transform__root_get(self.opaqu) };
        TuringerTransform { opaqu: turing_result }
    }

    pub fn get_components_by_type(&self, cs_type: Type, results: List1) {
        unsafe { _turinger_transform__get_components_by_type(self.opaqu, cs_type, results) }
    }

    pub fn get_enumerator(&self) -> IEnumerator {
        let turing_result = unsafe { _turinger_transform__get_enumerator(self.opaqu) };
        IEnumerator { opaqu: turing_result }
    }

    pub fn local_scale_set(&self, value: alg::Vec3) {
        let value = alg::enqueue_vec3(value);
        unsafe { _turinger_transform__local_scale_set(self.opaqu, value) }
    }

    pub fn child_count_get(&self) -> i32 {
        unsafe { _turinger_transform__child_count_get(self.opaqu) }
    }

    pub fn parent_set(&self, value: TuringerTransform) {
        unsafe { _turinger_transform__parent_set(self.opaqu, value) }
    }

    pub fn get_child(&self, index: i32) -> TuringerTransform {
        let turing_result = unsafe { _turinger_transform__get_child(self.opaqu, index) };
        TuringerTransform { opaqu: turing_result }
    }

    pub fn transform_direction(&self, x: f32, y: f32, z: f32) -> alg::Vec3 {
        unsafe { _turinger_transform__transform_direction(self.opaqu, x, y, z) };
        alg::dequeue_vec3()
    }

    pub fn has_changed_set(&self, value: bool) {
        unsafe { _turinger_transform__has_changed_set(self.opaqu, value) }
    }

    pub fn send_message_upwards(&self, method_name: &str, value: Object, options: i32) {
        let turing_handle_method_name = CString::new(method_name).unwrap();
        let method_name = turing_handle_method_name.as_ptr();
        unsafe { _turinger_transform__send_message_upwards(self.opaqu, method_name, value, options) }
    }

    pub fn find_child(&self, n: &str) -> TuringerTransform {
        let turing_handle_n = CString::new(n).unwrap();
        let n = turing_handle_n.as_ptr();
        let turing_result = unsafe { _turinger_transform__find_child(self.opaqu, n) };
        TuringerTransform { opaqu: turing_result }
    }

    pub fn get_components_in_parent_by_type(&self, t: Type, include_inactive: bool) -> Component {
        let turing_result = unsafe { _get_components_in_parent_by_type(self.opaqu, t, include_inactive) };
        Component { opaqu: turing_result }
    }

    pub fn rotate(&self, axis: alg::Vec3, angle: f32) {
        let axis = alg::enqueue_vec3(axis);
        unsafe { _turinger_transform__rotate(self.opaqu, axis, angle) }
    }

    pub fn has_changed_get(&self) -> bool {
        unsafe { _turinger_transform__has_changed_get(self.opaqu) }
    }

    pub fn local_position_get(&self) -> alg::Vec3 {
        unsafe { _turinger_transform__local_position_get(self.opaqu) };
        alg::dequeue_vec3()
    }

    pub fn translate_relative(&self, translation: alg::Vec3, relative_to: TuringerTransform) {
        let translation = alg::enqueue_vec3(translation);
        unsafe { _turinger_transform__translate_relative(self.opaqu, translation, relative_to) }
    }

    pub fn local_euler_angles_set(&self, value: alg::Vec3) {
        let value = alg::enqueue_vec3(value);
        unsafe { _turinger_transform__local_euler_angles_set(self.opaqu, value) }
    }

    pub fn set_local_position_and_rotation(&self, local_position: alg::Vec3, local_rotation: alg::Quat) {
        let local_position = alg::enqueue_vec3(local_position);
        let local_rotation = alg::enqueue_quat(local_rotation);
        unsafe { _turinger_transform__set_local_position_and_rotation(self.opaqu, local_position, local_rotation) }
    }

    pub fn forward_get(&self) -> alg::Vec3 {
        unsafe { _turinger_transform__forward_get(self.opaqu) };
        alg::dequeue_vec3()
    }

    pub fn get_sibling_index(&self) -> i32 {
        unsafe { _turinger_transform__get_sibling_index(self.opaqu) }
    }

    pub fn get_component_in_parent_by_type(&self, t: Type, include_inactive: bool) -> Component {
        let turing_result = unsafe { _turinger_transform__get_component_in_parent_by_type(self.opaqu, t, include_inactive) };
        Component { opaqu: turing_result }
    }

    pub fn up_get(&self) -> alg::Vec3 {
        unsafe { _turinger_transform__up_get(self.opaqu) };
        alg::dequeue_vec3()
    }

    pub fn get_component_index(&self) -> i32 {
        unsafe { _turinger_transform__get_component_index(self.opaqu) }
    }

    pub fn rotate_around_local(&self, axis: alg::Vec3, angle: f32) {
        let axis = alg::enqueue_vec3(axis);
        unsafe { _turinger_transform__rotate_around_local(self.opaqu, axis, angle) }
    }

    pub fn translate(&self, translation: alg::Vec3) {
        let translation = alg::enqueue_vec3(translation);
        unsafe { _turinger_transform__translate(self.opaqu, translation) }
    }

    pub fn broadcast_message(&self, method_name: &str, parameter: Object, options: i32) {
        let turing_handle_method_name = CString::new(method_name).unwrap();
        let method_name = turing_handle_method_name.as_ptr();
        unsafe { _turinger_transform__broadcast_message(self.opaqu, method_name, parameter, options) }
    }

    pub fn euler_angles_set(&self, value: alg::Vec3) {
        let value = alg::enqueue_vec3(value);
        unsafe { _turinger_transform__euler_angles_set(self.opaqu, value) }
    }

    pub fn send_message(&self, method_name: &str, value: Object, options: i32) {
        let turing_handle_method_name = CString::new(method_name).unwrap();
        let method_name = turing_handle_method_name.as_ptr();
        unsafe { _turinger_transform__send_message(self.opaqu, method_name, value, options) }
    }

    pub fn parent_get(&self) -> TuringerTransform {
        let turing_result = unsafe { _turinger_transform__parent_get(self.opaqu) };
        TuringerTransform { opaqu: turing_result }
    }

    pub fn local_to_world_matrix_get(&self) -> alg::Mat4 {
        unsafe { _turinger_transform__local_to_world_matrix_get(self.opaqu) };
        alg::dequeue_mat4()
    }

    pub fn get_component_by_name(&self, cs_type: &str) -> Component {
        let turing_handle_cs_type = CString::new(cs_type).unwrap();
        let cs_type = turing_handle_cs_type.as_ptr();
        let turing_result = unsafe { _turinger_transform__get_component_by_name(self.opaqu, cs_type) };
        Component { opaqu: turing_result }
    }

    pub fn set_parent(&self, parent: TuringerTransform, world_position_stays: bool) {
        unsafe { _turinger_transform__set_parent(self.opaqu, parent, world_position_stays) }
    }

    pub fn rotate_around(&self, axis: alg::Vec3, angle: f32) {
        let axis = alg::enqueue_vec3(axis);
        unsafe { _turinger_transform__rotate_around(self.opaqu, axis, angle) }
    }

    pub fn hierarchy_capacity_set(&self, value: i32) {
        unsafe { _turinger_transform__hierarchy_capacity_set(self.opaqu, value) }
    }

    pub fn up_set(&self, value: alg::Vec3) {
        let value = alg::enqueue_vec3(value);
        unsafe { _turinger_transform__up_set(self.opaqu, value) }
    }

    pub fn inverse_transform_direction(&self, x: f32, y: f32, z: f32) -> alg::Vec3 {
        unsafe { _turinger_transform__inverse_transform_direction(self.opaqu, x, y, z) };
        alg::dequeue_vec3()
    }

    pub fn local_scale_get(&self) -> alg::Vec3 {
        unsafe { _turinger_transform__local_scale_get(self.opaqu) };
        alg::dequeue_vec3()
    }

    pub fn transform_vector(&self, x: f32, y: f32, z: f32) -> alg::Vec3 {
        unsafe { _turinger_transform__transform_vector(self.opaqu, x, y, z) };
        alg::dequeue_vec3()
    }

    pub fn transform_point(&self, x: f32, y: f32, z: f32) -> alg::Vec3 {
        unsafe { _turinger_transform__transform_point(self.opaqu, x, y, z) };
        alg::dequeue_vec3()
    }

    pub fn euler_angles_get(&self) -> alg::Vec3 {
        unsafe { _turinger_transform__euler_angles_get(self.opaqu) };
        alg::dequeue_vec3()
    }

    pub fn is_child_of(&self, parent: TuringerTransform) -> bool {
        unsafe { _turinger_transform__is_child_of(self.opaqu, parent) }
    }

    pub fn right_set(&self, value: alg::Vec3) {
        let value = alg::enqueue_vec3(value);
        unsafe { _turinger_transform__right_set(self.opaqu, value) }
    }

    pub fn get_child_count(&self) -> i32 {
        unsafe { _turinger_transform__get_child_count(self.opaqu) }
    }

    pub fn hide_flags_get(&self) -> i32 {
        unsafe { _turinger_transform__hide_flags_get(self.opaqu) }
    }

    pub fn rotate_relative(&self, axis: alg::Vec3, angle: f32, relative_to: i32) {
        let axis = alg::enqueue_vec3(axis);
        unsafe { _turinger_transform__rotate_relative(self.opaqu, axis, angle, relative_to) }
    }

    pub fn rotation_set(&self, value: alg::Quat) {
        let value = alg::enqueue_quat(value);
        unsafe { _turinger_transform__rotation_set(self.opaqu, value) }
    }

    pub fn game_object_get(&self) -> TuringerGameObject {
        let turing_result = unsafe { _turinger_transform__game_object_get(self.opaqu) };
        TuringerGameObject { opaqu: turing_result }
    }

    pub fn hierarchy_capacity_get(&self) -> i32 {
        unsafe { _turinger_transform__hierarchy_capacity_get(self.opaqu) }
    }

    pub fn set_as_first_sibling(&self) {
        unsafe { _turinger_transform__set_as_first_sibling(self.opaqu) }
    }

    pub fn right_get(&self) -> alg::Vec3 {
        unsafe { _turinger_transform__right_get(self.opaqu) };
        alg::dequeue_vec3()
    }

    pub fn local_position_set(&self, value: alg::Vec3) {
        let value = alg::enqueue_vec3(value);
        unsafe { _turinger_transform__local_position_set(self.opaqu, value) }
    }

    pub fn forward_set(&self, value: alg::Vec3) {
        let value = alg::enqueue_vec3(value);
        unsafe { _turinger_transform__forward_set(self.opaqu, value) }
    }

    pub fn name_get(&self) -> String {
        let turing_result = unsafe { _turinger_transform__name_get(self.opaqu) };
        let mut turing_str: Vec<u8> = vec![0; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn compare_tag(&self, tag: &str) -> bool {
        let turing_handle_tag = CString::new(tag).unwrap();
        let tag = turing_handle_tag.as_ptr();
        unsafe { _turinger_transform__compare_tag(self.opaqu, tag) }
    }

    pub fn set_as_last_sibling(&self) {
        unsafe { _turinger_transform__set_as_last_sibling(self.opaqu) }
    }

    pub fn position_get(&self) -> alg::Vec3 {
        unsafe { _turinger_transform__position_get(self.opaqu) };
        alg::dequeue_vec3()
    }

    pub fn set_sibling_index(&self, index: i32) {
        unsafe { _turinger_transform__set_sibling_index(self.opaqu, index) }
    }

    pub fn position_set(&self, value: alg::Vec3) {
        let value = alg::enqueue_vec3(value);
        unsafe { _turinger_transform__position_set(self.opaqu, value) }
    }

    pub fn hide_flags_set(&self, value: i32) {
        unsafe { _turinger_transform__hide_flags_set(self.opaqu, value) }
    }

    pub fn set_position_and_rotation(&self, position: alg::Vec3, rotation: alg::Quat) {
        let position = alg::enqueue_vec3(position);
        let rotation = alg::enqueue_quat(rotation);
        unsafe { _turinger_transform__set_position_and_rotation(self.opaqu, position, rotation) }
    }

    pub fn find(&self, n: &str) -> TuringerTransform {
        let turing_handle_n = CString::new(n).unwrap();
        let n = turing_handle_n.as_ptr();
        let turing_result = unsafe { _turinger_transform__find(self.opaqu, n) };
        TuringerTransform { opaqu: turing_result }
    }

    pub fn tag_set(&self, value: &str) {
        let turing_handle_value = CString::new(value).unwrap();
        let value = turing_handle_value.as_ptr();
        unsafe { _turinger_transform__tag_set(self.opaqu, value) }
    }

    pub fn local_rotation_set(&self, value: alg::Quat) {
        let value = alg::enqueue_quat(value);
        unsafe { _turinger_transform__local_rotation_set(self.opaqu, value) }
    }

    pub fn inverse_transform_vector(&self, x: f32, y: f32, z: f32) -> alg::Vec3 {
        unsafe { _turinger_transform__inverse_transform_vector(self.opaqu, x, y, z) };
        alg::dequeue_vec3()
    }
}


pub struct GcHelper {
    opaqu: u64,
}
impl GcHelper {

    pub fn create() -> GCHelper {
        let turing_result = unsafe { _gc_helper__create() };
        GcHelper { opaqu: turing_result }
    }

    pub fn wasm_garbage_collect(&self) {
        unsafe { _gc_helper__wasm_garbage_collect(self.opaqu) }
    }

    pub fn dispose(&self) {
        unsafe { _gc_helper__dispose(self.opaqu) }
    }

    pub fn invalidate_all_handles(&self) {
        unsafe { _gc_helper__invalidate_all_handles(self.opaqu) }
    }
}


pub struct Xr {
    opaqu: u64,
}
impl Xr {

    pub fn get_device_tracking_state(node_int: i32) -> i32 {
        unsafe { _xr__get_device_tracking_state(node_int) }
    }

    pub fn get_device_name(node_int: i32) -> String {
        let turing_result = unsafe { _xr__get_device_name(node_int) };
        let mut turing_str: Vec<u8> = vec![0; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn get_device_secondary_button_state(node_int: i32) -> bool {
        unsafe { _xr__get_device_secondary_button_state(node_int) }
    }

    pub fn get_device_primary_button_state(node_int: i32) -> bool {
        unsafe { _xr__get_device_primary_button_state(node_int) }
    }

    pub fn send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32) {
        unsafe { _xr__send_haptic_impulse(node_int, amplitude, duration) }
    }

    pub fn is_device_valid(node_int: i32) -> bool {
        unsafe { _xr__is_device_valid(node_int) }
    }

    pub fn get_device_battery_level(node_int: i32) -> f32 {
        unsafe { _xr__get_device_battery_level(node_int) }
    }

    pub fn get_device_touchpad(node_int: i32) -> alg::Vec2 {
        unsafe { _xr__get_device_touchpad(node_int) };
        alg::dequeue_vec2()
    }

    pub fn get_device_grip_value(node_int: i32) -> f32 {
        unsafe { _xr__get_device_grip_value(node_int) }
    }

    pub fn get_device_trigger_value(node_int: i32) -> f32 {
        unsafe { _xr__get_device_trigger_value(node_int) }
    }

    pub fn stop_haptics(node_int: i32) {
        unsafe { _xr__stop_haptics(node_int) }
    }

    pub fn get_device_thumbstick(node_int: i32) -> alg::Vec2 {
        unsafe { _xr__get_device_thumbstick(node_int) };
        alg::dequeue_vec2()
    }

    pub fn _manager_get(&self) -> TuringScriptManager {
        let turing_result = unsafe { _xr___manager_get(self.opaqu) };
        TuringScriptManager { opaqu: turing_result }
    }
}


pub struct CustomData {
    opaqu: u64,
}
impl CustomData {

    pub fn create() -> CustomData {
        let turing_result = unsafe { _custom_data__create() };
        CustomData { opaqu: turing_result }
    }

    pub fn list_create() -> List {
        let turing_result = unsafe { _list_create() };
        List { opaqu: turing_result }
    }

    pub fn set_string(custom_data: CustomData, key: &str, value: &str) {
        let turing_handle_key = CString::new(key).unwrap();
        let key = turing_handle_key.as_ptr();
        let turing_handle_value = CString::new(value).unwrap();
        let value = turing_handle_value.as_ptr();
        unsafe { _custom_data__set_string(custom_data, key, value) }
    }

    pub fn set_custom_data(custom_data: CustomData, key: &str, value: CustomData) {
        let turing_handle_key = CString::new(key).unwrap();
        let key = turing_handle_key.as_ptr();
        unsafe { _custom_data__set_custom_data(custom_data, key, value) }
    }

    pub fn list_add_string(list: List1, value: &str) {
        let turing_handle_value = CString::new(value).unwrap();
        let value = turing_handle_value.as_ptr();
        unsafe { _custom_data__list_add_string(list, value) }
    }

    pub fn set_custom_data_list(custom_data: CustomData, key: &str, value: List1) {
        let turing_handle_key = CString::new(key).unwrap();
        let key = turing_handle_key.as_ptr();
        unsafe { _custom_data__set_custom_data_list(custom_data, key, value) }
    }

    pub fn set_float(custom_data: CustomData, key: &str, value: f32) {
        let turing_handle_key = CString::new(key).unwrap();
        let key = turing_handle_key.as_ptr();
        unsafe { _custom_data__set_float(custom_data, key, value) }
    }

    pub fn list_add_int(list: List1, value: i32) {
        unsafe { _custom_data__list_add_int(list, value) }
    }

    pub fn list_add_bool(list: List1, value: bool) {
        unsafe { _custom_data__list_add_bool(list, value) }
    }

    pub fn set_int(custom_data: CustomData, key: &str, value: i32) {
        let turing_handle_key = CString::new(key).unwrap();
        let key = turing_handle_key.as_ptr();
        unsafe { _custom_data__set_int(custom_data, key, value) }
    }

    pub fn set_bool(custom_data: CustomData, key: &str, value: bool) {
        let turing_handle_key = CString::new(key).unwrap();
        let key = turing_handle_key.as_ptr();
        unsafe { _custom_data__set_bool(custom_data, key, value) }
    }

    pub fn list_add_custom_data_list(list: List1, value: List1) {
        unsafe { _custom_data__list_add_custom_data_list(list, value) }
    }

    pub fn list_add_float(list: List1, value: f32) {
        unsafe { _custom_data__list_add_float(list, value) }
    }

    pub fn list_add_custom_data(list: List1, value: CustomData) {
        unsafe { _custom_data__list_add_custom_data(list, value) }
    }
}



