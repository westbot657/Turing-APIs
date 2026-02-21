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

struct Action1;

struct BeatmapDataItem;

struct Component;

struct CustomData;

struct CustomEventData;

struct CustomNoteData;

struct CustomObstacleData;

struct GcHelper;

struct GameObject;

struct GcHelper;

struct IAudioTimeSource;

struct IEnumerator;

struct IVariableMovementDataProvider;

struct Int32;

struct List1;

struct Log;

struct Mesh;

struct NoteController;

struct NoteControllerBase;

struct NoteFloorMovement;

struct NoteJump;

struct NoteManager;

struct Object;

struct ObstacleController;

struct ObstacleControllerBase;

struct PlayerSpaceConvertor;

struct PlayerTransforms;

struct TaskScheduler;

struct Texture2D;

struct Transform;

struct TuringMesh;

struct TuringScriptManager;

struct TuringTexture2D;

struct TuringerGameObjectManager;

struct Type;

struct Version;

struct Xr;




struct Action {

    

    
    
    
    
};


struct Action1 {

    

    
    
    
    
};


struct BeatmapDataItem {

    

    
    
    
    
};


struct Component {

    

    
    
    
    
};


struct CustomData {

    
     static CustomData create();
     static CustomData from_json(std::string_view json);
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
     static std::string to_json(CustomData custom_data, bool pretty);

    
    
    
    
};


struct CustomEventData {

    

    
    
    
     CustomData custom_data_get();
     std::string event_type_get();
     BeatmapDataItem get_copy();
     Version version_get();
    
};


struct CustomNoteData {

    
     static CustomNoteData create_custom_basic_note_data(float time, float beat, int32_t rotation, int32_t line_index, int32_t note_line_layer, int32_t color_type, int32_t cut_direction, CustomData custom_data, Version version);
     static CustomNoteData create_custom_bomb_note_data(float time, float beat, int32_t rotation, int32_t line_index, int32_t note_line_layer, CustomData custom_data, Version version);
     static CustomNoteData create_custom_burst_slider_note_data(float time, float beat, int32_t rotation, int32_t line_index, int32_t note_line_layer, int32_t before_jump_note_line_layer, int32_t color_type, int32_t cut_direction, float cut_sfx_volume_multiplier, CustomData custom_data);

    
    
    
     CustomData custom_data_get();
     BeatmapDataItem get_copy();
     Version version_get();
    
};


struct CustomObstacleData {

    

    
    
    
     CustomData custom_data_get();
     BeatmapDataItem get_copy();
     Version version_get();
    
};


struct GcHelper {

    

    
    
    
    
};


struct GameObject {

    

    
    
    
     Component add_component(Type component_type);
     TuringMesh add_or_get_mesh();
     void broadcast_message(std::string_view method_name, int32_t options);
     bool compare_tag(std::string_view tag);
     bool get_active();
     bool get_active_in_hierarchy();
     bool get_active_self();
     Component get_component_at_index(int32_t index);
     Component get_component_by_name(std::string_view cs_type);
     Component get_component_by_type(Type cs_type);
     int32_t get_component_count();
     Component get_component_in_children_by_type(Type cs_type, bool include_inactive);
     Component get_component_in_parent_by_type(Type cs_type, bool include_inactive);
     int32_t get_component_index(Component component);
     int32_t get_hide_flags();
     int32_t get_instance_id();
     bool get_is_static();
     int32_t get_layer();
     std::string get_name();
     uint64_t get_scene_culling_mask();
     std::string get_tag();
     Transform get_transform();
     void send_message(std::string_view method_name, int32_t options);
     void send_message_upwards(std::string_view method_name, int32_t options);
     void set_active(bool value);
     void set_active_prop(bool value);
     void set_active_recursively(bool state);
     void set_hide_flags(int32_t value);
     void set_is_static(bool value);
     void set_layer(int32_t value);
     void set_name(std::string_view value);
     void set_tag(std::string_view value);
    
};


struct GcHelper {

    
     static GCHelper create();

    
    
    
     void dispose();
     void invalidate_all_handles();
     void wasm_garbage_collect();
    
};


struct IAudioTimeSource {

    

    
    
    
    
};


struct IEnumerator {

    

    
    
    
    
};


struct IVariableMovementDataProvider {

    

    
    
    
    
};


struct Int32 {

    

    
    
    
    
};


struct List1 {

    

    
    
    
    
};


struct Log {

    
     static void critical(std::string_view msg);
     static void debug(std::string_view msg);
     static void info(std::string_view msg);
     static void warn(std::string_view msg);

    
    
    
    
};


struct Mesh {

    

    
    
    
    
};


struct NoteController {

    

    
    
    
     NoteFloorMovement get_note_floor_movement();
     NoteJump get_note_jump();
    
};


struct NoteControllerBase {

    

    
    
    
    
};


struct NoteFloorMovement {

    

    
    
    
     IAudioTimeSource _audio_time_sync_controller_get();
     float _beat_time_get();
     void _beat_time_set(float value);
     glm::quat _inverse_world_rotation_get();
     void _inverse_world_rotation_set(glm::quat value);
     glm::vec3 _local_position_get();
     void _local_position_set(glm::vec3 value);
     glm::vec3 _move_end_offset_get();
     void _move_end_offset_set(glm::vec3 value);
     glm::vec3 _move_start_offset_get();
     void _move_start_offset_set(glm::vec3 value);
     PlayerTransforms _player_transforms_get();
     Transform _rotated_object_get();
     void _rotated_object_set(Transform value);
     IVariableMovementDataProvider _variable_movement_data_provider_get();
     glm::quat _world_rotation_get();
     void _world_rotation_set(glm::quat value);
     float distance_to_player_get();
     glm::vec3 end_pos_get();
     void init_(float world_rotation, float beat_time, glm::vec3 move_start_offset, glm::vec3 move_end_offset);
     glm::quat inverse_world_rotation_get();
     glm::vec3 local_position_get();
     glm::vec3 manual_update();
     float note_time_get();
     glm::vec3 set_to_start();
     bool should_move();
     glm::quat world_rotation_get();
    
};


