// Generated C++ header for turing_api
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

struct GameObject;

struct Transform;

struct TuringScriptManager;

struct Object;

struct List1;

struct List;

struct Component;

struct Type;

struct IEnumerator;

struct Log;

struct TuringerGameObject;

struct TuringerGameObjectManager;

struct CustomData;

struct GcHelper;

struct NoteManager;

struct Xr;

struct TuringerTransform;




struct GameObject {
    
    uint64_t opaqu;

    

    
    
};


struct Transform {
    
    uint64_t opaqu;

    

    
    
};


struct TuringScriptManager {
    
    uint64_t opaqu;

    

    
    
};


struct Object {
    
    uint64_t opaqu;

    

    
    
};


struct List1 {
    
    uint64_t opaqu;

    

    
    
};


struct List {
    
    uint64_t opaqu;

    

    
    
};


struct Component {
    
    uint64_t opaqu;

    

    
    
};


struct Type {
    
    uint64_t opaqu;

    

    
    
};


struct IEnumerator {
    
    uint64_t opaqu;

    

    
    
};


struct Log {
    

    
    static void warn(std::string_view msg);
    static void info(std::string_view msg);
    static void debug(std::string_view msg);
    static void critical(std::string_view msg);

    
    
};


struct TuringerGameObject {
    
    uint64_t opaqu;

    

    
    
    Component get_components_in_parent_by_type(Type cs_type, bool include_inactive);
    void send_message(std::string_view method_name, int32_t options);
    Component get_component_in_parent_by_type(Type cs_type, bool include_inactive);
    bool is_static_get();
    TuringerTransform transform_get();
    Component get_component_in_children_by_type(Type cs_type, bool include_inactive);
    Component get_components_by_type(Type cs_type);
    void active_set(bool value);
    void broadcast_message(std::string_view method_name, int32_t options);
    GameObject game_object_get();
    void is_static_set(bool value);
    Component add_component(Type component_type);
    void hide_flags_set(int32_t value);
    void send_message_upwards(std::string_view method_name, int32_t options);
    bool compare_tag(std::string_view tag);
    int32_t hide_flags_get();
    void tag_set(std::string_view value);
    int32_t get_instance_id();
    int32_t layer_get();
    Component get_components_in_children_by_type(Type cs_type, bool include_inactive);
    void layer_set(int32_t value);
    void set_active_recursively(bool state);
    int32_t get_component_index(Component component);
    int32_t get_component_count();
    Component get_component_at_index(int32_t index);
    std::string tag_get();
    bool active_self_get();
    std::string name_get();
    Component get_component_by_type(Type cs_type);
    bool active_in_hierarchy_get();
    void set_active(bool value);
    bool active_get();
    Component get_component_by_name(std::string_view cs_type);
    void name_set(std::string_view value);
    uint64_t scene_culling_mask_get();
};


struct TuringerGameObjectManager {
    
    uint64_t opaqu;

    
    static TuringerGameObject create_object(std::string_view name);
    static TuringerGameObject find(std::string_view name);
    static void destroy_object(TuringerGameObject listener);

    
    
    TuringerGameObjectManager instance_get();
};


struct CustomData {
    
    uint64_t opaqu;

    
    static CustomData create();
    static List list_create();
    static void set_string(CustomData custom_data, std::string_view key, std::string_view value);
    static void set_custom_data(CustomData custom_data, std::string_view key, CustomData value);
    static void list_add_string(List1 list, std::string_view value);
    static void set_custom_data_list(CustomData custom_data, std::string_view key, List1 value);
    static void set_float(CustomData custom_data, std::string_view key, float value);
    static void list_add_int(List1 list, int32_t value);
    static void list_add_bool(List1 list, bool value);
    static void set_int(CustomData custom_data, std::string_view key, int32_t value);
    static void set_bool(CustomData custom_data, std::string_view key, bool value);
    static void list_add_custom_data_list(List1 list, List1 value);
    static void list_add_float(List1 list, float value);
    static void list_add_custom_data(List1 list, CustomData value);

    
    
};


struct GcHelper {
    
    uint64_t opaqu;

    
    static GCHelper create();

    
    
    void wasm_garbage_collect();
    void dispose();
    void invalidate_all_handles();
};


