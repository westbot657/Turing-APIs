

///// Generated C++ API /////
#include "turing_api.hpp"
#include "turing_api_wasm.h"
#include <string>

namespace turing_api_cpp {

uint64_t _turing_api_semver() {
    return ((uint64_t)0 << 32) | ((uint64_t)1 << 16) | (uint64_t)0;
}

//// Functions ////

//// Classes ////

// class GameObject
GameObject::GameObject(uint64_t ptr) : opaqu(ptr) {}



// class Transform
Transform::Transform(uint64_t ptr) : opaqu(ptr) {}



// class TuringScriptManager
TuringScriptManager::TuringScriptManager(uint64_t ptr) : opaqu(ptr) {}



// class Object
Object::Object(uint64_t ptr) : opaqu(ptr) {}



// class List1
List1::List1(uint64_t ptr) : opaqu(ptr) {}



// class List
List::List(uint64_t ptr) : opaqu(ptr) {}



// class Component
Component::Component(uint64_t ptr) : opaqu(ptr) {}



// class Type
Type::Type(uint64_t ptr) : opaqu(ptr) {}



// class IEnumerator
IEnumerator::IEnumerator(uint64_t ptr) : opaqu(ptr) {}



// class Log

void Log::warn(std::string& msg) {
    _log__warn(msg);
}
void Log::info(std::string& msg) {
    _log__info(msg);
}
void Log::debug(std::string& msg) {
    _log__debug(msg);
}
void Log::critical(std::string& msg) {
    _log__critical(msg);
}


// class NoteManager

void NoteManager::addObstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data) {
    _note_manager__add_obstacle(beat, duration, line, layer, width, height, custom_data);
}
void NoteManager::addColorNote(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data) {
    _note_manager__add_color_note(beat, line, layer, color, cut_direction, custom_data);
}
float NoteManager::timeToBeat(float time) {
    return _note_manager__time_to_beat(time);
}
void NoteManager::addBombNote(float beat, int32_t line, int32_t layer, CustomData custom_data) {
    _note_manager__add_bomb_note(beat, line, layer, custom_data);
}


// class TuringerGameObjectManager
TuringerGameObjectManager::TuringerGameObjectManager(uint64_t ptr) : opaqu(ptr) {}

TuringerGameObject TuringerGameObjectManager::createObject(std::string& name) {
    uint64_t turing_result = _turinger_game_object_manager__create_object(name);
    return TuringerGameObject(turing_result);
    
}
TuringerGameObject TuringerGameObjectManager::find(std::string& name) {
    uint64_t turing_result = _turinger_game_object_manager__find(name);
    return TuringerGameObject(turing_result);
    
}
void TuringerGameObjectManager::destroyObject(TuringerGameObject listener) {
    _turinger_game_object_manager__destroy_object(listener);
}

TuringerGameObjectManager TuringerGameObjectManager::instanceGet() {
    uint64_t turing_result = _turinger_game_object_manager__instance_get(this->opaqu);
    return TuringerGameObjectManager(turing_result);
    
}

// class TuringerGameObject
TuringerGameObject::TuringerGameObject(uint64_t ptr) : opaqu(ptr) {}


