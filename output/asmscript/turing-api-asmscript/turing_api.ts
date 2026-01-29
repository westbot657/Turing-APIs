
///// Generated AssemblyScript API /////
import { Vec2, Vec3, Vec4, Quat, Mat4 } from "./linear_algebra";

//// Wasm Bindings ////
@external("env", "_host_strcpy")
declare function _host_strcpy(location: u32, size: u32): void;
@external("env", "_host_f32_enqueue")
declare function _host_f32_enqueue(f: f32): void;
@external("env", "_host_f32_dequeue")
declare function _host_f32_dequeue(): f32;











@external("env", "_log__warn")
declare function _log__warn(msg: u32): void;
@external("env", "_log__info")
declare function _log__info(msg: u32): void;
@external("env", "_log__debug")
declare function _log__debug(msg: u32): void;
@external("env", "_log__critical")
declare function _log__critical(msg: u32): void;

@external("env", "_note_manager__add_obstacle")
declare function _note_manager__add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: CustomData): void;
@external("env", "_note_manager__add_color_note")
declare function _note_manager__add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: CustomData): void;
@external("env", "_note_manager__time_to_beat")
declare function _note_manager__time_to_beat(time: f32): f32;
@external("env", "_note_manager__add_bomb_note")
declare function _note_manager__add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: CustomData): void;

@external("env", "_turinger_game_object_manager__create_object")
declare function _turinger_game_object_manager__create_object(name: u32): TuringerGameObject;
@external("env", "_turinger_game_object_manager__find")
declare function _turinger_game_object_manager__find(name: u32): TuringerGameObject;
@external("env", "_turinger_game_object_manager__destroy_object")
declare function _turinger_game_object_manager__destroy_object(listener: TuringerGameObject): void;

@external("env", "_turinger_game_object_manager__instance_get")
declare function _turinger_game_object_manager__instance_get(opaqu: u64): TuringerGameObjectManager;

@external("env", "_get_components_in_parent_by_type")
declare function _get_components_in_parent_by_type(opaqu: u64, cs_type: Type, include_inactive: bool): Component;
@external("env", "_turinger_game_object__send_message")
declare function _turinger_game_object__send_message(opaqu: u64, method_name: u32): void;
@external("env", "_turinger_game_object__get_component_in_parent_by_type")
declare function _turinger_game_object__get_component_in_parent_by_type(opaqu: u64, cs_type: Type): Component;
@external("env", "_turinger_game_object__is_static_get")
declare function _turinger_game_object__is_static_get(opaqu: u64): bool;
@external("env", "_turinger_game_object__transform_get")
declare function _turinger_game_object__transform_get(opaqu: u64): TuringerTransform;
@external("env", "_turinger_game_object__get_component_in_children_by_type")
declare function _turinger_game_object__get_component_in_children_by_type(opaqu: u64, cs_type: Type): Component;
@external("env", "_turinger_game_object__get_components_by_type")
declare function _turinger_game_object__get_components_by_type(opaqu: u64, cs_type: Type, results: List1): void;
@external("env", "_turinger_game_object__active_set")
declare function _turinger_game_object__active_set(opaqu: u64, value: bool): void;
@external("env", "_turinger_game_object__broadcast_message")
declare function _turinger_game_object__broadcast_message(opaqu: u64, method_name: u32): void;
@external("env", "_turinger_game_object__game_object_get")
declare function _turinger_game_object__game_object_get(opaqu: u64): GameObject;
@external("env", "_turinger_game_object__is_static_set")
declare function _turinger_game_object__is_static_set(opaqu: u64, value: bool): void;
@external("env", "_turinger_game_object__add_component")
declare function _turinger_game_object__add_component(opaqu: u64, component_type: Type): Component;
@external("env", "_turinger_game_object__hide_flags_set")
declare function _turinger_game_object__hide_flags_set(opaqu: u64, value: i32): void;
@external("env", "_turinger_game_object__send_message_upwards")
declare function _turinger_game_object__send_message_upwards(opaqu: u64, method_name: u32): void;
@external("env", "_turinger_game_object__compare_tag")
declare function _turinger_game_object__compare_tag(opaqu: u64, tag: u32): bool;
@external("env", "_turinger_game_object__hide_flags_get")
declare function _turinger_game_object__hide_flags_get(opaqu: u64): i32;
@external("env", "_turinger_game_object__tag_set")
declare function _turinger_game_object__tag_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_game_object__get_instance_id")
declare function _turinger_game_object__get_instance_id(opaqu: u64): i32;
@external("env", "_turinger_game_object__layer_get")
declare function _turinger_game_object__layer_get(opaqu: u64): i32;
@external("env", "_get_components_in_children_by_type")
declare function _get_components_in_children_by_type(opaqu: u64, cs_type: Type, include_inactive: bool): Component;
@external("env", "_turinger_game_object__layer_set")
declare function _turinger_game_object__layer_set(opaqu: u64, value: i32): void;
@external("env", "_turinger_game_object__set_active_recursively")
declare function _turinger_game_object__set_active_recursively(opaqu: u64, state: bool): void;
@external("env", "_turinger_game_object__get_component_index")
declare function _turinger_game_object__get_component_index(opaqu: u64, component: Component): i32;
@external("env", "_turinger_game_object__get_component_count")
declare function _turinger_game_object__get_component_count(opaqu: u64): i32;
@external("env", "_turinger_game_object__get_component_at_index")
declare function _turinger_game_object__get_component_at_index(opaqu: u64, index: i32): Component;
@external("env", "_turinger_game_object__tag_get")
declare function _turinger_game_object__tag_get(opaqu: u64): u32;
@external("env", "_turinger_game_object__active_self_get")
declare function _turinger_game_object__active_self_get(opaqu: u64): bool;
@external("env", "_turinger_game_object__name_get")
declare function _turinger_game_object__name_get(opaqu: u64): u32;
@external("env", "_turinger_game_object__get_component_by_type")
declare function _turinger_game_object__get_component_by_type(opaqu: u64, cs_type: Type): Component;
@external("env", "_turinger_game_object__active_in_hierarchy_get")
declare function _turinger_game_object__active_in_hierarchy_get(opaqu: u64): bool;
@external("env", "_turinger_game_object__set_active")
declare function _turinger_game_object__set_active(opaqu: u64, value: bool): void;
@external("env", "_turinger_game_object__active_get")
declare function _turinger_game_object__active_get(opaqu: u64): bool;
@external("env", "_turinger_game_object__get_component_by_name")
declare function _turinger_game_object__get_component_by_name(opaqu: u64, cs_type: u32): Component;
@external("env", "_turinger_game_object__name_set")
declare function _turinger_game_object__name_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_game_object__scene_culling_mask_get")
declare function _turinger_game_object__scene_culling_mask_get(opaqu: u64): u64;

