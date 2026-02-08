// Generated C++ header for core
#pragma once

#include <cstdint>
#include <string>
#include <array>
#include <vector>

#include <glm/mat4x4.hpp>               // glm::mat4
#include <glm/vec3.hpp>                 // glm::vec3
#include <glm/vec4.hpp>                 // glm::vec4
#include <glm/vec2.hpp>                 // glm::vec2
#include <glm/gtc/quaternion.hpp>       // glm::quat

// Visibility macros to allow compiler optimizations and symbol hiding
#if defined(__GNUC__) || defined(__clang__)
#  define TURING_API_EXPORT __attribute__((visibility("default")))
#  define TURING_API_HIDDEN __attribute__((visibility("hidden")))
#else
#  define TURING_API_EXPORT
#  define TURING_API_HIDDEN
#endif


namespace alg {
    using Vec2 = glm::vec2;
    using Vec3 = glm::vec3;
    using Vec4 = glm::vec4;
    using Quat = glm::quat;
    using Mat4 = glm::mat4;

    Vec2 dequeue_vec2();
    uint32_t enqueue_vec2(const Vec2& v);

    Vec3 dequeue_vec3();
    uint32_t enqueue_vec3(const Vec3& v);

    Vec4 dequeue_vec4();
    uint32_t enqueue_vec4(const Vec4& v);

    Quat dequeue_quat();
    uint32_t enqueue_quat(const Quat& q);

    Mat4 dequeue_mat4();
    uint32_t enqueue_mat4(const Mat4& m);
}

// Public API wrappers
// Forward declarations for all classes (opaque or not)

struct Action;

struct Component;

struct CustomData;

struct GameObject;

struct GcHelper;

struct IEnumerator;

struct List1;

struct Log;

struct NoteManager;

struct Object;

struct TaskScheduler;

struct Transform;

struct TuringScriptManager;

struct TuringerGameObject;

struct TuringerGameObjectManager;

struct TuringerTransform;

struct Type;

struct Xr;




struct Action {

    

    
    
    
    
};


struct Component {

    

    
    
    
    
};


struct CustomData {

    
     static CustomData create();
     static void list_add_bool(List1 list, bool value);
     static void list_add_custom_data(List1 list, CustomData value);
     static void list_add_custom_data_list(List1 list, List1 value);
     static void list_add_float(List1 list, float value);
     static void list_add_int(List1 list, int32_t value);
     static void list_add_string(List1 list, std::string_view value);
     static void set_bool(CustomData custom_data, std::string_view key, bool value);
     static void set_custom_data(CustomData custom_data, std::string_view key, CustomData value);
     static void set_custom_data_list(CustomData custom_data, std::string_view key, List1 value);
     static void set_float(CustomData custom_data, std::string_view key, float value);
     static void set_int(CustomData custom_data, std::string_view key, int32_t value);
     static void set_string(CustomData custom_data, std::string_view key, std::string_view value);

    
    
    
    
};


struct GameObject {

    

    
    
    
    
};


struct GcHelper {

    
     static GcHelper create();

    
    
    
     void dispose();
     void invalidate_all_handles();
     void wasm_garbage_collect();
    
};


struct IEnumerator {

    

    
    
    
    
};


struct List1 {

    

    
    
    
    
};


struct Log {

    
     static void critical(std::string_view msg);
     static void debug(std::string_view msg);
     static void info(std::string_view msg);
     static void warn(std::string_view msg);

    
    
    
    
};


struct NoteManager {

    
     static void add_bomb_note(float beat, int32_t line, int32_t layer, CustomData custom_data);
     static void add_color_note(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data);
     static void add_obstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data);
     static float time_to_beat(float time);

    
    
    
    
};


struct Object {

    

    
    
    
    
};


struct TaskScheduler {

    
     static void schedule(Action task);

    
    
    
     void dispose();
    
};


struct Transform {

    

    
    
    
    
};


struct TuringScriptManager {

    

    
    
    
    
};