Component TuringerGameObject::getComponentsInParentByType(Type cs_type, bool include_inactive) {
    uint64_t turing_result = _get_components_in_parent_by_type(this->opaqu, cs_type, include_inactive);
    return Component(turing_result);
    
}
void TuringerGameObject::sendMessage(std::string& method_name) {
    _turinger_game_object__send_message(this->opaqu, method_name);
}
Component TuringerGameObject::getComponentInParentByType(Type cs_type) {
    uint64_t turing_result = _turinger_game_object__get_component_in_parent_by_type(this->opaqu, cs_type);
    return Component(turing_result);
    
}
bool TuringerGameObject::isStaticGet() {
    return _turinger_game_object__is_static_get(this->opaqu);
}
TuringerTransform TuringerGameObject::transformGet() {
    uint64_t turing_result = _turinger_game_object__transform_get(this->opaqu);
    return TuringerTransform(turing_result);
    
}
Component TuringerGameObject::getComponentInChildrenByType(Type cs_type) {
    uint64_t turing_result = _turinger_game_object__get_component_in_children_by_type(this->opaqu, cs_type);
    return Component(turing_result);
    
}
void TuringerGameObject::getComponentsByType(Type cs_type, List1 results) {
    _turinger_game_object__get_components_by_type(this->opaqu, cs_type, results);
}
void TuringerGameObject::activeSet(bool value) {
    _turinger_game_object__active_set(this->opaqu, value);
}
void TuringerGameObject::broadcastMessage(std::string& method_name) {
    _turinger_game_object__broadcast_message(this->opaqu, method_name);
}
GameObject TuringerGameObject::gameObjectGet() {
    uint64_t turing_result = _turinger_game_object__game_object_get(this->opaqu);
    return GameObject(turing_result);
    
}
void TuringerGameObject::isStaticSet(bool value) {
    _turinger_game_object__is_static_set(this->opaqu, value);
}
Component TuringerGameObject::addComponent(Type component_type) {
    uint64_t turing_result = _turinger_game_object__add_component(this->opaqu, component_type);
    return Component(turing_result);
    
}
void TuringerGameObject::hideFlagsSet(int32_t value) {
    _turinger_game_object__hide_flags_set(this->opaqu, value);
}
void TuringerGameObject::sendMessageUpwards(std::string& method_name) {
    _turinger_game_object__send_message_upwards(this->opaqu, method_name);
}
bool TuringerGameObject::compareTag(std::string& tag) {
    return _turinger_game_object__compare_tag(this->opaqu, tag);
}
int32_t TuringerGameObject::hideFlagsGet() {
    return _turinger_game_object__hide_flags_get(this->opaqu);
}
void TuringerGameObject::tagSet(std::string& value) {
    _turinger_game_object__tag_set(this->opaqu, value);
}
int32_t TuringerGameObject::getInstanceId() {
    return _turinger_game_object__get_instance_id(this->opaqu);
}
int32_t TuringerGameObject::layerGet() {
    return _turinger_game_object__layer_get(this->opaqu);
}
Component TuringerGameObject::getComponentsInChildrenByType(Type cs_type, bool include_inactive) {
    uint64_t turing_result = _get_components_in_children_by_type(this->opaqu, cs_type, include_inactive);
    return Component(turing_result);
    
}
void TuringerGameObject::layerSet(int32_t value) {
    _turinger_game_object__layer_set(this->opaqu, value);
}
void TuringerGameObject::setActiveRecursively(bool state) {
    _turinger_game_object__set_active_recursively(this->opaqu, state);
}
int32_t TuringerGameObject::getComponentIndex(Component component) {
    return _turinger_game_object__get_component_index(this->opaqu, component);
}
int32_t TuringerGameObject::getComponentCount() {
    return _turinger_game_object__get_component_count(this->opaqu);
}
Component TuringerGameObject::getComponentAtIndex(int32_t index) {
    uint64_t turing_result = _turinger_game_object__get_component_at_index(this->opaqu, index);
    return Component(turing_result);
    
}
std::string TuringerGameObject::tagGet() {
    uint32_t turing_size = _turinger_game_object__tag_get(this->opaqu);
    if (turing_size == 0) {
        return "";
    }
    std::string turing_buf(turing_size, '\0');
    _host_strcpy(const_cast<char*>(turing_buf.data()), turing_size);
    return turing_buf;
    
}
bool TuringerGameObject::activeSelfGet() {
    return _turinger_game_object__active_self_get(this->opaqu);
}
std::string TuringerGameObject::nameGet() {
    uint32_t turing_size = _turinger_game_object__name_get(this->opaqu);
    if (turing_size == 0) {
        return "";
    }
    std::string turing_buf(turing_size, '\0');
    _host_strcpy(const_cast<char*>(turing_buf.data()), turing_size);
    return turing_buf;
    
}
Component TuringerGameObject::getComponentByType(Type cs_type) {
    uint64_t turing_result = _turinger_game_object__get_component_by_type(this->opaqu, cs_type);
    return Component(turing_result);
    
}
bool TuringerGameObject::activeInHierarchyGet() {
    return _turinger_game_object__active_in_hierarchy_get(this->opaqu);
}
void TuringerGameObject::setActive(bool value) {
    _turinger_game_object__set_active(this->opaqu, value);
}
bool TuringerGameObject::activeGet() {
    return _turinger_game_object__active_get(this->opaqu);
}
Component TuringerGameObject::getComponentByName(std::string& cs_type) {
    uint64_t turing_result = _turinger_game_object__get_component_by_name(this->opaqu, cs_type);
    return Component(turing_result);
    
}
void TuringerGameObject::nameSet(std::string& value) {
    _turinger_game_object__name_set(this->opaqu, value);
}
uint64_t TuringerGameObject::sceneCullingMaskGet() {
    return _turinger_game_object__scene_culling_mask_get(this->opaqu);
}

