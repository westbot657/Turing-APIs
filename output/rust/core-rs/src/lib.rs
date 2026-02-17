///// Generated Rust API /////
use std::ffi::{CString, CStr, c_char, c_void};





//// Core Systems ////
pub mod alg {
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

    /// Not for public use. This method is marked public so that API extensions may access it.
    /// A user script should never be calling this directly
    pub fn dequeue_vec2() -> Vec2 {
        let x = unsafe { _host_f32_dequeue() };
        let y = unsafe { _host_f32_dequeue() };
        Vec2::new(x, y)
    }

    /// Not for public use. This method is marked public so that API extensions may access it.
    /// A user script should never be calling this directly
    pub fn enqueue_vec2(v: Vec2) -> u32 {
        unsafe {
            _host_f32_enqueue(v.x);
            _host_f32_enqueue(v.y);
        }
        2
    }

    /// Not for public use. This method is marked public so that API extensions may access it.
    /// A user script should never be calling this directly
    pub fn dequeue_vec3() -> Vec3 {
        let x = unsafe { _host_f32_dequeue() };
        let y = unsafe { _host_f32_dequeue() };
        let z = unsafe { _host_f32_dequeue() };
        Vec3::new(x, y, z)
    }

    /// Not for public use. This method is marked public so that API extensions may access it.
    /// A user script should never be calling this directly
    pub fn enqueue_vec3(v: Vec3) -> u32 {
        unsafe {
            _host_f32_enqueue(v.x);
            _host_f32_enqueue(v.y);
            _host_f32_enqueue(v.z);
        }
        3
    }

    /// Not for public use. This method is marked public so that API extensions may access it.
    /// A user script should never be calling this directly
    pub fn dequeue_vec4() -> Vec4 {
        let x = unsafe { _host_f32_dequeue() };
        let y = unsafe { _host_f32_dequeue() };
        let z = unsafe { _host_f32_dequeue() };
        let w = unsafe { _host_f32_dequeue() };
        Vec4::new(x, y, z, w)
    }

    /// Not for public use. This method is marked public so that API extensions may access it.
    /// A user script should never be calling this directly
    pub fn enqueue_vec4(v: Vec4) -> u32 {
        unsafe {
            _host_f32_enqueue(v.x);
            _host_f32_enqueue(v.y);
            _host_f32_enqueue(v.z);
            _host_f32_enqueue(v.w);
        }
        4
    }

    /// Not for public use. This method is marked public so that API extensions may access it.
    /// A user script should never be calling this directly
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

    /// Not for public use. This method is marked public so that API extensions may access it.
    /// A user script should never be calling this directly
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

    /// Not for public use. This method is marked public so that API extensions may access it.
    /// A user script should never be calling this directly
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

    /// Not for public use. This method is marked public so that API extensions may access it.
    /// A user script should never be calling this directly
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
    
    /// For internal use only.
    /// Copies a string from the host's memory to the pointer specified
    pub fn _host_strcpy(location: *mut c_char, size: u32);
    /// For internal use only.
    /// Copies a Vec<u32> from the host's memory to the pointer specified
    pub fn _host_bufcpy(location: *mut c_void, size: u32);
    /// For internal use only.
    /// Pushes an f32 to a queue for passing math objects
    pub fn _host_f32_enqueue(f: f32);
    /// For internal use only.
    /// pops an f32 from the queue for passing math objects
    pub fn _host_f32_dequeue() -> f32;
    /// For internal use only.
    /// Pushes a u32 to a queue for passing buffer lengths
    pub fn _host_u32_enqueue(u: u32);
    /// For internal use only.
    /// pops a u32 from the queue for passing buffer lengths
    pub fn _host_u32_dequeue() -> u32;
    
