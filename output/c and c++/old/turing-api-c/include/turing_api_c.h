

///// Generated C API Header /////
#ifndef TURING_API_H
#define TURING_API_H
#include <stdint.h>
// skip ffi imports as they're included from wasm.h
#define TURING_API_C_SEMVER "0.1.0"

uint64_t _turing_api_semver(void);

//// Functions ////

//// Classes ////

// class GameObject

typedef struct {
    uint64_t opaqu;
} GameObject;




// class Transform

typedef struct {
    uint64_t opaqu;
} Transform;




// class TuringScriptManager

typedef struct {
    uint64_t opaqu;
} TuringScriptManager;




// class Object

typedef struct {
    uint64_t opaqu;
} Object;




// class List1

typedef struct {
    uint64_t opaqu;
} List1;




// class List

typedef struct {
    uint64_t opaqu;
} List;




// class Component

typedef struct {
    uint64_t opaqu;
} Component;




// class Type

typedef struct {
    uint64_t opaqu;
} Type;




// class IEnumerator

typedef struct {
    uint64_t opaqu;
} IEnumerator;




// class Log

typedef struct Log Log;



void Log_warn(const char* msg);

void Log_info(const char* msg);

void Log_debug(const char* msg);

void Log_critical(const char* msg);


// class NoteManager

typedef struct NoteManager NoteManager;



void NoteManager_addObstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data);

void NoteManager_addColorNote(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data);

float NoteManager_timeToBeat(float time);

void NoteManager_addBombNote(float beat, int32_t line, int32_t layer, CustomData custom_data);


// class TuringerGameObjectManager

typedef struct {
    uint64_t opaqu;
} TuringerGameObjectManager;



TuringerGameObject TuringerGameObjectManager_createObject(const char* name);

TuringerGameObject TuringerGameObjectManager_find(const char* name);

void TuringerGameObjectManager_destroyObject(TuringerGameObject listener);


TuringerGameObjectManager TuringerGameObjectManager_instanceGet(TuringerGameObjectManager* self);

// class TuringerGameObject

typedef struct {
    uint64_t opaqu;
} TuringerGameObject;




Component TuringerGameObject_getComponentsInParentByType(TuringerGameObject* self, Type cs_type, bool include_inactive);

void TuringerGameObject_sendMessage(TuringerGameObject* self, const char* method_name);

Component TuringerGameObject_getComponentInParentByType(TuringerGameObject* self, Type cs_type);

bool TuringerGameObject_isStaticGet(TuringerGameObject* self);

TuringerTransform TuringerGameObject_transformGet(TuringerGameObject* self);

Component TuringerGameObject_getComponentInChildrenByType(TuringerGameObject* self, Type cs_type);

void TuringerGameObject_getComponentsByType(TuringerGameObject* self, Type cs_type, List1 results);

void TuringerGameObject_activeSet(TuringerGameObject* self, bool value);

void TuringerGameObject_broadcastMessage(TuringerGameObject* self, const char* method_name);

GameObject TuringerGameObject_gameObjectGet(TuringerGameObject* self);

void TuringerGameObject_isStaticSet(TuringerGameObject* self, bool value);

Component TuringerGameObject_addComponent(TuringerGameObject* self, Type component_type);

void TuringerGameObject_hideFlagsSet(TuringerGameObject* self, int32_t value);

void TuringerGameObject_sendMessageUpwards(TuringerGameObject* self, const char* method_name);

bool TuringerGameObject_compareTag(TuringerGameObject* self, const char* tag);

int32_t TuringerGameObject_hideFlagsGet(TuringerGameObject* self);

void TuringerGameObject_tagSet(TuringerGameObject* self, const char* value);

int32_t TuringerGameObject_getInstanceId(TuringerGameObject* self);

int32_t TuringerGameObject_layerGet(TuringerGameObject* self);

Component TuringerGameObject_getComponentsInChildrenByType(TuringerGameObject* self, Type cs_type, bool include_inactive);

void TuringerGameObject_layerSet(TuringerGameObject* self, int32_t value);

void TuringerGameObject_setActiveRecursively(TuringerGameObject* self, bool state);

int32_t TuringerGameObject_getComponentIndex(TuringerGameObject* self, Component component);

int32_t TuringerGameObject_getComponentCount(TuringerGameObject* self);

Component TuringerGameObject_getComponentAtIndex(TuringerGameObject* self, int32_t index);

char* TuringerGameObject_tagGet(TuringerGameObject* self);

bool TuringerGameObject_activeSelfGet(TuringerGameObject* self);

char* TuringerGameObject_nameGet(TuringerGameObject* self);

Component TuringerGameObject_getComponentByType(TuringerGameObject* self, Type cs_type);

bool TuringerGameObject_activeInHierarchyGet(TuringerGameObject* self);

void TuringerGameObject_setActive(TuringerGameObject* self, bool value);

