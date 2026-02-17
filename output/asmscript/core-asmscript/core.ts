///// Generated AssemblyScript API /////
import { Vec2, Vec3, Vec4, Quat, Mat4 } from "../turing-api-asmscript/linear_algebra";


//// Wasm Bindings ////


@external("env", "_host_strcpy")
export declare function _host_strcpy(location: u32, size: u32): void;
@external("env", "_host_bufcpy")
export declare function _host_bufcpy(location: u32, size: u32): void;
@external("env", "_host_f32_enqueue")
export declare function _host_f32_enqueue(f: f32): void;
@external("env", "_host_f32_dequeue")
export declare function _host_f32_dequeue(): f32;
@external("env", "_host_u32_enqueue")
export declare function _host_u32_enqueue(f: u32): void;
@external("env", "_host_u32_dequeue")
export declare function _host_u32_dequeue(): u32;


@external("env", "_core_custom_data__create")
declare function _core_custom_data__create(): u64;
@external("env", "_core_custom_data__from_json")
declare function _core_custom_data__from_json(json: u32): u64;
@external("env", "_core_custom_data__list_add_bool")
declare function _core_custom_data__list_add_bool(list: u64, value: bool): void;
@external("env", "_core_custom_data__list_add_custom_data")
declare function _core_custom_data__list_add_custom_data(list: u64, value: u64): void;
@external("env", "_core_custom_data__list_add_custom_data_list")
declare function _core_custom_data__list_add_custom_data_list(list: u64, value: u64): void;
@external("env", "_core_custom_data__list_add_float")
declare function _core_custom_data__list_add_float(list: u64, value: f32): void;
@external("env", "_core_custom_data__list_add_int")
declare function _core_custom_data__list_add_int(list: u64, value: i32): void;
@external("env", "_core_custom_data__list_add_string")
declare function _core_custom_data__list_add_string(list: u64, value: u32): void;
@external("env", "_core_custom_data__set_bool")
declare function _core_custom_data__set_bool(custom_data: u64, key: u32, value: bool): void;
@external("env", "_core_custom_data__set_custom_data")
declare function _core_custom_data__set_custom_data(custom_data: u64, key: u32, value: u64): void;
@external("env", "_core_custom_data__set_custom_data_list")
declare function _core_custom_data__set_custom_data_list(custom_data: u64, key: u32, value: u64): void;
@external("env", "_core_custom_data__set_float")
declare function _core_custom_data__set_float(custom_data: u64, key: u32, value: f32): void;
@external("env", "_core_custom_data__set_int")
declare function _core_custom_data__set_int(custom_data: u64, key: u32, value: i32): void;
@external("env", "_core_custom_data__set_string")
declare function _core_custom_data__set_string(custom_data: u64, key: u32, value: u32): void;
@external("env", "_core_custom_data__to_json")
declare function _core_custom_data__to_json(custom_data: u64, pretty: bool): u32;
@external("env", "_core_custom_event_data__custom_data_get")
declare function _core_custom_event_data__custom_data_get(handle: u64): u64;
@external("env", "_core_custom_event_data__event_type_get")
declare function _core_custom_event_data__event_type_get(handle: u64): u32;
@external("env", "_core_custom_event_data__get_copy")
declare function _core_custom_event_data__get_copy(handle: u64): u64;
@external("env", "_core_custom_event_data__version_get")
declare function _core_custom_event_data__version_get(handle: u64): u64;
@external("env", "_core_custom_note_data__create_custom_basic_note_data")
declare function _core_custom_note_data__create_custom_basic_note_data(time: f32, beat: f32, rotation: i32, line_index: i32): u64;
@external("env", "_core_custom_note_data__create_custom_bomb_note_data")
declare function _core_custom_note_data__create_custom_bomb_note_data(time: f32, beat: f32, rotation: i32, line_index: i32): u64;
@external("env", "_core_custom_note_data__create_custom_burst_slider_note_data")
declare function _core_custom_note_data__create_custom_burst_slider_note_data(time: f32, beat: f32, rotation: i32, line_index: i32): u64;
@external("env", "_core_custom_note_data__custom_data_get")
declare function _core_custom_note_data__custom_data_get(handle: u64): u64;
@external("env", "_core_custom_note_data__get_copy")
declare function _core_custom_note_data__get_copy(handle: u64): u64;
@external("env", "_core_custom_note_data__version_get")
declare function _core_custom_note_data__version_get(handle: u64): u64;
@external("env", "_core_custom_obstacle_data__custom_data_get")
declare function _core_custom_obstacle_data__custom_data_get(handle: u64): u64;
@external("env", "_core_custom_obstacle_data__get_copy")
declare function _core_custom_obstacle_data__get_copy(handle: u64): u64;
@external("env", "_core_custom_obstacle_data__version_get")
declare function _core_custom_obstacle_data__version_get(handle: u64): u64;
@external("env", "_core_gc_helper__create")
declare function _core_gc_helper__create(): u64;
@external("env", "_core_gc_helper__dispose")
declare function _core_gc_helper__dispose(handle: u64): void;
@external("env", "_core_gc_helper__invalidate_all_handles")
declare function _core_gc_helper__invalidate_all_handles(handle: u64): void;
@external("env", "_core_gc_helper__wasm_garbage_collect")
declare function _core_gc_helper__wasm_garbage_collect(handle: u64): void;
@external("env", "_core_log__critical")
declare function _core_log__critical(msg: u32): void;
@external("env", "_core_log__debug")
declare function _core_log__debug(msg: u32): void;
@external("env", "_core_log__info")
declare function _core_log__info(msg: u32): void;
@external("env", "_core_log__warn")
declare function _core_log__warn(msg: u32): void;
@external("env", "_core_note_floor_movement___audio_time_sync_controller_get")
declare function _core_note_floor_movement___audio_time_sync_controller_get(handle: u64): u64;
@external("env", "_core_note_floor_movement___beat_time_get")
declare function _core_note_floor_movement___beat_time_get(handle: u64): f32;
@external("env", "_core_note_floor_movement___beat_time_set")
declare function _core_note_floor_movement___beat_time_set(handle: u64, value: f32): void;
@external("env", "_core_note_floor_movement___inverse_world_rotation_get")
declare function _core_note_floor_movement___inverse_world_rotation_get(handle: u64): u32;
@external("env", "_core_note_floor_movement___inverse_world_rotation_set")
declare function _core_note_floor_movement___inverse_world_rotation_set(handle: u64, value: u32): void;
@external("env", "_core_note_floor_movement___local_position_get")
declare function _core_note_floor_movement___local_position_get(handle: u64): u32;
@external("env", "_core_note_floor_movement___local_position_set")
declare function _core_note_floor_movement___local_position_set(handle: u64, value: u32): void;
@external("env", "_core_note_floor_movement___move_end_offset_get")
declare function _core_note_floor_movement___move_end_offset_get(handle: u64): u32;
@external("env", "_core_note_floor_movement___move_end_offset_set")
declare function _core_note_floor_movement___move_end_offset_set(handle: u64, value: u32): void;
@external("env", "_core_note_floor_movement___move_start_offset_get")
declare function _core_note_floor_movement___move_start_offset_get(handle: u64): u32;
@external("env", "_core_note_floor_movement___move_start_offset_set")
declare function _core_note_floor_movement___move_start_offset_set(handle: u64, value: u32): void;
@external("env", "_core_note_floor_movement___player_transforms_get")
declare function _core_note_floor_movement___player_transforms_get(handle: u64): u64;
@external("env", "_core_note_floor_movement___rotated_object_get")
declare function _core_note_floor_movement___rotated_object_get(handle: u64): u64;
@external("env", "_core_note_floor_movement___rotated_object_set")
declare function _core_note_floor_movement___rotated_object_set(handle: u64, value: u64): void;
@external("env", "_core_note_floor_movement___variable_movement_data_provider_get")
declare function _core_note_floor_movement___variable_movement_data_provider_get(handle: u64): u64;
@external("env", "_core_note_floor_movement___world_rotation_get")
declare function _core_note_floor_movement___world_rotation_get(handle: u64): u32;
@external("env", "_core_note_floor_movement___world_rotation_set")
declare function _core_note_floor_movement___world_rotation_set(handle: u64, value: u32): void;
@external("env", "_core_note_floor_movement__distance_to_player_get")
declare function _core_note_floor_movement__distance_to_player_get(handle: u64): f32;
@external("env", "_core_note_floor_movement__end_pos_get")
declare function _core_note_floor_movement__end_pos_get(handle: u64): u32;
@external("env", "_core_note_floor_movement__init")
declare function _core_note_floor_movement__init(handle: u64, world_rotation: f32, beat_time: f32, move_start_offset: u32, move_end_offset: u32): void;
@external("env", "_core_note_floor_movement__inverse_world_rotation_get")
declare function _core_note_floor_movement__inverse_world_rotation_get(handle: u64): u32;
@external("env", "_core_note_floor_movement__local_position_get")
declare function _core_note_floor_movement__local_position_get(handle: u64): u32;
@external("env", "_core_note_floor_movement__manual_update")
declare function _core_note_floor_movement__manual_update(handle: u64): u32;
@external("env", "_core_note_floor_movement__note_time_get")
declare function _core_note_floor_movement__note_time_get(handle: u64): f32;
@external("env", "_core_note_floor_movement__set_to_start")
declare function _core_note_floor_movement__set_to_start(handle: u64): u32;
@external("env", "_core_note_floor_movement__should_move")
declare function _core_note_floor_movement__should_move(handle: u64): bool;
@external("env", "_core_note_floor_movement__world_rotation_get")
declare function _core_note_floor_movement__world_rotation_get(handle: u64): u32;
@external("env", "_core_note_jump__k_missed_time_offset_get")
declare function _core_note_jump__k_missed_time_offset_get(): f32;
@external("env", "_core_note_jump___audio_time_sync_controller_get")
declare function _core_note_jump___audio_time_sync_controller_get(handle: u64): u64;
@external("env", "_core_note_jump___end_distance_offset_get")
declare function _core_note_jump___end_distance_offset_get(handle: u64): f32;
@external("env", "_core_note_jump___end_distance_offset_set")
declare function _core_note_jump___end_distance_offset_set(handle: u64, value: f32): void;
@external("env", "_core_note_jump___end_offset_get")
declare function _core_note_jump___end_offset_get(handle: u64): u32;
@external("env", "_core_note_jump___end_offset_set")
declare function _core_note_jump___end_offset_set(handle: u64, value: u32): void;
@external("env", "_core_note_jump___end_pos_get")
declare function _core_note_jump___end_pos_get(handle: u64): u32;
@external("env", "_core_note_jump___end_pos_set")
declare function _core_note_jump___end_pos_set(handle: u64, value: u32): void;
@external("env", "_core_note_jump___end_rotation_get")
declare function _core_note_jump___end_rotation_get(handle: u64): u32;
@external("env", "_core_note_jump___end_rotation_set")
declare function _core_note_jump___end_rotation_set(handle: u64, value: u32): void;
@external("env", "_core_note_jump___gravity_base_get")
declare function _core_note_jump___gravity_base_get(handle: u64): f32;
@external("env", "_core_note_jump___gravity_base_set")
declare function _core_note_jump___gravity_base_set(handle: u64, value: f32): void;
@external("env", "_core_note_jump___gravity_get")
declare function _core_note_jump___gravity_get(handle: u64): f32;
@external("env", "_core_note_jump___gravity_set")
declare function _core_note_jump___gravity_set(handle: u64, value: f32): void;
@external("env", "_core_note_jump___half_jump_duration_get")
declare function _core_note_jump___half_jump_duration_get(handle: u64): f32;
@external("env", "_core_note_jump___half_jump_duration_set")
declare function _core_note_jump___half_jump_duration_set(handle: u64, value: f32): void;
@external("env", "_core_note_jump___half_jump_mark_reported_get")
declare function _core_note_jump___half_jump_mark_reported_get(handle: u64): bool;
@external("env", "_core_note_jump___half_jump_mark_reported_set")
declare function _core_note_jump___half_jump_mark_reported_set(handle: u64, value: bool): void;
@external("env", "_core_note_jump___inverse_world_rotation_get")
declare function _core_note_jump___inverse_world_rotation_get(handle: u64): u32;
@external("env", "_core_note_jump___inverse_world_rotation_set")
declare function _core_note_jump___inverse_world_rotation_set(handle: u64, value: u32): void;
@external("env", "_core_note_jump___jump_duration_get")
declare function _core_note_jump___jump_duration_get(handle: u64): f32;
@external("env", "_core_note_jump___jump_duration_set")
declare function _core_note_jump___jump_duration_set(handle: u64, value: f32): void;
@external("env", "_core_note_jump___jump_started_reported_get")
declare function _core_note_jump___jump_started_reported_get(handle: u64): bool;
@external("env", "_core_note_jump___jump_started_reported_set")
declare function _core_note_jump___jump_started_reported_set(handle: u64, value: bool): void;
@external("env", "_core_note_jump___local_position_get")
declare function _core_note_jump___local_position_get(handle: u64): u32;
@external("env", "_core_note_jump___local_position_set")
declare function _core_note_jump___local_position_set(handle: u64, value: u32): void;
@external("env", "_core_note_jump___middle_rotation_get")
declare function _core_note_jump___middle_rotation_get(handle: u64): u32;
@external("env", "_core_note_jump___middle_rotation_set")
declare function _core_note_jump___middle_rotation_set(handle: u64, value: u32): void;
@external("env", "_core_note_jump___missed_mark_reported_get")
declare function _core_note_jump___missed_mark_reported_get(handle: u64): bool;
@external("env", "_core_note_jump___missed_mark_reported_set")
declare function _core_note_jump___missed_mark_reported_set(handle: u64, value: bool): void;
@external("env", "_core_note_jump___missed_time_get")
declare function _core_note_jump___missed_time_get(handle: u64): f32;
@external("env", "_core_note_jump___missed_time_set")
declare function _core_note_jump___missed_time_set(handle: u64, value: f32): void;
@external("env", "_core_note_jump___note_time_get")
declare function _core_note_jump___note_time_get(handle: u64): f32;
@external("env", "_core_note_jump___note_time_set")
declare function _core_note_jump___note_time_set(handle: u64, value: f32): void;
@external("env", "_core_note_jump___player_space_convertor_get")
declare function _core_note_jump___player_space_convertor_get(handle: u64): u64;
@external("env", "_core_note_jump___player_transforms_get")
declare function _core_note_jump___player_transforms_get(handle: u64): u64;
@external("env", "_core_note_jump___rotate_towards_player_get")
declare function _core_note_jump___rotate_towards_player_get(handle: u64): bool;
@external("env", "_core_note_jump___rotate_towards_player_set")
declare function _core_note_jump___rotate_towards_player_set(handle: u64, value: bool): void;
@external("env", "_core_note_jump___rotated_object_get")
declare function _core_note_jump___rotated_object_get(handle: u64): u64;
@external("env", "_core_note_jump___rotated_object_set")
declare function _core_note_jump___rotated_object_set(handle: u64, value: u64): void;
@external("env", "_core_note_jump___start_offset_get")
declare function _core_note_jump___start_offset_get(handle: u64): u32;
@external("env", "_core_note_jump___start_offset_set")
declare function _core_note_jump___start_offset_set(handle: u64, value: u32): void;
@external("env", "_core_note_jump___start_pos_get")
declare function _core_note_jump___start_pos_get(handle: u64): u32;
@external("env", "_core_note_jump___start_pos_set")
declare function _core_note_jump___start_pos_set(handle: u64, value: u32): void;
@external("env", "_core_note_jump___start_rotation_get")
declare function _core_note_jump___start_rotation_get(handle: u64): u32;
@external("env", "_core_note_jump___start_rotation_set")
declare function _core_note_jump___start_rotation_set(handle: u64, value: u32): void;
@external("env", "_core_note_jump___three_quarters_mark_reported_get")
declare function _core_note_jump___three_quarters_mark_reported_get(handle: u64): bool;
@external("env", "_core_note_jump___three_quarters_mark_reported_set")
declare function _core_note_jump___three_quarters_mark_reported_set(handle: u64, value: bool): void;
@external("env", "_core_note_jump___variable_movement_data_provider_get")
declare function _core_note_jump___variable_movement_data_provider_get(handle: u64): u64;
@external("env", "_core_note_jump___world_rotation_get")
declare function _core_note_jump___world_rotation_get(handle: u64): u32;
@external("env", "_core_note_jump___world_rotation_set")
declare function _core_note_jump___world_rotation_set(handle: u64, value: u32): void;
@external("env", "_core_note_jump___y_avoidance_down_get")
declare function _core_note_jump___y_avoidance_down_get(handle: u64): f32;
@external("env", "_core_note_jump___y_avoidance_down_set")
declare function _core_note_jump___y_avoidance_down_set(handle: u64, value: f32): void;
@external("env", "_core_note_jump___y_avoidance_get")
declare function _core_note_jump___y_avoidance_get(handle: u64): f32;
@external("env", "_core_note_jump___y_avoidance_set")
declare function _core_note_jump___y_avoidance_set(handle: u64, value: f32): void;
@external("env", "_core_note_jump___y_avoidance_up_get")
declare function _core_note_jump___y_avoidance_up_get(handle: u64): f32;
@external("env", "_core_note_jump___y_avoidance_up_set")
declare function _core_note_jump___y_avoidance_up_set(handle: u64, value: f32): void;
@external("env", "_core_note_jump__add_note_jump_did_finish_event")
declare function _core_note_jump__add_note_jump_did_finish_event(handle: u64, value: u64): void;
@external("env", "_core_note_jump__add_note_jump_did_pass_half_event")
declare function _core_note_jump__add_note_jump_did_pass_half_event(handle: u64, value: u64): void;
@external("env", "_core_note_jump__add_note_jump_did_pass_missed_marker_event")
declare function _core_note_jump__add_note_jump_did_pass_missed_marker_event(handle: u64, value: u64): void;
@external("env", "_core_note_jump__add_note_jump_did_pass_three_quarters_event")
declare function _core_note_jump__add_note_jump_did_pass_three_quarters_event(handle: u64, value: u64): void;
@external("env", "_core_note_jump__add_note_jump_did_start_event")
declare function _core_note_jump__add_note_jump_did_start_event(handle: u64, value: u64): void;
@external("env", "_core_note_jump__add_note_jump_did_update_progress_event")
declare function _core_note_jump__add_note_jump_did_update_progress_event(handle: u64, value: u64): void;
@external("env", "_core_note_jump__beat_pos_get")
declare function _core_note_jump__beat_pos_get(handle: u64): u32;
@external("env", "_core_note_jump__distance_to_player_get")
declare function _core_note_jump__distance_to_player_get(handle: u64): f32;
@external("env", "_core_note_jump__init")
declare function _core_note_jump__init(handle: u64, note_time: f32, world_rotation: f32, move_end_offset: u32, jump_end_offset: u32, gravity_base: f32, flip_y_side: f32, end_rotation: f32, rotate_towards_player: bool, use_random_rotation: bool): void;
@external("env", "_core_note_jump__local_position_get")
declare function _core_note_jump__local_position_get(handle: u64): u32;
@external("env", "_core_note_jump__manual_update")
declare function _core_note_jump__manual_update(handle: u64): u32;
@external("env", "_core_note_jump__move_vec_get")
declare function _core_note_jump__move_vec_get(handle: u64): u32;
@external("env", "_core_note_jump__note_time_get")
declare function _core_note_jump__note_time_get(handle: u64): f32;
@external("env", "_core_note_jump__remove_note_jump_did_finish_event")
declare function _core_note_jump__remove_note_jump_did_finish_event(handle: u64, value: u64): void;
@external("env", "_core_note_jump__remove_note_jump_did_pass_half_event")
declare function _core_note_jump__remove_note_jump_did_pass_half_event(handle: u64, value: u64): void;
@external("env", "_core_note_jump__remove_note_jump_did_pass_missed_marker_event")
declare function _core_note_jump__remove_note_jump_did_pass_missed_marker_event(handle: u64, value: u64): void;
@external("env", "_core_note_jump__remove_note_jump_did_pass_three_quarters_event")
declare function _core_note_jump__remove_note_jump_did_pass_three_quarters_event(handle: u64, value: u64): void;
@external("env", "_core_note_jump__remove_note_jump_did_start_event")
declare function _core_note_jump__remove_note_jump_did_start_event(handle: u64, value: u64): void;
@external("env", "_core_note_jump__remove_note_jump_did_update_progress_event")
declare function _core_note_jump__remove_note_jump_did_update_progress_event(handle: u64, value: u64): void;
@external("env", "_core_note_manager__add_bomb_note")
declare function _core_note_manager__add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: u64): u64;
@external("env", "_core_note_manager__add_color_note")
declare function _core_note_manager__add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: u64): u64;
@external("env", "_core_note_manager__add_obstacle")
declare function _core_note_manager__add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: u64): u64;
@external("env", "_core_note_manager__get_note_controller")
declare function _core_note_manager__get_note_controller(n: i32): u64;
@external("env", "_core_note_manager__get_note_controller_from_custom")
declare function _core_note_manager__get_note_controller_from_custom(n: u64): u64;
@external("env", "_core_note_manager__get_nth_event")
declare function _core_note_manager__get_nth_event(id: i32): u64;
@external("env", "_core_note_manager__get_nth_note")
declare function _core_note_manager__get_nth_note(id: i32): u64;
@external("env", "_core_note_manager__get_nth_object")
declare function _core_note_manager__get_nth_object(id: i32): u64;
@external("env", "_core_note_manager__get_nth_obstacle")
declare function _core_note_manager__get_nth_obstacle(id: i32): u64;
@external("env", "_core_note_manager__get_obstacle_controller")
declare function _core_note_manager__get_obstacle_controller(n: i32): u64;
@external("env", "_core_note_manager__get_obstacle_controller_from_custom")
declare function _core_note_manager__get_obstacle_controller_from_custom(n: u64): u64;
@external("env", "_core_note_manager__time_to_beat")
declare function _core_note_manager__time_to_beat(time: f32): f32;
@external("env", "_core_task_scheduler__schedule")
declare function _core_task_scheduler__schedule(task: u64): void;
@external("env", "_core_task_scheduler__dispose")
declare function _core_task_scheduler__dispose(handle: u64): void;
@external("env", "_core_turing_mesh___mesh_get")
declare function _core_turing_mesh___mesh_get(handle: u64): u64;
@external("env", "_core_turing_mesh___mesh_set")
declare function _core_turing_mesh___mesh_set(handle: u64, value: u64): void;
@external("env", "_core_turing_mesh__clear")
declare function _core_turing_mesh__clear(handle: u64): void;
@external("env", "_core_turing_mesh__get_bounds_max_x")
declare function _core_turing_mesh__get_bounds_max_x(handle: u64): f32;
@external("env", "_core_turing_mesh__get_bounds_max_y")
declare function _core_turing_mesh__get_bounds_max_y(handle: u64): f32;
@external("env", "_core_turing_mesh__get_bounds_max_z")
declare function _core_turing_mesh__get_bounds_max_z(handle: u64): f32;
@external("env", "_core_turing_mesh__get_bounds_min_x")
declare function _core_turing_mesh__get_bounds_min_x(handle: u64): f32;
@external("env", "_core_turing_mesh__get_bounds_min_y")
declare function _core_turing_mesh__get_bounds_min_y(handle: u64): f32;
@external("env", "_core_turing_mesh__get_bounds_min_z")
declare function _core_turing_mesh__get_bounds_min_z(handle: u64): f32;
@external("env", "_core_turing_mesh__get_instance_id")
declare function _core_turing_mesh__get_instance_id(handle: u64): i32;
@external("env", "_core_turing_mesh__get_u_vs")
declare function _core_turing_mesh__get_u_vs(handle: u64, channel: i32): u32;
@external("env", "_core_turing_mesh__get_vertices")
declare function _core_turing_mesh__get_vertices(handle: u64): u32;
@external("env", "_core_turing_mesh__hide_flags_get")
declare function _core_turing_mesh__hide_flags_get(handle: u64): void;
@external("env", "_core_turing_mesh__hide_flags_set")
declare function _core_turing_mesh__hide_flags_set(handle: u64): void;
@external("env", "_core_turing_mesh__mark_modified")
declare function _core_turing_mesh__mark_modified(handle: u64): void;
@external("env", "_core_turing_mesh__name_get")
declare function _core_turing_mesh__name_get(handle: u64): u32;
@external("env", "_core_turing_mesh__name_set")
declare function _core_turing_mesh__name_set(handle: u64, value: u32): void;
@external("env", "_core_turing_mesh__optimize")
declare function _core_turing_mesh__optimize(handle: u64): void;
@external("env", "_core_turing_mesh__optimize_index_buffers")
declare function _core_turing_mesh__optimize_index_buffers(handle: u64): void;
@external("env", "_core_turing_mesh__recalculate_bounds")
declare function _core_turing_mesh__recalculate_bounds(handle: u64): void;
@external("env", "_core_turing_mesh__recalculate_normals")
declare function _core_turing_mesh__recalculate_normals(handle: u64): void;
@external("env", "_core_turing_mesh__recalculate_tangents")
declare function _core_turing_mesh__recalculate_tangents(handle: u64): void;
@external("env", "_core_turing_mesh__set_bounds")
declare function _core_turing_mesh__set_bounds(handle: u64, min_x: f32, min_y: f32, min_z: f32, max_x: f32, max_y: f32, max_z: f32): void;
@external("env", "_core_turing_mesh__set_triangles")
declare function _core_turing_mesh__set_triangles(handle: u64, triangles: u64, submesh: i32, calculate_bounds: bool, base_vertex: i32): void;
@external("env", "_core_turing_mesh__set_u_vs")
declare function _core_turing_mesh__set_u_vs(handle: u64, channel: i32, uvs: u32): void;
@external("env", "_core_turing_mesh__set_vertices")
declare function _core_turing_mesh__set_vertices(handle: u64, in_vertices: u32): void;
@external("env", "_core_turing_mesh__upload_mesh_data")
declare function _core_turing_mesh__upload_mesh_data(handle: u64, mark_no_longer_readable: bool): void;
@external("env", "_core_turinger_game_object__active_get")
declare function _core_turinger_game_object__active_get(handle: u64): bool;
@external("env", "_core_turinger_game_object__active_in_hierarchy_get")
declare function _core_turinger_game_object__active_in_hierarchy_get(handle: u64): bool;
@external("env", "_core_turinger_game_object__active_self_get")
declare function _core_turinger_game_object__active_self_get(handle: u64): bool;
@external("env", "_core_turinger_game_object__active_set")
declare function _core_turinger_game_object__active_set(handle: u64, value: bool): void;
@external("env", "_core_turinger_game_object__add_component")
declare function _core_turinger_game_object__add_component(handle: u64, component_type: u64): u64;
@external("env", "_core_turinger_game_object__add_or_get_mesh")
declare function _core_turinger_game_object__add_or_get_mesh(handle: u64): u64;
@external("env", "_core_turinger_game_object__broadcast_message")
declare function _core_turinger_game_object__broadcast_message(handle: u64, method_name: u32, options: i32): void;
@external("env", "_core_turinger_game_object__compare_tag")
declare function _core_turinger_game_object__compare_tag(handle: u64, tag: u32): bool;
@external("env", "_core_turinger_game_object__game_object_get")
declare function _core_turinger_game_object__game_object_get(handle: u64): u64;
@external("env", "_core_turinger_game_object__get_component_at_index")
declare function _core_turinger_game_object__get_component_at_index(handle: u64, index: i32): u64;
@external("env", "_core_turinger_game_object__get_component_by_name")
declare function _core_turinger_game_object__get_component_by_name(handle: u64, cs_type: u32): u64;
@external("env", "_core_turinger_game_object__get_component_by_type")
declare function _core_turinger_game_object__get_component_by_type(handle: u64, cs_type: u64): u64;
@external("env", "_core_turinger_game_object__get_component_count")
declare function _core_turinger_game_object__get_component_count(handle: u64): i32;
@external("env", "_core_turinger_game_object__get_component_in_children_by_type")
declare function _core_turinger_game_object__get_component_in_children_by_type(handle: u64, cs_type: u64, include_inactive: bool): u64;
@external("env", "_core_turinger_game_object__get_component_in_parent_by_type")
declare function _core_turinger_game_object__get_component_in_parent_by_type(handle: u64, cs_type: u64, include_inactive: bool): u64;
@external("env", "_core_turinger_game_object__get_component_index")
declare function _core_turinger_game_object__get_component_index(handle: u64, component: u64): i32;
@external("env", "_core_turinger_game_object__get_instance_id")
declare function _core_turinger_game_object__get_instance_id(handle: u64): i32;
@external("env", "_core_turinger_game_object__hide_flags_get")
declare function _core_turinger_game_object__hide_flags_get(handle: u64): i32;
@external("env", "_core_turinger_game_object__hide_flags_set")
declare function _core_turinger_game_object__hide_flags_set(handle: u64, value: i32): void;
@external("env", "_core_turinger_game_object__is_static_get")
declare function _core_turinger_game_object__is_static_get(handle: u64): bool;
@external("env", "_core_turinger_game_object__is_static_set")
declare function _core_turinger_game_object__is_static_set(handle: u64, value: bool): void;
@external("env", "_core_turinger_game_object__layer_get")
declare function _core_turinger_game_object__layer_get(handle: u64): i32;
@external("env", "_core_turinger_game_object__layer_set")
declare function _core_turinger_game_object__layer_set(handle: u64, value: i32): void;
@external("env", "_core_turinger_game_object__name_get")
declare function _core_turinger_game_object__name_get(handle: u64): u32;
@external("env", "_core_turinger_game_object__name_set")
declare function _core_turinger_game_object__name_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_game_object__scene_culling_mask_get")
declare function _core_turinger_game_object__scene_culling_mask_get(handle: u64): u64;
@external("env", "_core_turinger_game_object__send_message")
declare function _core_turinger_game_object__send_message(handle: u64, method_name: u32, options: i32): void;
@external("env", "_core_turinger_game_object__send_message_upwards")
declare function _core_turinger_game_object__send_message_upwards(handle: u64, method_name: u32, options: i32): void;
@external("env", "_core_turinger_game_object__set_active")
declare function _core_turinger_game_object__set_active(handle: u64, value: bool): void;
@external("env", "_core_turinger_game_object__set_active_recursively")
declare function _core_turinger_game_object__set_active_recursively(handle: u64, state: bool): void;
@external("env", "_core_turinger_game_object__tag_get")
declare function _core_turinger_game_object__tag_get(handle: u64): u32;
@external("env", "_core_turinger_game_object__tag_set")
declare function _core_turinger_game_object__tag_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_game_object__transform_get")
declare function _core_turinger_game_object__transform_get(handle: u64): u64;
@external("env", "_core_turinger_game_object_manager__create_object")
declare function _core_turinger_game_object_manager__create_object(name: u32): u64;
@external("env", "_core_turinger_game_object_manager__destroy_object")
declare function _core_turinger_game_object_manager__destroy_object(listener: u64): void;
@external("env", "_core_turinger_game_object_manager__find")
declare function _core_turinger_game_object_manager__find(name: u32): u64;
@external("env", "_core_turinger_game_object_manager__instance_get")
declare function _core_turinger_game_object_manager__instance_get(handle: u64): u64;
@external("env", "_core_turinger_transform__broadcast_message")
declare function _core_turinger_transform__broadcast_message(handle: u64, method_name: u32, parameter: u64, options: i32): void;
@external("env", "_core_turinger_transform__child_count_get")
declare function _core_turinger_transform__child_count_get(handle: u64): i32;
@external("env", "_core_turinger_transform__compare_tag")
declare function _core_turinger_transform__compare_tag(handle: u64, tag: u32): bool;
@external("env", "_core_turinger_transform__detach_children")
declare function _core_turinger_transform__detach_children(handle: u64): void;
@external("env", "_core_turinger_transform__euler_angles_get")
declare function _core_turinger_transform__euler_angles_get(handle: u64): u32;
@external("env", "_core_turinger_transform__euler_angles_set")
declare function _core_turinger_transform__euler_angles_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__find")
declare function _core_turinger_transform__find(handle: u64, n: u32): u64;
@external("env", "_core_turinger_transform__find_child")
declare function _core_turinger_transform__find_child(handle: u64, n: u32): u64;
@external("env", "_core_turinger_transform__forward_get")
declare function _core_turinger_transform__forward_get(handle: u64): u32;
@external("env", "_core_turinger_transform__forward_set")
declare function _core_turinger_transform__forward_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__game_object_get")
declare function _core_turinger_transform__game_object_get(handle: u64): u64;
@external("env", "_core_turinger_transform__get_child")
declare function _core_turinger_transform__get_child(handle: u64, index: i32): u64;
@external("env", "_core_turinger_transform__get_child_count")
declare function _core_turinger_transform__get_child_count(handle: u64): i32;
@external("env", "_core_turinger_transform__get_component_by_name")
declare function _core_turinger_transform__get_component_by_name(handle: u64, cs_type: u32): u64;
@external("env", "_core_turinger_transform__get_component_by_type")
declare function _core_turinger_transform__get_component_by_type(handle: u64, cs_type: u64): u64;
@external("env", "_core_turinger_transform__get_component_in_children_by_type")
declare function _core_turinger_transform__get_component_in_children_by_type(handle: u64, t: u64, include_inactive: bool): u64;
@external("env", "_core_turinger_transform__get_component_in_parent_by_type")
declare function _core_turinger_transform__get_component_in_parent_by_type(handle: u64, t: u64, include_inactive: bool): u64;
@external("env", "_core_turinger_transform__get_component_index")
declare function _core_turinger_transform__get_component_index(handle: u64): i32;
@external("env", "_core_turinger_transform__get_enumerator")
declare function _core_turinger_transform__get_enumerator(handle: u64): u64;
@external("env", "_core_turinger_transform__get_instance_id")
declare function _core_turinger_transform__get_instance_id(handle: u64): i32;
@external("env", "_core_turinger_transform__get_sibling_index")
declare function _core_turinger_transform__get_sibling_index(handle: u64): i32;
@external("env", "_core_turinger_transform__has_changed_get")
declare function _core_turinger_transform__has_changed_get(handle: u64): bool;
@external("env", "_core_turinger_transform__has_changed_set")
declare function _core_turinger_transform__has_changed_set(handle: u64, value: bool): void;
@external("env", "_core_turinger_transform__hide_flags_get")
declare function _core_turinger_transform__hide_flags_get(handle: u64): i32;
@external("env", "_core_turinger_transform__hide_flags_set")
declare function _core_turinger_transform__hide_flags_set(handle: u64, value: i32): void;
@external("env", "_core_turinger_transform__hierarchy_capacity_get")
declare function _core_turinger_transform__hierarchy_capacity_get(handle: u64): i32;
@external("env", "_core_turinger_transform__hierarchy_capacity_set")
declare function _core_turinger_transform__hierarchy_capacity_set(handle: u64, value: i32): void;
@external("env", "_core_turinger_transform__hierarchy_count_get")
declare function _core_turinger_transform__hierarchy_count_get(handle: u64): i32;
@external("env", "_core_turinger_transform__inverse_transform_direction")
declare function _core_turinger_transform__inverse_transform_direction(handle: u64, direction: u32): u32;
@external("env", "_core_turinger_transform__inverse_transform_point")
declare function _core_turinger_transform__inverse_transform_point(handle: u64, position: u32): u32;
@external("env", "_core_turinger_transform__inverse_transform_vector")
declare function _core_turinger_transform__inverse_transform_vector(handle: u64, vector: u32): u32;
@external("env", "_core_turinger_transform__is_child_of")
declare function _core_turinger_transform__is_child_of(handle: u64, parent: u64): bool;
@external("env", "_core_turinger_transform__local_euler_angles_get")
declare function _core_turinger_transform__local_euler_angles_get(handle: u64): u32;
@external("env", "_core_turinger_transform__local_euler_angles_set")
declare function _core_turinger_transform__local_euler_angles_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__local_position_get")
declare function _core_turinger_transform__local_position_get(handle: u64): u32;
@external("env", "_core_turinger_transform__local_position_set")
declare function _core_turinger_transform__local_position_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__local_rotation_get")
declare function _core_turinger_transform__local_rotation_get(handle: u64): u32;
@external("env", "_core_turinger_transform__local_rotation_set")
declare function _core_turinger_transform__local_rotation_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__local_scale_get")
declare function _core_turinger_transform__local_scale_get(handle: u64): u32;
@external("env", "_core_turinger_transform__local_scale_set")
declare function _core_turinger_transform__local_scale_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__local_to_world_matrix_get")
declare function _core_turinger_transform__local_to_world_matrix_get(handle: u64): u32;
@external("env", "_core_turinger_transform__look_at")
declare function _core_turinger_transform__look_at(handle: u64, target: u64, world_up: u32): void;
@external("env", "_core_turinger_transform__lossy_scale_get")
declare function _core_turinger_transform__lossy_scale_get(handle: u64): u32;
@external("env", "_core_turinger_transform__name_get")
declare function _core_turinger_transform__name_get(handle: u64): u32;
@external("env", "_core_turinger_transform__name_set")
declare function _core_turinger_transform__name_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__parent_get")
declare function _core_turinger_transform__parent_get(handle: u64): u64;
@external("env", "_core_turinger_transform__parent_set")
declare function _core_turinger_transform__parent_set(handle: u64, value: u64): void;
@external("env", "_core_turinger_transform__position_get")
declare function _core_turinger_transform__position_get(handle: u64): u32;
@external("env", "_core_turinger_transform__position_set")
declare function _core_turinger_transform__position_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__right_get")
declare function _core_turinger_transform__right_get(handle: u64): u32;
@external("env", "_core_turinger_transform__right_set")
declare function _core_turinger_transform__right_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__root_get")
declare function _core_turinger_transform__root_get(handle: u64): u64;
@external("env", "_core_turinger_transform__rotate")
declare function _core_turinger_transform__rotate(handle: u64, eulers: u32): void;
@external("env", "_core_turinger_transform__rotate_around")
declare function _core_turinger_transform__rotate_around(handle: u64, point: u32, axis: u32, angle: f32): void;
@external("env", "_core_turinger_transform__rotate_around_local")
declare function _core_turinger_transform__rotate_around_local(handle: u64, axis: u32, angle: f32): void;
@external("env", "_core_turinger_transform__rotate_relative")
declare function _core_turinger_transform__rotate_relative(handle: u64, eulers: u32, relative_to: i32): void;
@external("env", "_core_turinger_transform__rotation_get")
declare function _core_turinger_transform__rotation_get(handle: u64): u32;
@external("env", "_core_turinger_transform__rotation_set")
declare function _core_turinger_transform__rotation_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__send_message")
declare function _core_turinger_transform__send_message(handle: u64, method_name: u32, value: u64, options: i32): void;
@external("env", "_core_turinger_transform__send_message_upwards")
declare function _core_turinger_transform__send_message_upwards(handle: u64, method_name: u32, value: u64, options: i32): void;
@external("env", "_core_turinger_transform__set_as_first_sibling")
declare function _core_turinger_transform__set_as_first_sibling(handle: u64): void;
@external("env", "_core_turinger_transform__set_as_last_sibling")
declare function _core_turinger_transform__set_as_last_sibling(handle: u64): void;
@external("env", "_core_turinger_transform__set_local_position_and_rotation")
declare function _core_turinger_transform__set_local_position_and_rotation(handle: u64, local_position: u32, local_rotation: u32): void;
@external("env", "_core_turinger_transform__set_parent")
declare function _core_turinger_transform__set_parent(handle: u64, parent: u64, world_position_stays: bool): void;
@external("env", "_core_turinger_transform__set_position_and_rotation")
declare function _core_turinger_transform__set_position_and_rotation(handle: u64, position: u32, rotation: u32): void;
@external("env", "_core_turinger_transform__set_sibling_index")
declare function _core_turinger_transform__set_sibling_index(handle: u64, index: i32): void;
@external("env", "_core_turinger_transform__tag_get")
declare function _core_turinger_transform__tag_get(handle: u64): u32;
@external("env", "_core_turinger_transform__tag_set")
declare function _core_turinger_transform__tag_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__transform_direction")
declare function _core_turinger_transform__transform_direction(handle: u64, direction: u32): u32;
@external("env", "_core_turinger_transform__transform_get")
declare function _core_turinger_transform__transform_get(handle: u64): u64;
@external("env", "_core_turinger_transform__transform_point")
declare function _core_turinger_transform__transform_point(handle: u64, position: u32): u32;
@external("env", "_core_turinger_transform__transform_vector")
declare function _core_turinger_transform__transform_vector(handle: u64, vector: u32): u32;
@external("env", "_core_turinger_transform__translate")
declare function _core_turinger_transform__translate(handle: u64, translation: u32, relative_to: i32): void;
@external("env", "_core_turinger_transform__translate_relative")
declare function _core_turinger_transform__translate_relative(handle: u64, translation: u32, relative_to: u64): void;
@external("env", "_core_turinger_transform__up_get")
declare function _core_turinger_transform__up_get(handle: u64): u32;
@external("env", "_core_turinger_transform__up_set")
declare function _core_turinger_transform__up_set(handle: u64, value: u32): void;
@external("env", "_core_turinger_transform__world_to_local_matrix_get")
declare function _core_turinger_transform__world_to_local_matrix_get(handle: u64): u32;
@external("env", "_core_xr__get_device_battery_level")
declare function _core_xr__get_device_battery_level(node_int: i32): f32;
@external("env", "_core_xr__get_device_grip_value")
declare function _core_xr__get_device_grip_value(node_int: i32): f32;
@external("env", "_core_xr__get_device_name")
declare function _core_xr__get_device_name(node_int: i32): u32;
@external("env", "_core_xr__get_device_primary_button_state")
declare function _core_xr__get_device_primary_button_state(node_int: i32): bool;
@external("env", "_core_xr__get_device_secondary_button_state")
declare function _core_xr__get_device_secondary_button_state(node_int: i32): bool;
@external("env", "_core_xr__get_device_thumbstick")
declare function _core_xr__get_device_thumbstick(node_int: i32): u32;
@external("env", "_core_xr__get_device_touchpad")
declare function _core_xr__get_device_touchpad(node_int: i32): u32;
@external("env", "_core_xr__get_device_tracking_state")
declare function _core_xr__get_device_tracking_state(node_int: i32): i32;
@external("env", "_core_xr__get_device_trigger_value")
declare function _core_xr__get_device_trigger_value(node_int: i32): f32;
@external("env", "_core_xr__is_device_valid")
declare function _core_xr__is_device_valid(node_int: i32): bool;
@external("env", "_core_xr__send_haptic_impulse")
declare function _core_xr__send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32): void;
@external("env", "_core_xr__stop_haptics")
declare function _core_xr__stop_haptics(node_int: i32): void;
@external("env", "_core_xr___manager_get")
declare function _core_xr___manager_get(handle: u64): u64;