    fn _core_custom_data__create() -> CustomData;
    fn _core_custom_data__from_json(json: *const c_char) -> CustomData;
    fn _core_custom_data__list_add_bool(list: List1, value: bool);
    fn _core_custom_data__list_add_custom_data(list: List1, value: CustomData);
    fn _core_custom_data__list_add_custom_data_list(list: List1, value: List1);
    fn _core_custom_data__list_add_float(list: List1, value: f32);
    fn _core_custom_data__list_add_int(list: List1, value: i32);
    fn _core_custom_data__list_add_string(list: List1, value: *const c_char);
    fn _core_custom_data__set_bool(custom_data: CustomData, key: *const c_char, value: bool);
    fn _core_custom_data__set_custom_data(custom_data: CustomData, key: *const c_char, value: CustomData);
    fn _core_custom_data__set_custom_data_list(custom_data: CustomData, key: *const c_char, value: List1);
    fn _core_custom_data__set_float(custom_data: CustomData, key: *const c_char, value: f32);
    fn _core_custom_data__set_int(custom_data: CustomData, key: *const c_char, value: i32);
    fn _core_custom_data__set_string(custom_data: CustomData, key: *const c_char, value: *const c_char);
    fn _core_custom_data__to_json(custom_data: CustomData, pretty: bool) -> u32;
    fn _core_custom_event_data__custom_data_get(handle: CustomEventData) -> CustomData;
    fn _core_custom_event_data__event_type_get(handle: CustomEventData) -> u32;
    fn _core_custom_event_data__get_copy(handle: CustomEventData) -> BeatmapDataItem;
    fn _core_custom_event_data__version_get(handle: CustomEventData) -> Version;
    fn _core_custom_note_data__create_custom_basic_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) -> CustomNoteData;
    fn _core_custom_note_data__create_custom_bomb_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) -> CustomNoteData;
    fn _core_custom_note_data__create_custom_burst_slider_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) -> CustomNoteData;
    fn _core_custom_note_data__custom_data_get(handle: CustomNoteData) -> CustomData;
    fn _core_custom_note_data__get_copy(handle: CustomNoteData) -> BeatmapDataItem;
    fn _core_custom_note_data__version_get(handle: CustomNoteData) -> Version;
    fn _core_custom_obstacle_data__custom_data_get(handle: CustomObstacleData) -> CustomData;
    fn _core_custom_obstacle_data__get_copy(handle: CustomObstacleData) -> BeatmapDataItem;
    fn _core_custom_obstacle_data__version_get(handle: CustomObstacleData) -> Version;
    fn _core_game_object__add_component(handle: GameObject, component_type: Type) -> Component;
    fn _core_game_object__add_or_get_mesh(handle: GameObject) -> TuringMesh;
    fn _core_game_object__broadcast_message(handle: GameObject, method_name: *const c_char, options: i32);
    fn _core_game_object__compare_tag(handle: GameObject, tag: *const c_char) -> bool;
    fn _core_game_object__get_active(handle: GameObject) -> bool;
    fn _core_game_object__get_active_in_hierarchy(handle: GameObject) -> bool;
    fn _core_game_object__get_active_self(handle: GameObject) -> bool;
    fn _core_game_object__get_component_at_index(handle: GameObject, index: i32) -> Component;
    fn _core_game_object__get_component_by_name(handle: GameObject, cs_type: *const c_char) -> Component;
    fn _core_game_object__get_component_by_type(handle: GameObject, cs_type: Type) -> Component;
    fn _core_game_object__get_component_count(handle: GameObject) -> i32;
    fn _core_game_object__get_component_in_children_by_type(handle: GameObject, cs_type: Type, include_inactive: bool) -> Component;
    fn _core_game_object__get_component_in_parent_by_type(handle: GameObject, cs_type: Type, include_inactive: bool) -> Component;
    fn _core_game_object__get_component_index(handle: GameObject, component: Component) -> i32;
    fn _core_game_object__get_hide_flags(handle: GameObject) -> i32;
    fn _core_game_object__get_instance_id(handle: GameObject) -> i32;
    fn _core_game_object__get_is_static(handle: GameObject) -> bool;
    fn _core_game_object__get_layer(handle: GameObject) -> i32;
    fn _core_game_object__get_name(handle: GameObject) -> u32;
    fn _core_game_object__get_scene_culling_mask(handle: GameObject) -> u64;
    fn _core_game_object__get_tag(handle: GameObject) -> u32;
    fn _core_game_object__get_transform(handle: GameObject) -> Transform;
    fn _core_game_object__send_message(handle: GameObject, method_name: *const c_char, options: i32);
    fn _core_game_object__send_message_upwards(handle: GameObject, method_name: *const c_char, options: i32);
    fn _core_game_object__set_active(handle: GameObject, value: bool);
    fn _core_game_object__set_active_prop(handle: GameObject, value: bool);
    fn _core_game_object__set_active_recursively(handle: GameObject, state: bool);
    fn _core_game_object__set_hide_flags(handle: GameObject, value: i32);
    fn _core_game_object__set_is_static(handle: GameObject, value: bool);
    fn _core_game_object__set_layer(handle: GameObject, value: i32);
    fn _core_game_object__set_name(handle: GameObject, value: *const c_char);
    fn _core_game_object__set_tag(handle: GameObject, value: *const c_char);
    fn _core_gc_helper__create() -> GCHelper;
    fn _core_gc_helper__dispose(handle: GcHelper);
    fn _core_gc_helper__invalidate_all_handles(handle: GcHelper);
    fn _core_gc_helper__wasm_garbage_collect(handle: GcHelper);
    fn _core_log__critical(msg: *const c_char);
    fn _core_log__debug(msg: *const c_char);
    fn _core_log__info(msg: *const c_char);
    fn _core_log__warn(msg: *const c_char);
    fn _core_note_floor_movement___audio_time_sync_controller_get(handle: NoteFloorMovement) -> IAudioTimeSource;
    fn _core_note_floor_movement___beat_time_get(handle: NoteFloorMovement) -> f32;
    fn _core_note_floor_movement___beat_time_set(handle: NoteFloorMovement, value: f32);
    fn _core_note_floor_movement___inverse_world_rotation_get(handle: NoteFloorMovement) -> u32;
    fn _core_note_floor_movement___inverse_world_rotation_set(handle: NoteFloorMovement, value: u32);
    fn _core_note_floor_movement___local_position_get(handle: NoteFloorMovement) -> u32;
    fn _core_note_floor_movement___local_position_set(handle: NoteFloorMovement, value: u32);
    fn _core_note_floor_movement___move_end_offset_get(handle: NoteFloorMovement) -> u32;
    fn _core_note_floor_movement___move_end_offset_set(handle: NoteFloorMovement, value: u32);
    fn _core_note_floor_movement___move_start_offset_get(handle: NoteFloorMovement) -> u32;
    fn _core_note_floor_movement___move_start_offset_set(handle: NoteFloorMovement, value: u32);
    fn _core_note_floor_movement___player_transforms_get(handle: NoteFloorMovement) -> PlayerTransforms;
    fn _core_note_floor_movement___rotated_object_get(handle: NoteFloorMovement) -> Transform;
    fn _core_note_floor_movement___rotated_object_set(handle: NoteFloorMovement, value: Transform);
    fn _core_note_floor_movement___variable_movement_data_provider_get(handle: NoteFloorMovement) -> IVariableMovementDataProvider;
    fn _core_note_floor_movement___world_rotation_get(handle: NoteFloorMovement) -> u32;
    fn _core_note_floor_movement___world_rotation_set(handle: NoteFloorMovement, value: u32);
    fn _core_note_floor_movement__distance_to_player_get(handle: NoteFloorMovement) -> f32;
    fn _core_note_floor_movement__end_pos_get(handle: NoteFloorMovement) -> u32;
    fn _core_note_floor_movement__init(handle: NoteFloorMovement, world_rotation: f32, beat_time: f32, move_start_offset: u32, move_end_offset: u32);
    fn _core_note_floor_movement__inverse_world_rotation_get(handle: NoteFloorMovement) -> u32;
    fn _core_note_floor_movement__local_position_get(handle: NoteFloorMovement) -> u32;
    fn _core_note_floor_movement__manual_update(handle: NoteFloorMovement) -> u32;
    fn _core_note_floor_movement__note_time_get(handle: NoteFloorMovement) -> f32;
    fn _core_note_floor_movement__set_to_start(handle: NoteFloorMovement) -> u32;
    fn _core_note_floor_movement__should_move(handle: NoteFloorMovement) -> bool;
    fn _core_note_floor_movement__world_rotation_get(handle: NoteFloorMovement) -> u32;
    fn _core_note_jump__k_missed_time_offset_get() -> f32;
    fn _core_note_jump___audio_time_sync_controller_get(handle: NoteJump) -> IAudioTimeSource;
    fn _core_note_jump___end_distance_offset_get(handle: NoteJump) -> f32;
    fn _core_note_jump___end_distance_offset_set(handle: NoteJump, value: f32);
    fn _core_note_jump___end_offset_get(handle: NoteJump) -> u32;
    fn _core_note_jump___end_offset_set(handle: NoteJump, value: u32);
    fn _core_note_jump___end_pos_get(handle: NoteJump) -> u32;
    fn _core_note_jump___end_pos_set(handle: NoteJump, value: u32);
    fn _core_note_jump___end_rotation_get(handle: NoteJump) -> u32;
    fn _core_note_jump___end_rotation_set(handle: NoteJump, value: u32);
    fn _core_note_jump___gravity_base_get(handle: NoteJump) -> f32;
    fn _core_note_jump___gravity_base_set(handle: NoteJump, value: f32);
    fn _core_note_jump___gravity_get(handle: NoteJump) -> f32;
    fn _core_note_jump___gravity_set(handle: NoteJump, value: f32);
    fn _core_note_jump___half_jump_duration_get(handle: NoteJump) -> f32;
    fn _core_note_jump___half_jump_duration_set(handle: NoteJump, value: f32);
    fn _core_note_jump___half_jump_mark_reported_get(handle: NoteJump) -> bool;
    fn _core_note_jump___half_jump_mark_reported_set(handle: NoteJump, value: bool);
    fn _core_note_jump___inverse_world_rotation_get(handle: NoteJump) -> u32;
    fn _core_note_jump___inverse_world_rotation_set(handle: NoteJump, value: u32);
    fn _core_note_jump___jump_duration_get(handle: NoteJump) -> f32;
    fn _core_note_jump___jump_duration_set(handle: NoteJump, value: f32);
    fn _core_note_jump___jump_started_reported_get(handle: NoteJump) -> bool;
    fn _core_note_jump___jump_started_reported_set(handle: NoteJump, value: bool);
    fn _core_note_jump___local_position_get(handle: NoteJump) -> u32;
    fn _core_note_jump___local_position_set(handle: NoteJump, value: u32);
    fn _core_note_jump___middle_rotation_get(handle: NoteJump) -> u32;
    fn _core_note_jump___middle_rotation_set(handle: NoteJump, value: u32);
    fn _core_note_jump___missed_mark_reported_get(handle: NoteJump) -> bool;
    fn _core_note_jump___missed_mark_reported_set(handle: NoteJump, value: bool);
    fn _core_note_jump___missed_time_get(handle: NoteJump) -> f32;
    fn _core_note_jump___missed_time_set(handle: NoteJump, value: f32);
    fn _core_note_jump___note_time_get(handle: NoteJump) -> f32;
    fn _core_note_jump___note_time_set(handle: NoteJump, value: f32);
    fn _core_note_jump___player_space_convertor_get(handle: NoteJump) -> PlayerSpaceConvertor;
    fn _core_note_jump___player_transforms_get(handle: NoteJump) -> PlayerTransforms;
    fn _core_note_jump___rotate_towards_player_get(handle: NoteJump) -> bool;
    fn _core_note_jump___rotate_towards_player_set(handle: NoteJump, value: bool);
    fn _core_note_jump___rotated_object_get(handle: NoteJump) -> Transform;
    fn _core_note_jump___rotated_object_set(handle: NoteJump, value: Transform);
    fn _core_note_jump___start_offset_get(handle: NoteJump) -> u32;
    fn _core_note_jump___start_offset_set(handle: NoteJump, value: u32);
    fn _core_note_jump___start_pos_get(handle: NoteJump) -> u32;
    fn _core_note_jump___start_pos_set(handle: NoteJump, value: u32);
    fn _core_note_jump___start_rotation_get(handle: NoteJump) -> u32;
    fn _core_note_jump___start_rotation_set(handle: NoteJump, value: u32);
    fn _core_note_jump___three_quarters_mark_reported_get(handle: NoteJump) -> bool;
    fn _core_note_jump___three_quarters_mark_reported_set(handle: NoteJump, value: bool);
    fn _core_note_jump___variable_movement_data_provider_get(handle: NoteJump) -> IVariableMovementDataProvider;
    fn _core_note_jump___world_rotation_get(handle: NoteJump) -> u32;
    fn _core_note_jump___world_rotation_set(handle: NoteJump, value: u32);
    fn _core_note_jump___y_avoidance_down_get(handle: NoteJump) -> f32;
    fn _core_note_jump___y_avoidance_down_set(handle: NoteJump, value: f32);
    fn _core_note_jump___y_avoidance_get(handle: NoteJump) -> f32;
    fn _core_note_jump___y_avoidance_set(handle: NoteJump, value: f32);
    fn _core_note_jump___y_avoidance_up_get(handle: NoteJump) -> f32;
    fn _core_note_jump___y_avoidance_up_set(handle: NoteJump, value: f32);
    fn _core_note_jump__add_note_jump_did_finish_event(handle: NoteJump, value: Action);
    fn _core_note_jump__add_note_jump_did_pass_half_event(handle: NoteJump, value: Action);
    fn _core_note_jump__add_note_jump_did_pass_missed_marker_event(handle: NoteJump, value: Action);
    fn _core_note_jump__add_note_jump_did_pass_three_quarters_event(handle: NoteJump, value: Action1);
    fn _core_note_jump__add_note_jump_did_start_event(handle: NoteJump, value: Action);
    fn _core_note_jump__add_note_jump_did_update_progress_event(handle: NoteJump, value: Action1);
    fn _core_note_jump__beat_pos_get(handle: NoteJump) -> u32;
    fn _core_note_jump__distance_to_player_get(handle: NoteJump) -> f32;
    fn _core_note_jump__init(handle: NoteJump, note_time: f32, world_rotation: f32, move_end_offset: u32, jump_end_offset: u32, gravity_base: f32, flip_y_side: f32, end_rotation: f32, rotate_towards_player: bool, use_random_rotation: bool);
    fn _core_note_jump__local_position_get(handle: NoteJump) -> u32;
    fn _core_note_jump__manual_update(handle: NoteJump) -> u32;
    fn _core_note_jump__move_vec_get(handle: NoteJump) -> u32;
    fn _core_note_jump__note_time_get(handle: NoteJump) -> f32;
    fn _core_note_jump__remove_note_jump_did_finish_event(handle: NoteJump, value: Action);
    fn _core_note_jump__remove_note_jump_did_pass_half_event(handle: NoteJump, value: Action);
    fn _core_note_jump__remove_note_jump_did_pass_missed_marker_event(handle: NoteJump, value: Action);
    fn _core_note_jump__remove_note_jump_did_pass_three_quarters_event(handle: NoteJump, value: Action1);
    fn _core_note_jump__remove_note_jump_did_start_event(handle: NoteJump, value: Action);
    fn _core_note_jump__remove_note_jump_did_update_progress_event(handle: NoteJump, value: Action1);
    fn _core_note_manager__add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: CustomData) -> CustomNoteData;
    fn _core_note_manager__add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: CustomData) -> CustomNoteData;
    fn _core_note_manager__add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: CustomData) -> CustomObstacleData;
    fn _core_note_manager__get_note_controller(n: i32) -> NoteControllerBase;
    fn _core_note_manager__get_note_controller_from_custom(n: CustomNoteData) -> NoteControllerBase;
    fn _core_note_manager__get_nth_event(id: i32) -> CustomEventData;
    fn _core_note_manager__get_nth_note(id: i32) -> CustomNoteData;
    fn _core_note_manager__get_nth_object(id: i32) -> BeatmapDataItem;
    fn _core_note_manager__get_nth_obstacle(id: i32) -> CustomObstacleData;
    fn _core_note_manager__get_obstacle_controller(n: i32) -> ObstacleControllerBase;
    fn _core_note_manager__get_obstacle_controller_from_custom(n: CustomObstacleData) -> ObstacleController;
    fn _core_note_manager__time_to_beat(time: f32) -> f32;
    fn _core_task_scheduler__schedule(task: Action);
    fn _core_task_scheduler__dispose(handle: TaskScheduler);
    fn _core_transform__broadcast_message(handle: Transform, method_name: *const c_char, parameter: Object, options: i32);
    fn _core_transform__compare_tag(handle: Transform, tag: *const c_char) -> bool;
    fn _core_transform__detach_children(handle: Transform);
    fn _core_transform__find(handle: Transform, n: *const c_char) -> Transform;
    fn _core_transform__find_child(handle: Transform, n: *const c_char) -> Transform;
    fn _core_transform__get_child(handle: Transform, index: i32) -> Transform;
    fn _core_transform__get_child_count(handle: Transform) -> i32;
    fn _core_transform__get_child_count_prop(handle: Transform) -> i32;
    fn _core_transform__get_component_by_name(handle: Transform, cs_type: *const c_char) -> Component;
    fn _core_transform__get_component_by_type(handle: Transform, cs_type: Type) -> Component;
    fn _core_transform__get_component_in_children_by_type(handle: Transform, t: Type, include_inactive: bool) -> Component;
    fn _core_transform__get_component_in_parent_by_type(handle: Transform, t: Type, include_inactive: bool) -> Component;
    fn _core_transform__get_component_index(handle: Transform) -> i32;
    fn _core_transform__get_enumerator(handle: Transform) -> IEnumerator;
    fn _core_transform__get_euler_angles(handle: Transform) -> u32;
    fn _core_transform__get_forward(handle: Transform) -> u32;
    fn _core_transform__get_game_object(handle: Transform) -> GameObject;
    fn _core_transform__get_has_changed(handle: Transform) -> bool;
    fn _core_transform__get_hide_flags(handle: Transform) -> i32;
    fn _core_transform__get_hierarchy_capacity(handle: Transform) -> i32;
    fn _core_transform__get_hierarchy_count(handle: Transform) -> i32;
    fn _core_transform__get_instance_id(handle: Transform) -> i32;
    fn _core_transform__get_local_euler_angles(handle: Transform) -> u32;
    fn _core_transform__get_local_position(handle: Transform) -> u32;
    fn _core_transform__get_local_rotation(handle: Transform) -> u32;
    fn _core_transform__get_local_scale(handle: Transform) -> u32;
    fn _core_transform__get_local_to_world_matrix(handle: Transform) -> u32;
    fn _core_transform__get_lossy_scale(handle: Transform) -> u32;
    fn _core_transform__get_name(handle: Transform) -> u32;
    fn _core_transform__get_parent(handle: Transform) -> Transform;
    fn _core_transform__get_position(handle: Transform) -> u32;
    fn _core_transform__get_right(handle: Transform) -> u32;
    fn _core_transform__get_root(handle: Transform) -> Transform;
    fn _core_transform__get_rotation(handle: Transform) -> u32;
    fn _core_transform__get_sibling_index(handle: Transform) -> i32;
    fn _core_transform__get_tag(handle: Transform) -> u32;
    fn _core_transform__get_up(handle: Transform) -> u32;
    fn _core_transform__get_world_to_local_matrix(handle: Transform) -> u32;
    fn _core_transform__inverse_transform_direction(handle: Transform, direction: u32) -> u32;
    fn _core_transform__inverse_transform_point(handle: Transform, position: u32) -> u32;
    fn _core_transform__inverse_transform_vector(handle: Transform, vector: u32) -> u32;
    fn _core_transform__is_child_of(handle: Transform, parent: Transform) -> bool;
    fn _core_transform__look_at(handle: Transform, target: Transform, world_up: u32);
    fn _core_transform__rotate(handle: Transform, eulers: u32);
    fn _core_transform__rotate_around(handle: Transform, point: u32, axis: u32, angle: f32);
    fn _core_transform__rotate_around_local(handle: Transform, axis: u32, angle: f32);
    fn _core_transform__rotate_relative(handle: Transform, eulers: u32, relative_to: i32);
    fn _core_transform__send_message(handle: Transform, method_name: *const c_char, value: Object, options: i32);
    fn _core_transform__send_message_upwards(handle: Transform, method_name: *const c_char, value: Object, options: i32);
    fn _core_transform__set_as_first_sibling(handle: Transform);
    fn _core_transform__set_as_last_sibling(handle: Transform);
    fn _core_transform__set_euler_angles(handle: Transform, value: u32);
    fn _core_transform__set_forward(handle: Transform, value: u32);
    fn _core_transform__set_has_changed(handle: Transform, value: bool);
    fn _core_transform__set_hide_flags(handle: Transform, value: i32);
    fn _core_transform__set_hierarchy_capacity(handle: Transform, value: i32);
    fn _core_transform__set_local_euler_angles(handle: Transform, value: u32);
    fn _core_transform__set_local_position(handle: Transform, value: u32);
    fn _core_transform__set_local_position_and_rotation(handle: Transform, local_position: u32, local_rotation: u32);
    fn _core_transform__set_local_rotation(handle: Transform, value: u32);
    fn _core_transform__set_local_scale(handle: Transform, value: u32);
    fn _core_transform__set_name(handle: Transform, value: *const c_char);
    fn _core_transform__set_parent(handle: Transform, parent: Transform, world_position_stays: bool);
    fn _core_transform__set_position(handle: Transform, value: u32);
    fn _core_transform__set_position_and_rotation(handle: Transform, position: u32, rotation: u32);
    fn _core_transform__set_right(handle: Transform, value: u32);
    fn _core_transform__set_rotation(handle: Transform, value: u32);
    fn _core_transform__set_sibling_index(handle: Transform, index: i32);
    fn _core_transform__set_tag(handle: Transform, value: *const c_char);
    fn _core_transform__set_up(handle: Transform, value: u32);
    fn _core_transform__transform_direction(handle: Transform, direction: u32) -> u32;
    fn _core_transform__transform_point(handle: Transform, position: u32) -> u32;
    fn _core_transform__transform_vector(handle: Transform, vector: u32) -> u32;
    fn _core_transform__translate(handle: Transform, translation: u32, relative_to: i32);
    fn _core_transform__translate_relative(handle: Transform, translation: u32, relative_to: Transform);
    fn _core_turing_mesh___mesh_get(handle: TuringMesh) -> Mesh;
    fn _core_turing_mesh___mesh_set(handle: TuringMesh, value: Mesh);
    fn _core_turing_mesh__clear(handle: TuringMesh);
    fn _core_turing_mesh__get_bounds_max_x(handle: TuringMesh) -> f32;
    fn _core_turing_mesh__get_bounds_max_y(handle: TuringMesh) -> f32;
    fn _core_turing_mesh__get_bounds_max_z(handle: TuringMesh) -> f32;
    fn _core_turing_mesh__get_bounds_min_x(handle: TuringMesh) -> f32;
    fn _core_turing_mesh__get_bounds_min_y(handle: TuringMesh) -> f32;
    fn _core_turing_mesh__get_bounds_min_z(handle: TuringMesh) -> f32;
    fn _core_turing_mesh__get_instance_id(handle: TuringMesh) -> i32;
    fn _core_turing_mesh__get_u_vs(handle: TuringMesh, channel: i32) -> u32;
    fn _core_turing_mesh__get_vertices(handle: TuringMesh) -> u32;
    fn _core_turing_mesh__hide_flags_get(handle: TuringMesh);
    fn _core_turing_mesh__hide_flags_set(handle: TuringMesh);
    fn _core_turing_mesh__mark_modified(handle: TuringMesh);
    fn _core_turing_mesh__name_get(handle: TuringMesh) -> u32;
    fn _core_turing_mesh__name_set(handle: TuringMesh, value: *const c_char);
    fn _core_turing_mesh__optimize(handle: TuringMesh);
    fn _core_turing_mesh__optimize_index_buffers(handle: TuringMesh);
    fn _core_turing_mesh__recalculate_bounds(handle: TuringMesh);
    fn _core_turing_mesh__recalculate_normals(handle: TuringMesh);
    fn _core_turing_mesh__recalculate_tangents(handle: TuringMesh);
    fn _core_turing_mesh__set_bounds(handle: TuringMesh, min_x: f32, min_y: f32, min_z: f32, max_x: f32, max_y: f32, max_z: f32);
    fn _core_turing_mesh__set_triangles(handle: TuringMesh, triangles: Int32, submesh: i32, calculate_bounds: bool, base_vertex: i32);
    fn _core_turing_mesh__set_u_vs(handle: TuringMesh, channel: i32, uvs: *const c_void);
    fn _core_turing_mesh__set_vertices(handle: TuringMesh, in_vertices: *const c_void);
    fn _core_turing_mesh__upload_mesh_data(handle: TuringMesh, mark_no_longer_readable: bool);
    fn _core_turing_note_extensions__get_note_floor_movement(note_controller: NoteController) -> NoteFloorMovement;
    fn _core_turing_note_extensions__get_note_jump(note_controller: NoteController) -> NoteJump;
    fn _core_turinger_game_object_manager__create_object(name: *const c_char) -> GameObject;
    fn _core_turinger_game_object_manager__destroy_object(game_object: GameObject);
    fn _core_turinger_game_object_manager__find(name: *const c_char) -> GameObject;
    fn _core_turinger_game_object_manager__instance_get(handle: TuringerGameObjectManager) -> TuringerGameObjectManager;
    fn _core_xr__get_device_battery_level(node_int: i32) -> f32;
    fn _core_xr__get_device_grip_value(node_int: i32) -> f32;
    fn _core_xr__get_device_name(node_int: i32) -> u32;
    fn _core_xr__get_device_primary_button_state(node_int: i32) -> bool;
    fn _core_xr__get_device_secondary_button_state(node_int: i32) -> bool;
    fn _core_xr__get_device_thumbstick(node_int: i32) -> u32;
    fn _core_xr__get_device_touchpad(node_int: i32) -> u32;
    fn _core_xr__get_device_tracking_state(node_int: i32) -> i32;
    fn _core_xr__get_device_trigger_value(node_int: i32) -> f32;
    fn _core_xr__is_device_valid(node_int: i32) -> bool;
    fn _core_xr__send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32);
    fn _core_xr__stop_haptics(node_int: i32);
    fn _core_xr___manager_get(handle: Xr) -> TuringScriptManager;

}

