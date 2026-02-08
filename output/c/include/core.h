#pragma once

///// Generated C API /////

// This file is found in output/shared/include/
#include "core_wasm.h"
#include "cglm/struct.h"

#ifndef WASM_EXPORT
#define WASM_EXPORT(name) __attribute__((visibility("default"))) __attribute__((used)) __attribute__((export_name(name)))
#endif

uint32_t __enqueue_vec2(vec2s v);
vec2s __dequeue_vec2();

uint32_t __enqueue_vec3(vec3s v);
vec3s __dequeue_vec3();

uint32_t __enqueue_vec4(vec4s v);
vec4s __dequeue_vec4();

uint32_t __enqueue_quat(versors v);
versors __dequeue_quat();

uint32_t __enqueue_mat4(mat4s v);
mat4s __dequeue_mat4();

#define CORE_VERSION "0.1.0"

// // Type Defs // //

/// Represents a slice of 32-bit unsigned integers.
typedef struct U32Buffer {
    uint32_t* data;
    uint32_t length;
} U32Buffer;

typedef struct GcHelper {
    uint64_t handle;
} GcHelper;


typedef struct TuringerTransform {
    uint64_t handle;
} TuringerTransform;


typedef struct TuringerGameObjectManager {
    uint64_t handle;
} TuringerGameObjectManager;


typedef struct Xr {
    uint64_t handle;
} Xr;


typedef struct TaskScheduler {
    uint64_t handle;
} TaskScheduler;


typedef struct CustomData {
    uint64_t handle;
} CustomData;


typedef struct TuringerGameObject {
    uint64_t handle;
} TuringerGameObject;


typedef struct Object {
    uint64_t handle;
} Object;


typedef struct Component {
    uint64_t handle;
} Component;


typedef struct Type {
    uint64_t handle;
} Type;


typedef struct TuringScriptManager {
    uint64_t handle;
} TuringScriptManager;


typedef struct IEnumerator {
    uint64_t handle;
} IEnumerator;


typedef struct Action {
    uint64_t handle;
} Action;


typedef struct List1 {
    uint64_t handle;
} List1;


typedef struct GameObject {
    uint64_t handle;
} GameObject;


typedef struct Transform {
    uint64_t handle;
} Transform;
// // Functions // //


