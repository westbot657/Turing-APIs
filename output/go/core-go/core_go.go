


///// Generated Go API /////
package core

//// Wasm Bindings ////

//go:wasmimport env _host_strcpy
func _host_strcpy(location *byte, size uint32)
//go:wasmimport env _host_bufcpy
func _host_bufcpy(location *uint32, size uint32)
//go:wasmimport env _host_f32_enqueue
func _host_f32_enqueue(f: float32)
//go:wasmimport env _host_f32_dequeue
func _host_f32_dequeue() float32
//go:wasmimport env _host_u32_enqueue
func _host_u32_enqueue(u: uint32)
//go:wasmimport env _host_u32_dequeue
func _host_u32_dequeue() uint32


//go:wasmimport env _core_custom_data__create
func _core_custom_data__create() CustomData
//go:wasmimport env _core_custom_data__from_json
func _core_custom_data__from_json(json uint32) CustomData
//go:wasmimport env _core_custom_data__list_add_bool
func _core_custom_data__list_add_bool(list List1, value bool) void
//go:wasmimport env _core_custom_data__list_add_custom_data
func _core_custom_data__list_add_custom_data(list List1, value CustomData) void
//go:wasmimport env _core_custom_data__list_add_custom_data_list
func _core_custom_data__list_add_custom_data_list(list List1, value List1) void
//go:wasmimport env _core_custom_data__list_add_float
func _core_custom_data__list_add_float(list List1, value float32) void
//go:wasmimport env _core_custom_data__list_add_int
func _core_custom_data__list_add_int(list List1, value int32) void
//go:wasmimport env _core_custom_data__list_add_string
func _core_custom_data__list_add_string(list List1, value uint32) void
//go:wasmimport env _core_custom_data__set_bool
func _core_custom_data__set_bool(custom_data CustomData, key uint32, value bool) void
//go:wasmimport env _core_custom_data__set_custom_data
func _core_custom_data__set_custom_data(custom_data CustomData, key uint32, value CustomData) void
//go:wasmimport env _core_custom_data__set_custom_data_list
func _core_custom_data__set_custom_data_list(custom_data CustomData, key uint32, value List1) void
//go:wasmimport env _core_custom_data__set_float
func _core_custom_data__set_float(custom_data CustomData, key uint32, value float32) void
//go:wasmimport env _core_custom_data__set_int
func _core_custom_data__set_int(custom_data CustomData, key uint32, value int32) void
//go:wasmimport env _core_custom_data__set_string
func _core_custom_data__set_string(custom_data CustomData, key uint32, value uint32) void
//go:wasmimport env _core_custom_data__to_json
func _core_custom_data__to_json(custom_data CustomData, pretty bool) uint32
//go:wasmimport env _core_custom_event_data__custom_data_get
func _core_custom_event_data__custom_data_get(handle CustomEventData) CustomData
//go:wasmimport env _core_custom_event_data__event_type_get
func _core_custom_event_data__event_type_get(handle CustomEventData) uint32
//go:wasmimport env _core_custom_event_data__get_copy
func _core_custom_event_data__get_copy(handle CustomEventData) BeatmapDataItem
//go:wasmimport env _core_custom_event_data__version_get
func _core_custom_event_data__version_get(handle CustomEventData) Version
//go:wasmimport env _core_custom_note_data__create_custom_basic_note_data
func _core_custom_note_data__create_custom_basic_note_data(time float32, beat float32, rotation int32, line_index int32, note_line_layer int32, color_type int32, cut_direction int32, custom_data CustomData, version Version) CustomNoteData
//go:wasmimport env _core_custom_note_data__create_custom_bomb_note_data
func _core_custom_note_data__create_custom_bomb_note_data(time float32, beat float32, rotation int32, line_index int32, note_line_layer int32, custom_data CustomData, version Version) CustomNoteData
//go:wasmimport env _core_custom_note_data__create_custom_burst_slider_note_data
func _core_custom_note_data__create_custom_burst_slider_note_data(time float32, beat float32, rotation int32, line_index int32, note_line_layer int32, before_jump_note_line_layer int32, color_type int32, cut_direction int32, cut_sfx_volume_multiplier float32, custom_data CustomData) CustomNoteData
//go:wasmimport env _core_custom_note_data__custom_data_get
func _core_custom_note_data__custom_data_get(handle CustomNoteData) CustomData
//go:wasmimport env _core_custom_note_data__get_copy
func _core_custom_note_data__get_copy(handle CustomNoteData) BeatmapDataItem
//go:wasmimport env _core_custom_note_data__version_get
func _core_custom_note_data__version_get(handle CustomNoteData) Version
//go:wasmimport env _core_custom_obstacle_data__custom_data_get
func _core_custom_obstacle_data__custom_data_get(handle CustomObstacleData) CustomData
//go:wasmimport env _core_custom_obstacle_data__get_copy
func _core_custom_obstacle_data__get_copy(handle CustomObstacleData) BeatmapDataItem
//go:wasmimport env _core_custom_obstacle_data__version_get
func _core_custom_obstacle_data__version_get(handle CustomObstacleData) Version
//go:wasmimport env _core_game_object__add_component
func _core_game_object__add_component(handle GameObject, component_type Type) Component
//go:wasmimport env _core_game_object__add_or_get_mesh
func _core_game_object__add_or_get_mesh(handle GameObject) TuringMesh
//go:wasmimport env _core_game_object__broadcast_message
func _core_game_object__broadcast_message(handle GameObject, method_name uint32, options int32) void
//go:wasmimport env _core_game_object__compare_tag
func _core_game_object__compare_tag(handle GameObject, tag uint32) bool
//go:wasmimport env _core_game_object__get_active
func _core_game_object__get_active(handle GameObject) bool
//go:wasmimport env _core_game_object__get_active_in_hierarchy
func _core_game_object__get_active_in_hierarchy(handle GameObject) bool
//go:wasmimport env _core_game_object__get_active_self
func _core_game_object__get_active_self(handle GameObject) bool
//go:wasmimport env _core_game_object__get_component_at_index
func _core_game_object__get_component_at_index(handle GameObject, index int32) Component
//go:wasmimport env _core_game_object__get_component_by_name
func _core_game_object__get_component_by_name(handle GameObject, cs_type uint32) Component
//go:wasmimport env _core_game_object__get_component_by_type
func _core_game_object__get_component_by_type(handle GameObject, cs_type Type) Component
//go:wasmimport env _core_game_object__get_component_count
func _core_game_object__get_component_count(handle GameObject) int32
//go:wasmimport env _core_game_object__get_component_in_children_by_type
func _core_game_object__get_component_in_children_by_type(handle GameObject, cs_type Type, include_inactive bool) Component
//go:wasmimport env _core_game_object__get_component_in_parent_by_type
func _core_game_object__get_component_in_parent_by_type(handle GameObject, cs_type Type, include_inactive bool) Component
//go:wasmimport env _core_game_object__get_component_index
func _core_game_object__get_component_index(handle GameObject, component Component) int32
//go:wasmimport env _core_game_object__get_hide_flags
func _core_game_object__get_hide_flags(handle GameObject) int32
//go:wasmimport env _core_game_object__get_instance_id
func _core_game_object__get_instance_id(handle GameObject) int32
//go:wasmimport env _core_game_object__get_is_static
func _core_game_object__get_is_static(handle GameObject) bool
//go:wasmimport env _core_game_object__get_layer
func _core_game_object__get_layer(handle GameObject) int32
//go:wasmimport env _core_game_object__get_name
func _core_game_object__get_name(handle GameObject) uint32
//go:wasmimport env _core_game_object__get_scene_culling_mask
func _core_game_object__get_scene_culling_mask(handle GameObject) uint64
//go:wasmimport env _core_game_object__get_tag
func _core_game_object__get_tag(handle GameObject) uint32
//go:wasmimport env _core_game_object__get_transform
func _core_game_object__get_transform(handle GameObject) Transform
//go:wasmimport env _core_game_object__send_message
func _core_game_object__send_message(handle GameObject, method_name uint32, options int32) void
//go:wasmimport env _core_game_object__send_message_upwards
func _core_game_object__send_message_upwards(handle GameObject, method_name uint32, options int32) void
//go:wasmimport env _core_game_object__set_active
func _core_game_object__set_active(handle GameObject, value bool) void
//go:wasmimport env _core_game_object__set_active_prop
func _core_game_object__set_active_prop(handle GameObject, value bool) void
//go:wasmimport env _core_game_object__set_active_recursively
func _core_game_object__set_active_recursively(handle GameObject, state bool) void
//go:wasmimport env _core_game_object__set_hide_flags
func _core_game_object__set_hide_flags(handle GameObject, value int32) void
//go:wasmimport env _core_game_object__set_is_static
func _core_game_object__set_is_static(handle GameObject, value bool) void
//go:wasmimport env _core_game_object__set_layer
func _core_game_object__set_layer(handle GameObject, value int32) void
//go:wasmimport env _core_game_object__set_name
func _core_game_object__set_name(handle GameObject, value uint32) void
//go:wasmimport env _core_game_object__set_tag
func _core_game_object__set_tag(handle GameObject, value uint32) void
//go:wasmimport env _core_gc_helper__create
func _core_gc_helper__create() GCHelper
//go:wasmimport env _core_gc_helper__dispose
func _core_gc_helper__dispose(handle GcHelper) void
//go:wasmimport env _core_gc_helper__invalidate_all_handles
func _core_gc_helper__invalidate_all_handles(handle GcHelper) void
//go:wasmimport env _core_gc_helper__wasm_garbage_collect
func _core_gc_helper__wasm_garbage_collect(handle GcHelper) void
//go:wasmimport env _core_log__critical
func _core_log__critical(msg uint32) void
//go:wasmimport env _core_log__debug
func _core_log__debug(msg uint32) void
//go:wasmimport env _core_log__info
func _core_log__info(msg uint32) void
//go:wasmimport env _core_log__warn
func _core_log__warn(msg uint32) void
//go:wasmimport env _core_note_controller__get_note_floor_movement
func _core_note_controller__get_note_floor_movement(handle NoteController) NoteFloorMovement
//go:wasmimport env _core_note_controller__get_note_jump
func _core_note_controller__get_note_jump(handle NoteController) NoteJump
//go:wasmimport env _core_note_floor_movement___audio_time_sync_controller_get
func _core_note_floor_movement___audio_time_sync_controller_get(handle NoteFloorMovement) IAudioTimeSource
//go:wasmimport env _core_note_floor_movement___beat_time_get
func _core_note_floor_movement___beat_time_get(handle NoteFloorMovement) float32
//go:wasmimport env _core_note_floor_movement___beat_time_set
func _core_note_floor_movement___beat_time_set(handle NoteFloorMovement, value float32) void
//go:wasmimport env _core_note_floor_movement___inverse_world_rotation_get
func _core_note_floor_movement___inverse_world_rotation_get(handle NoteFloorMovement) uint32
//go:wasmimport env _core_note_floor_movement___inverse_world_rotation_set
func _core_note_floor_movement___inverse_world_rotation_set(handle NoteFloorMovement, value uint32) void
//go:wasmimport env _core_note_floor_movement___local_position_get
func _core_note_floor_movement___local_position_get(handle NoteFloorMovement) uint32
//go:wasmimport env _core_note_floor_movement___local_position_set
func _core_note_floor_movement___local_position_set(handle NoteFloorMovement, value uint32) void
//go:wasmimport env _core_note_floor_movement___move_end_offset_get
func _core_note_floor_movement___move_end_offset_get(handle NoteFloorMovement) uint32
//go:wasmimport env _core_note_floor_movement___move_end_offset_set
func _core_note_floor_movement___move_end_offset_set(handle NoteFloorMovement, value uint32) void
//go:wasmimport env _core_note_floor_movement___move_start_offset_get
func _core_note_floor_movement___move_start_offset_get(handle NoteFloorMovement) uint32
//go:wasmimport env _core_note_floor_movement___move_start_offset_set
func _core_note_floor_movement___move_start_offset_set(handle NoteFloorMovement, value uint32) void
//go:wasmimport env _core_note_floor_movement___player_transforms_get
func _core_note_floor_movement___player_transforms_get(handle NoteFloorMovement) PlayerTransforms
//go:wasmimport env _core_note_floor_movement___rotated_object_get
func _core_note_floor_movement___rotated_object_get(handle NoteFloorMovement) Transform
//go:wasmimport env _core_note_floor_movement___rotated_object_set
func _core_note_floor_movement___rotated_object_set(handle NoteFloorMovement, value Transform) void
//go:wasmimport env _core_note_floor_movement___variable_movement_data_provider_get
func _core_note_floor_movement___variable_movement_data_provider_get(handle NoteFloorMovement) IVariableMovementDataProvider
//go:wasmimport env _core_note_floor_movement___world_rotation_get
func _core_note_floor_movement___world_rotation_get(handle NoteFloorMovement) uint32
//go:wasmimport env _core_note_floor_movement___world_rotation_set
func _core_note_floor_movement___world_rotation_set(handle NoteFloorMovement, value uint32) void
//go:wasmimport env _core_note_floor_movement__distance_to_player_get
func _core_note_floor_movement__distance_to_player_get(handle NoteFloorMovement) float32
//go:wasmimport env _core_note_floor_movement__end_pos_get
func _core_note_floor_movement__end_pos_get(handle NoteFloorMovement) uint32
//go:wasmimport env _core_note_floor_movement__init
func _core_note_floor_movement__init(handle NoteFloorMovement, world_rotation float32, beat_time float32, move_start_offset uint32, move_end_offset uint32) void
//go:wasmimport env _core_note_floor_movement__inverse_world_rotation_get
func _core_note_floor_movement__inverse_world_rotation_get(handle NoteFloorMovement) uint32
//go:wasmimport env _core_note_floor_movement__local_position_get
func _core_note_floor_movement__local_position_get(handle NoteFloorMovement) uint32
//go:wasmimport env _core_note_floor_movement__manual_update
func _core_note_floor_movement__manual_update(handle NoteFloorMovement) uint32
//go:wasmimport env _core_note_floor_movement__note_time_get
func _core_note_floor_movement__note_time_get(handle NoteFloorMovement) float32
//go:wasmimport env _core_note_floor_movement__set_to_start
func _core_note_floor_movement__set_to_start(handle NoteFloorMovement) uint32
//go:wasmimport env _core_note_floor_movement__should_move
func _core_note_floor_movement__should_move(handle NoteFloorMovement) bool
//go:wasmimport env _core_note_floor_movement__world_rotation_get
func _core_note_floor_movement__world_rotation_get(handle NoteFloorMovement) uint32
//go:wasmimport env _core_note_jump__k_missed_time_offset_get
func _core_note_jump__k_missed_time_offset_get() float32
//go:wasmimport env _core_note_jump___audio_time_sync_controller_get
func _core_note_jump___audio_time_sync_controller_get(handle NoteJump) IAudioTimeSource
//go:wasmimport env _core_note_jump___end_distance_offset_get
func _core_note_jump___end_distance_offset_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump___end_distance_offset_set
func _core_note_jump___end_distance_offset_set(handle NoteJump, value float32) void
//go:wasmimport env _core_note_jump___end_offset_get
func _core_note_jump___end_offset_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump___end_offset_set
func _core_note_jump___end_offset_set(handle NoteJump, value uint32) void
//go:wasmimport env _core_note_jump___end_pos_get
func _core_note_jump___end_pos_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump___end_pos_set
func _core_note_jump___end_pos_set(handle NoteJump, value uint32) void
//go:wasmimport env _core_note_jump___end_rotation_get
func _core_note_jump___end_rotation_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump___end_rotation_set
func _core_note_jump___end_rotation_set(handle NoteJump, value uint32) void
//go:wasmimport env _core_note_jump___gravity_base_get
func _core_note_jump___gravity_base_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump___gravity_base_set
func _core_note_jump___gravity_base_set(handle NoteJump, value float32) void
//go:wasmimport env _core_note_jump___gravity_get
func _core_note_jump___gravity_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump___gravity_set
func _core_note_jump___gravity_set(handle NoteJump, value float32) void
//go:wasmimport env _core_note_jump___half_jump_duration_get
func _core_note_jump___half_jump_duration_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump___half_jump_duration_set
func _core_note_jump___half_jump_duration_set(handle NoteJump, value float32) void
//go:wasmimport env _core_note_jump___half_jump_mark_reported_get
func _core_note_jump___half_jump_mark_reported_get(handle NoteJump) bool
//go:wasmimport env _core_note_jump___half_jump_mark_reported_set
func _core_note_jump___half_jump_mark_reported_set(handle NoteJump, value bool) void
//go:wasmimport env _core_note_jump___inverse_world_rotation_get
func _core_note_jump___inverse_world_rotation_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump___inverse_world_rotation_set
func _core_note_jump___inverse_world_rotation_set(handle NoteJump, value uint32) void
//go:wasmimport env _core_note_jump___jump_duration_get
func _core_note_jump___jump_duration_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump___jump_duration_set
func _core_note_jump___jump_duration_set(handle NoteJump, value float32) void
//go:wasmimport env _core_note_jump___jump_started_reported_get
func _core_note_jump___jump_started_reported_get(handle NoteJump) bool
//go:wasmimport env _core_note_jump___jump_started_reported_set
func _core_note_jump___jump_started_reported_set(handle NoteJump, value bool) void
//go:wasmimport env _core_note_jump___local_position_get
func _core_note_jump___local_position_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump___local_position_set
func _core_note_jump___local_position_set(handle NoteJump, value uint32) void
//go:wasmimport env _core_note_jump___middle_rotation_get
func _core_note_jump___middle_rotation_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump___middle_rotation_set
func _core_note_jump___middle_rotation_set(handle NoteJump, value uint32) void
//go:wasmimport env _core_note_jump___missed_mark_reported_get
func _core_note_jump___missed_mark_reported_get(handle NoteJump) bool
//go:wasmimport env _core_note_jump___missed_mark_reported_set
func _core_note_jump___missed_mark_reported_set(handle NoteJump, value bool) void
//go:wasmimport env _core_note_jump___missed_time_get
func _core_note_jump___missed_time_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump___missed_time_set
func _core_note_jump___missed_time_set(handle NoteJump, value float32) void
//go:wasmimport env _core_note_jump___note_time_get
func _core_note_jump___note_time_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump___note_time_set
func _core_note_jump___note_time_set(handle NoteJump, value float32) void
//go:wasmimport env _core_note_jump___player_space_convertor_get
func _core_note_jump___player_space_convertor_get(handle NoteJump) PlayerSpaceConvertor
//go:wasmimport env _core_note_jump___player_transforms_get
func _core_note_jump___player_transforms_get(handle NoteJump) PlayerTransforms
//go:wasmimport env _core_note_jump___rotate_towards_player_get
func _core_note_jump___rotate_towards_player_get(handle NoteJump) bool
//go:wasmimport env _core_note_jump___rotate_towards_player_set
func _core_note_jump___rotate_towards_player_set(handle NoteJump, value bool) void
//go:wasmimport env _core_note_jump___rotated_object_get
func _core_note_jump___rotated_object_get(handle NoteJump) Transform
//go:wasmimport env _core_note_jump___rotated_object_set
func _core_note_jump___rotated_object_set(handle NoteJump, value Transform) void
//go:wasmimport env _core_note_jump___start_offset_get
func _core_note_jump___start_offset_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump___start_offset_set
func _core_note_jump___start_offset_set(handle NoteJump, value uint32) void
//go:wasmimport env _core_note_jump___start_pos_get
func _core_note_jump___start_pos_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump___start_pos_set
func _core_note_jump___start_pos_set(handle NoteJump, value uint32) void
//go:wasmimport env _core_note_jump___start_rotation_get
func _core_note_jump___start_rotation_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump___start_rotation_set
func _core_note_jump___start_rotation_set(handle NoteJump, value uint32) void
//go:wasmimport env _core_note_jump___three_quarters_mark_reported_get
func _core_note_jump___three_quarters_mark_reported_get(handle NoteJump) bool
//go:wasmimport env _core_note_jump___three_quarters_mark_reported_set
func _core_note_jump___three_quarters_mark_reported_set(handle NoteJump, value bool) void
//go:wasmimport env _core_note_jump___variable_movement_data_provider_get
func _core_note_jump___variable_movement_data_provider_get(handle NoteJump) IVariableMovementDataProvider
//go:wasmimport env _core_note_jump___world_rotation_get
func _core_note_jump___world_rotation_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump___world_rotation_set
func _core_note_jump___world_rotation_set(handle NoteJump, value uint32) void
//go:wasmimport env _core_note_jump___y_avoidance_down_get
func _core_note_jump___y_avoidance_down_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump___y_avoidance_down_set
func _core_note_jump___y_avoidance_down_set(handle NoteJump, value float32) void
//go:wasmimport env _core_note_jump___y_avoidance_get
func _core_note_jump___y_avoidance_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump___y_avoidance_set
func _core_note_jump___y_avoidance_set(handle NoteJump, value float32) void
//go:wasmimport env _core_note_jump___y_avoidance_up_get
func _core_note_jump___y_avoidance_up_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump___y_avoidance_up_set
func _core_note_jump___y_avoidance_up_set(handle NoteJump, value float32) void
//go:wasmimport env _core_note_jump__add_note_jump_did_finish_event
func _core_note_jump__add_note_jump_did_finish_event(handle NoteJump, value Action) void
//go:wasmimport env _core_note_jump__add_note_jump_did_pass_half_event
func _core_note_jump__add_note_jump_did_pass_half_event(handle NoteJump, value Action) void
//go:wasmimport env _core_note_jump__add_note_jump_did_pass_missed_marker_event
func _core_note_jump__add_note_jump_did_pass_missed_marker_event(handle NoteJump, value Action) void
//go:wasmimport env _core_note_jump__add_note_jump_did_pass_three_quarters_event
func _core_note_jump__add_note_jump_did_pass_three_quarters_event(handle NoteJump, value Action1) void
//go:wasmimport env _core_note_jump__add_note_jump_did_start_event
func _core_note_jump__add_note_jump_did_start_event(handle NoteJump, value Action) void
//go:wasmimport env _core_note_jump__add_note_jump_did_update_progress_event
func _core_note_jump__add_note_jump_did_update_progress_event(handle NoteJump, value Action1) void
//go:wasmimport env _core_note_jump__beat_pos_get
func _core_note_jump__beat_pos_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump__distance_to_player_get
func _core_note_jump__distance_to_player_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump__init
func _core_note_jump__init(handle NoteJump, note_time float32, world_rotation float32, move_end_offset uint32, jump_end_offset uint32, gravity_base float32, flip_y_side float32, end_rotation float32, rotate_towards_player bool, use_random_rotation bool) void
//go:wasmimport env _core_note_jump__local_position_get
func _core_note_jump__local_position_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump__manual_update
func _core_note_jump__manual_update(handle NoteJump) uint32
//go:wasmimport env _core_note_jump__move_vec_get
func _core_note_jump__move_vec_get(handle NoteJump) uint32
//go:wasmimport env _core_note_jump__note_time_get
func _core_note_jump__note_time_get(handle NoteJump) float32
//go:wasmimport env _core_note_jump__remove_note_jump_did_finish_event
func _core_note_jump__remove_note_jump_did_finish_event(handle NoteJump, value Action) void
//go:wasmimport env _core_note_jump__remove_note_jump_did_pass_half_event
func _core_note_jump__remove_note_jump_did_pass_half_event(handle NoteJump, value Action) void
//go:wasmimport env _core_note_jump__remove_note_jump_did_pass_missed_marker_event
func _core_note_jump__remove_note_jump_did_pass_missed_marker_event(handle NoteJump, value Action) void
//go:wasmimport env _core_note_jump__remove_note_jump_did_pass_three_quarters_event
func _core_note_jump__remove_note_jump_did_pass_three_quarters_event(handle NoteJump, value Action1) void
//go:wasmimport env _core_note_jump__remove_note_jump_did_start_event
func _core_note_jump__remove_note_jump_did_start_event(handle NoteJump, value Action) void
//go:wasmimport env _core_note_jump__remove_note_jump_did_update_progress_event
func _core_note_jump__remove_note_jump_did_update_progress_event(handle NoteJump, value Action1) void
//go:wasmimport env _core_note_manager__add_bomb_note
func _core_note_manager__add_bomb_note(beat float32, line int32, layer int32, custom_data CustomData) CustomNoteData
//go:wasmimport env _core_note_manager__add_color_note
func _core_note_manager__add_color_note(beat float32, line int32, layer int32, color int32, cut_direction int32, custom_data CustomData) CustomNoteData
//go:wasmimport env _core_note_manager__add_obstacle
func _core_note_manager__add_obstacle(beat float32, duration float32, line int32, layer int32, width int32, height int32, custom_data CustomData) CustomObstacleData
//go:wasmimport env _core_note_manager__get_note_controller
func _core_note_manager__get_note_controller(n int32) NoteControllerBase
//go:wasmimport env _core_note_manager__get_note_controller_from_custom
func _core_note_manager__get_note_controller_from_custom(n CustomNoteData) NoteControllerBase
//go:wasmimport env _core_note_manager__get_nth_event
func _core_note_manager__get_nth_event(id int32) CustomEventData
//go:wasmimport env _core_note_manager__get_nth_note
func _core_note_manager__get_nth_note(id int32) CustomNoteData
//go:wasmimport env _core_note_manager__get_nth_object
func _core_note_manager__get_nth_object(id int32) BeatmapDataItem
//go:wasmimport env _core_note_manager__get_nth_obstacle
func _core_note_manager__get_nth_obstacle(id int32) CustomObstacleData
//go:wasmimport env _core_note_manager__get_obstacle_controller
func _core_note_manager__get_obstacle_controller(n int32) ObstacleControllerBase
//go:wasmimport env _core_note_manager__get_obstacle_controller_from_custom
func _core_note_manager__get_obstacle_controller_from_custom(n CustomObstacleData) ObstacleController
//go:wasmimport env _core_note_manager__time_to_beat
func _core_note_manager__time_to_beat(time float32) float32
//go:wasmimport env _core_task_scheduler__schedule
func _core_task_scheduler__schedule(task Action) void
//go:wasmimport env _core_task_scheduler__dispose
func _core_task_scheduler__dispose(handle TaskScheduler) void
//go:wasmimport env _core_texture_2_d__apply
func _core_texture_2_d__apply(handle Texture2D, update_mipmaps bool, make_no_longer_readable bool) void
//go:wasmimport env _core_texture_2_d__get_format
func _core_texture_2_d__get_format(handle Texture2D) int32
//go:wasmimport env _core_texture_2_d__get_graphics_format
func _core_texture_2_d__get_graphics_format(handle Texture2D) int32
//go:wasmimport env _core_texture_2_d__get_height
func _core_texture_2_d__get_height(handle Texture2D) int32
//go:wasmimport env _core_texture_2_d__get_hide_flags
func _core_texture_2_d__get_hide_flags(handle Texture2D) int32
//go:wasmimport env _core_texture_2_d__get_instance_id
func _core_texture_2_d__get_instance_id(handle Texture2D) int32
//go:wasmimport env _core_texture_2_d__get_is_readable
func _core_texture_2_d__get_is_readable(handle Texture2D) bool
//go:wasmimport env _core_texture_2_d__get_mipmap_count
func _core_texture_2_d__get_mipmap_count(handle Texture2D) int32
//go:wasmimport env _core_texture_2_d__get_name
func _core_texture_2_d__get_name(handle Texture2D) uint32
//go:wasmimport env _core_texture_2_d__get_raw_texture_data
func _core_texture_2_d__get_raw_texture_data(handle Texture2D) uint32
//go:wasmimport env _core_texture_2_d__get_width
func _core_texture_2_d__get_width(handle Texture2D) int32
//go:wasmimport env _core_texture_2_d__load_raw_texture_data
func _core_texture_2_d__load_raw_texture_data(handle Texture2D, data_ *void) void
//go:wasmimport env _core_texture_2_d__reinitialize
func _core_texture_2_d__reinitialize(handle Texture2D, width int32, height int32, format int32, has_mip_map bool) bool
//go:wasmimport env _core_texture_2_d__set_height
func _core_texture_2_d__set_height(handle Texture2D, value int32) void
//go:wasmimport env _core_texture_2_d__set_hide_flags
func _core_texture_2_d__set_hide_flags(handle Texture2D, value int32) void
//go:wasmimport env _core_texture_2_d__set_name
func _core_texture_2_d__set_name(handle Texture2D, value uint32) void
//go:wasmimport env _core_texture_2_d__set_width
func _core_texture_2_d__set_width(handle Texture2D, value int32) void
//go:wasmimport env _core_transform__broadcast_message
func _core_transform__broadcast_message(handle Transform, method_name uint32, parameter Object, options int32) void
//go:wasmimport env _core_transform__compare_tag
func _core_transform__compare_tag(handle Transform, tag uint32) bool
//go:wasmimport env _core_transform__detach_children
func _core_transform__detach_children(handle Transform) void
//go:wasmimport env _core_transform__find
func _core_transform__find(handle Transform, n uint32) Transform
//go:wasmimport env _core_transform__find_child
func _core_transform__find_child(handle Transform, n uint32) Transform
//go:wasmimport env _core_transform__get_child
func _core_transform__get_child(handle Transform, index int32) Transform
//go:wasmimport env _core_transform__get_child_count
func _core_transform__get_child_count(handle Transform) int32
//go:wasmimport env _core_transform__get_child_count_prop
func _core_transform__get_child_count_prop(handle Transform) int32
//go:wasmimport env _core_transform__get_component_by_name
func _core_transform__get_component_by_name(handle Transform, cs_type uint32) Component
//go:wasmimport env _core_transform__get_component_by_type
func _core_transform__get_component_by_type(handle Transform, cs_type Type) Component
//go:wasmimport env _core_transform__get_component_in_children_by_type
func _core_transform__get_component_in_children_by_type(handle Transform, t Type, include_inactive bool) Component
//go:wasmimport env _core_transform__get_component_in_parent_by_type
func _core_transform__get_component_in_parent_by_type(handle Transform, t Type, include_inactive bool) Component
//go:wasmimport env _core_transform__get_component_index
func _core_transform__get_component_index(handle Transform) int32
//go:wasmimport env _core_transform__get_enumerator
func _core_transform__get_enumerator(handle Transform) IEnumerator
//go:wasmimport env _core_transform__get_euler_angles
func _core_transform__get_euler_angles(handle Transform) uint32
//go:wasmimport env _core_transform__get_forward
func _core_transform__get_forward(handle Transform) uint32
//go:wasmimport env _core_transform__get_game_object
func _core_transform__get_game_object(handle Transform) GameObject
//go:wasmimport env _core_transform__get_has_changed
func _core_transform__get_has_changed(handle Transform) bool
//go:wasmimport env _core_transform__get_hide_flags
func _core_transform__get_hide_flags(handle Transform) int32
//go:wasmimport env _core_transform__get_hierarchy_capacity
func _core_transform__get_hierarchy_capacity(handle Transform) int32
//go:wasmimport env _core_transform__get_hierarchy_count
func _core_transform__get_hierarchy_count(handle Transform) int32
//go:wasmimport env _core_transform__get_instance_id
func _core_transform__get_instance_id(handle Transform) int32
//go:wasmimport env _core_transform__get_local_euler_angles
func _core_transform__get_local_euler_angles(handle Transform) uint32
//go:wasmimport env _core_transform__get_local_position
func _core_transform__get_local_position(handle Transform) uint32
//go:wasmimport env _core_transform__get_local_rotation
func _core_transform__get_local_rotation(handle Transform) uint32
//go:wasmimport env _core_transform__get_local_scale
func _core_transform__get_local_scale(handle Transform) uint32
//go:wasmimport env _core_transform__get_local_to_world_matrix
func _core_transform__get_local_to_world_matrix(handle Transform) uint32
//go:wasmimport env _core_transform__get_lossy_scale
func _core_transform__get_lossy_scale(handle Transform) uint32
//go:wasmimport env _core_transform__get_name
func _core_transform__get_name(handle Transform) uint32
//go:wasmimport env _core_transform__get_parent
func _core_transform__get_parent(handle Transform) Transform
//go:wasmimport env _core_transform__get_position
func _core_transform__get_position(handle Transform) uint32
//go:wasmimport env _core_transform__get_right
func _core_transform__get_right(handle Transform) uint32
//go:wasmimport env _core_transform__get_root
func _core_transform__get_root(handle Transform) Transform
//go:wasmimport env _core_transform__get_rotation
func _core_transform__get_rotation(handle Transform) uint32
//go:wasmimport env _core_transform__get_sibling_index
func _core_transform__get_sibling_index(handle Transform) int32
//go:wasmimport env _core_transform__get_tag
func _core_transform__get_tag(handle Transform) uint32
//go:wasmimport env _core_transform__get_up
func _core_transform__get_up(handle Transform) uint32
//go:wasmimport env _core_transform__get_world_to_local_matrix
func _core_transform__get_world_to_local_matrix(handle Transform) uint32
//go:wasmimport env _core_transform__inverse_transform_direction
func _core_transform__inverse_transform_direction(handle Transform, direction uint32) uint32
//go:wasmimport env _core_transform__inverse_transform_point
func _core_transform__inverse_transform_point(handle Transform, position uint32) uint32
//go:wasmimport env _core_transform__inverse_transform_vector
func _core_transform__inverse_transform_vector(handle Transform, vector uint32) uint32
//go:wasmimport env _core_transform__is_child_of
func _core_transform__is_child_of(handle Transform, parent Transform) bool
//go:wasmimport env _core_transform__look_at
func _core_transform__look_at(handle Transform, target Transform, world_up uint32) void
//go:wasmimport env _core_transform__rotate
func _core_transform__rotate(handle Transform, eulers uint32) void
//go:wasmimport env _core_transform__rotate_around
func _core_transform__rotate_around(handle Transform, point uint32, axis uint32, angle float32) void
//go:wasmimport env _core_transform__rotate_around_local
func _core_transform__rotate_around_local(handle Transform, axis uint32, angle float32) void
//go:wasmimport env _core_transform__rotate_relative
func _core_transform__rotate_relative(handle Transform, eulers uint32, relative_to int32) void
//go:wasmimport env _core_transform__send_message
func _core_transform__send_message(handle Transform, method_name uint32, value Object, options int32) void
//go:wasmimport env _core_transform__send_message_upwards
func _core_transform__send_message_upwards(handle Transform, method_name uint32, value Object, options int32) void
//go:wasmimport env _core_transform__set_as_first_sibling
func _core_transform__set_as_first_sibling(handle Transform) void
//go:wasmimport env _core_transform__set_as_last_sibling
func _core_transform__set_as_last_sibling(handle Transform) void
//go:wasmimport env _core_transform__set_euler_angles
func _core_transform__set_euler_angles(handle Transform, value uint32) void
//go:wasmimport env _core_transform__set_forward
func _core_transform__set_forward(handle Transform, value uint32) void
//go:wasmimport env _core_transform__set_has_changed
func _core_transform__set_has_changed(handle Transform, value bool) void
//go:wasmimport env _core_transform__set_hide_flags
func _core_transform__set_hide_flags(handle Transform, value int32) void
//go:wasmimport env _core_transform__set_hierarchy_capacity
func _core_transform__set_hierarchy_capacity(handle Transform, value int32) void
//go:wasmimport env _core_transform__set_local_euler_angles
func _core_transform__set_local_euler_angles(handle Transform, value uint32) void
//go:wasmimport env _core_transform__set_local_position
func _core_transform__set_local_position(handle Transform, value uint32) void
//go:wasmimport env _core_transform__set_local_position_and_rotation
func _core_transform__set_local_position_and_rotation(handle Transform, local_position uint32, local_rotation uint32) void
//go:wasmimport env _core_transform__set_local_rotation
func _core_transform__set_local_rotation(handle Transform, value uint32) void
//go:wasmimport env _core_transform__set_local_scale
func _core_transform__set_local_scale(handle Transform, value uint32) void
//go:wasmimport env _core_transform__set_name
func _core_transform__set_name(handle Transform, value uint32) void
//go:wasmimport env _core_transform__set_parent
func _core_transform__set_parent(handle Transform, parent Transform, world_position_stays bool) void
//go:wasmimport env _core_transform__set_position
func _core_transform__set_position(handle Transform, value uint32) void
//go:wasmimport env _core_transform__set_position_and_rotation
func _core_transform__set_position_and_rotation(handle Transform, position uint32, rotation uint32) void
//go:wasmimport env _core_transform__set_right
func _core_transform__set_right(handle Transform, value uint32) void
//go:wasmimport env _core_transform__set_rotation
func _core_transform__set_rotation(handle Transform, value uint32) void
//go:wasmimport env _core_transform__set_sibling_index
func _core_transform__set_sibling_index(handle Transform, index int32) void
//go:wasmimport env _core_transform__set_tag
func _core_transform__set_tag(handle Transform, value uint32) void
//go:wasmimport env _core_transform__set_up
func _core_transform__set_up(handle Transform, value uint32) void
//go:wasmimport env _core_transform__transform_direction
func _core_transform__transform_direction(handle Transform, direction uint32) uint32
//go:wasmimport env _core_transform__transform_point
func _core_transform__transform_point(handle Transform, position uint32) uint32
//go:wasmimport env _core_transform__transform_vector
func _core_transform__transform_vector(handle Transform, vector uint32) uint32
//go:wasmimport env _core_transform__translate
func _core_transform__translate(handle Transform, translation uint32, relative_to int32) void
//go:wasmimport env _core_transform__translate_relative
func _core_transform__translate_relative(handle Transform, translation uint32, relative_to Transform) void
//go:wasmimport env _core_turing_mesh___mesh_get
func _core_turing_mesh___mesh_get(handle TuringMesh) Mesh
//go:wasmimport env _core_turing_mesh___mesh_set
func _core_turing_mesh___mesh_set(handle TuringMesh, value Mesh) void
//go:wasmimport env _core_turing_mesh__clear
func _core_turing_mesh__clear(handle TuringMesh) void
//go:wasmimport env _core_turing_mesh__get_bounds_max_x
func _core_turing_mesh__get_bounds_max_x(handle TuringMesh) float32
//go:wasmimport env _core_turing_mesh__get_bounds_max_y
func _core_turing_mesh__get_bounds_max_y(handle TuringMesh) float32
//go:wasmimport env _core_turing_mesh__get_bounds_max_z
func _core_turing_mesh__get_bounds_max_z(handle TuringMesh) float32
//go:wasmimport env _core_turing_mesh__get_bounds_min_x
func _core_turing_mesh__get_bounds_min_x(handle TuringMesh) float32
//go:wasmimport env _core_turing_mesh__get_bounds_min_y
func _core_turing_mesh__get_bounds_min_y(handle TuringMesh) float32
//go:wasmimport env _core_turing_mesh__get_bounds_min_z
func _core_turing_mesh__get_bounds_min_z(handle TuringMesh) float32
//go:wasmimport env _core_turing_mesh__get_instance_id
func _core_turing_mesh__get_instance_id(handle TuringMesh) int32
//go:wasmimport env _core_turing_mesh__get_u_vs
func _core_turing_mesh__get_u_vs(handle TuringMesh, channel int32) uint32
//go:wasmimport env _core_turing_mesh__get_vertices
func _core_turing_mesh__get_vertices(handle TuringMesh) uint32
//go:wasmimport env _core_turing_mesh__hide_flags_get
func _core_turing_mesh__hide_flags_get(handle TuringMesh) int32
//go:wasmimport env _core_turing_mesh__hide_flags_set
func _core_turing_mesh__hide_flags_set(handle TuringMesh, value int32) void
//go:wasmimport env _core_turing_mesh__mark_modified
func _core_turing_mesh__mark_modified(handle TuringMesh) void
//go:wasmimport env _core_turing_mesh__name_get
func _core_turing_mesh__name_get(handle TuringMesh) uint32
//go:wasmimport env _core_turing_mesh__name_set
func _core_turing_mesh__name_set(handle TuringMesh, value uint32) void
//go:wasmimport env _core_turing_mesh__optimize
func _core_turing_mesh__optimize(handle TuringMesh) void
//go:wasmimport env _core_turing_mesh__optimize_index_buffers
func _core_turing_mesh__optimize_index_buffers(handle TuringMesh) void
//go:wasmimport env _core_turing_mesh__recalculate_bounds
func _core_turing_mesh__recalculate_bounds(handle TuringMesh) void
//go:wasmimport env _core_turing_mesh__recalculate_normals
func _core_turing_mesh__recalculate_normals(handle TuringMesh) void
//go:wasmimport env _core_turing_mesh__recalculate_tangents
func _core_turing_mesh__recalculate_tangents(handle TuringMesh) void
//go:wasmimport env _core_turing_mesh__set_bounds
func _core_turing_mesh__set_bounds(handle TuringMesh, min_x float32, min_y float32, min_z float32, max_x float32, max_y float32, max_z float32) void
//go:wasmimport env _core_turing_mesh__set_triangles
func _core_turing_mesh__set_triangles(handle TuringMesh, triangles Int32, submesh int32, calculate_bounds bool, base_vertex int32) void
//go:wasmimport env _core_turing_mesh__set_u_vs
func _core_turing_mesh__set_u_vs(handle TuringMesh, channel int32, uvs *void) void
//go:wasmimport env _core_turing_mesh__set_vertices
func _core_turing_mesh__set_vertices(handle TuringMesh, in_vertices *void) void
//go:wasmimport env _core_turing_mesh__upload_mesh_data
func _core_turing_mesh__upload_mesh_data(handle TuringMesh, mark_no_longer_readable bool) void
//go:wasmimport env _core_turing_texture_2_d__create
func _core_turing_texture_2_d__create(width int32, height int32, format int32, mipmap bool) Texture2D
//go:wasmimport env _core_turing_texture_2_d__destroy
func _core_turing_texture_2_d__destroy(texture_2_d Texture2D) void
//go:wasmimport env _core_turing_texture_2_d__find
func _core_turing_texture_2_d__find(name uint32) Texture2D
//go:wasmimport env _core_turinger_game_object_manager__create_object
func _core_turinger_game_object_manager__create_object(name uint32) GameObject
//go:wasmimport env _core_turinger_game_object_manager__destroy_object
func _core_turinger_game_object_manager__destroy_object(game_object GameObject) void
//go:wasmimport env _core_turinger_game_object_manager__find
func _core_turinger_game_object_manager__find(name uint32) GameObject
//go:wasmimport env _core_turinger_game_object_manager__instance_get
func _core_turinger_game_object_manager__instance_get(handle TuringerGameObjectManager) TuringerGameObjectManager
//go:wasmimport env _core_xr__get_device_battery_level
func _core_xr__get_device_battery_level(node_int int32) float32
//go:wasmimport env _core_xr__get_device_grip_value
func _core_xr__get_device_grip_value(node_int int32) float32
//go:wasmimport env _core_xr__get_device_name
func _core_xr__get_device_name(node_int int32) uint32
//go:wasmimport env _core_xr__get_device_primary_button_state
func _core_xr__get_device_primary_button_state(node_int int32) bool
//go:wasmimport env _core_xr__get_device_secondary_button_state
func _core_xr__get_device_secondary_button_state(node_int int32) bool
//go:wasmimport env _core_xr__get_device_thumbstick
func _core_xr__get_device_thumbstick(node_int int32) uint32
//go:wasmimport env _core_xr__get_device_touchpad
func _core_xr__get_device_touchpad(node_int int32) uint32
//go:wasmimport env _core_xr__get_device_tracking_state
func _core_xr__get_device_tracking_state(node_int int32) int32
//go:wasmimport env _core_xr__get_device_trigger_value
func _core_xr__get_device_trigger_value(node_int int32) float32
//go:wasmimport env _core_xr__is_device_valid
func _core_xr__is_device_valid(node_int int32) bool
//go:wasmimport env _core_xr__send_haptic_impulse
func _core_xr__send_haptic_impulse(node_int int32, amplitude float32, duration float32) void
//go:wasmimport env _core_xr__stop_haptics
func _core_xr__stop_haptics(node_int int32) void
//go:wasmimport env _core_xr___manager_get
func _core_xr___manager_get(handle Xr) TuringScriptManager

