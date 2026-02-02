#include "./turing_api.hpp"
#include <cstring>



namespace alg {

     TURING_API_HIDDEN Vec2 dequeue_vec2() {
        Vec2 v;
        v[0] = _host_f32_dequeue();
        v[1] = _host_f32_dequeue();
        return v;
    }

     TURING_API_HIDDEN uint32_t enqueue_vec2(const Vec2& v) {
        _host_f32_enqueue(v[0]);
        _host_f32_enqueue(v[1]);
        return 2;
    }

     TURING_API_HIDDEN Vec3 dequeue_vec3() {
        Vec3 v;
        v[0] = _host_f32_dequeue();
        v[1] = _host_f32_dequeue();
        v[2] = _host_f32_dequeue();
        return v;
    }

     TURING_API_HIDDEN uint32_t enqueue_vec3(const Vec3& v) {
        _host_f32_enqueue(v[0]);
        _host_f32_enqueue(v[1]);
        _host_f32_enqueue(v[2]);
        return 3;
    }

     TURING_API_HIDDEN Vec4 dequeue_vec4() {
        Vec4 v;
        v[0] = _host_f32_dequeue();
        v[1] = _host_f32_dequeue();
        v[2] = _host_f32_dequeue();
        v[3] = _host_f32_dequeue();
        return v;
    }

     TURING_API_HIDDEN uint32_t enqueue_vec4(const Vec4& v) {
        _host_f32_enqueue(v[0]);
        _host_f32_enqueue(v[1]);
        _host_f32_enqueue(v[2]);
        _host_f32_enqueue(v[3]);
        return 4;
    }

     TURING_API_HIDDEN Quat dequeue_quat() {
          Quat q;
          q.x = _host_f32_dequeue();
          q.y = _host_f32_dequeue();
          q.z = _host_f32_dequeue();
          q.w = _host_f32_dequeue();
          return q;
    }

     TURING_API_HIDDEN uint32_t enqueue_quat(const Quat& q) {
        _host_f32_enqueue(q.x);
        _host_f32_enqueue(q.y);
        _host_f32_enqueue(q.z);
        _host_f32_enqueue(q.w);
        return 4;
    }

     TURING_API_HIDDEN Mat4 dequeue_mat4() {
        Mat4 m;
        for (int c = 0; c < 4; ++c) {
            for (int r = 0; r < 4; ++r) {
                m[c][r] = _host_f32_dequeue();
            }
        }
        return m;
    }

     TURING_API_HIDDEN uint32_t enqueue_mat4(const Mat4& m) {
        for (int c = 0; c < 4; ++c) {
            for (int r = 0; r < 4; ++r) {
                _host_f32_enqueue(m[c][r]);
            }
        }
        return 16;
    }

}

// Function implementations
// GameObject methods

// methods that take self (instance methods)
// Transform methods

// methods that take self (instance methods)
// TuringScriptManager methods

// methods that take self (instance methods)
// Object methods

// methods that take self (instance methods)
// List1 methods

// methods that take self (instance methods)
// List methods

// methods that take self (instance methods)
// Component methods

// methods that take self (instance methods)
// Type methods

// methods that take self (instance methods)
// IEnumerator methods

// methods that take self (instance methods)
// Log methods

TURING_API_EXPORT void Log::warn(std::string_view msg) {
    _core_log__warn(msg.data());
}

TURING_API_EXPORT void Log::info(std::string_view msg) {
    _core_log__info(msg.data());
}

TURING_API_EXPORT void Log::debug(std::string_view msg) {
    _core_log__debug(msg.data());
}

TURING_API_EXPORT void Log::critical(std::string_view msg) {
    _core_log__critical(msg.data());
}

// methods that take self (instance methods)
// TuringerGameObject methods

// methods that take self (instance methods)

TURING_API_EXPORT Component TuringerGameObject::get_components_in_parent_by_type(Type cs_type, bool include_inactive) {
    return _get_components_in_parent_by_type(this->opaqu, cs_type, include_inactive);
}

TURING_API_EXPORT void TuringerGameObject::send_message(std::string_view method_name, int32_t options) {
    _core_turinger_game_object__send_message(this->opaqu, method_name.data(), options);
}

TURING_API_EXPORT Component TuringerGameObject::get_component_in_parent_by_type(Type cs_type, bool include_inactive) {
    return _core_turinger_game_object__get_component_in_parent_by_type(this->opaqu, cs_type, include_inactive);
}