export function _core_semver(): u64 {
    return (0u64 << 32) | (1u64 << 16) | 0u64;
}

export const CORE_VERSION = "0.1.0";


//// Linear Algebra Helpers ////

export function __enqueue_vec2(v: Vec2): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    return 2;
}

export function __dequeue_vec2(): Vec2 {
    return new Vec2(
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

export function __enqueue_vec3(v: Vec3): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    return 3;
}

export function __dequeue_vec3(): Vec3 {
    return new Vec3(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

export function __enqueue_vec4(v: Vec4): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    _host_f32_enqueue(v.w);
    return 4;
}

export function __dequeue_vec4(): Vec4 {
    return new Vec4(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

export function __enqueue_quat(q: Quat): u32 {
    _host_f32_enqueue(q.x);
    _host_f32_enqueue(q.y);
    _host_f32_enqueue(q.z);
    _host_f32_enqueue(q.w);
    return 4;
}

export function __dequeue_quat(): Quat {
    return new Quat(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

export function __enqueue_mat4(m: Mat4): u32 {
    for (let i: i32 = 0; i < 16; i++) {
        _host_f32_enqueue(m.m[i]);
    }
    return 16;
}

export function __dequeue_mat4(): Mat4 {
    let out = new Mat4();
    for (let i: i32 = 0; i < 16; i++) {
        out.m[i] = _host_f32_dequeue();
    }
    return out;
}




//// Functions ////


//// Classes ////

@final
export class Action {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class Action1 {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class BeatmapDataItem {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class Component {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class CustomData {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


    public static create(): CustomData {
        let turing_result = _core_custom_data__create();
        return new CustomData(turing_result);
    }

    public static from_json(json: string): CustomData {
        let turing_handle_json = String.UTF8.encode(json, true);
        let turing_result = _core_custom_data__from_json(turing_handle_json);
        return new CustomData(turing_result);
    }

    public static list_add_bool(list: List1, value: bool): void {
        _core_custom_data__list_add_bool(list.handle, value);
    }

    public static list_add_custom_data(list: List1, value: CustomData): void {
        _core_custom_data__list_add_custom_data(list.handle, value.handle);
    }

    public static list_add_custom_data_list(list: List1, value: List1): void {
        _core_custom_data__list_add_custom_data_list(list.handle, value.handle);
    }

    public static list_add_float(list: List1, value: f32): void {
        _core_custom_data__list_add_float(list.handle, value);
    }

    public static list_add_int(list: List1, value: i32): void {
        _core_custom_data__list_add_int(list.handle, value);
    }

    public static list_add_string(list: List1, value: string): void {
        let turing_handle_value = String.UTF8.encode(value, true);
        _core_custom_data__list_add_string(list.handle, turing_handle_value);
    }

    public static set_bool(custom_data: CustomData, key: string, value: bool): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        _core_custom_data__set_bool(custom_data.handle, turing_handle_key, value);
    }

    public static set_custom_data(custom_data: CustomData, key: string, value: CustomData): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        _core_custom_data__set_custom_data(custom_data.handle, turing_handle_key, value.handle);
    }

    public static set_custom_data_list(custom_data: CustomData, key: string, value: List1): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        _core_custom_data__set_custom_data_list(custom_data.handle, turing_handle_key, value.handle);
    }

    public static set_float(custom_data: CustomData, key: string, value: f32): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        _core_custom_data__set_float(custom_data.handle, turing_handle_key, value);
    }

    public static set_int(custom_data: CustomData, key: string, value: i32): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        _core_custom_data__set_int(custom_data.handle, turing_handle_key, value);
    }

    public static set_string(custom_data: CustomData, key: string, value: string): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        let turing_handle_value = String.UTF8.encode(value, true);
        _core_custom_data__set_string(custom_data.handle, turing_handle_key, turing_handle_value);
    }

    public static to_json(custom_data: CustomData, pretty: bool): string {
        let turing_result = _core_custom_data__to_json(custom_data.handle, pretty);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

}

@final
export class CustomEventData {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    



    public custom_data_get(): CustomData {
        let turing_result = _core_custom_event_data__custom_data_get(this.handle);
        return new CustomData(turing_result);
    }

    public event_type_get(): string {
        let turing_result = _core_custom_event_data__event_type_get(this.handle);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public get_copy(): BeatmapDataItem {
        let turing_result = _core_custom_event_data__get_copy(this.handle);
        return new BeatmapDataItem(turing_result);
    }

    public version_get(): Version {
        let turing_result = _core_custom_event_data__version_get(this.handle);
        return new Version(turing_result);
    }
}

@final
export class CustomNoteData {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


    public static create_custom_basic_note_data(time: f32, beat: f32, rotation: i32, line_index: i32): CustomNoteData {
        let turing_result = _core_custom_note_data__create_custom_basic_note_data(time, beat, rotation, line_index);
        return new CustomNoteData(turing_result);
    }

    public static create_custom_bomb_note_data(time: f32, beat: f32, rotation: i32, line_index: i32): CustomNoteData {
        let turing_result = _core_custom_note_data__create_custom_bomb_note_data(time, beat, rotation, line_index);
        return new CustomNoteData(turing_result);
    }

    public static create_custom_burst_slider_note_data(time: f32, beat: f32, rotation: i32, line_index: i32): CustomNoteData {
        let turing_result = _core_custom_note_data__create_custom_burst_slider_note_data(time, beat, rotation, line_index);
        return new CustomNoteData(turing_result);
    }


    public custom_data_get(): CustomData {
        let turing_result = _core_custom_note_data__custom_data_get(this.handle);
        return new CustomData(turing_result);
    }

    public get_copy(): BeatmapDataItem {
        let turing_result = _core_custom_note_data__get_copy(this.handle);
        return new BeatmapDataItem(turing_result);
    }

    public version_get(): Version {
        let turing_result = _core_custom_note_data__version_get(this.handle);
        return new Version(turing_result);
    }
}

@final
export class CustomObstacleData {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    



    public custom_data_get(): CustomData {
        let turing_result = _core_custom_obstacle_data__custom_data_get(this.handle);
        return new CustomData(turing_result);
    }

    public get_copy(): BeatmapDataItem {
        let turing_result = _core_custom_obstacle_data__get_copy(this.handle);
        return new BeatmapDataItem(turing_result);
    }

    public version_get(): Version {
        let turing_result = _core_custom_obstacle_data__version_get(this.handle);
        return new Version(turing_result);
    }
}

@final
export class GcHelper {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class GameObject {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class GcHelper {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


    public static create(): GCHelper {
        let turing_result = _core_gc_helper__create();
        return new GcHelper(turing_result);
    }


    public dispose(): void {
        _core_gc_helper__dispose(this.handle);
    }

    public invalidate_all_handles(): void {
        _core_gc_helper__invalidate_all_handles(this.handle);
    }

    public wasm_garbage_collect(): void {
        _core_gc_helper__wasm_garbage_collect(this.handle);
    }
}

@final
export class IAudioTimeSource {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class IEnumerator {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class IVariableMovementDataProvider {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class Int32 {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class List1 {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class Log {
    


    public static critical(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _core_log__critical(turing_handle_msg);
    }

    public static debug(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _core_log__debug(turing_handle_msg);
    }

    public static info(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _core_log__info(turing_handle_msg);
    }

    public static warn(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _core_log__warn(turing_handle_msg);
    }

}

@final
export class Mesh {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class NoteControllerBase {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class NoteFloorMovement {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    



    public _audio_time_sync_controller_get(): IAudioTimeSource {
        let turing_result = _core_note_floor_movement___audio_time_sync_controller_get(this.handle);
        return new IAudioTimeSource(turing_result);
    }

    public _beat_time_get(): f32 {
        return _core_note_floor_movement___beat_time_get(this.handle);
    }

    public _beat_time_set(value: f32): void {
        _core_note_floor_movement___beat_time_set(this.handle, value);
    }

    public _inverse_world_rotation_get(): Quat {
        _core_note_floor_movement___inverse_world_rotation_get(this.handle);
        return __dequeue_quat();
    }

    public _inverse_world_rotation_set(value: Quat): void {
        let turing_handle_value = __enqueue_quat(value);
        _core_note_floor_movement___inverse_world_rotation_set(this.handle, turing_handle_value);
    }

    public _local_position_get(): Vec3 {
        _core_note_floor_movement___local_position_get(this.handle);
        return __dequeue_vec3();
    }

    public _local_position_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_note_floor_movement___local_position_set(this.handle, turing_handle_value);
    }

    public _move_end_offset_get(): Vec3 {
        _core_note_floor_movement___move_end_offset_get(this.handle);
        return __dequeue_vec3();
    }

    public _move_end_offset_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_note_floor_movement___move_end_offset_set(this.handle, turing_handle_value);
    }

    public _move_start_offset_get(): Vec3 {
        _core_note_floor_movement___move_start_offset_get(this.handle);
        return __dequeue_vec3();
    }

    public _move_start_offset_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_note_floor_movement___move_start_offset_set(this.handle, turing_handle_value);
    }

    public _player_transforms_get(): PlayerTransforms {
        let turing_result = _core_note_floor_movement___player_transforms_get(this.handle);
        return new PlayerTransforms(turing_result);
    }

    public _rotated_object_get(): Transform {
        let turing_result = _core_note_floor_movement___rotated_object_get(this.handle);
        return new Transform(turing_result);
    }

    public _rotated_object_set(value: Transform): void {
        _core_note_floor_movement___rotated_object_set(this.handle, value.handle);
    }

    public _variable_movement_data_provider_get(): IVariableMovementDataProvider {
        let turing_result = _core_note_floor_movement___variable_movement_data_provider_get(this.handle);
        return new IVariableMovementDataProvider(turing_result);
    }

    public _world_rotation_get(): Quat {
        _core_note_floor_movement___world_rotation_get(this.handle);
        return __dequeue_quat();
    }

    public _world_rotation_set(value: Quat): void {
        let turing_handle_value = __enqueue_quat(value);
        _core_note_floor_movement___world_rotation_set(this.handle, turing_handle_value);
    }

    public distance_to_player_get(): f32 {
        return _core_note_floor_movement__distance_to_player_get(this.handle);
    }

    public end_pos_get(): Vec3 {
        _core_note_floor_movement__end_pos_get(this.handle);
        return __dequeue_vec3();
    }

    public init_floor(world_rotation: f32, beat_time: f32, move_start_offset: Vec3, move_end_offset: Vec3): void {
        let turing_handle_move_start_offset = __enqueue_vec3(move_start_offset);
        let turing_handle_move_end_offset = __enqueue_vec3(move_end_offset);
        _core_note_floor_movement__init(this.handle, world_rotation, beat_time, turing_handle_move_start_offset, turing_handle_move_end_offset);
    }

    public inverse_world_rotation_get(): Quat {
        _core_note_floor_movement__inverse_world_rotation_get(this.handle);
        return __dequeue_quat();
    }

    public local_position_get(): Vec3 {
        _core_note_floor_movement__local_position_get(this.handle);
        return __dequeue_vec3();
    }

    public manual_update(): Vec3 {
        _core_note_floor_movement__manual_update(this.handle);
        return __dequeue_vec3();
    }

    public note_time_get(): f32 {
        return _core_note_floor_movement__note_time_get(this.handle);
    }

    public set_to_start(): Vec3 {
        _core_note_floor_movement__set_to_start(this.handle);
        return __dequeue_vec3();
    }

    public should_move(): bool {
        return _core_note_floor_movement__should_move(this.handle);
    }

    public world_rotation_get(): Quat {
        _core_note_floor_movement__world_rotation_get(this.handle);
        return __dequeue_quat();
    }
}

@final
export class NoteJump {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


    public static k_missed_time_offset_get(): f32 {
        return _core_note_jump__k_missed_time_offset_get();
    }


    public _audio_time_sync_controller_get(): IAudioTimeSource {
        let turing_result = _core_note_jump___audio_time_sync_controller_get(this.handle);
        return new IAudioTimeSource(turing_result);
    }

    public _end_distance_offset_get(): f32 {
        return _core_note_jump___end_distance_offset_get(this.handle);
    }

    public _end_distance_offset_set(value: f32): void {
        _core_note_jump___end_distance_offset_set(this.handle, value);
    }

    public _end_offset_get(): Vec3 {
        _core_note_jump___end_offset_get(this.handle);
        return __dequeue_vec3();
    }

    public _end_offset_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_note_jump___end_offset_set(this.handle, turing_handle_value);
    }

    public _end_pos_get(): Vec3 {
        _core_note_jump___end_pos_get(this.handle);
        return __dequeue_vec3();
    }

    public _end_pos_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_note_jump___end_pos_set(this.handle, turing_handle_value);
    }

    public _end_rotation_get(): Quat {
        _core_note_jump___end_rotation_get(this.handle);
        return __dequeue_quat();
    }

    public _end_rotation_set(value: Quat): void {
        let turing_handle_value = __enqueue_quat(value);
        _core_note_jump___end_rotation_set(this.handle, turing_handle_value);
    }

    public _gravity_base_get(): f32 {
        return _core_note_jump___gravity_base_get(this.handle);
    }

    public _gravity_base_set(value: f32): void {
        _core_note_jump___gravity_base_set(this.handle, value);
    }

    public _gravity_get(): f32 {
        return _core_note_jump___gravity_get(this.handle);
    }

    public _gravity_set(value: f32): void {
        _core_note_jump___gravity_set(this.handle, value);
    }

    public _half_jump_duration_get(): f32 {
        return _core_note_jump___half_jump_duration_get(this.handle);
    }

    public _half_jump_duration_set(value: f32): void {
        _core_note_jump___half_jump_duration_set(this.handle, value);
    }

    public _half_jump_mark_reported_get(): bool {
        return _core_note_jump___half_jump_mark_reported_get(this.handle);
    }

    public _half_jump_mark_reported_set(value: bool): void {
        _core_note_jump___half_jump_mark_reported_set(this.handle, value);
    }

    public _inverse_world_rotation_get(): Quat {
        _core_note_jump___inverse_world_rotation_get(this.handle);
        return __dequeue_quat();
    }

    public _inverse_world_rotation_set(value: Quat): void {
        let turing_handle_value = __enqueue_quat(value);
        _core_note_jump___inverse_world_rotation_set(this.handle, turing_handle_value);
    }

    public _jump_duration_get(): f32 {
        return _core_note_jump___jump_duration_get(this.handle);
    }

    public _jump_duration_set(value: f32): void {
        _core_note_jump___jump_duration_set(this.handle, value);
    }

    public _jump_started_reported_get(): bool {
        return _core_note_jump___jump_started_reported_get(this.handle);
    }

    public _jump_started_reported_set(value: bool): void {
        _core_note_jump___jump_started_reported_set(this.handle, value);
    }

    public _local_position_get(): Vec3 {
        _core_note_jump___local_position_get(this.handle);
        return __dequeue_vec3();
    }

    public _local_position_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_note_jump___local_position_set(this.handle, turing_handle_value);
    }

    public _middle_rotation_get(): Quat {
        _core_note_jump___middle_rotation_get(this.handle);
        return __dequeue_quat();
    }

    public _middle_rotation_set(value: Quat): void {
        let turing_handle_value = __enqueue_quat(value);
        _core_note_jump___middle_rotation_set(this.handle, turing_handle_value);
    }

    public _missed_mark_reported_get(): bool {
        return _core_note_jump___missed_mark_reported_get(this.handle);
    }

    public _missed_mark_reported_set(value: bool): void {
        _core_note_jump___missed_mark_reported_set(this.handle, value);
    }

    public _missed_time_get(): f32 {
        return _core_note_jump___missed_time_get(this.handle);
    }

    public _missed_time_set(value: f32): void {
        _core_note_jump___missed_time_set(this.handle, value);
    }

    public _note_time_get(): f32 {
        return _core_note_jump___note_time_get(this.handle);
    }

    public _note_time_set(value: f32): void {
        _core_note_jump___note_time_set(this.handle, value);
    }

    public _player_space_convertor_get(): PlayerSpaceConvertor {
        let turing_result = _core_note_jump___player_space_convertor_get(this.handle);
        return new PlayerSpaceConvertor(turing_result);
    }

    public _player_transforms_get(): PlayerTransforms {
        let turing_result = _core_note_jump___player_transforms_get(this.handle);
        return new PlayerTransforms(turing_result);
    }

    public _rotate_towards_player_get(): bool {
        return _core_note_jump___rotate_towards_player_get(this.handle);
    }

    public _rotate_towards_player_set(value: bool): void {
        _core_note_jump___rotate_towards_player_set(this.handle, value);
    }

    public _rotated_object_get(): Transform {
        let turing_result = _core_note_jump___rotated_object_get(this.handle);
        return new Transform(turing_result);
    }

    public _rotated_object_set(value: Transform): void {
        _core_note_jump___rotated_object_set(this.handle, value.handle);
    }

    public _start_offset_get(): Vec3 {
        _core_note_jump___start_offset_get(this.handle);
        return __dequeue_vec3();
    }

    public _start_offset_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_note_jump___start_offset_set(this.handle, turing_handle_value);
    }

    public _start_pos_get(): Vec3 {
        _core_note_jump___start_pos_get(this.handle);
        return __dequeue_vec3();
    }

    public _start_pos_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_note_jump___start_pos_set(this.handle, turing_handle_value);
    }

    public _start_rotation_get(): Quat {
        _core_note_jump___start_rotation_get(this.handle);
        return __dequeue_quat();
    }

    public _start_rotation_set(value: Quat): void {
        let turing_handle_value = __enqueue_quat(value);
        _core_note_jump___start_rotation_set(this.handle, turing_handle_value);
    }

    public _three_quarters_mark_reported_get(): bool {
        return _core_note_jump___three_quarters_mark_reported_get(this.handle);
    }

    public _three_quarters_mark_reported_set(value: bool): void {
        _core_note_jump___three_quarters_mark_reported_set(this.handle, value);
    }

    public _variable_movement_data_provider_get(): IVariableMovementDataProvider {
        let turing_result = _core_note_jump___variable_movement_data_provider_get(this.handle);
        return new IVariableMovementDataProvider(turing_result);
    }

    public _world_rotation_get(): Quat {
        _core_note_jump___world_rotation_get(this.handle);
        return __dequeue_quat();
    }

    public _world_rotation_set(value: Quat): void {
        let turing_handle_value = __enqueue_quat(value);
        _core_note_jump___world_rotation_set(this.handle, turing_handle_value);
    }

    public _y_avoidance_down_get(): f32 {
        return _core_note_jump___y_avoidance_down_get(this.handle);
    }

    public _y_avoidance_down_set(value: f32): void {
        _core_note_jump___y_avoidance_down_set(this.handle, value);
    }

    public _y_avoidance_get(): f32 {
        return _core_note_jump___y_avoidance_get(this.handle);
    }

    public _y_avoidance_set(value: f32): void {
        _core_note_jump___y_avoidance_set(this.handle, value);
    }

    public _y_avoidance_up_get(): f32 {
        return _core_note_jump___y_avoidance_up_get(this.handle);
    }

    public _y_avoidance_up_set(value: f32): void {
        _core_note_jump___y_avoidance_up_set(this.handle, value);
    }

    public add_note_jump_did_finish_event(value: Action): void {
        _core_note_jump__add_note_jump_did_finish_event(this.handle, value.handle);
    }

    public add_note_jump_did_pass_half_event(value: Action): void {
        _core_note_jump__add_note_jump_did_pass_half_event(this.handle, value.handle);
    }

    public add_note_jump_did_pass_missed_marker_event(value: Action): void {
        _core_note_jump__add_note_jump_did_pass_missed_marker_event(this.handle, value.handle);
    }

    public add_note_jump_did_pass_three_quarters_event(value: Action1): void {
        _core_note_jump__add_note_jump_did_pass_three_quarters_event(this.handle, value.handle);
    }

    public add_note_jump_did_start_event(value: Action): void {
        _core_note_jump__add_note_jump_did_start_event(this.handle, value.handle);
    }

    public add_note_jump_did_update_progress_event(value: Action1): void {
        _core_note_jump__add_note_jump_did_update_progress_event(this.handle, value.handle);
    }

    public beat_pos_get(): Vec3 {
        _core_note_jump__beat_pos_get(this.handle);
        return __dequeue_vec3();
    }

    public distance_to_player_get(): f32 {
        return _core_note_jump__distance_to_player_get(this.handle);
    }

    public init_note(note_time: f32, world_rotation: f32, move_end_offset: Vec3, jump_end_offset: Vec3, gravity_base: f32, flip_y_side: f32, end_rotation: f32, rotate_towards_player: bool, use_random_rotation: bool): void {
        let turing_handle_move_end_offset = __enqueue_vec3(move_end_offset);
        let turing_handle_jump_end_offset = __enqueue_vec3(jump_end_offset);
        _core_note_jump__init(this.handle, note_time, world_rotation, turing_handle_move_end_offset, turing_handle_jump_end_offset, gravity_base, flip_y_side, end_rotation, rotate_towards_player, use_random_rotation);
    }

    public local_position_get(): Vec3 {
        _core_note_jump__local_position_get(this.handle);
        return __dequeue_vec3();
    }

    public manual_update(): Vec3 {
        _core_note_jump__manual_update(this.handle);
        return __dequeue_vec3();
    }

    public move_vec_get(): Vec3 {
        _core_note_jump__move_vec_get(this.handle);
        return __dequeue_vec3();
    }

    public note_time_get(): f32 {
        return _core_note_jump__note_time_get(this.handle);
    }

    public remove_note_jump_did_finish_event(value: Action): void {
        _core_note_jump__remove_note_jump_did_finish_event(this.handle, value.handle);
    }

    public remove_note_jump_did_pass_half_event(value: Action): void {
        _core_note_jump__remove_note_jump_did_pass_half_event(this.handle, value.handle);
    }

    public remove_note_jump_did_pass_missed_marker_event(value: Action): void {
        _core_note_jump__remove_note_jump_did_pass_missed_marker_event(this.handle, value.handle);
    }

    public remove_note_jump_did_pass_three_quarters_event(value: Action1): void {
        _core_note_jump__remove_note_jump_did_pass_three_quarters_event(this.handle, value.handle);
    }

    public remove_note_jump_did_start_event(value: Action): void {
        _core_note_jump__remove_note_jump_did_start_event(this.handle, value.handle);
    }

    public remove_note_jump_did_update_progress_event(value: Action1): void {
        _core_note_jump__remove_note_jump_did_update_progress_event(this.handle, value.handle);
    }
}

@final
export class NoteManager {
    


    public static add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: CustomData): CustomNoteData {
        let turing_result = _core_note_manager__add_bomb_note(beat, line, layer, custom_data.handle);
        return new CustomNoteData(turing_result);
    }

    public static add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: CustomData): CustomNoteData {
        let turing_result = _core_note_manager__add_color_note(beat, line, layer, color, cut_direction, custom_data.handle);
        return new CustomNoteData(turing_result);
    }

    public static add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: CustomData): CustomObstacleData {
        let turing_result = _core_note_manager__add_obstacle(beat, duration, line, layer, width, height, custom_data.handle);
        return new CustomObstacleData(turing_result);
    }

    public static get_note_controller(n: i32): NoteControllerBase {
        let turing_result = _core_note_manager__get_note_controller(n);
        return new NoteControllerBase(turing_result);
    }

    public static get_note_controller_from_custom(n: CustomNoteData): NoteControllerBase {
        let turing_result = _core_note_manager__get_note_controller_from_custom(n.handle);
        return new NoteControllerBase(turing_result);
    }

    public static get_nth_event(id: i32): CustomEventData {
        let turing_result = _core_note_manager__get_nth_event(id);
        return new CustomEventData(turing_result);
    }

    public static get_nth_note(id: i32): CustomNoteData {
        let turing_result = _core_note_manager__get_nth_note(id);
        return new CustomNoteData(turing_result);
    }

    public static get_nth_object(id: i32): BeatmapDataItem {
        let turing_result = _core_note_manager__get_nth_object(id);
        return new BeatmapDataItem(turing_result);
    }

    public static get_nth_obstacle(id: i32): CustomObstacleData {
        let turing_result = _core_note_manager__get_nth_obstacle(id);
        return new CustomObstacleData(turing_result);
    }

    public static get_obstacle_controller(n: i32): ObstacleControllerBase {
        let turing_result = _core_note_manager__get_obstacle_controller(n);
        return new ObstacleControllerBase(turing_result);
    }

    public static get_obstacle_controller_from_custom(n: CustomObstacleData): ObstacleController {
        let turing_result = _core_note_manager__get_obstacle_controller_from_custom(n.handle);
        return new ObstacleController(turing_result);
    }

    public static time_to_beat(time: f32): f32 {
        return _core_note_manager__time_to_beat(time);
    }

}

@final
export class Object {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class ObstacleController {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class ObstacleControllerBase {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class PlayerSpaceConvertor {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class PlayerTransforms {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class TaskScheduler {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


    public static schedule(task: Action): void {
        _core_task_scheduler__schedule(task.handle);
    }


    public dispose(): void {
        _core_task_scheduler__dispose(this.handle);
    }
}

@final
export class Transform {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class TuringMesh {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    



    public _mesh_get(): Mesh {
        let turing_result = _core_turing_mesh___mesh_get(this.handle);
        return new Mesh(turing_result);
    }

    public _mesh_set(value: Mesh): void {
        _core_turing_mesh___mesh_set(this.handle, value.handle);
    }

    public clear(): void {
        _core_turing_mesh__clear(this.handle);
    }

    public get_bounds_max_x(): f32 {
        return _core_turing_mesh__get_bounds_max_x(this.handle);
    }

    public get_bounds_max_y(): f32 {
        return _core_turing_mesh__get_bounds_max_y(this.handle);
    }

    public get_bounds_max_z(): f32 {
        return _core_turing_mesh__get_bounds_max_z(this.handle);
    }

    public get_bounds_min_x(): f32 {
        return _core_turing_mesh__get_bounds_min_x(this.handle);
    }

    public get_bounds_min_y(): f32 {
        return _core_turing_mesh__get_bounds_min_y(this.handle);
    }

    public get_bounds_min_z(): f32 {
        return _core_turing_mesh__get_bounds_min_z(this.handle);
    }

    public get_instance_id(): i32 {
        return _core_turing_mesh__get_instance_id(this.handle);
    }

    public get_u_vs(channel: i32): Array<u32> {
        let turing_result = _core_turing_mesh__get_u_vs(this.handle, channel);
        let turing_buf = heap.alloc(usize(turing_result) * sizeof<u32>());
        _host_bufcpy(u32(turing_buf), turing_result);
        let view = Uint32Array.wrap(turing_buf, turing_result);
        let arr = Array.from(view);
        heap.free(turing_buf);
        return arr;
    }

    public get_vertices(): Array<u32> {
        let turing_result = _core_turing_mesh__get_vertices(this.handle);
        let turing_buf = heap.alloc(usize(turing_result) * sizeof<u32>());
        _host_bufcpy(u32(turing_buf), turing_result);
        let view = Uint32Array.wrap(turing_buf, turing_result);
        let arr = Array.from(view);
        heap.free(turing_buf);
        return arr;
    }

    public hide_flags_get(): void {
        _core_turing_mesh__hide_flags_get(this.handle);
    }

    public hide_flags_set(): void {
        _core_turing_mesh__hide_flags_set(this.handle);
    }

    public mark_modified(): void {
        _core_turing_mesh__mark_modified(this.handle);
    }

    public name_get(): string {
        let turing_result = _core_turing_mesh__name_get(this.handle);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public name_set(value: string): void {
        let turing_handle_value = String.UTF8.encode(value, true);
        _core_turing_mesh__name_set(this.handle, turing_handle_value);
    }

    public optimize(): void {
        _core_turing_mesh__optimize(this.handle);
    }

    public optimize_index_buffers(): void {
        _core_turing_mesh__optimize_index_buffers(this.handle);
    }

    public recalculate_bounds(): void {
        _core_turing_mesh__recalculate_bounds(this.handle);
    }

    public recalculate_normals(): void {
        _core_turing_mesh__recalculate_normals(this.handle);
    }

    public recalculate_tangents(): void {
        _core_turing_mesh__recalculate_tangents(this.handle);
    }

    public set_bounds(min_x: f32, min_y: f32, min_z: f32, max_x: f32, max_y: f32, max_z: f32): void {
        _core_turing_mesh__set_bounds(this.handle, min_x, min_y, min_z, max_x, max_y, max_z);
    }

    public set_triangles(triangles: Int32, submesh: i32, calculate_bounds: bool, base_vertex: i32): void {
        _core_turing_mesh__set_triangles(this.handle, triangles.handle, submesh, calculate_bounds, base_vertex);
    }

    public set_u_vs(channel: i32, uvs: Array<u32>): void {
        _host_u32_enqueue(u32(uvs.length));
        let turing_view_uvs = Uint32Array.wrap(uvs);
        let turing_handle_uvs = turing_view_uvs.dataStart;
        _core_turing_mesh__set_u_vs(this.handle, channel, turing_handle_uvs);
    }

    public set_vertices(in_vertices: Array<u32>): void {
        _host_u32_enqueue(u32(in_vertices.length));
        let turing_view_in_vertices = Uint32Array.wrap(in_vertices);
        let turing_handle_in_vertices = turing_view_in_vertices.dataStart;
        _core_turing_mesh__set_vertices(this.handle, turing_handle_in_vertices);
    }

    public upload_mesh_data(mark_no_longer_readable: bool): void {
        _core_turing_mesh__upload_mesh_data(this.handle, mark_no_longer_readable);
    }
}

@final
export class TuringScriptManager {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class TuringerGameObject {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    



    public active_get(): bool {
        return _core_turinger_game_object__active_get(this.handle);
    }

    public active_in_hierarchy_get(): bool {
        return _core_turinger_game_object__active_in_hierarchy_get(this.handle);
    }

    public active_self_get(): bool {
        return _core_turinger_game_object__active_self_get(this.handle);
    }

    public active_set(value: bool): void {
        _core_turinger_game_object__active_set(this.handle, value);
    }

    public add_component(component_type: Type): Component {
        let turing_result = _core_turinger_game_object__add_component(this.handle, component_type.handle);
        return new Component(turing_result);
    }

    public add_or_get_mesh(): TuringMesh {
        let turing_result = _core_turinger_game_object__add_or_get_mesh(this.handle);
        return new TuringMesh(turing_result);
    }

    public broadcast_message(method_name: string, options: i32): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _core_turinger_game_object__broadcast_message(this.handle, turing_handle_method_name, options);
    }

    public compare_tag(tag: string): bool {
        let turing_handle_tag = String.UTF8.encode(tag, true);
        return _core_turinger_game_object__compare_tag(this.handle, turing_handle_tag);
    }

    public game_object_get(): GameObject {
        let turing_result = _core_turinger_game_object__game_object_get(this.handle);
        return new GameObject(turing_result);
    }

    public get_component_at_index(index: i32): Component {
        let turing_result = _core_turinger_game_object__get_component_at_index(this.handle, index);
        return new Component(turing_result);
    }

    public get_component_by_name(cs_type: string): Component {
        let turing_handle_cs_type = String.UTF8.encode(cs_type, true);
        let turing_result = _core_turinger_game_object__get_component_by_name(this.handle, turing_handle_cs_type);
        return new Component(turing_result);
    }

    public get_component_by_type(cs_type: Type): Component {
        let turing_result = _core_turinger_game_object__get_component_by_type(this.handle, cs_type.handle);
        return new Component(turing_result);
    }

    public get_component_count(): i32 {
        return _core_turinger_game_object__get_component_count(this.handle);
    }

    public get_component_in_children_by_type(cs_type: Type, include_inactive: bool): Component {
        let turing_result = _core_turinger_game_object__get_component_in_children_by_type(this.handle, cs_type.handle, include_inactive);
        return new Component(turing_result);
    }

    public get_component_in_parent_by_type(cs_type: Type, include_inactive: bool): Component {
        let turing_result = _core_turinger_game_object__get_component_in_parent_by_type(this.handle, cs_type.handle, include_inactive);
        return new Component(turing_result);
    }

    public get_component_index(component: Component): i32 {
        return _core_turinger_game_object__get_component_index(this.handle, component.handle);
    }

    public get_instance_id(): i32 {
        return _core_turinger_game_object__get_instance_id(this.handle);
    }

    public hide_flags_get(): i32 {
        return _core_turinger_game_object__hide_flags_get(this.handle);
    }

    public hide_flags_set(value: i32): void {
        _core_turinger_game_object__hide_flags_set(this.handle, value);
    }

    public is_static_get(): bool {
        return _core_turinger_game_object__is_static_get(this.handle);
    }

    public is_static_set(value: bool): void {
        _core_turinger_game_object__is_static_set(this.handle, value);
    }

    public layer_get(): i32 {
        return _core_turinger_game_object__layer_get(this.handle);
    }

    public layer_set(value: i32): void {
        _core_turinger_game_object__layer_set(this.handle, value);
    }

    public name_get(): string {
        let turing_result = _core_turinger_game_object__name_get(this.handle);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public name_set(value: string): void {
        let turing_handle_value = String.UTF8.encode(value, true);
        _core_turinger_game_object__name_set(this.handle, turing_handle_value);
    }

    public scene_culling_mask_get(): u64 {
        return _core_turinger_game_object__scene_culling_mask_get(this.handle);
    }

    public send_message(method_name: string, options: i32): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _core_turinger_game_object__send_message(this.handle, turing_handle_method_name, options);
    }

    public send_message_upwards(method_name: string, options: i32): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _core_turinger_game_object__send_message_upwards(this.handle, turing_handle_method_name, options);
    }

    public set_active(value: bool): void {
        _core_turinger_game_object__set_active(this.handle, value);
    }

    public set_active_recursively(state: bool): void {
        _core_turinger_game_object__set_active_recursively(this.handle, state);
    }

    public tag_get(): string {
        let turing_result = _core_turinger_game_object__tag_get(this.handle);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public tag_set(value: string): void {
        let turing_handle_value = String.UTF8.encode(value, true);
        _core_turinger_game_object__tag_set(this.handle, turing_handle_value);
    }

    public transform_get(): TuringerTransform {
        let turing_result = _core_turinger_game_object__transform_get(this.handle);
        return new TuringerTransform(turing_result);
    }
}

@final
export class TuringerGameObjectManager {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


    public static create_object(name: string): TuringerGameObject {
        let turing_handle_name = String.UTF8.encode(name, true);
        let turing_result = _core_turinger_game_object_manager__create_object(turing_handle_name);
        return new TuringerGameObject(turing_result);
    }

    public static destroy_object(listener: TuringerGameObject): void {
        _core_turinger_game_object_manager__destroy_object(listener.handle);
    }

    public static find(name: string): TuringerGameObject {
        let turing_handle_name = String.UTF8.encode(name, true);
        let turing_result = _core_turinger_game_object_manager__find(turing_handle_name);
        return new TuringerGameObject(turing_result);
    }


    public instance_get(): TuringerGameObjectManager {
        let turing_result = _core_turinger_game_object_manager__instance_get(this.handle);
        return new TuringerGameObjectManager(turing_result);
    }
}

@final
export class TuringerTransform {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    



    public broadcast_message(method_name: string, parameter: Object, options: i32): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _core_turinger_transform__broadcast_message(this.handle, turing_handle_method_name, parameter.handle, options);
    }

    public child_count_get(): i32 {
        return _core_turinger_transform__child_count_get(this.handle);
    }

    public compare_tag(tag: string): bool {
        let turing_handle_tag = String.UTF8.encode(tag, true);
        return _core_turinger_transform__compare_tag(this.handle, turing_handle_tag);
    }

    public detach_children(): void {
        _core_turinger_transform__detach_children(this.handle);
    }

    public euler_angles_get(): Vec3 {
        _core_turinger_transform__euler_angles_get(this.handle);
        return __dequeue_vec3();
    }

    public euler_angles_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_turinger_transform__euler_angles_set(this.handle, turing_handle_value);
    }

    public find(n: string): TuringerTransform {
        let turing_handle_n = String.UTF8.encode(n, true);
        let turing_result = _core_turinger_transform__find(this.handle, turing_handle_n);
        return new TuringerTransform(turing_result);
    }

    public find_child(n: string): TuringerTransform {
        let turing_handle_n = String.UTF8.encode(n, true);
        let turing_result = _core_turinger_transform__find_child(this.handle, turing_handle_n);
        return new TuringerTransform(turing_result);
    }

    public forward_get(): Vec3 {
        _core_turinger_transform__forward_get(this.handle);
        return __dequeue_vec3();
    }

    public forward_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_turinger_transform__forward_set(this.handle, turing_handle_value);
    }

    public game_object_get(): TuringerGameObject {
        let turing_result = _core_turinger_transform__game_object_get(this.handle);
        return new TuringerGameObject(turing_result);
    }

    public get_child(index: i32): TuringerTransform {
        let turing_result = _core_turinger_transform__get_child(this.handle, index);
        return new TuringerTransform(turing_result);
    }

    public get_child_count(): i32 {
        return _core_turinger_transform__get_child_count(this.handle);
    }

    public get_component_by_name(cs_type: string): Component {
        let turing_handle_cs_type = String.UTF8.encode(cs_type, true);
        let turing_result = _core_turinger_transform__get_component_by_name(this.handle, turing_handle_cs_type);
        return new Component(turing_result);
    }

    public get_component_by_type(cs_type: Type): Component {
        let turing_result = _core_turinger_transform__get_component_by_type(this.handle, cs_type.handle);
        return new Component(turing_result);
    }

    public get_component_in_children_by_type(t: Type, include_inactive: bool): Component {
        let turing_result = _core_turinger_transform__get_component_in_children_by_type(this.handle, t.handle, include_inactive);
        return new Component(turing_result);
    }

    public get_component_in_parent_by_type(t: Type, include_inactive: bool): Component {
        let turing_result = _core_turinger_transform__get_component_in_parent_by_type(this.handle, t.handle, include_inactive);
        return new Component(turing_result);
    }

    public get_component_index(): i32 {
        return _core_turinger_transform__get_component_index(this.handle);
    }

    public get_enumerator(): IEnumerator {
        let turing_result = _core_turinger_transform__get_enumerator(this.handle);
        return new IEnumerator(turing_result);
    }

    public get_instance_id(): i32 {
        return _core_turinger_transform__get_instance_id(this.handle);
    }

    public get_sibling_index(): i32 {
        return _core_turinger_transform__get_sibling_index(this.handle);
    }

    public has_changed_get(): bool {
        return _core_turinger_transform__has_changed_get(this.handle);
    }

    public has_changed_set(value: bool): void {
        _core_turinger_transform__has_changed_set(this.handle, value);
    }

    public hide_flags_get(): i32 {
        return _core_turinger_transform__hide_flags_get(this.handle);
    }

    public hide_flags_set(value: i32): void {
        _core_turinger_transform__hide_flags_set(this.handle, value);
    }

    public hierarchy_capacity_get(): i32 {
        return _core_turinger_transform__hierarchy_capacity_get(this.handle);
    }

    public hierarchy_capacity_set(value: i32): void {
        _core_turinger_transform__hierarchy_capacity_set(this.handle, value);
    }

    public hierarchy_count_get(): i32 {
        return _core_turinger_transform__hierarchy_count_get(this.handle);
    }

    public inverse_transform_direction(direction: Vec3): Vec3 {
        let turing_handle_direction = __enqueue_vec3(direction);
        _core_turinger_transform__inverse_transform_direction(this.handle, turing_handle_direction);
        return __dequeue_vec3();
    }

    public inverse_transform_point(position: Vec3): Vec3 {
        let turing_handle_position = __enqueue_vec3(position);
        _core_turinger_transform__inverse_transform_point(this.handle, turing_handle_position);
        return __dequeue_vec3();
    }

    public inverse_transform_vector(vector: Vec3): Vec3 {
        let turing_handle_vector = __enqueue_vec3(vector);
        _core_turinger_transform__inverse_transform_vector(this.handle, turing_handle_vector);
        return __dequeue_vec3();
    }

    public is_child_of(parent: TuringerTransform): bool {
        return _core_turinger_transform__is_child_of(this.handle, parent.handle);
    }

    public local_euler_angles_get(): Vec3 {
        _core_turinger_transform__local_euler_angles_get(this.handle);
        return __dequeue_vec3();
    }

    public local_euler_angles_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_turinger_transform__local_euler_angles_set(this.handle, turing_handle_value);
    }

    public local_position_get(): Vec3 {
        _core_turinger_transform__local_position_get(this.handle);
        return __dequeue_vec3();
    }

    public local_position_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_turinger_transform__local_position_set(this.handle, turing_handle_value);
    }

    public local_rotation_get(): Quat {
        _core_turinger_transform__local_rotation_get(this.handle);
        return __dequeue_quat();
    }

    public local_rotation_set(value: Quat): void {
        let turing_handle_value = __enqueue_quat(value);
        _core_turinger_transform__local_rotation_set(this.handle, turing_handle_value);
    }

    public local_scale_get(): Vec3 {
        _core_turinger_transform__local_scale_get(this.handle);
        return __dequeue_vec3();
    }

    public local_scale_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_turinger_transform__local_scale_set(this.handle, turing_handle_value);
    }

    public local_to_world_matrix_get(): Mat4 {
        _core_turinger_transform__local_to_world_matrix_get(this.handle);
        return __dequeue_mat4();
    }

    public look_at(target: TuringerTransform, world_up: Vec3): void {
        let turing_handle_world_up = __enqueue_vec3(world_up);
        _core_turinger_transform__look_at(this.handle, target.handle, turing_handle_world_up);
    }

    public lossy_scale_get(): Vec3 {
        _core_turinger_transform__lossy_scale_get(this.handle);
        return __dequeue_vec3();
    }

    public name_get(): string {
        let turing_result = _core_turinger_transform__name_get(this.handle);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public name_set(value: string): void {
        let turing_handle_value = String.UTF8.encode(value, true);
        _core_turinger_transform__name_set(this.handle, turing_handle_value);
    }

    public parent_get(): TuringerTransform {
        let turing_result = _core_turinger_transform__parent_get(this.handle);
        return new TuringerTransform(turing_result);
    }

    public parent_set(value: TuringerTransform): void {
        _core_turinger_transform__parent_set(this.handle, value.handle);
    }

    public position_get(): Vec3 {
        _core_turinger_transform__position_get(this.handle);
        return __dequeue_vec3();
    }

    public position_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_turinger_transform__position_set(this.handle, turing_handle_value);
    }

    public right_get(): Vec3 {
        _core_turinger_transform__right_get(this.handle);
        return __dequeue_vec3();
    }

    public right_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_turinger_transform__right_set(this.handle, turing_handle_value);
    }

    public root_get(): TuringerTransform {
        let turing_result = _core_turinger_transform__root_get(this.handle);
        return new TuringerTransform(turing_result);
    }

    public rotate(eulers: Vec3): void {
        let turing_handle_eulers = __enqueue_vec3(eulers);
        _core_turinger_transform__rotate(this.handle, turing_handle_eulers);
    }

    public rotate_around(point: Vec3, axis: Vec3, angle: f32): void {
        let turing_handle_point = __enqueue_vec3(point);
        let turing_handle_axis = __enqueue_vec3(axis);
        _core_turinger_transform__rotate_around(this.handle, turing_handle_point, turing_handle_axis, angle);
    }

    public rotate_around_local(axis: Vec3, angle: f32): void {
        let turing_handle_axis = __enqueue_vec3(axis);
        _core_turinger_transform__rotate_around_local(this.handle, turing_handle_axis, angle);
    }

    public rotate_relative(eulers: Vec3, relative_to: i32): void {
        let turing_handle_eulers = __enqueue_vec3(eulers);
        _core_turinger_transform__rotate_relative(this.handle, turing_handle_eulers, relative_to);
    }

    public rotation_get(): Quat {
        _core_turinger_transform__rotation_get(this.handle);
        return __dequeue_quat();
    }

    public rotation_set(value: Quat): void {
        let turing_handle_value = __enqueue_quat(value);
        _core_turinger_transform__rotation_set(this.handle, turing_handle_value);
    }

    public send_message(method_name: string, value: Object, options: i32): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _core_turinger_transform__send_message(this.handle, turing_handle_method_name, value.handle, options);
    }

    public send_message_upwards(method_name: string, value: Object, options: i32): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _core_turinger_transform__send_message_upwards(this.handle, turing_handle_method_name, value.handle, options);
    }

    public set_as_first_sibling(): void {
        _core_turinger_transform__set_as_first_sibling(this.handle);
    }

    public set_as_last_sibling(): void {
        _core_turinger_transform__set_as_last_sibling(this.handle);
    }

    public set_local_position_and_rotation(local_position: Vec3, local_rotation: Quat): void {
        let turing_handle_local_position = __enqueue_vec3(local_position);
        let turing_handle_local_rotation = __enqueue_quat(local_rotation);
        _core_turinger_transform__set_local_position_and_rotation(this.handle, turing_handle_local_position, turing_handle_local_rotation);
    }

    public set_parent(parent: TuringerTransform, world_position_stays: bool): void {
        _core_turinger_transform__set_parent(this.handle, parent.handle, world_position_stays);
    }

    public set_position_and_rotation(position: Vec3, rotation: Quat): void {
        let turing_handle_position = __enqueue_vec3(position);
        let turing_handle_rotation = __enqueue_quat(rotation);
        _core_turinger_transform__set_position_and_rotation(this.handle, turing_handle_position, turing_handle_rotation);
    }

    public set_sibling_index(index: i32): void {
        _core_turinger_transform__set_sibling_index(this.handle, index);
    }

    public tag_get(): string {
        let turing_result = _core_turinger_transform__tag_get(this.handle);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public tag_set(value: string): void {
        let turing_handle_value = String.UTF8.encode(value, true);
        _core_turinger_transform__tag_set(this.handle, turing_handle_value);
    }

    public transform_direction(direction: Vec3): Vec3 {
        let turing_handle_direction = __enqueue_vec3(direction);
        _core_turinger_transform__transform_direction(this.handle, turing_handle_direction);
        return __dequeue_vec3();
    }

    public transform_get(): Transform {
        let turing_result = _core_turinger_transform__transform_get(this.handle);
        return new Transform(turing_result);
    }

    public transform_point(position: Vec3): Vec3 {
        let turing_handle_position = __enqueue_vec3(position);
        _core_turinger_transform__transform_point(this.handle, turing_handle_position);
        return __dequeue_vec3();
    }

    public transform_vector(vector: Vec3): Vec3 {
        let turing_handle_vector = __enqueue_vec3(vector);
        _core_turinger_transform__transform_vector(this.handle, turing_handle_vector);
        return __dequeue_vec3();
    }

    public translate(translation: Vec3, relative_to: i32): void {
        let turing_handle_translation = __enqueue_vec3(translation);
        _core_turinger_transform__translate(this.handle, turing_handle_translation, relative_to);
    }

    public translate_relative(translation: Vec3, relative_to: TuringerTransform): void {
        let turing_handle_translation = __enqueue_vec3(translation);
        _core_turinger_transform__translate_relative(this.handle, turing_handle_translation, relative_to.handle);
    }

    public up_get(): Vec3 {
        _core_turinger_transform__up_get(this.handle);
        return __dequeue_vec3();
    }

    public up_set(value: Vec3): void {
        let turing_handle_value = __enqueue_vec3(value);
        _core_turinger_transform__up_set(this.handle, turing_handle_value);
    }

    public world_to_local_matrix_get(): Mat4 {
        _core_turinger_transform__world_to_local_matrix_get(this.handle);
        return __dequeue_mat4();
    }
}

@final
export class Type {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class Version {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class Xr {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


    public static get_device_battery_level(node_int: i32): f32 {
        return _core_xr__get_device_battery_level(node_int);
    }

    public static get_device_grip_value(node_int: i32): f32 {
        return _core_xr__get_device_grip_value(node_int);
    }

    public static get_device_name(node_int: i32): string {
        let turing_result = _core_xr__get_device_name(node_int);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public static get_device_primary_button_state(node_int: i32): bool {
        return _core_xr__get_device_primary_button_state(node_int);
    }

    public static get_device_secondary_button_state(node_int: i32): bool {
        return _core_xr__get_device_secondary_button_state(node_int);
    }

    public static get_device_thumbstick(node_int: i32): Vec2 {
        _core_xr__get_device_thumbstick(node_int);
        return __dequeue_vec2();
    }

    public static get_device_touchpad(node_int: i32): Vec2 {
        _core_xr__get_device_touchpad(node_int);
        return __dequeue_vec2();
    }

    public static get_device_tracking_state(node_int: i32): i32 {
        return _core_xr__get_device_tracking_state(node_int);
    }

    public static get_device_trigger_value(node_int: i32): f32 {
        return _core_xr__get_device_trigger_value(node_int);
    }

    public static is_device_valid(node_int: i32): bool {
        return _core_xr__is_device_valid(node_int);
    }

    public static send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32): void {
        _core_xr__send_haptic_impulse(node_int, amplitude, duration);
    }

    public static stop_haptics(node_int: i32): void {
        _core_xr__stop_haptics(node_int);
    }


    public _manager_get(): TuringScriptManager {
        let turing_result = _core_xr___manager_get(this.handle);
        return new TuringScriptManager(turing_result);
    }
}