struct TuringerGameObject {

    

    
    
    
     bool active_get();
     bool active_in_hierarchy_get();
     bool active_self_get();
     void active_set(bool value);
     Component add_component(Type component_type);
     void broadcast_message(std::string_view method_name, int32_t options);
     bool compare_tag(std::string_view tag);
     GameObject game_object_get();
     Component get_component_at_index(int32_t index);
     Component get_component_by_name(std::string_view cs_type);
     Component get_component_by_type(Type cs_type);
     int32_t get_component_count();
     Component get_component_in_children_by_type(Type cs_type, bool include_inactive);
     Component get_component_in_parent_by_type(Type cs_type, bool include_inactive);
     int32_t get_component_index(Component component);
     int32_t get_instance_id();
     int32_t hide_flags_get();
     void hide_flags_set(int32_t value);
     bool is_static_get();
     void is_static_set(bool value);
     int32_t layer_get();
     void layer_set(int32_t value);
     std::string name_get();
     void name_set(std::string_view value);
     uint64_t scene_culling_mask_get();
     void send_message(std::string_view method_name, int32_t options);
     void send_message_upwards(std::string_view method_name, int32_t options);
     void set_active(bool value);
     void set_active_recursively(bool state);
     std::string tag_get();
     void tag_set(std::string_view value);
     TuringerTransform transform_get();
    
};


struct TuringerGameObjectManager {

    
     static TuringerGameObject create_object(std::string_view name);
     static void destroy_object(TuringerGameObject listener);
     static TuringerGameObject find(std::string_view name);

    
    
    
     TuringerGameObjectManager instance_get();
    
};


struct TuringerTransform {

    

    
    
    
     void broadcast_message(std::string_view method_name, Object parameter, int32_t options);
     int32_t child_count_get();
     bool compare_tag(std::string_view tag);
     void detach_children();
     glm::vec3 euler_angles_get();
     void euler_angles_set(glm::vec3 value);
     TuringerTransform find(std::string_view n);
     TuringerTransform find_child(std::string_view n);
     glm::vec3 forward_get();
     void forward_set(glm::vec3 value);
     TuringerGameObject game_object_get();
     TuringerTransform get_child(int32_t index);
     int32_t get_child_count();
     Component get_component_by_name(std::string_view cs_type);
     Component get_component_by_type(Type cs_type);
     Component get_component_in_children_by_type(Type t, bool include_inactive);
     Component get_component_in_parent_by_type(Type t, bool include_inactive);
     int32_t get_component_index();
     IEnumerator get_enumerator();
     int32_t get_instance_id();
     int32_t get_sibling_index();
     bool has_changed_get();
     void has_changed_set(bool value);
     int32_t hide_flags_get();
     void hide_flags_set(int32_t value);
     int32_t hierarchy_capacity_get();
     void hierarchy_capacity_set(int32_t value);
     int32_t hierarchy_count_get();
     glm::vec3 inverse_transform_direction(glm::vec3 direction);
     glm::vec3 inverse_transform_point(glm::vec3 position);
     glm::vec3 inverse_transform_vector(glm::vec3 vector);
     bool is_child_of(TuringerTransform parent);
     glm::vec3 local_euler_angles_get();
     void local_euler_angles_set(glm::vec3 value);
     glm::vec3 local_position_get();
     void local_position_set(glm::vec3 value);
     glm::quat local_rotation_get();
     void local_rotation_set(glm::quat value);
     glm::vec3 local_scale_get();
     void local_scale_set(glm::vec3 value);
     glm::mat4 local_to_world_matrix_get();
     void look_at(TuringerTransform target, glm::vec3 world_up);
     glm::vec3 lossy_scale_get();
     std::string name_get();
     void name_set(std::string_view value);
     TuringerTransform parent_get();
     void parent_set(TuringerTransform value);
     glm::vec3 position_get();
     void position_set(glm::vec3 value);
     glm::vec3 right_get();
     void right_set(glm::vec3 value);
     TuringerTransform root_get();
     void rotate(glm::vec3 eulers);
     void rotate_around(glm::vec3 point, glm::vec3 axis, float angle);
     void rotate_around_local(glm::vec3 axis, float angle);
     void rotate_relative(glm::vec3 eulers, int32_t relative_to);
     glm::quat rotation_get();
     void rotation_set(glm::quat value);
     void send_message(std::string_view method_name, Object value, int32_t options);
     void send_message_upwards(std::string_view method_name, Object value, int32_t options);
     void set_as_first_sibling();
     void set_as_last_sibling();
     void set_local_position_and_rotation(glm::vec3 local_position, glm::quat local_rotation);
     void set_parent(TuringerTransform parent, bool world_position_stays);
     void set_position_and_rotation(glm::vec3 position, glm::quat rotation);
     void set_sibling_index(int32_t index);
     std::string tag_get();
     void tag_set(std::string_view value);
     glm::vec3 transform_direction(glm::vec3 direction);
     Transform transform_get();
     glm::vec3 transform_point(glm::vec3 position);
     glm::vec3 transform_vector(glm::vec3 vector);
     void translate(glm::vec3 translation, int32_t relative_to);
     void translate_relative(glm::vec3 translation, TuringerTransform relative_to);
     glm::vec3 up_get();
     void up_set(glm::vec3 value);
     glm::mat4 world_to_local_matrix_get();
    
};


