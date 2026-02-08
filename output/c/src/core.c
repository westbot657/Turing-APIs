
#include "core.h"


WASM_EXPORT("_core_semver") uint64_t _core_semver() {
    return (((uint64_t) 0) << 32) | (((uint64_t) 1) << 16) | 0;
}


uint32_t __enqueue_vec2(vec2s v) {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    return 2;
}
vec2s __dequeue_vec2() {
    float x = _host_f32_dequeue();
    float y = _host_f32_dequeue();
    return (vec2s){ .x=x, .y=y };
}

uint32_t __enqueue_vec3(vec3s v) {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    return 3;
}
vec3s __dequeue_vec3() {
    float x = _host_f32_dequeue();
    float y = _host_f32_dequeue();
    float z = _host_f32_dequeue();
    return (vec3s){ .x=x, .y=y, .z=z };
}

uint32_t __enqueue_vec4(vec4s v) {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    _host_f32_enqueue(v.w);
    return 4;
}
vec4s __dequeue_vec4() {
    float x = _host_f32_dequeue();
    float y = _host_f32_dequeue();
    float z = _host_f32_dequeue();
    float w = _host_f32_dequeue();
    return (vec4s){ .x=x, .y=y, .z=z, .w=w };
}

uint32_t __enqueue_quat(versors v) {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    _host_f32_enqueue(v.w);
    return 4;
}
versors __dequeue_quat() {
    float x = _host_f32_dequeue();
    float y = _host_f32_dequeue();
    float z = _host_f32_dequeue();
    float w = _host_f32_dequeue();
    return (versors){ .x=x, .y=y, .z=z, .w=w };
}

uint32_t __enqueue_mat4(mat4s v) {
    __enqueue_vec4(v.col[0]);
    __enqueue_vec4(v.col[1]);
    __enqueue_vec4(v.col[2]);
    __enqueue_vec4(v.col[3]);
    return 16;
}
mat4s __dequeue_mat4() {
    vec4s x = __dequeue_vec4();
    vec4s y = __dequeue_vec4();
    vec4s z = __dequeue_vec4();
    vec4s w = __dequeue_vec4();
    return (mat4s){ .col={x, y, z, w} };
}

// // Functions // //



// // Classes // //


GcHelper Core_GcHelper_create() {
    
    return _core_gc_helper__create();
}


void Core_GcHelper_wasmGarbageCollect(GcHelper self) {
    
    _core_gc_helper__wasm_garbage_collect(self);
}

void Core_GcHelper_dispose(GcHelper self) {
    
    _core_gc_helper__dispose(self);
}

void Core_GcHelper_invalidateAllHandles(GcHelper self) {
    
    _core_gc_helper__invalidate_all_handles(self);
}



Component Core_TuringerTransform_getComponentByType(TuringerTransform self
, Type cs_type) {
    
    return _core_turinger_transform__get_component_by_type(self, cs_type);
}

void Core_TuringerTransform_lookAt(TuringerTransform self
, TuringerTransform target
, vec3s world_up) {
    uint32_t turing_handle_world_up = __enqueue_vec3(world_up);
    _core_turinger_transform__look_at(self, target, turing_handle_world_up);
}

int32_t Core_TuringerTransform_getInstanceId(TuringerTransform self) {
    
    return _core_turinger_transform__get_instance_id(self);
}

