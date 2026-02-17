
#include "./turing_api.hpp"
#include <cstring>
#include <cstdlib>

extern "C" {
    TURING_API_EXPORT uint64_t _core_semver() {
        return (((uint64_t) 0) << 32) | (((uint64_t) 1) << 16) | 0;
    }
}

// C++ helpers that enqueue/dequeue glm types using the host FFI
namespace alg {
    using Vec2 = glm::vec2;
    using Vec3 = glm::vec3;
    using Vec4 = glm::vec4;
    using Quat = glm::quat;
    using Mat4 = glm::mat4;

    TURING_API_HIDDEN Vec2 __dequeue_vec2() {
        Vec2 v;
        v[0] = _host_f32_dequeue();
        v[1] = _host_f32_dequeue();
        return v;
    }

    TURING_API_HIDDEN uint32_t __enqueue_vec2(const Vec2& v) {
        _host_f32_enqueue(v[0]);
        _host_f32_enqueue(v[1]);
        return 2;
    }

    TURING_API_HIDDEN Vec3 __dequeue_vec3() {
        Vec3 v;
        v[0] = _host_f32_dequeue();
        v[1] = _host_f32_dequeue();
        v[2] = _host_f32_dequeue();
        return v;
    }

    TURING_API_HIDDEN uint32_t __enqueue_vec3(const Vec3& v) {
        _host_f32_enqueue(v[0]);
        _host_f32_enqueue(v[1]);
        _host_f32_enqueue(v[2]);
        return 3;
    }

    TURING_API_HIDDEN Vec4 __dequeue_vec4() {
        Vec4 v;
        v[0] = _host_f32_dequeue();
        v[1] = _host_f32_dequeue();
        v[2] = _host_f32_dequeue();
        v[3] = _host_f32_dequeue();
        return v;
    }

    TURING_API_HIDDEN uint32_t __enqueue_vec4(const Vec4& v) {
        _host_f32_enqueue(v[0]);
        _host_f32_enqueue(v[1]);
        _host_f32_enqueue(v[2]);
        _host_f32_enqueue(v[3]);
        return 4;
    }

    TURING_API_HIDDEN Quat __dequeue_quat() {
        Quat q;
        q.x = _host_f32_dequeue();
        q.y = _host_f32_dequeue();
        q.z = _host_f32_dequeue();
        q.w = _host_f32_dequeue();
        return q;
    }

    TURING_API_HIDDEN uint32_t __enqueue_quat(const Quat& q) {
        _host_f32_enqueue(q.x);
        _host_f32_enqueue(q.y);
        _host_f32_enqueue(q.z);
        _host_f32_enqueue(q.w);
        return 4;
    }

    TURING_API_HIDDEN Mat4 __dequeue_mat4() {
        Mat4 m;
        for (int c = 0; c < 4; ++c) {
            for (int r = 0; r < 4; ++r) {
                m[c][r] = _host_f32_dequeue();
            }
        }
        return m;
    }

    TURING_API_HIDDEN uint32_t __enqueue_mat4(const Mat4& m) {
        for (int c = 0; c < 4; ++c) {
            for (int r = 0; r < 4; ++r) {
                _host_f32_enqueue(m[c][r]);
            }
        }
        return 16;
    }
}


// // Functions // //



// // Classes // //

CustomData Core_CustomData_create() {
    
    return _core_custom_data__create();
}

CustomData Core_CustomData_fromJson(const char* json) {
    
    return _core_custom_data__from_json(json);
}

void Core_CustomData_listAddBool(List1 list, bool value) {
    
    _core_custom_data__list_add_bool(list, value);
}

void Core_CustomData_listAddCustomData(List1 list, CustomData value) {
    
    _core_custom_data__list_add_custom_data(list, value);
}

void Core_CustomData_listAddCustomDataList(List1 list, List1 value) {
    
    _core_custom_data__list_add_custom_data_list(list, value);
}

void Core_CustomData_listAddFloat(List1 list, float value) {
    
    _core_custom_data__list_add_float(list, value);
}

void Core_CustomData_listAddInt(List1 list, int32_t value) {
    
    _core_custom_data__list_add_int(list, value);
}

void Core_CustomData_listAddString(List1 list, const char* value) {
    
    _core_custom_data__list_add_string(list, value);
}

void Core_CustomData_setBool(CustomData custom_data, const char* key, bool value) {
    
    _core_custom_data__set_bool(custom_data, key, value);
}

void Core_CustomData_setCustomData(CustomData custom_data, const char* key, CustomData value) {
    
    _core_custom_data__set_custom_data(custom_data, key, value);
}

void Core_CustomData_setCustomDataList(CustomData custom_data, const char* key, List1 value) {
    
    _core_custom_data__set_custom_data_list(custom_data, key, value);
}

void Core_CustomData_setFloat(CustomData custom_data, const char* key, float value) {
    
    _core_custom_data__set_float(custom_data, key, value);
}

void Core_CustomData_setInt(CustomData custom_data, const char* key, int32_t value) {
    
    _core_custom_data__set_int(custom_data, key, value);
}

void Core_CustomData_setString(CustomData custom_data, const char* key, const char* value) {
    
    _core_custom_data__set_string(custom_data, key, value);
}