struct Type {

    

    
    
    
    
};


struct Xr {

    
     static float get_device_battery_level(int32_t node_int);
     static float get_device_grip_value(int32_t node_int);
     static std::string get_device_name(int32_t node_int);
     static bool get_device_primary_button_state(int32_t node_int);
     static bool get_device_secondary_button_state(int32_t node_int);
     static glm::vec2 get_device_thumbstick(int32_t node_int);
     static glm::vec2 get_device_touchpad(int32_t node_int);
     static int32_t get_device_tracking_state(int32_t node_int);
     static float get_device_trigger_value(int32_t node_int);
     static bool is_device_valid(int32_t node_int);
     static void send_haptic_impulse(int32_t node_int, float amplitude, float duration);
     static void stop_haptics(int32_t node_int);

    
    
    
     TuringScriptManager _manager_get();
    
};



extern "C" {

    
    
    TURING_API_EXPORT CustomData Core_CustomData_create();
    TURING_API_EXPORT void Core_CustomData_listAddBool(List1 list, bool value);
    TURING_API_EXPORT void Core_CustomData_listAddCustomData(List1 list, CustomData value);
    TURING_API_EXPORT void Core_CustomData_listAddCustomDataList(List1 list, List1 value);
    TURING_API_EXPORT void Core_CustomData_listAddFloat(List1 list, float value);
    TURING_API_EXPORT void Core_CustomData_listAddInt(List1 list, int32_t value);
    TURING_API_EXPORT void Core_CustomData_listAddString(List1 list, const char* value);
    TURING_API_EXPORT void Core_CustomData_setBool(CustomData custom_data, const char* key, bool value);
    TURING_API_EXPORT void Core_CustomData_setCustomData(CustomData custom_data, const char* key, CustomData value);
    TURING_API_EXPORT void Core_CustomData_setCustomDataList(CustomData custom_data, const char* key, List1 value);
    TURING_API_EXPORT void Core_CustomData_setFloat(CustomData custom_data, const char* key, float value);
    TURING_API_EXPORT void Core_CustomData_setInt(CustomData custom_data, const char* key, int32_t value);
    TURING_API_EXPORT void Core_CustomData_setString(CustomData custom_data, const char* key, const char* value);
    
    
    TURING_API_EXPORT GcHelper Core_GcHelper_create();
    TURING_API_EXPORT void Core_GcHelper_dispose(uint64_t opaqu);
    TURING_API_EXPORT void Core_GcHelper_invalidateAllHandles(uint64_t opaqu);
    TURING_API_EXPORT void Core_GcHelper_wasmGarbageCollect(uint64_t opaqu);
    
    
    
    TURING_API_EXPORT void Core_Log_critical(const char* msg);
    TURING_API_EXPORT void Core_Log_debug(const char* msg);
    TURING_API_EXPORT void Core_Log_info(const char* msg);
    TURING_API_EXPORT void Core_Log_warn(const char* msg);
    
    TURING_API_EXPORT void Core_NoteManager_addBombNote(float beat, int32_t line, int32_t layer, CustomData custom_data);
    TURING_API_EXPORT void Core_NoteManager_addColorNote(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data);
    TURING_API_EXPORT void Core_NoteManager_addObstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data);
    TURING_API_EXPORT float Core_NoteManager_timeToBeat(float time);
    
    
    TURING_API_EXPORT void Core_TaskScheduler_schedule(Action task);
    TURING_API_EXPORT void Core_TaskScheduler_dispose(uint64_t opaqu);
    
    
    
    TURING_API_EXPORT bool Core_TuringerGameObject_activeGet(uint64_t opaqu);
    TURING_API_EXPORT bool Core_TuringerGameObject_activeInHierarchyGet(uint64_t opaqu);
    TURING_API_EXPORT bool Core_TuringerGameObject_activeSelfGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerGameObject_activeSet(uint64_t opaqu, bool value);
    TURING_API_EXPORT Component Core_TuringerGameObject_addComponent(uint64_t opaqu, Type component_type);
    TURING_API_EXPORT void Core_TuringerGameObject_broadcastMessage(uint64_t opaqu, const char* method_name, int32_t options);
    TURING_API_EXPORT bool Core_TuringerGameObject_compareTag(uint64_t opaqu, const char* tag);
    TURING_API_EXPORT GameObject Core_TuringerGameObject_gameObjectGet(uint64_t opaqu);
    TURING_API_EXPORT Component Core_TuringerGameObject_getComponentAtIndex(uint64_t opaqu, int32_t index);
    TURING_API_EXPORT Component Core_TuringerGameObject_getComponentByName(uint64_t opaqu, const char* cs_type);
    TURING_API_EXPORT Component Core_TuringerGameObject_getComponentByType(uint64_t opaqu, Type cs_type);
    TURING_API_EXPORT int32_t Core_TuringerGameObject_getComponentCount(uint64_t opaqu);
    TURING_API_EXPORT Component Core_TuringerGameObject_getComponentInChildrenByType(uint64_t opaqu, Type cs_type, bool include_inactive);
    TURING_API_EXPORT Component Core_TuringerGameObject_getComponentInParentByType(uint64_t opaqu, Type cs_type, bool include_inactive);
    TURING_API_EXPORT int32_t Core_TuringerGameObject_getComponentIndex(uint64_t opaqu, Component component);
    TURING_API_EXPORT int32_t Core_TuringerGameObject_getInstanceId(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_TuringerGameObject_hideFlagsGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerGameObject_hideFlagsSet(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT bool Core_TuringerGameObject_isStaticGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerGameObject_isStaticSet(uint64_t opaqu, bool value);
    TURING_API_EXPORT int32_t Core_TuringerGameObject_layerGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerGameObject_layerSet(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT char* Core_TuringerGameObject_nameGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerGameObject_nameSet(uint64_t opaqu, const char* value);
    TURING_API_EXPORT uint64_t Core_TuringerGameObject_sceneCullingMaskGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerGameObject_sendMessage(uint64_t opaqu, const char* method_name, int32_t options);
    TURING_API_EXPORT void Core_TuringerGameObject_sendMessageUpwards(uint64_t opaqu, const char* method_name, int32_t options);
    TURING_API_EXPORT void Core_TuringerGameObject_setActive(uint64_t opaqu, bool value);
    TURING_API_EXPORT void Core_TuringerGameObject_setActiveRecursively(uint64_t opaqu, bool state);
    TURING_API_EXPORT char* Core_TuringerGameObject_tagGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerGameObject_tagSet(uint64_t opaqu, const char* value);
    TURING_API_EXPORT TuringerTransform Core_TuringerGameObject_transformGet(uint64_t opaqu);
    
    TURING_API_EXPORT TuringerGameObject Core_TuringerGameObjectManager_createObject(const char* name);
    TURING_API_EXPORT void Core_TuringerGameObjectManager_destroyObject(TuringerGameObject listener);
    TURING_API_EXPORT TuringerGameObject Core_TuringerGameObjectManager_find(const char* name);
    TURING_API_EXPORT TuringerGameObjectManager Core_TuringerGameObjectManager_instanceGet(uint64_t opaqu);
    
    TURING_API_EXPORT void Core_TuringerTransform_broadcastMessage(uint64_t opaqu, const char* method_name, Object parameter, int32_t options);
    TURING_API_EXPORT int32_t Core_TuringerTransform_childCountGet(uint64_t opaqu);
    TURING_API_EXPORT bool Core_TuringerTransform_compareTag(uint64_t opaqu, const char* tag);
    TURING_API_EXPORT void Core_TuringerTransform_detachChildren(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_TuringerTransform_eulerAnglesGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_eulerAnglesSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT TuringerTransform Core_TuringerTransform_find(uint64_t opaqu, const char* n);
    TURING_API_EXPORT TuringerTransform Core_TuringerTransform_findChild(uint64_t opaqu, const char* n);
    TURING_API_EXPORT vec3s Core_TuringerTransform_forwardGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_forwardSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT TuringerGameObject Core_TuringerTransform_gameObjectGet(uint64_t opaqu);
    TURING_API_EXPORT TuringerTransform Core_TuringerTransform_getChild(uint64_t opaqu, int32_t index);
    TURING_API_EXPORT int32_t Core_TuringerTransform_getChildCount(uint64_t opaqu);
    TURING_API_EXPORT Component Core_TuringerTransform_getComponentByName(uint64_t opaqu, const char* cs_type);
    TURING_API_EXPORT Component Core_TuringerTransform_getComponentByType(uint64_t opaqu, Type cs_type);
    TURING_API_EXPORT Component Core_TuringerTransform_getComponentInChildrenByType(uint64_t opaqu, Type t, bool include_inactive);
    TURING_API_EXPORT Component Core_TuringerTransform_getComponentInParentByType(uint64_t opaqu, Type t, bool include_inactive);
    TURING_API_EXPORT int32_t Core_TuringerTransform_getComponentIndex(uint64_t opaqu);
    TURING_API_EXPORT IEnumerator Core_TuringerTransform_getEnumerator(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_TuringerTransform_getInstanceId(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_TuringerTransform_getSiblingIndex(uint64_t opaqu);
    TURING_API_EXPORT bool Core_TuringerTransform_hasChangedGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_hasChangedSet(uint64_t opaqu, bool value);
    TURING_API_EXPORT int32_t Core_TuringerTransform_hideFlagsGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_hideFlagsSet(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT int32_t Core_TuringerTransform_hierarchyCapacityGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_hierarchyCapacitySet(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT int32_t Core_TuringerTransform_hierarchyCountGet(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_TuringerTransform_inverseTransformDirection(uint64_t opaqu, vec3s direction);
    TURING_API_EXPORT vec3s Core_TuringerTransform_inverseTransformPoint(uint64_t opaqu, vec3s position);
    TURING_API_EXPORT vec3s Core_TuringerTransform_inverseTransformVector(uint64_t opaqu, vec3s vector);
    TURING_API_EXPORT bool Core_TuringerTransform_isChildOf(uint64_t opaqu, TuringerTransform parent);
    TURING_API_EXPORT vec3s Core_TuringerTransform_localEulerAnglesGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_localEulerAnglesSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT vec3s Core_TuringerTransform_localPositionGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_localPositionSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT versors Core_TuringerTransform_localRotationGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_localRotationSet(uint64_t opaqu, versors value);
    TURING_API_EXPORT vec3s Core_TuringerTransform_localScaleGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_localScaleSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT mat4s Core_TuringerTransform_localToWorldMatrixGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_lookAt(uint64_t opaqu, TuringerTransform target, vec3s world_up);
    TURING_API_EXPORT vec3s Core_TuringerTransform_lossyScaleGet(uint64_t opaqu);
    TURING_API_EXPORT char* Core_TuringerTransform_nameGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_nameSet(uint64_t opaqu, const char* value);
    TURING_API_EXPORT TuringerTransform Core_TuringerTransform_parentGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_parentSet(uint64_t opaqu, TuringerTransform value);
    TURING_API_EXPORT vec3s Core_TuringerTransform_positionGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_positionSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT vec3s Core_TuringerTransform_rightGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_rightSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT TuringerTransform Core_TuringerTransform_rootGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_rotate(uint64_t opaqu, vec3s eulers);
    TURING_API_EXPORT void Core_TuringerTransform_rotateAround(uint64_t opaqu, vec3s point, vec3s axis, float angle);
    TURING_API_EXPORT void Core_TuringerTransform_rotateAroundLocal(uint64_t opaqu, vec3s axis, float angle);
    TURING_API_EXPORT void Core_TuringerTransform_rotateRelative(uint64_t opaqu, vec3s eulers, int32_t relative_to);
    TURING_API_EXPORT versors Core_TuringerTransform_rotationGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_rotationSet(uint64_t opaqu, versors value);
    TURING_API_EXPORT void Core_TuringerTransform_sendMessage(uint64_t opaqu, const char* method_name, Object value, int32_t options);
    TURING_API_EXPORT void Core_TuringerTransform_sendMessageUpwards(uint64_t opaqu, const char* method_name, Object value, int32_t options);
    TURING_API_EXPORT void Core_TuringerTransform_setAsFirstSibling(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_setAsLastSibling(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_setLocalPositionAndRotation(uint64_t opaqu, vec3s local_position, versors local_rotation);
    TURING_API_EXPORT void Core_TuringerTransform_setParent(uint64_t opaqu, TuringerTransform parent, bool world_position_stays);
    TURING_API_EXPORT void Core_TuringerTransform_setPositionAndRotation(uint64_t opaqu, vec3s position, versors rotation);
    TURING_API_EXPORT void Core_TuringerTransform_setSiblingIndex(uint64_t opaqu, int32_t index);
    TURING_API_EXPORT char* Core_TuringerTransform_tagGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_tagSet(uint64_t opaqu, const char* value);
    TURING_API_EXPORT vec3s Core_TuringerTransform_transformDirection(uint64_t opaqu, vec3s direction);
    TURING_API_EXPORT Transform Core_TuringerTransform_transformGet(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_TuringerTransform_transformPoint(uint64_t opaqu, vec3s position);
    TURING_API_EXPORT vec3s Core_TuringerTransform_transformVector(uint64_t opaqu, vec3s vector);
    TURING_API_EXPORT void Core_TuringerTransform_translate(uint64_t opaqu, vec3s translation, int32_t relative_to);
    TURING_API_EXPORT void Core_TuringerTransform_translateRelative(uint64_t opaqu, vec3s translation, TuringerTransform relative_to);
    TURING_API_EXPORT vec3s Core_TuringerTransform_upGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringerTransform_upSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT mat4s Core_TuringerTransform_worldToLocalMatrixGet(uint64_t opaqu);
    
    
    TURING_API_EXPORT float Core_Xr_getDeviceBatteryLevel(int32_t node_int);
    TURING_API_EXPORT float Core_Xr_getDeviceGripValue(int32_t node_int);
    TURING_API_EXPORT char* Core_Xr_getDeviceName(int32_t node_int);
    TURING_API_EXPORT bool Core_Xr_getDevicePrimaryButtonState(int32_t node_int);
    TURING_API_EXPORT bool Core_Xr_getDeviceSecondaryButtonState(int32_t node_int);
    TURING_API_EXPORT vec2s Core_Xr_getDeviceThumbstick(int32_t node_int);
    TURING_API_EXPORT vec2s Core_Xr_getDeviceTouchpad(int32_t node_int);
    TURING_API_EXPORT int32_t Core_Xr_getDeviceTrackingState(int32_t node_int);
    TURING_API_EXPORT float Core_Xr_getDeviceTriggerValue(int32_t node_int);
    TURING_API_EXPORT bool Core_Xr_isDeviceValid(int32_t node_int);
    TURING_API_EXPORT void Core_Xr_sendHapticImpulse(int32_t node_int, float amplitude, float duration);
    TURING_API_EXPORT void Core_Xr_stopHaptics(int32_t node_int);
    TURING_API_EXPORT TuringScriptManager Core_Xr_ManagerGet(uint64_t opaqu);
    
}