TURING_API_EXPORT bool TuringerGameObject::is_static_get() {
    return _core_turinger_game_object__is_static_get(this->opaqu);
}

TURING_API_EXPORT TuringerTransform TuringerGameObject::transform_get() {
    return _core_turinger_game_object__transform_get(this->opaqu);
}

TURING_API_EXPORT Component TuringerGameObject::get_component_in_children_by_type(Type cs_type, bool include_inactive) {
    return _core_turinger_game_object__get_component_in_children_by_type(this->opaqu, cs_type, include_inactive);
}

TURING_API_EXPORT Component TuringerGameObject::get_components_by_type(Type cs_type) {
    return _get_components_by_type(this->opaqu, cs_type);
}

TURING_API_EXPORT void TuringerGameObject::active_set(bool value) {
    _core_turinger_game_object__active_set(this->opaqu, value);
}

TURING_API_EXPORT void TuringerGameObject::broadcast_message(std::string_view method_name, int32_t options) {
    _core_turinger_game_object__broadcast_message(this->opaqu, method_name.data(), options);
}

TURING_API_EXPORT GameObject TuringerGameObject::game_object_get() {
    return _core_turinger_game_object__game_object_get(this->opaqu);
}

TURING_API_EXPORT void TuringerGameObject::is_static_set(bool value) {
    _core_turinger_game_object__is_static_set(this->opaqu, value);
}

TURING_API_EXPORT Component TuringerGameObject::add_component(Type component_type) {
    return _core_turinger_game_object__add_component(this->opaqu, component_type);
}

TURING_API_EXPORT void TuringerGameObject::hide_flags_set(int32_t value) {
    _core_turinger_game_object__hide_flags_set(this->opaqu, value);
}

TURING_API_EXPORT void TuringerGameObject::send_message_upwards(std::string_view method_name, int32_t options) {
    _core_turinger_game_object__send_message_upwards(this->opaqu, method_name.data(), options);
}

TURING_API_EXPORT bool TuringerGameObject::compare_tag(std::string_view tag) {
    return _core_turinger_game_object__compare_tag(this->opaqu, tag.data());
}

TURING_API_EXPORT int32_t TuringerGameObject::hide_flags_get() {
    return _core_turinger_game_object__hide_flags_get(this->opaqu);
}

TURING_API_EXPORT void TuringerGameObject::tag_set(std::string_view value) {
    _core_turinger_game_object__tag_set(this->opaqu, value.data());
}

TURING_API_EXPORT int32_t TuringerGameObject::get_instance_id() {
    return _core_turinger_game_object__get_instance_id(this->opaqu);
}

TURING_API_EXPORT int32_t TuringerGameObject::layer_get() {
    return _core_turinger_game_object__layer_get(this->opaqu);
}

TURING_API_EXPORT Component TuringerGameObject::get_components_in_children_by_type(Type cs_type, bool include_inactive) {
    return _get_components_in_children_by_type(this->opaqu, cs_type, include_inactive);
}

TURING_API_EXPORT void TuringerGameObject::layer_set(int32_t value) {
    _core_turinger_game_object__layer_set(this->opaqu, value);
}

TURING_API_EXPORT void TuringerGameObject::set_active_recursively(bool state) {
    _core_turinger_game_object__set_active_recursively(this->opaqu, state);
}

TURING_API_EXPORT int32_t TuringerGameObject::get_component_index(Component component) {
    return _core_turinger_game_object__get_component_index(this->opaqu, component);
}

TURING_API_EXPORT int32_t TuringerGameObject::get_component_count() {
    return _core_turinger_game_object__get_component_count(this->opaqu);
}

TURING_API_EXPORT Component TuringerGameObject::get_component_at_index(int32_t index) {
    return _core_turinger_game_object__get_component_at_index(this->opaqu, index);
}

TURING_API_EXPORT std::string TuringerGameObject::tag_get() {
    const char* turing_result = _core_turinger_game_object__tag_get(this->opaqu);
    return std::string(turing_result);
}

TURING_API_EXPORT bool TuringerGameObject::active_self_get() {
    return _core_turinger_game_object__active_self_get(this->opaqu);
}

TURING_API_EXPORT std::string TuringerGameObject::name_get() {
    const char* turing_result = _core_turinger_game_object__name_get(this->opaqu);
    return std::string(turing_result);
}