@external("env", "_turinger_transform__get_component_by_type")
declare function _turinger_transform__get_component_by_type(opaqu: u64, cs_type: Type): Component;
@external("env", "_turinger_transform__look_at")
declare function _turinger_transform__look_at(opaqu: u64, world_position: u32): void;
@external("env", "_turinger_transform__get_instance_id")
declare function _turinger_transform__get_instance_id(opaqu: u64): i32;
@external("env", "_turinger_transform__tag_get")
declare function _turinger_transform__tag_get(opaqu: u64): u32;
@external("env", "_turinger_transform__local_euler_angles_get")
declare function _turinger_transform__local_euler_angles_get(opaqu: u64): u32;
@external("env", "_turinger_transform__rotation_get")
declare function _turinger_transform__rotation_get(opaqu: u64): u32;
@external("env", "_turinger_transform__world_to_local_matrix_get")
declare function _turinger_transform__world_to_local_matrix_get(opaqu: u64): u32;
@external("env", "_turinger_transform__hierarchy_count_get")
declare function _turinger_transform__hierarchy_count_get(opaqu: u64): i32;
@external("env", "_get_components_in_children_by_type")
declare function _get_components_in_children_by_type(opaqu: u64, t: Type, include_inactive: bool): Component;
@external("env", "_turinger_transform__name_set")
declare function _turinger_transform__name_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__local_rotation_get")
declare function _turinger_transform__local_rotation_get(opaqu: u64): u32;
@external("env", "_turinger_transform__detach_children")
declare function _turinger_transform__detach_children(opaqu: u64): void;
@external("env", "_turinger_transform__inverse_transform_point")
declare function _turinger_transform__inverse_transform_point(opaqu: u64, x: f32, y: f32, z: f32): u32;
@external("env", "_turinger_transform__get_component_in_children_by_type")
declare function _turinger_transform__get_component_in_children_by_type(opaqu: u64, t: Type, include_inactive: bool): Component;
@external("env", "_turinger_transform__transform_get")
declare function _turinger_transform__transform_get(opaqu: u64): Transform;
@external("env", "_turinger_transform__lossy_scale_get")
declare function _turinger_transform__lossy_scale_get(opaqu: u64): u32;
@external("env", "_turinger_transform__root_get")
declare function _turinger_transform__root_get(opaqu: u64): TuringerTransform;
@external("env", "_turinger_transform__get_components_by_type")
declare function _turinger_transform__get_components_by_type(opaqu: u64, cs_type: Type, results: List1): void;
@external("env", "_turinger_transform__get_enumerator")
declare function _turinger_transform__get_enumerator(opaqu: u64): IEnumerator;
@external("env", "_turinger_transform__local_scale_set")
declare function _turinger_transform__local_scale_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__child_count_get")
declare function _turinger_transform__child_count_get(opaqu: u64): i32;
@external("env", "_turinger_transform__parent_set")
declare function _turinger_transform__parent_set(opaqu: u64, value: TuringerTransform): void;
@external("env", "_turinger_transform__get_child")
declare function _turinger_transform__get_child(opaqu: u64, index: i32): TuringerTransform;
@external("env", "_turinger_transform__transform_direction")
declare function _turinger_transform__transform_direction(opaqu: u64, x: f32, y: f32, z: f32): u32;
@external("env", "_turinger_transform__has_changed_set")
declare function _turinger_transform__has_changed_set(opaqu: u64, value: bool): void;
@external("env", "_turinger_transform__send_message_upwards")
declare function _turinger_transform__send_message_upwards(opaqu: u64, method_name: u32, value: Object, options: i32): void;
@external("env", "_turinger_transform__find_child")
declare function _turinger_transform__find_child(opaqu: u64, n: u32): TuringerTransform;
@external("env", "_get_components_in_parent_by_type")
declare function _get_components_in_parent_by_type(opaqu: u64, t: Type, include_inactive: bool): Component;
@external("env", "_turinger_transform__rotate")
declare function _turinger_transform__rotate(opaqu: u64, axis: u32, angle: f32): void;
@external("env", "_turinger_transform__has_changed_get")
declare function _turinger_transform__has_changed_get(opaqu: u64): bool;
@external("env", "_turinger_transform__local_position_get")
declare function _turinger_transform__local_position_get(opaqu: u64): u32;
@external("env", "_turinger_transform__translate_relative")
declare function _turinger_transform__translate_relative(opaqu: u64, translation: u32, relative_to: TuringerTransform): void;
@external("env", "_turinger_transform__local_euler_angles_set")
declare function _turinger_transform__local_euler_angles_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__set_local_position_and_rotation")
declare function _turinger_transform__set_local_position_and_rotation(opaqu: u64, local_position: u32, local_rotation: u32): void;
@external("env", "_turinger_transform__forward_get")
declare function _turinger_transform__forward_get(opaqu: u64): u32;
@external("env", "_turinger_transform__get_sibling_index")
declare function _turinger_transform__get_sibling_index(opaqu: u64): i32;
@external("env", "_turinger_transform__get_component_in_parent_by_type")
declare function _turinger_transform__get_component_in_parent_by_type(opaqu: u64, t: Type, include_inactive: bool): Component;
@external("env", "_turinger_transform__up_get")
declare function _turinger_transform__up_get(opaqu: u64): u32;
@external("env", "_turinger_transform__get_component_index")
declare function _turinger_transform__get_component_index(opaqu: u64): i32;
@external("env", "_turinger_transform__rotate_around_local")
declare function _turinger_transform__rotate_around_local(opaqu: u64, axis: u32, angle: f32): void;
@external("env", "_turinger_transform__translate")
declare function _turinger_transform__translate(opaqu: u64, translation: u32): void;
@external("env", "_turinger_transform__broadcast_message")
declare function _turinger_transform__broadcast_message(opaqu: u64, method_name: u32, parameter: Object, options: i32): void;
@external("env", "_turinger_transform__euler_angles_set")
declare function _turinger_transform__euler_angles_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__send_message")
declare function _turinger_transform__send_message(opaqu: u64, method_name: u32, value: Object, options: i32): void;
@external("env", "_turinger_transform__parent_get")
declare function _turinger_transform__parent_get(opaqu: u64): TuringerTransform;
@external("env", "_turinger_transform__local_to_world_matrix_get")
declare function _turinger_transform__local_to_world_matrix_get(opaqu: u64): u32;
@external("env", "_turinger_transform__get_component_by_name")
declare function _turinger_transform__get_component_by_name(opaqu: u64, cs_type: u32): Component;
@external("env", "_turinger_transform__set_parent")
declare function _turinger_transform__set_parent(opaqu: u64, parent: TuringerTransform, world_position_stays: bool): void;
@external("env", "_turinger_transform__rotate_around")
declare function _turinger_transform__rotate_around(opaqu: u64, axis: u32, angle: f32): void;
@external("env", "_turinger_transform__hierarchy_capacity_set")
declare function _turinger_transform__hierarchy_capacity_set(opaqu: u64, value: i32): void;
@external("env", "_turinger_transform__up_set")
declare function _turinger_transform__up_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__inverse_transform_direction")
declare function _turinger_transform__inverse_transform_direction(opaqu: u64, x: f32, y: f32, z: f32): u32;
@external("env", "_turinger_transform__local_scale_get")
declare function _turinger_transform__local_scale_get(opaqu: u64): u32;
@external("env", "_turinger_transform__transform_vector")
declare function _turinger_transform__transform_vector(opaqu: u64, x: f32, y: f32, z: f32): u32;
@external("env", "_turinger_transform__transform_point")
declare function _turinger_transform__transform_point(opaqu: u64, x: f32, y: f32, z: f32): u32;
@external("env", "_turinger_transform__euler_angles_get")
declare function _turinger_transform__euler_angles_get(opaqu: u64): u32;
@external("env", "_turinger_transform__is_child_of")
declare function _turinger_transform__is_child_of(opaqu: u64, parent: TuringerTransform): bool;
@external("env", "_turinger_transform__right_set")
declare function _turinger_transform__right_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__get_child_count")
declare function _turinger_transform__get_child_count(opaqu: u64): i32;
@external("env", "_turinger_transform__hide_flags_get")
declare function _turinger_transform__hide_flags_get(opaqu: u64): i32;
@external("env", "_turinger_transform__rotate_relative")
declare function _turinger_transform__rotate_relative(opaqu: u64, axis: u32, angle: f32, relative_to: i32): void;
@external("env", "_turinger_transform__rotation_set")
declare function _turinger_transform__rotation_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__game_object_get")
declare function _turinger_transform__game_object_get(opaqu: u64): TuringerGameObject;
@external("env", "_turinger_transform__hierarchy_capacity_get")
declare function _turinger_transform__hierarchy_capacity_get(opaqu: u64): i32;
@external("env", "_turinger_transform__set_as_first_sibling")
declare function _turinger_transform__set_as_first_sibling(opaqu: u64): void;
@external("env", "_turinger_transform__right_get")
declare function _turinger_transform__right_get(opaqu: u64): u32;
@external("env", "_turinger_transform__local_position_set")
declare function _turinger_transform__local_position_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__forward_set")
declare function _turinger_transform__forward_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__name_get")
declare function _turinger_transform__name_get(opaqu: u64): u32;
@external("env", "_turinger_transform__compare_tag")
declare function _turinger_transform__compare_tag(opaqu: u64, tag: u32): bool;
@external("env", "_turinger_transform__set_as_last_sibling")
declare function _turinger_transform__set_as_last_sibling(opaqu: u64): void;
@external("env", "_turinger_transform__position_get")
declare function _turinger_transform__position_get(opaqu: u64): u32;
@external("env", "_turinger_transform__set_sibling_index")
declare function _turinger_transform__set_sibling_index(opaqu: u64, index: i32): void;
@external("env", "_turinger_transform__position_set")
declare function _turinger_transform__position_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__hide_flags_set")
declare function _turinger_transform__hide_flags_set(opaqu: u64, value: i32): void;
@external("env", "_turinger_transform__set_position_and_rotation")
declare function _turinger_transform__set_position_and_rotation(opaqu: u64, position: u32, rotation: u32): void;
@external("env", "_turinger_transform__find")
declare function _turinger_transform__find(opaqu: u64, n: u32): TuringerTransform;
@external("env", "_turinger_transform__tag_set")
declare function _turinger_transform__tag_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__local_rotation_set")
declare function _turinger_transform__local_rotation_set(opaqu: u64, value: u32): void;
@external("env", "_turinger_transform__inverse_transform_vector")
declare function _turinger_transform__inverse_transform_vector(opaqu: u64, x: f32, y: f32, z: f32): u32;
@external("env", "_gc_helper__create")
declare function _gc_helper__create(): GCHelper;

