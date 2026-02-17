
///// Generated Zig API /////
const std = @import("std");
const zalg = @import("zalgebra");



//// Core Systems ////
pub fn enqueue_vec2(v: zalg.Vec2) u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    return 2;
}

pub fn enqueue_vec3(v: zalg.Vec3) u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    return 3;
}

pub fn enqueue_vec4(v: zalg.Vec4) u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    _host_f32_enqueue(v.w);
    return 4;
}

pub fn enqueue_quat(q: zalg.Quat) u32 {
    _host_f32_enqueue(q.x);
    _host_f32_enqueue(q.y);
    _host_f32_enqueue(q.z);
    _host_f32_enqueue(q.w);
    return 4;
}

pub fn enqueue_mat4(m: zalg.Mat4) u32 {
    enqueue_vec4(m.c0);
    enqueue_vec4(m.c1);
    enqueue_vec4(m.c2);
    enqueue_vec4(m.c3);
    return 16;
}


pub fn dequeue_vec2() zalg.Vec2 {
    return zalg.Vec2.init(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
    );
}

pub fn dequeue_vec3() zalg.Vec3 {
    return zalg.Vec3.init(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
    );
}

pub fn dequeue_vec4() zalg.Vec4 {
    return zalg.Vec4.init(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
    );
}

pub fn dequeue_quat() zalg.Quat {
    return zalg.Quat.init(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
    );
}

pub fn dequeue_mat4() zalg.Mat4 {
    return zalg.Mat4{
        .c0 = dequeue_vec4(),
        .c1 = dequeue_vec4(),
        .c2 = dequeue_vec4(),
        .c3 = dequeue_vec4(),
    };
}



//// Wasm Bindings ////


extern "C" fn _host_strcpy(location: [*]u8, size: u32) void;
extern "C" fn _host_bufcpy(location: [*]u32, size: u32) void;
extern "C" fn _host_f32_enqueue(f: f32) void;
extern "C" fn _host_f32_dequeue() f32;
extern "C" fn _host_u32_enqueue(u: u32) void;
extern "C" fn _host_u32_dequeue() u32;



