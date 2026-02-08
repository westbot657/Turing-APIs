


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
//go:wasmimport env _core_gc_helper__create
func _core_gc_helper__create() GcHelper
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
//go:wasmimport env _core_note_manager__add_bomb_note
func _core_note_manager__add_bomb_note(beat float32, line int32, layer int32, custom_data CustomData) void
//go:wasmimport env _core_note_manager__add_color_note
func _core_note_manager__add_color_note(beat float32, line int32, layer int32, color int32, cut_direction int32, custom_data CustomData) void
//go:wasmimport env _core_note_manager__add_obstacle
func _core_note_manager__add_obstacle(beat float32, duration float32, line int32, layer int32, width int32, height int32, custom_data CustomData) void
//go:wasmimport env _core_note_manager__time_to_beat
func _core_note_manager__time_to_beat(time float32) float32
//go:wasmimport env _core_task_scheduler__schedule
func _core_task_scheduler__schedule(task Action) void
//go:wasmimport env _core_task_scheduler__dispose
func _core_task_scheduler__dispose(handle TaskScheduler) void
//go:wasmimport env _core_turinger_game_object__active_get
func _core_turinger_game_object__active_get(handle TuringerGameObject) bool
//go:wasmimport env _core_turinger_game_object__active_in_hierarchy_get
func _core_turinger_game_object__active_in_hierarchy_get(handle TuringerGameObject) bool
//go:wasmimport env _core_turinger_game_object__active_self_get
func _core_turinger_game_object__active_self_get(handle TuringerGameObject) bool
//go:wasmimport env _core_turinger_game_object__active_set
func _core_turinger_game_object__active_set(handle TuringerGameObject, value bool) void
//go:wasmimport env _core_turinger_game_object__add_component
func _core_turinger_game_object__add_component(handle TuringerGameObject, component_type Type) Component
//go:wasmimport env _core_turinger_game_object__broadcast_message
func _core_turinger_game_object__broadcast_message(handle TuringerGameObject, method_name uint32, options int32) void
//go:wasmimport env _core_turinger_game_object__compare_tag
func _core_turinger_game_object__compare_tag(handle TuringerGameObject, tag uint32) bool
//go:wasmimport env _core_turinger_game_object__game_object_get
func _core_turinger_game_object__game_object_get(handle TuringerGameObject) GameObject
//go:wasmimport env _core_turinger_game_object__get_component_at_index
func _core_turinger_game_object__get_component_at_index(handle TuringerGameObject, index int32) Component
//go:wasmimport env _core_turinger_game_object__get_component_by_name
func _core_turinger_game_object__get_component_by_name(handle TuringerGameObject, cs_type uint32) Component
//go:wasmimport env _core_turinger_game_object__get_component_by_type
func _core_turinger_game_object__get_component_by_type(handle TuringerGameObject, cs_type Type) Component
//go:wasmimport env _core_turinger_game_object__get_component_count
func _core_turinger_game_object__get_component_count(handle TuringerGameObject) int32
//go:wasmimport env _core_turinger_game_object__get_component_in_children_by_type
func _core_turinger_game_object__get_component_in_children_by_type(handle TuringerGameObject, cs_type Type, include_inactive bool) Component
//go:wasmimport env _core_turinger_game_object__get_component_in_parent_by_type
func _core_turinger_game_object__get_component_in_parent_by_type(handle TuringerGameObject, cs_type Type, include_inactive bool) Component
//go:wasmimport env _core_turinger_game_object__get_component_index
func _core_turinger_game_object__get_component_index(handle TuringerGameObject, component Component) int32
//go:wasmimport env _core_turinger_game_object__get_instance_id
func _core_turinger_game_object__get_instance_id(handle TuringerGameObject) int32
//go:wasmimport env _core_turinger_game_object__hide_flags_get
func _core_turinger_game_object__hide_flags_get(handle TuringerGameObject) int32
//go:wasmimport env _core_turinger_game_object__hide_flags_set
func _core_turinger_game_object__hide_flags_set(handle TuringerGameObject, value int32) void
//go:wasmimport env _core_turinger_game_object__is_static_get
func _core_turinger_game_object__is_static_get(handle TuringerGameObject) bool
//go:wasmimport env _core_turinger_game_object__is_static_set
func _core_turinger_game_object__is_static_set(handle TuringerGameObject, value bool) void
//go:wasmimport env _core_turinger_game_object__layer_get
func _core_turinger_game_object__layer_get(handle TuringerGameObject) int32
//go:wasmimport env _core_turinger_game_object__layer_set
func _core_turinger_game_object__layer_set(handle TuringerGameObject, value int32) void
//go:wasmimport env _core_turinger_game_object__name_get
func _core_turinger_game_object__name_get(handle TuringerGameObject) uint32
//go:wasmimport env _core_turinger_game_object__name_set
func _core_turinger_game_object__name_set(handle TuringerGameObject, value uint32) void
//go:wasmimport env _core_turinger_game_object__scene_culling_mask_get
func _core_turinger_game_object__scene_culling_mask_get(handle TuringerGameObject) uint64
//go:wasmimport env _core_turinger_game_object__send_message
func _core_turinger_game_object__send_message(handle TuringerGameObject, method_name uint32, options int32) void
//go:wasmimport env _core_turinger_game_object__send_message_upwards
func _core_turinger_game_object__send_message_upwards(handle TuringerGameObject, method_name uint32, options int32) void
//go:wasmimport env _core_turinger_game_object__set_active
func _core_turinger_game_object__set_active(handle TuringerGameObject, value bool) void
//go:wasmimport env _core_turinger_game_object__set_active_recursively
func _core_turinger_game_object__set_active_recursively(handle TuringerGameObject, state bool) void
//go:wasmimport env _core_turinger_game_object__tag_get
func _core_turinger_game_object__tag_get(handle TuringerGameObject) uint32
//go:wasmimport env _core_turinger_game_object__tag_set
func _core_turinger_game_object__tag_set(handle TuringerGameObject, value uint32) void
//go:wasmimport env _core_turinger_game_object__transform_get
func _core_turinger_game_object__transform_get(handle TuringerGameObject) TuringerTransform
//go:wasmimport env _core_turinger_game_object_manager__create_object
func _core_turinger_game_object_manager__create_object(name uint32) TuringerGameObject
//go:wasmimport env _core_turinger_game_object_manager__destroy_object
func _core_turinger_game_object_manager__destroy_object(listener TuringerGameObject) void
//go:wasmimport env _core_turinger_game_object_manager__find
func _core_turinger_game_object_manager__find(name uint32) TuringerGameObject
//go:wasmimport env _core_turinger_game_object_manager__instance_get
func _core_turinger_game_object_manager__instance_get(handle TuringerGameObjectManager) TuringerGameObjectManager
//go:wasmimport env _core_turinger_transform__broadcast_message
func _core_turinger_transform__broadcast_message(handle TuringerTransform, method_name uint32, parameter Object, options int32) void
//go:wasmimport env _core_turinger_transform__child_count_get
func _core_turinger_transform__child_count_get(handle TuringerTransform) int32
//go:wasmimport env _core_turinger_transform__compare_tag
func _core_turinger_transform__compare_tag(handle TuringerTransform, tag uint32) bool
//go:wasmimport env _core_turinger_transform__detach_children
func _core_turinger_transform__detach_children(handle TuringerTransform) void
//go:wasmimport env _core_turinger_transform__euler_angles_get
func _core_turinger_transform__euler_angles_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__euler_angles_set
func _core_turinger_transform__euler_angles_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__find
func _core_turinger_transform__find(handle TuringerTransform, n uint32) TuringerTransform
//go:wasmimport env _core_turinger_transform__find_child
func _core_turinger_transform__find_child(handle TuringerTransform, n uint32) TuringerTransform
//go:wasmimport env _core_turinger_transform__forward_get
func _core_turinger_transform__forward_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__forward_set
func _core_turinger_transform__forward_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__game_object_get
func _core_turinger_transform__game_object_get(handle TuringerTransform) TuringerGameObject
//go:wasmimport env _core_turinger_transform__get_child
func _core_turinger_transform__get_child(handle TuringerTransform, index int32) TuringerTransform
//go:wasmimport env _core_turinger_transform__get_child_count
func _core_turinger_transform__get_child_count(handle TuringerTransform) int32
//go:wasmimport env _core_turinger_transform__get_component_by_name
func _core_turinger_transform__get_component_by_name(handle TuringerTransform, cs_type uint32) Component
//go:wasmimport env _core_turinger_transform__get_component_by_type
func _core_turinger_transform__get_component_by_type(handle TuringerTransform, cs_type Type) Component
//go:wasmimport env _core_turinger_transform__get_component_in_children_by_type
func _core_turinger_transform__get_component_in_children_by_type(handle TuringerTransform, t Type, include_inactive bool) Component
//go:wasmimport env _core_turinger_transform__get_component_in_parent_by_type
func _core_turinger_transform__get_component_in_parent_by_type(handle TuringerTransform, t Type, include_inactive bool) Component
//go:wasmimport env _core_turinger_transform__get_component_index
func _core_turinger_transform__get_component_index(handle TuringerTransform) int32
//go:wasmimport env _core_turinger_transform__get_enumerator
func _core_turinger_transform__get_enumerator(handle TuringerTransform) IEnumerator
//go:wasmimport env _core_turinger_transform__get_instance_id
func _core_turinger_transform__get_instance_id(handle TuringerTransform) int32
//go:wasmimport env _core_turinger_transform__get_sibling_index
func _core_turinger_transform__get_sibling_index(handle TuringerTransform) int32
//go:wasmimport env _core_turinger_transform__has_changed_get
func _core_turinger_transform__has_changed_get(handle TuringerTransform) bool
//go:wasmimport env _core_turinger_transform__has_changed_set
func _core_turinger_transform__has_changed_set(handle TuringerTransform, value bool) void
//go:wasmimport env _core_turinger_transform__hide_flags_get
func _core_turinger_transform__hide_flags_get(handle TuringerTransform) int32
//go:wasmimport env _core_turinger_transform__hide_flags_set
func _core_turinger_transform__hide_flags_set(handle TuringerTransform, value int32) void
//go:wasmimport env _core_turinger_transform__hierarchy_capacity_get
func _core_turinger_transform__hierarchy_capacity_get(handle TuringerTransform) int32
//go:wasmimport env _core_turinger_transform__hierarchy_capacity_set
func _core_turinger_transform__hierarchy_capacity_set(handle TuringerTransform, value int32) void
//go:wasmimport env _core_turinger_transform__hierarchy_count_get
func _core_turinger_transform__hierarchy_count_get(handle TuringerTransform) int32
//go:wasmimport env _core_turinger_transform__inverse_transform_direction
func _core_turinger_transform__inverse_transform_direction(handle TuringerTransform, direction uint32) uint32
//go:wasmimport env _core_turinger_transform__inverse_transform_point
func _core_turinger_transform__inverse_transform_point(handle TuringerTransform, position uint32) uint32
//go:wasmimport env _core_turinger_transform__inverse_transform_vector
func _core_turinger_transform__inverse_transform_vector(handle TuringerTransform, vector uint32) uint32
//go:wasmimport env _core_turinger_transform__is_child_of
func _core_turinger_transform__is_child_of(handle TuringerTransform, parent TuringerTransform) bool
//go:wasmimport env _core_turinger_transform__local_euler_angles_get
func _core_turinger_transform__local_euler_angles_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__local_euler_angles_set
func _core_turinger_transform__local_euler_angles_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__local_position_get
func _core_turinger_transform__local_position_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__local_position_set
func _core_turinger_transform__local_position_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__local_rotation_get
func _core_turinger_transform__local_rotation_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__local_rotation_set
func _core_turinger_transform__local_rotation_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__local_scale_get
func _core_turinger_transform__local_scale_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__local_scale_set
func _core_turinger_transform__local_scale_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__local_to_world_matrix_get
func _core_turinger_transform__local_to_world_matrix_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__look_at
func _core_turinger_transform__look_at(handle TuringerTransform, target TuringerTransform, world_up uint32) void
//go:wasmimport env _core_turinger_transform__lossy_scale_get
func _core_turinger_transform__lossy_scale_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__name_get
func _core_turinger_transform__name_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__name_set
func _core_turinger_transform__name_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__parent_get
func _core_turinger_transform__parent_get(handle TuringerTransform) TuringerTransform
//go:wasmimport env _core_turinger_transform__parent_set
func _core_turinger_transform__parent_set(handle TuringerTransform, value TuringerTransform) void
//go:wasmimport env _core_turinger_transform__position_get
func _core_turinger_transform__position_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__position_set
func _core_turinger_transform__position_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__right_get
func _core_turinger_transform__right_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__right_set
func _core_turinger_transform__right_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__root_get
func _core_turinger_transform__root_get(handle TuringerTransform) TuringerTransform
//go:wasmimport env _core_turinger_transform__rotate
func _core_turinger_transform__rotate(handle TuringerTransform, eulers uint32) void
//go:wasmimport env _core_turinger_transform__rotate_around
func _core_turinger_transform__rotate_around(handle TuringerTransform, point uint32, axis uint32, angle float32) void
//go:wasmimport env _core_turinger_transform__rotate_around_local
func _core_turinger_transform__rotate_around_local(handle TuringerTransform, axis uint32, angle float32) void
//go:wasmimport env _core_turinger_transform__rotate_relative
func _core_turinger_transform__rotate_relative(handle TuringerTransform, eulers uint32, relative_to int32) void
//go:wasmimport env _core_turinger_transform__rotation_get
func _core_turinger_transform__rotation_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__rotation_set
func _core_turinger_transform__rotation_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__send_message
func _core_turinger_transform__send_message(handle TuringerTransform, method_name uint32, value Object, options int32) void
//go:wasmimport env _core_turinger_transform__send_message_upwards
func _core_turinger_transform__send_message_upwards(handle TuringerTransform, method_name uint32, value Object, options int32) void
//go:wasmimport env _core_turinger_transform__set_as_first_sibling
func _core_turinger_transform__set_as_first_sibling(handle TuringerTransform) void
//go:wasmimport env _core_turinger_transform__set_as_last_sibling
func _core_turinger_transform__set_as_last_sibling(handle TuringerTransform) void
//go:wasmimport env _core_turinger_transform__set_local_position_and_rotation
func _core_turinger_transform__set_local_position_and_rotation(handle TuringerTransform, local_position uint32, local_rotation uint32) void
//go:wasmimport env _core_turinger_transform__set_parent
func _core_turinger_transform__set_parent(handle TuringerTransform, parent TuringerTransform, world_position_stays bool) void
//go:wasmimport env _core_turinger_transform__set_position_and_rotation
func _core_turinger_transform__set_position_and_rotation(handle TuringerTransform, position uint32, rotation uint32) void
//go:wasmimport env _core_turinger_transform__set_sibling_index
func _core_turinger_transform__set_sibling_index(handle TuringerTransform, index int32) void
//go:wasmimport env _core_turinger_transform__tag_get
func _core_turinger_transform__tag_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__tag_set
func _core_turinger_transform__tag_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__transform_direction
func _core_turinger_transform__transform_direction(handle TuringerTransform, direction uint32) uint32
//go:wasmimport env _core_turinger_transform__transform_get
func _core_turinger_transform__transform_get(handle TuringerTransform) Transform
//go:wasmimport env _core_turinger_transform__transform_point
func _core_turinger_transform__transform_point(handle TuringerTransform, position uint32) uint32
//go:wasmimport env _core_turinger_transform__transform_vector
func _core_turinger_transform__transform_vector(handle TuringerTransform, vector uint32) uint32
//go:wasmimport env _core_turinger_transform__translate
func _core_turinger_transform__translate(handle TuringerTransform, translation uint32, relative_to int32) void
//go:wasmimport env _core_turinger_transform__translate_relative
func _core_turinger_transform__translate_relative(handle TuringerTransform, translation uint32, relative_to TuringerTransform) void
//go:wasmimport env _core_turinger_transform__up_get
func _core_turinger_transform__up_get(handle TuringerTransform) uint32
//go:wasmimport env _core_turinger_transform__up_set
func _core_turinger_transform__up_set(handle TuringerTransform, value uint32) void
//go:wasmimport env _core_turinger_transform__world_to_local_matrix_get
func _core_turinger_transform__world_to_local_matrix_get(handle TuringerTransform) uint32
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



