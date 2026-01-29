
//// Wasm Bindings ////

#ifdef __cplusplus
extern "C" {
#endif

void _host_strcpy(const char* location, uint32_t size);
void _host_f32_enqueue(float f);
float _host_f32_dequeue();


void _log__warn(const char* msg);
void _log__info(const char* msg);
void _log__debug(const char* msg);
void _log__critical(const char* msg);
void _note_manager__add_obstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data);
void _note_manager__add_color_note(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data);
float _note_manager__time_to_beat(float time);
void _note_manager__add_bomb_note(float beat, int32_t line, int32_t layer, CustomData custom_data);
TuringerGameObject _turinger_game_object_manager__create_object(const char* name);
TuringerGameObject _turinger_game_object_manager__find(const char* name);
void _turinger_game_object_manager__destroy_object(TuringerGameObject listener);

TuringerGameObjectManager _turinger_game_object_manager__instance_get(uint64_t opaqu);

Component _get_components_in_parent_by_type(uint64_t opaqu, Type cs_type, bool include_inactive);

void _turinger_game_object__send_message(uint64_t opaqu, const char* method_name);

Component _turinger_game_object__get_component_in_parent_by_type(uint64_t opaqu, Type cs_type);

bool _turinger_game_object__is_static_get(uint64_t opaqu);

TuringerTransform _turinger_game_object__transform_get(uint64_t opaqu);

Component _turinger_game_object__get_component_in_children_by_type(uint64_t opaqu, Type cs_type);

void _turinger_game_object__get_components_by_type(uint64_t opaqu, Type cs_type, List1 results);

void _turinger_game_object__active_set(uint64_t opaqu, bool value);

void _turinger_game_object__broadcast_message(uint64_t opaqu, const char* method_name);

GameObject _turinger_game_object__game_object_get(uint64_t opaqu);

void _turinger_game_object__is_static_set(uint64_t opaqu, bool value);

Component _turinger_game_object__add_component(uint64_t opaqu, Type component_type);

void _turinger_game_object__hide_flags_set(uint64_t opaqu, int32_t value);

void _turinger_game_object__send_message_upwards(uint64_t opaqu, const char* method_name);

bool _turinger_game_object__compare_tag(uint64_t opaqu, const char* tag);

int32_t _turinger_game_object__hide_flags_get(uint64_t opaqu);

void _turinger_game_object__tag_set(uint64_t opaqu, const char* value);

int32_t _turinger_game_object__get_instance_id(uint64_t opaqu);

int32_t _turinger_game_object__layer_get(uint64_t opaqu);

Component _get_components_in_children_by_type(uint64_t opaqu, Type cs_type, bool include_inactive);

void _turinger_game_object__layer_set(uint64_t opaqu, int32_t value);

void _turinger_game_object__set_active_recursively(uint64_t opaqu, bool state);

int32_t _turinger_game_object__get_component_index(uint64_t opaqu, Component component);

int32_t _turinger_game_object__get_component_count(uint64_t opaqu);

Component _turinger_game_object__get_component_at_index(uint64_t opaqu, int32_t index);

uint32_t _turinger_game_object__tag_get(uint64_t opaqu);

bool _turinger_game_object__active_self_get(uint64_t opaqu);

uint32_t _turinger_game_object__name_get(uint64_t opaqu);

Component _turinger_game_object__get_component_by_type(uint64_t opaqu, Type cs_type);

bool _turinger_game_object__active_in_hierarchy_get(uint64_t opaqu);

void _turinger_game_object__set_active(uint64_t opaqu, bool value);

bool _turinger_game_object__active_get(uint64_t opaqu);

Component _turinger_game_object__get_component_by_name(uint64_t opaqu, const char* cs_type);

void _turinger_game_object__name_set(uint64_t opaqu, const char* value);

uint64_t _turinger_game_object__scene_culling_mask_get(uint64_t opaqu);

Component _turinger_transform__get_component_by_type(uint64_t opaqu, Type cs_type);

void _turinger_transform__look_at(uint64_t opaqu, uint32_t world_position);

int32_t _turinger_transform__get_instance_id(uint64_t opaqu);

uint32_t _turinger_transform__tag_get(uint64_t opaqu);

uint32_t _turinger_transform__local_euler_angles_get(uint64_t opaqu);