//export _core_semver
func _core_semver() uint64 {
    return (uint64(0) << 32) | (uint64(1) << 16) | uint64(0)
}

const CORE_VERSION = "0.1.0"

//// Functions ////


//// Classes ////

type Action struct {
    opaqu uint32
}



type Action1 struct {
    opaqu uint32
}



type BeatmapDataItem struct {
    opaqu uint32
}



type Component struct {
    opaqu uint32
}



type CustomData struct {
    opaqu uint32
}


func CustomData_create() CustomData {
    
    return _core_custom_data__create()
}

func CustomData_fromJson(json string) CustomData {
    
    turingHJson := []byte(json)
    turingHJson = append(turingHJson, 0)
    turingHandleJson := &turingHJson[0]
    return _core_custom_data__from_json(turingHandleJson)
}

func CustomData_listAddBool(list List1, value bool) void {
    
    _core_custom_data__list_add_bool(list, value)
}

func CustomData_listAddCustomData(list List1, value CustomData) void {
    
    _core_custom_data__list_add_custom_data(list, value)
}

func CustomData_listAddCustomDataList(list List1, value List1) void {
    
    _core_custom_data__list_add_custom_data_list(list, value)
}

func CustomData_listAddFloat(list List1, value float32) void {
    
    _core_custom_data__list_add_float(list, value)
}