// class TuringerTransform
TuringerTransform::TuringerTransform(uint64_t ptr) : opaqu(ptr) {}


Component TuringerTransform::getComponentByType(Type cs_type) {
    uint64_t turing_result = _turinger_transform__get_component_by_type(this->opaqu, cs_type);
    return Component(turing_result);
    
}
void TuringerTransform::lookAt(glm::vec3 world_position) {
    _turinger_transform__look_at(this->opaqu, world_position);
}
int32_t TuringerTransform::getInstanceId() {
    return _turinger_transform__get_instance_id(this->opaqu);
}
std::string TuringerTransform::tagGet() {
    uint32_t turing_size = _turinger_transform__tag_get(this->opaqu);
    if (turing_size == 0) {
        return "";
    }
    std::string turing_buf(turing_size, '\0');
    _host_strcpy(const_cast<char*>(turing_buf.data()), turing_size);
    return turing_buf;
    
}
glm::vec3 TuringerTransform::localEulerAnglesGet() {
    return _turinger_transform__local_euler_angles_get(this->opaqu);
}
glm::quat TuringerTransform::rotationGet() {
    return _turinger_transform__rotation_get(this->opaqu);
}
glm::mat4 TuringerTransform::worldToLocalMatrixGet() {
    return _turinger_transform__world_to_local_matrix_get(this->opaqu);
}
int32_t TuringerTransform::hierarchyCountGet() {
    return _turinger_transform__hierarchy_count_get(this->opaqu);
}
Component TuringerTransform::getComponentsInChildrenByType(Type t, bool include_inactive) {
    uint64_t turing_result = _get_components_in_children_by_type(this->opaqu, t, include_inactive);
    return Component(turing_result);
    
}
void TuringerTransform::nameSet(std::string& value) {
    _turinger_transform__name_set(this->opaqu, value);
}
glm::quat TuringerTransform::localRotationGet() {
    return _turinger_transform__local_rotation_get(this->opaqu);
}
void TuringerTransform::detachChildren() {
    _turinger_transform__detach_children(this->opaqu);
}
glm::vec3 TuringerTransform::inverseTransformPoint(float x, float y, float z) {
    return _turinger_transform__inverse_transform_point(this->opaqu, x, y, z);
}
Component TuringerTransform::getComponentInChildrenByType(Type t, bool include_inactive) {
    uint64_t turing_result = _turinger_transform__get_component_in_children_by_type(this->opaqu, t, include_inactive);
    return Component(turing_result);
    
}
Transform TuringerTransform::transformGet() {
    uint64_t turing_result = _turinger_transform__transform_get(this->opaqu);
    return Transform(turing_result);
    
}
glm::vec3 TuringerTransform::lossyScaleGet() {
    return _turinger_transform__lossy_scale_get(this->opaqu);
}
TuringerTransform TuringerTransform::rootGet() {
    uint64_t turing_result = _turinger_transform__root_get(this->opaqu);
    return TuringerTransform(turing_result);
    
}
void TuringerTransform::getComponentsByType(Type cs_type, List1 results) {
    _turinger_transform__get_components_by_type(this->opaqu, cs_type, results);
}
IEnumerator TuringerTransform::getEnumerator() {
    uint64_t turing_result = _turinger_transform__get_enumerator(this->opaqu);
    return IEnumerator(turing_result);
    
}
void TuringerTransform::localScaleSet(glm::vec3 value) {
    _turinger_transform__local_scale_set(this->opaqu, value);
}
int32_t TuringerTransform::childCountGet() {
    return _turinger_transform__child_count_get(this->opaqu);
}
void TuringerTransform::parentSet(TuringerTransform value) {
    _turinger_transform__parent_set(this->opaqu, value);
}
TuringerTransform TuringerTransform::getChild(int32_t index) {
    uint64_t turing_result = _turinger_transform__get_child(this->opaqu, index);
    return TuringerTransform(turing_result);
    
}
glm::vec3 TuringerTransform::transformDirection(float x, float y, float z) {
    return _turinger_transform__transform_direction(this->opaqu, x, y, z);
}
void TuringerTransform::hasChangedSet(bool value) {
    _turinger_transform__has_changed_set(this->opaqu, value);
}
void TuringerTransform::sendMessageUpwards(std::string& method_name, Object value, int32_t options) {
    _turinger_transform__send_message_upwards(this->opaqu, method_name, value, options);
}
TuringerTransform TuringerTransform::findChild(std::string& n) {
    uint64_t turing_result = _turinger_transform__find_child(this->opaqu, n);
    return TuringerTransform(turing_result);
    
}
Component TuringerTransform::getComponentsInParentByType(Type t, bool include_inactive) {
    uint64_t turing_result = _get_components_in_parent_by_type(this->opaqu, t, include_inactive);
    return Component(turing_result);
    
}
void TuringerTransform::rotate(glm::vec3 axis, float angle) {
    _turinger_transform__rotate(this->opaqu, axis, angle);
}
bool TuringerTransform::hasChangedGet() {
    return _turinger_transform__has_changed_get(this->opaqu);
}
glm::vec3 TuringerTransform::localPositionGet() {
    return _turinger_transform__local_position_get(this->opaqu);
}
void TuringerTransform::translateRelative(glm::vec3 translation, TuringerTransform relative_to) {
    _turinger_transform__translate_relative(this->opaqu, translation, relative_to);
}
void TuringerTransform::localEulerAnglesSet(glm::vec3 value) {
    _turinger_transform__local_euler_angles_set(this->opaqu, value);
}
void TuringerTransform::setLocalPositionAndRotation(glm::vec3 local_position, glm::quat local_rotation) {
    _turinger_transform__set_local_position_and_rotation(this->opaqu, local_position, local_rotation);
}
glm::vec3 TuringerTransform::forwardGet() {
    return _turinger_transform__forward_get(this->opaqu);
}
int32_t TuringerTransform::getSiblingIndex() {
    return _turinger_transform__get_sibling_index(this->opaqu);
}
Component TuringerTransform::getComponentInParentByType(Type t, bool include_inactive) {
    uint64_t turing_result = _turinger_transform__get_component_in_parent_by_type(this->opaqu, t, include_inactive);
    return Component(turing_result);
    
}
glm::vec3 TuringerTransform::upGet() {
    return _turinger_transform__up_get(this->opaqu);
}
int32_t TuringerTransform::getComponentIndex() {
    return _turinger_transform__get_component_index(this->opaqu);
}
void TuringerTransform::rotateAroundLocal(glm::vec3 axis, float angle) {
    _turinger_transform__rotate_around_local(this->opaqu, axis, angle);
}
void TuringerTransform::translate(glm::vec3 translation) {
    _turinger_transform__translate(this->opaqu, translation);
}
void TuringerTransform::broadcastMessage(std::string& method_name, Object parameter, int32_t options) {
    _turinger_transform__broadcast_message(this->opaqu, method_name, parameter, options);
}
void TuringerTransform::eulerAnglesSet(glm::vec3 value) {
    _turinger_transform__euler_angles_set(this->opaqu, value);
}
void TuringerTransform::sendMessage(std::string& method_name, Object value, int32_t options) {
    _turinger_transform__send_message(this->opaqu, method_name, value, options);
}
TuringerTransform TuringerTransform::parentGet() {
    uint64_t turing_result = _turinger_transform__parent_get(this->opaqu);
    return TuringerTransform(turing_result);
    
}
glm::mat4 TuringerTransform::localToWorldMatrixGet() {
    return _turinger_transform__local_to_world_matrix_get(this->opaqu);
}
Component TuringerTransform::getComponentByName(std::string& cs_type) {
    uint64_t turing_result = _turinger_transform__get_component_by_name(this->opaqu, cs_type);
    return Component(turing_result);
    
}
void TuringerTransform::setParent(TuringerTransform parent, bool world_position_stays) {
    _turinger_transform__set_parent(this->opaqu, parent, world_position_stays);
}
void TuringerTransform::rotateAround(glm::vec3 axis, float angle) {
    _turinger_transform__rotate_around(this->opaqu, axis, angle);
}
void TuringerTransform::hierarchyCapacitySet(int32_t value) {
    _turinger_transform__hierarchy_capacity_set(this->opaqu, value);
}
void TuringerTransform::upSet(glm::vec3 value) {
    _turinger_transform__up_set(this->opaqu, value);
}
glm::vec3 TuringerTransform::inverseTransformDirection(float x, float y, float z) {
    return _turinger_transform__inverse_transform_direction(this->opaqu, x, y, z);
}
glm::vec3 TuringerTransform::localScaleGet() {
    return _turinger_transform__local_scale_get(this->opaqu);
}
glm::vec3 TuringerTransform::transformVector(float x, float y, float z) {
    return _turinger_transform__transform_vector(this->opaqu, x, y, z);
}
glm::vec3 TuringerTransform::transformPoint(float x, float y, float z) {
    return _turinger_transform__transform_point(this->opaqu, x, y, z);
}
glm::vec3 TuringerTransform::eulerAnglesGet() {
    return _turinger_transform__euler_angles_get(this->opaqu);
}
bool TuringerTransform::isChildOf(TuringerTransform parent) {
    return _turinger_transform__is_child_of(this->opaqu, parent);
}
void TuringerTransform::rightSet(glm::vec3 value) {
    _turinger_transform__right_set(this->opaqu, value);
}
int32_t TuringerTransform::getChildCount() {
    return _turinger_transform__get_child_count(this->opaqu);
}
int32_t TuringerTransform::hideFlagsGet() {
    return _turinger_transform__hide_flags_get(this->opaqu);
}
void TuringerTransform::rotateRelative(glm::vec3 axis, float angle, int32_t relative_to) {
    _turinger_transform__rotate_relative(this->opaqu, axis, angle, relative_to);
}
void TuringerTransform::rotationSet(glm::quat value) {
    _turinger_transform__rotation_set(this->opaqu, value);
}
TuringerGameObject TuringerTransform::gameObjectGet() {
    uint64_t turing_result = _turinger_transform__game_object_get(this->opaqu);
    return TuringerGameObject(turing_result);
    
}
int32_t TuringerTransform::hierarchyCapacityGet() {
    return _turinger_transform__hierarchy_capacity_get(this->opaqu);
}
void TuringerTransform::setAsFirstSibling() {
    _turinger_transform__set_as_first_sibling(this->opaqu);
}
glm::vec3 TuringerTransform::rightGet() {
    return _turinger_transform__right_get(this->opaqu);
}
void TuringerTransform::localPositionSet(glm::vec3 value) {
    _turinger_transform__local_position_set(this->opaqu, value);
}
void TuringerTransform::forwardSet(glm::vec3 value) {
    _turinger_transform__forward_set(this->opaqu, value);
}
std::string TuringerTransform::nameGet() {
    uint32_t turing_size = _turinger_transform__name_get(this->opaqu);
    if (turing_size == 0) {
        return "";
    }
    std::string turing_buf(turing_size, '\0');
    _host_strcpy(const_cast<char*>(turing_buf.data()), turing_size);
    return turing_buf;
    
}
bool TuringerTransform::compareTag(std::string& tag) {
    return _turinger_transform__compare_tag(this->opaqu, tag);
}
void TuringerTransform::setAsLastSibling() {
    _turinger_transform__set_as_last_sibling(this->opaqu);
}
glm::vec3 TuringerTransform::positionGet() {
    return _turinger_transform__position_get(this->opaqu);
}
void TuringerTransform::setSiblingIndex(int32_t index) {
    _turinger_transform__set_sibling_index(this->opaqu, index);
}
void TuringerTransform::positionSet(glm::vec3 value) {
    _turinger_transform__position_set(this->opaqu, value);
}
void TuringerTransform::hideFlagsSet(int32_t value) {
    _turinger_transform__hide_flags_set(this->opaqu, value);
}
void TuringerTransform::setPositionAndRotation(glm::vec3 position, glm::quat rotation) {
    _turinger_transform__set_position_and_rotation(this->opaqu, position, rotation);
}
TuringerTransform TuringerTransform::find(std::string& n) {
    uint64_t turing_result = _turinger_transform__find(this->opaqu, n);
    return TuringerTransform(turing_result);
    
}
void TuringerTransform::tagSet(std::string& value) {
    _turinger_transform__tag_set(this->opaqu, value);
}
void TuringerTransform::localRotationSet(glm::quat value) {
    _turinger_transform__local_rotation_set(this->opaqu, value);
}
glm::vec3 TuringerTransform::inverseTransformVector(float x, float y, float z) {
    return _turinger_transform__inverse_transform_vector(this->opaqu, x, y, z);
}

