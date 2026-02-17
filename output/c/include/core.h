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

typedef struct Action {
    uint64_t handle;
} Action;


typedef struct Action1 {
    uint64_t handle;
} Action1;


typedef struct BeatmapDataItem {
    uint64_t handle;
} BeatmapDataItem;


typedef struct Component {
    uint64_t handle;
} Component;


typedef struct CustomData {
    uint64_t handle;
} CustomData;


typedef struct CustomEventData {
    uint64_t handle;
} CustomEventData;


typedef struct CustomNoteData {
    uint64_t handle;
} CustomNoteData;


typedef struct CustomObstacleData {
    uint64_t handle;
} CustomObstacleData;


typedef struct GcHelper {
    uint64_t handle;
} GcHelper;


typedef struct GameObject {
    uint64_t handle;
} GameObject;


typedef struct GcHelper {
    uint64_t handle;
} GcHelper;


typedef struct IAudioTimeSource {
    uint64_t handle;
} IAudioTimeSource;


typedef struct IEnumerator {
    uint64_t handle;
} IEnumerator;


typedef struct IVariableMovementDataProvider {
    uint64_t handle;
} IVariableMovementDataProvider;


typedef struct Int32 {
    uint64_t handle;
} Int32;


typedef struct List1 {
    uint64_t handle;
} List1;


typedef struct Mesh {
    uint64_t handle;
} Mesh;


typedef struct NoteController {
    uint64_t handle;
} NoteController;


typedef struct NoteControllerBase {
    uint64_t handle;
} NoteControllerBase;


typedef struct NoteFloorMovement {
    uint64_t handle;
} NoteFloorMovement;


typedef struct NoteJump {
    uint64_t handle;
} NoteJump;


typedef struct Object {
    uint64_t handle;
} Object;


typedef struct ObstacleController {
    uint64_t handle;
} ObstacleController;


typedef struct ObstacleControllerBase {
    uint64_t handle;
} ObstacleControllerBase;


typedef struct PlayerSpaceConvertor {
    uint64_t handle;
} PlayerSpaceConvertor;


typedef struct PlayerTransforms {
    uint64_t handle;
} PlayerTransforms;


typedef struct TaskScheduler {
    uint64_t handle;
} TaskScheduler;


typedef struct Transform {
    uint64_t handle;
} Transform;


typedef struct TuringMesh {
    uint64_t handle;
} TuringMesh;


typedef struct TuringScriptManager {
    uint64_t handle;
} TuringScriptManager;


typedef struct TuringerGameObjectManager {
    uint64_t handle;
} TuringerGameObjectManager;


typedef struct Type {
    uint64_t handle;
} Type;


typedef struct Version {
    uint64_t handle;
} Version;


typedef struct Xr {
    uint64_t handle;
} Xr;
// // Functions // //