func CustomData_listAddInt(list List1, value int32) void {
    
    _core_custom_data__list_add_int(list, value)
}

func CustomData_listAddString(list List1, value string) void {
    
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_custom_data__list_add_string(list, turingHandleValue)
}

func CustomData_setBool(customData CustomData, key string, value bool) void {
    
    turingHKey := []byte(key)
    turingHKey = append(turingHKey, 0)
    turingHandleKey := &turingHKey[0]
    _core_custom_data__set_bool(customData, turingHandleKey, value)
}

func CustomData_setCustomData(customData CustomData, key string, value CustomData) void {
    
    turingHKey := []byte(key)
    turingHKey = append(turingHKey, 0)
    turingHandleKey := &turingHKey[0]
    _core_custom_data__set_custom_data(customData, turingHandleKey, value)
}

func CustomData_setCustomDataList(customData CustomData, key string, value List1) void {
    
    turingHKey := []byte(key)
    turingHKey = append(turingHKey, 0)
    turingHandleKey := &turingHKey[0]
    _core_custom_data__set_custom_data_list(customData, turingHandleKey, value)
}

func CustomData_setFloat(customData CustomData, key string, value float32) void {
    
    turingHKey := []byte(key)
    turingHKey = append(turingHKey, 0)
    turingHandleKey := &turingHKey[0]
    _core_custom_data__set_float(customData, turingHandleKey, value)
}