type Component struct {
    opaqu uint32
}



type CustomData struct {
    opaqu uint32
}


func CustomData_create() CustomData {
    
    return _core_custom_data__create()
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


type GameObject struct {
    opaqu uint32
}



type GcHelper struct {
    opaqu uint32
}


func GcHelper_create() GcHelper {
    
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

type IEnumerator struct {
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


type NoteManager struct {
    
}


func NoteManager_addBombNote(beat float32, line int32, layer int32, customData CustomData) void {
    
    _core_note_manager__add_bomb_note(beat, line, layer, customData)
}

func NoteManager_addColorNote(beat float32, line int32, layer int32, color int32, cutDirection int32, customData CustomData) void {
    
    _core_note_manager__add_color_note(beat, line, layer, color, cutDirection, customData)
}

func NoteManager_addObstacle(beat float32, duration float32, line int32, layer int32, width int32, height int32, customData CustomData) void {
    
    _core_note_manager__add_obstacle(beat, duration, line, layer, width, height, customData)
}

func NoteManager_timeToBeat(time float32) float32 {
    
    return _core_note_manager__time_to_beat(time)
}


type Object struct {
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

type Transform struct {
    opaqu uint32
}



type TuringScriptManager struct {
    opaqu uint32
}



type TuringerGameObject struct {
    opaqu uint32
}



func (self *TuringerGameObject)activeGet() bool {
    
    return _core_turinger_game_object__active_get(self)
}

func (self *TuringerGameObject)activeInHierarchyGet() bool {
    
    return _core_turinger_game_object__active_in_hierarchy_get(self)
}

func (self *TuringerGameObject)activeSelfGet() bool {
    
    return _core_turinger_game_object__active_self_get(self)
}

func (self *TuringerGameObject)activeSet(value bool) void {
    
    _core_turinger_game_object__active_set(self, value)
}

func (self *TuringerGameObject)addComponent(componentType Type) Component {
    
    return _core_turinger_game_object__add_component(self, componentType)
}

func (self *TuringerGameObject)broadcastMessage(methodName string, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_turinger_game_object__broadcast_message(self, turingHandleMethodName, options)
}

func (self *TuringerGameObject)compareTag(tag string) bool {
    
    turingHTag := []byte(tag)
    turingHTag = append(turingHTag, 0)
    turingHandleTag := &turingHTag[0]
    return _core_turinger_game_object__compare_tag(self, turingHandleTag)
}

func (self *TuringerGameObject)gameObjectGet() GameObject {
    
    return _core_turinger_game_object__game_object_get(self)
}

func (self *TuringerGameObject)getComponentAtIndex(index int32) Component {
    
    return _core_turinger_game_object__get_component_at_index(self, index)
}

func (self *TuringerGameObject)getComponentByName(csType string) Component {
    
    turingHCsType := []byte(csType)
    turingHCsType = append(turingHCsType, 0)
    turingHandleCsType := &turingHCsType[0]
    return _core_turinger_game_object__get_component_by_name(self, turingHandleCsType)
}

func (self *TuringerGameObject)getComponentByType(csType Type) Component {
    
    return _core_turinger_game_object__get_component_by_type(self, csType)
}

func (self *TuringerGameObject)getComponentCount() int32 {
    
    return _core_turinger_game_object__get_component_count(self)
}

func (self *TuringerGameObject)getComponentInChildrenByType(csType Type, includeInactive bool) Component {
    
    return _core_turinger_game_object__get_component_in_children_by_type(self, csType, includeInactive)
}

func (self *TuringerGameObject)getComponentInParentByType(csType Type, includeInactive bool) Component {
    
    return _core_turinger_game_object__get_component_in_parent_by_type(self, csType, includeInactive)
}

func (self *TuringerGameObject)getComponentIndex(component Component) int32 {
    
    return _core_turinger_game_object__get_component_index(self, component)
}

func (self *TuringerGameObject)getInstanceId() int32 {
    
    return _core_turinger_game_object__get_instance_id(self)
}

func (self *TuringerGameObject)hideFlagsGet() int32 {
    
    return _core_turinger_game_object__hide_flags_get(self)
}

func (self *TuringerGameObject)hideFlagsSet(value int32) void {
    
    _core_turinger_game_object__hide_flags_set(self, value)
}

func (self *TuringerGameObject)isStaticGet() bool {
    
    return _core_turinger_game_object__is_static_get(self)
}

func (self *TuringerGameObject)isStaticSet(value bool) void {
    
    _core_turinger_game_object__is_static_set(self, value)
}

func (self *TuringerGameObject)layerGet() int32 {
    
    return _core_turinger_game_object__layer_get(self)
}

func (self *TuringerGameObject)layerSet(value int32) void {
    
    _core_turinger_game_object__layer_set(self, value)
}

func (self *TuringerGameObject)nameGet() string {
    
    turingResult := _core_turinger_game_object__name_get(self)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func (self *TuringerGameObject)nameSet(value string) void {
    
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_turinger_game_object__name_set(self, turingHandleValue)
}

func (self *TuringerGameObject)sceneCullingMaskGet() uint64 {
    
    return _core_turinger_game_object__scene_culling_mask_get(self)
}

func (self *TuringerGameObject)sendMessage(methodName string, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_turinger_game_object__send_message(self, turingHandleMethodName, options)
}

func (self *TuringerGameObject)sendMessageUpwards(methodName string, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_turinger_game_object__send_message_upwards(self, turingHandleMethodName, options)
}

func (self *TuringerGameObject)setActive(value bool) void {
    
    _core_turinger_game_object__set_active(self, value)
}

func (self *TuringerGameObject)setActiveRecursively(state bool) void {
    
    _core_turinger_game_object__set_active_recursively(self, state)
}

func (self *TuringerGameObject)tagGet() string {
    
    turingResult := _core_turinger_game_object__tag_get(self)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func (self *TuringerGameObject)tagSet(value string) void {
    
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_turinger_game_object__tag_set(self, turingHandleValue)
}

func (self *TuringerGameObject)transformGet() TuringerTransform {
    
    return _core_turinger_game_object__transform_get(self)
}

type TuringerGameObjectManager struct {
    opaqu uint32
}


func TuringerGameObjectManager_createObject(name string) TuringerGameObject {
    
    turingHName := []byte(name)
    turingHName = append(turingHName, 0)
    turingHandleName := &turingHName[0]
    return _core_turinger_game_object_manager__create_object(turingHandleName)
}

func TuringerGameObjectManager_destroyObject(listener TuringerGameObject) void {
    
    _core_turinger_game_object_manager__destroy_object(listener)
}

func TuringerGameObjectManager_find(name string) TuringerGameObject {
    
    turingHName := []byte(name)
    turingHName = append(turingHName, 0)
    turingHandleName := &turingHName[0]
    return _core_turinger_game_object_manager__find(turingHandleName)
}


func (self *TuringerGameObjectManager)instanceGet() TuringerGameObjectManager {
    
    return _core_turinger_game_object_manager__instance_get(self)
}

type TuringerTransform struct {
    opaqu uint32
}



func (self *TuringerTransform)broadcastMessage(methodName string, parameter Object, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_turinger_transform__broadcast_message(self, turingHandleMethodName, parameter, options)
}

func (self *TuringerTransform)childCountGet() int32 {
    
    return _core_turinger_transform__child_count_get(self)
}

func (self *TuringerTransform)compareTag(tag string) bool {
    
    turingHTag := []byte(tag)
    turingHTag = append(turingHTag, 0)
    turingHandleTag := &turingHTag[0]
    return _core_turinger_transform__compare_tag(self, turingHandleTag)
}

func (self *TuringerTransform)detachChildren() void {
    
    _core_turinger_transform__detach_children(self)
}

func (self *TuringerTransform)eulerAnglesGet() Vec3 {
    
    _core_turinger_transform__euler_angles_get(self)
    return dequeue_vec3()
}

func (self *TuringerTransform)eulerAnglesSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_turinger_transform__euler_angles_set(self, turingHandleValue)
}

func (self *TuringerTransform)find(n string) TuringerTransform {
    
    turingHN := []byte(n)
    turingHN = append(turingHN, 0)
    turingHandleN := &turingHN[0]
    return _core_turinger_transform__find(self, turingHandleN)
}

func (self *TuringerTransform)findChild(n string) TuringerTransform {
    
    turingHN := []byte(n)
    turingHN = append(turingHN, 0)
    turingHandleN := &turingHN[0]
    return _core_turinger_transform__find_child(self, turingHandleN)
}

func (self *TuringerTransform)forwardGet() Vec3 {
    
    _core_turinger_transform__forward_get(self)
    return dequeue_vec3()
}

func (self *TuringerTransform)forwardSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_turinger_transform__forward_set(self, turingHandleValue)
}

func (self *TuringerTransform)gameObjectGet() TuringerGameObject {
    
    return _core_turinger_transform__game_object_get(self)
}

func (self *TuringerTransform)getChild(index int32) TuringerTransform {
    
    return _core_turinger_transform__get_child(self, index)
}

func (self *TuringerTransform)getChildCount() int32 {
    
    return _core_turinger_transform__get_child_count(self)
}

func (self *TuringerTransform)getComponentByName(csType string) Component {
    
    turingHCsType := []byte(csType)
    turingHCsType = append(turingHCsType, 0)
    turingHandleCsType := &turingHCsType[0]
    return _core_turinger_transform__get_component_by_name(self, turingHandleCsType)
}

func (self *TuringerTransform)getComponentByType(csType Type) Component {
    
    return _core_turinger_transform__get_component_by_type(self, csType)
}

func (self *TuringerTransform)getComponentInChildrenByType(t Type, includeInactive bool) Component {
    
    return _core_turinger_transform__get_component_in_children_by_type(self, t, includeInactive)
}

func (self *TuringerTransform)getComponentInParentByType(t Type, includeInactive bool) Component {
    
    return _core_turinger_transform__get_component_in_parent_by_type(self, t, includeInactive)
}

func (self *TuringerTransform)getComponentIndex() int32 {
    
    return _core_turinger_transform__get_component_index(self)
}

func (self *TuringerTransform)getEnumerator() IEnumerator {
    
    return _core_turinger_transform__get_enumerator(self)
}

func (self *TuringerTransform)getInstanceId() int32 {
    
    return _core_turinger_transform__get_instance_id(self)
}

func (self *TuringerTransform)getSiblingIndex() int32 {
    
    return _core_turinger_transform__get_sibling_index(self)
}

func (self *TuringerTransform)hasChangedGet() bool {
    
    return _core_turinger_transform__has_changed_get(self)
}

func (self *TuringerTransform)hasChangedSet(value bool) void {
    
    _core_turinger_transform__has_changed_set(self, value)
}

func (self *TuringerTransform)hideFlagsGet() int32 {
    
    return _core_turinger_transform__hide_flags_get(self)
}

func (self *TuringerTransform)hideFlagsSet(value int32) void {
    
    _core_turinger_transform__hide_flags_set(self, value)
}

func (self *TuringerTransform)hierarchyCapacityGet() int32 {
    
    return _core_turinger_transform__hierarchy_capacity_get(self)
}

func (self *TuringerTransform)hierarchyCapacitySet(value int32) void {
    
    _core_turinger_transform__hierarchy_capacity_set(self, value)
}

func (self *TuringerTransform)hierarchyCountGet() int32 {
    
    return _core_turinger_transform__hierarchy_count_get(self)
}

func (self *TuringerTransform)inverseTransformDirection(direction Vec3) Vec3 {
    
    turingHandleDirection := enqueue_vec3(direction)

    _core_turinger_transform__inverse_transform_direction(self, turingHandleDirection)
    return dequeue_vec3()
}

func (self *TuringerTransform)inverseTransformPoint(position Vec3) Vec3 {
    
    turingHandlePosition := enqueue_vec3(position)

    _core_turinger_transform__inverse_transform_point(self, turingHandlePosition)
    return dequeue_vec3()
}

func (self *TuringerTransform)inverseTransformVector(vector Vec3) Vec3 {
    
    turingHandleVector := enqueue_vec3(vector)

    _core_turinger_transform__inverse_transform_vector(self, turingHandleVector)
    return dequeue_vec3()
}

func (self *TuringerTransform)isChildOf(parent TuringerTransform) bool {
    
    return _core_turinger_transform__is_child_of(self, parent)
}

func (self *TuringerTransform)localEulerAnglesGet() Vec3 {
    
    _core_turinger_transform__local_euler_angles_get(self)
    return dequeue_vec3()
}

func (self *TuringerTransform)localEulerAnglesSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_turinger_transform__local_euler_angles_set(self, turingHandleValue)
}

func (self *TuringerTransform)localPositionGet() Vec3 {
    
    _core_turinger_transform__local_position_get(self)
    return dequeue_vec3()
}

func (self *TuringerTransform)localPositionSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_turinger_transform__local_position_set(self, turingHandleValue)
}

func (self *TuringerTransform)localRotationGet() Quat {
    
    _core_turinger_transform__local_rotation_get(self)
    return dequeue_quat()
}

func (self *TuringerTransform)localRotationSet(value Quat) void {
    
    turingHandleValue := enqueue_quat(value)

    _core_turinger_transform__local_rotation_set(self, turingHandleValue)
}

func (self *TuringerTransform)localScaleGet() Vec3 {
    
    _core_turinger_transform__local_scale_get(self)
    return dequeue_vec3()
}

func (self *TuringerTransform)localScaleSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_turinger_transform__local_scale_set(self, turingHandleValue)
}

func (self *TuringerTransform)localToWorldMatrixGet() Mat4 {
    
    _core_turinger_transform__local_to_world_matrix_get(self)
    return dequeue_mat4()
}

func (self *TuringerTransform)lookAt(target TuringerTransform, worldUp Vec3) void {
    
    turingHandleWorldUp := enqueue_vec3(worldUp)

    _core_turinger_transform__look_at(self, target, turingHandleWorldUp)
}

func (self *TuringerTransform)lossyScaleGet() Vec3 {
    
    _core_turinger_transform__lossy_scale_get(self)
    return dequeue_vec3()
}

func (self *TuringerTransform)nameGet() string {
    
    turingResult := _core_turinger_transform__name_get(self)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func (self *TuringerTransform)nameSet(value string) void {
    
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_turinger_transform__name_set(self, turingHandleValue)
}

func (self *TuringerTransform)parentGet() TuringerTransform {
    
    return _core_turinger_transform__parent_get(self)
}

func (self *TuringerTransform)parentSet(value TuringerTransform) void {
    
    _core_turinger_transform__parent_set(self, value)
}

func (self *TuringerTransform)positionGet() Vec3 {
    
    _core_turinger_transform__position_get(self)
    return dequeue_vec3()
}

func (self *TuringerTransform)positionSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_turinger_transform__position_set(self, turingHandleValue)
}

func (self *TuringerTransform)rightGet() Vec3 {
    
    _core_turinger_transform__right_get(self)
    return dequeue_vec3()
}

func (self *TuringerTransform)rightSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_turinger_transform__right_set(self, turingHandleValue)
}