@external("env", "_gc_helper__wasm_garbage_collect")
declare function _gc_helper__wasm_garbage_collect(opaqu: u64): void;
@external("env", "_gc_helper__dispose")
declare function _gc_helper__dispose(opaqu: u64): void;
@external("env", "_gc_helper__invalidate_all_handles")
declare function _gc_helper__invalidate_all_handles(opaqu: u64): void;
@external("env", "_xr__get_device_tracking_state")
declare function _xr__get_device_tracking_state(node_int: i32): i32;
@external("env", "_xr__get_device_name")
declare function _xr__get_device_name(node_int: i32): u32;
@external("env", "_xr__get_device_secondary_button_state")
declare function _xr__get_device_secondary_button_state(node_int: i32): bool;
@external("env", "_xr__get_device_primary_button_state")
declare function _xr__get_device_primary_button_state(node_int: i32): bool;
@external("env", "_xr__send_haptic_impulse")
declare function _xr__send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32): void;
@external("env", "_xr__is_device_valid")
declare function _xr__is_device_valid(node_int: i32): bool;
@external("env", "_xr__get_device_battery_level")
declare function _xr__get_device_battery_level(node_int: i32): f32;
@external("env", "_xr__get_device_touchpad")
declare function _xr__get_device_touchpad(node_int: i32): u32;
@external("env", "_xr__get_device_grip_value")
declare function _xr__get_device_grip_value(node_int: i32): f32;
@external("env", "_xr__get_device_trigger_value")
declare function _xr__get_device_trigger_value(node_int: i32): f32;
@external("env", "_xr__stop_haptics")
declare function _xr__stop_haptics(node_int: i32): void;
@external("env", "_xr__get_device_thumbstick")
declare function _xr__get_device_thumbstick(node_int: i32): u32;

