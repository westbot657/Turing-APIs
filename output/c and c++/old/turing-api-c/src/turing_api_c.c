

///// Generated C API /////
#include "turing_api.h"
#include "turing_api_wasm.h"
#include <stdlib.h>
#include <string.h>

uint64_t _turing_api_semver(void) {
    return ((uint64_t)0 << 32) | ((uint64_t)1 << 16) | (uint64_t)0;
}

//// Functions ////



//// Classes ////
// class GameObject



// class Transform



// class TuringScriptManager



// class Object



// class List1



// class List



// class Component



// class Type



// class IEnumerator



// class Log

void Log_warn(const char* msg) {
    _log__warn(msg);
}
void Log_info(const char* msg) {
    _log__info(msg);
}
void Log_debug(const char* msg) {
    _log__debug(msg);
}
void Log_critical(const char* msg) {
    _log__critical(msg);
}


// class NoteManager

void NoteManager_addObstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data) {
    _note_manager__add_obstacle(beat, duration, line, layer, width, height, custom_data);
}
void NoteManager_addColorNote(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data) {
    _note_manager__add_color_note(beat, line, layer, color, cut_direction, custom_data);
}
float NoteManager_timeToBeat(float time) {
    return _note_manager__time_to_beat(time);
}
void NoteManager_addBombNote(float beat, int32_t line, int32_t layer, CustomData custom_data) {
    _note_manager__add_bomb_note(beat, line, layer, custom_data);
}


// class TuringerGameObjectManager