uint32_t _turinger_transform__rotation_get(uint64_t opaqu);

uint32_t _turinger_transform__world_to_local_matrix_get(uint64_t opaqu);

int32_t _turinger_transform__hierarchy_count_get(uint64_t opaqu);

Component _get_components_in_children_by_type(uint64_t opaqu, Type t, bool include_inactive);

void _turinger_transform__name_set(uint64_t opaqu, const char* value);

uint32_t _turinger_transform__local_rotation_get(uint64_t opaqu);

void _turinger_transform__detach_children(uint64_t opaqu);

uint32_t _turinger_transform__inverse_transform_point(uint64_t opaqu, float x, float y, float z);

Component _turinger_transform__get_component_in_children_by_type(uint64_t opaqu, Type t, bool include_inactive);

Transform _turinger_transform__transform_get(uint64_t opaqu);

uint32_t _turinger_transform__lossy_scale_get(uint64_t opaqu);

TuringerTransform _turinger_transform__root_get(uint64_t opaqu);

void _turinger_transform__get_components_by_type(uint64_t opaqu, Type cs_type, List1 results);

IEnumerator _turinger_transform__get_enumerator(uint64_t opaqu);

void _turinger_transform__local_scale_set(uint64_t opaqu, uint32_t value);

int32_t _turinger_transform__child_count_get(uint64_t opaqu);

void _turinger_transform__parent_set(uint64_t opaqu, TuringerTransform value);

TuringerTransform _turinger_transform__get_child(uint64_t opaqu, int32_t index);

uint32_t _turinger_transform__transform_direction(uint64_t opaqu, float x, float y, float z);

void _turinger_transform__has_changed_set(uint64_t opaqu, bool value);

void _turinger_transform__send_message_upwards(uint64_t opaqu, const char* method_name, Object value, int32_t options);

TuringerTransform _turinger_transform__find_child(uint64_t opaqu, const char* n);

Component _get_components_in_parent_by_type(uint64_t opaqu, Type t, bool include_inactive);

void _turinger_transform__rotate(uint64_t opaqu, uint32_t axis, float angle);

bool _turinger_transform__has_changed_get(uint64_t opaqu);

uint32_t _turinger_transform__local_position_get(uint64_t opaqu);

void _turinger_transform__translate_relative(uint64_t opaqu, uint32_t translation, TuringerTransform relative_to);

void _turinger_transform__local_euler_angles_set(uint64_t opaqu, uint32_t value);

void _turinger_transform__set_local_position_and_rotation(uint64_t opaqu, uint32_t local_position, uint32_t local_rotation);

uint32_t _turinger_transform__forward_get(uint64_t opaqu);

int32_t _turinger_transform__get_sibling_index(uint64_t opaqu);

Component _turinger_transform__get_component_in_parent_by_type(uint64_t opaqu, Type t, bool include_inactive);

uint32_t _turinger_transform__up_get(uint64_t opaqu);

int32_t _turinger_transform__get_component_index(uint64_t opaqu);

void _turinger_transform__rotate_around_local(uint64_t opaqu, uint32_t axis, float angle);

void _turinger_transform__translate(uint64_t opaqu, uint32_t translation);

void _turinger_transform__broadcast_message(uint64_t opaqu, const char* method_name, Object parameter, int32_t options);

void _turinger_transform__euler_angles_set(uint64_t opaqu, uint32_t value);

void _turinger_transform__send_message(uint64_t opaqu, const char* method_name, Object value, int32_t options);

TuringerTransform _turinger_transform__parent_get(uint64_t opaqu);

uint32_t _turinger_transform__local_to_world_matrix_get(uint64_t opaqu);

Component _turinger_transform__get_component_by_name(uint64_t opaqu, const char* cs_type);

void _turinger_transform__set_parent(uint64_t opaqu, TuringerTransform parent, bool world_position_stays);

void _turinger_transform__rotate_around(uint64_t opaqu, uint32_t axis, float angle);

void _turinger_transform__hierarchy_capacity_set(uint64_t opaqu, int32_t value);

void _turinger_transform__up_set(uint64_t opaqu, uint32_t value);

uint32_t _turinger_transform__inverse_transform_direction(uint64_t opaqu, float x, float y, float z);

uint32_t _turinger_transform__local_scale_get(uint64_t opaqu);