export fn _core_semver() u64 {
    return (0 << 32) | (1 << 16) | 0;
}
pub const CORE_VERSION: []const u8 = "0.1.0";
extern "C" fn _core_custom_data__create() CustomData;
extern "C" fn _core_custom_data__from_json(json: [*c]const u8) CustomData;
extern "C" fn _core_custom_data__list_add_bool(list: List1, value: bool) void;
extern "C" fn _core_custom_data__list_add_custom_data(list: List1, value: CustomData) void;
extern "C" fn _core_custom_data__list_add_custom_data_list(list: List1, value: List1) void;
extern "C" fn _core_custom_data__list_add_float(list: List1, value: f32) void;
extern "C" fn _core_custom_data__list_add_int(list: List1, value: i32) void;
extern "C" fn _core_custom_data__list_add_string(list: List1, value: [*c]const u8) void;
extern "C" fn _core_custom_data__set_bool(custom_data: CustomData, key: [*c]const u8, value: bool) void;
extern "C" fn _core_custom_data__set_custom_data(custom_data: CustomData, key: [*c]const u8, value: CustomData) void;
extern "C" fn _core_custom_data__set_custom_data_list(custom_data: CustomData, key: [*c]const u8, value: List1) void;
extern "C" fn _core_custom_data__set_float(custom_data: CustomData, key: [*c]const u8, value: f32) void;
extern "C" fn _core_custom_data__set_int(custom_data: CustomData, key: [*c]const u8, value: i32) void;
extern "C" fn _core_custom_data__set_string(custom_data: CustomData, key: [*c]const u8, value: [*c]const u8) void;
extern "C" fn _core_custom_data__to_json(custom_data: CustomData, pretty: bool) u32;
extern "C" fn _core_custom_event_data__custom_data_get(handle: CustomEventData) CustomData;
extern "C" fn _core_custom_event_data__event_type_get(handle: CustomEventData) u32;
extern "C" fn _core_custom_event_data__get_copy(handle: CustomEventData) BeatmapDataItem;
extern "C" fn _core_custom_event_data__version_get(handle: CustomEventData) Version;
extern "C" fn _core_custom_note_data__create_custom_basic_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) CustomNoteData;
extern "C" fn _core_custom_note_data__create_custom_bomb_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) CustomNoteData;
extern "C" fn _core_custom_note_data__create_custom_burst_slider_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) CustomNoteData;
extern "C" fn _core_custom_note_data__custom_data_get(handle: CustomNoteData) CustomData;
extern "C" fn _core_custom_note_data__get_copy(handle: CustomNoteData) BeatmapDataItem;
extern "C" fn _core_custom_note_data__version_get(handle: CustomNoteData) Version;
extern "C" fn _core_custom_obstacle_data__custom_data_get(handle: CustomObstacleData) CustomData;
extern "C" fn _core_custom_obstacle_data__get_copy(handle: CustomObstacleData) BeatmapDataItem;
extern "C" fn _core_custom_obstacle_data__version_get(handle: CustomObstacleData) Version;
extern "C" fn _core_game_object__add_component(handle: GameObject, component_type: Type) Component;
extern "C" fn _core_game_object__add_or_get_mesh(handle: GameObject) TuringMesh;
extern "C" fn _core_game_object__broadcast_message(handle: GameObject, method_name: [*c]const u8, options: i32) void;
extern "C" fn _core_game_object__compare_tag(handle: GameObject, tag: [*c]const u8) bool;
extern "C" fn _core_game_object__get_active(handle: GameObject) bool;
extern "C" fn _core_game_object__get_active_in_hierarchy(handle: GameObject) bool;
extern "C" fn _core_game_object__get_active_self(handle: GameObject) bool;
extern "C" fn _core_game_object__get_component_at_index(handle: GameObject, index: i32) Component;
extern "C" fn _core_game_object__get_component_by_name(handle: GameObject, cs_type: [*c]const u8) Component;
extern "C" fn _core_game_object__get_component_by_type(handle: GameObject, cs_type: Type) Component;
extern "C" fn _core_game_object__get_component_count(handle: GameObject) i32;
extern "C" fn _core_game_object__get_component_in_children_by_type(handle: GameObject, cs_type: Type, include_inactive: bool) Component;
extern "C" fn _core_game_object__get_component_in_parent_by_type(handle: GameObject, cs_type: Type, include_inactive: bool) Component;
extern "C" fn _core_game_object__get_component_index(handle: GameObject, component: Component) i32;
extern "C" fn _core_game_object__get_hide_flags(handle: GameObject) i32;
extern "C" fn _core_game_object__get_instance_id(handle: GameObject) i32;
extern "C" fn _core_game_object__get_is_static(handle: GameObject) bool;
extern "C" fn _core_game_object__get_layer(handle: GameObject) i32;
extern "C" fn _core_game_object__get_name(handle: GameObject) u32;
extern "C" fn _core_game_object__get_scene_culling_mask(handle: GameObject) u64;
extern "C" fn _core_game_object__get_tag(handle: GameObject) u32;
extern "C" fn _core_game_object__get_transform(handle: GameObject) Transform;
extern "C" fn _core_game_object__send_message(handle: GameObject, method_name: [*c]const u8, options: i32) void;
extern "C" fn _core_game_object__send_message_upwards(handle: GameObject, method_name: [*c]const u8, options: i32) void;
extern "C" fn _core_game_object__set_active(handle: GameObject, value: bool) void;
extern "C" fn _core_game_object__set_active_prop(handle: GameObject, value: bool) void;
extern "C" fn _core_game_object__set_active_recursively(handle: GameObject, state: bool) void;
extern "C" fn _core_game_object__set_hide_flags(handle: GameObject, value: i32) void;
extern "C" fn _core_game_object__set_is_static(handle: GameObject, value: bool) void;
extern "C" fn _core_game_object__set_layer(handle: GameObject, value: i32) void;
extern "C" fn _core_game_object__set_name(handle: GameObject, value: [*c]const u8) void;
extern "C" fn _core_game_object__set_tag(handle: GameObject, value: [*c]const u8) void;
extern "C" fn _core_gc_helper__create() GCHelper;
extern "C" fn _core_gc_helper__dispose(handle: GcHelper) void;
extern "C" fn _core_gc_helper__invalidate_all_handles(handle: GcHelper) void;
extern "C" fn _core_gc_helper__wasm_garbage_collect(handle: GcHelper) void;
extern "C" fn _core_log__critical(msg: [*c]const u8) void;
extern "C" fn _core_log__debug(msg: [*c]const u8) void;
extern "C" fn _core_log__info(msg: [*c]const u8) void;
extern "C" fn _core_log__warn(msg: [*c]const u8) void;
extern "C" fn _core_note_floor_movement___audio_time_sync_controller_get(handle: NoteFloorMovement) IAudioTimeSource;
extern "C" fn _core_note_floor_movement___beat_time_get(handle: NoteFloorMovement) f32;
extern "C" fn _core_note_floor_movement___beat_time_set(handle: NoteFloorMovement, value: f32) void;
extern "C" fn _core_note_floor_movement___inverse_world_rotation_get(handle: NoteFloorMovement) u32;
extern "C" fn _core_note_floor_movement___inverse_world_rotation_set(handle: NoteFloorMovement, value: u32) void;
extern "C" fn _core_note_floor_movement___local_position_get(handle: NoteFloorMovement) u32;
extern "C" fn _core_note_floor_movement___local_position_set(handle: NoteFloorMovement, value: u32) void;
extern "C" fn _core_note_floor_movement___move_end_offset_get(handle: NoteFloorMovement) u32;
extern "C" fn _core_note_floor_movement___move_end_offset_set(handle: NoteFloorMovement, value: u32) void;
extern "C" fn _core_note_floor_movement___move_start_offset_get(handle: NoteFloorMovement) u32;
extern "C" fn _core_note_floor_movement___move_start_offset_set(handle: NoteFloorMovement, value: u32) void;
extern "C" fn _core_note_floor_movement___player_transforms_get(handle: NoteFloorMovement) PlayerTransforms;
extern "C" fn _core_note_floor_movement___rotated_object_get(handle: NoteFloorMovement) Transform;
extern "C" fn _core_note_floor_movement___rotated_object_set(handle: NoteFloorMovement, value: Transform) void;
extern "C" fn _core_note_floor_movement___variable_movement_data_provider_get(handle: NoteFloorMovement) IVariableMovementDataProvider;
extern "C" fn _core_note_floor_movement___world_rotation_get(handle: NoteFloorMovement) u32;
extern "C" fn _core_note_floor_movement___world_rotation_set(handle: NoteFloorMovement, value: u32) void;
extern "C" fn _core_note_floor_movement__distance_to_player_get(handle: NoteFloorMovement) f32;
extern "C" fn _core_note_floor_movement__end_pos_get(handle: NoteFloorMovement) u32;
extern "C" fn _core_note_floor_movement__init(handle: NoteFloorMovement, world_rotation: f32, beat_time: f32, move_start_offset: u32, move_end_offset: u32) void;
extern "C" fn _core_note_floor_movement__inverse_world_rotation_get(handle: NoteFloorMovement) u32;
extern "C" fn _core_note_floor_movement__local_position_get(handle: NoteFloorMovement) u32;
extern "C" fn _core_note_floor_movement__manual_update(handle: NoteFloorMovement) u32;
extern "C" fn _core_note_floor_movement__note_time_get(handle: NoteFloorMovement) f32;
extern "C" fn _core_note_floor_movement__set_to_start(handle: NoteFloorMovement) u32;
extern "C" fn _core_note_floor_movement__should_move(handle: NoteFloorMovement) bool;
extern "C" fn _core_note_floor_movement__world_rotation_get(handle: NoteFloorMovement) u32;
extern "C" fn _core_note_jump__k_missed_time_offset_get() f32;
extern "C" fn _core_note_jump___audio_time_sync_controller_get(handle: NoteJump) IAudioTimeSource;
extern "C" fn _core_note_jump___end_distance_offset_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump___end_distance_offset_set(handle: NoteJump, value: f32) void;
extern "C" fn _core_note_jump___end_offset_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump___end_offset_set(handle: NoteJump, value: u32) void;
extern "C" fn _core_note_jump___end_pos_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump___end_pos_set(handle: NoteJump, value: u32) void;
extern "C" fn _core_note_jump___end_rotation_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump___end_rotation_set(handle: NoteJump, value: u32) void;
extern "C" fn _core_note_jump___gravity_base_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump___gravity_base_set(handle: NoteJump, value: f32) void;
extern "C" fn _core_note_jump___gravity_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump___gravity_set(handle: NoteJump, value: f32) void;
extern "C" fn _core_note_jump___half_jump_duration_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump___half_jump_duration_set(handle: NoteJump, value: f32) void;
extern "C" fn _core_note_jump___half_jump_mark_reported_get(handle: NoteJump) bool;
extern "C" fn _core_note_jump___half_jump_mark_reported_set(handle: NoteJump, value: bool) void;
extern "C" fn _core_note_jump___inverse_world_rotation_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump___inverse_world_rotation_set(handle: NoteJump, value: u32) void;
extern "C" fn _core_note_jump___jump_duration_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump___jump_duration_set(handle: NoteJump, value: f32) void;
extern "C" fn _core_note_jump___jump_started_reported_get(handle: NoteJump) bool;
extern "C" fn _core_note_jump___jump_started_reported_set(handle: NoteJump, value: bool) void;
extern "C" fn _core_note_jump___local_position_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump___local_position_set(handle: NoteJump, value: u32) void;
extern "C" fn _core_note_jump___middle_rotation_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump___middle_rotation_set(handle: NoteJump, value: u32) void;
extern "C" fn _core_note_jump___missed_mark_reported_get(handle: NoteJump) bool;
extern "C" fn _core_note_jump___missed_mark_reported_set(handle: NoteJump, value: bool) void;
extern "C" fn _core_note_jump___missed_time_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump___missed_time_set(handle: NoteJump, value: f32) void;
extern "C" fn _core_note_jump___note_time_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump___note_time_set(handle: NoteJump, value: f32) void;
extern "C" fn _core_note_jump___player_space_convertor_get(handle: NoteJump) PlayerSpaceConvertor;
extern "C" fn _core_note_jump___player_transforms_get(handle: NoteJump) PlayerTransforms;
extern "C" fn _core_note_jump___rotate_towards_player_get(handle: NoteJump) bool;
extern "C" fn _core_note_jump___rotate_towards_player_set(handle: NoteJump, value: bool) void;
extern "C" fn _core_note_jump___rotated_object_get(handle: NoteJump) Transform;
extern "C" fn _core_note_jump___rotated_object_set(handle: NoteJump, value: Transform) void;
extern "C" fn _core_note_jump___start_offset_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump___start_offset_set(handle: NoteJump, value: u32) void;
extern "C" fn _core_note_jump___start_pos_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump___start_pos_set(handle: NoteJump, value: u32) void;
extern "C" fn _core_note_jump___start_rotation_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump___start_rotation_set(handle: NoteJump, value: u32) void;
extern "C" fn _core_note_jump___three_quarters_mark_reported_get(handle: NoteJump) bool;
extern "C" fn _core_note_jump___three_quarters_mark_reported_set(handle: NoteJump, value: bool) void;
extern "C" fn _core_note_jump___variable_movement_data_provider_get(handle: NoteJump) IVariableMovementDataProvider;
extern "C" fn _core_note_jump___world_rotation_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump___world_rotation_set(handle: NoteJump, value: u32) void;
extern "C" fn _core_note_jump___y_avoidance_down_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump___y_avoidance_down_set(handle: NoteJump, value: f32) void;
extern "C" fn _core_note_jump___y_avoidance_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump___y_avoidance_set(handle: NoteJump, value: f32) void;
extern "C" fn _core_note_jump___y_avoidance_up_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump___y_avoidance_up_set(handle: NoteJump, value: f32) void;
extern "C" fn _core_note_jump__add_note_jump_did_finish_event(handle: NoteJump, value: Action) void;
extern "C" fn _core_note_jump__add_note_jump_did_pass_half_event(handle: NoteJump, value: Action) void;
extern "C" fn _core_note_jump__add_note_jump_did_pass_missed_marker_event(handle: NoteJump, value: Action) void;
extern "C" fn _core_note_jump__add_note_jump_did_pass_three_quarters_event(handle: NoteJump, value: Action1) void;
extern "C" fn _core_note_jump__add_note_jump_did_start_event(handle: NoteJump, value: Action) void;
extern "C" fn _core_note_jump__add_note_jump_did_update_progress_event(handle: NoteJump, value: Action1) void;
extern "C" fn _core_note_jump__beat_pos_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump__distance_to_player_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump__init(handle: NoteJump, note_time: f32, world_rotation: f32, move_end_offset: u32, jump_end_offset: u32, gravity_base: f32, flip_y_side: f32, end_rotation: f32, rotate_towards_player: bool, use_random_rotation: bool) void;
extern "C" fn _core_note_jump__local_position_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump__manual_update(handle: NoteJump) u32;
extern "C" fn _core_note_jump__move_vec_get(handle: NoteJump) u32;
extern "C" fn _core_note_jump__note_time_get(handle: NoteJump) f32;
extern "C" fn _core_note_jump__remove_note_jump_did_finish_event(handle: NoteJump, value: Action) void;
extern "C" fn _core_note_jump__remove_note_jump_did_pass_half_event(handle: NoteJump, value: Action) void;
extern "C" fn _core_note_jump__remove_note_jump_did_pass_missed_marker_event(handle: NoteJump, value: Action) void;
extern "C" fn _core_note_jump__remove_note_jump_did_pass_three_quarters_event(handle: NoteJump, value: Action1) void;
extern "C" fn _core_note_jump__remove_note_jump_did_start_event(handle: NoteJump, value: Action) void;
extern "C" fn _core_note_jump__remove_note_jump_did_update_progress_event(handle: NoteJump, value: Action1) void;
extern "C" fn _core_note_manager__add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: CustomData) CustomNoteData;
extern "C" fn _core_note_manager__add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: CustomData) CustomNoteData;
extern "C" fn _core_note_manager__add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: CustomData) CustomObstacleData;
extern "C" fn _core_note_manager__get_note_controller(n: i32) NoteControllerBase;
extern "C" fn _core_note_manager__get_note_controller_from_custom(n: CustomNoteData) NoteControllerBase;
extern "C" fn _core_note_manager__get_nth_event(id: i32) CustomEventData;
extern "C" fn _core_note_manager__get_nth_note(id: i32) CustomNoteData;
extern "C" fn _core_note_manager__get_nth_object(id: i32) BeatmapDataItem;
extern "C" fn _core_note_manager__get_nth_obstacle(id: i32) CustomObstacleData;
extern "C" fn _core_note_manager__get_obstacle_controller(n: i32) ObstacleControllerBase;
extern "C" fn _core_note_manager__get_obstacle_controller_from_custom(n: CustomObstacleData) ObstacleController;
extern "C" fn _core_note_manager__time_to_beat(time: f32) f32;
extern "C" fn _core_task_scheduler__schedule(task: Action) void;
extern "C" fn _core_task_scheduler__dispose(handle: TaskScheduler) void;
extern "C" fn _core_transform__broadcast_message(handle: Transform, method_name: [*c]const u8, parameter: Object, options: i32) void;
extern "C" fn _core_transform__compare_tag(handle: Transform, tag: [*c]const u8) bool;
extern "C" fn _core_transform__detach_children(handle: Transform) void;
extern "C" fn _core_transform__find(handle: Transform, n: [*c]const u8) Transform;
extern "C" fn _core_transform__find_child(handle: Transform, n: [*c]const u8) Transform;
extern "C" fn _core_transform__get_child(handle: Transform, index: i32) Transform;
extern "C" fn _core_transform__get_child_count(handle: Transform) i32;
extern "C" fn _core_transform__get_child_count_prop(handle: Transform) i32;
extern "C" fn _core_transform__get_component_by_name(handle: Transform, cs_type: [*c]const u8) Component;
extern "C" fn _core_transform__get_component_by_type(handle: Transform, cs_type: Type) Component;
extern "C" fn _core_transform__get_component_in_children_by_type(handle: Transform, t: Type, include_inactive: bool) Component;
extern "C" fn _core_transform__get_component_in_parent_by_type(handle: Transform, t: Type, include_inactive: bool) Component;
extern "C" fn _core_transform__get_component_index(handle: Transform) i32;
extern "C" fn _core_transform__get_enumerator(handle: Transform) IEnumerator;
extern "C" fn _core_transform__get_euler_angles(handle: Transform) u32;
extern "C" fn _core_transform__get_forward(handle: Transform) u32;
extern "C" fn _core_transform__get_game_object(handle: Transform) GameObject;
extern "C" fn _core_transform__get_has_changed(handle: Transform) bool;
extern "C" fn _core_transform__get_hide_flags(handle: Transform) i32;
extern "C" fn _core_transform__get_hierarchy_capacity(handle: Transform) i32;
extern "C" fn _core_transform__get_hierarchy_count(handle: Transform) i32;
extern "C" fn _core_transform__get_instance_id(handle: Transform) i32;
extern "C" fn _core_transform__get_local_euler_angles(handle: Transform) u32;
extern "C" fn _core_transform__get_local_position(handle: Transform) u32;
extern "C" fn _core_transform__get_local_rotation(handle: Transform) u32;
extern "C" fn _core_transform__get_local_scale(handle: Transform) u32;
extern "C" fn _core_transform__get_local_to_world_matrix(handle: Transform) u32;
extern "C" fn _core_transform__get_lossy_scale(handle: Transform) u32;
extern "C" fn _core_transform__get_name(handle: Transform) u32;
extern "C" fn _core_transform__get_parent(handle: Transform) Transform;
extern "C" fn _core_transform__get_position(handle: Transform) u32;
extern "C" fn _core_transform__get_right(handle: Transform) u32;
extern "C" fn _core_transform__get_root(handle: Transform) Transform;
extern "C" fn _core_transform__get_rotation(handle: Transform) u32;
extern "C" fn _core_transform__get_sibling_index(handle: Transform) i32;
extern "C" fn _core_transform__get_tag(handle: Transform) u32;
extern "C" fn _core_transform__get_up(handle: Transform) u32;
extern "C" fn _core_transform__get_world_to_local_matrix(handle: Transform) u32;
extern "C" fn _core_transform__inverse_transform_direction(handle: Transform, direction: u32) u32;
extern "C" fn _core_transform__inverse_transform_point(handle: Transform, position: u32) u32;
extern "C" fn _core_transform__inverse_transform_vector(handle: Transform, vector: u32) u32;
extern "C" fn _core_transform__is_child_of(handle: Transform, parent: Transform) bool;
extern "C" fn _core_transform__look_at(handle: Transform, target: Transform, world_up: u32) void;
extern "C" fn _core_transform__rotate(handle: Transform, eulers: u32) void;
extern "C" fn _core_transform__rotate_around(handle: Transform, point: u32, axis: u32, angle: f32) void;
extern "C" fn _core_transform__rotate_around_local(handle: Transform, axis: u32, angle: f32) void;
extern "C" fn _core_transform__rotate_relative(handle: Transform, eulers: u32, relative_to: i32) void;
extern "C" fn _core_transform__send_message(handle: Transform, method_name: [*c]const u8, value: Object, options: i32) void;
extern "C" fn _core_transform__send_message_upwards(handle: Transform, method_name: [*c]const u8, value: Object, options: i32) void;
extern "C" fn _core_transform__set_as_first_sibling(handle: Transform) void;
extern "C" fn _core_transform__set_as_last_sibling(handle: Transform) void;
extern "C" fn _core_transform__set_euler_angles(handle: Transform, value: u32) void;
extern "C" fn _core_transform__set_forward(handle: Transform, value: u32) void;
extern "C" fn _core_transform__set_has_changed(handle: Transform, value: bool) void;
extern "C" fn _core_transform__set_hide_flags(handle: Transform, value: i32) void;
extern "C" fn _core_transform__set_hierarchy_capacity(handle: Transform, value: i32) void;
extern "C" fn _core_transform__set_local_euler_angles(handle: Transform, value: u32) void;
extern "C" fn _core_transform__set_local_position(handle: Transform, value: u32) void;
extern "C" fn _core_transform__set_local_position_and_rotation(handle: Transform, local_position: u32, local_rotation: u32) void;
extern "C" fn _core_transform__set_local_rotation(handle: Transform, value: u32) void;
extern "C" fn _core_transform__set_local_scale(handle: Transform, value: u32) void;
extern "C" fn _core_transform__set_name(handle: Transform, value: [*c]const u8) void;
extern "C" fn _core_transform__set_parent(handle: Transform, parent: Transform, world_position_stays: bool) void;
extern "C" fn _core_transform__set_position(handle: Transform, value: u32) void;
extern "C" fn _core_transform__set_position_and_rotation(handle: Transform, position: u32, rotation: u32) void;
extern "C" fn _core_transform__set_right(handle: Transform, value: u32) void;
extern "C" fn _core_transform__set_rotation(handle: Transform, value: u32) void;
extern "C" fn _core_transform__set_sibling_index(handle: Transform, index: i32) void;
extern "C" fn _core_transform__set_tag(handle: Transform, value: [*c]const u8) void;
extern "C" fn _core_transform__set_up(handle: Transform, value: u32) void;
extern "C" fn _core_transform__transform_direction(handle: Transform, direction: u32) u32;
extern "C" fn _core_transform__transform_point(handle: Transform, position: u32) u32;
extern "C" fn _core_transform__transform_vector(handle: Transform, vector: u32) u32;
extern "C" fn _core_transform__translate(handle: Transform, translation: u32, relative_to: i32) void;
extern "C" fn _core_transform__translate_relative(handle: Transform, translation: u32, relative_to: Transform) void;
extern "C" fn _core_turing_mesh___mesh_get(handle: TuringMesh) Mesh;
extern "C" fn _core_turing_mesh___mesh_set(handle: TuringMesh, value: Mesh) void;
extern "C" fn _core_turing_mesh__clear(handle: TuringMesh) void;
extern "C" fn _core_turing_mesh__get_bounds_max_x(handle: TuringMesh) f32;
extern "C" fn _core_turing_mesh__get_bounds_max_y(handle: TuringMesh) f32;
extern "C" fn _core_turing_mesh__get_bounds_max_z(handle: TuringMesh) f32;
extern "C" fn _core_turing_mesh__get_bounds_min_x(handle: TuringMesh) f32;
extern "C" fn _core_turing_mesh__get_bounds_min_y(handle: TuringMesh) f32;
extern "C" fn _core_turing_mesh__get_bounds_min_z(handle: TuringMesh) f32;
extern "C" fn _core_turing_mesh__get_instance_id(handle: TuringMesh) i32;
extern "C" fn _core_turing_mesh__get_u_vs(handle: TuringMesh, channel: i32) u32;
extern "C" fn _core_turing_mesh__get_vertices(handle: TuringMesh) u32;
extern "C" fn _core_turing_mesh__hide_flags_get(handle: TuringMesh) void;
extern "C" fn _core_turing_mesh__hide_flags_set(handle: TuringMesh) void;
extern "C" fn _core_turing_mesh__mark_modified(handle: TuringMesh) void;
extern "C" fn _core_turing_mesh__name_get(handle: TuringMesh) u32;
extern "C" fn _core_turing_mesh__name_set(handle: TuringMesh, value: [*c]const u8) void;
extern "C" fn _core_turing_mesh__optimize(handle: TuringMesh) void;
extern "C" fn _core_turing_mesh__optimize_index_buffers(handle: TuringMesh) void;
extern "C" fn _core_turing_mesh__recalculate_bounds(handle: TuringMesh) void;
extern "C" fn _core_turing_mesh__recalculate_normals(handle: TuringMesh) void;
extern "C" fn _core_turing_mesh__recalculate_tangents(handle: TuringMesh) void;
extern "C" fn _core_turing_mesh__set_bounds(handle: TuringMesh, min_x: f32, min_y: f32, min_z: f32, max_x: f32, max_y: f32, max_z: f32) void;
extern "C" fn _core_turing_mesh__set_triangles(handle: TuringMesh, triangles: Int32, submesh: i32, calculate_bounds: bool, base_vertex: i32) void;
extern "C" fn _core_turing_mesh__set_u_vs(handle: TuringMesh, channel: i32, uvs: *const anyopaque) void;
extern "C" fn _core_turing_mesh__set_vertices(handle: TuringMesh, in_vertices: *const anyopaque) void;
extern "C" fn _core_turing_mesh__upload_mesh_data(handle: TuringMesh, mark_no_longer_readable: bool) void;
extern "C" fn _core_turing_note_extensions__get_note_floor_movement(note_controller: NoteController) NoteFloorMovement;
extern "C" fn _core_turing_note_extensions__get_note_jump(note_controller: NoteController) NoteJump;
extern "C" fn _core_turinger_game_object_manager__create_object(name: [*c]const u8) GameObject;
extern "C" fn _core_turinger_game_object_manager__destroy_object(game_object: GameObject) void;
extern "C" fn _core_turinger_game_object_manager__find(name: [*c]const u8) GameObject;
extern "C" fn _core_turinger_game_object_manager__instance_get(handle: TuringerGameObjectManager) TuringerGameObjectManager;
extern "C" fn _core_xr__get_device_battery_level(node_int: i32) f32;
extern "C" fn _core_xr__get_device_grip_value(node_int: i32) f32;
extern "C" fn _core_xr__get_device_name(node_int: i32) u32;
extern "C" fn _core_xr__get_device_primary_button_state(node_int: i32) bool;
extern "C" fn _core_xr__get_device_secondary_button_state(node_int: i32) bool;
extern "C" fn _core_xr__get_device_thumbstick(node_int: i32) u32;
extern "C" fn _core_xr__get_device_touchpad(node_int: i32) u32;
extern "C" fn _core_xr__get_device_tracking_state(node_int: i32) i32;
extern "C" fn _core_xr__get_device_trigger_value(node_int: i32) f32;
extern "C" fn _core_xr__is_device_valid(node_int: i32) bool;
extern "C" fn _core_xr__send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32) void;
extern "C" fn _core_xr__stop_haptics(node_int: i32) void;
extern "C" fn _core_xr___manager_get(handle: Xr) TuringScriptManager;

