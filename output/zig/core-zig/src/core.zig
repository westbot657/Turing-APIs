
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
extern "C" fn _core_turinger_game_object__active_get(handle: TuringerGameObject) bool;
extern "C" fn _core_turinger_game_object__active_in_hierarchy_get(handle: TuringerGameObject) bool;
extern "C" fn _core_turinger_game_object__active_self_get(handle: TuringerGameObject) bool;
extern "C" fn _core_turinger_game_object__active_set(handle: TuringerGameObject, value: bool) void;
extern "C" fn _core_turinger_game_object__add_component(handle: TuringerGameObject, component_type: Type) Component;
extern "C" fn _core_turinger_game_object__add_or_get_mesh(handle: TuringerGameObject) TuringMesh;
extern "C" fn _core_turinger_game_object__broadcast_message(handle: TuringerGameObject, method_name: [*c]const u8, options: i32) void;
extern "C" fn _core_turinger_game_object__compare_tag(handle: TuringerGameObject, tag: [*c]const u8) bool;
extern "C" fn _core_turinger_game_object__game_object_get(handle: TuringerGameObject) GameObject;
extern "C" fn _core_turinger_game_object__get_component_at_index(handle: TuringerGameObject, index: i32) Component;
extern "C" fn _core_turinger_game_object__get_component_by_name(handle: TuringerGameObject, cs_type: [*c]const u8) Component;
extern "C" fn _core_turinger_game_object__get_component_by_type(handle: TuringerGameObject, cs_type: Type) Component;
extern "C" fn _core_turinger_game_object__get_component_count(handle: TuringerGameObject) i32;
extern "C" fn _core_turinger_game_object__get_component_in_children_by_type(handle: TuringerGameObject, cs_type: Type, include_inactive: bool) Component;
extern "C" fn _core_turinger_game_object__get_component_in_parent_by_type(handle: TuringerGameObject, cs_type: Type, include_inactive: bool) Component;
extern "C" fn _core_turinger_game_object__get_component_index(handle: TuringerGameObject, component: Component) i32;
extern "C" fn _core_turinger_game_object__get_instance_id(handle: TuringerGameObject) i32;
extern "C" fn _core_turinger_game_object__hide_flags_get(handle: TuringerGameObject) i32;
extern "C" fn _core_turinger_game_object__hide_flags_set(handle: TuringerGameObject, value: i32) void;
extern "C" fn _core_turinger_game_object__is_static_get(handle: TuringerGameObject) bool;
extern "C" fn _core_turinger_game_object__is_static_set(handle: TuringerGameObject, value: bool) void;
extern "C" fn _core_turinger_game_object__layer_get(handle: TuringerGameObject) i32;
extern "C" fn _core_turinger_game_object__layer_set(handle: TuringerGameObject, value: i32) void;
extern "C" fn _core_turinger_game_object__name_get(handle: TuringerGameObject) u32;
extern "C" fn _core_turinger_game_object__name_set(handle: TuringerGameObject, value: [*c]const u8) void;
extern "C" fn _core_turinger_game_object__scene_culling_mask_get(handle: TuringerGameObject) u64;
extern "C" fn _core_turinger_game_object__send_message(handle: TuringerGameObject, method_name: [*c]const u8, options: i32) void;
extern "C" fn _core_turinger_game_object__send_message_upwards(handle: TuringerGameObject, method_name: [*c]const u8, options: i32) void;
extern "C" fn _core_turinger_game_object__set_active(handle: TuringerGameObject, value: bool) void;
extern "C" fn _core_turinger_game_object__set_active_recursively(handle: TuringerGameObject, state: bool) void;
extern "C" fn _core_turinger_game_object__tag_get(handle: TuringerGameObject) u32;
extern "C" fn _core_turinger_game_object__tag_set(handle: TuringerGameObject, value: [*c]const u8) void;
extern "C" fn _core_turinger_game_object__transform_get(handle: TuringerGameObject) TuringerTransform;
extern "C" fn _core_turinger_game_object_manager__create_object(name: [*c]const u8) TuringerGameObject;
extern "C" fn _core_turinger_game_object_manager__destroy_object(listener: TuringerGameObject) void;
extern "C" fn _core_turinger_game_object_manager__find(name: [*c]const u8) TuringerGameObject;
extern "C" fn _core_turinger_game_object_manager__instance_get(handle: TuringerGameObjectManager) TuringerGameObjectManager;
extern "C" fn _core_turinger_transform__broadcast_message(handle: TuringerTransform, method_name: [*c]const u8, parameter: Object, options: i32) void;
extern "C" fn _core_turinger_transform__child_count_get(handle: TuringerTransform) i32;
extern "C" fn _core_turinger_transform__compare_tag(handle: TuringerTransform, tag: [*c]const u8) bool;
extern "C" fn _core_turinger_transform__detach_children(handle: TuringerTransform) void;
extern "C" fn _core_turinger_transform__euler_angles_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__euler_angles_set(handle: TuringerTransform, value: u32) void;
extern "C" fn _core_turinger_transform__find(handle: TuringerTransform, n: [*c]const u8) TuringerTransform;
extern "C" fn _core_turinger_transform__find_child(handle: TuringerTransform, n: [*c]const u8) TuringerTransform;
extern "C" fn _core_turinger_transform__forward_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__forward_set(handle: TuringerTransform, value: u32) void;
extern "C" fn _core_turinger_transform__game_object_get(handle: TuringerTransform) TuringerGameObject;
extern "C" fn _core_turinger_transform__get_child(handle: TuringerTransform, index: i32) TuringerTransform;
extern "C" fn _core_turinger_transform__get_child_count(handle: TuringerTransform) i32;
extern "C" fn _core_turinger_transform__get_component_by_name(handle: TuringerTransform, cs_type: [*c]const u8) Component;
extern "C" fn _core_turinger_transform__get_component_by_type(handle: TuringerTransform, cs_type: Type) Component;
extern "C" fn _core_turinger_transform__get_component_in_children_by_type(handle: TuringerTransform, t: Type, include_inactive: bool) Component;
extern "C" fn _core_turinger_transform__get_component_in_parent_by_type(handle: TuringerTransform, t: Type, include_inactive: bool) Component;
extern "C" fn _core_turinger_transform__get_component_index(handle: TuringerTransform) i32;
extern "C" fn _core_turinger_transform__get_enumerator(handle: TuringerTransform) IEnumerator;
extern "C" fn _core_turinger_transform__get_instance_id(handle: TuringerTransform) i32;
extern "C" fn _core_turinger_transform__get_sibling_index(handle: TuringerTransform) i32;
extern "C" fn _core_turinger_transform__has_changed_get(handle: TuringerTransform) bool;
extern "C" fn _core_turinger_transform__has_changed_set(handle: TuringerTransform, value: bool) void;
extern "C" fn _core_turinger_transform__hide_flags_get(handle: TuringerTransform) i32;
extern "C" fn _core_turinger_transform__hide_flags_set(handle: TuringerTransform, value: i32) void;
extern "C" fn _core_turinger_transform__hierarchy_capacity_get(handle: TuringerTransform) i32;
extern "C" fn _core_turinger_transform__hierarchy_capacity_set(handle: TuringerTransform, value: i32) void;
extern "C" fn _core_turinger_transform__hierarchy_count_get(handle: TuringerTransform) i32;
extern "C" fn _core_turinger_transform__inverse_transform_direction(handle: TuringerTransform, direction: u32) u32;
extern "C" fn _core_turinger_transform__inverse_transform_point(handle: TuringerTransform, position: u32) u32;
extern "C" fn _core_turinger_transform__inverse_transform_vector(handle: TuringerTransform, vector: u32) u32;
extern "C" fn _core_turinger_transform__is_child_of(handle: TuringerTransform, parent: TuringerTransform) bool;
extern "C" fn _core_turinger_transform__local_euler_angles_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__local_euler_angles_set(handle: TuringerTransform, value: u32) void;
extern "C" fn _core_turinger_transform__local_position_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__local_position_set(handle: TuringerTransform, value: u32) void;
extern "C" fn _core_turinger_transform__local_rotation_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__local_rotation_set(handle: TuringerTransform, value: u32) void;
extern "C" fn _core_turinger_transform__local_scale_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__local_scale_set(handle: TuringerTransform, value: u32) void;
extern "C" fn _core_turinger_transform__local_to_world_matrix_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__look_at(handle: TuringerTransform, target: TuringerTransform, world_up: u32) void;
extern "C" fn _core_turinger_transform__lossy_scale_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__name_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__name_set(handle: TuringerTransform, value: [*c]const u8) void;
extern "C" fn _core_turinger_transform__parent_get(handle: TuringerTransform) TuringerTransform;
extern "C" fn _core_turinger_transform__parent_set(handle: TuringerTransform, value: TuringerTransform) void;
extern "C" fn _core_turinger_transform__position_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__position_set(handle: TuringerTransform, value: u32) void;
extern "C" fn _core_turinger_transform__right_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__right_set(handle: TuringerTransform, value: u32) void;
extern "C" fn _core_turinger_transform__root_get(handle: TuringerTransform) TuringerTransform;
extern "C" fn _core_turinger_transform__rotate(handle: TuringerTransform, eulers: u32) void;
extern "C" fn _core_turinger_transform__rotate_around(handle: TuringerTransform, point: u32, axis: u32, angle: f32) void;
extern "C" fn _core_turinger_transform__rotate_around_local(handle: TuringerTransform, axis: u32, angle: f32) void;
extern "C" fn _core_turinger_transform__rotate_relative(handle: TuringerTransform, eulers: u32, relative_to: i32) void;
extern "C" fn _core_turinger_transform__rotation_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__rotation_set(handle: TuringerTransform, value: u32) void;
extern "C" fn _core_turinger_transform__send_message(handle: TuringerTransform, method_name: [*c]const u8, value: Object, options: i32) void;
extern "C" fn _core_turinger_transform__send_message_upwards(handle: TuringerTransform, method_name: [*c]const u8, value: Object, options: i32) void;
extern "C" fn _core_turinger_transform__set_as_first_sibling(handle: TuringerTransform) void;
extern "C" fn _core_turinger_transform__set_as_last_sibling(handle: TuringerTransform) void;
extern "C" fn _core_turinger_transform__set_local_position_and_rotation(handle: TuringerTransform, local_position: u32, local_rotation: u32) void;
extern "C" fn _core_turinger_transform__set_parent(handle: TuringerTransform, parent: TuringerTransform, world_position_stays: bool) void;
extern "C" fn _core_turinger_transform__set_position_and_rotation(handle: TuringerTransform, position: u32, rotation: u32) void;
extern "C" fn _core_turinger_transform__set_sibling_index(handle: TuringerTransform, index: i32) void;
extern "C" fn _core_turinger_transform__tag_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__tag_set(handle: TuringerTransform, value: [*c]const u8) void;
extern "C" fn _core_turinger_transform__transform_direction(handle: TuringerTransform, direction: u32) u32;
extern "C" fn _core_turinger_transform__transform_get(handle: TuringerTransform) Transform;
extern "C" fn _core_turinger_transform__transform_point(handle: TuringerTransform, position: u32) u32;
extern "C" fn _core_turinger_transform__transform_vector(handle: TuringerTransform, vector: u32) u32;
extern "C" fn _core_turinger_transform__translate(handle: TuringerTransform, translation: u32, relative_to: i32) void;
extern "C" fn _core_turinger_transform__translate_relative(handle: TuringerTransform, translation: u32, relative_to: TuringerTransform) void;
extern "C" fn _core_turinger_transform__up_get(handle: TuringerTransform) u32;
extern "C" fn _core_turinger_transform__up_set(handle: TuringerTransform, value: u32) void;
extern "C" fn _core_turinger_transform__world_to_local_matrix_get(handle: TuringerTransform) u32;
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

    pub fn init_note(self: *const NoteJump, note_time: f32, world_rotation: f32, move_end_offset: zalg.Vec3, jump_end_offset: zalg.Vec3, gravity_base: f32, flip_y_side: f32, end_rotation: f32, rotate_towards_player: bool, use_random_rotation: bool) void {
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

pub const TuringScriptManager = struct {
    opaqu: u64,
};

pub const TuringerGameObject = struct {
    opaqu: u64,

    pub fn active_get(self: *const TuringerGameObject) bool {
        return _core_turinger_game_object__active_get(self);
    }

    pub fn active_in_hierarchy_get(self: *const TuringerGameObject) bool {
        return _core_turinger_game_object__active_in_hierarchy_get(self);
    }

    pub fn active_self_get(self: *const TuringerGameObject) bool {
        return _core_turinger_game_object__active_self_get(self);
    }

    pub fn active_set(self: *const TuringerGameObject, value: bool) void {
        _core_turinger_game_object__active_set(self, value);
    }

    pub fn add_component(self: *const TuringerGameObject, component_type: Type) Component {
        return _core_turinger_game_object__add_component(self, component_type);
    }

    pub fn add_or_get_mesh(self: *const TuringerGameObject) TuringMesh {
        return _core_turinger_game_object__add_or_get_mesh(self);
    }

    pub fn broadcast_message(self: *const TuringerGameObject, method_name: []const u8, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_turinger_game_object__broadcast_message(self, turing_handle_method_name.ptr, options);
    }

    pub fn compare_tag(self: *const TuringerGameObject, tag: []const u8, allocator: std.mem.Allocator) !bool {
        const turing_handle_tag = try allocator.dupeZ(u8, tag);
        defer allocator.free(turing_handle_tag);
        return _core_turinger_game_object__compare_tag(self, turing_handle_tag.ptr);
    }

    pub fn game_object_get(self: *const TuringerGameObject) GameObject {
        return _core_turinger_game_object__game_object_get(self);
    }

    pub fn get_component_at_index(self: *const TuringerGameObject, index: i32) Component {
        return _core_turinger_game_object__get_component_at_index(self, index);
    }

    pub fn get_component_by_name(self: *const TuringerGameObject, cs_type: []const u8, allocator: std.mem.Allocator) !Component {
        const turing_handle_cs_type = try allocator.dupeZ(u8, cs_type);
        defer allocator.free(turing_handle_cs_type);
        return _core_turinger_game_object__get_component_by_name(self, turing_handle_cs_type.ptr);
    }

    pub fn get_component_by_type(self: *const TuringerGameObject, cs_type: Type) Component {
        return _core_turinger_game_object__get_component_by_type(self, cs_type);
    }

    pub fn get_component_count(self: *const TuringerGameObject) i32 {
        return _core_turinger_game_object__get_component_count(self);
    }

    pub fn get_component_in_children_by_type(self: *const TuringerGameObject, cs_type: Type, include_inactive: bool) Component {
        return _core_turinger_game_object__get_component_in_children_by_type(self, cs_type, include_inactive);
    }

    pub fn get_component_in_parent_by_type(self: *const TuringerGameObject, cs_type: Type, include_inactive: bool) Component {
        return _core_turinger_game_object__get_component_in_parent_by_type(self, cs_type, include_inactive);
    }

    pub fn get_component_index(self: *const TuringerGameObject, component: Component) i32 {
        return _core_turinger_game_object__get_component_index(self, component);
    }

    pub fn get_instance_id(self: *const TuringerGameObject) i32 {
        return _core_turinger_game_object__get_instance_id(self);
    }

    pub fn hide_flags_get(self: *const TuringerGameObject) i32 {
        return _core_turinger_game_object__hide_flags_get(self);
    }

    pub fn hide_flags_set(self: *const TuringerGameObject, value: i32) void {
        _core_turinger_game_object__hide_flags_set(self, value);
    }

    pub fn is_static_get(self: *const TuringerGameObject) bool {
        return _core_turinger_game_object__is_static_get(self);
    }

    pub fn is_static_set(self: *const TuringerGameObject, value: bool) void {
        _core_turinger_game_object__is_static_set(self, value);
    }

    pub fn layer_get(self: *const TuringerGameObject) i32 {
        return _core_turinger_game_object__layer_get(self);
    }

    pub fn layer_set(self: *const TuringerGameObject, value: i32) void {
        _core_turinger_game_object__layer_set(self, value);
    }

    pub fn name_get(self: *const TuringerGameObject, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_turinger_game_object__name_get(self);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }

    pub fn name_set(self: *const TuringerGameObject, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _core_turinger_game_object__name_set(self, turing_handle_value.ptr);
    }

    pub fn scene_culling_mask_get(self: *const TuringerGameObject) u64 {
        return _core_turinger_game_object__scene_culling_mask_get(self);
    }

    pub fn send_message(self: *const TuringerGameObject, method_name: []const u8, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_turinger_game_object__send_message(self, turing_handle_method_name.ptr, options);
    }

    pub fn send_message_upwards(self: *const TuringerGameObject, method_name: []const u8, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_turinger_game_object__send_message_upwards(self, turing_handle_method_name.ptr, options);
    }

    pub fn set_active(self: *const TuringerGameObject, value: bool) void {
        _core_turinger_game_object__set_active(self, value);
    }

    pub fn set_active_recursively(self: *const TuringerGameObject, state: bool) void {
        _core_turinger_game_object__set_active_recursively(self, state);
    }

    pub fn tag_get(self: *const TuringerGameObject, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_turinger_game_object__tag_get(self);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }

    pub fn tag_set(self: *const TuringerGameObject, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _core_turinger_game_object__tag_set(self, turing_handle_value.ptr);
    }

    pub fn transform_get(self: *const TuringerGameObject) TuringerTransform {
        return _core_turinger_game_object__transform_get(self);
    }
};

pub const TuringerGameObjectManager = struct {
    opaqu: u64,

    pub fn create_object(name: []const u8, allocator: std.mem.Allocator) !TuringerGameObject {
        const turing_handle_name = try allocator.dupeZ(u8, name);
        defer allocator.free(turing_handle_name);
        return _core_turinger_game_object_manager__create_object(turing_handle_name.ptr);
    }

    pub fn destroy_object(listener: TuringerGameObject) void {
        _core_turinger_game_object_manager__destroy_object(listener);
    }

    pub fn find(name: []const u8, allocator: std.mem.Allocator) !TuringerGameObject {
        const turing_handle_name = try allocator.dupeZ(u8, name);
        defer allocator.free(turing_handle_name);
        return _core_turinger_game_object_manager__find(turing_handle_name.ptr);
    }

    pub fn instance_get(self: *const TuringerGameObjectManager) TuringerGameObjectManager {
        return _core_turinger_game_object_manager__instance_get(self);
    }
};

pub const TuringerTransform = struct {
    opaqu: u64,

    pub fn broadcast_message(self: *const TuringerTransform, method_name: []const u8, parameter: Object, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_turinger_transform__broadcast_message(self, turing_handle_method_name.ptr, parameter, options);
    }

    pub fn child_count_get(self: *const TuringerTransform) i32 {
        return _core_turinger_transform__child_count_get(self);
    }

    pub fn compare_tag(self: *const TuringerTransform, tag: []const u8, allocator: std.mem.Allocator) !bool {
        const turing_handle_tag = try allocator.dupeZ(u8, tag);
        defer allocator.free(turing_handle_tag);
        return _core_turinger_transform__compare_tag(self, turing_handle_tag.ptr);
    }

    pub fn detach_children(self: *const TuringerTransform) void {
        _core_turinger_transform__detach_children(self);
    }

    pub fn euler_angles_get(self: *const TuringerTransform) zalg.Vec3 {
        _core_turinger_transform__euler_angles_get(self);
        return dequeue_vec3();
    }

    pub fn euler_angles_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_turinger_transform__euler_angles_set(self, turing_handle_value);
    }

    pub fn find(self: *const TuringerTransform, n: []const u8, allocator: std.mem.Allocator) !TuringerTransform {
        const turing_handle_n = try allocator.dupeZ(u8, n);
        defer allocator.free(turing_handle_n);
        return _core_turinger_transform__find(self, turing_handle_n.ptr);
    }

    pub fn find_child(self: *const TuringerTransform, n: []const u8, allocator: std.mem.Allocator) !TuringerTransform {
        const turing_handle_n = try allocator.dupeZ(u8, n);
        defer allocator.free(turing_handle_n);
        return _core_turinger_transform__find_child(self, turing_handle_n.ptr);
    }

    pub fn forward_get(self: *const TuringerTransform) zalg.Vec3 {
        _core_turinger_transform__forward_get(self);
        return dequeue_vec3();
    }

    pub fn forward_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_turinger_transform__forward_set(self, turing_handle_value);
    }

    pub fn game_object_get(self: *const TuringerTransform) TuringerGameObject {
        return _core_turinger_transform__game_object_get(self);
    }

    pub fn get_child(self: *const TuringerTransform, index: i32) TuringerTransform {
        return _core_turinger_transform__get_child(self, index);
    }

    pub fn get_child_count(self: *const TuringerTransform) i32 {
        return _core_turinger_transform__get_child_count(self);
    }

    pub fn get_component_by_name(self: *const TuringerTransform, cs_type: []const u8, allocator: std.mem.Allocator) !Component {
        const turing_handle_cs_type = try allocator.dupeZ(u8, cs_type);
        defer allocator.free(turing_handle_cs_type);
        return _core_turinger_transform__get_component_by_name(self, turing_handle_cs_type.ptr);
    }

    pub fn get_component_by_type(self: *const TuringerTransform, cs_type: Type) Component {
        return _core_turinger_transform__get_component_by_type(self, cs_type);
    }

    pub fn get_component_in_children_by_type(self: *const TuringerTransform, t: Type, include_inactive: bool) Component {
        return _core_turinger_transform__get_component_in_children_by_type(self, t, include_inactive);
    }

    pub fn get_component_in_parent_by_type(self: *const TuringerTransform, t: Type, include_inactive: bool) Component {
        return _core_turinger_transform__get_component_in_parent_by_type(self, t, include_inactive);
    }

    pub fn get_component_index(self: *const TuringerTransform) i32 {
        return _core_turinger_transform__get_component_index(self);
    }

    pub fn get_enumerator(self: *const TuringerTransform) IEnumerator {
        return _core_turinger_transform__get_enumerator(self);
    }

    pub fn get_instance_id(self: *const TuringerTransform) i32 {
        return _core_turinger_transform__get_instance_id(self);
    }

    pub fn get_sibling_index(self: *const TuringerTransform) i32 {
        return _core_turinger_transform__get_sibling_index(self);
    }

    pub fn has_changed_get(self: *const TuringerTransform) bool {
        return _core_turinger_transform__has_changed_get(self);
    }

    pub fn has_changed_set(self: *const TuringerTransform, value: bool) void {
        _core_turinger_transform__has_changed_set(self, value);
    }

    pub fn hide_flags_get(self: *const TuringerTransform) i32 {
        return _core_turinger_transform__hide_flags_get(self);
    }

    pub fn hide_flags_set(self: *const TuringerTransform, value: i32) void {
        _core_turinger_transform__hide_flags_set(self, value);
    }

    pub fn hierarchy_capacity_get(self: *const TuringerTransform) i32 {
        return _core_turinger_transform__hierarchy_capacity_get(self);
    }

    pub fn hierarchy_capacity_set(self: *const TuringerTransform, value: i32) void {
        _core_turinger_transform__hierarchy_capacity_set(self, value);
    }

    pub fn hierarchy_count_get(self: *const TuringerTransform) i32 {
        return _core_turinger_transform__hierarchy_count_get(self);
    }

    pub fn inverse_transform_direction(self: *const TuringerTransform, direction: zalg.Vec3) zalg.Vec3 {
        const turing_handle_direction = enqueue_vec3(direction);
        _core_turinger_transform__inverse_transform_direction(self, turing_handle_direction);
        return dequeue_vec3();
    }

    pub fn inverse_transform_point(self: *const TuringerTransform, position: zalg.Vec3) zalg.Vec3 {
        const turing_handle_position = enqueue_vec3(position);
        _core_turinger_transform__inverse_transform_point(self, turing_handle_position);
        return dequeue_vec3();
    }

    pub fn inverse_transform_vector(self: *const TuringerTransform, vector: zalg.Vec3) zalg.Vec3 {
        const turing_handle_vector = enqueue_vec3(vector);
        _core_turinger_transform__inverse_transform_vector(self, turing_handle_vector);
        return dequeue_vec3();
    }

    pub fn is_child_of(self: *const TuringerTransform, parent: TuringerTransform) bool {
        return _core_turinger_transform__is_child_of(self, parent);
    }

    pub fn local_euler_angles_get(self: *const TuringerTransform) zalg.Vec3 {
        _core_turinger_transform__local_euler_angles_get(self);
        return dequeue_vec3();
    }

    pub fn local_euler_angles_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_turinger_transform__local_euler_angles_set(self, turing_handle_value);
    }

    pub fn local_position_get(self: *const TuringerTransform) zalg.Vec3 {
        _core_turinger_transform__local_position_get(self);
        return dequeue_vec3();
    }

    pub fn local_position_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_turinger_transform__local_position_set(self, turing_handle_value);
    }

    pub fn local_rotation_get(self: *const TuringerTransform) zalg.Quat {
        _core_turinger_transform__local_rotation_get(self);
        return dequeue_quat();
    }

    pub fn local_rotation_set(self: *const TuringerTransform, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _core_turinger_transform__local_rotation_set(self, turing_handle_value);
    }

    pub fn local_scale_get(self: *const TuringerTransform) zalg.Vec3 {
        _core_turinger_transform__local_scale_get(self);
        return dequeue_vec3();
    }

    pub fn local_scale_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_turinger_transform__local_scale_set(self, turing_handle_value);
    }

    pub fn local_to_world_matrix_get(self: *const TuringerTransform) zalg.Mat4 {
        _core_turinger_transform__local_to_world_matrix_get(self);
        return dequeue_mat4();
    }

    pub fn look_at(self: *const TuringerTransform, target: TuringerTransform, world_up: zalg.Vec3) void {
        const turing_handle_world_up = enqueue_vec3(world_up);
        _core_turinger_transform__look_at(self, target, turing_handle_world_up);
    }

    pub fn lossy_scale_get(self: *const TuringerTransform) zalg.Vec3 {
        _core_turinger_transform__lossy_scale_get(self);
        return dequeue_vec3();
    }

    pub fn name_get(self: *const TuringerTransform, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_turinger_transform__name_get(self);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }

    pub fn name_set(self: *const TuringerTransform, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _core_turinger_transform__name_set(self, turing_handle_value.ptr);
    }

    pub fn parent_get(self: *const TuringerTransform) TuringerTransform {
        return _core_turinger_transform__parent_get(self);
    }

    pub fn parent_set(self: *const TuringerTransform, value: TuringerTransform) void {
        _core_turinger_transform__parent_set(self, value);
    }

    pub fn position_get(self: *const TuringerTransform) zalg.Vec3 {
        _core_turinger_transform__position_get(self);
        return dequeue_vec3();
    }

    pub fn position_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_turinger_transform__position_set(self, turing_handle_value);
    }

    pub fn right_get(self: *const TuringerTransform) zalg.Vec3 {
        _core_turinger_transform__right_get(self);
        return dequeue_vec3();
    }

    pub fn right_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_turinger_transform__right_set(self, turing_handle_value);
    }

    pub fn root_get(self: *const TuringerTransform) TuringerTransform {
        return _core_turinger_transform__root_get(self);
    }

    pub fn rotate(self: *const TuringerTransform, eulers: zalg.Vec3) void {
        const turing_handle_eulers = enqueue_vec3(eulers);
        _core_turinger_transform__rotate(self, turing_handle_eulers);
    }

    pub fn rotate_around(self: *const TuringerTransform, point: zalg.Vec3, axis: zalg.Vec3, angle: f32) void {
        const turing_handle_point = enqueue_vec3(point);
        const turing_handle_axis = enqueue_vec3(axis);
        _core_turinger_transform__rotate_around(self, turing_handle_point, turing_handle_axis, angle);
    }

    pub fn rotate_around_local(self: *const TuringerTransform, axis: zalg.Vec3, angle: f32) void {
        const turing_handle_axis = enqueue_vec3(axis);
        _core_turinger_transform__rotate_around_local(self, turing_handle_axis, angle);
    }

    pub fn rotate_relative(self: *const TuringerTransform, eulers: zalg.Vec3, relative_to: i32) void {
        const turing_handle_eulers = enqueue_vec3(eulers);
        _core_turinger_transform__rotate_relative(self, turing_handle_eulers, relative_to);
    }

    pub fn rotation_get(self: *const TuringerTransform) zalg.Quat {
        _core_turinger_transform__rotation_get(self);
        return dequeue_quat();
    }

    pub fn rotation_set(self: *const TuringerTransform, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _core_turinger_transform__rotation_set(self, turing_handle_value);
    }

    pub fn send_message(self: *const TuringerTransform, method_name: []const u8, value: Object, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_turinger_transform__send_message(self, turing_handle_method_name.ptr, value, options);
    }

    pub fn send_message_upwards(self: *const TuringerTransform, method_name: []const u8, value: Object, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _core_turinger_transform__send_message_upwards(self, turing_handle_method_name.ptr, value, options);
    }

    pub fn set_as_first_sibling(self: *const TuringerTransform) void {
        _core_turinger_transform__set_as_first_sibling(self);
    }

    pub fn set_as_last_sibling(self: *const TuringerTransform) void {
        _core_turinger_transform__set_as_last_sibling(self);
    }

    pub fn set_local_position_and_rotation(self: *const TuringerTransform, local_position: zalg.Vec3, local_rotation: zalg.Quat) void {
        const turing_handle_local_position = enqueue_vec3(local_position);
        const turing_handle_local_rotation = enqueue_quat(local_rotation);
        _core_turinger_transform__set_local_position_and_rotation(self, turing_handle_local_position, turing_handle_local_rotation);
    }

    pub fn set_parent(self: *const TuringerTransform, parent: TuringerTransform, world_position_stays: bool) void {
        _core_turinger_transform__set_parent(self, parent, world_position_stays);
    }

    pub fn set_position_and_rotation(self: *const TuringerTransform, position: zalg.Vec3, rotation: zalg.Quat) void {
        const turing_handle_position = enqueue_vec3(position);
        const turing_handle_rotation = enqueue_quat(rotation);
        _core_turinger_transform__set_position_and_rotation(self, turing_handle_position, turing_handle_rotation);
    }

    pub fn set_sibling_index(self: *const TuringerTransform, index: i32) void {
        _core_turinger_transform__set_sibling_index(self, index);
    }

    pub fn tag_get(self: *const TuringerTransform, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _core_turinger_transform__tag_get(self);
        const turing_str = try allocator.alloc(u8, turing_result);
        _host_strcpy(turing_str.ptr, turing_result);
        return turing_str[0 .. turing_result - 1];
    }

    pub fn tag_set(self: *const TuringerTransform, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _core_turinger_transform__tag_set(self, turing_handle_value.ptr);
    }

    pub fn transform_direction(self: *const TuringerTransform, direction: zalg.Vec3) zalg.Vec3 {
        const turing_handle_direction = enqueue_vec3(direction);
        _core_turinger_transform__transform_direction(self, turing_handle_direction);
        return dequeue_vec3();
    }

    pub fn transform_get(self: *const TuringerTransform) Transform {
        return _core_turinger_transform__transform_get(self);
    }

    pub fn transform_point(self: *const TuringerTransform, position: zalg.Vec3) zalg.Vec3 {
        const turing_handle_position = enqueue_vec3(position);
        _core_turinger_transform__transform_point(self, turing_handle_position);
        return dequeue_vec3();
    }

    pub fn transform_vector(self: *const TuringerTransform, vector: zalg.Vec3) zalg.Vec3 {
        const turing_handle_vector = enqueue_vec3(vector);
        _core_turinger_transform__transform_vector(self, turing_handle_vector);
        return dequeue_vec3();
    }

    pub fn translate(self: *const TuringerTransform, translation: zalg.Vec3, relative_to: i32) void {
        const turing_handle_translation = enqueue_vec3(translation);
        _core_turinger_transform__translate(self, turing_handle_translation, relative_to);
    }

    pub fn translate_relative(self: *const TuringerTransform, translation: zalg.Vec3, relative_to: TuringerTransform) void {
        const turing_handle_translation = enqueue_vec3(translation);
        _core_turinger_transform__translate_relative(self, turing_handle_translation, relative_to);
    }

    pub fn up_get(self: *const TuringerTransform) zalg.Vec3 {
        _core_turinger_transform__up_get(self);
        return dequeue_vec3();
    }

    pub fn up_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _core_turinger_transform__up_set(self, turing_handle_value);
    }

    pub fn world_to_local_matrix_get(self: *const TuringerTransform) zalg.Mat4 {
        _core_turinger_transform__world_to_local_matrix_get(self);
        return dequeue_mat4();
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