bool TuringerGameObject_activeGet(TuringerGameObject* self);

Component TuringerGameObject_getComponentByName(TuringerGameObject* self, const char* cs_type);

void TuringerGameObject_nameSet(TuringerGameObject* self, const char* value);

uint64_t TuringerGameObject_sceneCullingMaskGet(TuringerGameObject* self);

// class TuringerTransform

typedef struct {
    uint64_t opaqu;
} TuringerTransform;




Component TuringerTransform_getComponentByType(TuringerTransform* self, Type cs_type);

void TuringerTransform_lookAt(TuringerTransform* self, vec3s world_position);

int32_t TuringerTransform_getInstanceId(TuringerTransform* self);

char* TuringerTransform_tagGet(TuringerTransform* self);

vec3s TuringerTransform_localEulerAnglesGet(TuringerTransform* self);

quats TuringerTransform_rotationGet(TuringerTransform* self);

mat4s TuringerTransform_worldToLocalMatrixGet(TuringerTransform* self);

int32_t TuringerTransform_hierarchyCountGet(TuringerTransform* self);

Component TuringerTransform_getComponentsInChildrenByType(TuringerTransform* self, Type t, bool include_inactive);

void TuringerTransform_nameSet(TuringerTransform* self, const char* value);

quats TuringerTransform_localRotationGet(TuringerTransform* self);

void TuringerTransform_detachChildren(TuringerTransform* self);

vec3s TuringerTransform_inverseTransformPoint(TuringerTransform* self, float x, float y, float z);

Component TuringerTransform_getComponentInChildrenByType(TuringerTransform* self, Type t, bool include_inactive);

Transform TuringerTransform_transformGet(TuringerTransform* self);

vec3s TuringerTransform_lossyScaleGet(TuringerTransform* self);

TuringerTransform TuringerTransform_rootGet(TuringerTransform* self);

void TuringerTransform_getComponentsByType(TuringerTransform* self, Type cs_type, List1 results);

IEnumerator TuringerTransform_getEnumerator(TuringerTransform* self);

void TuringerTransform_localScaleSet(TuringerTransform* self, vec3s value);

int32_t TuringerTransform_childCountGet(TuringerTransform* self);

void TuringerTransform_parentSet(TuringerTransform* self, TuringerTransform value);

TuringerTransform TuringerTransform_getChild(TuringerTransform* self, int32_t index);

vec3s TuringerTransform_transformDirection(TuringerTransform* self, float x, float y, float z);

void TuringerTransform_hasChangedSet(TuringerTransform* self, bool value);

void TuringerTransform_sendMessageUpwards(TuringerTransform* self, const char* method_name, Object value, int32_t options);

TuringerTransform TuringerTransform_findChild(TuringerTransform* self, const char* n);

Component TuringerTransform_getComponentsInParentByType(TuringerTransform* self, Type t, bool include_inactive);

void TuringerTransform_rotate(TuringerTransform* self, vec3s axis, float angle);

bool TuringerTransform_hasChangedGet(TuringerTransform* self);

vec3s TuringerTransform_localPositionGet(TuringerTransform* self);

void TuringerTransform_translateRelative(TuringerTransform* self, vec3s translation, TuringerTransform relative_to);

void TuringerTransform_localEulerAnglesSet(TuringerTransform* self, vec3s value);

void TuringerTransform_setLocalPositionAndRotation(TuringerTransform* self, vec3s local_position, quats local_rotation);

vec3s TuringerTransform_forwardGet(TuringerTransform* self);

int32_t TuringerTransform_getSiblingIndex(TuringerTransform* self);

Component TuringerTransform_getComponentInParentByType(TuringerTransform* self, Type t, bool include_inactive);

vec3s TuringerTransform_upGet(TuringerTransform* self);

int32_t TuringerTransform_getComponentIndex(TuringerTransform* self);

void TuringerTransform_rotateAroundLocal(TuringerTransform* self, vec3s axis, float angle);

void TuringerTransform_translate(TuringerTransform* self, vec3s translation);

void TuringerTransform_broadcastMessage(TuringerTransform* self, const char* method_name, Object parameter, int32_t options);

void TuringerTransform_eulerAnglesSet(TuringerTransform* self, vec3s value);

void TuringerTransform_sendMessage(TuringerTransform* self, const char* method_name, Object value, int32_t options);

TuringerTransform TuringerTransform_parentGet(TuringerTransform* self);

mat4s TuringerTransform_localToWorldMatrixGet(TuringerTransform* self);

Component TuringerTransform_getComponentByName(TuringerTransform* self, const char* cs_type);

void TuringerTransform_setParent(TuringerTransform* self, TuringerTransform parent, bool world_position_stays);

void TuringerTransform_rotateAround(TuringerTransform* self, vec3s axis, float angle);