//// Functions ////



//// Classes ////

pub const Action = struct {
    opaqu: u64,
};

pub const Action1 = struct {
    opaqu: u64,
};

pub const BeatmapDataItem = struct {
    opaqu: u64,
};

pub const Component = struct {
    opaqu: u64,
};

pub const CustomData = struct {
    opaqu: u64,

    pub fn create() CustomData {
        return _core_custom_data__create();
    }

    pub fn from_json(json: []const u8, allocator: std.mem.Allocator) !CustomData {
        const turing_handle_json = try allocator.dupeZ(u8, json);
        defer allocator.free(turing_handle_json);
        return _core_custom_data__from_json(turing_handle_json.ptr);
    }

    pub fn list_add_bool(list: List1, value: bool) void {
        _core_custom_data__list_add_bool(list, value);
    }

    pub fn list_add_custom_data(list: List1, value: CustomData) void {
        _core_custom_data__list_add_custom_data(list, value);
    }

    pub fn list_add_custom_data_list(list: List1, value: List1) void {
        _core_custom_data__list_add_custom_data_list(list, value);
    }

    pub fn list_add_float(list: List1, value: f32) void {
        _core_custom_data__list_add_float(list, value);
    }

    pub fn list_add_int(list: List1, value: i32) void {
        _core_custom_data__list_add_int(list, value);
    }

    pub fn list_add_string(list: List1, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _core_custom_data__list_add_string(list, turing_handle_value.ptr);
    }

    pub fn set_bool(custom_data: CustomData, key: []const u8, value: bool, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        _core_custom_data__set_bool(custom_data, turing_handle_key.ptr, value);
    }

    pub fn set_custom_data(custom_data: CustomData, key: []const u8, value: CustomData, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        _core_custom_data__set_custom_data(custom_data, turing_handle_key.ptr, value);
    }

    pub fn set_custom_data_list(custom_data: CustomData, key: []const u8, value: List1, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        _core_custom_data__set_custom_data_list(custom_data, turing_handle_key.ptr, value);
    }

    pub fn set_float(custom_data: CustomData, key: []const u8, value: f32, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        _core_custom_data__set_float(custom_data, turing_handle_key.ptr, value);
    }

    pub fn set_int(custom_data: CustomData, key: []const u8, value: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        _core_custom_data__set_int(custom_data, turing_handle_key.ptr, value);
    }

    pub fn set_string(custom_data: CustomData, key: []const u8, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _core_custom_data__set_string(custom_data, turing_handle_key.ptr, turing_handle_value.ptr);
    }

    pub fn to_json(custom_data: CustomData, pretty: bool, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_custom_data__to_json(custom_data, pretty);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }
};