struct NoteManager {
    

    
    static void add_obstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data);
    static void add_color_note(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data);
    static float time_to_beat(float time);
    static void add_bomb_note(float beat, int32_t line, int32_t layer, CustomData custom_data);

    
    
};


struct Xr {
    
    uint64_t opaqu;

    
    static int32_t get_device_tracking_state(int32_t node_int);
    static std::string get_device_name(int32_t node_int);
    static bool get_device_secondary_button_state(int32_t node_int);
    static bool get_device_primary_button_state(int32_t node_int);
    static void send_haptic_impulse(int32_t node_int, float amplitude, float duration);
    static bool is_device_valid(int32_t node_int);
    static float get_device_battery_level(int32_t node_int);
    static glm::vec2 get_device_touchpad(int32_t node_int);
    static float get_device_grip_value(int32_t node_int);
    static float get_device_trigger_value(int32_t node_int);
    static void stop_haptics(int32_t node_int);
    static glm::vec2 get_device_thumbstick(int32_t node_int);

    
    
    TuringScriptManager _manager_get();
};


struct TuringerTransform {
    
    uint64_t opaqu;

    

    
    
    Component get_component_by_type(Type cs_type);
    void look_at(TuringerTransform target, glm::vec3 world_up);
    int32_t get_instance_id();
    std::string tag_get();
    glm::vec3 local_euler_angles_get();
    glm::quat rotation_get();
    glm::mat4 world_to_local_matrix_get();
    int32_t hierarchy_count_get();
    Component get_components_in_children_by_type(Type t, bool include_inactive);
    void name_set(std::string_view value);
    glm::quat local_rotation_get();
    void detach_children();
    glm::vec3 inverse_transform_point(glm::vec3 position);
    Component get_component_in_children_by_type(Type t, bool include_inactive);
    Transform transform_get();
    glm::vec3 lossy_scale_get();
    TuringerTransform root_get();
    Component get_components_by_type(Type cs_type);
    IEnumerator get_enumerator();
    void local_scale_set(glm::vec3 value);
    int32_t child_count_get();
    void parent_set(TuringerTransform value);
    TuringerTransform get_child(int32_t index);
    glm::vec3 transform_direction(glm::vec3 direction);
    void has_changed_set(bool value);
    void send_message_upwards(std::string_view method_name, Object value, int32_t options);
    TuringerTransform find_child(std::string_view n);
    Component get_components_in_parent_by_type(Type t, bool include_inactive);
    void rotate(glm::vec3 eulers);
    bool has_changed_get();
    glm::vec3 local_position_get();
    void translate_relative(glm::vec3 translation, TuringerTransform relative_to);
    void local_euler_angles_set(glm::vec3 value);
    void set_local_position_and_rotation(glm::vec3 local_position, glm::quat local_rotation);
    glm::vec3 forward_get();
    int32_t get_sibling_index();
    Component get_component_in_parent_by_type(Type t, bool include_inactive);
    glm::vec3 up_get();
    int32_t get_component_index();
    void rotate_around_local(glm::vec3 axis, float angle);
    void translate(glm::vec3 translation, int32_t relative_to);
    void broadcast_message(std::string_view method_name, Object parameter, int32_t options);
    void euler_angles_set(glm::vec3 value);
    void send_message(std::string_view method_name, Object value, int32_t options);
    TuringerTransform parent_get();
    glm::mat4 local_to_world_matrix_get();
    Component get_component_by_name(std::string_view cs_type);
    void set_parent(TuringerTransform parent, bool world_position_stays);
    void rotate_around(glm::vec3 point, glm::vec3 axis, float angle);
    void hierarchy_capacity_set(int32_t value);
    void up_set(glm::vec3 value);
    glm::vec3 inverse_transform_direction(glm::vec3 direction);
    glm::vec3 local_scale_get();
    glm::vec3 transform_vector(glm::vec3 vector);
    glm::vec3 transform_point(glm::vec3 position);
    glm::vec3 euler_angles_get();
    bool is_child_of(TuringerTransform parent);
    void right_set(glm::vec3 value);
    int32_t get_child_count();
    int32_t hide_flags_get();
    void rotate_relative(glm::vec3 eulers, int32_t relative_to);
    void rotation_set(glm::quat value);
    TuringerGameObject game_object_get();
    int32_t hierarchy_capacity_get();
    void set_as_first_sibling();
    glm::vec3 right_get();
    void local_position_set(glm::vec3 value);
    void forward_set(glm::vec3 value);
    std::string name_get();
    bool compare_tag(std::string_view tag);
    void set_as_last_sibling();
    glm::vec3 position_get();
    void set_sibling_index(int32_t index);
    void position_set(glm::vec3 value);
    void hide_flags_set(int32_t value);
    void set_position_and_rotation(glm::vec3 position, glm::quat rotation);
    TuringerTransform find(std::string_view n);
    void tag_set(std::string_view value);
    void local_rotation_set(glm::quat value);
    glm::vec3 inverse_transform_vector(glm::vec3 vector);
};