@external("env", "_xr___manager_get")
declare function _xr___manager_get(opaqu: u64): TuringScriptManager;
@external("env", "_custom_data__create")
declare function _custom_data__create(): CustomData;
@external("env", "_list_create")
declare function _list_create(): List;
@external("env", "_custom_data__set_string")
declare function _custom_data__set_string(custom_data: CustomData, key: u32, value: u32): void;
@external("env", "_custom_data__set_custom_data")
declare function _custom_data__set_custom_data(custom_data: CustomData, key: u32, value: CustomData): void;
@external("env", "_custom_data__list_add_string")
declare function _custom_data__list_add_string(list: List1, value: u32): void;
@external("env", "_custom_data__set_custom_data_list")
declare function _custom_data__set_custom_data_list(custom_data: CustomData, key: u32, value: List1): void;
@external("env", "_custom_data__set_float")
declare function _custom_data__set_float(custom_data: CustomData, key: u32, value: f32): void;
@external("env", "_custom_data__list_add_int")
declare function _custom_data__list_add_int(list: List1, value: i32): void;
@external("env", "_custom_data__list_add_bool")
declare function _custom_data__list_add_bool(list: List1, value: bool): void;
@external("env", "_custom_data__set_int")
declare function _custom_data__set_int(custom_data: CustomData, key: u32, value: i32): void;
@external("env", "_custom_data__set_bool")
declare function _custom_data__set_bool(custom_data: CustomData, key: u32, value: bool): void;
@external("env", "_custom_data__list_add_custom_data_list")
declare function _custom_data__list_add_custom_data_list(list: List1, value: List1): void;
@external("env", "_custom_data__list_add_float")
declare function _custom_data__list_add_float(list: List1, value: f32): void;
@external("env", "_custom_data__list_add_custom_data")
declare function _custom_data__list_add_custom_data(list: List1, value: CustomData): void;
export function _turing_api_semver(): u64 {
    return (0u64 << 32) | (1u64 << 16) | 0u64;
}

//// Linear Algebra Helpers ////

// Vec2
function enqueue_vec2(v: Vec2): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    return 2;
}