pub const CustomEventData = struct {
    opaqu: u64,

    pub fn custom_data_get(self: *const CustomEventData) CustomData {
        return _core_custom_event_data__custom_data_get(self);
    }

    pub fn event_type_get(self: *const CustomEventData, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_custom_event_data__event_type_get(self);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }

    pub fn get_copy(self: *const CustomEventData) BeatmapDataItem {
        return _core_custom_event_data__get_copy(self);
    }

    pub fn version_get(self: *const CustomEventData) Version {
        return _core_custom_event_data__version_get(self);
    }
};

pub const CustomNoteData = struct {
    opaqu: u64,

    pub fn create_custom_basic_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) CustomNoteData {
        return _core_custom_note_data__create_custom_basic_note_data(time, beat, rotation, line_index);
    }

    pub fn create_custom_bomb_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) CustomNoteData {
        return _core_custom_note_data__create_custom_bomb_note_data(time, beat, rotation, line_index);
    }

    pub fn create_custom_burst_slider_note_data(time: f32, beat: f32, rotation: i32, line_index: i32) CustomNoteData {
        return _core_custom_note_data__create_custom_burst_slider_note_data(time, beat, rotation, line_index);
    }

    pub fn custom_data_get(self: *const CustomNoteData) CustomData {
        return _core_custom_note_data__custom_data_get(self);
    }

    pub fn get_copy(self: *const CustomNoteData) BeatmapDataItem {
        return _core_custom_note_data__get_copy(self);
    }

    pub fn version_get(self: *const CustomNoteData) Version {
        return _core_custom_note_data__version_get(self);
    }
};

pub const CustomObstacleData = struct {
    opaqu: u64,

    pub fn custom_data_get(self: *const CustomObstacleData) CustomData {
        return _core_custom_obstacle_data__custom_data_get(self);
    }

    pub fn get_copy(self: *const CustomObstacleData) BeatmapDataItem {
        return _core_custom_obstacle_data__get_copy(self);
    }

    pub fn version_get(self: *const CustomObstacleData) Version {
        return _core_custom_obstacle_data__version_get(self);
    }
};

pub const GcHelper = struct {
    opaqu: u64,
};

pub const GameObject = struct {
    opaqu: u64,

    pub fn add_component(self: *const GameObject, component_type: Type) Component {
        return _core_game_object__add_component(self, component_type);
    }

    pub fn add_or_get_mesh(self: *const GameObject) TuringMesh {
        return _core_game_object__add_or_get_mesh(self);
    }

    pub fn broadcast_message(self: *const GameObject, method_name: []const u8, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_game_object__broadcast_message(self, turing_handle_method_name.ptr, options);
    }

    pub fn compare_tag(self: *const GameObject, tag: []const u8, allocator: std.mem.Allocator) !bool {
        const turing_handle_tag = try allocator.dupeZ(u8, tag);
        defer allocator.free(turing_handle_tag);
        return _core_game_object__compare_tag(self, turing_handle_tag.ptr);
    }

    pub fn get_active(self: *const GameObject) bool {
        return _core_game_object__get_active(self);
    }

    pub fn get_active_in_hierarchy(self: *const GameObject) bool {
        return _core_game_object__get_active_in_hierarchy(self);
    }

    pub fn get_active_self(self: *const GameObject) bool {
        return _core_game_object__get_active_self(self);
    }

    pub fn get_component_at_index(self: *const GameObject, index: i32) Component {
        return _core_game_object__get_component_at_index(self, index);
    }

    pub fn get_component_by_name(self: *const GameObject, cs_type: []const u8, allocator: std.mem.Allocator) !Component {
        const turing_handle_cs_type = try allocator.dupeZ(u8, cs_type);
        defer allocator.free(turing_handle_cs_type);
        return _core_game_object__get_component_by_name(self, turing_handle_cs_type.ptr);
    }

    pub fn get_component_by_type(self: *const GameObject, cs_type: Type) Component {
        return _core_game_object__get_component_by_type(self, cs_type);
    }

    pub fn get_component_count(self: *const GameObject) i32 {
        return _core_game_object__get_component_count(self);
    }

    pub fn get_component_in_children_by_type(self: *const GameObject, cs_type: Type, include_inactive: bool) Component {
        return _core_game_object__get_component_in_children_by_type(self, cs_type, include_inactive);
    }

    pub fn get_component_in_parent_by_type(self: *const GameObject, cs_type: Type, include_inactive: bool) Component {
        return _core_game_object__get_component_in_parent_by_type(self, cs_type, include_inactive);
    }

    pub fn get_component_index(self: *const GameObject, component: Component) i32 {
        return _core_game_object__get_component_index(self, component);
    }

    pub fn get_hide_flags(self: *const GameObject) i32 {
        return _core_game_object__get_hide_flags(self);
    }

    pub fn get_instance_id(self: *const GameObject) i32 {
        return _core_game_object__get_instance_id(self);
    }

    pub fn get_is_static(self: *const GameObject) bool {
        return _core_game_object__get_is_static(self);
    }

    pub fn get_layer(self: *const GameObject) i32 {
        return _core_game_object__get_layer(self);
    }

    pub fn get_name(self: *const GameObject, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_game_object__get_name(self);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }

    pub fn get_scene_culling_mask(self: *const GameObject) u64 {
        return _core_game_object__get_scene_culling_mask(self);
    }

    pub fn get_tag(self: *const GameObject, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_game_object__get_tag(self);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }

    pub fn get_transform(self: *const GameObject) Transform {
        return _core_game_object__get_transform(self);
    }

    pub fn send_message(self: *const GameObject, method_name: []const u8, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_game_object__send_message(self, turing_handle_method_name.ptr, options);
    }

    pub fn send_message_upwards(self: *const GameObject, method_name: []const u8, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_game_object__send_message_upwards(self, turing_handle_method_name.ptr, options);
    }

    pub fn set_active(self: *const GameObject, value: bool) void {
        _core_game_object__set_active(self, value);
    }

    pub fn set_active_prop(self: *const GameObject, value: bool) void {
        _core_game_object__set_active_prop(self, value);
    }

    pub fn set_active_recursively(self: *const GameObject, state: bool) void {
        _core_game_object__set_active_recursively(self, state);
    }

    pub fn set_hide_flags(self: *const GameObject, value: i32) void {
        _core_game_object__set_hide_flags(self, value);
    }

    pub fn set_is_static(self: *const GameObject, value: bool) void {
        _core_game_object__set_is_static(self, value);
    }

    pub fn set_layer(self: *const GameObject, value: i32) void {
        _core_game_object__set_layer(self, value);
    }

    pub fn set_name(self: *const GameObject, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _core_game_object__set_name(self, turing_handle_value.ptr);
    }

    pub fn set_tag(self: *const GameObject, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _core_game_object__set_tag(self, turing_handle_value.ptr);
    }
};

pub const GcHelper = struct {
    opaqu: u64,

    pub fn create() GCHelper {
        return _core_gc_helper__create();
    }

    pub fn dispose(self: *const GcHelper) void {
        _core_gc_helper__dispose(self);
    }

    pub fn invalidate_all_handles(self: *const GcHelper) void {
        _core_gc_helper__invalidate_all_handles(self);
    }

    pub fn wasm_garbage_collect(self: *const GcHelper) void {
        _core_gc_helper__wasm_garbage_collect(self);
    }
};

pub const IAudioTimeSource = struct {
    opaqu: u64,
};

pub const IEnumerator = struct {
    opaqu: u64,
};