func CustomData_setInt(customData CustomData, key string, value int32) void {
    
    turingHKey := []byte(key)
    turingHKey = append(turingHKey, 0)
    turingHandleKey := &turingHKey[0]
    _core_custom_data__set_int(customData, turingHandleKey, value)
}

func CustomData_setString(customData CustomData, key string, value string) void {
    
    turingHKey := []byte(key)
    turingHKey = append(turingHKey, 0)
    turingHandleKey := &turingHKey[0]
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_custom_data__set_string(customData, turingHandleKey, turingHandleValue)
}

func CustomData_toJson(customData CustomData, pretty bool) string {
    
    turingResult := _core_custom_data__to_json(customData, pretty)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}


type CustomEventData struct {
    opaqu uint32
}



func (self *CustomEventData)customDataGet() CustomData {
    
    return _core_custom_event_data__custom_data_get(self)
}

func (self *CustomEventData)eventTypeGet() string {
    
    turingResult := _core_custom_event_data__event_type_get(self)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func (self *CustomEventData)getCopy() BeatmapDataItem {
    
    return _core_custom_event_data__get_copy(self)
}

func (self *CustomEventData)versionGet() Version {
    
    return _core_custom_event_data__version_get(self)
}

type CustomNoteData struct {
    opaqu uint32
}


func CustomNoteData_createCustomBasicNoteData(time float32, beat float32, rotation int32, lineIndex int32, noteLineLayer int32, colorType int32, cutDirection int32, customData CustomData, version Version) CustomNoteData {
    
    return _core_custom_note_data__create_custom_basic_note_data(time, beat, rotation, lineIndex, noteLineLayer, colorType, cutDirection, customData, version)
}

func CustomNoteData_createCustomBombNoteData(time float32, beat float32, rotation int32, lineIndex int32, noteLineLayer int32, customData CustomData, version Version) CustomNoteData {
    
    return _core_custom_note_data__create_custom_bomb_note_data(time, beat, rotation, lineIndex, noteLineLayer, customData, version)
}

func CustomNoteData_createCustomBurstSliderNoteData(time float32, beat float32, rotation int32, lineIndex int32, noteLineLayer int32, beforeJumpNoteLineLayer int32, colorType int32, cutDirection int32, cutSfxVolumeMultiplier float32, customData CustomData) CustomNoteData {
    
    return _core_custom_note_data__create_custom_burst_slider_note_data(time, beat, rotation, lineIndex, noteLineLayer, beforeJumpNoteLineLayer, colorType, cutDirection, cutSfxVolumeMultiplier, customData)
}


func (self *CustomNoteData)customDataGet() CustomData {
    
    return _core_custom_note_data__custom_data_get(self)
}

func (self *CustomNoteData)getCopy() BeatmapDataItem {
    
    return _core_custom_note_data__get_copy(self)
}

func (self *CustomNoteData)versionGet() Version {
    
    return _core_custom_note_data__version_get(self)
}

type CustomObstacleData struct {
    opaqu uint32
}



func (self *CustomObstacleData)customDataGet() CustomData {
    
    return _core_custom_obstacle_data__custom_data_get(self)
}

func (self *CustomObstacleData)getCopy() BeatmapDataItem {
    
    return _core_custom_obstacle_data__get_copy(self)
}

func (self *CustomObstacleData)versionGet() Version {
    
    return _core_custom_obstacle_data__version_get(self)
}

type GcHelper struct {
    opaqu uint32
}



type GameObject struct {
    opaqu uint32
}



func (self *GameObject)addComponent(componentType Type) Component {
    
    return _core_game_object__add_component(self, componentType)
}

func (self *GameObject)addOrGetMesh() TuringMesh {
    
    return _core_game_object__add_or_get_mesh(self)
}

func (self *GameObject)broadcastMessage(methodName string, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_game_object__broadcast_message(self, turingHandleMethodName, options)
}

func (self *GameObject)compareTag(tag string) bool {
    
    turingHTag := []byte(tag)
    turingHTag = append(turingHTag, 0)
    turingHandleTag := &turingHTag[0]
    return _core_game_object__compare_tag(self, turingHandleTag)
}

func (self *GameObject)getActive() bool {
    
    return _core_game_object__get_active(self)
}

func (self *GameObject)getActiveInHierarchy() bool {
    
    return _core_game_object__get_active_in_hierarchy(self)
}

func (self *GameObject)getActiveSelf() bool {
    
    return _core_game_object__get_active_self(self)
}

func (self *GameObject)getComponentAtIndex(index int32) Component {
    
    return _core_game_object__get_component_at_index(self, index)
}

func (self *GameObject)getComponentByName(csType string) Component {
    
    turingHCsType := []byte(csType)
    turingHCsType = append(turingHCsType, 0)
    turingHandleCsType := &turingHCsType[0]
    return _core_game_object__get_component_by_name(self, turingHandleCsType)
}

func (self *GameObject)getComponentByType(csType Type) Component {
    
    return _core_game_object__get_component_by_type(self, csType)
}

func (self *GameObject)getComponentCount() int32 {
    
    return _core_game_object__get_component_count(self)
}

func (self *GameObject)getComponentInChildrenByType(csType Type, includeInactive bool) Component {
    
    return _core_game_object__get_component_in_children_by_type(self, csType, includeInactive)
}

func (self *GameObject)getComponentInParentByType(csType Type, includeInactive bool) Component {
    
    return _core_game_object__get_component_in_parent_by_type(self, csType, includeInactive)
}

func (self *GameObject)getComponentIndex(component Component) int32 {
    
    return _core_game_object__get_component_index(self, component)
}

func (self *GameObject)getHideFlags() int32 {
    
    return _core_game_object__get_hide_flags(self)
}

func (self *GameObject)getInstanceId() int32 {
    
    return _core_game_object__get_instance_id(self)
}

func (self *GameObject)getIsStatic() bool {
    
    return _core_game_object__get_is_static(self)
}

func (self *GameObject)getLayer() int32 {
    
    return _core_game_object__get_layer(self)
}

func (self *GameObject)getName() string {
    
    turingResult := _core_game_object__get_name(self)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func (self *GameObject)getSceneCullingMask() uint64 {
    
    return _core_game_object__get_scene_culling_mask(self)
}

func (self *GameObject)getTag() string {
    
    turingResult := _core_game_object__get_tag(self)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func (self *GameObject)getTransform() Transform {
    
    return _core_game_object__get_transform(self)
}

func (self *GameObject)sendMessage(methodName string, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_game_object__send_message(self, turingHandleMethodName, options)
}

func (self *GameObject)sendMessageUpwards(methodName string, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_game_object__send_message_upwards(self, turingHandleMethodName, options)
}

func (self *GameObject)setActive(value bool) void {
    
    _core_game_object__set_active(self, value)
}

func (self *GameObject)setActiveProp(value bool) void {
    
    _core_game_object__set_active_prop(self, value)
}

func (self *GameObject)setActiveRecursively(state bool) void {
    
    _core_game_object__set_active_recursively(self, state)
}

func (self *GameObject)setHideFlags(value int32) void {
    
    _core_game_object__set_hide_flags(self, value)
}

func (self *GameObject)setIsStatic(value bool) void {
    
    _core_game_object__set_is_static(self, value)
}

func (self *GameObject)setLayer(value int32) void {
    
    _core_game_object__set_layer(self, value)
}

func (self *GameObject)setName(value string) void {
    
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_game_object__set_name(self, turingHandleValue)
}

func (self *GameObject)setTag(value string) void {
    
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_game_object__set_tag(self, turingHandleValue)
}

type GcHelper struct {
    opaqu uint32
}


func GcHelper_create() GCHelper {
    
    return _core_gc_helper__create()
}


func (self *GcHelper)dispose() void {
    
    _core_gc_helper__dispose(self)
}

func (self *GcHelper)invalidateAllHandles() void {
    
    _core_gc_helper__invalidate_all_handles(self)
}

func (self *GcHelper)wasmGarbageCollect() void {
    
    _core_gc_helper__wasm_garbage_collect(self)
}

type IAudioTimeSource struct {
    opaqu uint32
}



type IEnumerator struct {
    opaqu uint32
}



type IVariableMovementDataProvider struct {
    opaqu uint32
}



type Int32 struct {
    opaqu uint32
}



type List1 struct {
    opaqu uint32
}



type Log struct {
    
}


func Log_critical(msg string) void {
    
    turingHMsg := []byte(msg)
    turingHMsg = append(turingHMsg, 0)
    turingHandleMsg := &turingHMsg[0]
    _core_log__critical(turingHandleMsg)
}

func Log_debug(msg string) void {
    
    turingHMsg := []byte(msg)
    turingHMsg = append(turingHMsg, 0)
    turingHandleMsg := &turingHMsg[0]
    _core_log__debug(turingHandleMsg)
}

func Log_info(msg string) void {
    
    turingHMsg := []byte(msg)
    turingHMsg = append(turingHMsg, 0)
    turingHandleMsg := &turingHMsg[0]
    _core_log__info(turingHandleMsg)
}

func Log_warn(msg string) void {
    
    turingHMsg := []byte(msg)
    turingHMsg = append(turingHMsg, 0)
    turingHandleMsg := &turingHMsg[0]
    _core_log__warn(turingHandleMsg)
}


type Mesh struct {
    opaqu uint32
}



type NoteController struct {
    opaqu uint32
}



func (self *NoteController)getNoteFloorMovement() NoteFloorMovement {
    
    return _core_note_controller__get_note_floor_movement(self)
}

func (self *NoteController)getNoteJump() NoteJump {
    
    return _core_note_controller__get_note_jump(self)
}

type NoteControllerBase struct {
    opaqu uint32
}



type NoteFloorMovement struct {
    opaqu uint32
}



func (self *NoteFloorMovement)AudioTimeSyncControllerGet() IAudioTimeSource {
    
    return _core_note_floor_movement___audio_time_sync_controller_get(self)
}

func (self *NoteFloorMovement)BeatTimeGet() float32 {
    
    return _core_note_floor_movement___beat_time_get(self)
}

func (self *NoteFloorMovement)BeatTimeSet(value float32) void {
    
    _core_note_floor_movement___beat_time_set(self, value)
}

func (self *NoteFloorMovement)InverseWorldRotationGet() Quat {
    
    _core_note_floor_movement___inverse_world_rotation_get(self)
    return dequeue_quat()
}

func (self *NoteFloorMovement)InverseWorldRotationSet(value Quat) void {
    
    turingHandleValue := enqueue_quat(value)

    _core_note_floor_movement___inverse_world_rotation_set(self, turingHandleValue)
}

func (self *NoteFloorMovement)LocalPositionGet() Vec3 {
    
    _core_note_floor_movement___local_position_get(self)
    return dequeue_vec3()
}

func (self *NoteFloorMovement)LocalPositionSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_note_floor_movement___local_position_set(self, turingHandleValue)
}

func (self *NoteFloorMovement)MoveEndOffsetGet() Vec3 {
    
    _core_note_floor_movement___move_end_offset_get(self)
    return dequeue_vec3()
}

func (self *NoteFloorMovement)MoveEndOffsetSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_note_floor_movement___move_end_offset_set(self, turingHandleValue)
}

func (self *NoteFloorMovement)MoveStartOffsetGet() Vec3 {
    
    _core_note_floor_movement___move_start_offset_get(self)
    return dequeue_vec3()
}

func (self *NoteFloorMovement)MoveStartOffsetSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_note_floor_movement___move_start_offset_set(self, turingHandleValue)
}