char* Core_CustomData_toJson(CustomData custom_data, bool pretty) {
    
    uint32_t turing_result = _core_custom_data__to_json(custom_data, pretty);
    char* turing_str = (char*) malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

CustomData Core_CustomEventData_customDataGet(CustomEventData self) {
    
    return _core_custom_event_data__custom_data_get(self);
}

char* Core_CustomEventData_eventTypeGet(CustomEventData self) {
    
    uint32_t turing_result = _core_custom_event_data__event_type_get(self);
    char* turing_str = (char*) malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

BeatmapDataItem Core_CustomEventData_getCopy(CustomEventData self) {
    
    return _core_custom_event_data__get_copy(self);
}

Version Core_CustomEventData_versionGet(CustomEventData self) {
    
    return _core_custom_event_data__version_get(self);
}

CustomNoteData Core_CustomNoteData_createCustomBasicNoteData(float time, float beat, int32_t rotation, int32_t line_index) {
    
    return _core_custom_note_data__create_custom_basic_note_data(time, beat, rotation, line_index);
}

CustomNoteData Core_CustomNoteData_createCustomBombNoteData(float time, float beat, int32_t rotation, int32_t line_index) {
    
    return _core_custom_note_data__create_custom_bomb_note_data(time, beat, rotation, line_index);
}

CustomNoteData Core_CustomNoteData_createCustomBurstSliderNoteData(float time, float beat, int32_t rotation, int32_t line_index) {
    
    return _core_custom_note_data__create_custom_burst_slider_note_data(time, beat, rotation, line_index);
}

CustomData Core_CustomNoteData_customDataGet(CustomNoteData self) {
    
    return _core_custom_note_data__custom_data_get(self);
}

BeatmapDataItem Core_CustomNoteData_getCopy(CustomNoteData self) {
    
    return _core_custom_note_data__get_copy(self);
}

Version Core_CustomNoteData_versionGet(CustomNoteData self) {
    
    return _core_custom_note_data__version_get(self);
}

CustomData Core_CustomObstacleData_customDataGet(CustomObstacleData self) {
    
    return _core_custom_obstacle_data__custom_data_get(self);
}

BeatmapDataItem Core_CustomObstacleData_getCopy(CustomObstacleData self) {
    
    return _core_custom_obstacle_data__get_copy(self);
}

Version Core_CustomObstacleData_versionGet(CustomObstacleData self) {
    
    return _core_custom_obstacle_data__version_get(self);
}

Component Core_GameObject_addComponent(GameObject self
, Type component_type) {
    
    return _core_game_object__add_component(self, component_type);
}

TuringMesh Core_GameObject_addOrGetMesh(GameObject self) {
    
    return _core_game_object__add_or_get_mesh(self);
}

void Core_GameObject_broadcastMessage(GameObject self
, const char* method_name
, int32_t options) {
    
    _core_game_object__broadcast_message(self, method_name, options);
}

bool Core_GameObject_compareTag(GameObject self
, const char* tag) {
    
    return _core_game_object__compare_tag(self, tag);
}

bool Core_GameObject_getActive(GameObject self) {
    
    return _core_game_object__get_active(self);
}

bool Core_GameObject_getActiveInHierarchy(GameObject self) {
    
    return _core_game_object__get_active_in_hierarchy(self);
}

bool Core_GameObject_getActiveSelf(GameObject self) {
    
    return _core_game_object__get_active_self(self);
}

Component Core_GameObject_getComponentAtIndex(GameObject self
, int32_t index) {
    
    return _core_game_object__get_component_at_index(self, index);
}

Component Core_GameObject_getComponentByName(GameObject self
, const char* cs_type) {
    
    return _core_game_object__get_component_by_name(self, cs_type);
}

Component Core_GameObject_getComponentByType(GameObject self
, Type cs_type) {
    
    return _core_game_object__get_component_by_type(self, cs_type);
}

int32_t Core_GameObject_getComponentCount(GameObject self) {
    
    return _core_game_object__get_component_count(self);
}

Component Core_GameObject_getComponentInChildrenByType(GameObject self
, Type cs_type
, bool include_inactive) {
    
    return _core_game_object__get_component_in_children_by_type(self, cs_type, include_inactive);
}

Component Core_GameObject_getComponentInParentByType(GameObject self
, Type cs_type
, bool include_inactive) {
    
    return _core_game_object__get_component_in_parent_by_type(self, cs_type, include_inactive);
}

int32_t Core_GameObject_getComponentIndex(GameObject self
, Component component) {
    
    return _core_game_object__get_component_index(self, component);
}

int32_t Core_GameObject_getHideFlags(GameObject self) {
    
    return _core_game_object__get_hide_flags(self);
}

int32_t Core_GameObject_getInstanceId(GameObject self) {
    
    return _core_game_object__get_instance_id(self);
}

bool Core_GameObject_getIsStatic(GameObject self) {
    
    return _core_game_object__get_is_static(self);
}

int32_t Core_GameObject_getLayer(GameObject self) {
    
    return _core_game_object__get_layer(self);
}

char* Core_GameObject_getName(GameObject self) {
    
    uint32_t turing_result = _core_game_object__get_name(self);
    char* turing_str = (char*) malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

uint64_t Core_GameObject_getSceneCullingMask(GameObject self) {
    
    return _core_game_object__get_scene_culling_mask(self);
}

char* Core_GameObject_getTag(GameObject self) {
    
    uint32_t turing_result = _core_game_object__get_tag(self);
    char* turing_str = (char*) malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

Transform Core_GameObject_getTransform(GameObject self) {
    
    return _core_game_object__get_transform(self);
}

void Core_GameObject_sendMessage(GameObject self
, const char* method_name
, int32_t options) {
    
    _core_game_object__send_message(self, method_name, options);
}

void Core_GameObject_sendMessageUpwards(GameObject self
, const char* method_name
, int32_t options) {
    
    _core_game_object__send_message_upwards(self, method_name, options);
}

void Core_GameObject_setActive(GameObject self
, bool value) {
    
    _core_game_object__set_active(self, value);
}

void Core_GameObject_setActiveProp(GameObject self
, bool value) {
    
    _core_game_object__set_active_prop(self, value);
}

void Core_GameObject_setActiveRecursively(GameObject self
, bool state) {
    
    _core_game_object__set_active_recursively(self, state);
}

void Core_GameObject_setHideFlags(GameObject self
, int32_t value) {
    
    _core_game_object__set_hide_flags(self, value);
}

void Core_GameObject_setIsStatic(GameObject self
, bool value) {
    
    _core_game_object__set_is_static(self, value);
}

void Core_GameObject_setLayer(GameObject self
, int32_t value) {
    
    _core_game_object__set_layer(self, value);
}

void Core_GameObject_setName(GameObject self
, const char* value) {
    
    _core_game_object__set_name(self, value);
}

void Core_GameObject_setTag(GameObject self
, const char* value) {
    
    _core_game_object__set_tag(self, value);
}

GCHelper Core_GcHelper_create() {
    
    return _core_gc_helper__create();
}

void Core_GcHelper_dispose(GcHelper self) {
    
    _core_gc_helper__dispose(self);
}

void Core_GcHelper_invalidateAllHandles(GcHelper self) {
    
    _core_gc_helper__invalidate_all_handles(self);
}

void Core_GcHelper_wasmGarbageCollect(GcHelper self) {
    
    _core_gc_helper__wasm_garbage_collect(self);
}

void Core_Log_critical(const char* msg) {
    
    _core_log__critical(msg);
}

void Core_Log_debug(const char* msg) {
    
    _core_log__debug(msg);
}

void Core_Log_info(const char* msg) {
    
    _core_log__info(msg);
}

void Core_Log_warn(const char* msg) {
    
    _core_log__warn(msg);
}

IAudioTimeSource Core_NoteFloorMovement_AudioTimeSyncControllerGet(NoteFloorMovement self) {
    
    return _core_note_floor_movement___audio_time_sync_controller_get(self);
}

float Core_NoteFloorMovement_BeatTimeGet(NoteFloorMovement self) {
    
    return _core_note_floor_movement___beat_time_get(self);
}

void Core_NoteFloorMovement_BeatTimeSet(NoteFloorMovement self
, float value) {
    
    _core_note_floor_movement___beat_time_set(self, value);
}

versors Core_NoteFloorMovement_InverseWorldRotationGet(NoteFloorMovement self) {
    
    _core_note_floor_movement___inverse_world_rotation_get(self);
    return alg::__dequeue_quat();
}

void Core_NoteFloorMovement_InverseWorldRotationSet(NoteFloorMovement self
, versors value) {
    uint32_t turing_handle_value = alg::__enqueue_quat(value);
    _core_note_floor_movement___inverse_world_rotation_set(self, turing_handle_value);
}

vec3s Core_NoteFloorMovement_LocalPositionGet(NoteFloorMovement self) {
    
    _core_note_floor_movement___local_position_get(self);
    return alg::__dequeue_vec3();
}

void Core_NoteFloorMovement_LocalPositionSet(NoteFloorMovement self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_note_floor_movement___local_position_set(self, turing_handle_value);
}

vec3s Core_NoteFloorMovement_MoveEndOffsetGet(NoteFloorMovement self) {
    
    _core_note_floor_movement___move_end_offset_get(self);
    return alg::__dequeue_vec3();
}

void Core_NoteFloorMovement_MoveEndOffsetSet(NoteFloorMovement self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_note_floor_movement___move_end_offset_set(self, turing_handle_value);
}

vec3s Core_NoteFloorMovement_MoveStartOffsetGet(NoteFloorMovement self) {
    
    _core_note_floor_movement___move_start_offset_get(self);
    return alg::__dequeue_vec3();
}

void Core_NoteFloorMovement_MoveStartOffsetSet(NoteFloorMovement self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_note_floor_movement___move_start_offset_set(self, turing_handle_value);
}

PlayerTransforms Core_NoteFloorMovement_PlayerTransformsGet(NoteFloorMovement self) {
    
    return _core_note_floor_movement___player_transforms_get(self);
}

Transform Core_NoteFloorMovement_RotatedObjectGet(NoteFloorMovement self) {
    
    return _core_note_floor_movement___rotated_object_get(self);
}

void Core_NoteFloorMovement_RotatedObjectSet(NoteFloorMovement self
, Transform value) {
    
    _core_note_floor_movement___rotated_object_set(self, value);
}

IVariableMovementDataProvider Core_NoteFloorMovement_VariableMovementDataProviderGet(NoteFloorMovement self) {
    
    return _core_note_floor_movement___variable_movement_data_provider_get(self);
}

versors Core_NoteFloorMovement_WorldRotationGet(NoteFloorMovement self) {
    
    _core_note_floor_movement___world_rotation_get(self);
    return alg::__dequeue_quat();
}

void Core_NoteFloorMovement_WorldRotationSet(NoteFloorMovement self
, versors value) {
    uint32_t turing_handle_value = alg::__enqueue_quat(value);
    _core_note_floor_movement___world_rotation_set(self, turing_handle_value);
}

float Core_NoteFloorMovement_distanceToPlayerGet(NoteFloorMovement self) {
    
    return _core_note_floor_movement__distance_to_player_get(self);
}

vec3s Core_NoteFloorMovement_endPosGet(NoteFloorMovement self) {
    
    _core_note_floor_movement__end_pos_get(self);
    return alg::__dequeue_vec3();
}

void Core_NoteFloorMovement_initFloor(NoteFloorMovement self
, float world_rotation
, float beat_time
, vec3s move_start_offset
, vec3s move_end_offset) {
    uint32_t turing_handle_move_start_offset = alg::__enqueue_vec3(move_start_offset);uint32_t turing_handle_move_end_offset = alg::__enqueue_vec3(move_end_offset);
    _core_note_floor_movement__init(self, world_rotation, beat_time, turing_handle_move_start_offset, turing_handle_move_end_offset);
}

versors Core_NoteFloorMovement_inverseWorldRotationGet(NoteFloorMovement self) {
    
    _core_note_floor_movement__inverse_world_rotation_get(self);
    return alg::__dequeue_quat();
}

vec3s Core_NoteFloorMovement_localPositionGet(NoteFloorMovement self) {
    
    _core_note_floor_movement__local_position_get(self);
    return alg::__dequeue_vec3();
}

vec3s Core_NoteFloorMovement_manualUpdate(NoteFloorMovement self) {
    
    _core_note_floor_movement__manual_update(self);
    return alg::__dequeue_vec3();
}

float Core_NoteFloorMovement_noteTimeGet(NoteFloorMovement self) {
    
    return _core_note_floor_movement__note_time_get(self);
}

vec3s Core_NoteFloorMovement_setToStart(NoteFloorMovement self) {
    
    _core_note_floor_movement__set_to_start(self);
    return alg::__dequeue_vec3();
}

bool Core_NoteFloorMovement_shouldMove(NoteFloorMovement self) {
    
    return _core_note_floor_movement__should_move(self);
}

versors Core_NoteFloorMovement_worldRotationGet(NoteFloorMovement self) {
    
    _core_note_floor_movement__world_rotation_get(self);
    return alg::__dequeue_quat();
}

float Core_NoteJump_kMissedTimeOffsetGet() {
    
    return _core_note_jump__k_missed_time_offset_get();
}

IAudioTimeSource Core_NoteJump_AudioTimeSyncControllerGet(NoteJump self) {
    
    return _core_note_jump___audio_time_sync_controller_get(self);
}

float Core_NoteJump_EndDistanceOffsetGet(NoteJump self) {
    
    return _core_note_jump___end_distance_offset_get(self);
}

void Core_NoteJump_EndDistanceOffsetSet(NoteJump self
, float value) {
    
    _core_note_jump___end_distance_offset_set(self, value);
}

vec3s Core_NoteJump_EndOffsetGet(NoteJump self) {
    
    _core_note_jump___end_offset_get(self);
    return alg::__dequeue_vec3();
}

void Core_NoteJump_EndOffsetSet(NoteJump self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_note_jump___end_offset_set(self, turing_handle_value);
}

vec3s Core_NoteJump_EndPosGet(NoteJump self) {
    
    _core_note_jump___end_pos_get(self);
    return alg::__dequeue_vec3();
}

void Core_NoteJump_EndPosSet(NoteJump self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_note_jump___end_pos_set(self, turing_handle_value);
}

versors Core_NoteJump_EndRotationGet(NoteJump self) {
    
    _core_note_jump___end_rotation_get(self);
    return alg::__dequeue_quat();
}

void Core_NoteJump_EndRotationSet(NoteJump self
, versors value) {
    uint32_t turing_handle_value = alg::__enqueue_quat(value);
    _core_note_jump___end_rotation_set(self, turing_handle_value);
}

float Core_NoteJump_GravityBaseGet(NoteJump self) {
    
    return _core_note_jump___gravity_base_get(self);
}

void Core_NoteJump_GravityBaseSet(NoteJump self
, float value) {
    
    _core_note_jump___gravity_base_set(self, value);
}

float Core_NoteJump_GravityGet(NoteJump self) {
    
    return _core_note_jump___gravity_get(self);
}

void Core_NoteJump_GravitySet(NoteJump self
, float value) {
    
    _core_note_jump___gravity_set(self, value);
}

float Core_NoteJump_HalfJumpDurationGet(NoteJump self) {
    
    return _core_note_jump___half_jump_duration_get(self);
}

void Core_NoteJump_HalfJumpDurationSet(NoteJump self
, float value) {
    
    _core_note_jump___half_jump_duration_set(self, value);
}

bool Core_NoteJump_HalfJumpMarkReportedGet(NoteJump self) {
    
    return _core_note_jump___half_jump_mark_reported_get(self);
}

void Core_NoteJump_HalfJumpMarkReportedSet(NoteJump self
, bool value) {
    
    _core_note_jump___half_jump_mark_reported_set(self, value);
}

versors Core_NoteJump_InverseWorldRotationGet(NoteJump self) {
    
    _core_note_jump___inverse_world_rotation_get(self);
    return alg::__dequeue_quat();
}

void Core_NoteJump_InverseWorldRotationSet(NoteJump self
, versors value) {
    uint32_t turing_handle_value = alg::__enqueue_quat(value);
    _core_note_jump___inverse_world_rotation_set(self, turing_handle_value);
}

float Core_NoteJump_JumpDurationGet(NoteJump self) {
    
    return _core_note_jump___jump_duration_get(self);
}

void Core_NoteJump_JumpDurationSet(NoteJump self
, float value) {
    
    _core_note_jump___jump_duration_set(self, value);
}

bool Core_NoteJump_JumpStartedReportedGet(NoteJump self) {
    
    return _core_note_jump___jump_started_reported_get(self);
}

void Core_NoteJump_JumpStartedReportedSet(NoteJump self
, bool value) {
    
    _core_note_jump___jump_started_reported_set(self, value);
}

vec3s Core_NoteJump_LocalPositionGet(NoteJump self) {
    
    _core_note_jump___local_position_get(self);
    return alg::__dequeue_vec3();
}

void Core_NoteJump_LocalPositionSet(NoteJump self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_note_jump___local_position_set(self, turing_handle_value);
}

versors Core_NoteJump_MiddleRotationGet(NoteJump self) {
    
    _core_note_jump___middle_rotation_get(self);
    return alg::__dequeue_quat();
}

void Core_NoteJump_MiddleRotationSet(NoteJump self
, versors value) {
    uint32_t turing_handle_value = alg::__enqueue_quat(value);
    _core_note_jump___middle_rotation_set(self, turing_handle_value);
}

bool Core_NoteJump_MissedMarkReportedGet(NoteJump self) {
    
    return _core_note_jump___missed_mark_reported_get(self);
}

void Core_NoteJump_MissedMarkReportedSet(NoteJump self
, bool value) {
    
    _core_note_jump___missed_mark_reported_set(self, value);
}

float Core_NoteJump_MissedTimeGet(NoteJump self) {
    
    return _core_note_jump___missed_time_get(self);
}

void Core_NoteJump_MissedTimeSet(NoteJump self
, float value) {
    
    _core_note_jump___missed_time_set(self, value);
}

float Core_NoteJump_NoteTimeGet(NoteJump self) {
    
    return _core_note_jump___note_time_get(self);
}

void Core_NoteJump_NoteTimeSet(NoteJump self
, float value) {
    
    _core_note_jump___note_time_set(self, value);
}

PlayerSpaceConvertor Core_NoteJump_PlayerSpaceConvertorGet(NoteJump self) {
    
    return _core_note_jump___player_space_convertor_get(self);
}

PlayerTransforms Core_NoteJump_PlayerTransformsGet(NoteJump self) {
    
    return _core_note_jump___player_transforms_get(self);
}

bool Core_NoteJump_RotateTowardsPlayerGet(NoteJump self) {
    
    return _core_note_jump___rotate_towards_player_get(self);
}

void Core_NoteJump_RotateTowardsPlayerSet(NoteJump self
, bool value) {
    
    _core_note_jump___rotate_towards_player_set(self, value);
}

Transform Core_NoteJump_RotatedObjectGet(NoteJump self) {
    
    return _core_note_jump___rotated_object_get(self);
}

void Core_NoteJump_RotatedObjectSet(NoteJump self
, Transform value) {
    
    _core_note_jump___rotated_object_set(self, value);
}

vec3s Core_NoteJump_StartOffsetGet(NoteJump self) {
    
    _core_note_jump___start_offset_get(self);
    return alg::__dequeue_vec3();
}

void Core_NoteJump_StartOffsetSet(NoteJump self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_note_jump___start_offset_set(self, turing_handle_value);
}

vec3s Core_NoteJump_StartPosGet(NoteJump self) {
    
    _core_note_jump___start_pos_get(self);
    return alg::__dequeue_vec3();
}

void Core_NoteJump_StartPosSet(NoteJump self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_note_jump___start_pos_set(self, turing_handle_value);
}

versors Core_NoteJump_StartRotationGet(NoteJump self) {
    
    _core_note_jump___start_rotation_get(self);
    return alg::__dequeue_quat();
}

void Core_NoteJump_StartRotationSet(NoteJump self
, versors value) {
    uint32_t turing_handle_value = alg::__enqueue_quat(value);
    _core_note_jump___start_rotation_set(self, turing_handle_value);
}

bool Core_NoteJump_ThreeQuartersMarkReportedGet(NoteJump self) {
    
    return _core_note_jump___three_quarters_mark_reported_get(self);
}

void Core_NoteJump_ThreeQuartersMarkReportedSet(NoteJump self
, bool value) {
    
    _core_note_jump___three_quarters_mark_reported_set(self, value);
}

IVariableMovementDataProvider Core_NoteJump_VariableMovementDataProviderGet(NoteJump self) {
    
    return _core_note_jump___variable_movement_data_provider_get(self);
}

versors Core_NoteJump_WorldRotationGet(NoteJump self) {
    
    _core_note_jump___world_rotation_get(self);
    return alg::__dequeue_quat();
}

void Core_NoteJump_WorldRotationSet(NoteJump self
, versors value) {
    uint32_t turing_handle_value = alg::__enqueue_quat(value);
    _core_note_jump___world_rotation_set(self, turing_handle_value);
}

float Core_NoteJump_YAvoidanceDownGet(NoteJump self) {
    
    return _core_note_jump___y_avoidance_down_get(self);
}

void Core_NoteJump_YAvoidanceDownSet(NoteJump self
, float value) {
    
    _core_note_jump___y_avoidance_down_set(self, value);
}

float Core_NoteJump_YAvoidanceGet(NoteJump self) {
    
    return _core_note_jump___y_avoidance_get(self);
}

void Core_NoteJump_YAvoidanceSet(NoteJump self
, float value) {
    
    _core_note_jump___y_avoidance_set(self, value);
}

float Core_NoteJump_YAvoidanceUpGet(NoteJump self) {
    
    return _core_note_jump___y_avoidance_up_get(self);
}

void Core_NoteJump_YAvoidanceUpSet(NoteJump self
, float value) {
    
    _core_note_jump___y_avoidance_up_set(self, value);
}

void Core_NoteJump_addNoteJumpDidFinishEvent(NoteJump self
, Action value) {
    
    _core_note_jump__add_note_jump_did_finish_event(self, value);
}

void Core_NoteJump_addNoteJumpDidPassHalfEvent(NoteJump self
, Action value) {
    
    _core_note_jump__add_note_jump_did_pass_half_event(self, value);
}

void Core_NoteJump_addNoteJumpDidPassMissedMarkerEvent(NoteJump self
, Action value) {
    
    _core_note_jump__add_note_jump_did_pass_missed_marker_event(self, value);
}

void Core_NoteJump_addNoteJumpDidPassThreeQuartersEvent(NoteJump self
, Action1 value) {
    
    _core_note_jump__add_note_jump_did_pass_three_quarters_event(self, value);
}

void Core_NoteJump_addNoteJumpDidStartEvent(NoteJump self
, Action value) {
    
    _core_note_jump__add_note_jump_did_start_event(self, value);
}

void Core_NoteJump_addNoteJumpDidUpdateProgressEvent(NoteJump self
, Action1 value) {
    
    _core_note_jump__add_note_jump_did_update_progress_event(self, value);
}

vec3s Core_NoteJump_beatPosGet(NoteJump self) {
    
    _core_note_jump__beat_pos_get(self);
    return alg::__dequeue_vec3();
}

float Core_NoteJump_distanceToPlayerGet(NoteJump self) {
    
    return _core_note_jump__distance_to_player_get(self);
}

void Core_NoteJump_initJump(NoteJump self
, float note_time
, float world_rotation
, vec3s move_end_offset
, vec3s jump_end_offset
, float gravity_base
, float flip_y_side
, float end_rotation
, bool rotate_towards_player
, bool use_random_rotation) {
    uint32_t turing_handle_move_end_offset = alg::__enqueue_vec3(move_end_offset);uint32_t turing_handle_jump_end_offset = alg::__enqueue_vec3(jump_end_offset);
    _core_note_jump__init(self, note_time, world_rotation, turing_handle_move_end_offset, turing_handle_jump_end_offset, gravity_base, flip_y_side, end_rotation, rotate_towards_player, use_random_rotation);
}

vec3s Core_NoteJump_localPositionGet(NoteJump self) {
    
    _core_note_jump__local_position_get(self);
    return alg::__dequeue_vec3();
}

vec3s Core_NoteJump_manualUpdate(NoteJump self) {
    
    _core_note_jump__manual_update(self);
    return alg::__dequeue_vec3();
}

vec3s Core_NoteJump_moveVecGet(NoteJump self) {
    
    _core_note_jump__move_vec_get(self);
    return alg::__dequeue_vec3();
}

float Core_NoteJump_noteTimeGet(NoteJump self) {
    
    return _core_note_jump__note_time_get(self);
}

void Core_NoteJump_removeNoteJumpDidFinishEvent(NoteJump self
, Action value) {
    
    _core_note_jump__remove_note_jump_did_finish_event(self, value);
}

void Core_NoteJump_removeNoteJumpDidPassHalfEvent(NoteJump self
, Action value) {
    
    _core_note_jump__remove_note_jump_did_pass_half_event(self, value);
}

void Core_NoteJump_removeNoteJumpDidPassMissedMarkerEvent(NoteJump self
, Action value) {
    
    _core_note_jump__remove_note_jump_did_pass_missed_marker_event(self, value);
}

void Core_NoteJump_removeNoteJumpDidPassThreeQuartersEvent(NoteJump self
, Action1 value) {
    
    _core_note_jump__remove_note_jump_did_pass_three_quarters_event(self, value);
}

void Core_NoteJump_removeNoteJumpDidStartEvent(NoteJump self
, Action value) {
    
    _core_note_jump__remove_note_jump_did_start_event(self, value);
}

void Core_NoteJump_removeNoteJumpDidUpdateProgressEvent(NoteJump self
, Action1 value) {
    
    _core_note_jump__remove_note_jump_did_update_progress_event(self, value);
}

CustomNoteData Core_NoteManager_addBombNote(float beat, int32_t line, int32_t layer, CustomData custom_data) {
    
    return _core_note_manager__add_bomb_note(beat, line, layer, custom_data);
}

CustomNoteData Core_NoteManager_addColorNote(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data) {
    
    return _core_note_manager__add_color_note(beat, line, layer, color, cut_direction, custom_data);
}

CustomObstacleData Core_NoteManager_addObstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data) {
    
    return _core_note_manager__add_obstacle(beat, duration, line, layer, width, height, custom_data);
}

NoteControllerBase Core_NoteManager_getNoteController(int32_t n) {
    
    return _core_note_manager__get_note_controller(n);
}

NoteControllerBase Core_NoteManager_getNoteControllerFromCustom(CustomNoteData n) {
    
    return _core_note_manager__get_note_controller_from_custom(n);
}

CustomEventData Core_NoteManager_getNthEvent(int32_t id) {
    
    return _core_note_manager__get_nth_event(id);
}

CustomNoteData Core_NoteManager_getNthNote(int32_t id) {
    
    return _core_note_manager__get_nth_note(id);
}

BeatmapDataItem Core_NoteManager_getNthObject(int32_t id) {
    
    return _core_note_manager__get_nth_object(id);
}

CustomObstacleData Core_NoteManager_getNthObstacle(int32_t id) {
    
    return _core_note_manager__get_nth_obstacle(id);
}

ObstacleControllerBase Core_NoteManager_getObstacleController(int32_t n) {
    
    return _core_note_manager__get_obstacle_controller(n);
}

ObstacleController Core_NoteManager_getObstacleControllerFromCustom(CustomObstacleData n) {
    
    return _core_note_manager__get_obstacle_controller_from_custom(n);
}

float Core_NoteManager_timeToBeat(float time) {
    
    return _core_note_manager__time_to_beat(time);
}

void Core_TaskScheduler_schedule(Action task) {
    
    _core_task_scheduler__schedule(task);
}

void Core_TaskScheduler_dispose(TaskScheduler self) {
    
    _core_task_scheduler__dispose(self);
}

void Core_Transform_broadcastMessage(Transform self
, const char* method_name
, Object parameter
, int32_t options) {
    
    _core_transform__broadcast_message(self, method_name, parameter, options);
}

bool Core_Transform_compareTag(Transform self
, const char* tag) {
    
    return _core_transform__compare_tag(self, tag);
}

void Core_Transform_detachChildren(Transform self) {
    
    _core_transform__detach_children(self);
}

Transform Core_Transform_find(Transform self
, const char* n) {
    
    return _core_transform__find(self, n);
}

Transform Core_Transform_findChild(Transform self
, const char* n) {
    
    return _core_transform__find_child(self, n);
}

Transform Core_Transform_getChild(Transform self
, int32_t index) {
    
    return _core_transform__get_child(self, index);
}

int32_t Core_Transform_getChildCount(Transform self) {
    
    return _core_transform__get_child_count(self);
}

int32_t Core_Transform_getChildCountProp(Transform self) {
    
    return _core_transform__get_child_count_prop(self);
}

Component Core_Transform_getComponentByName(Transform self
, const char* cs_type) {
    
    return _core_transform__get_component_by_name(self, cs_type);
}

Component Core_Transform_getComponentByType(Transform self
, Type cs_type) {
    
    return _core_transform__get_component_by_type(self, cs_type);
}

Component Core_Transform_getComponentInChildrenByType(Transform self
, Type t
, bool include_inactive) {
    
    return _core_transform__get_component_in_children_by_type(self, t, include_inactive);
}

Component Core_Transform_getComponentInParentByType(Transform self
, Type t
, bool include_inactive) {
    
    return _core_transform__get_component_in_parent_by_type(self, t, include_inactive);
}

int32_t Core_Transform_getComponentIndex(Transform self) {
    
    return _core_transform__get_component_index(self);
}

IEnumerator Core_Transform_getEnumerator(Transform self) {
    
    return _core_transform__get_enumerator(self);
}

vec3s Core_Transform_getEulerAngles(Transform self) {
    
    _core_transform__get_euler_angles(self);
    return alg::__dequeue_vec3();
}

vec3s Core_Transform_getForward(Transform self) {
    
    _core_transform__get_forward(self);
    return alg::__dequeue_vec3();
}

GameObject Core_Transform_getGameObject(Transform self) {
    
    return _core_transform__get_game_object(self);
}

bool Core_Transform_getHasChanged(Transform self) {
    
    return _core_transform__get_has_changed(self);
}

int32_t Core_Transform_getHideFlags(Transform self) {
    
    return _core_transform__get_hide_flags(self);
}

int32_t Core_Transform_getHierarchyCapacity(Transform self) {
    
    return _core_transform__get_hierarchy_capacity(self);
}

int32_t Core_Transform_getHierarchyCount(Transform self) {
    
    return _core_transform__get_hierarchy_count(self);
}

int32_t Core_Transform_getInstanceId(Transform self) {
    
    return _core_transform__get_instance_id(self);
}

vec3s Core_Transform_getLocalEulerAngles(Transform self) {
    
    _core_transform__get_local_euler_angles(self);
    return alg::__dequeue_vec3();
}

vec3s Core_Transform_getLocalPosition(Transform self) {
    
    _core_transform__get_local_position(self);
    return alg::__dequeue_vec3();
}

versors Core_Transform_getLocalRotation(Transform self) {
    
    _core_transform__get_local_rotation(self);
    return alg::__dequeue_quat();
}

vec3s Core_Transform_getLocalScale(Transform self) {
    
    _core_transform__get_local_scale(self);
    return alg::__dequeue_vec3();
}

mat4s Core_Transform_getLocalToWorldMatrix(Transform self) {
    
    _core_transform__get_local_to_world_matrix(self);
    return alg::__dequeue_mat4();
}

vec3s Core_Transform_getLossyScale(Transform self) {
    
    _core_transform__get_lossy_scale(self);
    return alg::__dequeue_vec3();
}

char* Core_Transform_getName(Transform self) {
    
    uint32_t turing_result = _core_transform__get_name(self);
    char* turing_str = (char*) malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

Transform Core_Transform_getParent(Transform self) {
    
    return _core_transform__get_parent(self);
}

vec3s Core_Transform_getPosition(Transform self) {
    
    _core_transform__get_position(self);
    return alg::__dequeue_vec3();
}

vec3s Core_Transform_getRight(Transform self) {
    
    _core_transform__get_right(self);
    return alg::__dequeue_vec3();
}

Transform Core_Transform_getRoot(Transform self) {
    
    return _core_transform__get_root(self);
}

versors Core_Transform_getRotation(Transform self) {
    
    _core_transform__get_rotation(self);
    return alg::__dequeue_quat();
}

int32_t Core_Transform_getSiblingIndex(Transform self) {
    
    return _core_transform__get_sibling_index(self);
}

char* Core_Transform_getTag(Transform self) {
    
    uint32_t turing_result = _core_transform__get_tag(self);
    char* turing_str = (char*) malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

vec3s Core_Transform_getUp(Transform self) {
    
    _core_transform__get_up(self);
    return alg::__dequeue_vec3();
}

mat4s Core_Transform_getWorldToLocalMatrix(Transform self) {
    
    _core_transform__get_world_to_local_matrix(self);
    return alg::__dequeue_mat4();
}

vec3s Core_Transform_inverseTransformDirection(Transform self
, vec3s direction) {
    uint32_t turing_handle_direction = alg::__enqueue_vec3(direction);
    _core_transform__inverse_transform_direction(self, turing_handle_direction);
    return alg::__dequeue_vec3();
}

vec3s Core_Transform_inverseTransformPoint(Transform self
, vec3s position) {
    uint32_t turing_handle_position = alg::__enqueue_vec3(position);
    _core_transform__inverse_transform_point(self, turing_handle_position);
    return alg::__dequeue_vec3();
}

vec3s Core_Transform_inverseTransformVector(Transform self
, vec3s vector) {
    uint32_t turing_handle_vector = alg::__enqueue_vec3(vector);
    _core_transform__inverse_transform_vector(self, turing_handle_vector);
    return alg::__dequeue_vec3();
}

bool Core_Transform_isChildOf(Transform self
, Transform parent) {
    
    return _core_transform__is_child_of(self, parent);
}

void Core_Transform_lookAt(Transform self
, Transform target
, vec3s world_up) {
    uint32_t turing_handle_world_up = alg::__enqueue_vec3(world_up);
    _core_transform__look_at(self, target, turing_handle_world_up);
}

void Core_Transform_rotate(Transform self
, vec3s eulers) {
    uint32_t turing_handle_eulers = alg::__enqueue_vec3(eulers);
    _core_transform__rotate(self, turing_handle_eulers);
}

void Core_Transform_rotateAround(Transform self
, vec3s point
, vec3s axis
, float angle) {
    uint32_t turing_handle_point = alg::__enqueue_vec3(point);uint32_t turing_handle_axis = alg::__enqueue_vec3(axis);
    _core_transform__rotate_around(self, turing_handle_point, turing_handle_axis, angle);
}

void Core_Transform_rotateAroundLocal(Transform self
, vec3s axis
, float angle) {
    uint32_t turing_handle_axis = alg::__enqueue_vec3(axis);
    _core_transform__rotate_around_local(self, turing_handle_axis, angle);
}

void Core_Transform_rotateRelative(Transform self
, vec3s eulers
, int32_t relative_to) {
    uint32_t turing_handle_eulers = alg::__enqueue_vec3(eulers);
    _core_transform__rotate_relative(self, turing_handle_eulers, relative_to);
}

void Core_Transform_sendMessage(Transform self
, const char* method_name
, Object value
, int32_t options) {
    
    _core_transform__send_message(self, method_name, value, options);
}

void Core_Transform_sendMessageUpwards(Transform self
, const char* method_name
, Object value
, int32_t options) {
    
    _core_transform__send_message_upwards(self, method_name, value, options);
}

void Core_Transform_setAsFirstSibling(Transform self) {
    
    _core_transform__set_as_first_sibling(self);
}

void Core_Transform_setAsLastSibling(Transform self) {
    
    _core_transform__set_as_last_sibling(self);
}

void Core_Transform_setEulerAngles(Transform self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_transform__set_euler_angles(self, turing_handle_value);
}

void Core_Transform_setForward(Transform self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_transform__set_forward(self, turing_handle_value);
}

void Core_Transform_setHasChanged(Transform self
, bool value) {
    
    _core_transform__set_has_changed(self, value);
}

void Core_Transform_setHideFlags(Transform self
, int32_t value) {
    
    _core_transform__set_hide_flags(self, value);
}

void Core_Transform_setHierarchyCapacity(Transform self
, int32_t value) {
    
    _core_transform__set_hierarchy_capacity(self, value);
}

void Core_Transform_setLocalEulerAngles(Transform self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_transform__set_local_euler_angles(self, turing_handle_value);
}

void Core_Transform_setLocalPosition(Transform self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_transform__set_local_position(self, turing_handle_value);
}

void Core_Transform_setLocalPositionAndRotation(Transform self
, vec3s local_position
, versors local_rotation) {
    uint32_t turing_handle_local_position = alg::__enqueue_vec3(local_position);uint32_t turing_handle_local_rotation = alg::__enqueue_quat(local_rotation);
    _core_transform__set_local_position_and_rotation(self, turing_handle_local_position, turing_handle_local_rotation);
}

void Core_Transform_setLocalRotation(Transform self
, versors value) {
    uint32_t turing_handle_value = alg::__enqueue_quat(value);
    _core_transform__set_local_rotation(self, turing_handle_value);
}

void Core_Transform_setLocalScale(Transform self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_transform__set_local_scale(self, turing_handle_value);
}

void Core_Transform_setName(Transform self
, const char* value) {
    
    _core_transform__set_name(self, value);
}

void Core_Transform_setParent(Transform self
, Transform parent
, bool world_position_stays) {
    
    _core_transform__set_parent(self, parent, world_position_stays);
}

void Core_Transform_setPosition(Transform self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_transform__set_position(self, turing_handle_value);
}

void Core_Transform_setPositionAndRotation(Transform self
, vec3s position
, versors rotation) {
    uint32_t turing_handle_position = alg::__enqueue_vec3(position);uint32_t turing_handle_rotation = alg::__enqueue_quat(rotation);
    _core_transform__set_position_and_rotation(self, turing_handle_position, turing_handle_rotation);
}

void Core_Transform_setRight(Transform self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_transform__set_right(self, turing_handle_value);
}

void Core_Transform_setRotation(Transform self
, versors value) {
    uint32_t turing_handle_value = alg::__enqueue_quat(value);
    _core_transform__set_rotation(self, turing_handle_value);
}

void Core_Transform_setSiblingIndex(Transform self
, int32_t index) {
    
    _core_transform__set_sibling_index(self, index);
}

void Core_Transform_setTag(Transform self
, const char* value) {
    
    _core_transform__set_tag(self, value);
}

void Core_Transform_setUp(Transform self
, vec3s value) {
    uint32_t turing_handle_value = alg::__enqueue_vec3(value);
    _core_transform__set_up(self, turing_handle_value);
}

vec3s Core_Transform_transformDirection(Transform self
, vec3s direction) {
    uint32_t turing_handle_direction = alg::__enqueue_vec3(direction);
    _core_transform__transform_direction(self, turing_handle_direction);
    return alg::__dequeue_vec3();
}

vec3s Core_Transform_transformPoint(Transform self
, vec3s position) {
    uint32_t turing_handle_position = alg::__enqueue_vec3(position);
    _core_transform__transform_point(self, turing_handle_position);
    return alg::__dequeue_vec3();
}

vec3s Core_Transform_transformVector(Transform self
, vec3s vector) {
    uint32_t turing_handle_vector = alg::__enqueue_vec3(vector);
    _core_transform__transform_vector(self, turing_handle_vector);
    return alg::__dequeue_vec3();
}

void Core_Transform_translate(Transform self
, vec3s translation
, int32_t relative_to) {
    uint32_t turing_handle_translation = alg::__enqueue_vec3(translation);
    _core_transform__translate(self, turing_handle_translation, relative_to);
}

void Core_Transform_translateRelative(Transform self
, vec3s translation
, Transform relative_to) {
    uint32_t turing_handle_translation = alg::__enqueue_vec3(translation);
    _core_transform__translate_relative(self, turing_handle_translation, relative_to);
}

Mesh Core_TuringMesh_MeshGet(TuringMesh self) {
    
    return _core_turing_mesh___mesh_get(self);
}

void Core_TuringMesh_MeshSet(TuringMesh self
, Mesh value) {
    
    _core_turing_mesh___mesh_set(self, value);
}

void Core_TuringMesh_clear(TuringMesh self) {
    
    _core_turing_mesh__clear(self);
}

float Core_TuringMesh_getBoundsMaxX(TuringMesh self) {
    
    return _core_turing_mesh__get_bounds_max_x(self);
}

float Core_TuringMesh_getBoundsMaxY(TuringMesh self) {
    
    return _core_turing_mesh__get_bounds_max_y(self);
}

float Core_TuringMesh_getBoundsMaxZ(TuringMesh self) {
    
    return _core_turing_mesh__get_bounds_max_z(self);
}

float Core_TuringMesh_getBoundsMinX(TuringMesh self) {
    
    return _core_turing_mesh__get_bounds_min_x(self);
}

float Core_TuringMesh_getBoundsMinY(TuringMesh self) {
    
    return _core_turing_mesh__get_bounds_min_y(self);
}

float Core_TuringMesh_getBoundsMinZ(TuringMesh self) {
    
    return _core_turing_mesh__get_bounds_min_z(self);
}

int32_t Core_TuringMesh_getInstanceId(TuringMesh self) {
    
    return _core_turing_mesh__get_instance_id(self);
}

U32Buffer Core_TuringMesh_getUVs(TuringMesh self
, int32_t channel) {
    
    uint32_t turing_result = _core_turing_mesh__get_u_vs(self, channel);
    uint32_t turing_buf = (uint32_t) malloc((size_t) turing_result * 4);
    _host_bufcpy(turing_buf, turing_result);
    return (U32Buffer){ .data=turing_buf, .length=turing_result };
}

U32Buffer Core_TuringMesh_getVertices(TuringMesh self) {
    
    uint32_t turing_result = _core_turing_mesh__get_vertices(self);
    uint32_t turing_buf = (uint32_t) malloc((size_t) turing_result * 4);
    _host_bufcpy(turing_buf, turing_result);
    return (U32Buffer){ .data=turing_buf, .length=turing_result };
}

void Core_TuringMesh_hideFlagsGet(TuringMesh self) {
    
    _core_turing_mesh__hide_flags_get(self);
}

void Core_TuringMesh_hideFlagsSet(TuringMesh self) {
    
    _core_turing_mesh__hide_flags_set(self);
}

void Core_TuringMesh_markModified(TuringMesh self) {
    
    _core_turing_mesh__mark_modified(self);
}

char* Core_TuringMesh_nameGet(TuringMesh self) {
    
    uint32_t turing_result = _core_turing_mesh__name_get(self);
    char* turing_str = (char*) malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

void Core_TuringMesh_nameSet(TuringMesh self
, const char* value) {
    
    _core_turing_mesh__name_set(self, value);
}

void Core_TuringMesh_optimize(TuringMesh self) {
    
    _core_turing_mesh__optimize(self);
}

void Core_TuringMesh_optimizeIndexBuffers(TuringMesh self) {
    
    _core_turing_mesh__optimize_index_buffers(self);
}

void Core_TuringMesh_recalculateBounds(TuringMesh self) {
    
    _core_turing_mesh__recalculate_bounds(self);
}

void Core_TuringMesh_recalculateNormals(TuringMesh self) {
    
    _core_turing_mesh__recalculate_normals(self);
}

void Core_TuringMesh_recalculateTangents(TuringMesh self) {
    
    _core_turing_mesh__recalculate_tangents(self);
}

void Core_TuringMesh_setBounds(TuringMesh self
, float min_x
, float min_y
, float min_z
, float max_x
, float max_y
, float max_z) {
    
    _core_turing_mesh__set_bounds(self, min_x, min_y, min_z, max_x, max_y, max_z);
}

void Core_TuringMesh_setTriangles(TuringMesh self
, Int32 triangles
, int32_t submesh
, bool calculate_bounds
, int32_t base_vertex) {
    
    _core_turing_mesh__set_triangles(self, triangles, submesh, calculate_bounds, base_vertex);
}

void Core_TuringMesh_setUVs(TuringMesh self
, int32_t channel
, U32Buffer uvs) {
    _host_u32_enqueue(uvs.length);
    _core_turing_mesh__set_u_vs(self, channel, uvs.data);
}

void Core_TuringMesh_setVertices(TuringMesh self
, U32Buffer in_vertices) {
    _host_u32_enqueue(in_vertices.length);
    _core_turing_mesh__set_vertices(self, in_vertices.data);
}

void Core_TuringMesh_uploadMeshData(TuringMesh self
, bool mark_no_longer_readable) {
    
    _core_turing_mesh__upload_mesh_data(self, mark_no_longer_readable);
}

NoteFloorMovement Core_TuringNoteExtensions_getNoteFloorMovement(NoteController note_controller) {
    
    return _core_turing_note_extensions__get_note_floor_movement(note_controller);
}

NoteJump Core_TuringNoteExtensions_getNoteJump(NoteController note_controller) {
    
    return _core_turing_note_extensions__get_note_jump(note_controller);
}

GameObject Core_TuringerGameObjectManager_createObject(const char* name) {
    
    return _core_turinger_game_object_manager__create_object(name);
}

void Core_TuringerGameObjectManager_destroyObject(GameObject game_object) {
    
    _core_turinger_game_object_manager__destroy_object(game_object);
}

GameObject Core_TuringerGameObjectManager_find(const char* name) {
    
    return _core_turinger_game_object_manager__find(name);
}

TuringerGameObjectManager Core_TuringerGameObjectManager_instanceGet(TuringerGameObjectManager self) {
    
    return _core_turinger_game_object_manager__instance_get(self);
}

float Core_Xr_getDeviceBatteryLevel(int32_t node_int) {
    
    return _core_xr__get_device_battery_level(node_int);
}

float Core_Xr_getDeviceGripValue(int32_t node_int) {
    
    return _core_xr__get_device_grip_value(node_int);
}

char* Core_Xr_getDeviceName(int32_t node_int) {
    
    uint32_t turing_result = _core_xr__get_device_name(node_int);
    char* turing_str = (char*) malloc((size_t) turing_result);
    _host_strcpy(turing_str, turing_result);
    return turing_str;
}

bool Core_Xr_getDevicePrimaryButtonState(int32_t node_int) {
    
    return _core_xr__get_device_primary_button_state(node_int);
}

bool Core_Xr_getDeviceSecondaryButtonState(int32_t node_int) {
    
    return _core_xr__get_device_secondary_button_state(node_int);
}

vec2s Core_Xr_getDeviceThumbstick(int32_t node_int) {
    
    _core_xr__get_device_thumbstick(node_int);
    return alg::__dequeue_vec2();
}

vec2s Core_Xr_getDeviceTouchpad(int32_t node_int) {
    
    _core_xr__get_device_touchpad(node_int);
    return alg::__dequeue_vec2();
}

int32_t Core_Xr_getDeviceTrackingState(int32_t node_int) {
    
    return _core_xr__get_device_tracking_state(node_int);
}

float Core_Xr_getDeviceTriggerValue(int32_t node_int) {
    
    return _core_xr__get_device_trigger_value(node_int);
}

bool Core_Xr_isDeviceValid(int32_t node_int) {
    
    return _core_xr__is_device_valid(node_int);
}

void Core_Xr_sendHapticImpulse(int32_t node_int, float amplitude, float duration) {
    
    _core_xr__send_haptic_impulse(node_int, amplitude, duration);
}

void Core_Xr_stopHaptics(int32_t node_int) {
    
    _core_xr__stop_haptics(node_int);
}

TuringScriptManager Core_Xr_ManagerGet(Xr self) {
    
    return _core_xr___manager_get(self);
}