func (self *TuringerTransform)rootGet() TuringerTransform {
    
    return _core_turinger_transform__root_get(self)
}

func (self *TuringerTransform)rotate(eulers Vec3) void {
    
    turingHandleEulers := enqueue_vec3(eulers)

    _core_turinger_transform__rotate(self, turingHandleEulers)
}

func (self *TuringerTransform)rotateAround(point Vec3, axis Vec3, angle float32) void {
    
    turingHandlePoint := enqueue_vec3(point)

    turingHandleAxis := enqueue_vec3(axis)

    _core_turinger_transform__rotate_around(self, turingHandlePoint, turingHandleAxis, angle)
}

func (self *TuringerTransform)rotateAroundLocal(axis Vec3, angle float32) void {
    
    turingHandleAxis := enqueue_vec3(axis)

    _core_turinger_transform__rotate_around_local(self, turingHandleAxis, angle)
}

func (self *TuringerTransform)rotateRelative(eulers Vec3, relativeTo int32) void {
    
    turingHandleEulers := enqueue_vec3(eulers)

    _core_turinger_transform__rotate_relative(self, turingHandleEulers, relativeTo)
}

func (self *TuringerTransform)rotationGet() Quat {
    
    _core_turinger_transform__rotation_get(self)
    return dequeue_quat()
}