pub const IVariableMovementDataProvider = struct {
    opaqu: u64,
};

pub const Int32 = struct {
    opaqu: u64,
};

pub const List1 = struct {
    opaqu: u64,
};

pub const Log = struct {
    

    pub fn critical(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _core_log__critical(turing_handle_msg.ptr);
    }

    pub fn debug(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _core_log__debug(turing_handle_msg.ptr);
    }

    pub fn info(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _core_log__info(turing_handle_msg.ptr);
    }

    pub fn warn(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _core_log__warn(turing_handle_msg.ptr);
    }
};

pub const Mesh = struct {
    opaqu: u64,
};

pub const NoteController = struct {
    opaqu: u64,
};

pub const NoteControllerBase = struct {
    opaqu: u64,
};

pub const NoteFloorMovement = struct {
    opaqu: u64,

    pub fn _audio_time_sync_controller_get(self: *const NoteFloorMovement) IAudioTimeSource {
        return _core_note_floor_movement___audio_time_sync_controller_get(self);
    }

    pub fn _beat_time_get(self: *const NoteFloorMovement) f32 {
        return _core_note_floor_movement___beat_time_get(self);
    }

    pub fn _beat_time_set(self: *const NoteFloorMovement, value: f32) void {
        _core_note_floor_movement___beat_time_set(self, value);
    }

    pub fn _inverse_world_rotation_get(self: *const NoteFloorMovement) zalg.Quat {
        _core_note_floor_movement___inverse_world_rotation_get(self);
        return dequeue_quat();
    }

    pub fn _inverse_world_rotation_set(self: *const NoteFloorMovement, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _core_note_floor_movement___inverse_world_rotation_set(self, turing_handle_value);
    }

    pub fn _local_position_get(self: *const NoteFloorMovement) zalg.Vec3 {
        _core_note_floor_movement___local_position_get(self);
        return dequeue_vec3();
    }

    pub fn _local_position_set(self: *const NoteFloorMovement, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_note_floor_movement___local_position_set(self, turing_handle_value);
    }

    pub fn _move_end_offset_get(self: *const NoteFloorMovement) zalg.Vec3 {
        _core_note_floor_movement___move_end_offset_get(self);
        return dequeue_vec3();
    }

    pub fn _move_end_offset_set(self: *const NoteFloorMovement, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_note_floor_movement___move_end_offset_set(self, turing_handle_value);
    }

    pub fn _move_start_offset_get(self: *const NoteFloorMovement) zalg.Vec3 {
        _core_note_floor_movement___move_start_offset_get(self);
        return dequeue_vec3();
    }

    pub fn _move_start_offset_set(self: *const NoteFloorMovement, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_note_floor_movement___move_start_offset_set(self, turing_handle_value);
    }

    pub fn _player_transforms_get(self: *const NoteFloorMovement) PlayerTransforms {
        return _core_note_floor_movement___player_transforms_get(self);
    }

    pub fn _rotated_object_get(self: *const NoteFloorMovement) Transform {
        return _core_note_floor_movement___rotated_object_get(self);
    }

    pub fn _rotated_object_set(self: *const NoteFloorMovement, value: Transform) void {
        _core_note_floor_movement___rotated_object_set(self, value);
    }

    pub fn _variable_movement_data_provider_get(self: *const NoteFloorMovement) IVariableMovementDataProvider {
        return _core_note_floor_movement___variable_movement_data_provider_get(self);
    }

    pub fn _world_rotation_get(self: *const NoteFloorMovement) zalg.Quat {
        _core_note_floor_movement___world_rotation_get(self);
        return dequeue_quat();
    }

    pub fn _world_rotation_set(self: *const NoteFloorMovement, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _core_note_floor_movement___world_rotation_set(self, turing_handle_value);
    }

    pub fn distance_to_player_get(self: *const NoteFloorMovement) f32 {
        return _core_note_floor_movement__distance_to_player_get(self);
    }

    pub fn end_pos_get(self: *const NoteFloorMovement) zalg.Vec3 {
        _core_note_floor_movement__end_pos_get(self);
        return dequeue_vec3();
    }

    pub fn init_floor(self: *const NoteFloorMovement, world_rotation: f32, beat_time: f32, move_start_offset: zalg.Vec3, move_end_offset: zalg.Vec3) void {
        const turing_handle_move_start_offset = enqueue_vec3(move_start_offset);
        const turing_handle_move_end_offset = enqueue_vec3(move_end_offset);
        _core_note_floor_movement__init(self, world_rotation, beat_time, turing_handle_move_start_offset, turing_handle_move_end_offset);
    }

    pub fn inverse_world_rotation_get(self: *const NoteFloorMovement) zalg.Quat {
        _core_note_floor_movement__inverse_world_rotation_get(self);
        return dequeue_quat();
    }

    pub fn local_position_get(self: *const NoteFloorMovement) zalg.Vec3 {
        _core_note_floor_movement__local_position_get(self);
        return dequeue_vec3();
    }

    pub fn manual_update(self: *const NoteFloorMovement) zalg.Vec3 {
        _core_note_floor_movement__manual_update(self);
        return dequeue_vec3();
    }

    pub fn note_time_get(self: *const NoteFloorMovement) f32 {
        return _core_note_floor_movement__note_time_get(self);
    }

    pub fn set_to_start(self: *const NoteFloorMovement) zalg.Vec3 {
        _core_note_floor_movement__set_to_start(self);
        return dequeue_vec3();
    }

    pub fn should_move(self: *const NoteFloorMovement) bool {
        return _core_note_floor_movement__should_move(self);
    }

    pub fn world_rotation_get(self: *const NoteFloorMovement) zalg.Quat {
        _core_note_floor_movement__world_rotation_get(self);
        return dequeue_quat();
    }
};