func (self *NoteFloorMovement)PlayerTransformsGet() PlayerTransforms {
    
    return _core_note_floor_movement___player_transforms_get(self)
}

func (self *NoteFloorMovement)RotatedObjectGet() Transform {
    
    return _core_note_floor_movement___rotated_object_get(self)
}

func (self *NoteFloorMovement)RotatedObjectSet(value Transform) void {
    
    _core_note_floor_movement___rotated_object_set(self, value)
}

func (self *NoteFloorMovement)VariableMovementDataProviderGet() IVariableMovementDataProvider {
    
    return _core_note_floor_movement___variable_movement_data_provider_get(self)
}

func (self *NoteFloorMovement)WorldRotationGet() Quat {
    
    _core_note_floor_movement___world_rotation_get(self)
    return dequeue_quat()
}

func (self *NoteFloorMovement)WorldRotationSet(value Quat) void {
    
    turingHandleValue := enqueue_quat(value)

    _core_note_floor_movement___world_rotation_set(self, turingHandleValue)
}

func (self *NoteFloorMovement)distanceToPlayerGet() float32 {
    
    return _core_note_floor_movement__distance_to_player_get(self)
}

func (self *NoteFloorMovement)endPosGet() Vec3 {
    
    _core_note_floor_movement__end_pos_get(self)
    return dequeue_vec3()
}

func (self *NoteFloorMovement)init(worldRotation float32, beatTime float32, moveStartOffset Vec3, moveEndOffset Vec3) void {
    
    turingHandleMoveStartOffset := enqueue_vec3(moveStartOffset)

    turingHandleMoveEndOffset := enqueue_vec3(moveEndOffset)

    _core_note_floor_movement__init(self, worldRotation, beatTime, turingHandleMoveStartOffset, turingHandleMoveEndOffset)
}

func (self *NoteFloorMovement)inverseWorldRotationGet() Quat {
    
    _core_note_floor_movement__inverse_world_rotation_get(self)
    return dequeue_quat()
}

func (self *NoteFloorMovement)localPositionGet() Vec3 {
    
    _core_note_floor_movement__local_position_get(self)
    return dequeue_vec3()
}