func (self *TuringerTransform)rotationSet(value Quat) void {
    
    turingHandleValue := enqueue_quat(value)

    _core_turinger_transform__rotation_set(self, turingHandleValue)
}

func (self *TuringerTransform)sendMessage(methodName string, value Object, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_turinger_transform__send_message(self, turingHandleMethodName, value, options)
}

func (self *TuringerTransform)sendMessageUpwards(methodName string, value Object, options int32) void {
    
    turingHMethodName := []byte(methodName)
    turingHMethodName = append(turingHMethodName, 0)
    turingHandleMethodName := &turingHMethodName[0]
    _core_turinger_transform__send_message_upwards(self, turingHandleMethodName, value, options)
}

func (self *TuringerTransform)setAsFirstSibling() void {
    
    _core_turinger_transform__set_as_first_sibling(self)
}

func (self *TuringerTransform)setAsLastSibling() void {
    
    _core_turinger_transform__set_as_last_sibling(self)
}

func (self *TuringerTransform)setLocalPositionAndRotation(localPosition Vec3, localRotation Quat) void {
    
    turingHandleLocalPosition := enqueue_vec3(localPosition)

    turingHandleLocalRotation := enqueue_quat(localRotation)

    _core_turinger_transform__set_local_position_and_rotation(self, turingHandleLocalPosition, turingHandleLocalRotation)
}