char* Core_TuringerTransform_tagGet(TuringerTransform self) {
    
    uint32_t turing_result = _core_turinger_transform__tag_get(self);
    char* turing_str = malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

vec3s Core_TuringerTransform_localEulerAnglesGet(TuringerTransform self) {
    
    _core_turinger_transform__local_euler_angles_get(self);
    return __dequeue_vec3();
}

versors Core_TuringerTransform_rotationGet(TuringerTransform self) {
    
    _core_turinger_transform__rotation_get(self);
    return __dequeue_quat();
}

mat4s Core_TuringerTransform_worldToLocalMatrixGet(TuringerTransform self) {
    
    _core_turinger_transform__world_to_local_matrix_get(self);
    return __dequeue_mat4();
}

int32_t Core_TuringerTransform_hierarchyCountGet(TuringerTransform self) {
    
    return _core_turinger_transform__hierarchy_count_get(self);
}

void Core_TuringerTransform_nameSet(TuringerTransform self
, const char* value) {
    
    _core_turinger_transform__name_set(self, value);
}

versors Core_TuringerTransform_localRotationGet(TuringerTransform self) {
    
    _core_turinger_transform__local_rotation_get(self);
    return __dequeue_quat();
}

void Core_TuringerTransform_detachChildren(TuringerTransform self) {
    
    _core_turinger_transform__detach_children(self);
}

vec3s Core_TuringerTransform_inverseTransformPoint(TuringerTransform self
, vec3s position) {
    uint32_t turing_handle_position = __enqueue_vec3(position);
    _core_turinger_transform__inverse_transform_point(self, turing_handle_position);
    return __dequeue_vec3();
}

Component Core_TuringerTransform_getComponentInChildrenByType(TuringerTransform self
, Type t
, bool include_inactive) {
    
    return _core_turinger_transform__get_component_in_children_by_type(self, t, include_inactive);
}

Transform Core_TuringerTransform_transformGet(TuringerTransform self) {
    
    return _core_turinger_transform__transform_get(self);
}

vec3s Core_TuringerTransform_lossyScaleGet(TuringerTransform self) {
    
    _core_turinger_transform__lossy_scale_get(self);
    return __dequeue_vec3();
}

TuringerTransform Core_TuringerTransform_rootGet(TuringerTransform self) {
    
    return _core_turinger_transform__root_get(self);
}

IEnumerator Core_TuringerTransform_getEnumerator(TuringerTransform self) {
    
    return _core_turinger_transform__get_enumerator(self);
}

void Core_TuringerTransform_localScaleSet(TuringerTransform self
, vec3s value) {
    uint32_t turing_handle_value = __enqueue_vec3(value);
    _core_turinger_transform__local_scale_set(self, turing_handle_value);
}

int32_t Core_TuringerTransform_childCountGet(TuringerTransform self) {
    
    return _core_turinger_transform__child_count_get(self);
}

void Core_TuringerTransform_parentSet(TuringerTransform self
, TuringerTransform value) {
    
    _core_turinger_transform__parent_set(self, value);
}

TuringerTransform Core_TuringerTransform_getChild(TuringerTransform self
, int32_t index) {
    
    return _core_turinger_transform__get_child(self, index);
}

vec3s Core_TuringerTransform_transformDirection(TuringerTransform self
, vec3s direction) {
    uint32_t turing_handle_direction = __enqueue_vec3(direction);
    _core_turinger_transform__transform_direction(self, turing_handle_direction);
    return __dequeue_vec3();
}

void Core_TuringerTransform_hasChangedSet(TuringerTransform self
, bool value) {
    
    _core_turinger_transform__has_changed_set(self, value);
}

void Core_TuringerTransform_sendMessageUpwards(TuringerTransform self
, const char* method_name
, Object value
, int32_t options) {
    
    _core_turinger_transform__send_message_upwards(self, method_name, value, options);
}

TuringerTransform Core_TuringerTransform_findChild(TuringerTransform self
, const char* n) {
    
    return _core_turinger_transform__find_child(self, n);
}

void Core_TuringerTransform_rotate(TuringerTransform self
, vec3s eulers) {
    uint32_t turing_handle_eulers = __enqueue_vec3(eulers);
    _core_turinger_transform__rotate(self, turing_handle_eulers);
}

bool Core_TuringerTransform_hasChangedGet(TuringerTransform self) {
    
    return _core_turinger_transform__has_changed_get(self);
}

vec3s Core_TuringerTransform_localPositionGet(TuringerTransform self) {
    
    _core_turinger_transform__local_position_get(self);
    return __dequeue_vec3();
}

void Core_TuringerTransform_translateRelative(TuringerTransform self
, vec3s translation
, TuringerTransform relative_to) {
    uint32_t turing_handle_translation = __enqueue_vec3(translation);
    _core_turinger_transform__translate_relative(self, turing_handle_translation, relative_to);
}

void Core_TuringerTransform_localEulerAnglesSet(TuringerTransform self
, vec3s value) {
    uint32_t turing_handle_value = __enqueue_vec3(value);
    _core_turinger_transform__local_euler_angles_set(self, turing_handle_value);
}

void Core_TuringerTransform_setLocalPositionAndRotation(TuringerTransform self
, vec3s local_position
, versors local_rotation) {
    uint32_t turing_handle_local_position = __enqueue_vec3(local_position);uint32_t turing_handle_local_rotation = __enqueue_quat(local_rotation);
    _core_turinger_transform__set_local_position_and_rotation(self, turing_handle_local_position, turing_handle_local_rotation);
}

vec3s Core_TuringerTransform_forwardGet(TuringerTransform self) {
    
    _core_turinger_transform__forward_get(self);
    return __dequeue_vec3();
}

int32_t Core_TuringerTransform_getSiblingIndex(TuringerTransform self) {
    
    return _core_turinger_transform__get_sibling_index(self);
}

Component Core_TuringerTransform_getComponentInParentByType(TuringerTransform self
, Type t
, bool include_inactive) {
    
    return _core_turinger_transform__get_component_in_parent_by_type(self, t, include_inactive);
}

vec3s Core_TuringerTransform_upGet(TuringerTransform self) {
    
    _core_turinger_transform__up_get(self);
    return __dequeue_vec3();
}

int32_t Core_TuringerTransform_getComponentIndex(TuringerTransform self) {
    
    return _core_turinger_transform__get_component_index(self);
}

void Core_TuringerTransform_rotateAroundLocal(TuringerTransform self
, vec3s axis
, float angle) {
    uint32_t turing_handle_axis = __enqueue_vec3(axis);
    _core_turinger_transform__rotate_around_local(self, turing_handle_axis, angle);
}

void Core_TuringerTransform_translate(TuringerTransform self
, vec3s translation
, int32_t relative_to) {
    uint32_t turing_handle_translation = __enqueue_vec3(translation);
    _core_turinger_transform__translate(self, turing_handle_translation, relative_to);
}

void Core_TuringerTransform_broadcastMessage(TuringerTransform self
, const char* method_name
, Object parameter
, int32_t options) {
    
    _core_turinger_transform__broadcast_message(self, method_name, parameter, options);
}

void Core_TuringerTransform_eulerAnglesSet(TuringerTransform self
, vec3s value) {
    uint32_t turing_handle_value = __enqueue_vec3(value);
    _core_turinger_transform__euler_angles_set(self, turing_handle_value);
}

void Core_TuringerTransform_sendMessage(TuringerTransform self
, const char* method_name
, Object value
, int32_t options) {
    
    _core_turinger_transform__send_message(self, method_name, value, options);
}

TuringerTransform Core_TuringerTransform_parentGet(TuringerTransform self) {
    
    return _core_turinger_transform__parent_get(self);
}

mat4s Core_TuringerTransform_localToWorldMatrixGet(TuringerTransform self) {
    
    _core_turinger_transform__local_to_world_matrix_get(self);
    return __dequeue_mat4();
}

Component Core_TuringerTransform_getComponentByName(TuringerTransform self
, const char* cs_type) {
    
    return _core_turinger_transform__get_component_by_name(self, cs_type);
}

void Core_TuringerTransform_setParent(TuringerTransform self
, TuringerTransform parent
, bool world_position_stays) {
    
    _core_turinger_transform__set_parent(self, parent, world_position_stays);
}

void Core_TuringerTransform_rotateAround(TuringerTransform self
, vec3s point
, vec3s axis
, float angle) {
    uint32_t turing_handle_point = __enqueue_vec3(point);uint32_t turing_handle_axis = __enqueue_vec3(axis);
    _core_turinger_transform__rotate_around(self, turing_handle_point, turing_handle_axis, angle);
}

void Core_TuringerTransform_hierarchyCapacitySet(TuringerTransform self
, int32_t value) {
    
    _core_turinger_transform__hierarchy_capacity_set(self, value);
}

void Core_TuringerTransform_upSet(TuringerTransform self
, vec3s value) {
    uint32_t turing_handle_value = __enqueue_vec3(value);
    _core_turinger_transform__up_set(self, turing_handle_value);
}

vec3s Core_TuringerTransform_inverseTransformDirection(TuringerTransform self
, vec3s direction) {
    uint32_t turing_handle_direction = __enqueue_vec3(direction);
    _core_turinger_transform__inverse_transform_direction(self, turing_handle_direction);
    return __dequeue_vec3();
}

vec3s Core_TuringerTransform_localScaleGet(TuringerTransform self) {
    
    _core_turinger_transform__local_scale_get(self);
    return __dequeue_vec3();
}

vec3s Core_TuringerTransform_transformVector(TuringerTransform self
, vec3s vector) {
    uint32_t turing_handle_vector = __enqueue_vec3(vector);
    _core_turinger_transform__transform_vector(self, turing_handle_vector);
    return __dequeue_vec3();
}

vec3s Core_TuringerTransform_transformPoint(TuringerTransform self
, vec3s position) {
    uint32_t turing_handle_position = __enqueue_vec3(position);
    _core_turinger_transform__transform_point(self, turing_handle_position);
    return __dequeue_vec3();
}

vec3s Core_TuringerTransform_eulerAnglesGet(TuringerTransform self) {
    
    _core_turinger_transform__euler_angles_get(self);
    return __dequeue_vec3();
}

bool Core_TuringerTransform_isChildOf(TuringerTransform self
, TuringerTransform parent) {
    
    return _core_turinger_transform__is_child_of(self, parent);
}

void Core_TuringerTransform_rightSet(TuringerTransform self
, vec3s value) {
    uint32_t turing_handle_value = __enqueue_vec3(value);
    _core_turinger_transform__right_set(self, turing_handle_value);
}

int32_t Core_TuringerTransform_getChildCount(TuringerTransform self) {
    
    return _core_turinger_transform__get_child_count(self);
}

int32_t Core_TuringerTransform_hideFlagsGet(TuringerTransform self) {
    
    return _core_turinger_transform__hide_flags_get(self);
}

void Core_TuringerTransform_rotateRelative(TuringerTransform self
, vec3s eulers
, int32_t relative_to) {
    uint32_t turing_handle_eulers = __enqueue_vec3(eulers);
    _core_turinger_transform__rotate_relative(self, turing_handle_eulers, relative_to);
}

void Core_TuringerTransform_rotationSet(TuringerTransform self
, versors value) {
    uint32_t turing_handle_value = __enqueue_quat(value);
    _core_turinger_transform__rotation_set(self, turing_handle_value);
}

int32_t Core_TuringerTransform_hierarchyCapacityGet(TuringerTransform self) {
    
    return _core_turinger_transform__hierarchy_capacity_get(self);
}

void Core_TuringerTransform_setAsFirstSibling(TuringerTransform self) {
    
    _core_turinger_transform__set_as_first_sibling(self);
}

vec3s Core_TuringerTransform_rightGet(TuringerTransform self) {
    
    _core_turinger_transform__right_get(self);
    return __dequeue_vec3();
}

void Core_TuringerTransform_localPositionSet(TuringerTransform self
, vec3s value) {
    uint32_t turing_handle_value = __enqueue_vec3(value);
    _core_turinger_transform__local_position_set(self, turing_handle_value);
}

void Core_TuringerTransform_forwardSet(TuringerTransform self
, vec3s value) {
    uint32_t turing_handle_value = __enqueue_vec3(value);
    _core_turinger_transform__forward_set(self, turing_handle_value);
}

char* Core_TuringerTransform_nameGet(TuringerTransform self) {
    
    uint32_t turing_result = _core_turinger_transform__name_get(self);
    char* turing_str = malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

TuringerGameObject Core_TuringerTransform_gameObjectGet(TuringerTransform self) {
    
    return _core_turinger_transform__game_object_get(self);
}

bool Core_TuringerTransform_compareTag(TuringerTransform self
, const char* tag) {
    
    return _core_turinger_transform__compare_tag(self, tag);
}

void Core_TuringerTransform_setAsLastSibling(TuringerTransform self) {
    
    _core_turinger_transform__set_as_last_sibling(self);
}

vec3s Core_TuringerTransform_positionGet(TuringerTransform self) {
    
    _core_turinger_transform__position_get(self);
    return __dequeue_vec3();
}

void Core_TuringerTransform_setSiblingIndex(TuringerTransform self
, int32_t index) {
    
    _core_turinger_transform__set_sibling_index(self, index);
}

void Core_TuringerTransform_positionSet(TuringerTransform self
, vec3s value) {
    uint32_t turing_handle_value = __enqueue_vec3(value);
    _core_turinger_transform__position_set(self, turing_handle_value);
}

void Core_TuringerTransform_hideFlagsSet(TuringerTransform self
, int32_t value) {
    
    _core_turinger_transform__hide_flags_set(self, value);
}

void Core_TuringerTransform_setPositionAndRotation(TuringerTransform self
, vec3s position
, versors rotation) {
    uint32_t turing_handle_position = __enqueue_vec3(position);uint32_t turing_handle_rotation = __enqueue_quat(rotation);
    _core_turinger_transform__set_position_and_rotation(self, turing_handle_position, turing_handle_rotation);
}

TuringerTransform Core_TuringerTransform_find(TuringerTransform self
, const char* n) {
    
    return _core_turinger_transform__find(self, n);
}

void Core_TuringerTransform_tagSet(TuringerTransform self
, const char* value) {
    
    _core_turinger_transform__tag_set(self, value);
}

void Core_TuringerTransform_localRotationSet(TuringerTransform self
, versors value) {
    uint32_t turing_handle_value = __enqueue_quat(value);
    _core_turinger_transform__local_rotation_set(self, turing_handle_value);
}

vec3s Core_TuringerTransform_inverseTransformVector(TuringerTransform self
, vec3s vector) {
    uint32_t turing_handle_vector = __enqueue_vec3(vector);
    _core_turinger_transform__inverse_transform_vector(self, turing_handle_vector);
    return __dequeue_vec3();
}


TuringerGameObject Core_TuringerGameObjectManager_createObject(const char* name) {
    
    return _core_turinger_game_object_manager__create_object(name);
}

TuringerGameObject Core_TuringerGameObjectManager_find(const char* name) {
    
    return _core_turinger_game_object_manager__find(name);
}

void Core_TuringerGameObjectManager_destroyObject(TuringerGameObject listener) {
    
    _core_turinger_game_object_manager__destroy_object(listener);
}


TuringerGameObjectManager Core_TuringerGameObjectManager_instanceGet(TuringerGameObjectManager self) {
    
    return _core_turinger_game_object_manager__instance_get(self);
}


void Core_NoteManager_addObstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data) {
    
    _core_note_manager__add_obstacle(beat, duration, line, layer, width, height, custom_data);
}

void Core_NoteManager_addColorNote(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data) {
    
    _core_note_manager__add_color_note(beat, line, layer, color, cut_direction, custom_data);
}

float Core_NoteManager_timeToBeat(float time) {
    
    return _core_note_manager__time_to_beat(time);
}

void Core_NoteManager_addBombNote(float beat, int32_t line, int32_t layer, CustomData custom_data) {
    
    _core_note_manager__add_bomb_note(beat, line, layer, custom_data);
}



int32_t Core_Xr_getDeviceTrackingState(int32_t node_int) {
    
    return _core_xr__get_device_tracking_state(node_int);
}

char* Core_Xr_getDeviceName(int32_t node_int) {
    
    uint32_t turing_result = _core_xr__get_device_name(node_int);
    char* turing_str = malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

bool Core_Xr_getDeviceSecondaryButtonState(int32_t node_int) {
    
    return _core_xr__get_device_secondary_button_state(node_int);
}

bool Core_Xr_getDevicePrimaryButtonState(int32_t node_int) {
    
    return _core_xr__get_device_primary_button_state(node_int);
}

void Core_Xr_sendHapticImpulse(int32_t node_int, float amplitude, float duration) {
    
    _core_xr__send_haptic_impulse(node_int, amplitude, duration);
}

bool Core_Xr_isDeviceValid(int32_t node_int) {
    
    return _core_xr__is_device_valid(node_int);
}

float Core_Xr_getDeviceBatteryLevel(int32_t node_int) {
    
    return _core_xr__get_device_battery_level(node_int);
}

vec2s Core_Xr_getDeviceTouchpad(int32_t node_int) {
    
    _core_xr__get_device_touchpad(node_int);
    return __dequeue_vec2();
}

float Core_Xr_getDeviceGripValue(int32_t node_int) {
    
    return _core_xr__get_device_grip_value(node_int);
}

float Core_Xr_getDeviceTriggerValue(int32_t node_int) {
    
    return _core_xr__get_device_trigger_value(node_int);
}

void Core_Xr_stopHaptics(int32_t node_int) {
    
    _core_xr__stop_haptics(node_int);
}

vec2s Core_Xr_getDeviceThumbstick(int32_t node_int) {
    
    _core_xr__get_device_thumbstick(node_int);
    return __dequeue_vec2();
}


TuringScriptManager Core_Xr_ManagerGet(Xr self) {
    
    return _core_xr___manager_get(self);
}


void Core_Log_warn(const char* msg) {
    
    _core_log__warn(msg);
}

void Core_Log_info(const char* msg) {
    
    _core_log__info(msg);
}

void Core_Log_debug(const char* msg) {
    
    _core_log__debug(msg);
}

void Core_Log_critical(const char* msg) {
    
    _core_log__critical(msg);
}



void Core_TaskScheduler_schedule(Action task) {
    
    _core_task_scheduler__schedule(task);
}


void Core_TaskScheduler_dispose(TaskScheduler self) {
    
    _core_task_scheduler__dispose(self);
}


CustomData Core_CustomData_create() {
    
    return _core_custom_data__create();
}

void Core_CustomData_setString(CustomData custom_data, const char* key, const char* value) {
    
    _core_custom_data__set_string(custom_data, key, value);
}

void Core_CustomData_setCustomData(CustomData custom_data, const char* key, CustomData value) {
    
    _core_custom_data__set_custom_data(custom_data, key, value);
}

void Core_CustomData_listAddString(List1 list, const char* value) {
    
    _core_custom_data__list_add_string(list, value);
}

void Core_CustomData_setCustomDataList(CustomData custom_data, const char* key, List1 value) {
    
    _core_custom_data__set_custom_data_list(custom_data, key, value);
}

void Core_CustomData_setFloat(CustomData custom_data, const char* key, float value) {
    
    _core_custom_data__set_float(custom_data, key, value);
}

void Core_CustomData_listAddInt(List1 list, int32_t value) {
    
    _core_custom_data__list_add_int(list, value);
}

void Core_CustomData_listAddBool(List1 list, bool value) {
    
    _core_custom_data__list_add_bool(list, value);
}

void Core_CustomData_setInt(CustomData custom_data, const char* key, int32_t value) {
    
    _core_custom_data__set_int(custom_data, key, value);
}

void Core_CustomData_setBool(CustomData custom_data, const char* key, bool value) {
    
    _core_custom_data__set_bool(custom_data, key, value);
}

void Core_CustomData_listAddCustomDataList(List1 list, List1 value) {
    
    _core_custom_data__list_add_custom_data_list(list, value);
}

void Core_CustomData_listAddFloat(List1 list, float value) {
    
    _core_custom_data__list_add_float(list, value);
}

void Core_CustomData_listAddCustomData(List1 list, CustomData value) {
    
    _core_custom_data__list_add_custom_data(list, value);
}




void Core_TuringerGameObject_sendMessage(TuringerGameObject self
, const char* method_name
, int32_t options) {
    
    _core_turinger_game_object__send_message(self, method_name, options);
}

Component Core_TuringerGameObject_getComponentInParentByType(TuringerGameObject self
, Type cs_type
, bool include_inactive) {
    
    return _core_turinger_game_object__get_component_in_parent_by_type(self, cs_type, include_inactive);
}

bool Core_TuringerGameObject_isStaticGet(TuringerGameObject self) {
    
    return _core_turinger_game_object__is_static_get(self);
}

TuringerTransform Core_TuringerGameObject_transformGet(TuringerGameObject self) {
    
    return _core_turinger_game_object__transform_get(self);
}

Component Core_TuringerGameObject_getComponentInChildrenByType(TuringerGameObject self
, Type cs_type
, bool include_inactive) {
    
    return _core_turinger_game_object__get_component_in_children_by_type(self, cs_type, include_inactive);
}

void Core_TuringerGameObject_activeSet(TuringerGameObject self
, bool value) {
    
    _core_turinger_game_object__active_set(self, value);
}

void Core_TuringerGameObject_broadcastMessage(TuringerGameObject self
, const char* method_name
, int32_t options) {
    
    _core_turinger_game_object__broadcast_message(self, method_name, options);
}

GameObject Core_TuringerGameObject_gameObjectGet(TuringerGameObject self) {
    
    return _core_turinger_game_object__game_object_get(self);
}

void Core_TuringerGameObject_isStaticSet(TuringerGameObject self
, bool value) {
    
    _core_turinger_game_object__is_static_set(self, value);
}

Component Core_TuringerGameObject_addComponent(TuringerGameObject self
, Type component_type) {
    
    return _core_turinger_game_object__add_component(self, component_type);
}

void Core_TuringerGameObject_hideFlagsSet(TuringerGameObject self
, int32_t value) {
    
    _core_turinger_game_object__hide_flags_set(self, value);
}

void Core_TuringerGameObject_sendMessageUpwards(TuringerGameObject self
, const char* method_name
, int32_t options) {
    
    _core_turinger_game_object__send_message_upwards(self, method_name, options);
}

bool Core_TuringerGameObject_compareTag(TuringerGameObject self
, const char* tag) {
    
    return _core_turinger_game_object__compare_tag(self, tag);
}

int32_t Core_TuringerGameObject_hideFlagsGet(TuringerGameObject self) {
    
    return _core_turinger_game_object__hide_flags_get(self);
}

void Core_TuringerGameObject_tagSet(TuringerGameObject self
, const char* value) {
    
    _core_turinger_game_object__tag_set(self, value);
}

int32_t Core_TuringerGameObject_getInstanceId(TuringerGameObject self) {
    
    return _core_turinger_game_object__get_instance_id(self);
}

int32_t Core_TuringerGameObject_layerGet(TuringerGameObject self) {
    
    return _core_turinger_game_object__layer_get(self);
}

void Core_TuringerGameObject_layerSet(TuringerGameObject self
, int32_t value) {
    
    _core_turinger_game_object__layer_set(self, value);
}

void Core_TuringerGameObject_setActiveRecursively(TuringerGameObject self
, bool state) {
    
    _core_turinger_game_object__set_active_recursively(self, state);
}

int32_t Core_TuringerGameObject_getComponentIndex(TuringerGameObject self
, Component component) {
    
    return _core_turinger_game_object__get_component_index(self, component);
}

int32_t Core_TuringerGameObject_getComponentCount(TuringerGameObject self) {
    
    return _core_turinger_game_object__get_component_count(self);
}

Component Core_TuringerGameObject_getComponentAtIndex(TuringerGameObject self
, int32_t index) {
    
    return _core_turinger_game_object__get_component_at_index(self, index);
}

char* Core_TuringerGameObject_tagGet(TuringerGameObject self) {
    
    uint32_t turing_result = _core_turinger_game_object__tag_get(self);
    char* turing_str = malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

bool Core_TuringerGameObject_activeSelfGet(TuringerGameObject self) {
    
    return _core_turinger_game_object__active_self_get(self);
}

char* Core_TuringerGameObject_nameGet(TuringerGameObject self) {
    
    uint32_t turing_result = _core_turinger_game_object__name_get(self);
    char* turing_str = malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

Component Core_TuringerGameObject_getComponentByType(TuringerGameObject self
, Type cs_type) {
    
    return _core_turinger_game_object__get_component_by_type(self, cs_type);
}

bool Core_TuringerGameObject_activeInHierarchyGet(TuringerGameObject self) {
    
    return _core_turinger_game_object__active_in_hierarchy_get(self);
}

void Core_TuringerGameObject_setActive(TuringerGameObject self
, bool value) {
    
    _core_turinger_game_object__set_active(self, value);
}

bool Core_TuringerGameObject_activeGet(TuringerGameObject self) {
    
    return _core_turinger_game_object__active_get(self);
}

Component Core_TuringerGameObject_getComponentByName(TuringerGameObject self
, const char* cs_type) {
    
    return _core_turinger_game_object__get_component_by_name(self, cs_type);
}

void Core_TuringerGameObject_nameSet(TuringerGameObject self
, const char* value) {
    
    _core_turinger_game_object__name_set(self, value);
}

uint64_t Core_TuringerGameObject_sceneCullingMaskGet(TuringerGameObject self) {
    
    return _core_turinger_game_object__scene_culling_mask_get(self);
}





