pub const NoteJump = struct {
    opaqu: u64,

    pub fn k_missed_time_offset_get() f32 {
        return _core_note_jump__k_missed_time_offset_get();
    }

    pub fn _audio_time_sync_controller_get(self: *const NoteJump) IAudioTimeSource {
        return _core_note_jump___audio_time_sync_controller_get(self);
    }

    pub fn _end_distance_offset_get(self: *const NoteJump) f32 {
        return _core_note_jump___end_distance_offset_get(self);
    }

    pub fn _end_distance_offset_set(self: *const NoteJump, value: f32) void {
        _core_note_jump___end_distance_offset_set(self, value);
    }

    pub fn _end_offset_get(self: *const NoteJump) zalg.Vec3 {
        _core_note_jump___end_offset_get(self);
        return dequeue_vec3();
    }

    pub fn _end_offset_set(self: *const NoteJump, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_note_jump___end_offset_set(self, turing_handle_value);
    }

    pub fn _end_pos_get(self: *const NoteJump) zalg.Vec3 {
        _core_note_jump___end_pos_get(self);
        return dequeue_vec3();
    }

    pub fn _end_pos_set(self: *const NoteJump, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_note_jump___end_pos_set(self, turing_handle_value);
    }

    pub fn _end_rotation_get(self: *const NoteJump) zalg.Quat {
        _core_note_jump___end_rotation_get(self);
        return dequeue_quat();
    }

    pub fn _end_rotation_set(self: *const NoteJump, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _core_note_jump___end_rotation_set(self, turing_handle_value);
    }

    pub fn _gravity_base_get(self: *const NoteJump) f32 {
        return _core_note_jump___gravity_base_get(self);
    }

    pub fn _gravity_base_set(self: *const NoteJump, value: f32) void {
        _core_note_jump___gravity_base_set(self, value);
    }

    pub fn _gravity_get(self: *const NoteJump) f32 {
        return _core_note_jump___gravity_get(self);
    }

    pub fn _gravity_set(self: *const NoteJump, value: f32) void {
        _core_note_jump___gravity_set(self, value);
    }

    pub fn _half_jump_duration_get(self: *const NoteJump) f32 {
        return _core_note_jump___half_jump_duration_get(self);
    }

    pub fn _half_jump_duration_set(self: *const NoteJump, value: f32) void {
        _core_note_jump___half_jump_duration_set(self, value);
    }

    pub fn _half_jump_mark_reported_get(self: *const NoteJump) bool {
        return _core_note_jump___half_jump_mark_reported_get(self);
    }

    pub fn _half_jump_mark_reported_set(self: *const NoteJump, value: bool) void {
        _core_note_jump___half_jump_mark_reported_set(self, value);
    }

    pub fn _inverse_world_rotation_get(self: *const NoteJump) zalg.Quat {
        _core_note_jump___inverse_world_rotation_get(self);
        return dequeue_quat();
    }

    pub fn _inverse_world_rotation_set(self: *const NoteJump, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _core_note_jump___inverse_world_rotation_set(self, turing_handle_value);
    }

    pub fn _jump_duration_get(self: *const NoteJump) f32 {
        return _core_note_jump___jump_duration_get(self);
    }

    pub fn _jump_duration_set(self: *const NoteJump, value: f32) void {
        _core_note_jump___jump_duration_set(self, value);
    }

    pub fn _jump_started_reported_get(self: *const NoteJump) bool {
        return _core_note_jump___jump_started_reported_get(self);
    }

    pub fn _jump_started_reported_set(self: *const NoteJump, value: bool) void {
        _core_note_jump___jump_started_reported_set(self, value);
    }

    pub fn _local_position_get(self: *const NoteJump) zalg.Vec3 {
        _core_note_jump___local_position_get(self);
        return dequeue_vec3();
    }

    pub fn _local_position_set(self: *const NoteJump, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_note_jump___local_position_set(self, turing_handle_value);
    }

    pub fn _middle_rotation_get(self: *const NoteJump) zalg.Quat {
        _core_note_jump___middle_rotation_get(self);
        return dequeue_quat();
    }

    pub fn _middle_rotation_set(self: *const NoteJump, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _core_note_jump___middle_rotation_set(self, turing_handle_value);
    }

    pub fn _missed_mark_reported_get(self: *const NoteJump) bool {
        return _core_note_jump___missed_mark_reported_get(self);
    }

    pub fn _missed_mark_reported_set(self: *const NoteJump, value: bool) void {
        _core_note_jump___missed_mark_reported_set(self, value);
    }

    pub fn _missed_time_get(self: *const NoteJump) f32 {
        return _core_note_jump___missed_time_get(self);
    }

    pub fn _missed_time_set(self: *const NoteJump, value: f32) void {
        _core_note_jump___missed_time_set(self, value);
    }

    pub fn _note_time_get(self: *const NoteJump) f32 {
        return _core_note_jump___note_time_get(self);
    }

    pub fn _note_time_set(self: *const NoteJump, value: f32) void {
        _core_note_jump___note_time_set(self, value);
    }

    pub fn _player_space_convertor_get(self: *const NoteJump) PlayerSpaceConvertor {
        return _core_note_jump___player_space_convertor_get(self);
    }

    pub fn _player_transforms_get(self: *const NoteJump) PlayerTransforms {
        return _core_note_jump___player_transforms_get(self);
    }

    pub fn _rotate_towards_player_get(self: *const NoteJump) bool {
        return _core_note_jump___rotate_towards_player_get(self);
    }

    pub fn _rotate_towards_player_set(self: *const NoteJump, value: bool) void {
        _core_note_jump___rotate_towards_player_set(self, value);
    }

    pub fn _rotated_object_get(self: *const NoteJump) Transform {
        return _core_note_jump___rotated_object_get(self);
    }

    pub fn _rotated_object_set(self: *const NoteJump, value: Transform) void {
        _core_note_jump___rotated_object_set(self, value);
    }

    pub fn _start_offset_get(self: *const NoteJump) zalg.Vec3 {
        _core_note_jump___start_offset_get(self);
        return dequeue_vec3();
    }

    pub fn _start_offset_set(self: *const NoteJump, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_note_jump___start_offset_set(self, turing_handle_value);
    }

    pub fn _start_pos_get(self: *const NoteJump) zalg.Vec3 {
        _core_note_jump___start_pos_get(self);
        return dequeue_vec3();
    }

    pub fn _start_pos_set(self: *const NoteJump, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_note_jump___start_pos_set(self, turing_handle_value);
    }

    pub fn _start_rotation_get(self: *const NoteJump) zalg.Quat {
        _core_note_jump___start_rotation_get(self);
        return dequeue_quat();
    }

    pub fn _start_rotation_set(self: *const NoteJump, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _core_note_jump___start_rotation_set(self, turing_handle_value);
    }

    pub fn _three_quarters_mark_reported_get(self: *const NoteJump) bool {
        return _core_note_jump___three_quarters_mark_reported_get(self);
    }

    pub fn _three_quarters_mark_reported_set(self: *const NoteJump, value: bool) void {
        _core_note_jump___three_quarters_mark_reported_set(self, value);
    }

    pub fn _variable_movement_data_provider_get(self: *const NoteJump) IVariableMovementDataProvider {
        return _core_note_jump___variable_movement_data_provider_get(self);
    }

    pub fn _world_rotation_get(self: *const NoteJump) zalg.Quat {
        _core_note_jump___world_rotation_get(self);
        return dequeue_quat();
    }

    pub fn _world_rotation_set(self: *const NoteJump, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _core_note_jump___world_rotation_set(self, turing_handle_value);
    }

    pub fn _y_avoidance_down_get(self: *const NoteJump) f32 {
        return _core_note_jump___y_avoidance_down_get(self);
    }

    pub fn _y_avoidance_down_set(self: *const NoteJump, value: f32) void {
        _core_note_jump___y_avoidance_down_set(self, value);
    }

    pub fn _y_avoidance_get(self: *const NoteJump) f32 {
        return _core_note_jump___y_avoidance_get(self);
    }

    pub fn _y_avoidance_set(self: *const NoteJump, value: f32) void {
        _core_note_jump___y_avoidance_set(self, value);
    }

    pub fn _y_avoidance_up_get(self: *const NoteJump) f32 {
        return _core_note_jump___y_avoidance_up_get(self);
    }

    pub fn _y_avoidance_up_set(self: *const NoteJump, value: f32) void {
        _core_note_jump___y_avoidance_up_set(self, value);
    }

    pub fn add_note_jump_did_finish_event(self: *const NoteJump, value: Action) void {
        _core_note_jump__add_note_jump_did_finish_event(self, value);
    }

    pub fn add_note_jump_did_pass_half_event(self: *const NoteJump, value: Action) void {
        _core_note_jump__add_note_jump_did_pass_half_event(self, value);
    }

    pub fn add_note_jump_did_pass_missed_marker_event(self: *const NoteJump, value: Action) void {
        _core_note_jump__add_note_jump_did_pass_missed_marker_event(self, value);
    }

    pub fn add_note_jump_did_pass_three_quarters_event(self: *const NoteJump, value: Action1) void {
        _core_note_jump__add_note_jump_did_pass_three_quarters_event(self, value);
    }

    pub fn add_note_jump_did_start_event(self: *const NoteJump, value: Action) void {
        _core_note_jump__add_note_jump_did_start_event(self, value);
    }

    pub fn add_note_jump_did_update_progress_event(self: *const NoteJump, value: Action1) void {
        _core_note_jump__add_note_jump_did_update_progress_event(self, value);
    }

    pub fn beat_pos_get(self: *const NoteJump) zalg.Vec3 {
        _core_note_jump__beat_pos_get(self);
        return dequeue_vec3();
    }

    pub fn distance_to_player_get(self: *const NoteJump) f32 {
        return _core_note_jump__distance_to_player_get(self);
    }

    pub fn init_jump(self: *const NoteJump, note_time: f32, world_rotation: f32, move_end_offset: zalg.Vec3, jump_end_offset: zalg.Vec3, gravity_base: f32, flip_y_side: f32, end_rotation: f32, rotate_towards_player: bool, use_random_rotation: bool) void {
        const turing_handle_move_end_offset = enqueue_vec3(move_end_offset);
        const turing_handle_jump_end_offset = enqueue_vec3(jump_end_offset);
        _core_note_jump__init(self, note_time, world_rotation, turing_handle_move_end_offset, turing_handle_jump_end_offset, gravity_base, flip_y_side, end_rotation, rotate_towards_player, use_random_rotation);
    }

    pub fn local_position_get(self: *const NoteJump) zalg.Vec3 {
        _core_note_jump__local_position_get(self);
        return dequeue_vec3();
    }

    pub fn manual_update(self: *const NoteJump) zalg.Vec3 {
        _core_note_jump__manual_update(self);
        return dequeue_vec3();
    }

    pub fn move_vec_get(self: *const NoteJump) zalg.Vec3 {
        _core_note_jump__move_vec_get(self);
        return dequeue_vec3();
    }

    pub fn note_time_get(self: *const NoteJump) f32 {
        return _core_note_jump__note_time_get(self);
    }

    pub fn remove_note_jump_did_finish_event(self: *const NoteJump, value: Action) void {
        _core_note_jump__remove_note_jump_did_finish_event(self, value);
    }

    pub fn remove_note_jump_did_pass_half_event(self: *const NoteJump, value: Action) void {
        _core_note_jump__remove_note_jump_did_pass_half_event(self, value);
    }

    pub fn remove_note_jump_did_pass_missed_marker_event(self: *const NoteJump, value: Action) void {
        _core_note_jump__remove_note_jump_did_pass_missed_marker_event(self, value);
    }

    pub fn remove_note_jump_did_pass_three_quarters_event(self: *const NoteJump, value: Action1) void {
        _core_note_jump__remove_note_jump_did_pass_three_quarters_event(self, value);
    }

    pub fn remove_note_jump_did_start_event(self: *const NoteJump, value: Action) void {
        _core_note_jump__remove_note_jump_did_start_event(self, value);
    }

    pub fn remove_note_jump_did_update_progress_event(self: *const NoteJump, value: Action1) void {
        _core_note_jump__remove_note_jump_did_update_progress_event(self, value);
    }
};

pub const NoteManager = struct {
    

    pub fn add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: CustomData) CustomNoteData {
        return _core_note_manager__add_bomb_note(beat, line, layer, custom_data);
    }

    pub fn add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: CustomData) CustomNoteData {
        return _core_note_manager__add_color_note(beat, line, layer, color, cut_direction, custom_data);
    }

    pub fn add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: CustomData) CustomObstacleData {
        return _core_note_manager__add_obstacle(beat, duration, line, layer, width, height, custom_data);
    }

    pub fn get_note_controller(n: i32) NoteControllerBase {
        return _core_note_manager__get_note_controller(n);
    }

    pub fn get_note_controller_from_custom(n: CustomNoteData) NoteControllerBase {
        return _core_note_manager__get_note_controller_from_custom(n);
    }

    pub fn get_nth_event(id: i32) CustomEventData {
        return _core_note_manager__get_nth_event(id);
    }

    pub fn get_nth_note(id: i32) CustomNoteData {
        return _core_note_manager__get_nth_note(id);
    }

    pub fn get_nth_object(id: i32) BeatmapDataItem {
        return _core_note_manager__get_nth_object(id);
    }

    pub fn get_nth_obstacle(id: i32) CustomObstacleData {
        return _core_note_manager__get_nth_obstacle(id);
    }

    pub fn get_obstacle_controller(n: i32) ObstacleControllerBase {
        return _core_note_manager__get_obstacle_controller(n);
    }

    pub fn get_obstacle_controller_from_custom(n: CustomObstacleData) ObstacleController {
        return _core_note_manager__get_obstacle_controller_from_custom(n);
    }

    pub fn time_to_beat(time: f32) f32 {
        return _core_note_manager__time_to_beat(time);
    }
};

pub const Object = struct {
    opaqu: u64,
};

pub const ObstacleController = struct {
    opaqu: u64,
};

pub const ObstacleControllerBase = struct {
    opaqu: u64,
};

pub const PlayerSpaceConvertor = struct {
    opaqu: u64,
};

pub const PlayerTransforms = struct {
    opaqu: u64,
};

pub const TaskScheduler = struct {
    opaqu: u64,

    pub fn schedule(task: Action) void {
        _core_task_scheduler__schedule(task);
    }

    pub fn dispose(self: *const TaskScheduler) void {
        _core_task_scheduler__dispose(self);
    }
};