// class GcHelper
GcHelper::GcHelper(uint64_t ptr) : opaqu(ptr) {}

GCHelper GcHelper::create() {
    uint64_t turing_result = _gc_helper__create();
    return GcHelper(turing_result);
    
}

void GcHelper::wasmGarbageCollect() {
    _gc_helper__wasm_garbage_collect(this->opaqu);
}
void GcHelper::dispose() {
    _gc_helper__dispose(this->opaqu);
}
void GcHelper::invalidateAllHandles() {
    _gc_helper__invalidate_all_handles(this->opaqu);
}

// class Xr
Xr::Xr(uint64_t ptr) : opaqu(ptr) {}

int32_t Xr::getDeviceTrackingState(int32_t node_int) {
    return _xr__get_device_tracking_state(node_int);
}
std::string Xr::getDeviceName(int32_t node_int) {
    uint32_t turing_size = _xr__get_device_name(node_int);
    if (turing_size == 0) {
        return "";
    }
    std::string turing_buf(turing_size, '\0');
    _host_strcpy(const_cast<char*>(turing_buf.data()), turing_size);
    return turing_buf;
    
}
bool Xr::getDeviceSecondaryButtonState(int32_t node_int) {
    return _xr__get_device_secondary_button_state(node_int);
}
bool Xr::getDevicePrimaryButtonState(int32_t node_int) {
    return _xr__get_device_primary_button_state(node_int);
}
void Xr::sendHapticImpulse(int32_t node_int, float amplitude, float duration) {
    _xr__send_haptic_impulse(node_int, amplitude, duration);
}
bool Xr::isDeviceValid(int32_t node_int) {
    return _xr__is_device_valid(node_int);
}
float Xr::getDeviceBatteryLevel(int32_t node_int) {
    return _xr__get_device_battery_level(node_int);
}
glm::vec2 Xr::getDeviceTouchpad(int32_t node_int) {
    return _xr__get_device_touchpad(node_int);
}
float Xr::getDeviceGripValue(int32_t node_int) {
    return _xr__get_device_grip_value(node_int);
}
float Xr::getDeviceTriggerValue(int32_t node_int) {
    return _xr__get_device_trigger_value(node_int);
}
void Xr::stopHaptics(int32_t node_int) {
    _xr__stop_haptics(node_int);
}
glm::vec2 Xr::getDeviceThumbstick(int32_t node_int) {
    return _xr__get_device_thumbstick(node_int);
}