struct NoteJump {

    
     static float k_missed_time_offset_get();

    
    
    
     IAudioTimeSource _audio_time_sync_controller_get();
     float _end_distance_offset_get();
     void _end_distance_offset_set(float value);
     glm::vec3 _end_offset_get();
     void _end_offset_set(glm::vec3 value);
     glm::vec3 _end_pos_get();
     void _end_pos_set(glm::vec3 value);
     glm::quat _end_rotation_get();
     void _end_rotation_set(glm::quat value);
     float _gravity_base_get();
     void _gravity_base_set(float value);
     float _gravity_get();
     void _gravity_set(float value);
     float _half_jump_duration_get();
     void _half_jump_duration_set(float value);
     bool _half_jump_mark_reported_get();
     void _half_jump_mark_reported_set(bool value);
     glm::quat _inverse_world_rotation_get();
     void _inverse_world_rotation_set(glm::quat value);
     float _jump_duration_get();
     void _jump_duration_set(float value);
     bool _jump_started_reported_get();
     void _jump_started_reported_set(bool value);
     glm::vec3 _local_position_get();
     void _local_position_set(glm::vec3 value);
     glm::quat _middle_rotation_get();
     void _middle_rotation_set(glm::quat value);
     bool _missed_mark_reported_get();
     void _missed_mark_reported_set(bool value);
     float _missed_time_get();
     void _missed_time_set(float value);
     float _note_time_get();
     void _note_time_set(float value);
     PlayerSpaceConvertor _player_space_convertor_get();
     PlayerTransforms _player_transforms_get();
     bool _rotate_towards_player_get();
     void _rotate_towards_player_set(bool value);
     Transform _rotated_object_get();
     void _rotated_object_set(Transform value);
     glm::vec3 _start_offset_get();
     void _start_offset_set(glm::vec3 value);
     glm::vec3 _start_pos_get();
     void _start_pos_set(glm::vec3 value);
     glm::quat _start_rotation_get();
     void _start_rotation_set(glm::quat value);
     bool _three_quarters_mark_reported_get();
     void _three_quarters_mark_reported_set(bool value);
     IVariableMovementDataProvider _variable_movement_data_provider_get();
     glm::quat _world_rotation_get();
     void _world_rotation_set(glm::quat value);
     float _y_avoidance_down_get();
     void _y_avoidance_down_set(float value);
     float _y_avoidance_get();
     void _y_avoidance_set(float value);
     float _y_avoidance_up_get();
     void _y_avoidance_up_set(float value);
     void add_note_jump_did_finish_event(Action value);
     void add_note_jump_did_pass_half_event(Action value);
     void add_note_jump_did_pass_missed_marker_event(Action value);
     void add_note_jump_did_pass_three_quarters_event(Action1 value);
     void add_note_jump_did_start_event(Action value);
     void add_note_jump_did_update_progress_event(Action1 value);
     glm::vec3 beat_pos_get();
     float distance_to_player_get();
     void init_(float note_time, float world_rotation, glm::vec3 move_end_offset, glm::vec3 jump_end_offset, float gravity_base, float flip_y_side, float end_rotation, bool rotate_towards_player, bool use_random_rotation);
     glm::vec3 local_position_get();
     glm::vec3 manual_update();
     glm::vec3 move_vec_get();
     float note_time_get();
     void remove_note_jump_did_finish_event(Action value);
     void remove_note_jump_did_pass_half_event(Action value);
     void remove_note_jump_did_pass_missed_marker_event(Action value);
     void remove_note_jump_did_pass_three_quarters_event(Action1 value);
     void remove_note_jump_did_start_event(Action value);
     void remove_note_jump_did_update_progress_event(Action1 value);
    
};


struct NoteManager {

    
     static CustomNoteData add_bomb_note(float beat, int32_t line, int32_t layer, CustomData custom_data);
     static CustomNoteData add_color_note(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data);
     static CustomObstacleData add_obstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data);
     static NoteControllerBase get_note_controller(int32_t n);
     static NoteControllerBase get_note_controller_from_custom(CustomNoteData n);
     static CustomEventData get_nth_event(int32_t id);
     static CustomNoteData get_nth_note(int32_t id);
     static BeatmapDataItem get_nth_object(int32_t id);
     static CustomObstacleData get_nth_obstacle(int32_t id);
     static ObstacleControllerBase get_obstacle_controller(int32_t n);
     static ObstacleController get_obstacle_controller_from_custom(CustomObstacleData n);
     static float time_to_beat(float time);

    
    
    
    
};


struct Object {

    

    
    
    
    
};


struct ObstacleController {

    

    
    
    
    
};


struct ObstacleControllerBase {

    

    
    
    
    
};


struct PlayerSpaceConvertor {

    

    
    
    
    
};


struct PlayerTransforms {

    

    
    
    
    
};


struct TaskScheduler {

    
     static void schedule(Action task);

    
    
    
     void dispose();
    
};