#[unsafe(no_mangle)]
/// For internal use only.
/// Provides the host with the api version
extern "C" fn _core_semver() -> u64 {
    (0u64 << 32) | (1u64 << 16) | 0u64
}

pub static CORE_VERSION: &'static str = "0.1.0";


//// Functions ////


//// Classes ////
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct Action {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct Action1 {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct BeatmapDataItem {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct Component {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct CustomData {
    handle: u64,
}
impl CustomData {


    pub fn create() -> CustomData {
        unsafe { _core_custom_data__create() }
    }

    pub fn from_json(json: &str) -> CustomData {
        let turing_handle = CString::new(json).unwrap();
        let json = turing_handle.as_ptr();
        unsafe { _core_custom_data__from_json(json) }
    }

    pub fn list_add_bool(list: List1, value: bool) {
        unsafe { _core_custom_data__list_add_bool(list, value) };
    }

    pub fn list_add_custom_data(list: List1, value: CustomData) {
        unsafe { _core_custom_data__list_add_custom_data(list, value) };
    }

    pub fn list_add_custom_data_list(list: List1, value: List1) {
        unsafe { _core_custom_data__list_add_custom_data_list(list, value) };
    }

    pub fn list_add_float(list: List1, value: f32) {
        unsafe { _core_custom_data__list_add_float(list, value) };
    }

    pub fn list_add_int(list: List1, value: i32) {
        unsafe { _core_custom_data__list_add_int(list, value) };
    }

    pub fn list_add_string(list: List1, value: &str) {
        let turing_handle = CString::new(value).unwrap();
        let value = turing_handle.as_ptr();
        unsafe { _core_custom_data__list_add_string(list, value) };
    }

    pub fn set_bool(custom_data: CustomData, key: &str, value: bool) {
        let turing_handle = CString::new(key).unwrap();
        let key = turing_handle.as_ptr();
        unsafe { _core_custom_data__set_bool(custom_data, key, value) };
    }

    pub fn set_custom_data(custom_data: CustomData, key: &str, value: CustomData) {
        let turing_handle = CString::new(key).unwrap();
        let key = turing_handle.as_ptr();
        unsafe { _core_custom_data__set_custom_data(custom_data, key, value) };
    }

    pub fn set_custom_data_list(custom_data: CustomData, key: &str, value: List1) {
        let turing_handle = CString::new(key).unwrap();
        let key = turing_handle.as_ptr();
        unsafe { _core_custom_data__set_custom_data_list(custom_data, key, value) };
    }

    pub fn set_float(custom_data: CustomData, key: &str, value: f32) {
        let turing_handle = CString::new(key).unwrap();
        let key = turing_handle.as_ptr();
        unsafe { _core_custom_data__set_float(custom_data, key, value) };
    }

    pub fn set_int(custom_data: CustomData, key: &str, value: i32) {
        let turing_handle = CString::new(key).unwrap();
        let key = turing_handle.as_ptr();
        unsafe { _core_custom_data__set_int(custom_data, key, value) };
    }

    pub fn set_string(custom_data: CustomData, key: &str, value: &str) {
        let turing_handle = CString::new(key).unwrap();
        let key = turing_handle.as_ptr();
        let turing_handle = CString::new(value).unwrap();
        let value = turing_handle.as_ptr();
        unsafe { _core_custom_data__set_string(custom_data, key, value) };
    }

    pub fn to_json(custom_data: CustomData, pretty: bool) -> String {
        let turing_result = unsafe { _core_custom_data__to_json(custom_data, pretty) };
        let mut turing_str = vec![0u8; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }
    
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct CustomEventData {
    handle: u64,
}
impl CustomEventData {

    

    pub fn custom_data_get(&self) -> CustomData {
        unsafe { _core_custom_event_data__custom_data_get(*self) }
    }

    pub fn event_type_get(&self) -> String {
        let turing_result = unsafe { _core_custom_event_data__event_type_get(*self) };
        let mut turing_str = vec![0u8; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn get_copy(&self) -> BeatmapDataItem {
        unsafe { _core_custom_event_data__get_copy(*self) }
    }

    pub fn version_get(&self) -> Version {
        unsafe { _core_custom_event_data__version_get(*self) }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct CustomNoteData {
    handle: u64,
}
impl CustomNoteData {


    pub fn create_custom_basic_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) -> CustomNoteData {
        unsafe { _core_custom_note_data__create_custom_basic_note_data(time, beat, rotation, line_index) }
    }

    pub fn create_custom_bomb_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) -> CustomNoteData {
        unsafe { _core_custom_note_data__create_custom_bomb_note_data(time, beat, rotation, line_index) }
    }

    pub fn create_custom_burst_slider_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) -> CustomNoteData {
        unsafe { _core_custom_note_data__create_custom_burst_slider_note_data(time, beat, rotation, line_index) }
    }
    

    pub fn custom_data_get(&self) -> CustomData {
        unsafe { _core_custom_note_data__custom_data_get(*self) }
    }

    pub fn get_copy(&self) -> BeatmapDataItem {
        unsafe { _core_custom_note_data__get_copy(*self) }
    }

    pub fn version_get(&self) -> Version {
        unsafe { _core_custom_note_data__version_get(*self) }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct CustomObstacleData {
    handle: u64,
}
impl CustomObstacleData {

    

    pub fn custom_data_get(&self) -> CustomData {
        unsafe { _core_custom_obstacle_data__custom_data_get(*self) }
    }

    pub fn get_copy(&self) -> BeatmapDataItem {
        unsafe { _core_custom_obstacle_data__get_copy(*self) }
    }

    pub fn version_get(&self) -> Version {
        unsafe { _core_custom_obstacle_data__version_get(*self) }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct GcHelper {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct GameObject {
    handle: u64,
}
impl GameObject {

    

    pub fn add_component(&self, component_type: Type) -> Component {
        unsafe { _core_game_object__add_component(*self, component_type) }
    }

    pub fn add_or_get_mesh(&self) -> TuringMesh {
        unsafe { _core_game_object__add_or_get_mesh(*self) }
    }

    pub fn broadcast_message(&self, method_name: &str, options: i32) {
        let turing_handle = CString::new(method_name).unwrap();
        let method_name = turing_handle.as_ptr();
        unsafe { _core_game_object__broadcast_message(*self, method_name, options) };
    }

    pub fn compare_tag(&self, tag: &str) -> bool {
        let turing_handle = CString::new(tag).unwrap();
        let tag = turing_handle.as_ptr();
        unsafe { _core_game_object__compare_tag(*self, tag) }
    }

    pub fn get_active(&self) -> bool {
        unsafe { _core_game_object__get_active(*self) }
    }

    pub fn get_active_in_hierarchy(&self) -> bool {
        unsafe { _core_game_object__get_active_in_hierarchy(*self) }
    }

    pub fn get_active_self(&self) -> bool {
        unsafe { _core_game_object__get_active_self(*self) }
    }

    pub fn get_component_at_index(&self, index: i32) -> Component {
        unsafe { _core_game_object__get_component_at_index(*self, index) }
    }

    pub fn get_component_by_name(&self, cs_type: &str) -> Component {
        let turing_handle = CString::new(cs_type).unwrap();
        let cs_type = turing_handle.as_ptr();
        unsafe { _core_game_object__get_component_by_name(*self, cs_type) }
    }

    pub fn get_component_by_type(&self, cs_type: Type) -> Component {
        unsafe { _core_game_object__get_component_by_type(*self, cs_type) }
    }

    pub fn get_component_count(&self) -> i32 {
        unsafe { _core_game_object__get_component_count(*self) }
    }

    pub fn get_component_in_children_by_type(&self, cs_type: Type, include_inactive: bool) -> Component {
        unsafe { _core_game_object__get_component_in_children_by_type(*self, cs_type, include_inactive) }
    }

    pub fn get_component_in_parent_by_type(&self, cs_type: Type, include_inactive: bool) -> Component {
        unsafe { _core_game_object__get_component_in_parent_by_type(*self, cs_type, include_inactive) }
    }

    pub fn get_component_index(&self, component: Component) -> i32 {
        unsafe { _core_game_object__get_component_index(*self, component) }
    }

    pub fn get_hide_flags(&self) -> i32 {
        unsafe { _core_game_object__get_hide_flags(*self) }
    }

    pub fn get_instance_id(&self) -> i32 {
        unsafe { _core_game_object__get_instance_id(*self) }
    }

    pub fn get_is_static(&self) -> bool {
        unsafe { _core_game_object__get_is_static(*self) }
    }

    pub fn get_layer(&self) -> i32 {
        unsafe { _core_game_object__get_layer(*self) }
    }

    pub fn get_name(&self) -> String {
        let turing_result = unsafe { _core_game_object__get_name(*self) };
        let mut turing_str = vec![0u8; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn get_scene_culling_mask(&self) -> u64 {
        unsafe { _core_game_object__get_scene_culling_mask(*self) }
    }

    pub fn get_tag(&self) -> String {
        let turing_result = unsafe { _core_game_object__get_tag(*self) };
        let mut turing_str = vec![0u8; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn get_transform(&self) -> Transform {
        unsafe { _core_game_object__get_transform(*self) }
    }

    pub fn send_message(&self, method_name: &str, options: i32) {
        let turing_handle = CString::new(method_name).unwrap();
        let method_name = turing_handle.as_ptr();
        unsafe { _core_game_object__send_message(*self, method_name, options) };
    }

    pub fn send_message_upwards(&self, method_name: &str, options: i32) {
        let turing_handle = CString::new(method_name).unwrap();
        let method_name = turing_handle.as_ptr();
        unsafe { _core_game_object__send_message_upwards(*self, method_name, options) };
    }

    pub fn set_active(&self, value: bool) {
        unsafe { _core_game_object__set_active(*self, value) };
    }

    pub fn set_active_prop(&self, value: bool) {
        unsafe { _core_game_object__set_active_prop(*self, value) };
    }

    pub fn set_active_recursively(&self, state: bool) {
        unsafe { _core_game_object__set_active_recursively(*self, state) };
    }

    pub fn set_hide_flags(&self, value: i32) {
        unsafe { _core_game_object__set_hide_flags(*self, value) };
    }

    pub fn set_is_static(&self, value: bool) {
        unsafe { _core_game_object__set_is_static(*self, value) };
    }

    pub fn set_layer(&self, value: i32) {
        unsafe { _core_game_object__set_layer(*self, value) };
    }

    pub fn set_name(&self, value: &str) {
        let turing_handle = CString::new(value).unwrap();
        let value = turing_handle.as_ptr();
        unsafe { _core_game_object__set_name(*self, value) };
    }

    pub fn set_tag(&self, value: &str) {
        let turing_handle = CString::new(value).unwrap();
        let value = turing_handle.as_ptr();
        unsafe { _core_game_object__set_tag(*self, value) };
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct GcHelper {
    handle: u64,
}
impl GcHelper {


    pub fn create() -> GCHelper {
        unsafe { _core_gc_helper__create() }
    }
    

    pub fn dispose(&self) {
        unsafe { _core_gc_helper__dispose(*self) };
    }

    pub fn invalidate_all_handles(&self) {
        unsafe { _core_gc_helper__invalidate_all_handles(*self) };
    }

    pub fn wasm_garbage_collect(&self) {
        unsafe { _core_gc_helper__wasm_garbage_collect(*self) };
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct IAudioTimeSource {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct IEnumerator {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct IVariableMovementDataProvider {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct Int32 {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct List1 {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct Log;
impl Log {


    pub fn critical(msg: &str) {
        let turing_handle = CString::new(msg).unwrap();
        let msg = turing_handle.as_ptr();
        unsafe { _core_log__critical(msg) };
    }

    pub fn debug(msg: &str) {
        let turing_handle = CString::new(msg).unwrap();
        let msg = turing_handle.as_ptr();
        unsafe { _core_log__debug(msg) };
    }

    pub fn info(msg: &str) {
        let turing_handle = CString::new(msg).unwrap();
        let msg = turing_handle.as_ptr();
        unsafe { _core_log__info(msg) };
    }

    pub fn warn(msg: &str) {
        let turing_handle = CString::new(msg).unwrap();
        let msg = turing_handle.as_ptr();
        unsafe { _core_log__warn(msg) };
    }
    
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct Mesh {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct NoteController {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct NoteControllerBase {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct NoteFloorMovement {
    handle: u64,
}
impl NoteFloorMovement {

    

    pub fn _audio_time_sync_controller_get(&self) -> IAudioTimeSource {
        unsafe { _core_note_floor_movement___audio_time_sync_controller_get(*self) }
    }

    pub fn _beat_time_get(&self) -> f32 {
        unsafe { _core_note_floor_movement___beat_time_get(*self) }
    }

    pub fn _beat_time_set(&self, value: f32) {
        unsafe { _core_note_floor_movement___beat_time_set(*self, value) };
    }

    pub fn _inverse_world_rotation_get(&self) -> alg::Quat {
        unsafe { _core_note_floor_movement___inverse_world_rotation_get(*self) };
        alg::dequeue_quat()
    }

    pub fn _inverse_world_rotation_set(&self, value: alg::Quat) {
         let value = alg::enqueue_quat(value);
        unsafe { _core_note_floor_movement___inverse_world_rotation_set(*self, value) };
    }

    pub fn _local_position_get(&self) -> alg::Vec3 {
        unsafe { _core_note_floor_movement___local_position_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn _local_position_set(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_note_floor_movement___local_position_set(*self, value) };
    }

    pub fn _move_end_offset_get(&self) -> alg::Vec3 {
        unsafe { _core_note_floor_movement___move_end_offset_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn _move_end_offset_set(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_note_floor_movement___move_end_offset_set(*self, value) };
    }

    pub fn _move_start_offset_get(&self) -> alg::Vec3 {
        unsafe { _core_note_floor_movement___move_start_offset_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn _move_start_offset_set(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_note_floor_movement___move_start_offset_set(*self, value) };
    }

    pub fn _player_transforms_get(&self) -> PlayerTransforms {
        unsafe { _core_note_floor_movement___player_transforms_get(*self) }
    }

    pub fn _rotated_object_get(&self) -> Transform {
        unsafe { _core_note_floor_movement___rotated_object_get(*self) }
    }

    pub fn _rotated_object_set(&self, value: Transform) {
        unsafe { _core_note_floor_movement___rotated_object_set(*self, value) };
    }

    pub fn _variable_movement_data_provider_get(&self) -> IVariableMovementDataProvider {
        unsafe { _core_note_floor_movement___variable_movement_data_provider_get(*self) }
    }

    pub fn _world_rotation_get(&self) -> alg::Quat {
        unsafe { _core_note_floor_movement___world_rotation_get(*self) };
        alg::dequeue_quat()
    }

    pub fn _world_rotation_set(&self, value: alg::Quat) {
         let value = alg::enqueue_quat(value);
        unsafe { _core_note_floor_movement___world_rotation_set(*self, value) };
    }

    pub fn distance_to_player_get(&self) -> f32 {
        unsafe { _core_note_floor_movement__distance_to_player_get(*self) }
    }

    pub fn end_pos_get(&self) -> alg::Vec3 {
        unsafe { _core_note_floor_movement__end_pos_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn init_floor(&self, world_rotation: f32, beat_time: f32, move_start_offset: alg::Vec3, move_end_offset: alg::Vec3) {
         let move_start_offset = alg::enqueue_vec3(move_start_offset);
         let move_end_offset = alg::enqueue_vec3(move_end_offset);
        unsafe { _core_note_floor_movement__init(*self, world_rotation, beat_time, move_start_offset, move_end_offset) };
    }

    pub fn inverse_world_rotation_get(&self) -> alg::Quat {
        unsafe { _core_note_floor_movement__inverse_world_rotation_get(*self) };
        alg::dequeue_quat()
    }

    pub fn local_position_get(&self) -> alg::Vec3 {
        unsafe { _core_note_floor_movement__local_position_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn manual_update(&self) -> alg::Vec3 {
        unsafe { _core_note_floor_movement__manual_update(*self) };
        alg::dequeue_vec3()
    }

    pub fn note_time_get(&self) -> f32 {
        unsafe { _core_note_floor_movement__note_time_get(*self) }
    }

    pub fn set_to_start(&self) -> alg::Vec3 {
        unsafe { _core_note_floor_movement__set_to_start(*self) };
        alg::dequeue_vec3()
    }

    pub fn should_move(&self) -> bool {
        unsafe { _core_note_floor_movement__should_move(*self) }
    }

    pub fn world_rotation_get(&self) -> alg::Quat {
        unsafe { _core_note_floor_movement__world_rotation_get(*self) };
        alg::dequeue_quat()
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct NoteJump {
    handle: u64,
}
impl NoteJump {


    pub fn k_missed_time_offset_get() -> f32 {
        unsafe { _core_note_jump__k_missed_time_offset_get() }
    }
    

    pub fn _audio_time_sync_controller_get(&self) -> IAudioTimeSource {
        unsafe { _core_note_jump___audio_time_sync_controller_get(*self) }
    }

    pub fn _end_distance_offset_get(&self) -> f32 {
        unsafe { _core_note_jump___end_distance_offset_get(*self) }
    }

    pub fn _end_distance_offset_set(&self, value: f32) {
        unsafe { _core_note_jump___end_distance_offset_set(*self, value) };
    }

    pub fn _end_offset_get(&self) -> alg::Vec3 {
        unsafe { _core_note_jump___end_offset_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn _end_offset_set(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_note_jump___end_offset_set(*self, value) };
    }

    pub fn _end_pos_get(&self) -> alg::Vec3 {
        unsafe { _core_note_jump___end_pos_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn _end_pos_set(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_note_jump___end_pos_set(*self, value) };
    }

    pub fn _end_rotation_get(&self) -> alg::Quat {
        unsafe { _core_note_jump___end_rotation_get(*self) };
        alg::dequeue_quat()
    }

    pub fn _end_rotation_set(&self, value: alg::Quat) {
         let value = alg::enqueue_quat(value);
        unsafe { _core_note_jump___end_rotation_set(*self, value) };
    }

    pub fn _gravity_base_get(&self) -> f32 {
        unsafe { _core_note_jump___gravity_base_get(*self) }
    }

    pub fn _gravity_base_set(&self, value: f32) {
        unsafe { _core_note_jump___gravity_base_set(*self, value) };
    }

    pub fn _gravity_get(&self) -> f32 {
        unsafe { _core_note_jump___gravity_get(*self) }
    }

    pub fn _gravity_set(&self, value: f32) {
        unsafe { _core_note_jump___gravity_set(*self, value) };
    }

    pub fn _half_jump_duration_get(&self) -> f32 {
        unsafe { _core_note_jump___half_jump_duration_get(*self) }
    }

    pub fn _half_jump_duration_set(&self, value: f32) {
        unsafe { _core_note_jump___half_jump_duration_set(*self, value) };
    }

    pub fn _half_jump_mark_reported_get(&self) -> bool {
        unsafe { _core_note_jump___half_jump_mark_reported_get(*self) }
    }

    pub fn _half_jump_mark_reported_set(&self, value: bool) {
        unsafe { _core_note_jump___half_jump_mark_reported_set(*self, value) };
    }

    pub fn _inverse_world_rotation_get(&self) -> alg::Quat {
        unsafe { _core_note_jump___inverse_world_rotation_get(*self) };
        alg::dequeue_quat()
    }

    pub fn _inverse_world_rotation_set(&self, value: alg::Quat) {
         let value = alg::enqueue_quat(value);
        unsafe { _core_note_jump___inverse_world_rotation_set(*self, value) };
    }

    pub fn _jump_duration_get(&self) -> f32 {
        unsafe { _core_note_jump___jump_duration_get(*self) }
    }

    pub fn _jump_duration_set(&self, value: f32) {
        unsafe { _core_note_jump___jump_duration_set(*self, value) };
    }

    pub fn _jump_started_reported_get(&self) -> bool {
        unsafe { _core_note_jump___jump_started_reported_get(*self) }
    }

    pub fn _jump_started_reported_set(&self, value: bool) {
        unsafe { _core_note_jump___jump_started_reported_set(*self, value) };
    }

    pub fn _local_position_get(&self) -> alg::Vec3 {
        unsafe { _core_note_jump___local_position_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn _local_position_set(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_note_jump___local_position_set(*self, value) };
    }

    pub fn _middle_rotation_get(&self) -> alg::Quat {
        unsafe { _core_note_jump___middle_rotation_get(*self) };
        alg::dequeue_quat()
    }

    pub fn _middle_rotation_set(&self, value: alg::Quat) {
         let value = alg::enqueue_quat(value);
        unsafe { _core_note_jump___middle_rotation_set(*self, value) };
    }

    pub fn _missed_mark_reported_get(&self) -> bool {
        unsafe { _core_note_jump___missed_mark_reported_get(*self) }
    }

    pub fn _missed_mark_reported_set(&self, value: bool) {
        unsafe { _core_note_jump___missed_mark_reported_set(*self, value) };
    }

    pub fn _missed_time_get(&self) -> f32 {
        unsafe { _core_note_jump___missed_time_get(*self) }
    }

    pub fn _missed_time_set(&self, value: f32) {
        unsafe { _core_note_jump___missed_time_set(*self, value) };
    }

    pub fn _note_time_get(&self) -> f32 {
        unsafe { _core_note_jump___note_time_get(*self) }
    }

    pub fn _note_time_set(&self, value: f32) {
        unsafe { _core_note_jump___note_time_set(*self, value) };
    }

    pub fn _player_space_convertor_get(&self) -> PlayerSpaceConvertor {
        unsafe { _core_note_jump___player_space_convertor_get(*self) }
    }

    pub fn _player_transforms_get(&self) -> PlayerTransforms {
        unsafe { _core_note_jump___player_transforms_get(*self) }
    }

    pub fn _rotate_towards_player_get(&self) -> bool {
        unsafe { _core_note_jump___rotate_towards_player_get(*self) }
    }

    pub fn _rotate_towards_player_set(&self, value: bool) {
        unsafe { _core_note_jump___rotate_towards_player_set(*self, value) };
    }

    pub fn _rotated_object_get(&self) -> Transform {
        unsafe { _core_note_jump___rotated_object_get(*self) }
    }

    pub fn _rotated_object_set(&self, value: Transform) {
        unsafe { _core_note_jump___rotated_object_set(*self, value) };
    }

    pub fn _start_offset_get(&self) -> alg::Vec3 {
        unsafe { _core_note_jump___start_offset_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn _start_offset_set(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_note_jump___start_offset_set(*self, value) };
    }

    pub fn _start_pos_get(&self) -> alg::Vec3 {
        unsafe { _core_note_jump___start_pos_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn _start_pos_set(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_note_jump___start_pos_set(*self, value) };
    }

    pub fn _start_rotation_get(&self) -> alg::Quat {
        unsafe { _core_note_jump___start_rotation_get(*self) };
        alg::dequeue_quat()
    }

    pub fn _start_rotation_set(&self, value: alg::Quat) {
         let value = alg::enqueue_quat(value);
        unsafe { _core_note_jump___start_rotation_set(*self, value) };
    }

    pub fn _three_quarters_mark_reported_get(&self) -> bool {
        unsafe { _core_note_jump___three_quarters_mark_reported_get(*self) }
    }

    pub fn _three_quarters_mark_reported_set(&self, value: bool) {
        unsafe { _core_note_jump___three_quarters_mark_reported_set(*self, value) };
    }

    pub fn _variable_movement_data_provider_get(&self) -> IVariableMovementDataProvider {
        unsafe { _core_note_jump___variable_movement_data_provider_get(*self) }
    }

    pub fn _world_rotation_get(&self) -> alg::Quat {
        unsafe { _core_note_jump___world_rotation_get(*self) };
        alg::dequeue_quat()
    }

    pub fn _world_rotation_set(&self, value: alg::Quat) {
         let value = alg::enqueue_quat(value);
        unsafe { _core_note_jump___world_rotation_set(*self, value) };
    }

    pub fn _y_avoidance_down_get(&self) -> f32 {
        unsafe { _core_note_jump___y_avoidance_down_get(*self) }
    }

    pub fn _y_avoidance_down_set(&self, value: f32) {
        unsafe { _core_note_jump___y_avoidance_down_set(*self, value) };
    }

    pub fn _y_avoidance_get(&self) -> f32 {
        unsafe { _core_note_jump___y_avoidance_get(*self) }
    }

    pub fn _y_avoidance_set(&self, value: f32) {
        unsafe { _core_note_jump___y_avoidance_set(*self, value) };
    }

    pub fn _y_avoidance_up_get(&self) -> f32 {
        unsafe { _core_note_jump___y_avoidance_up_get(*self) }
    }

    pub fn _y_avoidance_up_set(&self, value: f32) {
        unsafe { _core_note_jump___y_avoidance_up_set(*self, value) };
    }

    pub fn add_note_jump_did_finish_event(&self, value: Action) {
        unsafe { _core_note_jump__add_note_jump_did_finish_event(*self, value) };
    }

    pub fn add_note_jump_did_pass_half_event(&self, value: Action) {
        unsafe { _core_note_jump__add_note_jump_did_pass_half_event(*self, value) };
    }

    pub fn add_note_jump_did_pass_missed_marker_event(&self, value: Action) {
        unsafe { _core_note_jump__add_note_jump_did_pass_missed_marker_event(*self, value) };
    }

    pub fn add_note_jump_did_pass_three_quarters_event(&self, value: Action1) {
        unsafe { _core_note_jump__add_note_jump_did_pass_three_quarters_event(*self, value) };
    }

    pub fn add_note_jump_did_start_event(&self, value: Action) {
        unsafe { _core_note_jump__add_note_jump_did_start_event(*self, value) };
    }

    pub fn add_note_jump_did_update_progress_event(&self, value: Action1) {
        unsafe { _core_note_jump__add_note_jump_did_update_progress_event(*self, value) };
    }

    pub fn beat_pos_get(&self) -> alg::Vec3 {
        unsafe { _core_note_jump__beat_pos_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn distance_to_player_get(&self) -> f32 {
        unsafe { _core_note_jump__distance_to_player_get(*self) }
    }

    pub fn init_jump(&self, note_time: f32, world_rotation: f32, move_end_offset: alg::Vec3, jump_end_offset: alg::Vec3, gravity_base: f32, flip_y_side: f32, end_rotation: f32, rotate_towards_player: bool, use_random_rotation: bool) {
         let move_end_offset = alg::enqueue_vec3(move_end_offset);
         let jump_end_offset = alg::enqueue_vec3(jump_end_offset);
        unsafe { _core_note_jump__init(*self, note_time, world_rotation, move_end_offset, jump_end_offset, gravity_base, flip_y_side, end_rotation, rotate_towards_player, use_random_rotation) };
    }

    pub fn local_position_get(&self) -> alg::Vec3 {
        unsafe { _core_note_jump__local_position_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn manual_update(&self) -> alg::Vec3 {
        unsafe { _core_note_jump__manual_update(*self) };
        alg::dequeue_vec3()
    }

    pub fn move_vec_get(&self) -> alg::Vec3 {
        unsafe { _core_note_jump__move_vec_get(*self) };
        alg::dequeue_vec3()
    }

    pub fn note_time_get(&self) -> f32 {
        unsafe { _core_note_jump__note_time_get(*self) }
    }

    pub fn remove_note_jump_did_finish_event(&self, value: Action) {
        unsafe { _core_note_jump__remove_note_jump_did_finish_event(*self, value) };
    }

    pub fn remove_note_jump_did_pass_half_event(&self, value: Action) {
        unsafe { _core_note_jump__remove_note_jump_did_pass_half_event(*self, value) };
    }

    pub fn remove_note_jump_did_pass_missed_marker_event(&self, value: Action) {
        unsafe { _core_note_jump__remove_note_jump_did_pass_missed_marker_event(*self, value) };
    }

    pub fn remove_note_jump_did_pass_three_quarters_event(&self, value: Action1) {
        unsafe { _core_note_jump__remove_note_jump_did_pass_three_quarters_event(*self, value) };
    }

    pub fn remove_note_jump_did_start_event(&self, value: Action) {
        unsafe { _core_note_jump__remove_note_jump_did_start_event(*self, value) };
    }

    pub fn remove_note_jump_did_update_progress_event(&self, value: Action1) {
        unsafe { _core_note_jump__remove_note_jump_did_update_progress_event(*self, value) };
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct NoteManager;
impl NoteManager {


    pub fn add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: CustomData) -> CustomNoteData {
        unsafe { _core_note_manager__add_bomb_note(beat, line, layer, custom_data) }
    }

    pub fn add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: CustomData) -> CustomNoteData {
        unsafe { _core_note_manager__add_color_note(beat, line, layer, color, cut_direction, custom_data) }
    }

    pub fn add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: CustomData) -> CustomObstacleData {
        unsafe { _core_note_manager__add_obstacle(beat, duration, line, layer, width, height, custom_data) }
    }

    pub fn get_note_controller(n: i32) -> NoteControllerBase {
        unsafe { _core_note_manager__get_note_controller(n) }
    }

    pub fn get_note_controller_from_custom(n: CustomNoteData) -> NoteControllerBase {
        unsafe { _core_note_manager__get_note_controller_from_custom(n) }
    }

    pub fn get_nth_event(id: i32) -> CustomEventData {
        unsafe { _core_note_manager__get_nth_event(id) }
    }

    pub fn get_nth_note(id: i32) -> CustomNoteData {
        unsafe { _core_note_manager__get_nth_note(id) }
    }

    pub fn get_nth_object(id: i32) -> BeatmapDataItem {
        unsafe { _core_note_manager__get_nth_object(id) }
    }

    pub fn get_nth_obstacle(id: i32) -> CustomObstacleData {
        unsafe { _core_note_manager__get_nth_obstacle(id) }
    }

    pub fn get_obstacle_controller(n: i32) -> ObstacleControllerBase {
        unsafe { _core_note_manager__get_obstacle_controller(n) }
    }

    pub fn get_obstacle_controller_from_custom(n: CustomObstacleData) -> ObstacleController {
        unsafe { _core_note_manager__get_obstacle_controller_from_custom(n) }
    }

    pub fn time_to_beat(time: f32) -> f32 {
        unsafe { _core_note_manager__time_to_beat(time) }
    }
    
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct Object {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct ObstacleController {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct ObstacleControllerBase {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct PlayerSpaceConvertor {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct PlayerTransforms {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct TaskScheduler {
    handle: u64,
}
impl TaskScheduler {


    pub fn schedule(task: Action) {
        unsafe { _core_task_scheduler__schedule(task) };
    }
    

    pub fn dispose(&self) {
        unsafe { _core_task_scheduler__dispose(*self) };
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct Transform {
    handle: u64,
}
impl Transform {

    

    pub fn broadcast_message(&self, method_name: &str, parameter: Object, options: i32) {
        let turing_handle = CString::new(method_name).unwrap();
        let method_name = turing_handle.as_ptr();
        unsafe { _core_transform__broadcast_message(*self, method_name, parameter, options) };
    }

    pub fn compare_tag(&self, tag: &str) -> bool {
        let turing_handle = CString::new(tag).unwrap();
        let tag = turing_handle.as_ptr();
        unsafe { _core_transform__compare_tag(*self, tag) }
    }

    pub fn detach_children(&self) {
        unsafe { _core_transform__detach_children(*self) };
    }

    pub fn find(&self, n: &str) -> Transform {
        let turing_handle = CString::new(n).unwrap();
        let n = turing_handle.as_ptr();
        unsafe { _core_transform__find(*self, n) }
    }

    pub fn find_child(&self, n: &str) -> Transform {
        let turing_handle = CString::new(n).unwrap();
        let n = turing_handle.as_ptr();
        unsafe { _core_transform__find_child(*self, n) }
    }

    pub fn get_child(&self, index: i32) -> Transform {
        unsafe { _core_transform__get_child(*self, index) }
    }

    pub fn get_child_count(&self) -> i32 {
        unsafe { _core_transform__get_child_count(*self) }
    }

    pub fn get_child_count_prop(&self) -> i32 {
        unsafe { _core_transform__get_child_count_prop(*self) }
    }

    pub fn get_component_by_name(&self, cs_type: &str) -> Component {
        let turing_handle = CString::new(cs_type).unwrap();
        let cs_type = turing_handle.as_ptr();
        unsafe { _core_transform__get_component_by_name(*self, cs_type) }
    }

    pub fn get_component_by_type(&self, cs_type: Type) -> Component {
        unsafe { _core_transform__get_component_by_type(*self, cs_type) }
    }

    pub fn get_component_in_children_by_type(&self, t: Type, include_inactive: bool) -> Component {
        unsafe { _core_transform__get_component_in_children_by_type(*self, t, include_inactive) }
    }

    pub fn get_component_in_parent_by_type(&self, t: Type, include_inactive: bool) -> Component {
        unsafe { _core_transform__get_component_in_parent_by_type(*self, t, include_inactive) }
    }

    pub fn get_component_index(&self) -> i32 {
        unsafe { _core_transform__get_component_index(*self) }
    }

    pub fn get_enumerator(&self) -> IEnumerator {
        unsafe { _core_transform__get_enumerator(*self) }
    }

    pub fn get_euler_angles(&self) -> alg::Vec3 {
        unsafe { _core_transform__get_euler_angles(*self) };
        alg::dequeue_vec3()
    }

    pub fn get_forward(&self) -> alg::Vec3 {
        unsafe { _core_transform__get_forward(*self) };
        alg::dequeue_vec3()
    }

    pub fn get_game_object(&self) -> GameObject {
        unsafe { _core_transform__get_game_object(*self) }
    }

    pub fn get_has_changed(&self) -> bool {
        unsafe { _core_transform__get_has_changed(*self) }
    }

    pub fn get_hide_flags(&self) -> i32 {
        unsafe { _core_transform__get_hide_flags(*self) }
    }

    pub fn get_hierarchy_capacity(&self) -> i32 {
        unsafe { _core_transform__get_hierarchy_capacity(*self) }
    }

    pub fn get_hierarchy_count(&self) -> i32 {
        unsafe { _core_transform__get_hierarchy_count(*self) }
    }

    pub fn get_instance_id(&self) -> i32 {
        unsafe { _core_transform__get_instance_id(*self) }
    }

    pub fn get_local_euler_angles(&self) -> alg::Vec3 {
        unsafe { _core_transform__get_local_euler_angles(*self) };
        alg::dequeue_vec3()
    }

    pub fn get_local_position(&self) -> alg::Vec3 {
        unsafe { _core_transform__get_local_position(*self) };
        alg::dequeue_vec3()
    }

    pub fn get_local_rotation(&self) -> alg::Quat {
        unsafe { _core_transform__get_local_rotation(*self) };
        alg::dequeue_quat()
    }

    pub fn get_local_scale(&self) -> alg::Vec3 {
        unsafe { _core_transform__get_local_scale(*self) };
        alg::dequeue_vec3()
    }

    pub fn get_local_to_world_matrix(&self) -> alg::Mat4 {
        unsafe { _core_transform__get_local_to_world_matrix(*self) };
        alg::dequeue_mat4()
    }

    pub fn get_lossy_scale(&self) -> alg::Vec3 {
        unsafe { _core_transform__get_lossy_scale(*self) };
        alg::dequeue_vec3()
    }

    pub fn get_name(&self) -> String {
        let turing_result = unsafe { _core_transform__get_name(*self) };
        let mut turing_str = vec![0u8; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn get_parent(&self) -> Transform {
        unsafe { _core_transform__get_parent(*self) }
    }

    pub fn get_position(&self) -> alg::Vec3 {
        unsafe { _core_transform__get_position(*self) };
        alg::dequeue_vec3()
    }

    pub fn get_right(&self) -> alg::Vec3 {
        unsafe { _core_transform__get_right(*self) };
        alg::dequeue_vec3()
    }

    pub fn get_root(&self) -> Transform {
        unsafe { _core_transform__get_root(*self) }
    }

    pub fn get_rotation(&self) -> alg::Quat {
        unsafe { _core_transform__get_rotation(*self) };
        alg::dequeue_quat()
    }

    pub fn get_sibling_index(&self) -> i32 {
        unsafe { _core_transform__get_sibling_index(*self) }
    }

    pub fn get_tag(&self) -> String {
        let turing_result = unsafe { _core_transform__get_tag(*self) };
        let mut turing_str = vec![0u8; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn get_up(&self) -> alg::Vec3 {
        unsafe { _core_transform__get_up(*self) };
        alg::dequeue_vec3()
    }

    pub fn get_world_to_local_matrix(&self) -> alg::Mat4 {
        unsafe { _core_transform__get_world_to_local_matrix(*self) };
        alg::dequeue_mat4()
    }

    pub fn inverse_transform_direction(&self, direction: alg::Vec3) -> alg::Vec3 {
         let direction = alg::enqueue_vec3(direction);
        unsafe { _core_transform__inverse_transform_direction(*self, direction) };
        alg::dequeue_vec3()
    }

    pub fn inverse_transform_point(&self, position: alg::Vec3) -> alg::Vec3 {
         let position = alg::enqueue_vec3(position);
        unsafe { _core_transform__inverse_transform_point(*self, position) };
        alg::dequeue_vec3()
    }

    pub fn inverse_transform_vector(&self, vector: alg::Vec3) -> alg::Vec3 {
         let vector = alg::enqueue_vec3(vector);
        unsafe { _core_transform__inverse_transform_vector(*self, vector) };
        alg::dequeue_vec3()
    }

    pub fn is_child_of(&self, parent: Transform) -> bool {
        unsafe { _core_transform__is_child_of(*self, parent) }
    }

    pub fn look_at(&self, target: Transform, world_up: alg::Vec3) {
         let world_up = alg::enqueue_vec3(world_up);
        unsafe { _core_transform__look_at(*self, target, world_up) };
    }

    pub fn rotate(&self, eulers: alg::Vec3) {
         let eulers = alg::enqueue_vec3(eulers);
        unsafe { _core_transform__rotate(*self, eulers) };
    }

    pub fn rotate_around(&self, point: alg::Vec3, axis: alg::Vec3, angle: f32) {
         let point = alg::enqueue_vec3(point);
         let axis = alg::enqueue_vec3(axis);
        unsafe { _core_transform__rotate_around(*self, point, axis, angle) };
    }

    pub fn rotate_around_local(&self, axis: alg::Vec3, angle: f32) {
         let axis = alg::enqueue_vec3(axis);
        unsafe { _core_transform__rotate_around_local(*self, axis, angle) };
    }

    pub fn rotate_relative(&self, eulers: alg::Vec3, relative_to: i32) {
         let eulers = alg::enqueue_vec3(eulers);
        unsafe { _core_transform__rotate_relative(*self, eulers, relative_to) };
    }

    pub fn send_message(&self, method_name: &str, value: Object, options: i32) {
        let turing_handle = CString::new(method_name).unwrap();
        let method_name = turing_handle.as_ptr();
        unsafe { _core_transform__send_message(*self, method_name, value, options) };
    }

    pub fn send_message_upwards(&self, method_name: &str, value: Object, options: i32) {
        let turing_handle = CString::new(method_name).unwrap();
        let method_name = turing_handle.as_ptr();
        unsafe { _core_transform__send_message_upwards(*self, method_name, value, options) };
    }

    pub fn set_as_first_sibling(&self) {
        unsafe { _core_transform__set_as_first_sibling(*self) };
    }

    pub fn set_as_last_sibling(&self) {
        unsafe { _core_transform__set_as_last_sibling(*self) };
    }

    pub fn set_euler_angles(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_transform__set_euler_angles(*self, value) };
    }

    pub fn set_forward(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_transform__set_forward(*self, value) };
    }

    pub fn set_has_changed(&self, value: bool) {
        unsafe { _core_transform__set_has_changed(*self, value) };
    }

    pub fn set_hide_flags(&self, value: i32) {
        unsafe { _core_transform__set_hide_flags(*self, value) };
    }

    pub fn set_hierarchy_capacity(&self, value: i32) {
        unsafe { _core_transform__set_hierarchy_capacity(*self, value) };
    }

    pub fn set_local_euler_angles(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_transform__set_local_euler_angles(*self, value) };
    }

    pub fn set_local_position(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_transform__set_local_position(*self, value) };
    }

    pub fn set_local_position_and_rotation(&self, local_position: alg::Vec3, local_rotation: alg::Quat) {
         let local_position = alg::enqueue_vec3(local_position);
         let local_rotation = alg::enqueue_quat(local_rotation);
        unsafe { _core_transform__set_local_position_and_rotation(*self, local_position, local_rotation) };
    }

    pub fn set_local_rotation(&self, value: alg::Quat) {
         let value = alg::enqueue_quat(value);
        unsafe { _core_transform__set_local_rotation(*self, value) };
    }

    pub fn set_local_scale(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_transform__set_local_scale(*self, value) };
    }

    pub fn set_name(&self, value: &str) {
        let turing_handle = CString::new(value).unwrap();
        let value = turing_handle.as_ptr();
        unsafe { _core_transform__set_name(*self, value) };
    }

    pub fn set_parent(&self, parent: Transform, world_position_stays: bool) {
        unsafe { _core_transform__set_parent(*self, parent, world_position_stays) };
    }

    pub fn set_position(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_transform__set_position(*self, value) };
    }

    pub fn set_position_and_rotation(&self, position: alg::Vec3, rotation: alg::Quat) {
         let position = alg::enqueue_vec3(position);
         let rotation = alg::enqueue_quat(rotation);
        unsafe { _core_transform__set_position_and_rotation(*self, position, rotation) };
    }

    pub fn set_right(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_transform__set_right(*self, value) };
    }

    pub fn set_rotation(&self, value: alg::Quat) {
         let value = alg::enqueue_quat(value);
        unsafe { _core_transform__set_rotation(*self, value) };
    }

    pub fn set_sibling_index(&self, index: i32) {
        unsafe { _core_transform__set_sibling_index(*self, index) };
    }

    pub fn set_tag(&self, value: &str) {
        let turing_handle = CString::new(value).unwrap();
        let value = turing_handle.as_ptr();
        unsafe { _core_transform__set_tag(*self, value) };
    }

    pub fn set_up(&self, value: alg::Vec3) {
         let value = alg::enqueue_vec3(value);
        unsafe { _core_transform__set_up(*self, value) };
    }

    pub fn transform_direction(&self, direction: alg::Vec3) -> alg::Vec3 {
         let direction = alg::enqueue_vec3(direction);
        unsafe { _core_transform__transform_direction(*self, direction) };
        alg::dequeue_vec3()
    }

    pub fn transform_point(&self, position: alg::Vec3) -> alg::Vec3 {
         let position = alg::enqueue_vec3(position);
        unsafe { _core_transform__transform_point(*self, position) };
        alg::dequeue_vec3()
    }

    pub fn transform_vector(&self, vector: alg::Vec3) -> alg::Vec3 {
         let vector = alg::enqueue_vec3(vector);
        unsafe { _core_transform__transform_vector(*self, vector) };
        alg::dequeue_vec3()
    }

    pub fn translate(&self, translation: alg::Vec3, relative_to: i32) {
         let translation = alg::enqueue_vec3(translation);
        unsafe { _core_transform__translate(*self, translation, relative_to) };
    }

    pub fn translate_relative(&self, translation: alg::Vec3, relative_to: Transform) {
         let translation = alg::enqueue_vec3(translation);
        unsafe { _core_transform__translate_relative(*self, translation, relative_to) };
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct TuringMesh {
    handle: u64,
}
impl TuringMesh {

    

    pub fn _mesh_get(&self) -> Mesh {
        unsafe { _core_turing_mesh___mesh_get(*self) }
    }

    pub fn _mesh_set(&self, value: Mesh) {
        unsafe { _core_turing_mesh___mesh_set(*self, value) };
    }

    pub fn clear(&self) {
        unsafe { _core_turing_mesh__clear(*self) };
    }

    pub fn get_bounds_max_x(&self) -> f32 {
        unsafe { _core_turing_mesh__get_bounds_max_x(*self) }
    }

    pub fn get_bounds_max_y(&self) -> f32 {
        unsafe { _core_turing_mesh__get_bounds_max_y(*self) }
    }

    pub fn get_bounds_max_z(&self) -> f32 {
        unsafe { _core_turing_mesh__get_bounds_max_z(*self) }
    }

    pub fn get_bounds_min_x(&self) -> f32 {
        unsafe { _core_turing_mesh__get_bounds_min_x(*self) }
    }

    pub fn get_bounds_min_y(&self) -> f32 {
        unsafe { _core_turing_mesh__get_bounds_min_y(*self) }
    }

    pub fn get_bounds_min_z(&self) -> f32 {
        unsafe { _core_turing_mesh__get_bounds_min_z(*self) }
    }

    pub fn get_instance_id(&self) -> i32 {
        unsafe { _core_turing_mesh__get_instance_id(*self) }
    }

    pub fn get_u_vs(&self, channel: i32) -> Vec<u32> {
        let turing_result = unsafe { _core_turing_mesh__get_u_vs(*self, channel) };
        let mut turing_buf = vec![0u32; turing_result as usize];
        unsafe { _host_bufcpy(turing_buf.as_mut_ptr() as *mut c_void, turing_result) };
        turing_buf
    }

    pub fn get_vertices(&self) -> Vec<u32> {
        let turing_result = unsafe { _core_turing_mesh__get_vertices(*self) };
        let mut turing_buf = vec![0u32; turing_result as usize];
        unsafe { _host_bufcpy(turing_buf.as_mut_ptr() as *mut c_void, turing_result) };
        turing_buf
    }

    pub fn hide_flags_get(&self) {
        unsafe { _core_turing_mesh__hide_flags_get(*self) };
    }

    pub fn hide_flags_set(&self) {
        unsafe { _core_turing_mesh__hide_flags_set(*self) };
    }

    pub fn mark_modified(&self) {
        unsafe { _core_turing_mesh__mark_modified(*self) };
    }

    pub fn name_get(&self) -> String {
        let turing_result = unsafe { _core_turing_mesh__name_get(*self) };
        let mut turing_str = vec![0u8; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn name_set(&self, value: &str) {
        let turing_handle = CString::new(value).unwrap();
        let value = turing_handle.as_ptr();
        unsafe { _core_turing_mesh__name_set(*self, value) };
    }

    pub fn optimize(&self) {
        unsafe { _core_turing_mesh__optimize(*self) };
    }

    pub fn optimize_index_buffers(&self) {
        unsafe { _core_turing_mesh__optimize_index_buffers(*self) };
    }

    pub fn recalculate_bounds(&self) {
        unsafe { _core_turing_mesh__recalculate_bounds(*self) };
    }

    pub fn recalculate_normals(&self) {
        unsafe { _core_turing_mesh__recalculate_normals(*self) };
    }

    pub fn recalculate_tangents(&self) {
        unsafe { _core_turing_mesh__recalculate_tangents(*self) };
    }

    pub fn set_bounds(&self, min_x: f32, min_y: f32, min_z: f32, max_x: f32, max_y: f32, max_z: f32) {
        unsafe { _core_turing_mesh__set_bounds(*self, min_x, min_y, min_z, max_x, max_y, max_z) };
    }

    pub fn set_triangles(&self, triangles: Int32, submesh: i32, calculate_bounds: bool, base_vertex: i32) {
        unsafe { _core_turing_mesh__set_triangles(*self, triangles, submesh, calculate_bounds, base_vertex) };
    }

    pub fn set_u_vs(&self, channel: i32, uvs: &[u32]) {
        unsafe { _host_u32_enqueue(uvs.len() as u32) };
        let uvs = uvs.as_ptr() as *mut c_void;
        unsafe { _core_turing_mesh__set_u_vs(*self, channel, uvs) };
    }

    pub fn set_vertices(&self, in_vertices: &[u32]) {
        unsafe { _host_u32_enqueue(in_vertices.len() as u32) };
        let in_vertices = in_vertices.as_ptr() as *mut c_void;
        unsafe { _core_turing_mesh__set_vertices(*self, in_vertices) };
    }

    pub fn upload_mesh_data(&self, mark_no_longer_readable: bool) {
        unsafe { _core_turing_mesh__upload_mesh_data(*self, mark_no_longer_readable) };
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct TuringNoteExtensions;
impl TuringNoteExtensions {


    pub fn get_note_floor_movement(note_controller: NoteController) -> NoteFloorMovement {
        unsafe { _core_turing_note_extensions__get_note_floor_movement(note_controller) }
    }

    pub fn get_note_jump(note_controller: NoteController) -> NoteJump {
        unsafe { _core_turing_note_extensions__get_note_jump(note_controller) }
    }
    
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct TuringScriptManager {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct TuringerGameObjectManager {
    handle: u64,
}
impl TuringerGameObjectManager {


    pub fn create_object(name: &str) -> GameObject {
        let turing_handle = CString::new(name).unwrap();
        let name = turing_handle.as_ptr();
        unsafe { _core_turinger_game_object_manager__create_object(name) }
    }

    pub fn destroy_object(game_object: GameObject) {
        unsafe { _core_turinger_game_object_manager__destroy_object(game_object) };
    }

    pub fn find(name: &str) -> GameObject {
        let turing_handle = CString::new(name).unwrap();
        let name = turing_handle.as_ptr();
        unsafe { _core_turinger_game_object_manager__find(name) }
    }
    

    pub fn instance_get(&self) -> TuringerGameObjectManager {
        unsafe { _core_turinger_game_object_manager__instance_get(*self) }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct Type {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct Version {
    handle: u64,
}
#[repr(C)]
#[derive(Copy, Clone)]
#[cfg_attr(feature = "debug", derive(Debug))]
pub struct Xr {
    handle: u64,
}
impl Xr {


    pub fn get_device_battery_level(node_int: i32) -> f32 {
        unsafe { _core_xr__get_device_battery_level(node_int) }
    }

    pub fn get_device_grip_value(node_int: i32) -> f32 {
        unsafe { _core_xr__get_device_grip_value(node_int) }
    }

    pub fn get_device_name(node_int: i32) -> String {
        let turing_result = unsafe { _core_xr__get_device_name(node_int) };
        let mut turing_str = vec![0u8; turing_result as usize];
        unsafe { _host_strcpy(turing_str.as_mut_ptr() as *mut c_char, turing_result) };
        let turing_str = unsafe { CStr::from_ptr(turing_str.as_ptr() as *const c_char) };
        turing_str.to_string_lossy().into_owned()
    }

    pub fn get_device_primary_button_state(node_int: i32) -> bool {
        unsafe { _core_xr__get_device_primary_button_state(node_int) }
    }

    pub fn get_device_secondary_button_state(node_int: i32) -> bool {
        unsafe { _core_xr__get_device_secondary_button_state(node_int) }
    }

    pub fn get_device_thumbstick(node_int: i32) -> alg::Vec2 {
        unsafe { _core_xr__get_device_thumbstick(node_int) };
        alg::dequeue_vec2()
    }

    pub fn get_device_touchpad(node_int: i32) -> alg::Vec2 {
        unsafe { _core_xr__get_device_touchpad(node_int) };
        alg::dequeue_vec2()
    }

    pub fn get_device_tracking_state(node_int: i32) -> i32 {
        unsafe { _core_xr__get_device_tracking_state(node_int) }
    }

    pub fn get_device_trigger_value(node_int: i32) -> f32 {
        unsafe { _core_xr__get_device_trigger_value(node_int) }
    }

    pub fn is_device_valid(node_int: i32) -> bool {
        unsafe { _core_xr__is_device_valid(node_int) }
    }

    pub fn send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32) {
        unsafe { _core_xr__send_haptic_impulse(node_int, amplitude, duration) };
    }

    pub fn stop_haptics(node_int: i32) {
        unsafe { _core_xr__stop_haptics(node_int) };
    }
    

    pub fn _manager_get(&self) -> TuringScriptManager {
        unsafe { _core_xr___manager_get(*self) }
    }
}