function dequeue_vec2(): Vec2 {
    return new Vec2(
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

// Vec3
function enqueue_vec3(v: Vec3): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    return 3;
}

function dequeue_vec3(): Vec3 {
    return new Vec3(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

// Vec4
function enqueue_vec4(v: Vec4): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    _host_f32_enqueue(v.w);
    return 4;
}

function dequeue_vec4(): Vec4 {
    return new Vec4(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

// Quat
function enqueue_quat(q: Quat): u32 {
    _host_f32_enqueue(q.x);
    _host_f32_enqueue(q.y);
    _host_f32_enqueue(q.z);
    _host_f32_enqueue(q.w);
    return 4;
}

function dequeue_quat(): Quat {
    return new Quat(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

// Mat4 (column-major)
function enqueue_mat4(m: Mat4): u32 {
    for (let i: i32 = 0; i < 16; i++) {
        _host_f32_enqueue(m.m[i]);
    }
    return 16;
}

function dequeue_mat4(): Mat4 {
    let out = new Mat4();
    for (let i: i32 = 0; i < 16; i++) {
        out.m[i] = _host_f32_dequeue();
    }
    return out;
}

//// Functions ////



//// Classes ////

class GameObject {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


}

class Transform {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


}

class TuringScriptManager {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


}

class Object {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


}

class List1 {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


}

class List {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


}

class Component {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


}

class Type {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


}

class IEnumerator {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


}

class Log {
    


    public static warn(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log__warn(turing_handle_msg);
    }

    public static info(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log__info(turing_handle_msg);
    }

    public static debug(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log__debug(turing_handle_msg);
    }

    public static critical(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log__critical(turing_handle_msg);
    }

}

class NoteManager {
    


    public static add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: CustomData): void {
        _note_manager__add_obstacle(beat, duration, line, layer, width, height, custom_data);
    }

    public static add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: CustomData): void {
        _note_manager__add_color_note(beat, line, layer, color, cut_direction, custom_data);
    }

    public static time_to_beat(time: f32): f32 {
        return _note_manager__time_to_beat(time);
    }

    public static add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: CustomData): void {
        _note_manager__add_bomb_note(beat, line, layer, custom_data);
    }

}

class TuringerGameObjectManager {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


    public static create_object(name: string): TuringerGameObject {
        let turing_handle_name = String.UTF8.encode(name, true);
        let turing_result = _turinger_game_object_manager__create_object(turing_handle_name);
        return new TuringerGameObject(turing_result);
    }

    public static find(name: string): TuringerGameObject {
        let turing_handle_name = String.UTF8.encode(name, true);
        let turing_result = _turinger_game_object_manager__find(turing_handle_name);
        return new TuringerGameObject(turing_result);
    }

    public static destroy_object(listener: TuringerGameObject): void {
        _turinger_game_object_manager__destroy_object(listener);
    }


    public instance_get(): TuringerGameObjectManager {
        let turing_result = _turinger_game_object_manager__instance_get(this.opaqu);
        return new TuringerGameObjectManager(turing_result);
    }
}

class TuringerGameObject {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }



    public get_components_in_parent_by_type(cs_type: Type, include_inactive: bool): Component {
        let turing_result = _get_components_in_parent_by_type(this.opaqu, cs_type, include_inactive);
        return new Component(turing_result);
    }

    public send_message(method_name: string): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _turinger_game_object__send_message(this.opaqu, turing_handle_method_name);
    }

    public get_component_in_parent_by_type(cs_type: Type): Component {
        let turing_result = _turinger_game_object__get_component_in_parent_by_type(this.opaqu, cs_type);
        return new Component(turing_result);
    }

    public is_static_get(): bool {
        return _turinger_game_object__is_static_get(this.opaqu);
    }

    public transform_get(): TuringerTransform {
        let turing_result = _turinger_game_object__transform_get(this.opaqu);
        return new TuringerTransform(turing_result);
    }

    public get_component_in_children_by_type(cs_type: Type): Component {
        let turing_result = _turinger_game_object__get_component_in_children_by_type(this.opaqu, cs_type);
        return new Component(turing_result);
    }

    public get_components_by_type(cs_type: Type, results: List1): void {
        _turinger_game_object__get_components_by_type(this.opaqu, cs_type, results);
    }

    public active_set(value: bool): void {
        _turinger_game_object__active_set(this.opaqu, value);
    }

    public broadcast_message(method_name: string): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _turinger_game_object__broadcast_message(this.opaqu, turing_handle_method_name);
    }

    public game_object_get(): GameObject {
        let turing_result = _turinger_game_object__game_object_get(this.opaqu);
        return new GameObject(turing_result);
    }

    public is_static_set(value: bool): void {
        _turinger_game_object__is_static_set(this.opaqu, value);
    }

    public add_component(component_type: Type): Component {
        let turing_result = _turinger_game_object__add_component(this.opaqu, component_type);
        return new Component(turing_result);
    }

    public hide_flags_set(value: i32): void {
        _turinger_game_object__hide_flags_set(this.opaqu, value);
    }

    public send_message_upwards(method_name: string): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _turinger_game_object__send_message_upwards(this.opaqu, turing_handle_method_name);
    }

    public compare_tag(tag: string): bool {
        let turing_handle_tag = String.UTF8.encode(tag, true);
        return _turinger_game_object__compare_tag(this.opaqu, turing_handle_tag);
    }

    public hide_flags_get(): i32 {
        return _turinger_game_object__hide_flags_get(this.opaqu);
    }

    public tag_set(value: string): void {
        let turing_handle_value = String.UTF8.encode(value, true);
        _turinger_game_object__tag_set(this.opaqu, turing_handle_value);
    }

    public get_instance_id(): i32 {
        return _turinger_game_object__get_instance_id(this.opaqu);
    }

    public layer_get(): i32 {
        return _turinger_game_object__layer_get(this.opaqu);
    }

    public get_components_in_children_by_type(cs_type: Type, include_inactive: bool): Component {
        let turing_result = _get_components_in_children_by_type(this.opaqu, cs_type, include_inactive);
        return new Component(turing_result);
    }

    public layer_set(value: i32): void {
        _turinger_game_object__layer_set(this.opaqu, value);
    }

    public set_active_recursively(state: bool): void {
        _turinger_game_object__set_active_recursively(this.opaqu, state);
    }

    public get_component_index(component: Component): i32 {
        return _turinger_game_object__get_component_index(this.opaqu, component);
    }

    public get_component_count(): i32 {
        return _turinger_game_object__get_component_count(this.opaqu);
    }

    public get_component_at_index(index: i32): Component {
        let turing_result = _turinger_game_object__get_component_at_index(this.opaqu, index);
        return new Component(turing_result);
    }

    public tag_get(): string {
        let turing_result = _turinger_game_object__tag_get(this.opaqu);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public active_self_get(): bool {
        return _turinger_game_object__active_self_get(this.opaqu);
    }

    public name_get(): string {
        let turing_result = _turinger_game_object__name_get(this.opaqu);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public get_component_by_type(cs_type: Type): Component {
        let turing_result = _turinger_game_object__get_component_by_type(this.opaqu, cs_type);
        return new Component(turing_result);
    }

    public active_in_hierarchy_get(): bool {
        return _turinger_game_object__active_in_hierarchy_get(this.opaqu);
    }

    public set_active(value: bool): void {
        _turinger_game_object__set_active(this.opaqu, value);
    }

    public active_get(): bool {
        return _turinger_game_object__active_get(this.opaqu);
    }

    public get_component_by_name(cs_type: string): Component {
        let turing_handle_cs_type = String.UTF8.encode(cs_type, true);
        let turing_result = _turinger_game_object__get_component_by_name(this.opaqu, turing_handle_cs_type);
        return new Component(turing_result);
    }

    public name_set(value: string): void {
        let turing_handle_value = String.UTF8.encode(value, true);
        _turinger_game_object__name_set(this.opaqu, turing_handle_value);
    }

    public scene_culling_mask_get(): u64 {
        return _turinger_game_object__scene_culling_mask_get(this.opaqu);
    }
}

class TuringerTransform {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }



    public get_component_by_type(cs_type: Type): Component {
        let turing_result = _turinger_transform__get_component_by_type(this.opaqu, cs_type);
        return new Component(turing_result);
    }

    public look_at(world_position: Vec3): void {
        let turing_handle_world_position = enqueue_vec3(world_position);
        _turinger_transform__look_at(this.opaqu, turing_handle_world_position);
    }

    public get_instance_id(): i32 {
        return _turinger_transform__get_instance_id(this.opaqu);
    }

    public tag_get(): string {
        let turing_result = _turinger_transform__tag_get(this.opaqu);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public local_euler_angles_get(): Vec3 {
        _turinger_transform__local_euler_angles_get(this.opaqu);
        return dequeue_vec3();
    }

    public rotation_get(): Quat {
        _turinger_transform__rotation_get(this.opaqu);
        return dequeue_quat();
    }

    public world_to_local_matrix_get(): Mat4 {
        _turinger_transform__world_to_local_matrix_get(this.opaqu);
        return dequeue_mat4();
    }

    public hierarchy_count_get(): i32 {
        return _turinger_transform__hierarchy_count_get(this.opaqu);
    }

    public get_components_in_children_by_type(t: Type, include_inactive: bool): Component {
        let turing_result = _get_components_in_children_by_type(this.opaqu, t, include_inactive);
        return new Component(turing_result);
    }

    public name_set(value: string): void {
        let turing_handle_value = String.UTF8.encode(value, true);
        _turinger_transform__name_set(this.opaqu, turing_handle_value);
    }

    public local_rotation_get(): Quat {
        _turinger_transform__local_rotation_get(this.opaqu);
        return dequeue_quat();
    }

    public detach_children(): void {
        _turinger_transform__detach_children(this.opaqu);
    }

    public inverse_transform_point(x: f32, y: f32, z: f32): Vec3 {
        _turinger_transform__inverse_transform_point(this.opaqu, x, y, z);
        return dequeue_vec3();
    }

    public get_component_in_children_by_type(t: Type, include_inactive: bool): Component {
        let turing_result = _turinger_transform__get_component_in_children_by_type(this.opaqu, t, include_inactive);
        return new Component(turing_result);
    }

    public transform_get(): Transform {
        let turing_result = _turinger_transform__transform_get(this.opaqu);
        return new Transform(turing_result);
    }

    public lossy_scale_get(): Vec3 {
        _turinger_transform__lossy_scale_get(this.opaqu);
        return dequeue_vec3();
    }

    public root_get(): TuringerTransform {
        let turing_result = _turinger_transform__root_get(this.opaqu);
        return new TuringerTransform(turing_result);
    }

    public get_components_by_type(cs_type: Type, results: List1): void {
        _turinger_transform__get_components_by_type(this.opaqu, cs_type, results);
    }

    public get_enumerator(): IEnumerator {
        let turing_result = _turinger_transform__get_enumerator(this.opaqu);
        return new IEnumerator(turing_result);
    }

    public local_scale_set(value: Vec3): void {
        let turing_handle_value = enqueue_vec3(value);
        _turinger_transform__local_scale_set(this.opaqu, turing_handle_value);
    }

    public child_count_get(): i32 {
        return _turinger_transform__child_count_get(this.opaqu);
    }

    public parent_set(value: TuringerTransform): void {
        _turinger_transform__parent_set(this.opaqu, value);
    }

    public get_child(index: i32): TuringerTransform {
        let turing_result = _turinger_transform__get_child(this.opaqu, index);
        return new TuringerTransform(turing_result);
    }

    public transform_direction(x: f32, y: f32, z: f32): Vec3 {
        _turinger_transform__transform_direction(this.opaqu, x, y, z);
        return dequeue_vec3();
    }

    public has_changed_set(value: bool): void {
        _turinger_transform__has_changed_set(this.opaqu, value);
    }

    public send_message_upwards(method_name: string, value: Object, options: i32): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _turinger_transform__send_message_upwards(this.opaqu, turing_handle_method_name, value, options);
    }

    public find_child(n: string): TuringerTransform {
        let turing_handle_n = String.UTF8.encode(n, true);
        let turing_result = _turinger_transform__find_child(this.opaqu, turing_handle_n);
        return new TuringerTransform(turing_result);
    }

    public get_components_in_parent_by_type(t: Type, include_inactive: bool): Component {
        let turing_result = _get_components_in_parent_by_type(this.opaqu, t, include_inactive);
        return new Component(turing_result);
    }

    public rotate(axis: Vec3, angle: f32): void {
        let turing_handle_axis = enqueue_vec3(axis);
        _turinger_transform__rotate(this.opaqu, turing_handle_axis, angle);
    }

    public has_changed_get(): bool {
        return _turinger_transform__has_changed_get(this.opaqu);
    }

    public local_position_get(): Vec3 {
        _turinger_transform__local_position_get(this.opaqu);
        return dequeue_vec3();
    }

    public translate_relative(translation: Vec3, relative_to: TuringerTransform): void {
        let turing_handle_translation = enqueue_vec3(translation);
        _turinger_transform__translate_relative(this.opaqu, turing_handle_translation, relative_to);
    }

    public local_euler_angles_set(value: Vec3): void {
        let turing_handle_value = enqueue_vec3(value);
        _turinger_transform__local_euler_angles_set(this.opaqu, turing_handle_value);
    }

    public set_local_position_and_rotation(local_position: Vec3, local_rotation: Quat): void {
        let turing_handle_local_position = enqueue_vec3(local_position);
        let turing_handle_local_rotation = enqueue_quat(local_rotation);
        _turinger_transform__set_local_position_and_rotation(this.opaqu, turing_handle_local_position, turing_handle_local_rotation);
    }

    public forward_get(): Vec3 {
        _turinger_transform__forward_get(this.opaqu);
        return dequeue_vec3();
    }

    public get_sibling_index(): i32 {
        return _turinger_transform__get_sibling_index(this.opaqu);
    }

    public get_component_in_parent_by_type(t: Type, include_inactive: bool): Component {
        let turing_result = _turinger_transform__get_component_in_parent_by_type(this.opaqu, t, include_inactive);
        return new Component(turing_result);
    }

    public up_get(): Vec3 {
        _turinger_transform__up_get(this.opaqu);
        return dequeue_vec3();
    }

    public get_component_index(): i32 {
        return _turinger_transform__get_component_index(this.opaqu);
    }

    public rotate_around_local(axis: Vec3, angle: f32): void {
        let turing_handle_axis = enqueue_vec3(axis);
        _turinger_transform__rotate_around_local(this.opaqu, turing_handle_axis, angle);
    }

    public translate(translation: Vec3): void {
        let turing_handle_translation = enqueue_vec3(translation);
        _turinger_transform__translate(this.opaqu, turing_handle_translation);
    }

    public broadcast_message(method_name: string, parameter: Object, options: i32): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _turinger_transform__broadcast_message(this.opaqu, turing_handle_method_name, parameter, options);
    }

    public euler_angles_set(value: Vec3): void {
        let turing_handle_value = enqueue_vec3(value);
        _turinger_transform__euler_angles_set(this.opaqu, turing_handle_value);
    }

    public send_message(method_name: string, value: Object, options: i32): void {
        let turing_handle_method_name = String.UTF8.encode(method_name, true);
        _turinger_transform__send_message(this.opaqu, turing_handle_method_name, value, options);
    }

    public parent_get(): TuringerTransform {
        let turing_result = _turinger_transform__parent_get(this.opaqu);
        return new TuringerTransform(turing_result);
    }

    public local_to_world_matrix_get(): Mat4 {
        _turinger_transform__local_to_world_matrix_get(this.opaqu);
        return dequeue_mat4();
    }

    public get_component_by_name(cs_type: string): Component {
        let turing_handle_cs_type = String.UTF8.encode(cs_type, true);
        let turing_result = _turinger_transform__get_component_by_name(this.opaqu, turing_handle_cs_type);
        return new Component(turing_result);
    }

    public set_parent(parent: TuringerTransform, world_position_stays: bool): void {
        _turinger_transform__set_parent(this.opaqu, parent, world_position_stays);
    }

    public rotate_around(axis: Vec3, angle: f32): void {
        let turing_handle_axis = enqueue_vec3(axis);
        _turinger_transform__rotate_around(this.opaqu, turing_handle_axis, angle);
    }

    public hierarchy_capacity_set(value: i32): void {
        _turinger_transform__hierarchy_capacity_set(this.opaqu, value);
    }

    public up_set(value: Vec3): void {
        let turing_handle_value = enqueue_vec3(value);
        _turinger_transform__up_set(this.opaqu, turing_handle_value);
    }

    public inverse_transform_direction(x: f32, y: f32, z: f32): Vec3 {
        _turinger_transform__inverse_transform_direction(this.opaqu, x, y, z);
        return dequeue_vec3();
    }

    public local_scale_get(): Vec3 {
        _turinger_transform__local_scale_get(this.opaqu);
        return dequeue_vec3();
    }

    public transform_vector(x: f32, y: f32, z: f32): Vec3 {
        _turinger_transform__transform_vector(this.opaqu, x, y, z);
        return dequeue_vec3();
    }

    public transform_point(x: f32, y: f32, z: f32): Vec3 {
        _turinger_transform__transform_point(this.opaqu, x, y, z);
        return dequeue_vec3();
    }

    public euler_angles_get(): Vec3 {
        _turinger_transform__euler_angles_get(this.opaqu);
        return dequeue_vec3();
    }

    public is_child_of(parent: TuringerTransform): bool {
        return _turinger_transform__is_child_of(this.opaqu, parent);
    }

    public right_set(value: Vec3): void {
        let turing_handle_value = enqueue_vec3(value);
        _turinger_transform__right_set(this.opaqu, turing_handle_value);
    }

    public get_child_count(): i32 {
        return _turinger_transform__get_child_count(this.opaqu);
    }

    public hide_flags_get(): i32 {
        return _turinger_transform__hide_flags_get(this.opaqu);
    }

    public rotate_relative(axis: Vec3, angle: f32, relative_to: i32): void {
        let turing_handle_axis = enqueue_vec3(axis);
        _turinger_transform__rotate_relative(this.opaqu, turing_handle_axis, angle, relative_to);
    }

    public rotation_set(value: Quat): void {
        let turing_handle_value = enqueue_quat(value);
        _turinger_transform__rotation_set(this.opaqu, turing_handle_value);
    }

    public game_object_get(): TuringerGameObject {
        let turing_result = _turinger_transform__game_object_get(this.opaqu);
        return new TuringerGameObject(turing_result);
    }

    public hierarchy_capacity_get(): i32 {
        return _turinger_transform__hierarchy_capacity_get(this.opaqu);
    }

    public set_as_first_sibling(): void {
        _turinger_transform__set_as_first_sibling(this.opaqu);
    }

    public right_get(): Vec3 {
        _turinger_transform__right_get(this.opaqu);
        return dequeue_vec3();
    }

    public local_position_set(value: Vec3): void {
        let turing_handle_value = enqueue_vec3(value);
        _turinger_transform__local_position_set(this.opaqu, turing_handle_value);
    }

    public forward_set(value: Vec3): void {
        let turing_handle_value = enqueue_vec3(value);
        _turinger_transform__forward_set(this.opaqu, turing_handle_value);
    }

    public name_get(): string {
        let turing_result = _turinger_transform__name_get(this.opaqu);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public compare_tag(tag: string): bool {
        let turing_handle_tag = String.UTF8.encode(tag, true);
        return _turinger_transform__compare_tag(this.opaqu, turing_handle_tag);
    }

    public set_as_last_sibling(): void {
        _turinger_transform__set_as_last_sibling(this.opaqu);
    }

    public position_get(): Vec3 {
        _turinger_transform__position_get(this.opaqu);
        return dequeue_vec3();
    }

    public set_sibling_index(index: i32): void {
        _turinger_transform__set_sibling_index(this.opaqu, index);
    }

    public position_set(value: Vec3): void {
        let turing_handle_value = enqueue_vec3(value);
        _turinger_transform__position_set(this.opaqu, turing_handle_value);
    }

    public hide_flags_set(value: i32): void {
        _turinger_transform__hide_flags_set(this.opaqu, value);
    }

    public set_position_and_rotation(position: Vec3, rotation: Quat): void {
        let turing_handle_position = enqueue_vec3(position);
        let turing_handle_rotation = enqueue_quat(rotation);
        _turinger_transform__set_position_and_rotation(this.opaqu, turing_handle_position, turing_handle_rotation);
    }

    public find(n: string): TuringerTransform {
        let turing_handle_n = String.UTF8.encode(n, true);
        let turing_result = _turinger_transform__find(this.opaqu, turing_handle_n);
        return new TuringerTransform(turing_result);
    }

    public tag_set(value: string): void {
        let turing_handle_value = String.UTF8.encode(value, true);
        _turinger_transform__tag_set(this.opaqu, turing_handle_value);
    }

    public local_rotation_set(value: Quat): void {
        let turing_handle_value = enqueue_quat(value);
        _turinger_transform__local_rotation_set(this.opaqu, turing_handle_value);
    }

    public inverse_transform_vector(x: f32, y: f32, z: f32): Vec3 {
        _turinger_transform__inverse_transform_vector(this.opaqu, x, y, z);
        return dequeue_vec3();
    }
}