struct Texture2D {

    

    
    
    
     void apply(bool update_mipmaps, bool make_no_longer_readable);
     int32_t get_format();
     int32_t get_graphics_format();
     int32_t get_height();
     int32_t get_hide_flags();
     int32_t get_instance_id();
     bool get_is_readable();
     int32_t get_mipmap_count();
     std::string get_name();
     std::vector<uint32_t> get_raw_texture_data();
     int32_t get_width();
     void load_raw_texture_data(std::span<const uint32_t> data_);
     bool reinitialize(int32_t width, int32_t height, int32_t format, bool has_mip_map);
     void set_height(int32_t value);
     void set_hide_flags(int32_t value);
     void set_name(std::string_view value);
     void set_width(int32_t value);
    
};


struct Transform {

    

    
    
    
     void broadcast_message(std::string_view method_name, Object parameter, int32_t options);
     bool compare_tag(std::string_view tag);
     void detach_children();
     Transform find(std::string_view n);
     Transform find_child(std::string_view n);
     Transform get_child(int32_t index);
     int32_t get_child_count();
     int32_t get_child_count_prop();
     Component get_component_by_name(std::string_view cs_type);
     Component get_component_by_type(Type cs_type);
     Component get_component_in_children_by_type(Type t, bool include_inactive);
     Component get_component_in_parent_by_type(Type t, bool include_inactive);
     int32_t get_component_index();
     IEnumerator get_enumerator();
     glm::vec3 get_euler_angles();
     glm::vec3 get_forward();
     GameObject get_game_object();
     bool get_has_changed();
     int32_t get_hide_flags();
     int32_t get_hierarchy_capacity();
     int32_t get_hierarchy_count();
     int32_t get_instance_id();
     glm::vec3 get_local_euler_angles();
     glm::vec3 get_local_position();
     glm::quat get_local_rotation();
     glm::vec3 get_local_scale();
     glm::mat4 get_local_to_world_matrix();
     glm::vec3 get_lossy_scale();
     std::string get_name();
     Transform get_parent();
     glm::vec3 get_position();
     glm::vec3 get_right();
     Transform get_root();
     glm::quat get_rotation();
     int32_t get_sibling_index();
     std::string get_tag();
     glm::vec3 get_up();
     glm::mat4 get_world_to_local_matrix();
     glm::vec3 inverse_transform_direction(glm::vec3 direction);
     glm::vec3 inverse_transform_point(glm::vec3 position);
     glm::vec3 inverse_transform_vector(glm::vec3 vector);
     bool is_child_of(Transform parent);
     void look_at(Transform target, glm::vec3 world_up);
     void rotate(glm::vec3 eulers);
     void rotate_around(glm::vec3 point, glm::vec3 axis, float angle);
     void rotate_around_local(glm::vec3 axis, float angle);
     void rotate_relative(glm::vec3 eulers, int32_t relative_to);
     void send_message(std::string_view method_name, Object value, int32_t options);
     void send_message_upwards(std::string_view method_name, Object value, int32_t options);
     void set_as_first_sibling();
     void set_as_last_sibling();
     void set_euler_angles(glm::vec3 value);
     void set_forward(glm::vec3 value);
     void set_has_changed(bool value);
     void set_hide_flags(int32_t value);
     void set_hierarchy_capacity(int32_t value);
     void set_local_euler_angles(glm::vec3 value);
     void set_local_position(glm::vec3 value);
     void set_local_position_and_rotation(glm::vec3 local_position, glm::quat local_rotation);
     void set_local_rotation(glm::quat value);
     void set_local_scale(glm::vec3 value);
     void set_name(std::string_view value);
     void set_parent(Transform parent, bool world_position_stays);
     void set_position(glm::vec3 value);
     void set_position_and_rotation(glm::vec3 position, glm::quat rotation);
     void set_right(glm::vec3 value);
     void set_rotation(glm::quat value);
     void set_sibling_index(int32_t index);
     void set_tag(std::string_view value);
     void set_up(glm::vec3 value);
     glm::vec3 transform_direction(glm::vec3 direction);
     glm::vec3 transform_point(glm::vec3 position);
     glm::vec3 transform_vector(glm::vec3 vector);
     void translate(glm::vec3 translation, int32_t relative_to);
     void translate_relative(glm::vec3 translation, Transform relative_to);
    
};


struct TuringMesh {

    

    
    
    
     Mesh _mesh_get();
     void _mesh_set(Mesh value);
     void clear();
     float get_bounds_max_x();
     float get_bounds_max_y();
     float get_bounds_max_z();
     float get_bounds_min_x();
     float get_bounds_min_y();
     float get_bounds_min_z();
     int32_t get_instance_id();
     std::vector<uint32_t> get_u_vs(int32_t channel);
     std::vector<uint32_t> get_vertices();
     int32_t hide_flags_get();
     void hide_flags_set(int32_t value);
     void mark_modified();
     std::string name_get();
     void name_set(std::string_view value);
     void optimize();
     void optimize_index_buffers();
     void recalculate_bounds();
     void recalculate_normals();
     void recalculate_tangents();
     void set_bounds(float min_x, float min_y, float min_z, float max_x, float max_y, float max_z);
     void set_triangles(Int32 triangles, int32_t submesh, bool calculate_bounds, int32_t base_vertex);
     void set_u_vs(int32_t channel, std::span<const uint32_t> uvs);
     void set_vertices(std::span<const uint32_t> in_vertices);
     void upload_mesh_data(bool mark_no_longer_readable);
    
};


struct TuringScriptManager {

    

    
    
    
    
};


struct TuringTexture2D {

    
     static Texture2D create(int32_t width, int32_t height, int32_t format, bool mipmap);
     static void destroy(Texture2D texture_2_d);
     static Texture2D find(std::string_view name);

    
    
    
    
};


struct TuringerGameObjectManager {

    
     static GameObject create_object(std::string_view name);
     static void destroy_object(GameObject game_object);
     static GameObject find(std::string_view name);

    
    
    
     TuringerGameObjectManager instance_get();
    
};