extern "C" {

    TURING_API_EXPORT void _host_strcpy(const char* location, uint32_t size);
    TURING_API_EXPORT void _host_f32_enqueue(float f);
    TURING_API_EXPORT float _host_f32_dequeue();

    
    
    
    
    
    
    
    
    
    TURING_API_EXPORT void _core_log__warn(const char* msg);
    TURING_API_EXPORT void _core_log__info(const char* msg);
    TURING_API_EXPORT void _core_log__debug(const char* msg);
    TURING_API_EXPORT void _core_log__critical(const char* msg);
    
    TURING_API_EXPORT Component _get_components_in_parent_by_type(uint64_t opaqu, Type cs_type, bool include_inactive);
    TURING_API_EXPORT void _core_turinger_game_object__send_message(uint64_t opaqu, const char* method_name, int32_t options);
    TURING_API_EXPORT Component _core_turinger_game_object__get_component_in_parent_by_type(uint64_t opaqu, Type cs_type, bool include_inactive);
    TURING_API_EXPORT bool _core_turinger_game_object__is_static_get(uint64_t opaqu);
    TURING_API_EXPORT TuringerTransform _core_turinger_game_object__transform_get(uint64_t opaqu);
    TURING_API_EXPORT Component _core_turinger_game_object__get_component_in_children_by_type(uint64_t opaqu, Type cs_type, bool include_inactive);
    TURING_API_EXPORT Component _get_components_by_type(uint64_t opaqu, Type cs_type);
    TURING_API_EXPORT void _core_turinger_game_object__active_set(uint64_t opaqu, bool value);
    TURING_API_EXPORT void _core_turinger_game_object__broadcast_message(uint64_t opaqu, const char* method_name, int32_t options);
    TURING_API_EXPORT GameObject _core_turinger_game_object__game_object_get(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_game_object__is_static_set(uint64_t opaqu, bool value);
    TURING_API_EXPORT Component _core_turinger_game_object__add_component(uint64_t opaqu, Type component_type);
    TURING_API_EXPORT void _core_turinger_game_object__hide_flags_set(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT void _core_turinger_game_object__send_message_upwards(uint64_t opaqu, const char* method_name, int32_t options);
    TURING_API_EXPORT bool _core_turinger_game_object__compare_tag(uint64_t opaqu, const char* tag);
    TURING_API_EXPORT int32_t _core_turinger_game_object__hide_flags_get(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_game_object__tag_set(uint64_t opaqu, const char* value);
    TURING_API_EXPORT int32_t _core_turinger_game_object__get_instance_id(uint64_t opaqu);
    TURING_API_EXPORT int32_t _core_turinger_game_object__layer_get(uint64_t opaqu);
    TURING_API_EXPORT Component _get_components_in_children_by_type(uint64_t opaqu, Type cs_type, bool include_inactive);
    TURING_API_EXPORT void _core_turinger_game_object__layer_set(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT void _core_turinger_game_object__set_active_recursively(uint64_t opaqu, bool state);
    TURING_API_EXPORT int32_t _core_turinger_game_object__get_component_index(uint64_t opaqu, Component component);
    TURING_API_EXPORT int32_t _core_turinger_game_object__get_component_count(uint64_t opaqu);
    TURING_API_EXPORT Component _core_turinger_game_object__get_component_at_index(uint64_t opaqu, int32_t index);
    TURING_API_EXPORT char* _core_turinger_game_object__tag_get(uint64_t opaqu);
    TURING_API_EXPORT bool _core_turinger_game_object__active_self_get(uint64_t opaqu);
    TURING_API_EXPORT char* _core_turinger_game_object__name_get(uint64_t opaqu);
    TURING_API_EXPORT Component _core_turinger_game_object__get_component_by_type(uint64_t opaqu, Type cs_type);
    TURING_API_EXPORT bool _core_turinger_game_object__active_in_hierarchy_get(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_game_object__set_active(uint64_t opaqu, bool value);
    TURING_API_EXPORT bool _core_turinger_game_object__active_get(uint64_t opaqu);
    TURING_API_EXPORT Component _core_turinger_game_object__get_component_by_name(uint64_t opaqu, const char* cs_type);
    TURING_API_EXPORT void _core_turinger_game_object__name_set(uint64_t opaqu, const char* value);
    TURING_API_EXPORT uint64_t _core_turinger_game_object__scene_culling_mask_get(uint64_t opaqu);
    
    TURING_API_EXPORT TuringerGameObject _core_turinger_game_object_manager__create_object(const char* name);
    TURING_API_EXPORT TuringerGameObject _core_turinger_game_object_manager__find(const char* name);
    TURING_API_EXPORT void _core_turinger_game_object_manager__destroy_object(TuringerGameObject listener);
    TURING_API_EXPORT TuringerGameObjectManager _core_turinger_game_object_manager__instance_get(uint64_t opaqu);
    
    TURING_API_EXPORT CustomData _core_custom_data__create();
    TURING_API_EXPORT List _list_create();
    TURING_API_EXPORT void _core_custom_data__set_string(CustomData custom_data, const char* key, const char* value);
    TURING_API_EXPORT void _core_custom_data__set_custom_data(CustomData custom_data, const char* key, CustomData value);
    TURING_API_EXPORT void _core_custom_data__list_add_string(List1 list, const char* value);
    TURING_API_EXPORT void _core_custom_data__set_custom_data_list(CustomData custom_data, const char* key, List1 value);
    TURING_API_EXPORT void _core_custom_data__set_float(CustomData custom_data, const char* key, float value);
    TURING_API_EXPORT void _core_custom_data__list_add_int(List1 list, int32_t value);
    TURING_API_EXPORT void _core_custom_data__list_add_bool(List1 list, bool value);
    TURING_API_EXPORT void _core_custom_data__set_int(CustomData custom_data, const char* key, int32_t value);
    TURING_API_EXPORT void _core_custom_data__set_bool(CustomData custom_data, const char* key, bool value);
    TURING_API_EXPORT void _core_custom_data__list_add_custom_data_list(List1 list, List1 value);
    TURING_API_EXPORT void _core_custom_data__list_add_float(List1 list, float value);
    TURING_API_EXPORT void _core_custom_data__list_add_custom_data(List1 list, CustomData value);
    
    TURING_API_EXPORT GCHelper _core_gc_helper__create();
    TURING_API_EXPORT void _core_gc_helper__wasm_garbage_collect(uint64_t opaqu);
    TURING_API_EXPORT void _core_gc_helper__dispose(uint64_t opaqu);
    TURING_API_EXPORT void _core_gc_helper__invalidate_all_handles(uint64_t opaqu);
    
    TURING_API_EXPORT void _core_note_manager__add_obstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data);
    TURING_API_EXPORT void _core_note_manager__add_color_note(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data);
    TURING_API_EXPORT float _core_note_manager__time_to_beat(float time);
    TURING_API_EXPORT void _core_note_manager__add_bomb_note(float beat, int32_t line, int32_t layer, CustomData custom_data);
    
    TURING_API_EXPORT int32_t _core_xr__get_device_tracking_state(int32_t node_int);
    TURING_API_EXPORT char* _core_xr__get_device_name(int32_t node_int);
    TURING_API_EXPORT bool _core_xr__get_device_secondary_button_state(int32_t node_int);
    TURING_API_EXPORT bool _core_xr__get_device_primary_button_state(int32_t node_int);
    TURING_API_EXPORT void _core_xr__send_haptic_impulse(int32_t node_int, float amplitude, float duration);
    TURING_API_EXPORT bool _core_xr__is_device_valid(int32_t node_int);
    TURING_API_EXPORT float _core_xr__get_device_battery_level(int32_t node_int);
    TURING_API_EXPORT vec2s _core_xr__get_device_touchpad(int32_t node_int);
    TURING_API_EXPORT float _core_xr__get_device_grip_value(int32_t node_int);
    TURING_API_EXPORT float _core_xr__get_device_trigger_value(int32_t node_int);
    TURING_API_EXPORT void _core_xr__stop_haptics(int32_t node_int);
    TURING_API_EXPORT vec2s _core_xr__get_device_thumbstick(int32_t node_int);
    TURING_API_EXPORT TuringScriptManager _core_xr___manager_get(uint64_t opaqu);
    
    TURING_API_EXPORT Component _core_turinger_transform__get_component_by_type(uint64_t opaqu, Type cs_type);
    TURING_API_EXPORT void _core_turinger_transform__look_at(uint64_t opaqu, TuringerTransform target, vec3s world_up);
    TURING_API_EXPORT int32_t _core_turinger_transform__get_instance_id(uint64_t opaqu);
    TURING_API_EXPORT char* _core_turinger_transform__tag_get(uint64_t opaqu);
    TURING_API_EXPORT vec3s _core_turinger_transform__local_euler_angles_get(uint64_t opaqu);
    TURING_API_EXPORT quats _core_turinger_transform__rotation_get(uint64_t opaqu);
    TURING_API_EXPORT mat4s _core_turinger_transform__world_to_local_matrix_get(uint64_t opaqu);
    TURING_API_EXPORT int32_t _core_turinger_transform__hierarchy_count_get(uint64_t opaqu);
    TURING_API_EXPORT Component _get_components_in_children_by_type(uint64_t opaqu, Type t, bool include_inactive);
    TURING_API_EXPORT void _core_turinger_transform__name_set(uint64_t opaqu, const char* value);
    TURING_API_EXPORT quats _core_turinger_transform__local_rotation_get(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_transform__detach_children(uint64_t opaqu);
    TURING_API_EXPORT vec3s _core_turinger_transform__inverse_transform_point(uint64_t opaqu, vec3s position);
    TURING_API_EXPORT Component _core_turinger_transform__get_component_in_children_by_type(uint64_t opaqu, Type t, bool include_inactive);
    TURING_API_EXPORT Transform _core_turinger_transform__transform_get(uint64_t opaqu);
    TURING_API_EXPORT vec3s _core_turinger_transform__lossy_scale_get(uint64_t opaqu);
    TURING_API_EXPORT TuringerTransform _core_turinger_transform__root_get(uint64_t opaqu);
    TURING_API_EXPORT Component _get_components_by_type(uint64_t opaqu, Type cs_type);
    TURING_API_EXPORT IEnumerator _core_turinger_transform__get_enumerator(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_transform__local_scale_set(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT int32_t _core_turinger_transform__child_count_get(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_transform__parent_set(uint64_t opaqu, TuringerTransform value);
    TURING_API_EXPORT TuringerTransform _core_turinger_transform__get_child(uint64_t opaqu, int32_t index);
    TURING_API_EXPORT vec3s _core_turinger_transform__transform_direction(uint64_t opaqu, vec3s direction);
    TURING_API_EXPORT void _core_turinger_transform__has_changed_set(uint64_t opaqu, bool value);
    TURING_API_EXPORT void _core_turinger_transform__send_message_upwards(uint64_t opaqu, const char* method_name, Object value, int32_t options);
    TURING_API_EXPORT TuringerTransform _core_turinger_transform__find_child(uint64_t opaqu, const char* n);
    TURING_API_EXPORT Component _get_components_in_parent_by_type(uint64_t opaqu, Type t, bool include_inactive);
    TURING_API_EXPORT void _core_turinger_transform__rotate(uint64_t opaqu, vec3s eulers);
    TURING_API_EXPORT bool _core_turinger_transform__has_changed_get(uint64_t opaqu);
    TURING_API_EXPORT vec3s _core_turinger_transform__local_position_get(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_transform__translate_relative(uint64_t opaqu, vec3s translation, TuringerTransform relative_to);
    TURING_API_EXPORT void _core_turinger_transform__local_euler_angles_set(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT void _core_turinger_transform__set_local_position_and_rotation(uint64_t opaqu, vec3s local_position, quats local_rotation);
    TURING_API_EXPORT vec3s _core_turinger_transform__forward_get(uint64_t opaqu);
    TURING_API_EXPORT int32_t _core_turinger_transform__get_sibling_index(uint64_t opaqu);
    TURING_API_EXPORT Component _core_turinger_transform__get_component_in_parent_by_type(uint64_t opaqu, Type t, bool include_inactive);
    TURING_API_EXPORT vec3s _core_turinger_transform__up_get(uint64_t opaqu);
    TURING_API_EXPORT int32_t _core_turinger_transform__get_component_index(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_transform__rotate_around_local(uint64_t opaqu, vec3s axis, float angle);
    TURING_API_EXPORT void _core_turinger_transform__translate(uint64_t opaqu, vec3s translation, int32_t relative_to);
    TURING_API_EXPORT void _core_turinger_transform__broadcast_message(uint64_t opaqu, const char* method_name, Object parameter, int32_t options);
    TURING_API_EXPORT void _core_turinger_transform__euler_angles_set(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT void _core_turinger_transform__send_message(uint64_t opaqu, const char* method_name, Object value, int32_t options);
    TURING_API_EXPORT TuringerTransform _core_turinger_transform__parent_get(uint64_t opaqu);
    TURING_API_EXPORT mat4s _core_turinger_transform__local_to_world_matrix_get(uint64_t opaqu);
    TURING_API_EXPORT Component _core_turinger_transform__get_component_by_name(uint64_t opaqu, const char* cs_type);
    TURING_API_EXPORT void _core_turinger_transform__set_parent(uint64_t opaqu, TuringerTransform parent, bool world_position_stays);
    TURING_API_EXPORT void _core_turinger_transform__rotate_around(uint64_t opaqu, vec3s point, vec3s axis, float angle);
    TURING_API_EXPORT void _core_turinger_transform__hierarchy_capacity_set(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT void _core_turinger_transform__up_set(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT vec3s _core_turinger_transform__inverse_transform_direction(uint64_t opaqu, vec3s direction);
    TURING_API_EXPORT vec3s _core_turinger_transform__local_scale_get(uint64_t opaqu);
    TURING_API_EXPORT vec3s _core_turinger_transform__transform_vector(uint64_t opaqu, vec3s vector);
    TURING_API_EXPORT vec3s _core_turinger_transform__transform_point(uint64_t opaqu, vec3s position);
    TURING_API_EXPORT vec3s _core_turinger_transform__euler_angles_get(uint64_t opaqu);
    TURING_API_EXPORT bool _core_turinger_transform__is_child_of(uint64_t opaqu, TuringerTransform parent);
    TURING_API_EXPORT void _core_turinger_transform__right_set(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT int32_t _core_turinger_transform__get_child_count(uint64_t opaqu);
    TURING_API_EXPORT int32_t _core_turinger_transform__hide_flags_get(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_transform__rotate_relative(uint64_t opaqu, vec3s eulers, int32_t relative_to);
    TURING_API_EXPORT void _core_turinger_transform__rotation_set(uint64_t opaqu, quats value);
    TURING_API_EXPORT TuringerGameObject _core_turinger_transform__game_object_get(uint64_t opaqu);
    TURING_API_EXPORT int32_t _core_turinger_transform__hierarchy_capacity_get(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_transform__set_as_first_sibling(uint64_t opaqu);
    TURING_API_EXPORT vec3s _core_turinger_transform__right_get(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_transform__local_position_set(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT void _core_turinger_transform__forward_set(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT char* _core_turinger_transform__name_get(uint64_t opaqu);
    TURING_API_EXPORT bool _core_turinger_transform__compare_tag(uint64_t opaqu, const char* tag);
    TURING_API_EXPORT void _core_turinger_transform__set_as_last_sibling(uint64_t opaqu);
    TURING_API_EXPORT vec3s _core_turinger_transform__position_get(uint64_t opaqu);
    TURING_API_EXPORT void _core_turinger_transform__set_sibling_index(uint64_t opaqu, int32_t index);
    TURING_API_EXPORT void _core_turinger_transform__position_set(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT void _core_turinger_transform__hide_flags_set(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT void _core_turinger_transform__set_position_and_rotation(uint64_t opaqu, vec3s position, quats rotation);
    TURING_API_EXPORT TuringerTransform _core_turinger_transform__find(uint64_t opaqu, const char* n);
    TURING_API_EXPORT void _core_turinger_transform__tag_set(uint64_t opaqu, const char* value);
    TURING_API_EXPORT void _core_turinger_transform__local_rotation_set(uint64_t opaqu, quats value);
    TURING_API_EXPORT vec3s _core_turinger_transform__inverse_transform_vector(uint64_t opaqu, vec3s vector);
    
}