pub const Transform = struct {
    opaqu: u64,

    pub fn broadcast_message(self: *const Transform, method_name: []const u8, parameter: Object, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_transform__broadcast_message(self, turing_handle_method_name.ptr, parameter, options);
    }

    pub fn compare_tag(self: *const Transform, tag: []const u8, allocator: std.mem.Allocator) !bool {
        const turing_handle_tag = try allocator.dupeZ(u8, tag);
        defer allocator.free(turing_handle_tag);
        return _core_transform__compare_tag(self, turing_handle_tag.ptr);
    }

    pub fn detach_children(self: *const Transform) void {
        _core_transform__detach_children(self);
    }

    pub fn find(self: *const Transform, n: []const u8, allocator: std.mem.Allocator) !Transform {
        const turing_handle_n = try allocator.dupeZ(u8, n);
        defer allocator.free(turing_handle_n);
        return _core_transform__find(self, turing_handle_n.ptr);
    }

    pub fn find_child(self: *const Transform, n: []const u8, allocator: std.mem.Allocator) !Transform {
        const turing_handle_n = try allocator.dupeZ(u8, n);
        defer allocator.free(turing_handle_n);
        return _core_transform__find_child(self, turing_handle_n.ptr);
    }

    pub fn get_child(self: *const Transform, index: i32) Transform {
        return _core_transform__get_child(self, index);
    }

    pub fn get_child_count(self: *const Transform) i32 {
        return _core_transform__get_child_count(self);
    }

    pub fn get_child_count_prop(self: *const Transform) i32 {
        return _core_transform__get_child_count_prop(self);
    }

    pub fn get_component_by_name(self: *const Transform, cs_type: []const u8, allocator: std.mem.Allocator) !Component {
        const turing_handle_cs_type = try allocator.dupeZ(u8, cs_type);
        defer allocator.free(turing_handle_cs_type);
        return _core_transform__get_component_by_name(self, turing_handle_cs_type.ptr);
    }

    pub fn get_component_by_type(self: *const Transform, cs_type: Type) Component {
        return _core_transform__get_component_by_type(self, cs_type);
    }

    pub fn get_component_in_children_by_type(self: *const Transform, t: Type, include_inactive: bool) Component {
        return _core_transform__get_component_in_children_by_type(self, t, include_inactive);
    }

    pub fn get_component_in_parent_by_type(self: *const Transform, t: Type, include_inactive: bool) Component {
        return _core_transform__get_component_in_parent_by_type(self, t, include_inactive);
    }

    pub fn get_component_index(self: *const Transform) i32 {
        return _core_transform__get_component_index(self);
    }

    pub fn get_enumerator(self: *const Transform) IEnumerator {
        return _core_transform__get_enumerator(self);
    }

    pub fn get_euler_angles(self: *const Transform) zalg.Vec3 {
        _core_transform__get_euler_angles(self);
        return dequeue_vec3();
    }

    pub fn get_forward(self: *const Transform) zalg.Vec3 {
        _core_transform__get_forward(self);
        return dequeue_vec3();
    }

    pub fn get_game_object(self: *const Transform) GameObject {
        return _core_transform__get_game_object(self);
    }

    pub fn get_has_changed(self: *const Transform) bool {
        return _core_transform__get_has_changed(self);
    }

    pub fn get_hide_flags(self: *const Transform) i32 {
        return _core_transform__get_hide_flags(self);
    }

    pub fn get_hierarchy_capacity(self: *const Transform) i32 {
        return _core_transform__get_hierarchy_capacity(self);
    }

    pub fn get_hierarchy_count(self: *const Transform) i32 {
        return _core_transform__get_hierarchy_count(self);
    }

    pub fn get_instance_id(self: *const Transform) i32 {
        return _core_transform__get_instance_id(self);
    }

    pub fn get_local_euler_angles(self: *const Transform) zalg.Vec3 {
        _core_transform__get_local_euler_angles(self);
        return dequeue_vec3();
    }

    pub fn get_local_position(self: *const Transform) zalg.Vec3 {
        _core_transform__get_local_position(self);
        return dequeue_vec3();
    }

    pub fn get_local_rotation(self: *const Transform) zalg.Quat {
        _core_transform__get_local_rotation(self);
        return dequeue_quat();
    }

    pub fn get_local_scale(self: *const Transform) zalg.Vec3 {
        _core_transform__get_local_scale(self);
        return dequeue_vec3();
    }

    pub fn get_local_to_world_matrix(self: *const Transform) zalg.Mat4 {
        _core_transform__get_local_to_world_matrix(self);
        return dequeue_mat4();
    }

    pub fn get_lossy_scale(self: *const Transform) zalg.Vec3 {
        _core_transform__get_lossy_scale(self);
        return dequeue_vec3();
    }

    pub fn get_name(self: *const Transform, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_transform__get_name(self);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }

    pub fn get_parent(self: *const Transform) Transform {
        return _core_transform__get_parent(self);
    }

    pub fn get_position(self: *const Transform) zalg.Vec3 {
        _core_transform__get_position(self);
        return dequeue_vec3();
    }

    pub fn get_right(self: *const Transform) zalg.Vec3 {
        _core_transform__get_right(self);
        return dequeue_vec3();
    }

    pub fn get_root(self: *const Transform) Transform {
        return _core_transform__get_root(self);
    }

    pub fn get_rotation(self: *const Transform) zalg.Quat {
        _core_transform__get_rotation(self);
        return dequeue_quat();
    }

    pub fn get_sibling_index(self: *const Transform) i32 {
        return _core_transform__get_sibling_index(self);
    }

    pub fn get_tag(self: *const Transform, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_transform__get_tag(self);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }

    pub fn get_up(self: *const Transform) zalg.Vec3 {
        _core_transform__get_up(self);
        return dequeue_vec3();
    }

    pub fn get_world_to_local_matrix(self: *const Transform) zalg.Mat4 {
        _core_transform__get_world_to_local_matrix(self);
        return dequeue_mat4();
    }

    pub fn inverse_transform_direction(self: *const Transform, direction: zalg.Vec3) zalg.Vec3 {
        const turing_handle_direction = enqueue_vec3(direction);
        _core_transform__inverse_transform_direction(self, turing_handle_direction);
        return dequeue_vec3();
    }

    pub fn inverse_transform_point(self: *const Transform, position: zalg.Vec3) zalg.Vec3 {
        const turing_handle_position = enqueue_vec3(position);
        _core_transform__inverse_transform_point(self, turing_handle_position);
        return dequeue_vec3();
    }

    pub fn inverse_transform_vector(self: *const Transform, vector: zalg.Vec3) zalg.Vec3 {
        const turing_handle_vector = enqueue_vec3(vector);
        _core_transform__inverse_transform_vector(self, turing_handle_vector);
        return dequeue_vec3();
    }

    pub fn is_child_of(self: *const Transform, parent: Transform) bool {
        return _core_transform__is_child_of(self, parent);
    }

    pub fn look_at(self: *const Transform, target: Transform, world_up: zalg.Vec3) void {
        const turing_handle_world_up = enqueue_vec3(world_up);
        _core_transform__look_at(self, target, turing_handle_world_up);
    }

    pub fn rotate(self: *const Transform, eulers: zalg.Vec3) void {
        const turing_handle_eulers = enqueue_vec3(eulers);
        _core_transform__rotate(self, turing_handle_eulers);
    }

    pub fn rotate_around(self: *const Transform, point: zalg.Vec3, axis: zalg.Vec3, angle: f32) void {
        const turing_handle_point = enqueue_vec3(point);
        const turing_handle_axis = enqueue_vec3(axis);
        _core_transform__rotate_around(self, turing_handle_point, turing_handle_axis, angle);
    }

    pub fn rotate_around_local(self: *const Transform, axis: zalg.Vec3, angle: f32) void {
        const turing_handle_axis = enqueue_vec3(axis);
        _core_transform__rotate_around_local(self, turing_handle_axis, angle);
    }

    pub fn rotate_relative(self: *const Transform, eulers: zalg.Vec3, relative_to: i32) void {
        const turing_handle_eulers = enqueue_vec3(eulers);
        _core_transform__rotate_relative(self, turing_handle_eulers, relative_to);
    }

    pub fn send_message(self: *const Transform, method_name: []const u8, value: Object, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_transform__send_message(self, turing_handle_method_name.ptr, value, options);
    }

    pub fn send_message_upwards(self: *const Transform, method_name: []const u8, value: Object, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_transform__send_message_upwards(self, turing_handle_method_name.ptr, value, options);
    }

    pub fn set_as_first_sibling(self: *const Transform) void {
        _core_transform__set_as_first_sibling(self);
    }

    pub fn set_as_last_sibling(self: *const Transform) void {
        _core_transform__set_as_last_sibling(self);
    }

    pub fn set_euler_angles(self: *const Transform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_transform__set_euler_angles(self, turing_handle_value);
    }

    pub fn set_forward(self: *const Transform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_transform__set_forward(self, turing_handle_value);
    }

    pub fn set_has_changed(self: *const Transform, value: bool) void {
        _core_transform__set_has_changed(self, value);
    }

    pub fn set_hide_flags(self: *const Transform, value: i32) void {
        _core_transform__set_hide_flags(self, value);
    }

    pub fn set_hierarchy_capacity(self: *const Transform, value: i32) void {
        _core_transform__set_hierarchy_capacity(self, value);
    }

    pub fn set_local_euler_angles(self: *const Transform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_transform__set_local_euler_angles(self, turing_handle_value);
    }

    pub fn set_local_position(self: *const Transform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_transform__set_local_position(self, turing_handle_value);
    }

    pub fn set_local_position_and_rotation(self: *const Transform, local_position: zalg.Vec3, local_rotation: zalg.Quat) void {
        const turing_handle_local_position = enqueue_vec3(local_position);
        const turing_handle_local_rotation = enqueue_quat(local_rotation);
        _core_transform__set_local_position_and_rotation(self, turing_handle_local_position, turing_handle_local_rotation);
    }

    pub fn set_local_rotation(self: *const Transform, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _core_transform__set_local_rotation(self, turing_handle_value);
    }

    pub fn set_local_scale(self: *const Transform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_transform__set_local_scale(self, turing_handle_value);
    }

    pub fn set_name(self: *const Transform, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _core_transform__set_name(self, turing_handle_value.ptr);
    }

    pub fn set_parent(self: *const Transform, parent: Transform, world_position_stays: bool) void {
        _core_transform__set_parent(self, parent, world_position_stays);
    }

    pub fn set_position(self: *const Transform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_transform__set_position(self, turing_handle_value);
    }

    pub fn set_position_and_rotation(self: *const Transform, position: zalg.Vec3, rotation: zalg.Quat) void {
        const turing_handle_position = enqueue_vec3(position);
        const turing_handle_rotation = enqueue_quat(rotation);
        _core_transform__set_position_and_rotation(self, turing_handle_position, turing_handle_rotation);
    }

    pub fn set_right(self: *const Transform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_transform__set_right(self, turing_handle_value);
    }

    pub fn set_rotation(self: *const Transform, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _core_transform__set_rotation(self, turing_handle_value);
    }

    pub fn set_sibling_index(self: *const Transform, index: i32) void {
        _core_transform__set_sibling_index(self, index);
    }

    pub fn set_tag(self: *const Transform, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _core_transform__set_tag(self, turing_handle_value.ptr);
    }

    pub fn set_up(self: *const Transform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_transform__set_up(self, turing_handle_value);
    }

    pub fn transform_direction(self: *const Transform, direction: zalg.Vec3) zalg.Vec3 {
        const turing_handle_direction = enqueue_vec3(direction);
        _core_transform__transform_direction(self, turing_handle_direction);
        return dequeue_vec3();
    }

    pub fn transform_point(self: *const Transform, position: zalg.Vec3) zalg.Vec3 {
        const turing_handle_position = enqueue_vec3(position);
        _core_transform__transform_point(self, turing_handle_position);
        return dequeue_vec3();
    }

    pub fn transform_vector(self: *const Transform, vector: zalg.Vec3) zalg.Vec3 {
        const turing_handle_vector = enqueue_vec3(vector);
        _core_transform__transform_vector(self, turing_handle_vector);
        return dequeue_vec3();
    }

    pub fn translate(self: *const Transform, translation: zalg.Vec3, relative_to: i32) void {
        const turing_handle_translation = enqueue_vec3(translation);
        _core_transform__translate(self, turing_handle_translation, relative_to);
    }

    pub fn translate_relative(self: *const Transform, translation: zalg.Vec3, relative_to: Transform) void {
        const turing_handle_translation = enqueue_vec3(translation);
        _core_transform__translate_relative(self, turing_handle_translation, relative_to);
    }
};