func (self *NoteFloorMovement)manualUpdate() Vec3 {
    
    _core_note_floor_movement__manual_update(self)
    return dequeue_vec3()
}

func (self *NoteFloorMovement)noteTimeGet() float32 {
    
    return _core_note_floor_movement__note_time_get(self)
}

func (self *NoteFloorMovement)setToStart() Vec3 {
    
    _core_note_floor_movement__set_to_start(self)
    return dequeue_vec3()
}

func (self *NoteFloorMovement)shouldMove() bool {
    
    return _core_note_floor_movement__should_move(self)
}

func (self *NoteFloorMovement)worldRotationGet() Quat {
    
    _core_note_floor_movement__world_rotation_get(self)
    return dequeue_quat()
}

type NoteJump struct {
    opaqu uint32
}


func NoteJump_kMissedTimeOffsetGet() float32 {
    
    return _core_note_jump__k_missed_time_offset_get()
}


func (self *NoteJump)AudioTimeSyncControllerGet() IAudioTimeSource {
    
    return _core_note_jump___audio_time_sync_controller_get(self)
}

func (self *NoteJump)EndDistanceOffsetGet() float32 {
    
    return _core_note_jump___end_distance_offset_get(self)
}

func (self *NoteJump)EndDistanceOffsetSet(value float32) void {
    
    _core_note_jump___end_distance_offset_set(self, value)
}

func (self *NoteJump)EndOffsetGet() Vec3 {
    
    _core_note_jump___end_offset_get(self)
    return dequeue_vec3()
}

func (self *NoteJump)EndOffsetSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_note_jump___end_offset_set(self, turingHandleValue)
}

func (self *NoteJump)EndPosGet() Vec3 {
    
    _core_note_jump___end_pos_get(self)
    return dequeue_vec3()
}

func (self *NoteJump)EndPosSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_note_jump___end_pos_set(self, turingHandleValue)
}

func (self *NoteJump)EndRotationGet() Quat {
    
    _core_note_jump___end_rotation_get(self)
    return dequeue_quat()
}

func (self *NoteJump)EndRotationSet(value Quat) void {
    
    turingHandleValue := enqueue_quat(value)

    _core_note_jump___end_rotation_set(self, turingHandleValue)
}

func (self *NoteJump)GravityBaseGet() float32 {
    
    return _core_note_jump___gravity_base_get(self)
}

func (self *NoteJump)GravityBaseSet(value float32) void {
    
    _core_note_jump___gravity_base_set(self, value)
}

func (self *NoteJump)GravityGet() float32 {
    
    return _core_note_jump___gravity_get(self)
}

func (self *NoteJump)GravitySet(value float32) void {
    
    _core_note_jump___gravity_set(self, value)
}

func (self *NoteJump)HalfJumpDurationGet() float32 {
    
    return _core_note_jump___half_jump_duration_get(self)
}

func (self *NoteJump)HalfJumpDurationSet(value float32) void {
    
    _core_note_jump___half_jump_duration_set(self, value)
}

func (self *NoteJump)HalfJumpMarkReportedGet() bool {
    
    return _core_note_jump___half_jump_mark_reported_get(self)
}

func (self *NoteJump)HalfJumpMarkReportedSet(value bool) void {
    
    _core_note_jump___half_jump_mark_reported_set(self, value)
}

func (self *NoteJump)InverseWorldRotationGet() Quat {
    
    _core_note_jump___inverse_world_rotation_get(self)
    return dequeue_quat()
}

func (self *NoteJump)InverseWorldRotationSet(value Quat) void {
    
    turingHandleValue := enqueue_quat(value)

    _core_note_jump___inverse_world_rotation_set(self, turingHandleValue)
}

func (self *NoteJump)JumpDurationGet() float32 {
    
    return _core_note_jump___jump_duration_get(self)
}

func (self *NoteJump)JumpDurationSet(value float32) void {
    
    _core_note_jump___jump_duration_set(self, value)
}

func (self *NoteJump)JumpStartedReportedGet() bool {
    
    return _core_note_jump___jump_started_reported_get(self)
}

func (self *NoteJump)JumpStartedReportedSet(value bool) void {
    
    _core_note_jump___jump_started_reported_set(self, value)
}

func (self *NoteJump)LocalPositionGet() Vec3 {
    
    _core_note_jump___local_position_get(self)
    return dequeue_vec3()
}

func (self *NoteJump)LocalPositionSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_note_jump___local_position_set(self, turingHandleValue)
}

func (self *NoteJump)MiddleRotationGet() Quat {
    
    _core_note_jump___middle_rotation_get(self)
    return dequeue_quat()
}

func (self *NoteJump)MiddleRotationSet(value Quat) void {
    
    turingHandleValue := enqueue_quat(value)

    _core_note_jump___middle_rotation_set(self, turingHandleValue)
}

func (self *NoteJump)MissedMarkReportedGet() bool {
    
    return _core_note_jump___missed_mark_reported_get(self)
}

func (self *NoteJump)MissedMarkReportedSet(value bool) void {
    
    _core_note_jump___missed_mark_reported_set(self, value)
}

func (self *NoteJump)MissedTimeGet() float32 {
    
    return _core_note_jump___missed_time_get(self)
}

func (self *NoteJump)MissedTimeSet(value float32) void {
    
    _core_note_jump___missed_time_set(self, value)
}

func (self *NoteJump)NoteTimeGet() float32 {
    
    return _core_note_jump___note_time_get(self)
}

func (self *NoteJump)NoteTimeSet(value float32) void {
    
    _core_note_jump___note_time_set(self, value)
}

func (self *NoteJump)PlayerSpaceConvertorGet() PlayerSpaceConvertor {
    
    return _core_note_jump___player_space_convertor_get(self)
}

func (self *NoteJump)PlayerTransformsGet() PlayerTransforms {
    
    return _core_note_jump___player_transforms_get(self)
}

func (self *NoteJump)RotateTowardsPlayerGet() bool {
    
    return _core_note_jump___rotate_towards_player_get(self)
}

func (self *NoteJump)RotateTowardsPlayerSet(value bool) void {
    
    _core_note_jump___rotate_towards_player_set(self, value)
}

func (self *NoteJump)RotatedObjectGet() Transform {
    
    return _core_note_jump___rotated_object_get(self)
}

func (self *NoteJump)RotatedObjectSet(value Transform) void {
    
    _core_note_jump___rotated_object_set(self, value)
}

func (self *NoteJump)StartOffsetGet() Vec3 {
    
    _core_note_jump___start_offset_get(self)
    return dequeue_vec3()
}

func (self *NoteJump)StartOffsetSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_note_jump___start_offset_set(self, turingHandleValue)
}

func (self *NoteJump)StartPosGet() Vec3 {
    
    _core_note_jump___start_pos_get(self)
    return dequeue_vec3()
}

func (self *NoteJump)StartPosSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_note_jump___start_pos_set(self, turingHandleValue)
}

func (self *NoteJump)StartRotationGet() Quat {
    
    _core_note_jump___start_rotation_get(self)
    return dequeue_quat()
}

func (self *NoteJump)StartRotationSet(value Quat) void {
    
    turingHandleValue := enqueue_quat(value)

    _core_note_jump___start_rotation_set(self, turingHandleValue)
}

func (self *NoteJump)ThreeQuartersMarkReportedGet() bool {
    
    return _core_note_jump___three_quarters_mark_reported_get(self)
}

func (self *NoteJump)ThreeQuartersMarkReportedSet(value bool) void {
    
    _core_note_jump___three_quarters_mark_reported_set(self, value)
}

func (self *NoteJump)VariableMovementDataProviderGet() IVariableMovementDataProvider {
    
    return _core_note_jump___variable_movement_data_provider_get(self)
}

func (self *NoteJump)WorldRotationGet() Quat {
    
    _core_note_jump___world_rotation_get(self)
    return dequeue_quat()
}

func (self *NoteJump)WorldRotationSet(value Quat) void {
    
    turingHandleValue := enqueue_quat(value)

    _core_note_jump___world_rotation_set(self, turingHandleValue)
}

func (self *NoteJump)YAvoidanceDownGet() float32 {
    
    return _core_note_jump___y_avoidance_down_get(self)
}

func (self *NoteJump)YAvoidanceDownSet(value float32) void {
    
    _core_note_jump___y_avoidance_down_set(self, value)
}

func (self *NoteJump)YAvoidanceGet() float32 {
    
    return _core_note_jump___y_avoidance_get(self)
}

func (self *NoteJump)YAvoidanceSet(value float32) void {
    
    _core_note_jump___y_avoidance_set(self, value)
}

func (self *NoteJump)YAvoidanceUpGet() float32 {
    
    return _core_note_jump___y_avoidance_up_get(self)
}

func (self *NoteJump)YAvoidanceUpSet(value float32) void {
    
    _core_note_jump___y_avoidance_up_set(self, value)
}

func (self *NoteJump)addNoteJumpDidFinishEvent(value Action) void {
    
    _core_note_jump__add_note_jump_did_finish_event(self, value)
}

func (self *NoteJump)addNoteJumpDidPassHalfEvent(value Action) void {
    
    _core_note_jump__add_note_jump_did_pass_half_event(self, value)
}

func (self *NoteJump)addNoteJumpDidPassMissedMarkerEvent(value Action) void {
    
    _core_note_jump__add_note_jump_did_pass_missed_marker_event(self, value)
}

func (self *NoteJump)addNoteJumpDidPassThreeQuartersEvent(value Action1) void {
    
    _core_note_jump__add_note_jump_did_pass_three_quarters_event(self, value)
}

func (self *NoteJump)addNoteJumpDidStartEvent(value Action) void {
    
    _core_note_jump__add_note_jump_did_start_event(self, value)
}

func (self *NoteJump)addNoteJumpDidUpdateProgressEvent(value Action1) void {
    
    _core_note_jump__add_note_jump_did_update_progress_event(self, value)
}

func (self *NoteJump)beatPosGet() Vec3 {
    
    _core_note_jump__beat_pos_get(self)
    return dequeue_vec3()
}

func (self *NoteJump)distanceToPlayerGet() float32 {
    
    return _core_note_jump__distance_to_player_get(self)
}

func (self *NoteJump)init(noteTime float32, worldRotation float32, moveEndOffset Vec3, jumpEndOffset Vec3, gravityBase float32, flipYSide float32, endRotation float32, rotateTowardsPlayer bool, useRandomRotation bool) void {
    
    turingHandleMoveEndOffset := enqueue_vec3(moveEndOffset)

    turingHandleJumpEndOffset := enqueue_vec3(jumpEndOffset)

    _core_note_jump__init(self, noteTime, worldRotation, turingHandleMoveEndOffset, turingHandleJumpEndOffset, gravityBase, flipYSide, endRotation, rotateTowardsPlayer, useRandomRotation)
}

func (self *NoteJump)localPositionGet() Vec3 {
    
    _core_note_jump__local_position_get(self)
    return dequeue_vec3()
}

func (self *NoteJump)manualUpdate() Vec3 {
    
    _core_note_jump__manual_update(self)
    return dequeue_vec3()
}

func (self *NoteJump)moveVecGet() Vec3 {
    
    _core_note_jump__move_vec_get(self)
    return dequeue_vec3()
}

func (self *NoteJump)noteTimeGet() float32 {
    
    return _core_note_jump__note_time_get(self)
}

func (self *NoteJump)removeNoteJumpDidFinishEvent(value Action) void {
    
    _core_note_jump__remove_note_jump_did_finish_event(self, value)
}

func (self *NoteJump)removeNoteJumpDidPassHalfEvent(value Action) void {
    
    _core_note_jump__remove_note_jump_did_pass_half_event(self, value)
}

func (self *NoteJump)removeNoteJumpDidPassMissedMarkerEvent(value Action) void {
    
    _core_note_jump__remove_note_jump_did_pass_missed_marker_event(self, value)
}

func (self *NoteJump)removeNoteJumpDidPassThreeQuartersEvent(value Action1) void {
    
    _core_note_jump__remove_note_jump_did_pass_three_quarters_event(self, value)
}

func (self *NoteJump)removeNoteJumpDidStartEvent(value Action) void {
    
    _core_note_jump__remove_note_jump_did_start_event(self, value)
}