class GcHelper {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


    public static create(): GCHelper {
        let turing_result = _gc_helper__create();
        return new GcHelper(turing_result);
    }


    public wasm_garbage_collect(): void {
        _gc_helper__wasm_garbage_collect(this.opaqu);
    }

    public dispose(): void {
        _gc_helper__dispose(this.opaqu);
    }

    public invalidate_all_handles(): void {
        _gc_helper__invalidate_all_handles(this.opaqu);
    }
}

class Xr {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


    public static get_device_tracking_state(node_int: i32): i32 {
        return _xr__get_device_tracking_state(node_int);
    }

    public static get_device_name(node_int: i32): string {
        let turing_result = _xr__get_device_name(node_int);
        let turing_str = heap.alloc(usize(turing_result));
        _host_strcpy(u32(turing_str), turing_result);
        let turing_output = String.UTF8.decode(turing_str, true);
        heap.free(turing_str);
        return turing_output;
    }

    public static get_device_secondary_button_state(node_int: i32): bool {
        return _xr__get_device_secondary_button_state(node_int);
    }

    public static get_device_primary_button_state(node_int: i32): bool {
        return _xr__get_device_primary_button_state(node_int);
    }

    public static send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32): void {
        _xr__send_haptic_impulse(node_int, amplitude, duration);
    }

    public static is_device_valid(node_int: i32): bool {
        return _xr__is_device_valid(node_int);
    }

    public static get_device_battery_level(node_int: i32): f32 {
        return _xr__get_device_battery_level(node_int);
    }

    public static get_device_touchpad(node_int: i32): Vec2 {
        _xr__get_device_touchpad(node_int);
        return dequeue_vec2();
    }

    public static get_device_grip_value(node_int: i32): f32 {
        return _xr__get_device_grip_value(node_int);
    }

    public static get_device_trigger_value(node_int: i32): f32 {
        return _xr__get_device_trigger_value(node_int);
    }

    public static stop_haptics(node_int: i32): void {
        _xr__stop_haptics(node_int);
    }

    public static get_device_thumbstick(node_int: i32): Vec2 {
        _xr__get_device_thumbstick(node_int);
        return dequeue_vec2();
    }


    public _manager_get(): TuringScriptManager {
        let turing_result = _xr___manager_get(this.opaqu);
        return new TuringScriptManager(turing_result);
    }
}