TURING_API_EXPORT Component TuringerGameObject::get_component_by_type(Type cs_type) {
    return _core_turinger_game_object__get_component_by_type(this->opaqu, cs_type);
}

TURING_API_EXPORT bool TuringerGameObject::active_in_hierarchy_get() {
    return _core_turinger_game_object__active_in_hierarchy_get(this->opaqu);
}

TURING_API_EXPORT void TuringerGameObject::set_active(bool value) {
    _core_turinger_game_object__set_active(this->opaqu, value);
}

TURING_API_EXPORT bool TuringerGameObject::active_get() {
    return _core_turinger_game_object__active_get(this->opaqu);
}

TURING_API_EXPORT Component TuringerGameObject::get_component_by_name(std::string_view cs_type) {
    return _core_turinger_game_object__get_component_by_name(this->opaqu, cs_type.data());
}

TURING_API_EXPORT void TuringerGameObject::name_set(std::string_view value) {
    _core_turinger_game_object__name_set(this->opaqu, value.data());
}

TURING_API_EXPORT uint64_t TuringerGameObject::scene_culling_mask_get() {
    return _core_turinger_game_object__scene_culling_mask_get(this->opaqu);
}
// TuringerGameObjectManager methods

TURING_API_EXPORT TuringerGameObject TuringerGameObjectManager::create_object(std::string_view name) {
    return _core_turinger_game_object_manager__create_object(name.data());
}

TURING_API_EXPORT TuringerGameObject TuringerGameObjectManager::find(std::string_view name) {
    return _core_turinger_game_object_manager__find(name.data());
}

TURING_API_EXPORT void TuringerGameObjectManager::destroy_object(TuringerGameObject listener) {
    _core_turinger_game_object_manager__destroy_object(listener);
}

// methods that take self (instance methods)

TURING_API_EXPORT TuringerGameObjectManager TuringerGameObjectManager::instance_get() {
    return _core_turinger_game_object_manager__instance_get(this->opaqu);
}
// CustomData methods

TURING_API_EXPORT CustomData CustomData::create() {
    return _core_custom_data__create();
}

TURING_API_EXPORT List CustomData::list_create() {
    return _list_create();
}

TURING_API_EXPORT void CustomData::set_string(CustomData custom_data, std::string_view key, std::string_view value) {
    _core_custom_data__set_string(custom_data, key.data(), value.data());
}

TURING_API_EXPORT void CustomData::set_custom_data(CustomData custom_data, std::string_view key, CustomData value) {
    _core_custom_data__set_custom_data(custom_data, key.data(), value);
}

TURING_API_EXPORT void CustomData::list_add_string(List1 list, std::string_view value) {
    _core_custom_data__list_add_string(list, value.data());
}

TURING_API_EXPORT void CustomData::set_custom_data_list(CustomData custom_data, std::string_view key, List1 value) {
    _core_custom_data__set_custom_data_list(custom_data, key.data(), value);
}

TURING_API_EXPORT void CustomData::set_float(CustomData custom_data, std::string_view key, float value) {
    _core_custom_data__set_float(custom_data, key.data(), value);
}

TURING_API_EXPORT void CustomData::list_add_int(List1 list, int32_t value) {
    _core_custom_data__list_add_int(list, value);
}

TURING_API_EXPORT void CustomData::list_add_bool(List1 list, bool value) {
    _core_custom_data__list_add_bool(list, value);
}

TURING_API_EXPORT void CustomData::set_int(CustomData custom_data, std::string_view key, int32_t value) {
    _core_custom_data__set_int(custom_data, key.data(), value);
}

TURING_API_EXPORT void CustomData::set_bool(CustomData custom_data, std::string_view key, bool value) {
    _core_custom_data__set_bool(custom_data, key.data(), value);
}

TURING_API_EXPORT void CustomData::list_add_custom_data_list(List1 list, List1 value) {
    _core_custom_data__list_add_custom_data_list(list, value);
}

TURING_API_EXPORT void CustomData::list_add_float(List1 list, float value) {
    _core_custom_data__list_add_float(list, value);
}

TURING_API_EXPORT void CustomData::list_add_custom_data(List1 list, CustomData value) {
    _core_custom_data__list_add_custom_data(list, value);
}

// methods that take self (instance methods)
// GCHelper methods