// // Classes // //
GcHelper Core_GcHelper_create();
void Core_GcHelper_wasmGarbageCollect(GcHelper self);
void Core_GcHelper_dispose(GcHelper self);
void Core_GcHelper_invalidateAllHandles(GcHelper self);
Component Core_TuringerTransform_getComponentByType(TuringerTransform self, Type cs_type);
void Core_TuringerTransform_lookAt(TuringerTransform self, TuringerTransform target, vec3s world_up);
int32_t Core_TuringerTransform_getInstanceId(TuringerTransform self);
char* Core_TuringerTransform_tagGet(TuringerTransform self);
vec3s Core_TuringerTransform_localEulerAnglesGet(TuringerTransform self);
versors Core_TuringerTransform_rotationGet(TuringerTransform self);
mat4s Core_TuringerTransform_worldToLocalMatrixGet(TuringerTransform self);
int32_t Core_TuringerTransform_hierarchyCountGet(TuringerTransform self);
void Core_TuringerTransform_nameSet(TuringerTransform self, const char* value);
versors Core_TuringerTransform_localRotationGet(TuringerTransform self);
void Core_TuringerTransform_detachChildren(TuringerTransform self);
vec3s Core_TuringerTransform_inverseTransformPoint(TuringerTransform self, vec3s position);
Component Core_TuringerTransform_getComponentInChildrenByType(TuringerTransform self, Type t, bool include_inactive);
Transform Core_TuringerTransform_transformGet(TuringerTransform self);
vec3s Core_TuringerTransform_lossyScaleGet(TuringerTransform self);
TuringerTransform Core_TuringerTransform_rootGet(TuringerTransform self);
IEnumerator Core_TuringerTransform_getEnumerator(TuringerTransform self);
void Core_TuringerTransform_localScaleSet(TuringerTransform self, vec3s value);
int32_t Core_TuringerTransform_childCountGet(TuringerTransform self);
void Core_TuringerTransform_parentSet(TuringerTransform self, TuringerTransform value);
TuringerTransform Core_TuringerTransform_getChild(TuringerTransform self, int32_t index);
vec3s Core_TuringerTransform_transformDirection(TuringerTransform self, vec3s direction);
void Core_TuringerTransform_hasChangedSet(TuringerTransform self, bool value);
void Core_TuringerTransform_sendMessageUpwards(TuringerTransform self, const char* method_name, Object value, int32_t options);
TuringerTransform Core_TuringerTransform_findChild(TuringerTransform self, const char* n);
void Core_TuringerTransform_rotate(TuringerTransform self, vec3s eulers);
bool Core_TuringerTransform_hasChangedGet(TuringerTransform self);
vec3s Core_TuringerTransform_localPositionGet(TuringerTransform self);
void Core_TuringerTransform_translateRelative(TuringerTransform self, vec3s translation, TuringerTransform relative_to);
void Core_TuringerTransform_localEulerAnglesSet(TuringerTransform self, vec3s value);
void Core_TuringerTransform_setLocalPositionAndRotation(TuringerTransform self, vec3s local_position, versors local_rotation);
vec3s Core_TuringerTransform_forwardGet(TuringerTransform self);
int32_t Core_TuringerTransform_getSiblingIndex(TuringerTransform self);
Component Core_TuringerTransform_getComponentInParentByType(TuringerTransform self, Type t, bool include_inactive);
vec3s Core_TuringerTransform_upGet(TuringerTransform self);
int32_t Core_TuringerTransform_getComponentIndex(TuringerTransform self);
void Core_TuringerTransform_rotateAroundLocal(TuringerTransform self, vec3s axis, float angle);
void Core_TuringerTransform_translate(TuringerTransform self, vec3s translation, int32_t relative_to);
void Core_TuringerTransform_broadcastMessage(TuringerTransform self, const char* method_name, Object parameter, int32_t options);
void Core_TuringerTransform_eulerAnglesSet(TuringerTransform self, vec3s value);
void Core_TuringerTransform_sendMessage(TuringerTransform self, const char* method_name, Object value, int32_t options);
TuringerTransform Core_TuringerTransform_parentGet(TuringerTransform self);
mat4s Core_TuringerTransform_localToWorldMatrixGet(TuringerTransform self);
Component Core_TuringerTransform_getComponentByName(TuringerTransform self, const char* cs_type);
void Core_TuringerTransform_setParent(TuringerTransform self, TuringerTransform parent, bool world_position_stays);
void Core_TuringerTransform_rotateAround(TuringerTransform self, vec3s point, vec3s axis, float angle);
void Core_TuringerTransform_hierarchyCapacitySet(TuringerTransform self, int32_t value);
void Core_TuringerTransform_upSet(TuringerTransform self, vec3s value);
vec3s Core_TuringerTransform_inverseTransformDirection(TuringerTransform self, vec3s direction);
vec3s Core_TuringerTransform_localScaleGet(TuringerTransform self);
vec3s Core_TuringerTransform_transformVector(TuringerTransform self, vec3s vector);
vec3s Core_TuringerTransform_transformPoint(TuringerTransform self, vec3s position);
vec3s Core_TuringerTransform_eulerAnglesGet(TuringerTransform self);
bool Core_TuringerTransform_isChildOf(TuringerTransform self, TuringerTransform parent);
void Core_TuringerTransform_rightSet(TuringerTransform self, vec3s value);
int32_t Core_TuringerTransform_getChildCount(TuringerTransform self);
int32_t Core_TuringerTransform_hideFlagsGet(TuringerTransform self);
void Core_TuringerTransform_rotateRelative(TuringerTransform self, vec3s eulers, int32_t relative_to);
void Core_TuringerTransform_rotationSet(TuringerTransform self, versors value);
int32_t Core_TuringerTransform_hierarchyCapacityGet(TuringerTransform self);
void Core_TuringerTransform_setAsFirstSibling(TuringerTransform self);
vec3s Core_TuringerTransform_rightGet(TuringerTransform self);
void Core_TuringerTransform_localPositionSet(TuringerTransform self, vec3s value);
void Core_TuringerTransform_forwardSet(TuringerTransform self, vec3s value);
char* Core_TuringerTransform_nameGet(TuringerTransform self);
TuringerGameObject Core_TuringerTransform_gameObjectGet(TuringerTransform self);
bool Core_TuringerTransform_compareTag(TuringerTransform self, const char* tag);
void Core_TuringerTransform_setAsLastSibling(TuringerTransform self);
vec3s Core_TuringerTransform_positionGet(TuringerTransform self);
void Core_TuringerTransform_setSiblingIndex(TuringerTransform self, int32_t index);
void Core_TuringerTransform_positionSet(TuringerTransform self, vec3s value);
void Core_TuringerTransform_hideFlagsSet(TuringerTransform self, int32_t value);
void Core_TuringerTransform_setPositionAndRotation(TuringerTransform self, vec3s position, versors rotation);
TuringerTransform Core_TuringerTransform_find(TuringerTransform self, const char* n);
void Core_TuringerTransform_tagSet(TuringerTransform self, const char* value);
void Core_TuringerTransform_localRotationSet(TuringerTransform self, versors value);
vec3s Core_TuringerTransform_inverseTransformVector(TuringerTransform self, vec3s vector);
TuringerGameObject Core_TuringerGameObjectManager_createObject(const char* name);
TuringerGameObject Core_TuringerGameObjectManager_find(const char* name);
void Core_TuringerGameObjectManager_destroyObject(TuringerGameObject listener);
TuringerGameObjectManager Core_TuringerGameObjectManager_instanceGet(TuringerGameObjectManager self);
void Core_NoteManager_addObstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data);
void Core_NoteManager_addColorNote(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data);
float Core_NoteManager_timeToBeat(float time);
void Core_NoteManager_addBombNote(float beat, int32_t line, int32_t layer, CustomData custom_data);
int32_t Core_Xr_getDeviceTrackingState(int32_t node_int);
char* Core_Xr_getDeviceName(int32_t node_int);
bool Core_Xr_getDeviceSecondaryButtonState(int32_t node_int);
bool Core_Xr_getDevicePrimaryButtonState(int32_t node_int);
void Core_Xr_sendHapticImpulse(int32_t node_int, float amplitude, float duration);
bool Core_Xr_isDeviceValid(int32_t node_int);
float Core_Xr_getDeviceBatteryLevel(int32_t node_int);
vec2s Core_Xr_getDeviceTouchpad(int32_t node_int);
float Core_Xr_getDeviceGripValue(int32_t node_int);
float Core_Xr_getDeviceTriggerValue(int32_t node_int);
void Core_Xr_stopHaptics(int32_t node_int);
vec2s Core_Xr_getDeviceThumbstick(int32_t node_int);
TuringScriptManager Core_Xr_ManagerGet(Xr self);
void Core_Log_warn(const char* msg);
void Core_Log_info(const char* msg);
void Core_Log_debug(const char* msg);
void Core_Log_critical(const char* msg);
void Core_TaskScheduler_schedule(Action task);
void Core_TaskScheduler_dispose(TaskScheduler self);
CustomData Core_CustomData_create();
void Core_CustomData_setString(CustomData custom_data, const char* key, const char* value);
void Core_CustomData_setCustomData(CustomData custom_data, const char* key, CustomData value);
void Core_CustomData_listAddString(List1 list, const char* value);
void Core_CustomData_setCustomDataList(CustomData custom_data, const char* key, List1 value);
void Core_CustomData_setFloat(CustomData custom_data, const char* key, float value);
void Core_CustomData_listAddInt(List1 list, int32_t value);
void Core_CustomData_listAddBool(List1 list, bool value);
void Core_CustomData_setInt(CustomData custom_data, const char* key, int32_t value);
void Core_CustomData_setBool(CustomData custom_data, const char* key, bool value);
void Core_CustomData_listAddCustomDataList(List1 list, List1 value);
void Core_CustomData_listAddFloat(List1 list, float value);
void Core_CustomData_listAddCustomData(List1 list, CustomData value);
void Core_TuringerGameObject_sendMessage(TuringerGameObject self, const char* method_name, int32_t options);
Component Core_TuringerGameObject_getComponentInParentByType(TuringerGameObject self, Type cs_type, bool include_inactive);
bool Core_TuringerGameObject_isStaticGet(TuringerGameObject self);
TuringerTransform Core_TuringerGameObject_transformGet(TuringerGameObject self);
Component Core_TuringerGameObject_getComponentInChildrenByType(TuringerGameObject self, Type cs_type, bool include_inactive);
void Core_TuringerGameObject_activeSet(TuringerGameObject self, bool value);
void Core_TuringerGameObject_broadcastMessage(TuringerGameObject self, const char* method_name, int32_t options);
GameObject Core_TuringerGameObject_gameObjectGet(TuringerGameObject self);
void Core_TuringerGameObject_isStaticSet(TuringerGameObject self, bool value);
Component Core_TuringerGameObject_addComponent(TuringerGameObject self, Type component_type);
void Core_TuringerGameObject_hideFlagsSet(TuringerGameObject self, int32_t value);
void Core_TuringerGameObject_sendMessageUpwards(TuringerGameObject self, const char* method_name, int32_t options);
bool Core_TuringerGameObject_compareTag(TuringerGameObject self, const char* tag);
int32_t Core_TuringerGameObject_hideFlagsGet(TuringerGameObject self);
void Core_TuringerGameObject_tagSet(TuringerGameObject self, const char* value);
int32_t Core_TuringerGameObject_getInstanceId(TuringerGameObject self);
int32_t Core_TuringerGameObject_layerGet(TuringerGameObject self);
void Core_TuringerGameObject_layerSet(TuringerGameObject self, int32_t value);
void Core_TuringerGameObject_setActiveRecursively(TuringerGameObject self, bool state);
int32_t Core_TuringerGameObject_getComponentIndex(TuringerGameObject self, Component component);
int32_t Core_TuringerGameObject_getComponentCount(TuringerGameObject self);
Component Core_TuringerGameObject_getComponentAtIndex(TuringerGameObject self, int32_t index);
char* Core_TuringerGameObject_tagGet(TuringerGameObject self);
bool Core_TuringerGameObject_activeSelfGet(TuringerGameObject self);
char* Core_TuringerGameObject_nameGet(TuringerGameObject self);
Component Core_TuringerGameObject_getComponentByType(TuringerGameObject self, Type cs_type);
bool Core_TuringerGameObject_activeInHierarchyGet(TuringerGameObject self);
void Core_TuringerGameObject_setActive(TuringerGameObject self, bool value);
bool Core_TuringerGameObject_activeGet(TuringerGameObject self);
Component Core_TuringerGameObject_getComponentByName(TuringerGameObject self, const char* cs_type);
void Core_TuringerGameObject_nameSet(TuringerGameObject self, const char* value);
uint64_t Core_TuringerGameObject_sceneCullingMaskGet(TuringerGameObject self);