class CustomData {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }


    public static create(): CustomData {
        let turing_result = _custom_data__create();
        return new CustomData(turing_result);
    }

    public static list_create(): List {
        let turing_result = _list_create();
        return new List(turing_result);
    }

    public static set_string(custom_data: CustomData, key: string, value: string): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        let turing_handle_value = String.UTF8.encode(value, true);
        _custom_data__set_string(custom_data, turing_handle_key, turing_handle_value);
    }

    public static set_custom_data(custom_data: CustomData, key: string, value: CustomData): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        _custom_data__set_custom_data(custom_data, turing_handle_key, value);
    }

    public static list_add_string(list: List1, value: string): void {
        let turing_handle_value = String.UTF8.encode(value, true);
        _custom_data__list_add_string(list, turing_handle_value);
    }

    public static set_custom_data_list(custom_data: CustomData, key: string, value: List1): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        _custom_data__set_custom_data_list(custom_data, turing_handle_key, value);
    }

    public static set_float(custom_data: CustomData, key: string, value: f32): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        _custom_data__set_float(custom_data, turing_handle_key, value);
    }

    public static list_add_int(list: List1, value: i32): void {
        _custom_data__list_add_int(list, value);
    }

    public static list_add_bool(list: List1, value: bool): void {
        _custom_data__list_add_bool(list, value);
    }

    public static set_int(custom_data: CustomData, key: string, value: i32): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        _custom_data__set_int(custom_data, turing_handle_key, value);
    }

    public static set_bool(custom_data: CustomData, key: string, value: bool): void {
        let turing_handle_key = String.UTF8.encode(key, true);
        _custom_data__set_bool(custom_data, turing_handle_key, value);
    }

    public static list_add_custom_data_list(list: List1, value: List1): void {
        _custom_data__list_add_custom_data_list(list, value);
    }

    public static list_add_float(list: List1, value: f32): void {
        _custom_data__list_add_float(list, value);
    }

    public static list_add_custom_data(list: List1, value: CustomData): void {
        _custom_data__list_add_custom_data(list, value);
    }

}