func (self *TuringerTransform)setParent(parent TuringerTransform, worldPositionStays bool) void {
    
    _core_turinger_transform__set_parent(self, parent, worldPositionStays)
}

func (self *TuringerTransform)setPositionAndRotation(position Vec3, rotation Quat) void {
    
    turingHandlePosition := enqueue_vec3(position)

    turingHandleRotation := enqueue_quat(rotation)

    _core_turinger_transform__set_position_and_rotation(self, turingHandlePosition, turingHandleRotation)
}

func (self *TuringerTransform)setSiblingIndex(index int32) void {
    
    _core_turinger_transform__set_sibling_index(self, index)
}

func (self *TuringerTransform)tagGet() string {
    
    turingResult := _core_turinger_transform__tag_get(self)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], turingResult)
    return string(turingStr[:len(turingStr)-1])
}

func (self *TuringerTransform)tagSet(value string) void {
    
    turingHValue := []byte(value)
    turingHValue = append(turingHValue, 0)
    turingHandleValue := &turingHValue[0]
    _core_turinger_transform__tag_set(self, turingHandleValue)
}

func (self *TuringerTransform)transformDirection(direction Vec3) Vec3 {
    
    turingHandleDirection := enqueue_vec3(direction)

    _core_turinger_transform__transform_direction(self, turingHandleDirection)
    return dequeue_vec3()
}