TuringScriptManager Xr::ManagerGet() {
    uint64_t turing_result = _xr___manager_get(this->opaqu);
    return TuringScriptManager(turing_result);
    
}

// class CustomData
CustomData::CustomData(uint64_t ptr) : opaqu(ptr) {}

CustomData CustomData::create() {
    uint64_t turing_result = _custom_data__create();
    return CustomData(turing_result);
    
}
List CustomData::listCreate() {
    uint64_t turing_result = _list_create();
    return List(turing_result);
    
}
void CustomData::setString(CustomData custom_data, std::string& key, std::string& value) {
    _custom_data__set_string(custom_data, key, value);
}
void CustomData::setCustomData(CustomData custom_data, std::string& key, CustomData value) {
    _custom_data__set_custom_data(custom_data, key, value);
}
void CustomData::listAddString(List1 list, std::string& value) {
    _custom_data__list_add_string(list, value);
}
void CustomData::setCustomDataList(CustomData custom_data, std::string& key, List1 value) {
    _custom_data__set_custom_data_list(custom_data, key, value);
}
void CustomData::setFloat(CustomData custom_data, std::string& key, float value) {
    _custom_data__set_float(custom_data, key, value);
}
void CustomData::listAddInt(List1 list, int32_t value) {
    _custom_data__list_add_int(list, value);
}
void CustomData::listAddBool(List1 list, bool value) {
    _custom_data__list_add_bool(list, value);
}
void CustomData::setInt(CustomData custom_data, std::string& key, int32_t value) {
    _custom_data__set_int(custom_data, key, value);
}
void CustomData::setBool(CustomData custom_data, std::string& key, bool value) {
    _custom_data__set_bool(custom_data, key, value);
}
void CustomData::listAddCustomDataList(List1 list, List1 value) {
    _custom_data__list_add_custom_data_list(list, value);
}
void CustomData::listAddFloat(List1 list, float value) {
    _custom_data__list_add_float(list, value);
}
void CustomData::listAddCustomData(List1 list, CustomData value) {
    _custom_data__list_add_custom_data(list, value);
}


} // namespace turing_api_cpp