func (self *NoteJump)removeNoteJumpDidUpdateProgressEvent(value Action1) void {
    
    _core_note_jump__remove_note_jump_did_update_progress_event(self, value)
}

type NoteManager struct {
    
}


func NoteManager_addBombNote(beat float32, line int32, layer int32, customData CustomData) CustomNoteData {
    
    return _core_note_manager__add_bomb_note(beat, line, layer, customData)
}

func NoteManager_addColorNote(beat float32, line int32, layer int32, color int32, cutDirection int32, customData CustomData) CustomNoteData {
    
    return _core_note_manager__add_color_note(beat, line, layer, color, cutDirection, customData)
}

func NoteManager_addObstacle(beat float32, duration float32, line int32, layer int32, width int32, height int32, customData CustomData) CustomObstacleData {
    
    return _core_note_manager__add_obstacle(beat, duration, line, layer, width, height, customData)
}

func NoteManager_getNoteController(n int32) NoteControllerBase {
    
    return _core_note_manager__get_note_controller(n)
}

func NoteManager_getNoteControllerFromCustom(n CustomNoteData) NoteControllerBase {
    
    return _core_note_manager__get_note_controller_from_custom(n)
}

func NoteManager_getNthEvent(id int32) CustomEventData {
    
    return _core_note_manager__get_nth_event(id)
}

func NoteManager_getNthNote(id int32) CustomNoteData {
    
    return _core_note_manager__get_nth_note(id)
}

func NoteManager_getNthObject(id int32) BeatmapDataItem {
    
    return _core_note_manager__get_nth_object(id)
}

func NoteManager_getNthObstacle(id int32) CustomObstacleData {
    
    return _core_note_manager__get_nth_obstacle(id)
}

func NoteManager_getObstacleController(n int32) ObstacleControllerBase {
    
    return _core_note_manager__get_obstacle_controller(n)
}

func NoteManager_getObstacleControllerFromCustom(n CustomObstacleData) ObstacleController {
    
    return _core_note_manager__get_obstacle_controller_from_custom(n)
}

func NoteManager_timeToBeat(time float32) float32 {
    
    return _core_note_manager__time_to_beat(time)
}


type Object struct {
    opaqu uint32
}



type ObstacleController struct {
    opaqu uint32
}



type ObstacleControllerBase struct {
    opaqu uint32
}



type PlayerSpaceConvertor struct {
    opaqu uint32
}



type PlayerTransforms struct {
    opaqu uint32
}



type TaskScheduler struct {
    opaqu uint32
}


func TaskScheduler_schedule(task Action) void {
    
    _core_task_scheduler__schedule(task)
}


func (self *TaskScheduler)dispose() void {
    
    _core_task_scheduler__dispose(self)
}

type Texture2D struct {
    opaqu uint32
}



func (self *Texture2D)apply(updateMipmaps bool, makeNoLongerReadable bool) void {
    
    _core_texture_2_d__apply(self, updateMipmaps, makeNoLongerReadable)
}

func (self *Texture2D)getFormat() int32 {
    
    return _core_texture_2_d__get_format(self)
}

func (self *Texture2D)getGraphicsFormat() int32 {
    
    return _core_texture_2_d__get_graphics_format(self)
}

func (self *Texture2D)getHeight() int32 {
    
    return _core_texture_2_d__get_height(self)
}

func (self *Texture2D)getHideFlags() int32 {
    
    return _core_texture_2_d__get_hide_flags(self)
}

func (self *Texture2D)getInstanceId() int32 {
    
    return _core_texture_2_d__get_instance_id(self)
}

func (self *Texture2D)getIsReadable() bool {
    
    return _core_texture_2_d__get_is_readable(self)
}

func (self *Texture2D)getMipmapCount() int32 {
    
    return _core_texture_2_d__get_mipmap_count(self)
}

