#pragma once

///// Generated Shared C/C++ Wasm API Header /////


// // Raw Wasm Bindings // //

// Note on using this file directly:
// Some types cannot properly be passed across FFI
// such as strings and structs.
// Due to this, there are mechanisms in place to
// transfer those data types, such as `_host_strcpy`,
// `_host_f32_enqueue`, etc...
// The places where these mechanisms are meant to be used
// may be poorly documented within this file


#ifdef __cplusplus
extern "C" {
#endif

//// Core functions ////

/// When a string is to be passed from the host to wasm,
/// it instead returns it's length, including the NUL terminator.
/// The wasm is responsible for allocating that space and then
/// calling this function, passing the pointer to the allocated
/// space, and the size received.
void _host_strcpy(const char* location, uint32_t size);

/// This function allows types such as Vec3 and Mat4 to be passed back and forth
void _host_f32_enqueue(float f);

/// Inverted behavior to `_host_f32_enqueue`
float _host_f32_dequeue();

/// Same as `_host_f32_enqueue` but bit-casts u32 into it instead
void _host_u32_enqueue(uint32_t u);

/// Same as `_host_f32_dequeue` but bit-casts to u32 before returning
uint32_t _host_u32_dequeue();

//// Functions ////


//// Classes ////

uint64_t _core_custom_data__create()
void _core_custom_data__list_add_bool(uint64_t list, bool value)
void _core_custom_data__list_add_custom_data(uint64_t list, uint64_t value)
void _core_custom_data__list_add_custom_data_list(uint64_t list, uint64_t value)
void _core_custom_data__list_add_float(uint64_t list, float value)
void _core_custom_data__list_add_int(uint64_t list, int32_t value)
void _core_custom_data__list_add_string(uint64_t list, const char* value)
void _core_custom_data__set_bool(uint64_t custom_data, const char* key, bool value)
void _core_custom_data__set_custom_data(uint64_t custom_data, const char* key, uint64_t value)
void _core_custom_data__set_custom_data_list(uint64_t custom_data, const char* key, uint64_t value)
void _core_custom_data__set_float(uint64_t custom_data, const char* key, float value)
void _core_custom_data__set_int(uint64_t custom_data, const char* key, int32_t value)
void _core_custom_data__set_string(uint64_t custom_data, const char* key, const char* value)
uint64_t _core_gc_helper__create()
void _core_gc_helper__dispose()
void _core_gc_helper__invalidate_all_handles()
void _core_gc_helper__wasm_garbage_collect()
void _core_log__critical(const char* msg)
void _core_log__debug(const char* msg)
void _core_log__info(const char* msg)
void _core_log__warn(const char* msg)
void _core_note_manager__add_bomb_note(float beat, int32_t line, int32_t layer, uint64_t custom_data)
void _core_note_manager__add_color_note(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, uint64_t custom_data)
void _core_note_manager__add_obstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, uint64_t custom_data)
float _core_note_manager__time_to_beat(float time)
void _core_task_scheduler__schedule(uint64_t task)
void _core_task_scheduler__dispose()
bool _core_turinger_game_object__active_get()
bool _core_turinger_game_object__active_in_hierarchy_get()
bool _core_turinger_game_object__active_self_get()
void _core_turinger_game_object__active_set(bool value)
uint64_t _core_turinger_game_object__add_component(uint64_t component_type)
void _core_turinger_game_object__broadcast_message(const char* method_name, int32_t options)
bool _core_turinger_game_object__compare_tag(const char* tag)
uint64_t _core_turinger_game_object__game_object_get()
uint64_t _core_turinger_game_object__get_component_at_index(int32_t index)
uint64_t _core_turinger_game_object__get_component_by_name(const char* cs_type)
uint64_t _core_turinger_game_object__get_component_by_type(uint64_t cs_type)
int32_t _core_turinger_game_object__get_component_count()
uint64_t _core_turinger_game_object__get_component_in_children_by_type(uint64_t cs_type, bool include_inactive)
uint64_t _core_turinger_game_object__get_component_in_parent_by_type(uint64_t cs_type, bool include_inactive)
int32_t _core_turinger_game_object__get_component_index(uint64_t component)
int32_t _core_turinger_game_object__get_instance_id()
int32_t _core_turinger_game_object__hide_flags_get()
void _core_turinger_game_object__hide_flags_set(int32_t value)
bool _core_turinger_game_object__is_static_get()
void _core_turinger_game_object__is_static_set(bool value)
int32_t _core_turinger_game_object__layer_get()
void _core_turinger_game_object__layer_set(int32_t value)
uint32_t _core_turinger_game_object__name_get()
void _core_turinger_game_object__name_set(const char* value)
uint64_t _core_turinger_game_object__scene_culling_mask_get()
void _core_turinger_game_object__send_message(const char* method_name, int32_t options)
void _core_turinger_game_object__send_message_upwards(const char* method_name, int32_t options)
void _core_turinger_game_object__set_active(bool value)
void _core_turinger_game_object__set_active_recursively(bool state)
uint32_t _core_turinger_game_object__tag_get()
void _core_turinger_game_object__tag_set(const char* value)
uint64_t _core_turinger_game_object__transform_get()
uint64_t _core_turinger_game_object_manager__create_object(const char* name)
void _core_turinger_game_object_manager__destroy_object(uint64_t listener)
uint64_t _core_turinger_game_object_manager__find(const char* name)
uint64_t _core_turinger_game_object_manager__instance_get()
void _core_turinger_transform__broadcast_message(const char* method_name, uint64_t parameter, int32_t options)
int32_t _core_turinger_transform__child_count_get()
bool _core_turinger_transform__compare_tag(const char* tag)
void _core_turinger_transform__detach_children()
uint32_t _core_turinger_transform__euler_angles_get()
void _core_turinger_transform__euler_angles_set(uint32_t value)
uint64_t _core_turinger_transform__find(const char* n)
uint64_t _core_turinger_transform__find_child(const char* n)
uint32_t _core_turinger_transform__forward_get()
void _core_turinger_transform__forward_set(uint32_t value)
uint64_t _core_turinger_transform__game_object_get()
uint64_t _core_turinger_transform__get_child(int32_t index)
int32_t _core_turinger_transform__get_child_count()
uint64_t _core_turinger_transform__get_component_by_name(const char* cs_type)
uint64_t _core_turinger_transform__get_component_by_type(uint64_t cs_type)
uint64_t _core_turinger_transform__get_component_in_children_by_type(uint64_t t, bool include_inactive)
uint64_t _core_turinger_transform__get_component_in_parent_by_type(uint64_t t, bool include_inactive)
int32_t _core_turinger_transform__get_component_index()
uint64_t _core_turinger_transform__get_enumerator()
int32_t _core_turinger_transform__get_instance_id()
int32_t _core_turinger_transform__get_sibling_index()
bool _core_turinger_transform__has_changed_get()
void _core_turinger_transform__has_changed_set(bool value)
int32_t _core_turinger_transform__hide_flags_get()
void _core_turinger_transform__hide_flags_set(int32_t value)
int32_t _core_turinger_transform__hierarchy_capacity_get()
void _core_turinger_transform__hierarchy_capacity_set(int32_t value)
int32_t _core_turinger_transform__hierarchy_count_get()
uint32_t _core_turinger_transform__inverse_transform_direction(uint32_t direction)
uint32_t _core_turinger_transform__inverse_transform_point(uint32_t position)
uint32_t _core_turinger_transform__inverse_transform_vector(uint32_t vector)
bool _core_turinger_transform__is_child_of(uint64_t parent)
uint32_t _core_turinger_transform__local_euler_angles_get()
void _core_turinger_transform__local_euler_angles_set(uint32_t value)
uint32_t _core_turinger_transform__local_position_get()
void _core_turinger_transform__local_position_set(uint32_t value)
uint32_t _core_turinger_transform__local_rotation_get()
void _core_turinger_transform__local_rotation_set(uint32_t value)
uint32_t _core_turinger_transform__local_scale_get()
void _core_turinger_transform__local_scale_set(uint32_t value)
uint32_t _core_turinger_transform__local_to_world_matrix_get()
void _core_turinger_transform__look_at(uint64_t target, uint32_t world_up)
uint32_t _core_turinger_transform__lossy_scale_get()
uint32_t _core_turinger_transform__name_get()
void _core_turinger_transform__name_set(const char* value)
uint64_t _core_turinger_transform__parent_get()
void _core_turinger_transform__parent_set(uint64_t value)
uint32_t _core_turinger_transform__position_get()
void _core_turinger_transform__position_set(uint32_t value)
uint32_t _core_turinger_transform__right_get()
void _core_turinger_transform__right_set(uint32_t value)
uint64_t _core_turinger_transform__root_get()
void _core_turinger_transform__rotate(uint32_t eulers)
void _core_turinger_transform__rotate_around(uint32_t point, uint32_t axis, float angle)
void _core_turinger_transform__rotate_around_local(uint32_t axis, float angle)
void _core_turinger_transform__rotate_relative(uint32_t eulers, int32_t relative_to)
uint32_t _core_turinger_transform__rotation_get()
void _core_turinger_transform__rotation_set(uint32_t value)
void _core_turinger_transform__send_message(const char* method_name, uint64_t value, int32_t options)
void _core_turinger_transform__send_message_upwards(const char* method_name, uint64_t value, int32_t options)
void _core_turinger_transform__set_as_first_sibling()
void _core_turinger_transform__set_as_last_sibling()
void _core_turinger_transform__set_local_position_and_rotation(uint32_t local_position, uint32_t local_rotation)
void _core_turinger_transform__set_parent(uint64_t parent, bool world_position_stays)
void _core_turinger_transform__set_position_and_rotation(uint32_t position, uint32_t rotation)
void _core_turinger_transform__set_sibling_index(int32_t index)
uint32_t _core_turinger_transform__tag_get()
void _core_turinger_transform__tag_set(const char* value)
uint32_t _core_turinger_transform__transform_direction(uint32_t direction)
uint64_t _core_turinger_transform__transform_get()
uint32_t _core_turinger_transform__transform_point(uint32_t position)
uint32_t _core_turinger_transform__transform_vector(uint32_t vector)
void _core_turinger_transform__translate(uint32_t translation, int32_t relative_to)
void _core_turinger_transform__translate_relative(uint32_t translation, uint64_t relative_to)
uint32_t _core_turinger_transform__up_get()
void _core_turinger_transform__up_set(uint32_t value)
uint32_t _core_turinger_transform__world_to_local_matrix_get()
float _core_xr__get_device_battery_level(int32_t node_int)
float _core_xr__get_device_grip_value(int32_t node_int)
uint32_t _core_xr__get_device_name(int32_t node_int)
bool _core_xr__get_device_primary_button_state(int32_t node_int)
bool _core_xr__get_device_secondary_button_state(int32_t node_int)
uint32_t _core_xr__get_device_thumbstick(int32_t node_int)
uint32_t _core_xr__get_device_touchpad(int32_t node_int)
int32_t _core_xr__get_device_tracking_state(int32_t node_int)
float _core_xr__get_device_trigger_value(int32_t node_int)
bool _core_xr__is_device_valid(int32_t node_int)
void _core_xr__send_haptic_impulse(int32_t node_int, float amplitude, float duration)
void _core_xr__stop_haptics(int32_t node_int)
uint64_t _core_xr___manager_get()


#ifdef __cplusplus
}
#endif