struct Type {

    

    
    
    
    
};


struct Version {

    

    
    
    
    
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
    TURING_API_EXPORT CustomData Core_CustomData_fromJson(const char* json);
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
    TURING_API_EXPORT char* Core_CustomData_toJson(CustomData custom_data, bool pretty);
    
    TURING_API_EXPORT CustomData Core_CustomEventData_customDataGet(uint64_t opaqu);
    TURING_API_EXPORT char* Core_CustomEventData_eventTypeGet(uint64_t opaqu);
    TURING_API_EXPORT BeatmapDataItem Core_CustomEventData_getCopy(uint64_t opaqu);
    TURING_API_EXPORT Version Core_CustomEventData_versionGet(uint64_t opaqu);
    
    TURING_API_EXPORT CustomNoteData Core_CustomNoteData_createCustomBasicNoteData(float time, float beat, int32_t rotation, int32_t line_index, int32_t note_line_layer, int32_t color_type, int32_t cut_direction, CustomData custom_data, Version version);
    TURING_API_EXPORT CustomNoteData Core_CustomNoteData_createCustomBombNoteData(float time, float beat, int32_t rotation, int32_t line_index, int32_t note_line_layer, CustomData custom_data, Version version);
    TURING_API_EXPORT CustomNoteData Core_CustomNoteData_createCustomBurstSliderNoteData(float time, float beat, int32_t rotation, int32_t line_index, int32_t note_line_layer, int32_t before_jump_note_line_layer, int32_t color_type, int32_t cut_direction, float cut_sfx_volume_multiplier, CustomData custom_data);
    TURING_API_EXPORT CustomData Core_CustomNoteData_customDataGet(uint64_t opaqu);
    TURING_API_EXPORT BeatmapDataItem Core_CustomNoteData_getCopy(uint64_t opaqu);
    TURING_API_EXPORT Version Core_CustomNoteData_versionGet(uint64_t opaqu);
    