func (self *Texture2D)getName() string {
    
    turingResult := _core_texture_2_d__get_name(self)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func (self *Texture2D)getRawTextureData() []uint32 {
    
    turingResult := _core_texture_2_d__get_raw_texture_data(self)
    turingBuf := make([]uint32, turingResult)
    _host_bufcpy(&turingBuf[0], turingResult)
    return turingBuf
}

func (self *Texture2D)getWidth() int32 {
    
    return _core_texture_2_d__get_width(self)
}

func (self *Texture2D)loadRawTextureData(data []uint32) void {
    
    _host_u32_enqueue(len(data))
    turingHData := []uint32(data)
    turingHandleData := &turingHData[0]
    _core_texture_2_d__load_raw_texture_data(self, turingHandleData)
}

func (self *Texture2D)reinitialize(width int32, height int32, format int32, hasMipMap bool) bool {
    
    return _core_texture_2_d__reinitialize(self, width, height, format, hasMipMap)
}

func (self *Texture2D)setHeight(value int32) void {
    
    _core_texture_2_d__set_height(self, value)
}

func (self *Texture2D)setHideFlags(value int32) void {
    
    _core_texture_2_d__set_hide_flags(self, value)
}

func (self *Texture2D)setName(value string) void {
    
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_texture_2_d__set_name(self, turingHandleValue)
}

func (self *Texture2D)setWidth(value int32) void {
    
    _core_texture_2_d__set_width(self, value)
}

type Transform struct {
    opaqu uint32
}



func (self *Transform)broadcastMessage(methodName string, parameter Object, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_transform__broadcast_message(self, turingHandleMethodName, parameter, options)
}

func (self *Transform)compareTag(tag string) bool {
    
    turingHTag := []byte(tag)
    turingHTag = append(turingHTag, 0)
    turingHandleTag := &turingHTag[0]
    return _core_transform__compare_tag(self, turingHandleTag)
}

func (self *Transform)detachChildren() void {
    
    _core_transform__detach_children(self)
}

func (self *Transform)find(n string) Transform {
    
    turingHN := []byte(n)
    turingHN = append(turingHN, 0)
    turingHandleN := &turingHN[0]
    return _core_transform__find(self, turingHandleN)
}

func (self *Transform)findChild(n string) Transform {
    
    turingHN := []byte(n)
    turingHN = append(turingHN, 0)
    turingHandleN := &turingHN[0]
    return _core_transform__find_child(self, turingHandleN)
}

func (self *Transform)getChild(index int32) Transform {
    
    return _core_transform__get_child(self, index)
}

func (self *Transform)getChildCount() int32 {
    
    return _core_transform__get_child_count(self)
}

func (self *Transform)getChildCountProp() int32 {
    
    return _core_transform__get_child_count_prop(self)
}

func (self *Transform)getComponentByName(csType string) Component {
    
    turingHCsType := []byte(csType)
    turingHCsType = append(turingHCsType, 0)
    turingHandleCsType := &turingHCsType[0]
    return _core_transform__get_component_by_name(self, turingHandleCsType)
}

func (self *Transform)getComponentByType(csType Type) Component {
    
    return _core_transform__get_component_by_type(self, csType)
}

func (self *Transform)getComponentInChildrenByType(t Type, includeInactive bool) Component {
    
    return _core_transform__get_component_in_children_by_type(self, t, includeInactive)
}

func (self *Transform)getComponentInParentByType(t Type, includeInactive bool) Component {
    
    return _core_transform__get_component_in_parent_by_type(self, t, includeInactive)
}

func (self *Transform)getComponentIndex() int32 {
    
    return _core_transform__get_component_index(self)
}

func (self *Transform)getEnumerator() IEnumerator {
    
    return _core_transform__get_enumerator(self)
}

func (self *Transform)getEulerAngles() Vec3 {
    
    _core_transform__get_euler_angles(self)
    return dequeue_vec3()
}

func (self *Transform)getForward() Vec3 {
    
    _core_transform__get_forward(self)
    return dequeue_vec3()
}

func (self *Transform)getGameObject() GameObject {
    
    return _core_transform__get_game_object(self)
}

func (self *Transform)getHasChanged() bool {
    
    return _core_transform__get_has_changed(self)
}

func (self *Transform)getHideFlags() int32 {
    
    return _core_transform__get_hide_flags(self)
}

func (self *Transform)getHierarchyCapacity() int32 {
    
    return _core_transform__get_hierarchy_capacity(self)
}

func (self *Transform)getHierarchyCount() int32 {
    
    return _core_transform__get_hierarchy_count(self)
}

func (self *Transform)getInstanceId() int32 {
    
    return _core_transform__get_instance_id(self)
}

func (self *Transform)getLocalEulerAngles() Vec3 {
    
    _core_transform__get_local_euler_angles(self)
    return dequeue_vec3()
}

func (self *Transform)getLocalPosition() Vec3 {
    
    _core_transform__get_local_position(self)
    return dequeue_vec3()
}

func (self *Transform)getLocalRotation() Quat {
    
    _core_transform__get_local_rotation(self)
    return dequeue_quat()
}

func (self *Transform)getLocalScale() Vec3 {
    
    _core_transform__get_local_scale(self)
    return dequeue_vec3()
}

func (self *Transform)getLocalToWorldMatrix() Mat4 {
    
    _core_transform__get_local_to_world_matrix(self)
    return dequeue_mat4()
}

func (self *Transform)getLossyScale() Vec3 {
    
    _core_transform__get_lossy_scale(self)
    return dequeue_vec3()
}

func (self *Transform)getName() string {
    
    turingResult := _core_transform__get_name(self)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func (self *Transform)getParent() Transform {
    
    return _core_transform__get_parent(self)
}

func (self *Transform)getPosition() Vec3 {
    
    _core_transform__get_position(self)
    return dequeue_vec3()
}

func (self *Transform)getRight() Vec3 {
    
    _core_transform__get_right(self)
    return dequeue_vec3()
}

func (self *Transform)getRoot() Transform {
    
    return _core_transform__get_root(self)
}

func (self *Transform)getRotation() Quat {
    
    _core_transform__get_rotation(self)
    return dequeue_quat()
}

func (self *Transform)getSiblingIndex() int32 {
    
    return _core_transform__get_sibling_index(self)
}

func (self *Transform)getTag() string {
    
    turingResult := _core_transform__get_tag(self)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func (self *Transform)getUp() Vec3 {
    
    _core_transform__get_up(self)
    return dequeue_vec3()
}

func (self *Transform)getWorldToLocalMatrix() Mat4 {
    
    _core_transform__get_world_to_local_matrix(self)
    return dequeue_mat4()
}

func (self *Transform)inverseTransformDirection(direction Vec3) Vec3 {
    
    turingHandleDirection := enqueue_vec3(direction)

    _core_transform__inverse_transform_direction(self, turingHandleDirection)
    return dequeue_vec3()
}

func (self *Transform)inverseTransformPoint(position Vec3) Vec3 {
    
    turingHandlePosition := enqueue_vec3(position)

    _core_transform__inverse_transform_point(self, turingHandlePosition)
    return dequeue_vec3()
}

func (self *Transform)inverseTransformVector(vector Vec3) Vec3 {
    
    turingHandleVector := enqueue_vec3(vector)

    _core_transform__inverse_transform_vector(self, turingHandleVector)
    return dequeue_vec3()
}

func (self *Transform)isChildOf(parent Transform) bool {
    
    return _core_transform__is_child_of(self, parent)
}

func (self *Transform)lookAt(target Transform, worldUp Vec3) void {
    
    turingHandleWorldUp := enqueue_vec3(worldUp)

    _core_transform__look_at(self, target, turingHandleWorldUp)
}

func (self *Transform)rotate(eulers Vec3) void {
    
    turingHandleEulers := enqueue_vec3(eulers)

    _core_transform__rotate(self, turingHandleEulers)
}

func (self *Transform)rotateAround(point Vec3, axis Vec3, angle float32) void {
    
    turingHandlePoint := enqueue_vec3(point)

    turingHandleAxis := enqueue_vec3(axis)

    _core_transform__rotate_around(self, turingHandlePoint, turingHandleAxis, angle)
}

func (self *Transform)rotateAroundLocal(axis Vec3, angle float32) void {
    
    turingHandleAxis := enqueue_vec3(axis)

    _core_transform__rotate_around_local(self, turingHandleAxis, angle)
}

func (self *Transform)rotateRelative(eulers Vec3, relativeTo int32) void {
    
    turingHandleEulers := enqueue_vec3(eulers)

    _core_transform__rotate_relative(self, turingHandleEulers, relativeTo)
}

func (self *Transform)sendMessage(methodName string, value Object, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_transform__send_message(self, turingHandleMethodName, value, options)
}

func (self *Transform)sendMessageUpwards(methodName string, value Object, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_transform__send_message_upwards(self, turingHandleMethodName, value, options)
}

func (self *Transform)setAsFirstSibling() void {
    
    _core_transform__set_as_first_sibling(self)
}

func (self *Transform)setAsLastSibling() void {
    
    _core_transform__set_as_last_sibling(self)
}

func (self *Transform)setEulerAngles(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_transform__set_euler_angles(self, turingHandleValue)
}

func (self *Transform)setForward(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_transform__set_forward(self, turingHandleValue)
}

func (self *Transform)setHasChanged(value bool) void {
    
    _core_transform__set_has_changed(self, value)
}

func (self *Transform)setHideFlags(value int32) void {
    
    _core_transform__set_hide_flags(self, value)
}

func (self *Transform)setHierarchyCapacity(value int32) void {
    
    _core_transform__set_hierarchy_capacity(self, value)
}

func (self *Transform)setLocalEulerAngles(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_transform__set_local_euler_angles(self, turingHandleValue)
}

func (self *Transform)setLocalPosition(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_transform__set_local_position(self, turingHandleValue)
}

func (self *Transform)setLocalPositionAndRotation(localPosition Vec3, localRotation Quat) void {
    
    turingHandleLocalPosition := enqueue_vec3(localPosition)

    turingHandleLocalRotation := enqueue_quat(localRotation)

    _core_transform__set_local_position_and_rotation(self, turingHandleLocalPosition, turingHandleLocalRotation)
}

func (self *Transform)setLocalRotation(value Quat) void {
    
    turingHandleValue := enqueue_quat(value)

    _core_transform__set_local_rotation(self, turingHandleValue)
}

func (self *Transform)setLocalScale(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_transform__set_local_scale(self, turingHandleValue)
}

func (self *Transform)setName(value string) void {
    
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_transform__set_name(self, turingHandleValue)
}

func (self *Transform)setParent(parent Transform, worldPositionStays bool) void {
    
    _core_transform__set_parent(self, parent, worldPositionStays)
}

func (self *Transform)setPosition(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_transform__set_position(self, turingHandleValue)
}

func (self *Transform)setPositionAndRotation(position Vec3, rotation Quat) void {
    
    turingHandlePosition := enqueue_vec3(position)

    turingHandleRotation := enqueue_quat(rotation)

    _core_transform__set_position_and_rotation(self, turingHandlePosition, turingHandleRotation)
}

func (self *Transform)setRight(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_transform__set_right(self, turingHandleValue)
}

func (self *Transform)setRotation(value Quat) void {
    
    turingHandleValue := enqueue_quat(value)

    _core_transform__set_rotation(self, turingHandleValue)
}

func (self *Transform)setSiblingIndex(index int32) void {
    
    _core_transform__set_sibling_index(self, index)
}

func (self *Transform)setTag(value string) void {
    
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_transform__set_tag(self, turingHandleValue)
}

func (self *Transform)setUp(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_transform__set_up(self, turingHandleValue)
}

func (self *Transform)transformDirection(direction Vec3) Vec3 {
    
    turingHandleDirection := enqueue_vec3(direction)

    _core_transform__transform_direction(self, turingHandleDirection)
    return dequeue_vec3()
}

func (self *Transform)transformPoint(position Vec3) Vec3 {
    
    turingHandlePosition := enqueue_vec3(position)

    _core_transform__transform_point(self, turingHandlePosition)
    return dequeue_vec3()
}

func (self *Transform)transformVector(vector Vec3) Vec3 {
    
    turingHandleVector := enqueue_vec3(vector)

    _core_transform__transform_vector(self, turingHandleVector)
    return dequeue_vec3()
}

func (self *Transform)translate(translation Vec3, relativeTo int32) void {
    
    turingHandleTranslation := enqueue_vec3(translation)

    _core_transform__translate(self, turingHandleTranslation, relativeTo)
}

func (self *Transform)translateRelative(translation Vec3, relativeTo Transform) void {
    
    turingHandleTranslation := enqueue_vec3(translation)

    _core_transform__translate_relative(self, turingHandleTranslation, relativeTo)
}

type TuringMesh struct {
    opaqu uint32
}



func (self *TuringMesh)MeshGet() Mesh {
    
    return _core_turing_mesh___mesh_get(self)
}

func (self *TuringMesh)MeshSet(value Mesh) void {
    
    _core_turing_mesh___mesh_set(self, value)
}

func (self *TuringMesh)clear() void {
    
    _core_turing_mesh__clear(self)
}

func (self *TuringMesh)getBoundsMaxX() float32 {
    
    return _core_turing_mesh__get_bounds_max_x(self)
}

func (self *TuringMesh)getBoundsMaxY() float32 {
    
    return _core_turing_mesh__get_bounds_max_y(self)
}

func (self *TuringMesh)getBoundsMaxZ() float32 {
    
    return _core_turing_mesh__get_bounds_max_z(self)
}

func (self *TuringMesh)getBoundsMinX() float32 {
    
    return _core_turing_mesh__get_bounds_min_x(self)
}

func (self *TuringMesh)getBoundsMinY() float32 {
    
    return _core_turing_mesh__get_bounds_min_y(self)
}

func (self *TuringMesh)getBoundsMinZ() float32 {
    
    return _core_turing_mesh__get_bounds_min_z(self)
}

func (self *TuringMesh)getInstanceId() int32 {
    
    return _core_turing_mesh__get_instance_id(self)
}

func (self *TuringMesh)getUVs(channel int32) []uint32 {
    
    turingResult := _core_turing_mesh__get_u_vs(self, channel)
    turingBuf := make([]uint32, turingResult)
    _host_bufcpy(&turingBuf[0], turingResult)
    return turingBuf
}

func (self *TuringMesh)getVertices() []uint32 {
    
    turingResult := _core_turing_mesh__get_vertices(self)
    turingBuf := make([]uint32, turingResult)
    _host_bufcpy(&turingBuf[0], turingResult)
    return turingBuf
}

func (self *TuringMesh)hideFlagsGet() int32 {
    
    return _core_turing_mesh__hide_flags_get(self)
}

func (self *TuringMesh)hideFlagsSet(value int32) void {
    
    _core_turing_mesh__hide_flags_set(self, value)
}

func (self *TuringMesh)markModified() void {
    
    _core_turing_mesh__mark_modified(self)
}

func (self *TuringMesh)nameGet() string {
    
    turingResult := _core_turing_mesh__name_get(self)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func (self *TuringMesh)nameSet(value string) void {
    
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_turing_mesh__name_set(self, turingHandleValue)
}

func (self *TuringMesh)optimize() void {
    
    _core_turing_mesh__optimize(self)
}

func (self *TuringMesh)optimizeIndexBuffers() void {
    
    _core_turing_mesh__optimize_index_buffers(self)
}

func (self *TuringMesh)recalculateBounds() void {
    
    _core_turing_mesh__recalculate_bounds(self)
}

func (self *TuringMesh)recalculateNormals() void {
    
    _core_turing_mesh__recalculate_normals(self)
}

func (self *TuringMesh)recalculateTangents() void {
    
    _core_turing_mesh__recalculate_tangents(self)
}

func (self *TuringMesh)setBounds(minX float32, minY float32, minZ float32, maxX float32, maxY float32, maxZ float32) void {
    
    _core_turing_mesh__set_bounds(self, minX, minY, minZ, maxX, maxY, maxZ)
}

func (self *TuringMesh)setTriangles(triangles Int32, submesh int32, calculateBounds bool, baseVertex int32) void {
    
    _core_turing_mesh__set_triangles(self, triangles, submesh, calculateBounds, baseVertex)
}

func (self *TuringMesh)setUVs(channel int32, uvs []uint32) void {
    
    _host_u32_enqueue(len(uvs))
    turingHUvs := []uint32(uvs)
    turingHandleUvs := &turingHUvs[0]
    _core_turing_mesh__set_u_vs(self, channel, turingHandleUvs)
}

func (self *TuringMesh)setVertices(inVertices []uint32) void {
    
    _host_u32_enqueue(len(inVertices))
    turingHInVertices := []uint32(inVertices)
    turingHandleInVertices := &turingHInVertices[0]
    _core_turing_mesh__set_vertices(self, turingHandleInVertices)
}

func (self *TuringMesh)uploadMeshData(markNoLongerReadable bool) void {
    
    _core_turing_mesh__upload_mesh_data(self, markNoLongerReadable)
}

type TuringScriptManager struct {
    opaqu uint32
}



type TuringTexture2D struct {
    
}


func TuringTexture2D_create(width int32, height int32, format int32, mipmap bool) Texture2D {
    
    return _core_turing_texture_2_d__create(width, height, format, mipmap)
}

func TuringTexture2D_destroy(texture2D Texture2D) void {
    
    _core_turing_texture_2_d__destroy(texture2D)
}

func TuringTexture2D_find(name string) Texture2D {
    
    turingHName := []byte(name)
    turingHName = append(turingHName, 0)
    turingHandleName := &turingHName[0]
    return _core_turing_texture_2_d__find(turingHandleName)
}


type TuringerGameObjectManager struct {
    opaqu uint32
}


func TuringerGameObjectManager_createObject(name string) GameObject {
    
    turingHName := []byte(name)
    turingHName = append(turingHName, 0)
    turingHandleName := &turingHName[0]
    return _core_turinger_game_object_manager__create_object(turingHandleName)
}

func TuringerGameObjectManager_destroyObject(gameObject GameObject) void {
    
    _core_turinger_game_object_manager__destroy_object(gameObject)
}

func TuringerGameObjectManager_find(name string) GameObject {
    
    turingHName := []byte(name)
    turingHName = append(turingHName, 0)
    turingHandleName := &turingHName[0]
    return _core_turinger_game_object_manager__find(turingHandleName)
}


func (self *TuringerGameObjectManager)instanceGet() TuringerGameObjectManager {
    
    return _core_turinger_game_object_manager__instance_get(self)
}

type Type struct {
    opaqu uint32
}



type Version struct {
    opaqu uint32
}



type Xr struct {
    opaqu uint32
}


func Xr_getDeviceBatteryLevel(nodeInt int32) float32 {
    
    return _core_xr__get_device_battery_level(nodeInt)
}

func Xr_getDeviceGripValue(nodeInt int32) float32 {
    
    return _core_xr__get_device_grip_value(nodeInt)
}

func Xr_getDeviceName(nodeInt int32) string {
    
    turingResult := _core_xr__get_device_name(nodeInt)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func Xr_getDevicePrimaryButtonState(nodeInt int32) bool {
    
    return _core_xr__get_device_primary_button_state(nodeInt)
}

func Xr_getDeviceSecondaryButtonState(nodeInt int32) bool {
    
    return _core_xr__get_device_secondary_button_state(nodeInt)
}

func Xr_getDeviceThumbstick(nodeInt int32) Vec2 {
    
    _core_xr__get_device_thumbstick(nodeInt)
    return dequeue_vec2()
}

func Xr_getDeviceTouchpad(nodeInt int32) Vec2 {
    
    _core_xr__get_device_touchpad(nodeInt)
    return dequeue_vec2()
}

func Xr_getDeviceTrackingState(nodeInt int32) int32 {
    
    return _core_xr__get_device_tracking_state(nodeInt)
}

func Xr_getDeviceTriggerValue(nodeInt int32) float32 {
    
    return _core_xr__get_device_trigger_value(nodeInt)
}

func Xr_isDeviceValid(nodeInt int32) bool {
    
    return _core_xr__is_device_valid(nodeInt)
}

func Xr_sendHapticImpulse(nodeInt int32, amplitude float32, duration float32) void {
    
    _core_xr__send_haptic_impulse(nodeInt, amplitude, duration)
}

func Xr_stopHaptics(nodeInt int32) void {
    
    _core_xr__stop_haptics(nodeInt)
}


func (self *Xr)ManagerGet() TuringScriptManager {
    
    return _core_xr___manager_get(self)
}