TURING_API_EXPORT GCHelper GcHelper::create() {
    return _core_gc_helper__create();
}

// methods that take self (instance methods)

TURING_API_EXPORT void GcHelper::wasm_garbage_collect() {
    _core_gc_helper__wasm_garbage_collect(this->opaqu);
}

TURING_API_EXPORT void GcHelper::dispose() {
    _core_gc_helper__dispose(this->opaqu);
}

TURING_API_EXPORT void GcHelper::invalidate_all_handles() {
    _core_gc_helper__invalidate_all_handles(this->opaqu);
}
// NoteManager methods

TURING_API_EXPORT void NoteManager::add_obstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data) {
    _core_note_manager__add_obstacle(beat, duration, line, layer, width, height, custom_data);
}

TURING_API_EXPORT void NoteManager::add_color_note(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data) {
    _core_note_manager__add_color_note(beat, line, layer, color, cut_direction, custom_data);
}

TURING_API_EXPORT float NoteManager::time_to_beat(float time) {
    return _core_note_manager__time_to_beat(time);
}

TURING_API_EXPORT void NoteManager::add_bomb_note(float beat, int32_t line, int32_t layer, CustomData custom_data) {
    _core_note_manager__add_bomb_note(beat, line, layer, custom_data);
}

// methods that take self (instance methods)
// Xr methods

TURING_API_EXPORT int32_t Xr::get_device_tracking_state(int32_t node_int) {
    return _core_xr__get_device_tracking_state(node_int);
}

TURING_API_EXPORT std::string Xr::get_device_name(int32_t node_int) {
    const char* turing_result = _core_xr__get_device_name(node_int);
    return std::string(turing_result);
}

TURING_API_EXPORT bool Xr::get_device_secondary_button_state(int32_t node_int) {
    return _core_xr__get_device_secondary_button_state(node_int);
}

TURING_API_EXPORT bool Xr::get_device_primary_button_state(int32_t node_int) {
    return _core_xr__get_device_primary_button_state(node_int);
}

TURING_API_EXPORT void Xr::send_haptic_impulse(int32_t node_int, float amplitude, float duration) {
    _core_xr__send_haptic_impulse(node_int, amplitude, duration);
}

TURING_API_EXPORT bool Xr::is_device_valid(int32_t node_int) {
    return _core_xr__is_device_valid(node_int);
}

TURING_API_EXPORT float Xr::get_device_battery_level(int32_t node_int) {
    return _core_xr__get_device_battery_level(node_int);
}

TURING_API_EXPORT glm::vec2 Xr::get_device_touchpad(int32_t node_int) {
    _core_xr__get_device_touchpad(node_int);
    return alg::dequeue_vec2();
}

TURING_API_EXPORT float Xr::get_device_grip_value(int32_t node_int) {
    return _core_xr__get_device_grip_value(node_int);
}

TURING_API_EXPORT float Xr::get_device_trigger_value(int32_t node_int) {
    return _core_xr__get_device_trigger_value(node_int);
}

TURING_API_EXPORT void Xr::stop_haptics(int32_t node_int) {
    _core_xr__stop_haptics(node_int);
}

TURING_API_EXPORT glm::vec2 Xr::get_device_thumbstick(int32_t node_int) {
    _core_xr__get_device_thumbstick(node_int);
    return alg::dequeue_vec2();
}

// methods that take self (instance methods)

TURING_API_EXPORT TuringScriptManager Xr::_manager_get() {
    return _core_xr___manager_get(this->opaqu);
}
// TuringerTransform methods

// methods that take self (instance methods)

TURING_API_EXPORT Component TuringerTransform::get_component_by_type(Type cs_type) {
    return _core_turinger_transform__get_component_by_type(this->opaqu, cs_type);
}

TURING_API_EXPORT void TuringerTransform::look_at(TuringerTransform target, glm::vec3 world_up) {
    _core_turinger_transform__look_at(this->opaqu, target, world_up);
}

TURING_API_EXPORT int32_t TuringerTransform::get_instance_id() {
    return _core_turinger_transform__get_instance_id(this->opaqu);
}

TURING_API_EXPORT std::string TuringerTransform::tag_get() {
    const char* turing_result = _core_turinger_transform__tag_get(this->opaqu);
    return std::string(turing_result);
}