uint32_t _turinger_transform__transform_vector(uint64_t opaqu, float x, float y, float z);

uint32_t _turinger_transform__transform_point(uint64_t opaqu, float x, float y, float z);

uint32_t _turinger_transform__euler_angles_get(uint64_t opaqu);

bool _turinger_transform__is_child_of(uint64_t opaqu, TuringerTransform parent);

void _turinger_transform__right_set(uint64_t opaqu, uint32_t value);

int32_t _turinger_transform__get_child_count(uint64_t opaqu);

int32_t _turinger_transform__hide_flags_get(uint64_t opaqu);

void _turinger_transform__rotate_relative(uint64_t opaqu, uint32_t axis, float angle, int32_t relative_to);

void _turinger_transform__rotation_set(uint64_t opaqu, uint32_t value);

TuringerGameObject _turinger_transform__game_object_get(uint64_t opaqu);

int32_t _turinger_transform__hierarchy_capacity_get(uint64_t opaqu);

void _turinger_transform__set_as_first_sibling(uint64_t opaqu);

uint32_t _turinger_transform__right_get(uint64_t opaqu);

void _turinger_transform__local_position_set(uint64_t opaqu, uint32_t value);

void _turinger_transform__forward_set(uint64_t opaqu, uint32_t value);

uint32_t _turinger_transform__name_get(uint64_t opaqu);

bool _turinger_transform__compare_tag(uint64_t opaqu, const char* tag);

void _turinger_transform__set_as_last_sibling(uint64_t opaqu);

uint32_t _turinger_transform__position_get(uint64_t opaqu);

void _turinger_transform__set_sibling_index(uint64_t opaqu, int32_t index);

void _turinger_transform__position_set(uint64_t opaqu, uint32_t value);

void _turinger_transform__hide_flags_set(uint64_t opaqu, int32_t value);

void _turinger_transform__set_position_and_rotation(uint64_t opaqu, uint32_t position, uint32_t rotation);

TuringerTransform _turinger_transform__find(uint64_t opaqu, const char* n);

void _turinger_transform__tag_set(uint64_t opaqu, const char* value);

void _turinger_transform__local_rotation_set(uint64_t opaqu, uint32_t value);

uint32_t _turinger_transform__inverse_transform_vector(uint64_t opaqu, float x, float y, float z);
GCHelper _gc_helper__create();

void _gc_helper__wasm_garbage_collect(uint64_t opaqu);

void _gc_helper__dispose(uint64_t opaqu);

void _gc_helper__invalidate_all_handles(uint64_t opaqu);
int32_t _xr__get_device_tracking_state(int32_t node_int);
uint32_t _xr__get_device_name(int32_t node_int);
bool _xr__get_device_secondary_button_state(int32_t node_int);
bool _xr__get_device_primary_button_state(int32_t node_int);
void _xr__send_haptic_impulse(int32_t node_int, float amplitude, float duration);
bool _xr__is_device_valid(int32_t node_int);
float _xr__get_device_battery_level(int32_t node_int);
uint32_t _xr__get_device_touchpad(int32_t node_int);
float _xr__get_device_grip_value(int32_t node_int);
float _xr__get_device_trigger_value(int32_t node_int);
void _xr__stop_haptics(int32_t node_int);
uint32_t _xr__get_device_thumbstick(int32_t node_int);

TuringScriptManager _xr___manager_get(uint64_t opaqu);
CustomData _custom_data__create();
List _list_create();
void _custom_data__set_string(CustomData custom_data, const char* key, const char* value);
void _custom_data__set_custom_data(CustomData custom_data, const char* key, CustomData value);
void _custom_data__list_add_string(List1 list, const char* value);
void _custom_data__set_custom_data_list(CustomData custom_data, const char* key, List1 value);
void _custom_data__set_float(CustomData custom_data, const char* key, float value);
void _custom_data__list_add_int(List1 list, int32_t value);
void _custom_data__list_add_bool(List1 list, bool value);
void _custom_data__set_int(CustomData custom_data, const char* key, int32_t value);
void _custom_data__set_bool(CustomData custom_data, const char* key, bool value);
void _custom_data__list_add_custom_data_list(List1 list, List1 value);
void _custom_data__list_add_float(List1 list, float value);
void _custom_data__list_add_custom_data(List1 list, CustomData value);


#ifdef __cplusplus
}
#endif