// // Classes // //
CustomData Core_CustomData_create();
CustomData Core_CustomData_fromJson(const char* json);
void Core_CustomData_listAddBool(List1 list, bool value);
void Core_CustomData_listAddCustomData(List1 list, CustomData value);
void Core_CustomData_listAddCustomDataList(List1 list, List1 value);
void Core_CustomData_listAddFloat(List1 list, float value);
void Core_CustomData_listAddInt(List1 list, int32_t value);
void Core_CustomData_listAddString(List1 list, const char* value);
void Core_CustomData_setBool(CustomData custom_data, const char* key, bool value);
void Core_CustomData_setCustomData(CustomData custom_data, const char* key, CustomData value);
void Core_CustomData_setCustomDataList(CustomData custom_data, const char* key, List1 value);
void Core_CustomData_setFloat(CustomData custom_data, const char* key, float value);
void Core_CustomData_setInt(CustomData custom_data, const char* key, int32_t value);
void Core_CustomData_setString(CustomData custom_data, const char* key, const char* value);
char* Core_CustomData_toJson(CustomData custom_data, bool pretty);
CustomData Core_CustomEventData_customDataGet(CustomEventData self);
char* Core_CustomEventData_eventTypeGet(CustomEventData self);
BeatmapDataItem Core_CustomEventData_getCopy(CustomEventData self);
Version Core_CustomEventData_versionGet(CustomEventData self);
CustomNoteData Core_CustomNoteData_createCustomBasicNoteData(float time, float beat, int32_t rotation, int32_t line_index);
CustomNoteData Core_CustomNoteData_createCustomBombNoteData(float time, float beat, int32_t rotation, int32_t line_index);
CustomNoteData Core_CustomNoteData_createCustomBurstSliderNoteData(float time, float beat, int32_t rotation, int32_t line_index);
CustomData Core_CustomNoteData_customDataGet(CustomNoteData self);
BeatmapDataItem Core_CustomNoteData_getCopy(CustomNoteData self);
Version Core_CustomNoteData_versionGet(CustomNoteData self);
CustomData Core_CustomObstacleData_customDataGet(CustomObstacleData self);
BeatmapDataItem Core_CustomObstacleData_getCopy(CustomObstacleData self);
Version Core_CustomObstacleData_versionGet(CustomObstacleData self);
Component Core_GameObject_addComponent(GameObject self, Type component_type);
TuringMesh Core_GameObject_addOrGetMesh(GameObject self);
void Core_GameObject_broadcastMessage(GameObject self, const char* method_name, int32_t options);
bool Core_GameObject_compareTag(GameObject self, const char* tag);
bool Core_GameObject_getActive(GameObject self);
bool Core_GameObject_getActiveInHierarchy(GameObject self);
bool Core_GameObject_getActiveSelf(GameObject self);
Component Core_GameObject_getComponentAtIndex(GameObject self, int32_t index);
Component Core_GameObject_getComponentByName(GameObject self, const char* cs_type);
Component Core_GameObject_getComponentByType(GameObject self, Type cs_type);
int32_t Core_GameObject_getComponentCount(GameObject self);
Component Core_GameObject_getComponentInChildrenByType(GameObject self, Type cs_type, bool include_inactive);
Component Core_GameObject_getComponentInParentByType(GameObject self, Type cs_type, bool include_inactive);
int32_t Core_GameObject_getComponentIndex(GameObject self, Component component);
int32_t Core_GameObject_getHideFlags(GameObject self);
int32_t Core_GameObject_getInstanceId(GameObject self);
bool Core_GameObject_getIsStatic(GameObject self);
int32_t Core_GameObject_getLayer(GameObject self);
char* Core_GameObject_getName(GameObject self);
uint64_t Core_GameObject_getSceneCullingMask(GameObject self);
char* Core_GameObject_getTag(GameObject self);
Transform Core_GameObject_getTransform(GameObject self);
void Core_GameObject_sendMessage(GameObject self, const char* method_name, int32_t options);
void Core_GameObject_sendMessageUpwards(GameObject self, const char* method_name, int32_t options);
void Core_GameObject_setActive(GameObject self, bool value);
void Core_GameObject_setActiveProp(GameObject self, bool value);
void Core_GameObject_setActiveRecursively(GameObject self, bool state);
void Core_GameObject_setHideFlags(GameObject self, int32_t value);
void Core_GameObject_setIsStatic(GameObject self, bool value);
void Core_GameObject_setLayer(GameObject self, int32_t value);
void Core_GameObject_setName(GameObject self, const char* value);
void Core_GameObject_setTag(GameObject self, const char* value);
GCHelper Core_GcHelper_create();
void Core_GcHelper_dispose(GcHelper self);
void Core_GcHelper_invalidateAllHandles(GcHelper self);
void Core_GcHelper_wasmGarbageCollect(GcHelper self);
void Core_Log_critical(const char* msg);
void Core_Log_debug(const char* msg);
void Core_Log_info(const char* msg);
void Core_Log_warn(const char* msg);
IAudioTimeSource Core_NoteFloorMovement_AudioTimeSyncControllerGet(NoteFloorMovement self);
float Core_NoteFloorMovement_BeatTimeGet(NoteFloorMovement self);
void Core_NoteFloorMovement_BeatTimeSet(NoteFloorMovement self, float value);
versors Core_NoteFloorMovement_InverseWorldRotationGet(NoteFloorMovement self);
void Core_NoteFloorMovement_InverseWorldRotationSet(NoteFloorMovement self, versors value);
vec3s Core_NoteFloorMovement_LocalPositionGet(NoteFloorMovement self);
void Core_NoteFloorMovement_LocalPositionSet(NoteFloorMovement self, vec3s value);
vec3s Core_NoteFloorMovement_MoveEndOffsetGet(NoteFloorMovement self);
void Core_NoteFloorMovement_MoveEndOffsetSet(NoteFloorMovement self, vec3s value);
vec3s Core_NoteFloorMovement_MoveStartOffsetGet(NoteFloorMovement self);
void Core_NoteFloorMovement_MoveStartOffsetSet(NoteFloorMovement self, vec3s value);
PlayerTransforms Core_NoteFloorMovement_PlayerTransformsGet(NoteFloorMovement self);
Transform Core_NoteFloorMovement_RotatedObjectGet(NoteFloorMovement self);
void Core_NoteFloorMovement_RotatedObjectSet(NoteFloorMovement self, Transform value);
IVariableMovementDataProvider Core_NoteFloorMovement_VariableMovementDataProviderGet(NoteFloorMovement self);
versors Core_NoteFloorMovement_WorldRotationGet(NoteFloorMovement self);
void Core_NoteFloorMovement_WorldRotationSet(NoteFloorMovement self, versors value);
float Core_NoteFloorMovement_distanceToPlayerGet(NoteFloorMovement self);
vec3s Core_NoteFloorMovement_endPosGet(NoteFloorMovement self);
void Core_NoteFloorMovement_initFloor(NoteFloorMovement self, float world_rotation, float beat_time, vec3s move_start_offset, vec3s move_end_offset);
versors Core_NoteFloorMovement_inverseWorldRotationGet(NoteFloorMovement self);
vec3s Core_NoteFloorMovement_localPositionGet(NoteFloorMovement self);
vec3s Core_NoteFloorMovement_manualUpdate(NoteFloorMovement self);
float Core_NoteFloorMovement_noteTimeGet(NoteFloorMovement self);
vec3s Core_NoteFloorMovement_setToStart(NoteFloorMovement self);
bool Core_NoteFloorMovement_shouldMove(NoteFloorMovement self);
versors Core_NoteFloorMovement_worldRotationGet(NoteFloorMovement self);
float Core_NoteJump_kMissedTimeOffsetGet();
IAudioTimeSource Core_NoteJump_AudioTimeSyncControllerGet(NoteJump self);
float Core_NoteJump_EndDistanceOffsetGet(NoteJump self);
void Core_NoteJump_EndDistanceOffsetSet(NoteJump self, float value);
vec3s Core_NoteJump_EndOffsetGet(NoteJump self);
void Core_NoteJump_EndOffsetSet(NoteJump self, vec3s value);
vec3s Core_NoteJump_EndPosGet(NoteJump self);
void Core_NoteJump_EndPosSet(NoteJump self, vec3s value);
versors Core_NoteJump_EndRotationGet(NoteJump self);
void Core_NoteJump_EndRotationSet(NoteJump self, versors value);
float Core_NoteJump_GravityBaseGet(NoteJump self);
void Core_NoteJump_GravityBaseSet(NoteJump self, float value);
float Core_NoteJump_GravityGet(NoteJump self);
void Core_NoteJump_GravitySet(NoteJump self, float value);
float Core_NoteJump_HalfJumpDurationGet(NoteJump self);
void Core_NoteJump_HalfJumpDurationSet(NoteJump self, float value);
bool Core_NoteJump_HalfJumpMarkReportedGet(NoteJump self);
void Core_NoteJump_HalfJumpMarkReportedSet(NoteJump self, bool value);
versors Core_NoteJump_InverseWorldRotationGet(NoteJump self);
void Core_NoteJump_InverseWorldRotationSet(NoteJump self, versors value);
float Core_NoteJump_JumpDurationGet(NoteJump self);
void Core_NoteJump_JumpDurationSet(NoteJump self, float value);
bool Core_NoteJump_JumpStartedReportedGet(NoteJump self);
void Core_NoteJump_JumpStartedReportedSet(NoteJump self, bool value);
vec3s Core_NoteJump_LocalPositionGet(NoteJump self);
void Core_NoteJump_LocalPositionSet(NoteJump self, vec3s value);
versors Core_NoteJump_MiddleRotationGet(NoteJump self);
void Core_NoteJump_MiddleRotationSet(NoteJump self, versors value);
bool Core_NoteJump_MissedMarkReportedGet(NoteJump self);
void Core_NoteJump_MissedMarkReportedSet(NoteJump self, bool value);
float Core_NoteJump_MissedTimeGet(NoteJump self);
void Core_NoteJump_MissedTimeSet(NoteJump self, float value);
float Core_NoteJump_NoteTimeGet(NoteJump self);
void Core_NoteJump_NoteTimeSet(NoteJump self, float value);
PlayerSpaceConvertor Core_NoteJump_PlayerSpaceConvertorGet(NoteJump self);
PlayerTransforms Core_NoteJump_PlayerTransformsGet(NoteJump self);
bool Core_NoteJump_RotateTowardsPlayerGet(NoteJump self);
void Core_NoteJump_RotateTowardsPlayerSet(NoteJump self, bool value);
Transform Core_NoteJump_RotatedObjectGet(NoteJump self);
void Core_NoteJump_RotatedObjectSet(NoteJump self, Transform value);
vec3s Core_NoteJump_StartOffsetGet(NoteJump self);
void Core_NoteJump_StartOffsetSet(NoteJump self, vec3s value);
vec3s Core_NoteJump_StartPosGet(NoteJump self);
void Core_NoteJump_StartPosSet(NoteJump self, vec3s value);
versors Core_NoteJump_StartRotationGet(NoteJump self);
void Core_NoteJump_StartRotationSet(NoteJump self, versors value);
bool Core_NoteJump_ThreeQuartersMarkReportedGet(NoteJump self);
void Core_NoteJump_ThreeQuartersMarkReportedSet(NoteJump self, bool value);
IVariableMovementDataProvider Core_NoteJump_VariableMovementDataProviderGet(NoteJump self);
versors Core_NoteJump_WorldRotationGet(NoteJump self);
void Core_NoteJump_WorldRotationSet(NoteJump self, versors value);
float Core_NoteJump_YAvoidanceDownGet(NoteJump self);
void Core_NoteJump_YAvoidanceDownSet(NoteJump self, float value);
float Core_NoteJump_YAvoidanceGet(NoteJump self);
void Core_NoteJump_YAvoidanceSet(NoteJump self, float value);
float Core_NoteJump_YAvoidanceUpGet(NoteJump self);
void Core_NoteJump_YAvoidanceUpSet(NoteJump self, float value);
void Core_NoteJump_addNoteJumpDidFinishEvent(NoteJump self, Action value);
void Core_NoteJump_addNoteJumpDidPassHalfEvent(NoteJump self, Action value);
void Core_NoteJump_addNoteJumpDidPassMissedMarkerEvent(NoteJump self, Action value);
void Core_NoteJump_addNoteJumpDidPassThreeQuartersEvent(NoteJump self, Action1 value);
void Core_NoteJump_addNoteJumpDidStartEvent(NoteJump self, Action value);
void Core_NoteJump_addNoteJumpDidUpdateProgressEvent(NoteJump self, Action1 value);
vec3s Core_NoteJump_beatPosGet(NoteJump self);
float Core_NoteJump_distanceToPlayerGet(NoteJump self);
void Core_NoteJump_initJump(NoteJump self, float note_time, float world_rotation, vec3s move_end_offset, vec3s jump_end_offset, float gravity_base, float flip_y_side, float end_rotation, bool rotate_towards_player, bool use_random_rotation);
vec3s Core_NoteJump_localPositionGet(NoteJump self);
vec3s Core_NoteJump_manualUpdate(NoteJump self);
vec3s Core_NoteJump_moveVecGet(NoteJump self);
float Core_NoteJump_noteTimeGet(NoteJump self);
void Core_NoteJump_removeNoteJumpDidFinishEvent(NoteJump self, Action value);
void Core_NoteJump_removeNoteJumpDidPassHalfEvent(NoteJump self, Action value);
void Core_NoteJump_removeNoteJumpDidPassMissedMarkerEvent(NoteJump self, Action value);
void Core_NoteJump_removeNoteJumpDidPassThreeQuartersEvent(NoteJump self, Action1 value);
void Core_NoteJump_removeNoteJumpDidStartEvent(NoteJump self, Action value);
void Core_NoteJump_removeNoteJumpDidUpdateProgressEvent(NoteJump self, Action1 value);
CustomNoteData Core_NoteManager_addBombNote(float beat, int32_t line, int32_t layer, CustomData custom_data);
CustomNoteData Core_NoteManager_addColorNote(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data);
CustomObstacleData Core_NoteManager_addObstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data);
NoteControllerBase Core_NoteManager_getNoteController(int32_t n);
NoteControllerBase Core_NoteManager_getNoteControllerFromCustom(CustomNoteData n);
CustomEventData Core_NoteManager_getNthEvent(int32_t id);
CustomNoteData Core_NoteManager_getNthNote(int32_t id);
BeatmapDataItem Core_NoteManager_getNthObject(int32_t id);
CustomObstacleData Core_NoteManager_getNthObstacle(int32_t id);
ObstacleControllerBase Core_NoteManager_getObstacleController(int32_t n);
ObstacleController Core_NoteManager_getObstacleControllerFromCustom(CustomObstacleData n);
float Core_NoteManager_timeToBeat(float time);
void Core_TaskScheduler_schedule(Action task);
void Core_TaskScheduler_dispose(TaskScheduler self);
void Core_Transform_broadcastMessage(Transform self, const char* method_name, Object parameter, int32_t options);
bool Core_Transform_compareTag(Transform self, const char* tag);
void Core_Transform_detachChildren(Transform self);
Transform Core_Transform_find(Transform self, const char* n);
Transform Core_Transform_findChild(Transform self, const char* n);
Transform Core_Transform_getChild(Transform self, int32_t index);
int32_t Core_Transform_getChildCount(Transform self);
int32_t Core_Transform_getChildCountProp(Transform self);
Component Core_Transform_getComponentByName(Transform self, const char* cs_type);
Component Core_Transform_getComponentByType(Transform self, Type cs_type);
Component Core_Transform_getComponentInChildrenByType(Transform self, Type t, bool include_inactive);
Component Core_Transform_getComponentInParentByType(Transform self, Type t, bool include_inactive);
int32_t Core_Transform_getComponentIndex(Transform self);
IEnumerator Core_Transform_getEnumerator(Transform self);
vec3s Core_Transform_getEulerAngles(Transform self);
vec3s Core_Transform_getForward(Transform self);
GameObject Core_Transform_getGameObject(Transform self);
bool Core_Transform_getHasChanged(Transform self);
int32_t Core_Transform_getHideFlags(Transform self);
int32_t Core_Transform_getHierarchyCapacity(Transform self);
int32_t Core_Transform_getHierarchyCount(Transform self);
int32_t Core_Transform_getInstanceId(Transform self);
vec3s Core_Transform_getLocalEulerAngles(Transform self);
vec3s Core_Transform_getLocalPosition(Transform self);
versors Core_Transform_getLocalRotation(Transform self);
vec3s Core_Transform_getLocalScale(Transform self);
mat4s Core_Transform_getLocalToWorldMatrix(Transform self);
vec3s Core_Transform_getLossyScale(Transform self);
char* Core_Transform_getName(Transform self);
Transform Core_Transform_getParent(Transform self);
vec3s Core_Transform_getPosition(Transform self);
vec3s Core_Transform_getRight(Transform self);
Transform Core_Transform_getRoot(Transform self);
versors Core_Transform_getRotation(Transform self);
int32_t Core_Transform_getSiblingIndex(Transform self);
char* Core_Transform_getTag(Transform self);
vec3s Core_Transform_getUp(Transform self);
mat4s Core_Transform_getWorldToLocalMatrix(Transform self);
vec3s Core_Transform_inverseTransformDirection(Transform self, vec3s direction);
vec3s Core_Transform_inverseTransformPoint(Transform self, vec3s position);
vec3s Core_Transform_inverseTransformVector(Transform self, vec3s vector);
bool Core_Transform_isChildOf(Transform self, Transform parent);
void Core_Transform_lookAt(Transform self, Transform target, vec3s world_up);
void Core_Transform_rotate(Transform self, vec3s eulers);
void Core_Transform_rotateAround(Transform self, vec3s point, vec3s axis, float angle);
void Core_Transform_rotateAroundLocal(Transform self, vec3s axis, float angle);
void Core_Transform_rotateRelative(Transform self, vec3s eulers, int32_t relative_to);
void Core_Transform_sendMessage(Transform self, const char* method_name, Object value, int32_t options);
void Core_Transform_sendMessageUpwards(Transform self, const char* method_name, Object value, int32_t options);
void Core_Transform_setAsFirstSibling(Transform self);
void Core_Transform_setAsLastSibling(Transform self);
void Core_Transform_setEulerAngles(Transform self, vec3s value);
void Core_Transform_setForward(Transform self, vec3s value);
void Core_Transform_setHasChanged(Transform self, bool value);
void Core_Transform_setHideFlags(Transform self, int32_t value);
void Core_Transform_setHierarchyCapacity(Transform self, int32_t value);
void Core_Transform_setLocalEulerAngles(Transform self, vec3s value);
void Core_Transform_setLocalPosition(Transform self, vec3s value);
void Core_Transform_setLocalPositionAndRotation(Transform self, vec3s local_position, versors local_rotation);
void Core_Transform_setLocalRotation(Transform self, versors value);
void Core_Transform_setLocalScale(Transform self, vec3s value);
void Core_Transform_setName(Transform self, const char* value);
void Core_Transform_setParent(Transform self, Transform parent, bool world_position_stays);
void Core_Transform_setPosition(Transform self, vec3s value);
void Core_Transform_setPositionAndRotation(Transform self, vec3s position, versors rotation);
void Core_Transform_setRight(Transform self, vec3s value);
void Core_Transform_setRotation(Transform self, versors value);
void Core_Transform_setSiblingIndex(Transform self, int32_t index);
void Core_Transform_setTag(Transform self, const char* value);
void Core_Transform_setUp(Transform self, vec3s value);
vec3s Core_Transform_transformDirection(Transform self, vec3s direction);
vec3s Core_Transform_transformPoint(Transform self, vec3s position);
vec3s Core_Transform_transformVector(Transform self, vec3s vector);
void Core_Transform_translate(Transform self, vec3s translation, int32_t relative_to);
void Core_Transform_translateRelative(Transform self, vec3s translation, Transform relative_to);
Mesh Core_TuringMesh_MeshGet(TuringMesh self);
void Core_TuringMesh_MeshSet(TuringMesh self, Mesh value);
void Core_TuringMesh_clear(TuringMesh self);
float Core_TuringMesh_getBoundsMaxX(TuringMesh self);
float Core_TuringMesh_getBoundsMaxY(TuringMesh self);
float Core_TuringMesh_getBoundsMaxZ(TuringMesh self);
float Core_TuringMesh_getBoundsMinX(TuringMesh self);
float Core_TuringMesh_getBoundsMinY(TuringMesh self);
float Core_TuringMesh_getBoundsMinZ(TuringMesh self);
int32_t Core_TuringMesh_getInstanceId(TuringMesh self);
U32Buffer Core_TuringMesh_getUVs(TuringMesh self, int32_t channel);
U32Buffer Core_TuringMesh_getVertices(TuringMesh self);
void Core_TuringMesh_hideFlagsGet(TuringMesh self);
void Core_TuringMesh_hideFlagsSet(TuringMesh self);
void Core_TuringMesh_markModified(TuringMesh self);
char* Core_TuringMesh_nameGet(TuringMesh self);
void Core_TuringMesh_nameSet(TuringMesh self, const char* value);
void Core_TuringMesh_optimize(TuringMesh self);
void Core_TuringMesh_optimizeIndexBuffers(TuringMesh self);
void Core_TuringMesh_recalculateBounds(TuringMesh self);
void Core_TuringMesh_recalculateNormals(TuringMesh self);
void Core_TuringMesh_recalculateTangents(TuringMesh self);
void Core_TuringMesh_setBounds(TuringMesh self, float min_x, float min_y, float min_z, float max_x, float max_y, float max_z);
void Core_TuringMesh_setTriangles(TuringMesh self, Int32 triangles, int32_t submesh, bool calculate_bounds, int32_t base_vertex);
void Core_TuringMesh_setUVs(TuringMesh self, int32_t channel, U32Buffer uvs);
void Core_TuringMesh_setVertices(TuringMesh self, U32Buffer in_vertices);
void Core_TuringMesh_uploadMeshData(TuringMesh self, bool mark_no_longer_readable);
NoteFloorMovement Core_TuringNoteExtensions_getNoteFloorMovement(NoteController note_controller);
NoteJump Core_TuringNoteExtensions_getNoteJump(NoteController note_controller);
GameObject Core_TuringerGameObjectManager_createObject(const char* name);
void Core_TuringerGameObjectManager_destroyObject(GameObject game_object);
GameObject Core_TuringerGameObjectManager_find(const char* name);
TuringerGameObjectManager Core_TuringerGameObjectManager_instanceGet(TuringerGameObjectManager self);
float Core_Xr_getDeviceBatteryLevel(int32_t node_int);
float Core_Xr_getDeviceGripValue(int32_t node_int);
char* Core_Xr_getDeviceName(int32_t node_int);
bool Core_Xr_getDevicePrimaryButtonState(int32_t node_int);
bool Core_Xr_getDeviceSecondaryButtonState(int32_t node_int);
vec2s Core_Xr_getDeviceThumbstick(int32_t node_int);
vec2s Core_Xr_getDeviceTouchpad(int32_t node_int);
int32_t Core_Xr_getDeviceTrackingState(int32_t node_int);
float Core_Xr_getDeviceTriggerValue(int32_t node_int);
bool Core_Xr_isDeviceValid(int32_t node_int);
void Core_Xr_sendHapticImpulse(int32_t node_int, float amplitude, float duration);
void Core_Xr_stopHaptics(int32_t node_int);
TuringScriptManager Core_Xr_ManagerGet(Xr self);