TURING_API_EXPORT glm::vec3 TuringerTransform::local_euler_angles_get() {
    _core_turinger_transform__local_euler_angles_get(this->opaqu);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT glm::quat TuringerTransform::rotation_get() {
    _core_turinger_transform__rotation_get(this->opaqu);
    return alg::dequeue_quat();
}

TURING_API_EXPORT glm::mat4 TuringerTransform::world_to_local_matrix_get() {
    _core_turinger_transform__world_to_local_matrix_get(this->opaqu);
    return alg::dequeue_mat4();
}

TURING_API_EXPORT int32_t TuringerTransform::hierarchy_count_get() {
    return _core_turinger_transform__hierarchy_count_get(this->opaqu);
}

TURING_API_EXPORT Component TuringerTransform::get_components_in_children_by_type(Type t, bool include_inactive) {
    return _get_components_in_children_by_type(this->opaqu, t, include_inactive);
}

TURING_API_EXPORT void TuringerTransform::name_set(std::string_view value) {
    _core_turinger_transform__name_set(this->opaqu, value.data());
}

TURING_API_EXPORT glm::quat TuringerTransform::local_rotation_get() {
    _core_turinger_transform__local_rotation_get(this->opaqu);
    return alg::dequeue_quat();
}

TURING_API_EXPORT void TuringerTransform::detach_children() {
    _core_turinger_transform__detach_children(this->opaqu);
}

TURING_API_EXPORT glm::vec3 TuringerTransform::inverse_transform_point(glm::vec3 position) {
    _core_turinger_transform__inverse_transform_point(this->opaqu, position);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT Component TuringerTransform::get_component_in_children_by_type(Type t, bool include_inactive) {
    return _core_turinger_transform__get_component_in_children_by_type(this->opaqu, t, include_inactive);
}

TURING_API_EXPORT Transform TuringerTransform::transform_get() {
    return _core_turinger_transform__transform_get(this->opaqu);
}

TURING_API_EXPORT glm::vec3 TuringerTransform::lossy_scale_get() {
    _core_turinger_transform__lossy_scale_get(this->opaqu);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT TuringerTransform TuringerTransform::root_get() {
    return _core_turinger_transform__root_get(this->opaqu);
}

TURING_API_EXPORT Component TuringerTransform::get_components_by_type(Type cs_type) {
    return _get_components_by_type(this->opaqu, cs_type);
}

TURING_API_EXPORT IEnumerator TuringerTransform::get_enumerator() {
    return _core_turinger_transform__get_enumerator(this->opaqu);
}

TURING_API_EXPORT void TuringerTransform::local_scale_set(glm::vec3 value) {
    _core_turinger_transform__local_scale_set(this->opaqu, value);
}

TURING_API_EXPORT int32_t TuringerTransform::child_count_get() {
    return _core_turinger_transform__child_count_get(this->opaqu);
}

TURING_API_EXPORT void TuringerTransform::parent_set(TuringerTransform value) {
    _core_turinger_transform__parent_set(this->opaqu, value);
}

TURING_API_EXPORT TuringerTransform TuringerTransform::get_child(int32_t index) {
    return _core_turinger_transform__get_child(this->opaqu, index);
}

TURING_API_EXPORT glm::vec3 TuringerTransform::transform_direction(glm::vec3 direction) {
    _core_turinger_transform__transform_direction(this->opaqu, direction);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT void TuringerTransform::has_changed_set(bool value) {
    _core_turinger_transform__has_changed_set(this->opaqu, value);
}

TURING_API_EXPORT void TuringerTransform::send_message_upwards(std::string_view method_name, Object value, int32_t options) {
    _core_turinger_transform__send_message_upwards(this->opaqu, method_name.data(), value, options);
}

TURING_API_EXPORT TuringerTransform TuringerTransform::find_child(std::string_view n) {
    return _core_turinger_transform__find_child(this->opaqu, n.data());
}

TURING_API_EXPORT Component TuringerTransform::get_components_in_parent_by_type(Type t, bool include_inactive) {
    return _get_components_in_parent_by_type(this->opaqu, t, include_inactive);
}

TURING_API_EXPORT void TuringerTransform::rotate(glm::vec3 eulers) {
    _core_turinger_transform__rotate(this->opaqu, eulers);
}

TURING_API_EXPORT bool TuringerTransform::has_changed_get() {
    return _core_turinger_transform__has_changed_get(this->opaqu);
}

TURING_API_EXPORT glm::vec3 TuringerTransform::local_position_get() {
    _core_turinger_transform__local_position_get(this->opaqu);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT void TuringerTransform::translate_relative(glm::vec3 translation, TuringerTransform relative_to) {
    _core_turinger_transform__translate_relative(this->opaqu, translation, relative_to);
}

TURING_API_EXPORT void TuringerTransform::local_euler_angles_set(glm::vec3 value) {
    _core_turinger_transform__local_euler_angles_set(this->opaqu, value);
}

TURING_API_EXPORT void TuringerTransform::set_local_position_and_rotation(glm::vec3 local_position, glm::quat local_rotation) {
    _core_turinger_transform__set_local_position_and_rotation(this->opaqu, local_position, local_rotation);
}

TURING_API_EXPORT glm::vec3 TuringerTransform::forward_get() {
    _core_turinger_transform__forward_get(this->opaqu);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT int32_t TuringerTransform::get_sibling_index() {
    return _core_turinger_transform__get_sibling_index(this->opaqu);
}

TURING_API_EXPORT Component TuringerTransform::get_component_in_parent_by_type(Type t, bool include_inactive) {
    return _core_turinger_transform__get_component_in_parent_by_type(this->opaqu, t, include_inactive);
}

TURING_API_EXPORT glm::vec3 TuringerTransform::up_get() {
    _core_turinger_transform__up_get(this->opaqu);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT int32_t TuringerTransform::get_component_index() {
    return _core_turinger_transform__get_component_index(this->opaqu);
}

TURING_API_EXPORT void TuringerTransform::rotate_around_local(glm::vec3 axis, float angle) {
    _core_turinger_transform__rotate_around_local(this->opaqu, axis, angle);
}

TURING_API_EXPORT void TuringerTransform::translate(glm::vec3 translation, int32_t relative_to) {
    _core_turinger_transform__translate(this->opaqu, translation, relative_to);
}

TURING_API_EXPORT void TuringerTransform::broadcast_message(std::string_view method_name, Object parameter, int32_t options) {
    _core_turinger_transform__broadcast_message(this->opaqu, method_name.data(), parameter, options);
}

TURING_API_EXPORT void TuringerTransform::euler_angles_set(glm::vec3 value) {
    _core_turinger_transform__euler_angles_set(this->opaqu, value);
}

TURING_API_EXPORT void TuringerTransform::send_message(std::string_view method_name, Object value, int32_t options) {
    _core_turinger_transform__send_message(this->opaqu, method_name.data(), value, options);
}

TURING_API_EXPORT TuringerTransform TuringerTransform::parent_get() {
    return _core_turinger_transform__parent_get(this->opaqu);
}

TURING_API_EXPORT glm::mat4 TuringerTransform::local_to_world_matrix_get() {
    _core_turinger_transform__local_to_world_matrix_get(this->opaqu);
    return alg::dequeue_mat4();
}

TURING_API_EXPORT Component TuringerTransform::get_component_by_name(std::string_view cs_type) {
    return _core_turinger_transform__get_component_by_name(this->opaqu, cs_type.data());
}

TURING_API_EXPORT void TuringerTransform::set_parent(TuringerTransform parent, bool world_position_stays) {
    _core_turinger_transform__set_parent(this->opaqu, parent, world_position_stays);
}

TURING_API_EXPORT void TuringerTransform::rotate_around(glm::vec3 point, glm::vec3 axis, float angle) {
    _core_turinger_transform__rotate_around(this->opaqu, point, axis, angle);
}

TURING_API_EXPORT void TuringerTransform::hierarchy_capacity_set(int32_t value) {
    _core_turinger_transform__hierarchy_capacity_set(this->opaqu, value);
}

TURING_API_EXPORT void TuringerTransform::up_set(glm::vec3 value) {
    _core_turinger_transform__up_set(this->opaqu, value);
}

TURING_API_EXPORT glm::vec3 TuringerTransform::inverse_transform_direction(glm::vec3 direction) {
    _core_turinger_transform__inverse_transform_direction(this->opaqu, direction);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT glm::vec3 TuringerTransform::local_scale_get() {
    _core_turinger_transform__local_scale_get(this->opaqu);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT glm::vec3 TuringerTransform::transform_vector(glm::vec3 vector) {
    _core_turinger_transform__transform_vector(this->opaqu, vector);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT glm::vec3 TuringerTransform::transform_point(glm::vec3 position) {
    _core_turinger_transform__transform_point(this->opaqu, position);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT glm::vec3 TuringerTransform::euler_angles_get() {
    _core_turinger_transform__euler_angles_get(this->opaqu);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT bool TuringerTransform::is_child_of(TuringerTransform parent) {
    return _core_turinger_transform__is_child_of(this->opaqu, parent);
}

TURING_API_EXPORT void TuringerTransform::right_set(glm::vec3 value) {
    _core_turinger_transform__right_set(this->opaqu, value);
}

TURING_API_EXPORT int32_t TuringerTransform::get_child_count() {
    return _core_turinger_transform__get_child_count(this->opaqu);
}

TURING_API_EXPORT int32_t TuringerTransform::hide_flags_get() {
    return _core_turinger_transform__hide_flags_get(this->opaqu);
}

TURING_API_EXPORT void TuringerTransform::rotate_relative(glm::vec3 eulers, int32_t relative_to) {
    _core_turinger_transform__rotate_relative(this->opaqu, eulers, relative_to);
}

TURING_API_EXPORT void TuringerTransform::rotation_set(glm::quat value) {
    _core_turinger_transform__rotation_set(this->opaqu, value);
}

TURING_API_EXPORT TuringerGameObject TuringerTransform::game_object_get() {
    return _core_turinger_transform__game_object_get(this->opaqu);
}

TURING_API_EXPORT int32_t TuringerTransform::hierarchy_capacity_get() {
    return _core_turinger_transform__hierarchy_capacity_get(this->opaqu);
}

TURING_API_EXPORT void TuringerTransform::set_as_first_sibling() {
    _core_turinger_transform__set_as_first_sibling(this->opaqu);
}

TURING_API_EXPORT glm::vec3 TuringerTransform::right_get() {
    _core_turinger_transform__right_get(this->opaqu);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT void TuringerTransform::local_position_set(glm::vec3 value) {
    _core_turinger_transform__local_position_set(this->opaqu, value);
}

TURING_API_EXPORT void TuringerTransform::forward_set(glm::vec3 value) {
    _core_turinger_transform__forward_set(this->opaqu, value);
}

TURING_API_EXPORT std::string TuringerTransform::name_get() {
    const char* turing_result = _core_turinger_transform__name_get(this->opaqu);
    return std::string(turing_result);
}

TURING_API_EXPORT bool TuringerTransform::compare_tag(std::string_view tag) {
    return _core_turinger_transform__compare_tag(this->opaqu, tag.data());
}

TURING_API_EXPORT void TuringerTransform::set_as_last_sibling() {
    _core_turinger_transform__set_as_last_sibling(this->opaqu);
}

TURING_API_EXPORT glm::vec3 TuringerTransform::position_get() {
    _core_turinger_transform__position_get(this->opaqu);
    return alg::dequeue_vec3();
}

TURING_API_EXPORT void TuringerTransform::set_sibling_index(int32_t index) {
    _core_turinger_transform__set_sibling_index(this->opaqu, index);
}

TURING_API_EXPORT void TuringerTransform::position_set(glm::vec3 value) {
    _core_turinger_transform__position_set(this->opaqu, value);
}

TURING_API_EXPORT void TuringerTransform::hide_flags_set(int32_t value) {
    _core_turinger_transform__hide_flags_set(this->opaqu, value);
}

TURING_API_EXPORT void TuringerTransform::set_position_and_rotation(glm::vec3 position, glm::quat rotation) {
    _core_turinger_transform__set_position_and_rotation(this->opaqu, position, rotation);
}

TURING_API_EXPORT TuringerTransform TuringerTransform::find(std::string_view n) {
    return _core_turinger_transform__find(this->opaqu, n.data());
}

TURING_API_EXPORT void TuringerTransform::tag_set(std::string_view value) {
    _core_turinger_transform__tag_set(this->opaqu, value.data());
}

TURING_API_EXPORT void TuringerTransform::local_rotation_set(glm::quat value) {
    _core_turinger_transform__local_rotation_set(this->opaqu, value);
}

TURING_API_EXPORT glm::vec3 TuringerTransform::inverse_transform_vector(glm::vec3 vector) {
    _core_turinger_transform__inverse_transform_vector(this->opaqu, vector);
    return alg::dequeue_vec3();
}