    TURING_API_EXPORT CustomData Core_CustomObstacleData_customDataGet(uint64_t opaqu);
    TURING_API_EXPORT BeatmapDataItem Core_CustomObstacleData_getCopy(uint64_t opaqu);
    TURING_API_EXPORT Version Core_CustomObstacleData_versionGet(uint64_t opaqu);
    
    
    TURING_API_EXPORT Component Core_GameObject_addComponent(uint64_t opaqu, Type component_type);
    TURING_API_EXPORT TuringMesh Core_GameObject_addOrGetMesh(uint64_t opaqu);
    TURING_API_EXPORT void Core_GameObject_broadcastMessage(uint64_t opaqu, const char* method_name, int32_t options);
    TURING_API_EXPORT bool Core_GameObject_compareTag(uint64_t opaqu, const char* tag);
    TURING_API_EXPORT bool Core_GameObject_getActive(uint64_t opaqu);
    TURING_API_EXPORT bool Core_GameObject_getActiveInHierarchy(uint64_t opaqu);
    TURING_API_EXPORT bool Core_GameObject_getActiveSelf(uint64_t opaqu);
    TURING_API_EXPORT Component Core_GameObject_getComponentAtIndex(uint64_t opaqu, int32_t index);
    TURING_API_EXPORT Component Core_GameObject_getComponentByName(uint64_t opaqu, const char* cs_type);
    TURING_API_EXPORT Component Core_GameObject_getComponentByType(uint64_t opaqu, Type cs_type);
    TURING_API_EXPORT int32_t Core_GameObject_getComponentCount(uint64_t opaqu);
    TURING_API_EXPORT Component Core_GameObject_getComponentInChildrenByType(uint64_t opaqu, Type cs_type, bool include_inactive);
    TURING_API_EXPORT Component Core_GameObject_getComponentInParentByType(uint64_t opaqu, Type cs_type, bool include_inactive);
    TURING_API_EXPORT int32_t Core_GameObject_getComponentIndex(uint64_t opaqu, Component component);
    TURING_API_EXPORT int32_t Core_GameObject_getHideFlags(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_GameObject_getInstanceId(uint64_t opaqu);
    TURING_API_EXPORT bool Core_GameObject_getIsStatic(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_GameObject_getLayer(uint64_t opaqu);
    TURING_API_EXPORT char* Core_GameObject_getName(uint64_t opaqu);
    TURING_API_EXPORT uint64_t Core_GameObject_getSceneCullingMask(uint64_t opaqu);
    TURING_API_EXPORT char* Core_GameObject_getTag(uint64_t opaqu);
    TURING_API_EXPORT Transform Core_GameObject_getTransform(uint64_t opaqu);
    TURING_API_EXPORT void Core_GameObject_sendMessage(uint64_t opaqu, const char* method_name, int32_t options);
    TURING_API_EXPORT void Core_GameObject_sendMessageUpwards(uint64_t opaqu, const char* method_name, int32_t options);
    TURING_API_EXPORT void Core_GameObject_setActive(uint64_t opaqu, bool value);
    TURING_API_EXPORT void Core_GameObject_setActiveProp(uint64_t opaqu, bool value);
    TURING_API_EXPORT void Core_GameObject_setActiveRecursively(uint64_t opaqu, bool state);
    TURING_API_EXPORT void Core_GameObject_setHideFlags(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT void Core_GameObject_setIsStatic(uint64_t opaqu, bool value);
    TURING_API_EXPORT void Core_GameObject_setLayer(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT void Core_GameObject_setName(uint64_t opaqu, const char* value);
    TURING_API_EXPORT void Core_GameObject_setTag(uint64_t opaqu, const char* value);
    
    TURING_API_EXPORT GCHelper Core_GcHelper_create();
    TURING_API_EXPORT void Core_GcHelper_dispose(uint64_t opaqu);
    TURING_API_EXPORT void Core_GcHelper_invalidateAllHandles(uint64_t opaqu);
    TURING_API_EXPORT void Core_GcHelper_wasmGarbageCollect(uint64_t opaqu);
    
    
    
    
    
    
    TURING_API_EXPORT void Core_Log_critical(const char* msg);
    TURING_API_EXPORT void Core_Log_debug(const char* msg);
    TURING_API_EXPORT void Core_Log_info(const char* msg);
    TURING_API_EXPORT void Core_Log_warn(const char* msg);
    
    
    TURING_API_EXPORT NoteFloorMovement Core_NoteController_getNoteFloorMovement(uint64_t opaqu);
    TURING_API_EXPORT NoteJump Core_NoteController_getNoteJump(uint64_t opaqu);
    
    
    TURING_API_EXPORT IAudioTimeSource Core_NoteFloorMovement_AudioTimeSyncControllerGet(uint64_t opaqu);
    TURING_API_EXPORT float Core_NoteFloorMovement_BeatTimeGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteFloorMovement_BeatTimeSet(uint64_t opaqu, float value);
    TURING_API_EXPORT versors Core_NoteFloorMovement_InverseWorldRotationGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteFloorMovement_InverseWorldRotationSet(uint64_t opaqu, versors value);
    TURING_API_EXPORT vec3s Core_NoteFloorMovement_LocalPositionGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteFloorMovement_LocalPositionSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT vec3s Core_NoteFloorMovement_MoveEndOffsetGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteFloorMovement_MoveEndOffsetSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT vec3s Core_NoteFloorMovement_MoveStartOffsetGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteFloorMovement_MoveStartOffsetSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT PlayerTransforms Core_NoteFloorMovement_PlayerTransformsGet(uint64_t opaqu);
    TURING_API_EXPORT Transform Core_NoteFloorMovement_RotatedObjectGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteFloorMovement_RotatedObjectSet(uint64_t opaqu, Transform value);
    TURING_API_EXPORT IVariableMovementDataProvider Core_NoteFloorMovement_VariableMovementDataProviderGet(uint64_t opaqu);
    TURING_API_EXPORT versors Core_NoteFloorMovement_WorldRotationGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteFloorMovement_WorldRotationSet(uint64_t opaqu, versors value);
    TURING_API_EXPORT float Core_NoteFloorMovement_distanceToPlayerGet(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_NoteFloorMovement_endPosGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteFloorMovement_init(uint64_t opaqu, float world_rotation, float beat_time, vec3s move_start_offset, vec3s move_end_offset);
    TURING_API_EXPORT versors Core_NoteFloorMovement_inverseWorldRotationGet(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_NoteFloorMovement_localPositionGet(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_NoteFloorMovement_manualUpdate(uint64_t opaqu);
    TURING_API_EXPORT float Core_NoteFloorMovement_noteTimeGet(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_NoteFloorMovement_setToStart(uint64_t opaqu);
    TURING_API_EXPORT bool Core_NoteFloorMovement_shouldMove(uint64_t opaqu);
    TURING_API_EXPORT versors Core_NoteFloorMovement_worldRotationGet(uint64_t opaqu);
    
    TURING_API_EXPORT float Core_NoteJump_kMissedTimeOffsetGet();
    TURING_API_EXPORT IAudioTimeSource Core_NoteJump_AudioTimeSyncControllerGet(uint64_t opaqu);
    TURING_API_EXPORT float Core_NoteJump_EndDistanceOffsetGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_EndDistanceOffsetSet(uint64_t opaqu, float value);
    TURING_API_EXPORT vec3s Core_NoteJump_EndOffsetGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_EndOffsetSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT vec3s Core_NoteJump_EndPosGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_EndPosSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT versors Core_NoteJump_EndRotationGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_EndRotationSet(uint64_t opaqu, versors value);
    TURING_API_EXPORT float Core_NoteJump_GravityBaseGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_GravityBaseSet(uint64_t opaqu, float value);
    TURING_API_EXPORT float Core_NoteJump_GravityGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_GravitySet(uint64_t opaqu, float value);
    TURING_API_EXPORT float Core_NoteJump_HalfJumpDurationGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_HalfJumpDurationSet(uint64_t opaqu, float value);
    TURING_API_EXPORT bool Core_NoteJump_HalfJumpMarkReportedGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_HalfJumpMarkReportedSet(uint64_t opaqu, bool value);
    TURING_API_EXPORT versors Core_NoteJump_InverseWorldRotationGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_InverseWorldRotationSet(uint64_t opaqu, versors value);
    TURING_API_EXPORT float Core_NoteJump_JumpDurationGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_JumpDurationSet(uint64_t opaqu, float value);
    TURING_API_EXPORT bool Core_NoteJump_JumpStartedReportedGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_JumpStartedReportedSet(uint64_t opaqu, bool value);
    TURING_API_EXPORT vec3s Core_NoteJump_LocalPositionGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_LocalPositionSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT versors Core_NoteJump_MiddleRotationGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_MiddleRotationSet(uint64_t opaqu, versors value);
    TURING_API_EXPORT bool Core_NoteJump_MissedMarkReportedGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_MissedMarkReportedSet(uint64_t opaqu, bool value);
    TURING_API_EXPORT float Core_NoteJump_MissedTimeGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_MissedTimeSet(uint64_t opaqu, float value);
    TURING_API_EXPORT float Core_NoteJump_NoteTimeGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_NoteTimeSet(uint64_t opaqu, float value);
    TURING_API_EXPORT PlayerSpaceConvertor Core_NoteJump_PlayerSpaceConvertorGet(uint64_t opaqu);
    TURING_API_EXPORT PlayerTransforms Core_NoteJump_PlayerTransformsGet(uint64_t opaqu);
    TURING_API_EXPORT bool Core_NoteJump_RotateTowardsPlayerGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_RotateTowardsPlayerSet(uint64_t opaqu, bool value);
    TURING_API_EXPORT Transform Core_NoteJump_RotatedObjectGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_RotatedObjectSet(uint64_t opaqu, Transform value);
    TURING_API_EXPORT vec3s Core_NoteJump_StartOffsetGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_StartOffsetSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT vec3s Core_NoteJump_StartPosGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_StartPosSet(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT versors Core_NoteJump_StartRotationGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_StartRotationSet(uint64_t opaqu, versors value);
    TURING_API_EXPORT bool Core_NoteJump_ThreeQuartersMarkReportedGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_ThreeQuartersMarkReportedSet(uint64_t opaqu, bool value);
    TURING_API_EXPORT IVariableMovementDataProvider Core_NoteJump_VariableMovementDataProviderGet(uint64_t opaqu);
    TURING_API_EXPORT versors Core_NoteJump_WorldRotationGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_WorldRotationSet(uint64_t opaqu, versors value);
    TURING_API_EXPORT float Core_NoteJump_YAvoidanceDownGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_YAvoidanceDownSet(uint64_t opaqu, float value);
    TURING_API_EXPORT float Core_NoteJump_YAvoidanceGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_YAvoidanceSet(uint64_t opaqu, float value);
    TURING_API_EXPORT float Core_NoteJump_YAvoidanceUpGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_YAvoidanceUpSet(uint64_t opaqu, float value);
    TURING_API_EXPORT void Core_NoteJump_addNoteJumpDidFinishEvent(uint64_t opaqu, Action value);
    TURING_API_EXPORT void Core_NoteJump_addNoteJumpDidPassHalfEvent(uint64_t opaqu, Action value);
    TURING_API_EXPORT void Core_NoteJump_addNoteJumpDidPassMissedMarkerEvent(uint64_t opaqu, Action value);
    TURING_API_EXPORT void Core_NoteJump_addNoteJumpDidPassThreeQuartersEvent(uint64_t opaqu, Action1 value);
    TURING_API_EXPORT void Core_NoteJump_addNoteJumpDidStartEvent(uint64_t opaqu, Action value);
    TURING_API_EXPORT void Core_NoteJump_addNoteJumpDidUpdateProgressEvent(uint64_t opaqu, Action1 value);
    TURING_API_EXPORT vec3s Core_NoteJump_beatPosGet(uint64_t opaqu);
    TURING_API_EXPORT float Core_NoteJump_distanceToPlayerGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_init(uint64_t opaqu, float note_time, float world_rotation, vec3s move_end_offset, vec3s jump_end_offset, float gravity_base, float flip_y_side, float end_rotation, bool rotate_towards_player, bool use_random_rotation);
    TURING_API_EXPORT vec3s Core_NoteJump_localPositionGet(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_NoteJump_manualUpdate(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_NoteJump_moveVecGet(uint64_t opaqu);
    TURING_API_EXPORT float Core_NoteJump_noteTimeGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_NoteJump_removeNoteJumpDidFinishEvent(uint64_t opaqu, Action value);
    TURING_API_EXPORT void Core_NoteJump_removeNoteJumpDidPassHalfEvent(uint64_t opaqu, Action value);
    TURING_API_EXPORT void Core_NoteJump_removeNoteJumpDidPassMissedMarkerEvent(uint64_t opaqu, Action value);
    TURING_API_EXPORT void Core_NoteJump_removeNoteJumpDidPassThreeQuartersEvent(uint64_t opaqu, Action1 value);
    TURING_API_EXPORT void Core_NoteJump_removeNoteJumpDidStartEvent(uint64_t opaqu, Action value);
    TURING_API_EXPORT void Core_NoteJump_removeNoteJumpDidUpdateProgressEvent(uint64_t opaqu, Action1 value);
    
    TURING_API_EXPORT CustomNoteData Core_NoteManager_addBombNote(float beat, int32_t line, int32_t layer, CustomData custom_data);
    TURING_API_EXPORT CustomNoteData Core_NoteManager_addColorNote(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data);
    TURING_API_EXPORT CustomObstacleData Core_NoteManager_addObstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data);
    TURING_API_EXPORT NoteControllerBase Core_NoteManager_getNoteController(int32_t n);
    TURING_API_EXPORT NoteControllerBase Core_NoteManager_getNoteControllerFromCustom(CustomNoteData n);
    TURING_API_EXPORT CustomEventData Core_NoteManager_getNthEvent(int32_t id);
    TURING_API_EXPORT CustomNoteData Core_NoteManager_getNthNote(int32_t id);
    TURING_API_EXPORT BeatmapDataItem Core_NoteManager_getNthObject(int32_t id);
    TURING_API_EXPORT CustomObstacleData Core_NoteManager_getNthObstacle(int32_t id);
    TURING_API_EXPORT ObstacleControllerBase Core_NoteManager_getObstacleController(int32_t n);
    TURING_API_EXPORT ObstacleController Core_NoteManager_getObstacleControllerFromCustom(CustomObstacleData n);
    TURING_API_EXPORT float Core_NoteManager_timeToBeat(float time);
    
    
    
    
    
    
    TURING_API_EXPORT void Core_TaskScheduler_schedule(Action task);
    TURING_API_EXPORT void Core_TaskScheduler_dispose(uint64_t opaqu);
    
    TURING_API_EXPORT void Core_Texture2D_apply(uint64_t opaqu, bool update_mipmaps, bool make_no_longer_readable);
    TURING_API_EXPORT int32_t Core_Texture2D_getFormat(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Texture2D_getGraphicsFormat(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Texture2D_getHeight(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Texture2D_getHideFlags(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Texture2D_getInstanceId(uint64_t opaqu);
    TURING_API_EXPORT bool Core_Texture2D_getIsReadable(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Texture2D_getMipmapCount(uint64_t opaqu);
    TURING_API_EXPORT char* Core_Texture2D_getName(uint64_t opaqu);
    TURING_API_EXPORT U32Buffer Core_Texture2D_getRawTextureData(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Texture2D_getWidth(uint64_t opaqu);
    TURING_API_EXPORT void Core_Texture2D_loadRawTextureData(uint64_t opaqu, U32Buffer data_);
    TURING_API_EXPORT bool Core_Texture2D_reinitialize(uint64_t opaqu, int32_t width, int32_t height, int32_t format, bool has_mip_map);
    TURING_API_EXPORT void Core_Texture2D_setHeight(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT void Core_Texture2D_setHideFlags(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT void Core_Texture2D_setName(uint64_t opaqu, const char* value);
    TURING_API_EXPORT void Core_Texture2D_setWidth(uint64_t opaqu, int32_t value);
    
    TURING_API_EXPORT void Core_Transform_broadcastMessage(uint64_t opaqu, const char* method_name, Object parameter, int32_t options);
    TURING_API_EXPORT bool Core_Transform_compareTag(uint64_t opaqu, const char* tag);
    TURING_API_EXPORT void Core_Transform_detachChildren(uint64_t opaqu);
    TURING_API_EXPORT Transform Core_Transform_find(uint64_t opaqu, const char* n);
    TURING_API_EXPORT Transform Core_Transform_findChild(uint64_t opaqu, const char* n);
    TURING_API_EXPORT Transform Core_Transform_getChild(uint64_t opaqu, int32_t index);
    TURING_API_EXPORT int32_t Core_Transform_getChildCount(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Transform_getChildCountProp(uint64_t opaqu);
    TURING_API_EXPORT Component Core_Transform_getComponentByName(uint64_t opaqu, const char* cs_type);
    TURING_API_EXPORT Component Core_Transform_getComponentByType(uint64_t opaqu, Type cs_type);
    TURING_API_EXPORT Component Core_Transform_getComponentInChildrenByType(uint64_t opaqu, Type t, bool include_inactive);
    TURING_API_EXPORT Component Core_Transform_getComponentInParentByType(uint64_t opaqu, Type t, bool include_inactive);
    TURING_API_EXPORT int32_t Core_Transform_getComponentIndex(uint64_t opaqu);
    TURING_API_EXPORT IEnumerator Core_Transform_getEnumerator(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_Transform_getEulerAngles(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_Transform_getForward(uint64_t opaqu);
    TURING_API_EXPORT GameObject Core_Transform_getGameObject(uint64_t opaqu);
    TURING_API_EXPORT bool Core_Transform_getHasChanged(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Transform_getHideFlags(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Transform_getHierarchyCapacity(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Transform_getHierarchyCount(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Transform_getInstanceId(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_Transform_getLocalEulerAngles(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_Transform_getLocalPosition(uint64_t opaqu);
    TURING_API_EXPORT versors Core_Transform_getLocalRotation(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_Transform_getLocalScale(uint64_t opaqu);
    TURING_API_EXPORT mat4s Core_Transform_getLocalToWorldMatrix(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_Transform_getLossyScale(uint64_t opaqu);
    TURING_API_EXPORT char* Core_Transform_getName(uint64_t opaqu);
    TURING_API_EXPORT Transform Core_Transform_getParent(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_Transform_getPosition(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_Transform_getRight(uint64_t opaqu);
    TURING_API_EXPORT Transform Core_Transform_getRoot(uint64_t opaqu);
    TURING_API_EXPORT versors Core_Transform_getRotation(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_Transform_getSiblingIndex(uint64_t opaqu);
    TURING_API_EXPORT char* Core_Transform_getTag(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_Transform_getUp(uint64_t opaqu);
    TURING_API_EXPORT mat4s Core_Transform_getWorldToLocalMatrix(uint64_t opaqu);
    TURING_API_EXPORT vec3s Core_Transform_inverseTransformDirection(uint64_t opaqu, vec3s direction);
    TURING_API_EXPORT vec3s Core_Transform_inverseTransformPoint(uint64_t opaqu, vec3s position);
    TURING_API_EXPORT vec3s Core_Transform_inverseTransformVector(uint64_t opaqu, vec3s vector);
    TURING_API_EXPORT bool Core_Transform_isChildOf(uint64_t opaqu, Transform parent);
    TURING_API_EXPORT void Core_Transform_lookAt(uint64_t opaqu, Transform target, vec3s world_up);
    TURING_API_EXPORT void Core_Transform_rotate(uint64_t opaqu, vec3s eulers);
    TURING_API_EXPORT void Core_Transform_rotateAround(uint64_t opaqu, vec3s point, vec3s axis, float angle);
    TURING_API_EXPORT void Core_Transform_rotateAroundLocal(uint64_t opaqu, vec3s axis, float angle);
    TURING_API_EXPORT void Core_Transform_rotateRelative(uint64_t opaqu, vec3s eulers, int32_t relative_to);
    TURING_API_EXPORT void Core_Transform_sendMessage(uint64_t opaqu, const char* method_name, Object value, int32_t options);
    TURING_API_EXPORT void Core_Transform_sendMessageUpwards(uint64_t opaqu, const char* method_name, Object value, int32_t options);
    TURING_API_EXPORT void Core_Transform_setAsFirstSibling(uint64_t opaqu);
    TURING_API_EXPORT void Core_Transform_setAsLastSibling(uint64_t opaqu);
    TURING_API_EXPORT void Core_Transform_setEulerAngles(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT void Core_Transform_setForward(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT void Core_Transform_setHasChanged(uint64_t opaqu, bool value);
    TURING_API_EXPORT void Core_Transform_setHideFlags(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT void Core_Transform_setHierarchyCapacity(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT void Core_Transform_setLocalEulerAngles(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT void Core_Transform_setLocalPosition(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT void Core_Transform_setLocalPositionAndRotation(uint64_t opaqu, vec3s local_position, versors local_rotation);
    TURING_API_EXPORT void Core_Transform_setLocalRotation(uint64_t opaqu, versors value);
    TURING_API_EXPORT void Core_Transform_setLocalScale(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT void Core_Transform_setName(uint64_t opaqu, const char* value);
    TURING_API_EXPORT void Core_Transform_setParent(uint64_t opaqu, Transform parent, bool world_position_stays);
    TURING_API_EXPORT void Core_Transform_setPosition(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT void Core_Transform_setPositionAndRotation(uint64_t opaqu, vec3s position, versors rotation);
    TURING_API_EXPORT void Core_Transform_setRight(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT void Core_Transform_setRotation(uint64_t opaqu, versors value);
    TURING_API_EXPORT void Core_Transform_setSiblingIndex(uint64_t opaqu, int32_t index);
    TURING_API_EXPORT void Core_Transform_setTag(uint64_t opaqu, const char* value);
    TURING_API_EXPORT void Core_Transform_setUp(uint64_t opaqu, vec3s value);
    TURING_API_EXPORT vec3s Core_Transform_transformDirection(uint64_t opaqu, vec3s direction);
    TURING_API_EXPORT vec3s Core_Transform_transformPoint(uint64_t opaqu, vec3s position);
    TURING_API_EXPORT vec3s Core_Transform_transformVector(uint64_t opaqu, vec3s vector);
    TURING_API_EXPORT void Core_Transform_translate(uint64_t opaqu, vec3s translation, int32_t relative_to);
    TURING_API_EXPORT void Core_Transform_translateRelative(uint64_t opaqu, vec3s translation, Transform relative_to);
    
    TURING_API_EXPORT Mesh Core_TuringMesh_MeshGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringMesh_MeshSet(uint64_t opaqu, Mesh value);
    TURING_API_EXPORT void Core_TuringMesh_clear(uint64_t opaqu);
    TURING_API_EXPORT float Core_TuringMesh_getBoundsMaxX(uint64_t opaqu);
    TURING_API_EXPORT float Core_TuringMesh_getBoundsMaxY(uint64_t opaqu);
    TURING_API_EXPORT float Core_TuringMesh_getBoundsMaxZ(uint64_t opaqu);
    TURING_API_EXPORT float Core_TuringMesh_getBoundsMinX(uint64_t opaqu);
    TURING_API_EXPORT float Core_TuringMesh_getBoundsMinY(uint64_t opaqu);
    TURING_API_EXPORT float Core_TuringMesh_getBoundsMinZ(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_TuringMesh_getInstanceId(uint64_t opaqu);
    TURING_API_EXPORT U32Buffer Core_TuringMesh_getUVs(uint64_t opaqu, int32_t channel);
    TURING_API_EXPORT U32Buffer Core_TuringMesh_getVertices(uint64_t opaqu);
    TURING_API_EXPORT int32_t Core_TuringMesh_hideFlagsGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringMesh_hideFlagsSet(uint64_t opaqu, int32_t value);
    TURING_API_EXPORT void Core_TuringMesh_markModified(uint64_t opaqu);
    TURING_API_EXPORT char* Core_TuringMesh_nameGet(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringMesh_nameSet(uint64_t opaqu, const char* value);
    TURING_API_EXPORT void Core_TuringMesh_optimize(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringMesh_optimizeIndexBuffers(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringMesh_recalculateBounds(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringMesh_recalculateNormals(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringMesh_recalculateTangents(uint64_t opaqu);
    TURING_API_EXPORT void Core_TuringMesh_setBounds(uint64_t opaqu, float min_x, float min_y, float min_z, float max_x, float max_y, float max_z);
    TURING_API_EXPORT void Core_TuringMesh_setTriangles(uint64_t opaqu, Int32 triangles, int32_t submesh, bool calculate_bounds, int32_t base_vertex);
    TURING_API_EXPORT void Core_TuringMesh_setUVs(uint64_t opaqu, int32_t channel, U32Buffer uvs);
    TURING_API_EXPORT void Core_TuringMesh_setVertices(uint64_t opaqu, U32Buffer in_vertices);
    TURING_API_EXPORT void Core_TuringMesh_uploadMeshData(uint64_t opaqu, bool mark_no_longer_readable);
    
    
    TURING_API_EXPORT Texture2D Core_TuringTexture2D_create(int32_t width, int32_t height, int32_t format, bool mipmap);
    TURING_API_EXPORT void Core_TuringTexture2D_destroy(Texture2D texture_2_d);
    TURING_API_EXPORT Texture2D Core_TuringTexture2D_find(const char* name);
    
    TURING_API_EXPORT GameObject Core_TuringerGameObjectManager_createObject(const char* name);
    TURING_API_EXPORT void Core_TuringerGameObjectManager_destroyObject(GameObject game_object);
    TURING_API_EXPORT GameObject Core_TuringerGameObjectManager_find(const char* name);
    TURING_API_EXPORT TuringerGameObjectManager Core_TuringerGameObjectManager_instanceGet(uint64_t opaqu);
    
    
    
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