TuringerGameObject TuringerGameObjectManager_createObject(const char* name) {
    uint64_t turing_result = _turinger_game_object_manager__create_object(name);
    TuringerGameObject turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
TuringerGameObject TuringerGameObjectManager_find(const char* name) {
    uint64_t turing_result = _turinger_game_object_manager__find(name);
    TuringerGameObject turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerGameObjectManager_destroyObject(TuringerGameObject listener) {
    _turinger_game_object_manager__destroy_object(listener);
}

TuringerGameObjectManager TuringerGameObjectManager_instanceGet(TuringerGameObjectManager* self) {
    uint64_t turing_result = _turinger_game_object_manager__instance_get(self->opaqu);
    TuringerGameObjectManager turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}

// class TuringerGameObject


Component TuringerGameObject_getComponentsInParentByType(TuringerGameObject* self, Type cs_type, bool include_inactive) {
    uint64_t turing_result = _get_components_in_parent_by_type(self->opaqu, cs_type, include_inactive);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerGameObject_sendMessage(TuringerGameObject* self, const char* method_name) {
    _turinger_game_object__send_message(self->opaqu, method_name);
}
Component TuringerGameObject_getComponentInParentByType(TuringerGameObject* self, Type cs_type) {
    uint64_t turing_result = _turinger_game_object__get_component_in_parent_by_type(self->opaqu, cs_type);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
bool TuringerGameObject_isStaticGet(TuringerGameObject* self) {
    return _turinger_game_object__is_static_get(self->opaqu);
}
TuringerTransform TuringerGameObject_transformGet(TuringerGameObject* self) {
    uint64_t turing_result = _turinger_game_object__transform_get(self->opaqu);
    TuringerTransform turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
Component TuringerGameObject_getComponentInChildrenByType(TuringerGameObject* self, Type cs_type) {
    uint64_t turing_result = _turinger_game_object__get_component_in_children_by_type(self->opaqu, cs_type);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerGameObject_getComponentsByType(TuringerGameObject* self, Type cs_type, List1 results) {
    _turinger_game_object__get_components_by_type(self->opaqu, cs_type, results);
}
void TuringerGameObject_activeSet(TuringerGameObject* self, bool value) {
    _turinger_game_object__active_set(self->opaqu, value);
}
void TuringerGameObject_broadcastMessage(TuringerGameObject* self, const char* method_name) {
    _turinger_game_object__broadcast_message(self->opaqu, method_name);
}
GameObject TuringerGameObject_gameObjectGet(TuringerGameObject* self) {
    uint64_t turing_result = _turinger_game_object__game_object_get(self->opaqu);
    GameObject turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerGameObject_isStaticSet(TuringerGameObject* self, bool value) {
    _turinger_game_object__is_static_set(self->opaqu, value);
}
Component TuringerGameObject_addComponent(TuringerGameObject* self, Type component_type) {
    uint64_t turing_result = _turinger_game_object__add_component(self->opaqu, component_type);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerGameObject_hideFlagsSet(TuringerGameObject* self, int32_t value) {
    _turinger_game_object__hide_flags_set(self->opaqu, value);
}
void TuringerGameObject_sendMessageUpwards(TuringerGameObject* self, const char* method_name) {
    _turinger_game_object__send_message_upwards(self->opaqu, method_name);
}
bool TuringerGameObject_compareTag(TuringerGameObject* self, const char* tag) {
    return _turinger_game_object__compare_tag(self->opaqu, tag);
}
int32_t TuringerGameObject_hideFlagsGet(TuringerGameObject* self) {
    return _turinger_game_object__hide_flags_get(self->opaqu);
}
void TuringerGameObject_tagSet(TuringerGameObject* self, const char* value) {
    _turinger_game_object__tag_set(self->opaqu, value);
}
int32_t TuringerGameObject_getInstanceId(TuringerGameObject* self) {
    return _turinger_game_object__get_instance_id(self->opaqu);
}
int32_t TuringerGameObject_layerGet(TuringerGameObject* self) {
    return _turinger_game_object__layer_get(self->opaqu);
}
Component TuringerGameObject_getComponentsInChildrenByType(TuringerGameObject* self, Type cs_type, bool include_inactive) {
    uint64_t turing_result = _get_components_in_children_by_type(self->opaqu, cs_type, include_inactive);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerGameObject_layerSet(TuringerGameObject* self, int32_t value) {
    _turinger_game_object__layer_set(self->opaqu, value);
}
void TuringerGameObject_setActiveRecursively(TuringerGameObject* self, bool state) {
    _turinger_game_object__set_active_recursively(self->opaqu, state);
}
int32_t TuringerGameObject_getComponentIndex(TuringerGameObject* self, Component component) {
    return _turinger_game_object__get_component_index(self->opaqu, component);
}
int32_t TuringerGameObject_getComponentCount(TuringerGameObject* self) {
    return _turinger_game_object__get_component_count(self->opaqu);
}
Component TuringerGameObject_getComponentAtIndex(TuringerGameObject* self, int32_t index) {
    uint64_t turing_result = _turinger_game_object__get_component_at_index(self->opaqu, index);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
char* TuringerGameObject_tagGet(TuringerGameObject* self) {
    uint32_t turing_size = _turinger_game_object__tag_get(self->opaqu);
    if (turing_size == 0) {
        return NULL;
    }
    char* turing_buf = (char*) malloc(turing_size);
    if (!turing_buf) {
        return NULL;
    }
    _host_strcpy(turing_buf, turing_size);
    return turing_buf;
    
}
bool TuringerGameObject_activeSelfGet(TuringerGameObject* self) {
    return _turinger_game_object__active_self_get(self->opaqu);
}
char* TuringerGameObject_nameGet(TuringerGameObject* self) {
    uint32_t turing_size = _turinger_game_object__name_get(self->opaqu);
    if (turing_size == 0) {
        return NULL;
    }
    char* turing_buf = (char*) malloc(turing_size);
    if (!turing_buf) {
        return NULL;
    }
    _host_strcpy(turing_buf, turing_size);
    return turing_buf;
    
}
Component TuringerGameObject_getComponentByType(TuringerGameObject* self, Type cs_type) {
    uint64_t turing_result = _turinger_game_object__get_component_by_type(self->opaqu, cs_type);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
bool TuringerGameObject_activeInHierarchyGet(TuringerGameObject* self) {
    return _turinger_game_object__active_in_hierarchy_get(self->opaqu);
}
void TuringerGameObject_setActive(TuringerGameObject* self, bool value) {
    _turinger_game_object__set_active(self->opaqu, value);
}
bool TuringerGameObject_activeGet(TuringerGameObject* self) {
    return _turinger_game_object__active_get(self->opaqu);
}
Component TuringerGameObject_getComponentByName(TuringerGameObject* self, const char* cs_type) {
    uint64_t turing_result = _turinger_game_object__get_component_by_name(self->opaqu, cs_type);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerGameObject_nameSet(TuringerGameObject* self, const char* value) {
    _turinger_game_object__name_set(self->opaqu, value);
}
uint64_t TuringerGameObject_sceneCullingMaskGet(TuringerGameObject* self) {
    return _turinger_game_object__scene_culling_mask_get(self->opaqu);
}

// class TuringerTransform


Component TuringerTransform_getComponentByType(TuringerTransform* self, Type cs_type) {
    uint64_t turing_result = _turinger_transform__get_component_by_type(self->opaqu, cs_type);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerTransform_lookAt(TuringerTransform* self, vec3s world_position) {
    _turinger_transform__look_at(self->opaqu, world_position);
}
int32_t TuringerTransform_getInstanceId(TuringerTransform* self) {
    return _turinger_transform__get_instance_id(self->opaqu);
}
char* TuringerTransform_tagGet(TuringerTransform* self) {
    uint32_t turing_size = _turinger_transform__tag_get(self->opaqu);
    if (turing_size == 0) {
        return NULL;
    }
    char* turing_buf = (char*) malloc(turing_size);
    if (!turing_buf) {
        return NULL;
    }
    _host_strcpy(turing_buf, turing_size);
    return turing_buf;
    
}
vec3s TuringerTransform_localEulerAnglesGet(TuringerTransform* self) {
    return _turinger_transform__local_euler_angles_get(self->opaqu);
}
quats TuringerTransform_rotationGet(TuringerTransform* self) {
    return _turinger_transform__rotation_get(self->opaqu);
}
mat4s TuringerTransform_worldToLocalMatrixGet(TuringerTransform* self) {
    return _turinger_transform__world_to_local_matrix_get(self->opaqu);
}
int32_t TuringerTransform_hierarchyCountGet(TuringerTransform* self) {
    return _turinger_transform__hierarchy_count_get(self->opaqu);
}
Component TuringerTransform_getComponentsInChildrenByType(TuringerTransform* self, Type t, bool include_inactive) {
    uint64_t turing_result = _get_components_in_children_by_type(self->opaqu, t, include_inactive);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerTransform_nameSet(TuringerTransform* self, const char* value) {
    _turinger_transform__name_set(self->opaqu, value);
}
quats TuringerTransform_localRotationGet(TuringerTransform* self) {
    return _turinger_transform__local_rotation_get(self->opaqu);
}
void TuringerTransform_detachChildren(TuringerTransform* self) {
    _turinger_transform__detach_children(self->opaqu);
}
vec3s TuringerTransform_inverseTransformPoint(TuringerTransform* self, float x, float y, float z) {
    return _turinger_transform__inverse_transform_point(self->opaqu, x, y, z);
}
Component TuringerTransform_getComponentInChildrenByType(TuringerTransform* self, Type t, bool include_inactive) {
    uint64_t turing_result = _turinger_transform__get_component_in_children_by_type(self->opaqu, t, include_inactive);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
Transform TuringerTransform_transformGet(TuringerTransform* self) {
    uint64_t turing_result = _turinger_transform__transform_get(self->opaqu);
    Transform turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
vec3s TuringerTransform_lossyScaleGet(TuringerTransform* self) {
    return _turinger_transform__lossy_scale_get(self->opaqu);
}
TuringerTransform TuringerTransform_rootGet(TuringerTransform* self) {
    uint64_t turing_result = _turinger_transform__root_get(self->opaqu);
    TuringerTransform turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerTransform_getComponentsByType(TuringerTransform* self, Type cs_type, List1 results) {
    _turinger_transform__get_components_by_type(self->opaqu, cs_type, results);
}
IEnumerator TuringerTransform_getEnumerator(TuringerTransform* self) {
    uint64_t turing_result = _turinger_transform__get_enumerator(self->opaqu);
    IEnumerator turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerTransform_localScaleSet(TuringerTransform* self, vec3s value) {
    _turinger_transform__local_scale_set(self->opaqu, value);
}
int32_t TuringerTransform_childCountGet(TuringerTransform* self) {
    return _turinger_transform__child_count_get(self->opaqu);
}
void TuringerTransform_parentSet(TuringerTransform* self, TuringerTransform value) {
    _turinger_transform__parent_set(self->opaqu, value);
}
TuringerTransform TuringerTransform_getChild(TuringerTransform* self, int32_t index) {
    uint64_t turing_result = _turinger_transform__get_child(self->opaqu, index);
    TuringerTransform turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
vec3s TuringerTransform_transformDirection(TuringerTransform* self, float x, float y, float z) {
    return _turinger_transform__transform_direction(self->opaqu, x, y, z);
}
void TuringerTransform_hasChangedSet(TuringerTransform* self, bool value) {
    _turinger_transform__has_changed_set(self->opaqu, value);
}
void TuringerTransform_sendMessageUpwards(TuringerTransform* self, const char* method_name, Object value, int32_t options) {
    _turinger_transform__send_message_upwards(self->opaqu, method_name, value, options);
}
TuringerTransform TuringerTransform_findChild(TuringerTransform* self, const char* n) {
    uint64_t turing_result = _turinger_transform__find_child(self->opaqu, n);
    TuringerTransform turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
Component TuringerTransform_getComponentsInParentByType(TuringerTransform* self, Type t, bool include_inactive) {
    uint64_t turing_result = _get_components_in_parent_by_type(self->opaqu, t, include_inactive);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerTransform_rotate(TuringerTransform* self, vec3s axis, float angle) {
    _turinger_transform__rotate(self->opaqu, axis, angle);
}
bool TuringerTransform_hasChangedGet(TuringerTransform* self) {
    return _turinger_transform__has_changed_get(self->opaqu);
}
vec3s TuringerTransform_localPositionGet(TuringerTransform* self) {
    return _turinger_transform__local_position_get(self->opaqu);
}
void TuringerTransform_translateRelative(TuringerTransform* self, vec3s translation, TuringerTransform relative_to) {
    _turinger_transform__translate_relative(self->opaqu, translation, relative_to);
}
void TuringerTransform_localEulerAnglesSet(TuringerTransform* self, vec3s value) {
    _turinger_transform__local_euler_angles_set(self->opaqu, value);
}
void TuringerTransform_setLocalPositionAndRotation(TuringerTransform* self, vec3s local_position, quats local_rotation) {
    _turinger_transform__set_local_position_and_rotation(self->opaqu, local_position, local_rotation);
}
vec3s TuringerTransform_forwardGet(TuringerTransform* self) {
    return _turinger_transform__forward_get(self->opaqu);
}
int32_t TuringerTransform_getSiblingIndex(TuringerTransform* self) {
    return _turinger_transform__get_sibling_index(self->opaqu);
}
Component TuringerTransform_getComponentInParentByType(TuringerTransform* self, Type t, bool include_inactive) {
    uint64_t turing_result = _turinger_transform__get_component_in_parent_by_type(self->opaqu, t, include_inactive);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
vec3s TuringerTransform_upGet(TuringerTransform* self) {
    return _turinger_transform__up_get(self->opaqu);
}
int32_t TuringerTransform_getComponentIndex(TuringerTransform* self) {
    return _turinger_transform__get_component_index(self->opaqu);
}
void TuringerTransform_rotateAroundLocal(TuringerTransform* self, vec3s axis, float angle) {
    _turinger_transform__rotate_around_local(self->opaqu, axis, angle);
}
void TuringerTransform_translate(TuringerTransform* self, vec3s translation) {
    _turinger_transform__translate(self->opaqu, translation);
}
void TuringerTransform_broadcastMessage(TuringerTransform* self, const char* method_name, Object parameter, int32_t options) {
    _turinger_transform__broadcast_message(self->opaqu, method_name, parameter, options);
}
void TuringerTransform_eulerAnglesSet(TuringerTransform* self, vec3s value) {
    _turinger_transform__euler_angles_set(self->opaqu, value);
}
void TuringerTransform_sendMessage(TuringerTransform* self, const char* method_name, Object value, int32_t options) {
    _turinger_transform__send_message(self->opaqu, method_name, value, options);
}
TuringerTransform TuringerTransform_parentGet(TuringerTransform* self) {
    uint64_t turing_result = _turinger_transform__parent_get(self->opaqu);
    TuringerTransform turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
mat4s TuringerTransform_localToWorldMatrixGet(TuringerTransform* self) {
    return _turinger_transform__local_to_world_matrix_get(self->opaqu);
}
Component TuringerTransform_getComponentByName(TuringerTransform* self, const char* cs_type) {
    uint64_t turing_result = _turinger_transform__get_component_by_name(self->opaqu, cs_type);
    Component turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerTransform_setParent(TuringerTransform* self, TuringerTransform parent, bool world_position_stays) {
    _turinger_transform__set_parent(self->opaqu, parent, world_position_stays);
}
void TuringerTransform_rotateAround(TuringerTransform* self, vec3s axis, float angle) {
    _turinger_transform__rotate_around(self->opaqu, axis, angle);
}
void TuringerTransform_hierarchyCapacitySet(TuringerTransform* self, int32_t value) {
    _turinger_transform__hierarchy_capacity_set(self->opaqu, value);
}
void TuringerTransform_upSet(TuringerTransform* self, vec3s value) {
    _turinger_transform__up_set(self->opaqu, value);
}
vec3s TuringerTransform_inverseTransformDirection(TuringerTransform* self, float x, float y, float z) {
    return _turinger_transform__inverse_transform_direction(self->opaqu, x, y, z);
}
vec3s TuringerTransform_localScaleGet(TuringerTransform* self) {
    return _turinger_transform__local_scale_get(self->opaqu);
}
vec3s TuringerTransform_transformVector(TuringerTransform* self, float x, float y, float z) {
    return _turinger_transform__transform_vector(self->opaqu, x, y, z);
}
vec3s TuringerTransform_transformPoint(TuringerTransform* self, float x, float y, float z) {
    return _turinger_transform__transform_point(self->opaqu, x, y, z);
}
vec3s TuringerTransform_eulerAnglesGet(TuringerTransform* self) {
    return _turinger_transform__euler_angles_get(self->opaqu);
}
bool TuringerTransform_isChildOf(TuringerTransform* self, TuringerTransform parent) {
    return _turinger_transform__is_child_of(self->opaqu, parent);
}
void TuringerTransform_rightSet(TuringerTransform* self, vec3s value) {
    _turinger_transform__right_set(self->opaqu, value);
}
int32_t TuringerTransform_getChildCount(TuringerTransform* self) {
    return _turinger_transform__get_child_count(self->opaqu);
}
int32_t TuringerTransform_hideFlagsGet(TuringerTransform* self) {
    return _turinger_transform__hide_flags_get(self->opaqu);
}
void TuringerTransform_rotateRelative(TuringerTransform* self, vec3s axis, float angle, int32_t relative_to) {
    _turinger_transform__rotate_relative(self->opaqu, axis, angle, relative_to);
}
void TuringerTransform_rotationSet(TuringerTransform* self, quats value) {
    _turinger_transform__rotation_set(self->opaqu, value);
}
TuringerGameObject TuringerTransform_gameObjectGet(TuringerTransform* self) {
    uint64_t turing_result = _turinger_transform__game_object_get(self->opaqu);
    TuringerGameObject turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
int32_t TuringerTransform_hierarchyCapacityGet(TuringerTransform* self) {
    return _turinger_transform__hierarchy_capacity_get(self->opaqu);
}
void TuringerTransform_setAsFirstSibling(TuringerTransform* self) {
    _turinger_transform__set_as_first_sibling(self->opaqu);
}
vec3s TuringerTransform_rightGet(TuringerTransform* self) {
    return _turinger_transform__right_get(self->opaqu);
}
void TuringerTransform_localPositionSet(TuringerTransform* self, vec3s value) {
    _turinger_transform__local_position_set(self->opaqu, value);
}
void TuringerTransform_forwardSet(TuringerTransform* self, vec3s value) {
    _turinger_transform__forward_set(self->opaqu, value);
}
char* TuringerTransform_nameGet(TuringerTransform* self) {
    uint32_t turing_size = _turinger_transform__name_get(self->opaqu);
    if (turing_size == 0) {
        return NULL;
    }
    char* turing_buf = (char*) malloc(turing_size);
    if (!turing_buf) {
        return NULL;
    }
    _host_strcpy(turing_buf, turing_size);
    return turing_buf;
    
}
bool TuringerTransform_compareTag(TuringerTransform* self, const char* tag) {
    return _turinger_transform__compare_tag(self->opaqu, tag);
}
void TuringerTransform_setAsLastSibling(TuringerTransform* self) {
    _turinger_transform__set_as_last_sibling(self->opaqu);
}
vec3s TuringerTransform_positionGet(TuringerTransform* self) {
    return _turinger_transform__position_get(self->opaqu);
}
void TuringerTransform_setSiblingIndex(TuringerTransform* self, int32_t index) {
    _turinger_transform__set_sibling_index(self->opaqu, index);
}
void TuringerTransform_positionSet(TuringerTransform* self, vec3s value) {
    _turinger_transform__position_set(self->opaqu, value);
}
void TuringerTransform_hideFlagsSet(TuringerTransform* self, int32_t value) {
    _turinger_transform__hide_flags_set(self->opaqu, value);
}
void TuringerTransform_setPositionAndRotation(TuringerTransform* self, vec3s position, quats rotation) {
    _turinger_transform__set_position_and_rotation(self->opaqu, position, rotation);
}
TuringerTransform TuringerTransform_find(TuringerTransform* self, const char* n) {
    uint64_t turing_result = _turinger_transform__find(self->opaqu, n);
    TuringerTransform turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void TuringerTransform_tagSet(TuringerTransform* self, const char* value) {
    _turinger_transform__tag_set(self->opaqu, value);
}
void TuringerTransform_localRotationSet(TuringerTransform* self, quats value) {
    _turinger_transform__local_rotation_set(self->opaqu, value);
}
vec3s TuringerTransform_inverseTransformVector(TuringerTransform* self, float x, float y, float z) {
    return _turinger_transform__inverse_transform_vector(self->opaqu, x, y, z);
}

// class GcHelper

GCHelper GcHelper_create(void) {
    uint64_t turing_result = _gc_helper__create();
    GcHelper turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}

void GcHelper_wasmGarbageCollect(GcHelper* self) {
    _gc_helper__wasm_garbage_collect(self->opaqu);
}
void GcHelper_dispose(GcHelper* self) {
    _gc_helper__dispose(self->opaqu);
}
void GcHelper_invalidateAllHandles(GcHelper* self) {
    _gc_helper__invalidate_all_handles(self->opaqu);
}

// class Xr

int32_t Xr_getDeviceTrackingState(int32_t node_int) {
    return _xr__get_device_tracking_state(node_int);
}
char* Xr_getDeviceName(int32_t node_int) {
    uint32_t turing_size = _xr__get_device_name(node_int);
    if (turing_size == 0) {
        return NULL;
    }
    char* turing_buf = (char*) malloc(turing_size);
    if (!turing_buf) {
        return NULL;
    }
    _host_strcpy(turing_buf, turing_size);
    return turing_buf;
    
}
bool Xr_getDeviceSecondaryButtonState(int32_t node_int) {
    return _xr__get_device_secondary_button_state(node_int);
}
bool Xr_getDevicePrimaryButtonState(int32_t node_int) {
    return _xr__get_device_primary_button_state(node_int);
}
void Xr_sendHapticImpulse(int32_t node_int, float amplitude, float duration) {
    _xr__send_haptic_impulse(node_int, amplitude, duration);
}
bool Xr_isDeviceValid(int32_t node_int) {
    return _xr__is_device_valid(node_int);
}
float Xr_getDeviceBatteryLevel(int32_t node_int) {
    return _xr__get_device_battery_level(node_int);
}
vec2s Xr_getDeviceTouchpad(int32_t node_int) {
    return _xr__get_device_touchpad(node_int);
}
float Xr_getDeviceGripValue(int32_t node_int) {
    return _xr__get_device_grip_value(node_int);
}
float Xr_getDeviceTriggerValue(int32_t node_int) {
    return _xr__get_device_trigger_value(node_int);
}
void Xr_stopHaptics(int32_t node_int) {
    _xr__stop_haptics(node_int);
}
vec2s Xr_getDeviceThumbstick(int32_t node_int) {
    return _xr__get_device_thumbstick(node_int);
}

TuringScriptManager Xr_ManagerGet(Xr* self) {
    uint64_t turing_result = _xr___manager_get(self->opaqu);
    TuringScriptManager turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}

// class CustomData

CustomData CustomData_create(void) {
    uint64_t turing_result = _custom_data__create();
    CustomData turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
List CustomData_listCreate(void) {
    uint64_t turing_result = _list_create();
    List turing_ret = { .opaqu = turing_result };
    return turing_ret;
    
}
void CustomData_setString(CustomData custom_data, const char* key, const char* value) {
    _custom_data__set_string(custom_data, key, value);
}
void CustomData_setCustomData(CustomData custom_data, const char* key, CustomData value) {
    _custom_data__set_custom_data(custom_data, key, value);
}
void CustomData_listAddString(List1 list, const char* value) {
    _custom_data__list_add_string(list, value);
}
void CustomData_setCustomDataList(CustomData custom_data, const char* key, List1 value) {
    _custom_data__set_custom_data_list(custom_data, key, value);
}
void CustomData_setFloat(CustomData custom_data, const char* key, float value) {
    _custom_data__set_float(custom_data, key, value);
}
void CustomData_listAddInt(List1 list, int32_t value) {
    _custom_data__list_add_int(list, value);
}
void CustomData_listAddBool(List1 list, bool value) {
    _custom_data__list_add_bool(list, value);
}
void CustomData_setInt(CustomData custom_data, const char* key, int32_t value) {
    _custom_data__set_int(custom_data, key, value);
}
void CustomData_setBool(CustomData custom_data, const char* key, bool value) {
    _custom_data__set_bool(custom_data, key, value);
}
void CustomData_listAddCustomDataList(List1 list, List1 value) {
    _custom_data__list_add_custom_data_list(list, value);
}
void CustomData_listAddFloat(List1 list, float value) {
    _custom_data__list_add_float(list, value);
}
void CustomData_listAddCustomData(List1 list, CustomData value) {
    _custom_data__list_add_custom_data(list, value);
}