void TuringerTransform_hierarchyCapacitySet(TuringerTransform* self, int32_t value);

void TuringerTransform_upSet(TuringerTransform* self, vec3s value);

vec3s TuringerTransform_inverseTransformDirection(TuringerTransform* self, float x, float y, float z);

vec3s TuringerTransform_localScaleGet(TuringerTransform* self);

vec3s TuringerTransform_transformVector(TuringerTransform* self, float x, float y, float z);

vec3s TuringerTransform_transformPoint(TuringerTransform* self, float x, float y, float z);

vec3s TuringerTransform_eulerAnglesGet(TuringerTransform* self);

bool TuringerTransform_isChildOf(TuringerTransform* self, TuringerTransform parent);

void TuringerTransform_rightSet(TuringerTransform* self, vec3s value);

int32_t TuringerTransform_getChildCount(TuringerTransform* self);

int32_t TuringerTransform_hideFlagsGet(TuringerTransform* self);

void TuringerTransform_rotateRelative(TuringerTransform* self, vec3s axis, float angle, int32_t relative_to);

void TuringerTransform_rotationSet(TuringerTransform* self, quats value);

TuringerGameObject TuringerTransform_gameObjectGet(TuringerTransform* self);

int32_t TuringerTransform_hierarchyCapacityGet(TuringerTransform* self);

void TuringerTransform_setAsFirstSibling(TuringerTransform* self);

vec3s TuringerTransform_rightGet(TuringerTransform* self);

void TuringerTransform_localPositionSet(TuringerTransform* self, vec3s value);

void TuringerTransform_forwardSet(TuringerTransform* self, vec3s value);

char* TuringerTransform_nameGet(TuringerTransform* self);

bool TuringerTransform_compareTag(TuringerTransform* self, const char* tag);

void TuringerTransform_setAsLastSibling(TuringerTransform* self);

vec3s TuringerTransform_positionGet(TuringerTransform* self);

void TuringerTransform_setSiblingIndex(TuringerTransform* self, int32_t index);

void TuringerTransform_positionSet(TuringerTransform* self, vec3s value);

void TuringerTransform_hideFlagsSet(TuringerTransform* self, int32_t value);

void TuringerTransform_setPositionAndRotation(TuringerTransform* self, vec3s position, quats rotation);

TuringerTransform TuringerTransform_find(TuringerTransform* self, const char* n);

void TuringerTransform_tagSet(TuringerTransform* self, const char* value);

void TuringerTransform_localRotationSet(TuringerTransform* self, quats value);

vec3s TuringerTransform_inverseTransformVector(TuringerTransform* self, float x, float y, float z);

// class GcHelper

typedef struct {
    uint64_t opaqu;
} GcHelper;



GCHelper GcHelper_create(void);


void GcHelper_wasmGarbageCollect(GcHelper* self);

void GcHelper_dispose(GcHelper* self);

void GcHelper_invalidateAllHandles(GcHelper* self);

// class Xr

typedef struct {
    uint64_t opaqu;
} Xr;



int32_t Xr_getDeviceTrackingState(int32_t node_int);

char* Xr_getDeviceName(int32_t node_int);

bool Xr_getDeviceSecondaryButtonState(int32_t node_int);

bool Xr_getDevicePrimaryButtonState(int32_t node_int);

void Xr_sendHapticImpulse(int32_t node_int, float amplitude, float duration);

bool Xr_isDeviceValid(int32_t node_int);

float Xr_getDeviceBatteryLevel(int32_t node_int);

vec2s Xr_getDeviceTouchpad(int32_t node_int);

float Xr_getDeviceGripValue(int32_t node_int);

float Xr_getDeviceTriggerValue(int32_t node_int);

void Xr_stopHaptics(int32_t node_int);

vec2s Xr_getDeviceThumbstick(int32_t node_int);


TuringScriptManager Xr_ManagerGet(Xr* self);

// class CustomData

typedef struct {
    uint64_t opaqu;
} CustomData;



CustomData CustomData_create(void);

List CustomData_listCreate(void);

void CustomData_setString(CustomData custom_data, const char* key, const char* value);

void CustomData_setCustomData(CustomData custom_data, const char* key, CustomData value);

void CustomData_listAddString(List1 list, const char* value);

void CustomData_setCustomDataList(CustomData custom_data, const char* key, List1 value);

void CustomData_setFloat(CustomData custom_data, const char* key, float value);

void CustomData_listAddInt(List1 list, int32_t value);

void CustomData_listAddBool(List1 list, bool value);

void CustomData_setInt(CustomData custom_data, const char* key, int32_t value);

void CustomData_setBool(CustomData custom_data, const char* key, bool value);

void CustomData_listAddCustomDataList(List1 list, List1 value);

void CustomData_listAddFloat(List1 list, float value);

void CustomData_listAddCustomData(List1 list, CustomData value);


#endif // TURING_API_H