pub const TuringMesh = struct {
    opaqu: u64,

    pub fn _mesh_get(self: *const TuringMesh) Mesh {
        return _core_turing_mesh___mesh_get(self);
    }

    pub fn _mesh_set(self: *const TuringMesh, value: Mesh) void {
        _core_turing_mesh___mesh_set(self, value);
    }

    pub fn clear(self: *const TuringMesh) void {
        _core_turing_mesh__clear(self);
    }

    pub fn get_bounds_max_x(self: *const TuringMesh) f32 {
        return _core_turing_mesh__get_bounds_max_x(self);
    }

    pub fn get_bounds_max_y(self: *const TuringMesh) f32 {
        return _core_turing_mesh__get_bounds_max_y(self);
    }

    pub fn get_bounds_max_z(self: *const TuringMesh) f32 {
        return _core_turing_mesh__get_bounds_max_z(self);
    }

    pub fn get_bounds_min_x(self: *const TuringMesh) f32 {
        return _core_turing_mesh__get_bounds_min_x(self);
    }

    pub fn get_bounds_min_y(self: *const TuringMesh) f32 {
        return _core_turing_mesh__get_bounds_min_y(self);
    }

    pub fn get_bounds_min_z(self: *const TuringMesh) f32 {
        return _core_turing_mesh__get_bounds_min_z(self);
    }

    pub fn get_instance_id(self: *const TuringMesh) i32 {
        return _core_turing_mesh__get_instance_id(self);
    }

    pub fn get_u_vs(self: *const TuringMesh, channel: i32, allocator: std.mem.Allocator) ![]u32 {
        const turing_result = _core_turing_mesh__get_u_vs(self, channel);
        const turing_buf = try allocator.alloc(u32, turing_result);
        _host_bufcpy(turing_buf.ptr, turing_result);
        return turing_buf;
    }

    pub fn get_vertices(self: *const TuringMesh, allocator: std.mem.Allocator) ![]u32 {
        const turing_result = _core_turing_mesh__get_vertices(self);
        const turing_buf = try allocator.alloc(u32, turing_result);
        _host_bufcpy(turing_buf.ptr, turing_result);
        return turing_buf;
    }

    pub fn hide_flags_get(self: *const TuringMesh) void {
        _core_turing_mesh__hide_flags_get(self);
    }

    pub fn hide_flags_set(self: *const TuringMesh) void {
        _core_turing_mesh__hide_flags_set(self);
    }

    pub fn mark_modified(self: *const TuringMesh) void {
        _core_turing_mesh__mark_modified(self);
    }

    pub fn name_get(self: *const TuringMesh, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_turing_mesh__name_get(self);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }

    pub fn name_set(self: *const TuringMesh, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _core_turing_mesh__name_set(self, turing_handle_value.ptr);
    }

    pub fn optimize(self: *const TuringMesh) void {
        _core_turing_mesh__optimize(self);
    }

    pub fn optimize_index_buffers(self: *const TuringMesh) void {
        _core_turing_mesh__optimize_index_buffers(self);
    }

    pub fn recalculate_bounds(self: *const TuringMesh) void {
        _core_turing_mesh__recalculate_bounds(self);
    }

    pub fn recalculate_normals(self: *const TuringMesh) void {
        _core_turing_mesh__recalculate_normals(self);
    }

    pub fn recalculate_tangents(self: *const TuringMesh) void {
        _core_turing_mesh__recalculate_tangents(self);
    }

    pub fn set_bounds(self: *const TuringMesh, min_x: f32, min_y: f32, min_z: f32, max_x: f32, max_y: f32, max_z: f32) void {
        _core_turing_mesh__set_bounds(self, min_x, min_y, min_z, max_x, max_y, max_z);
    }

    pub fn set_triangles(self: *const TuringMesh, triangles: Int32, submesh: i32, calculate_bounds: bool, base_vertex: i32) void {
        _core_turing_mesh__set_triangles(self, triangles, submesh, calculate_bounds, base_vertex);
    }

    pub fn set_u_vs(self: *const TuringMesh, channel: i32, uvs: []const u32) void {
        _host_u32_enqueue(@intCast(uvs.len));
        _core_turing_mesh__set_u_vs(self, channel, uvs.ptr);
    }

    pub fn set_vertices(self: *const TuringMesh, in_vertices: []const u32) void {
        _host_u32_enqueue(@intCast(in_vertices.len));
        _core_turing_mesh__set_vertices(self, in_vertices.ptr);
    }

    pub fn upload_mesh_data(self: *const TuringMesh, mark_no_longer_readable: bool) void {
        _core_turing_mesh__upload_mesh_data(self, mark_no_longer_readable);
    }
};

pub const TuringNoteExtensions = struct {
    

    pub fn get_note_floor_movement(note_controller: NoteController) NoteFloorMovement {
        return _core_turing_note_extensions__get_note_floor_movement(note_controller);
    }

    pub fn get_note_jump(note_controller: NoteController) NoteJump {
        return _core_turing_note_extensions__get_note_jump(note_controller);
    }
};

pub const TuringScriptManager = struct {
    opaqu: u64,
};

pub const TuringerGameObjectManager = struct {
    opaqu: u64,

    pub fn create_object(name: []const u8, allocator: std.mem.Allocator) !GameObject {
        const turing_handle_name = try allocator.dupeZ(u8, name);
        defer allocator.free(turing_handle_name);
        return _core_turinger_game_object_manager__create_object(turing_handle_name.ptr);
    }

    pub fn destroy_object(game_object: GameObject) void {
        _core_turinger_game_object_manager__destroy_object(game_object);
    }

    pub fn find(name: []const u8, allocator: std.mem.Allocator) !GameObject {
        const turing_handle_name = try allocator.dupeZ(u8, name);
        defer allocator.free(turing_handle_name);
        return _core_turinger_game_object_manager__find(turing_handle_name.ptr);
    }

    pub fn instance_get(self: *const TuringerGameObjectManager) TuringerGameObjectManager {
        return _core_turinger_game_object_manager__instance_get(self);
    }
};

pub const Type = struct {
    opaqu: u64,
};

pub const Version = struct {
    opaqu: u64,
};

pub const Xr = struct {
    opaqu: u64,

    pub fn get_device_battery_level(node_int: i32) f32 {
        return _core_xr__get_device_battery_level(node_int);
    }

    pub fn get_device_grip_value(node_int: i32) f32 {
        return _core_xr__get_device_grip_value(node_int);
    }

    pub fn get_device_name(node_int: i32, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_xr__get_device_name(node_int);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }

    pub fn get_device_primary_button_state(node_int: i32) bool {
        return _core_xr__get_device_primary_button_state(node_int);
    }

    pub fn get_device_secondary_button_state(node_int: i32) bool {
        return _core_xr__get_device_secondary_button_state(node_int);
    }

    pub fn get_device_thumbstick(node_int: i32) zalg.Vec2 {
        _core_xr__get_device_thumbstick(node_int);
        return dequeue_vec2();
    }

    pub fn get_device_touchpad(node_int: i32) zalg.Vec2 {
        _core_xr__get_device_touchpad(node_int);
        return dequeue_vec2();
    }

    pub fn get_device_tracking_state(node_int: i32) i32 {
        return _core_xr__get_device_tracking_state(node_int);
    }

    pub fn get_device_trigger_value(node_int: i32) f32 {
        return _core_xr__get_device_trigger_value(node_int);
    }

    pub fn is_device_valid(node_int: i32) bool {
        return _core_xr__is_device_valid(node_int);
    }

    pub fn send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32) void {
        _core_xr__send_haptic_impulse(node_int, amplitude, duration);
    }

    pub fn stop_haptics(node_int: i32) void {
        _core_xr__stop_haptics(node_int);
    }

    pub fn _manager_get(self: *const Xr) TuringScriptManager {
        return _core_xr___manager_get(self);
    }
};