func (self *TuringerTransform)transformGet() Transform {
    
    return _core_turinger_transform__transform_get(self)
}

func (self *TuringerTransform)transformPoint(position Vec3) Vec3 {
    
    turingHandlePosition := enqueue_vec3(position)

    _core_turinger_transform__transform_point(self, turingHandlePosition)
    return dequeue_vec3()
}

func (self *TuringerTransform)transformVector(vector Vec3) Vec3 {
    
    turingHandleVector := enqueue_vec3(vector)

    _core_turinger_transform__transform_vector(self, turingHandleVector)
    return dequeue_vec3()
}

func (self *TuringerTransform)translate(translation Vec3, relativeTo int32) void {
    
    turingHandleTranslation := enqueue_vec3(translation)

    _core_turinger_transform__translate(self, turingHandleTranslation, relativeTo)
}

func (self *TuringerTransform)translateRelative(translation Vec3, relativeTo TuringerTransform) void {
    
    turingHandleTranslation := enqueue_vec3(translation)

    _core_turinger_transform__translate_relative(self, turingHandleTranslation, relativeTo)
}

func (self *TuringerTransform)upGet() Vec3 {
    
    _core_turinger_transform__up_get(self)
    return dequeue_vec3()
}

func (self *TuringerTransform)upSet(value Vec3) void {
    
    turingHandleValue := enqueue_vec3(value)

    _core_turinger_transform__up_set(self, turingHandleValue)
}

func (self *TuringerTransform)worldToLocalMatrixGet() Mat4 {
    
    _core_turinger_transform__world_to_local_matrix_get(self)
    return dequeue_mat4()
}

type Type struct {
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


