@file:OptIn(
    kotlin.wasm.ExperimentalWasmInterop::class,
)
@file:Suppress("Unused")

///// Generated Kotlin API /////

import kotlinx.cinterop.*
import kotlin.native.concurrent.*

//// Wasm Bindings ////
@WasmImport("env", "_host_strcpy")
external fun _host_strcpy(location: CPointer<ByteVar>?, size: UInt)
@WasmImport("env", "_host_f32_enqueue")
external fun _host_f32_enqueue(f: Float);
@WasmImport("env", "_host_f32_dequeue")
external fun _host_f32_dequeue() : Float;
@WasmImport("env", "_core_log__warn")
external fun _core_log__warn(msg: CPointer<ByteVar>?)
@WasmImport("env", "_core_log__info")
external fun _core_log__info(msg: CPointer<ByteVar>?)
@WasmImport("env", "_core_log__debug")
external fun _core_log__debug(msg: CPointer<ByteVar>?)
@WasmImport("env", "_core_log__critical")
external fun _core_log__critical(msg: CPointer<ByteVar>?)
@WasmImport("env", "_get_components_in_parent_by_type")
external fun _get_components_in_parent_by_type(opaqu: Int, csType: Type, includeInactive: Boolean): Component
@WasmImport("env", "_core_turinger_game_object__send_message")
external fun _core_turinger_game_object__send_message(opaqu: Int, methodName: CPointer<ByteVar>?, options: Int)
@WasmImport("env", "_core_turinger_game_object__get_component_in_parent_by_type")
external fun _core_turinger_game_object__get_component_in_parent_by_type(opaqu: Int, csType: Type, includeInactive: Boolean): Component
@WasmImport("env", "_core_turinger_game_object__is_static_get")
external fun _core_turinger_game_object__is_static_get(opaqu: Int): Boolean
@WasmImport("env", "_core_turinger_game_object__transform_get")
external fun _core_turinger_game_object__transform_get(opaqu: Int): TuringerTransform
@WasmImport("env", "_core_turinger_game_object__get_component_in_children_by_type")
external fun _core_turinger_game_object__get_component_in_children_by_type(opaqu: Int, csType: Type, includeInactive: Boolean): Component
@WasmImport("env", "_get_components_by_type")
external fun _get_components_by_type(opaqu: Int, csType: Type): Component
@WasmImport("env", "_core_turinger_game_object__active_set")
external fun _core_turinger_game_object__active_set(opaqu: Int, value: Boolean)
@WasmImport("env", "_core_turinger_game_object__broadcast_message")
external fun _core_turinger_game_object__broadcast_message(opaqu: Int, methodName: CPointer<ByteVar>?, options: Int)
@WasmImport("env", "_core_turinger_game_object__game_object_get")
external fun _core_turinger_game_object__game_object_get(opaqu: Int): GameObject
@WasmImport("env", "_core_turinger_game_object__is_static_set")
external fun _core_turinger_game_object__is_static_set(opaqu: Int, value: Boolean)
@WasmImport("env", "_core_turinger_game_object__add_component")
external fun _core_turinger_game_object__add_component(opaqu: Int, componentType: Type): Component
@WasmImport("env", "_core_turinger_game_object__hide_flags_set")
external fun _core_turinger_game_object__hide_flags_set(opaqu: Int, value: Int)
@WasmImport("env", "_core_turinger_game_object__send_message_upwards")
external fun _core_turinger_game_object__send_message_upwards(opaqu: Int, methodName: CPointer<ByteVar>?, options: Int)
@WasmImport("env", "_core_turinger_game_object__compare_tag")
external fun _core_turinger_game_object__compare_tag(opaqu: Int, tag: CPointer<ByteVar>?): Boolean
@WasmImport("env", "_core_turinger_game_object__hide_flags_get")
external fun _core_turinger_game_object__hide_flags_get(opaqu: Int): Int
@WasmImport("env", "_core_turinger_game_object__tag_set")
external fun _core_turinger_game_object__tag_set(opaqu: Int, value: CPointer<ByteVar>?)
@WasmImport("env", "_core_turinger_game_object__get_instance_id")
external fun _core_turinger_game_object__get_instance_id(opaqu: Int): Int
@WasmImport("env", "_core_turinger_game_object__layer_get")
external fun _core_turinger_game_object__layer_get(opaqu: Int): Int
@WasmImport("env", "_get_components_in_children_by_type")
external fun _get_components_in_children_by_type(opaqu: Int, csType: Type, includeInactive: Boolean): Component
@WasmImport("env", "_core_turinger_game_object__layer_set")
external fun _core_turinger_game_object__layer_set(opaqu: Int, value: Int)
@WasmImport("env", "_core_turinger_game_object__set_active_recursively")
external fun _core_turinger_game_object__set_active_recursively(opaqu: Int, state: Boolean)
@WasmImport("env", "_core_turinger_game_object__get_component_index")
external fun _core_turinger_game_object__get_component_index(opaqu: Int, component: Component): Int
@WasmImport("env", "_core_turinger_game_object__get_component_count")
external fun _core_turinger_game_object__get_component_count(opaqu: Int): Int
@WasmImport("env", "_core_turinger_game_object__get_component_at_index")
external fun _core_turinger_game_object__get_component_at_index(opaqu: Int, index: Int): Component
@WasmImport("env", "_core_turinger_game_object__tag_get")
external fun _core_turinger_game_object__tag_get(opaqu: Int): CPointer<ByteVar>?
@WasmImport("env", "_core_turinger_game_object__active_self_get")
external fun _core_turinger_game_object__active_self_get(opaqu: Int): Boolean
@WasmImport("env", "_core_turinger_game_object__name_get")
external fun _core_turinger_game_object__name_get(opaqu: Int): CPointer<ByteVar>?
@WasmImport("env", "_core_turinger_game_object__get_component_by_type")
external fun _core_turinger_game_object__get_component_by_type(opaqu: Int, csType: Type): Component
@WasmImport("env", "_core_turinger_game_object__active_in_hierarchy_get")
external fun _core_turinger_game_object__active_in_hierarchy_get(opaqu: Int): Boolean
@WasmImport("env", "_core_turinger_game_object__set_active")
external fun _core_turinger_game_object__set_active(opaqu: Int, value: Boolean)
@WasmImport("env", "_core_turinger_game_object__active_get")
external fun _core_turinger_game_object__active_get(opaqu: Int): Boolean
@WasmImport("env", "_core_turinger_game_object__get_component_by_name")
external fun _core_turinger_game_object__get_component_by_name(opaqu: Int, csType: CPointer<ByteVar>?): Component
@WasmImport("env", "_core_turinger_game_object__name_set")
external fun _core_turinger_game_object__name_set(opaqu: Int, value: CPointer<ByteVar>?)
@WasmImport("env", "_core_turinger_game_object__scene_culling_mask_get")
external fun _core_turinger_game_object__scene_culling_mask_get(opaqu: Int): ULong
@WasmImport("env", "_core_turinger_game_object_manager__create_object")
external fun _core_turinger_game_object_manager__create_object(name: CPointer<ByteVar>?): TuringerGameObject
@WasmImport("env", "_core_turinger_game_object_manager__find")
external fun _core_turinger_game_object_manager__find(name: CPointer<ByteVar>?): TuringerGameObject
@WasmImport("env", "_core_turinger_game_object_manager__destroy_object")
external fun _core_turinger_game_object_manager__destroy_object(listener: TuringerGameObject)
@WasmImport("env", "_core_turinger_game_object_manager__instance_get")
external fun _core_turinger_game_object_manager__instance_get(opaqu: Int): TuringerGameObjectManager
@WasmImport("env", "_core_custom_data__create")
external fun _core_custom_data__create(): CustomData
@WasmImport("env", "_list_create")
external fun _list_create(): List
@WasmImport("env", "_core_custom_data__set_string")
external fun _core_custom_data__set_string(customData: CustomData, key: CPointer<ByteVar>?, value: CPointer<ByteVar>?)
@WasmImport("env", "_core_custom_data__set_custom_data")
external fun _core_custom_data__set_custom_data(customData: CustomData, key: CPointer<ByteVar>?, value: CustomData)
@WasmImport("env", "_core_custom_data__list_add_string")
external fun _core_custom_data__list_add_string(list: List1, value: CPointer<ByteVar>?)
@WasmImport("env", "_core_custom_data__set_custom_data_list")
external fun _core_custom_data__set_custom_data_list(customData: CustomData, key: CPointer<ByteVar>?, value: List1)
@WasmImport("env", "_core_custom_data__set_float")
external fun _core_custom_data__set_float(customData: CustomData, key: CPointer<ByteVar>?, value: Float)
@WasmImport("env", "_core_custom_data__list_add_int")
external fun _core_custom_data__list_add_int(list: List1, value: Int)
@WasmImport("env", "_core_custom_data__list_add_bool")
external fun _core_custom_data__list_add_bool(list: List1, value: Boolean)
@WasmImport("env", "_core_custom_data__set_int")
external fun _core_custom_data__set_int(customData: CustomData, key: CPointer<ByteVar>?, value: Int)
@WasmImport("env", "_core_custom_data__set_bool")
external fun _core_custom_data__set_bool(customData: CustomData, key: CPointer<ByteVar>?, value: Boolean)
@WasmImport("env", "_core_custom_data__list_add_custom_data_list")
external fun _core_custom_data__list_add_custom_data_list(list: List1, value: List1)
@WasmImport("env", "_core_custom_data__list_add_float")
external fun _core_custom_data__list_add_float(list: List1, value: Float)
@WasmImport("env", "_core_custom_data__list_add_custom_data")
external fun _core_custom_data__list_add_custom_data(list: List1, value: CustomData)
@WasmImport("env", "_core_gc_helper__create")
external fun _core_gc_helper__create(): GCHelper
@WasmImport("env", "_core_gc_helper__wasm_garbage_collect")
external fun _core_gc_helper__wasm_garbage_collect(opaqu: Int)
@WasmImport("env", "_core_gc_helper__dispose")
external fun _core_gc_helper__dispose(opaqu: Int)
@WasmImport("env", "_core_gc_helper__invalidate_all_handles")
external fun _core_gc_helper__invalidate_all_handles(opaqu: Int)
@WasmImport("env", "_core_note_manager__add_obstacle")
external fun _core_note_manager__add_obstacle(beat: Float, duration: Float, line: Int, layer: Int, width: Int, height: Int, customData: CustomData)
@WasmImport("env", "_core_note_manager__add_color_note")
external fun _core_note_manager__add_color_note(beat: Float, line: Int, layer: Int, color: Int, cutDirection: Int, customData: CustomData)
@WasmImport("env", "_core_note_manager__time_to_beat")
external fun _core_note_manager__time_to_beat(time: Float): Float
@WasmImport("env", "_core_note_manager__add_bomb_note")
external fun _core_note_manager__add_bomb_note(beat: Float, line: Int, layer: Int, customData: CustomData)
@WasmImport("env", "_core_xr__get_device_tracking_state")
external fun _core_xr__get_device_tracking_state(nodeInt: Int): Int
@WasmImport("env", "_core_xr__get_device_name")
external fun _core_xr__get_device_name(nodeInt: Int): CPointer<ByteVar>?
@WasmImport("env", "_core_xr__get_device_secondary_button_state")
external fun _core_xr__get_device_secondary_button_state(nodeInt: Int): Boolean
@WasmImport("env", "_core_xr__get_device_primary_button_state")
external fun _core_xr__get_device_primary_button_state(nodeInt: Int): Boolean
@WasmImport("env", "_core_xr__send_haptic_impulse")
external fun _core_xr__send_haptic_impulse(nodeInt: Int, amplitude: Float, duration: Float)
@WasmImport("env", "_core_xr__is_device_valid")
external fun _core_xr__is_device_valid(nodeInt: Int): Boolean
@WasmImport("env", "_core_xr__get_device_battery_level")
external fun _core_xr__get_device_battery_level(nodeInt: Int): Float
@WasmImport("env", "_core_xr__get_device_touchpad")
external fun _core_xr__get_device_touchpad(nodeInt: Int): UInt
@WasmImport("env", "_core_xr__get_device_grip_value")
external fun _core_xr__get_device_grip_value(nodeInt: Int): Float
@WasmImport("env", "_core_xr__get_device_trigger_value")
external fun _core_xr__get_device_trigger_value(nodeInt: Int): Float
@WasmImport("env", "_core_xr__stop_haptics")
external fun _core_xr__stop_haptics(nodeInt: Int)
@WasmImport("env", "_core_xr__get_device_thumbstick")
external fun _core_xr__get_device_thumbstick(nodeInt: Int): UInt
@WasmImport("env", "_core_xr___manager_get")
external fun _core_xr___manager_get(opaqu: Int): TuringScriptManager
@WasmImport("env", "_core_turinger_transform__get_component_by_type")
external fun _core_turinger_transform__get_component_by_type(opaqu: Int, csType: Type): Component
@WasmImport("env", "_core_turinger_transform__look_at")
external fun _core_turinger_transform__look_at(opaqu: Int, target: TuringerTransform, worldUp: UInt)
@WasmImport("env", "_core_turinger_transform__get_instance_id")
external fun _core_turinger_transform__get_instance_id(opaqu: Int): Int
@WasmImport("env", "_core_turinger_transform__tag_get")
external fun _core_turinger_transform__tag_get(opaqu: Int): CPointer<ByteVar>?
@WasmImport("env", "_core_turinger_transform__local_euler_angles_get")
external fun _core_turinger_transform__local_euler_angles_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__rotation_get")
external fun _core_turinger_transform__rotation_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__world_to_local_matrix_get")
external fun _core_turinger_transform__world_to_local_matrix_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__hierarchy_count_get")
external fun _core_turinger_transform__hierarchy_count_get(opaqu: Int): Int
@WasmImport("env", "_get_components_in_children_by_type")
external fun _get_components_in_children_by_type(opaqu: Int, t: Type, includeInactive: Boolean): Component
@WasmImport("env", "_core_turinger_transform__name_set")
external fun _core_turinger_transform__name_set(opaqu: Int, value: CPointer<ByteVar>?)
@WasmImport("env", "_core_turinger_transform__local_rotation_get")
external fun _core_turinger_transform__local_rotation_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__detach_children")
external fun _core_turinger_transform__detach_children(opaqu: Int)
@WasmImport("env", "_core_turinger_transform__inverse_transform_point")
external fun _core_turinger_transform__inverse_transform_point(opaqu: Int, position: UInt): UInt
@WasmImport("env", "_core_turinger_transform__get_component_in_children_by_type")
external fun _core_turinger_transform__get_component_in_children_by_type(opaqu: Int, t: Type, includeInactive: Boolean): Component
@WasmImport("env", "_core_turinger_transform__transform_get")
external fun _core_turinger_transform__transform_get(opaqu: Int): Transform
@WasmImport("env", "_core_turinger_transform__lossy_scale_get")
external fun _core_turinger_transform__lossy_scale_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__root_get")
external fun _core_turinger_transform__root_get(opaqu: Int): TuringerTransform
@WasmImport("env", "_get_components_by_type")
external fun _get_components_by_type(opaqu: Int, csType: Type): Component
@WasmImport("env", "_core_turinger_transform__get_enumerator")
external fun _core_turinger_transform__get_enumerator(opaqu: Int): IEnumerator
@WasmImport("env", "_core_turinger_transform__local_scale_set")
external fun _core_turinger_transform__local_scale_set(opaqu: Int, value: UInt)
@WasmImport("env", "_core_turinger_transform__child_count_get")
external fun _core_turinger_transform__child_count_get(opaqu: Int): Int
@WasmImport("env", "_core_turinger_transform__parent_set")
external fun _core_turinger_transform__parent_set(opaqu: Int, value: TuringerTransform)
@WasmImport("env", "_core_turinger_transform__get_child")
external fun _core_turinger_transform__get_child(opaqu: Int, index: Int): TuringerTransform
@WasmImport("env", "_core_turinger_transform__transform_direction")
external fun _core_turinger_transform__transform_direction(opaqu: Int, direction: UInt): UInt
@WasmImport("env", "_core_turinger_transform__has_changed_set")
external fun _core_turinger_transform__has_changed_set(opaqu: Int, value: Boolean)
@WasmImport("env", "_core_turinger_transform__send_message_upwards")
external fun _core_turinger_transform__send_message_upwards(opaqu: Int, methodName: CPointer<ByteVar>?, value: Object, options: Int)
@WasmImport("env", "_core_turinger_transform__find_child")
external fun _core_turinger_transform__find_child(opaqu: Int, n: CPointer<ByteVar>?): TuringerTransform
@WasmImport("env", "_get_components_in_parent_by_type")
external fun _get_components_in_parent_by_type(opaqu: Int, t: Type, includeInactive: Boolean): Component
@WasmImport("env", "_core_turinger_transform__rotate")
external fun _core_turinger_transform__rotate(opaqu: Int, eulers: UInt)
@WasmImport("env", "_core_turinger_transform__has_changed_get")
external fun _core_turinger_transform__has_changed_get(opaqu: Int): Boolean
@WasmImport("env", "_core_turinger_transform__local_position_get")
external fun _core_turinger_transform__local_position_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__translate_relative")
external fun _core_turinger_transform__translate_relative(opaqu: Int, translation: UInt, relativeTo: TuringerTransform)
@WasmImport("env", "_core_turinger_transform__local_euler_angles_set")
external fun _core_turinger_transform__local_euler_angles_set(opaqu: Int, value: UInt)
@WasmImport("env", "_core_turinger_transform__set_local_position_and_rotation")
external fun _core_turinger_transform__set_local_position_and_rotation(opaqu: Int, localPosition: UInt, localRotation: UInt)
@WasmImport("env", "_core_turinger_transform__forward_get")
external fun _core_turinger_transform__forward_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__get_sibling_index")
external fun _core_turinger_transform__get_sibling_index(opaqu: Int): Int
@WasmImport("env", "_core_turinger_transform__get_component_in_parent_by_type")
external fun _core_turinger_transform__get_component_in_parent_by_type(opaqu: Int, t: Type, includeInactive: Boolean): Component
@WasmImport("env", "_core_turinger_transform__up_get")
external fun _core_turinger_transform__up_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__get_component_index")
external fun _core_turinger_transform__get_component_index(opaqu: Int): Int
@WasmImport("env", "_core_turinger_transform__rotate_around_local")
external fun _core_turinger_transform__rotate_around_local(opaqu: Int, axis: UInt, angle: Float)
@WasmImport("env", "_core_turinger_transform__translate")
external fun _core_turinger_transform__translate(opaqu: Int, translation: UInt, relativeTo: Int)
@WasmImport("env", "_core_turinger_transform__broadcast_message")
external fun _core_turinger_transform__broadcast_message(opaqu: Int, methodName: CPointer<ByteVar>?, parameter: Object, options: Int)
@WasmImport("env", "_core_turinger_transform__euler_angles_set")
external fun _core_turinger_transform__euler_angles_set(opaqu: Int, value: UInt)
@WasmImport("env", "_core_turinger_transform__send_message")
external fun _core_turinger_transform__send_message(opaqu: Int, methodName: CPointer<ByteVar>?, value: Object, options: Int)
@WasmImport("env", "_core_turinger_transform__parent_get")
external fun _core_turinger_transform__parent_get(opaqu: Int): TuringerTransform
@WasmImport("env", "_core_turinger_transform__local_to_world_matrix_get")
external fun _core_turinger_transform__local_to_world_matrix_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__get_component_by_name")
external fun _core_turinger_transform__get_component_by_name(opaqu: Int, csType: CPointer<ByteVar>?): Component
@WasmImport("env", "_core_turinger_transform__set_parent")
external fun _core_turinger_transform__set_parent(opaqu: Int, parent: TuringerTransform, worldPositionStays: Boolean)
@WasmImport("env", "_core_turinger_transform__rotate_around")
external fun _core_turinger_transform__rotate_around(opaqu: Int, point: UInt, axis: UInt, angle: Float)
@WasmImport("env", "_core_turinger_transform__hierarchy_capacity_set")
external fun _core_turinger_transform__hierarchy_capacity_set(opaqu: Int, value: Int)
@WasmImport("env", "_core_turinger_transform__up_set")
external fun _core_turinger_transform__up_set(opaqu: Int, value: UInt)
@WasmImport("env", "_core_turinger_transform__inverse_transform_direction")
external fun _core_turinger_transform__inverse_transform_direction(opaqu: Int, direction: UInt): UInt
@WasmImport("env", "_core_turinger_transform__local_scale_get")
external fun _core_turinger_transform__local_scale_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__transform_vector")
external fun _core_turinger_transform__transform_vector(opaqu: Int, vector: UInt): UInt
@WasmImport("env", "_core_turinger_transform__transform_point")
external fun _core_turinger_transform__transform_point(opaqu: Int, position: UInt): UInt
@WasmImport("env", "_core_turinger_transform__euler_angles_get")
external fun _core_turinger_transform__euler_angles_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__is_child_of")
external fun _core_turinger_transform__is_child_of(opaqu: Int, parent: TuringerTransform): Boolean
@WasmImport("env", "_core_turinger_transform__right_set")
external fun _core_turinger_transform__right_set(opaqu: Int, value: UInt)
@WasmImport("env", "_core_turinger_transform__get_child_count")
external fun _core_turinger_transform__get_child_count(opaqu: Int): Int
@WasmImport("env", "_core_turinger_transform__hide_flags_get")
external fun _core_turinger_transform__hide_flags_get(opaqu: Int): Int
@WasmImport("env", "_core_turinger_transform__rotate_relative")
external fun _core_turinger_transform__rotate_relative(opaqu: Int, eulers: UInt, relativeTo: Int)
@WasmImport("env", "_core_turinger_transform__rotation_set")
external fun _core_turinger_transform__rotation_set(opaqu: Int, value: UInt)
@WasmImport("env", "_core_turinger_transform__game_object_get")
external fun _core_turinger_transform__game_object_get(opaqu: Int): TuringerGameObject
@WasmImport("env", "_core_turinger_transform__hierarchy_capacity_get")
external fun _core_turinger_transform__hierarchy_capacity_get(opaqu: Int): Int
@WasmImport("env", "_core_turinger_transform__set_as_first_sibling")
external fun _core_turinger_transform__set_as_first_sibling(opaqu: Int)
@WasmImport("env", "_core_turinger_transform__right_get")
external fun _core_turinger_transform__right_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__local_position_set")
external fun _core_turinger_transform__local_position_set(opaqu: Int, value: UInt)
@WasmImport("env", "_core_turinger_transform__forward_set")
external fun _core_turinger_transform__forward_set(opaqu: Int, value: UInt)
@WasmImport("env", "_core_turinger_transform__name_get")
external fun _core_turinger_transform__name_get(opaqu: Int): CPointer<ByteVar>?
@WasmImport("env", "_core_turinger_transform__compare_tag")
external fun _core_turinger_transform__compare_tag(opaqu: Int, tag: CPointer<ByteVar>?): Boolean
@WasmImport("env", "_core_turinger_transform__set_as_last_sibling")
external fun _core_turinger_transform__set_as_last_sibling(opaqu: Int)
@WasmImport("env", "_core_turinger_transform__position_get")
external fun _core_turinger_transform__position_get(opaqu: Int): UInt
@WasmImport("env", "_core_turinger_transform__set_sibling_index")
external fun _core_turinger_transform__set_sibling_index(opaqu: Int, index: Int)
@WasmImport("env", "_core_turinger_transform__position_set")
external fun _core_turinger_transform__position_set(opaqu: Int, value: UInt)
@WasmImport("env", "_core_turinger_transform__hide_flags_set")
external fun _core_turinger_transform__hide_flags_set(opaqu: Int, value: Int)
@WasmImport("env", "_core_turinger_transform__set_position_and_rotation")
external fun _core_turinger_transform__set_position_and_rotation(opaqu: Int, position: UInt, rotation: UInt)
@WasmImport("env", "_core_turinger_transform__find")
external fun _core_turinger_transform__find(opaqu: Int, n: CPointer<ByteVar>?): TuringerTransform
@WasmImport("env", "_core_turinger_transform__tag_set")
external fun _core_turinger_transform__tag_set(opaqu: Int, value: CPointer<ByteVar>?)
@WasmImport("env", "_core_turinger_transform__local_rotation_set")
external fun _core_turinger_transform__local_rotation_set(opaqu: Int, value: UInt)
@WasmImport("env", "_core_turinger_transform__inverse_transform_vector")
external fun _core_turinger_transform__inverse_transform_vector(opaqu: Int, vector: UInt): UInt


@WasmExport(name = "_turing_api_semver")
fun _turing_api_semver() : ULong {
    (0uL shl 32) or (1uL shl 16) or 0uL
}

//// Functions ////


//// Classes ////
data class GameObject(val opaqu: ULong) {
}

data class Transform(val opaqu: ULong) {
}

data class TuringScriptManager(val opaqu: ULong) {
}

data class Object(val opaqu: ULong) {
}

data class List1(val opaqu: ULong) {
}

data class List(val opaqu: ULong) {
}

data class Component(val opaqu: ULong) {
}

data class Type(val opaqu: ULong) {
}

data class IEnumerator(val opaqu: ULong) {
}

object Log {

    fun warn(msg: String) {
        val hostResult = _core_log__warn(msg.cstr)
    }

    fun info(msg: String) {
        val hostResult = _core_log__info(msg.cstr)
    }

    fun debug(msg: String) {
        val hostResult = _core_log__debug(msg.cstr)
    }

    fun critical(msg: String) {
        val hostResult = _core_log__critical(msg.cstr)
    }
}

data class TuringerGameObject(val opaqu: ULong) {

    fun getComponentsInParentByType(csType: Type, includeInactive: Boolean) : Component {
        val hostResult = _get_components_in_parent_by_type(this.opaqu, csType, includeInactive)
        Component(opaqu = hostResult)
    }

    fun sendMessage(methodName: String, options: Int) {
        val hostResult = _core_turinger_game_object__send_message(this.opaqu, methodName.cstr, options)
    }

    fun getComponentInParentByType(csType: Type, includeInactive: Boolean) : Component {
        val hostResult = _core_turinger_game_object__get_component_in_parent_by_type(this.opaqu, csType, includeInactive)
        Component(opaqu = hostResult)
    }

    fun isStaticGet() : Boolean {
        val hostResult = _core_turinger_game_object__is_static_get(this.opaqu)
        hostResult
    }

    fun transformGet() : TuringerTransform {
        val hostResult = _core_turinger_game_object__transform_get(this.opaqu)
        TuringerTransform(opaqu = hostResult)
    }

    fun getComponentInChildrenByType(csType: Type, includeInactive: Boolean) : Component {
        val hostResult = _core_turinger_game_object__get_component_in_children_by_type(this.opaqu, csType, includeInactive)
        Component(opaqu = hostResult)
    }

    fun getComponentsByType(csType: Type) : Component {
        val hostResult = _get_components_by_type(this.opaqu, csType)
        Component(opaqu = hostResult)
    }

    fun activeSet(value: Boolean) {
        val hostResult = _core_turinger_game_object__active_set(this.opaqu, value)
    }

    fun broadcastMessage(methodName: String, options: Int) {
        val hostResult = _core_turinger_game_object__broadcast_message(this.opaqu, methodName.cstr, options)
    }

    fun gameObjectGet() : GameObject {
        val hostResult = _core_turinger_game_object__game_object_get(this.opaqu)
        GameObject(opaqu = hostResult)
    }

    fun isStaticSet(value: Boolean) {
        val hostResult = _core_turinger_game_object__is_static_set(this.opaqu, value)
    }

    fun addComponent(componentType: Type) : Component {
        val hostResult = _core_turinger_game_object__add_component(this.opaqu, componentType)
        Component(opaqu = hostResult)
    }

    fun hideFlagsSet(value: Int) {
        val hostResult = _core_turinger_game_object__hide_flags_set(this.opaqu, value)
    }

    fun sendMessageUpwards(methodName: String, options: Int) {
        val hostResult = _core_turinger_game_object__send_message_upwards(this.opaqu, methodName.cstr, options)
    }

    fun compareTag(tag: String) : Boolean {
        val hostResult = _core_turinger_game_object__compare_tag(this.opaqu, tag.cstr)
        hostResult
    }

    fun hideFlagsGet() : Int {
        val hostResult = _core_turinger_game_object__hide_flags_get(this.opaqu)
        hostResult
    }

    fun tagSet(value: String) {
        val hostResult = _core_turinger_game_object__tag_set(this.opaqu, value.cstr)
    }

    fun getInstanceId() : Int {
        val hostResult = _core_turinger_game_object__get_instance_id(this.opaqu)
        hostResult
    }

    fun layerGet() : Int {
        val hostResult = _core_turinger_game_object__layer_get(this.opaqu)
        hostResult
    }

    fun getComponentsInChildrenByType(csType: Type, includeInactive: Boolean) : Component {
        val hostResult = _get_components_in_children_by_type(this.opaqu, csType, includeInactive)
        Component(opaqu = hostResult)
    }

    fun layerSet(value: Int) {
        val hostResult = _core_turinger_game_object__layer_set(this.opaqu, value)
    }

    fun setActiveRecursively(state: Boolean) {
        val hostResult = _core_turinger_game_object__set_active_recursively(this.opaqu, state)
    }

    fun getComponentIndex(component: Component) : Int {
        val hostResult = _core_turinger_game_object__get_component_index(this.opaqu, component)
        hostResult
    }

    fun getComponentCount() : Int {
        val hostResult = _core_turinger_game_object__get_component_count(this.opaqu)
        hostResult
    }

    fun getComponentAtIndex(index: Int) : Component {
        val hostResult = _core_turinger_game_object__get_component_at_index(this.opaqu, index)
        Component(opaqu = hostResult)
    }

    fun tagGet() : String {
        val hostResult = _core_turinger_game_object__tag_get(this.opaqu)
        val useMe = hostResult?.toKString() ?: error("null pointer returned")
        useMe
    }

    fun activeSelfGet() : Boolean {
        val hostResult = _core_turinger_game_object__active_self_get(this.opaqu)
        hostResult
    }

    fun nameGet() : String {
        val hostResult = _core_turinger_game_object__name_get(this.opaqu)
        val useMe = hostResult?.toKString() ?: error("null pointer returned")
        useMe
    }

    fun getComponentByType(csType: Type) : Component {
        val hostResult = _core_turinger_game_object__get_component_by_type(this.opaqu, csType)
        Component(opaqu = hostResult)
    }

    fun activeInHierarchyGet() : Boolean {
        val hostResult = _core_turinger_game_object__active_in_hierarchy_get(this.opaqu)
        hostResult
    }

    fun setActive(value: Boolean) {
        val hostResult = _core_turinger_game_object__set_active(this.opaqu, value)
    }

    fun activeGet() : Boolean {
        val hostResult = _core_turinger_game_object__active_get(this.opaqu)
        hostResult
    }

    fun getComponentByName(csType: String) : Component {
        val hostResult = _core_turinger_game_object__get_component_by_name(this.opaqu, csType.cstr)
        Component(opaqu = hostResult)
    }

    fun nameSet(value: String) {
        val hostResult = _core_turinger_game_object__name_set(this.opaqu, value.cstr)
    }

    fun sceneCullingMaskGet() : ULong {
        val hostResult = _core_turinger_game_object__scene_culling_mask_get(this.opaqu)
        hostResult
    }
}

data class TuringerGameObjectManager(val opaqu: ULong) {

    fun createObject(name: String) : TuringerGameObject {
        val hostResult = _core_turinger_game_object_manager__create_object(name.cstr)
        TuringerGameObject(opaqu = hostResult)
    }

    fun find(name: String) : TuringerGameObject {
        val hostResult = _core_turinger_game_object_manager__find(name.cstr)
        TuringerGameObject(opaqu = hostResult)
    }

    fun destroyObject(listener: TuringerGameObject) {
        val hostResult = _core_turinger_game_object_manager__destroy_object(listener)
    }

    fun instanceGet() : TuringerGameObjectManager {
        val hostResult = _core_turinger_game_object_manager__instance_get(this.opaqu)
        TuringerGameObjectManager(opaqu = hostResult)
    }
}

data class CustomData(val opaqu: ULong) {

    fun create() : CustomData {
        val hostResult = _core_custom_data__create()
        CustomData(opaqu = hostResult)
    }

    fun listCreate() : List {
        val hostResult = _list_create()
        List(opaqu = hostResult)
    }

    fun setString(customData: CustomData, key: String, value: String) {
        val hostResult = _core_custom_data__set_string(customData, key.cstr, value.cstr)
    }

    fun setCustomData(customData: CustomData, key: String, value: CustomData) {
        val hostResult = _core_custom_data__set_custom_data(customData, key.cstr, value)
    }

    fun listAddString(list: List1, value: String) {
        val hostResult = _core_custom_data__list_add_string(list, value.cstr)
    }

    fun setCustomDataList(customData: CustomData, key: String, value: List1) {
        val hostResult = _core_custom_data__set_custom_data_list(customData, key.cstr, value)
    }

    fun setFloat(customData: CustomData, key: String, value: Float) {
        val hostResult = _core_custom_data__set_float(customData, key.cstr, value)
    }

    fun listAddInt(list: List1, value: Int) {
        val hostResult = _core_custom_data__list_add_int(list, value)
    }

    fun listAddBool(list: List1, value: Boolean) {
        val hostResult = _core_custom_data__list_add_bool(list, value)
    }

    fun setInt(customData: CustomData, key: String, value: Int) {
        val hostResult = _core_custom_data__set_int(customData, key.cstr, value)
    }

    fun setBool(customData: CustomData, key: String, value: Boolean) {
        val hostResult = _core_custom_data__set_bool(customData, key.cstr, value)
    }

    fun listAddCustomDataList(list: List1, value: List1) {
        val hostResult = _core_custom_data__list_add_custom_data_list(list, value)
    }

    fun listAddFloat(list: List1, value: Float) {
        val hostResult = _core_custom_data__list_add_float(list, value)
    }

    fun listAddCustomData(list: List1, value: CustomData) {
        val hostResult = _core_custom_data__list_add_custom_data(list, value)
    }
}

data class GcHelper(val opaqu: ULong) {

    fun create() : GCHelper {
        val hostResult = _core_gc_helper__create()
        GcHelper(opaqu = hostResult)
    }

    fun wasmGarbageCollect() {
        val hostResult = _core_gc_helper__wasm_garbage_collect(this.opaqu)
    }

    fun dispose() {
        val hostResult = _core_gc_helper__dispose(this.opaqu)
    }

    fun invalidateAllHandles() {
        val hostResult = _core_gc_helper__invalidate_all_handles(this.opaqu)
    }
}

object NoteManager {

    fun addObstacle(beat: Float, duration: Float, line: Int, layer: Int, width: Int, height: Int, customData: CustomData) {
        val hostResult = _core_note_manager__add_obstacle(beat, duration, line, layer, width, height, customData)
    }

    fun addColorNote(beat: Float, line: Int, layer: Int, color: Int, cutDirection: Int, customData: CustomData) {
        val hostResult = _core_note_manager__add_color_note(beat, line, layer, color, cutDirection, customData)
    }

    fun timeToBeat(time: Float) : Float {
        val hostResult = _core_note_manager__time_to_beat(time)
        hostResult
    }

    fun addBombNote(beat: Float, line: Int, layer: Int, customData: CustomData) {
        val hostResult = _core_note_manager__add_bomb_note(beat, line, layer, customData)
    }
}

data class Xr(val opaqu: ULong) {

    fun getDeviceTrackingState(nodeInt: Int) : Int {
        val hostResult = _core_xr__get_device_tracking_state(nodeInt)
        hostResult
    }

    fun getDeviceName(nodeInt: Int) : String {
        val hostResult = _core_xr__get_device_name(nodeInt)
        val useMe = hostResult?.toKString() ?: error("null pointer returned")
        useMe
    }

    fun getDeviceSecondaryButtonState(nodeInt: Int) : Boolean {
        val hostResult = _core_xr__get_device_secondary_button_state(nodeInt)
        hostResult
    }

    fun getDevicePrimaryButtonState(nodeInt: Int) : Boolean {
        val hostResult = _core_xr__get_device_primary_button_state(nodeInt)
        hostResult
    }

    fun sendHapticImpulse(nodeInt: Int, amplitude: Float, duration: Float) {
        val hostResult = _core_xr__send_haptic_impulse(nodeInt, amplitude, duration)
    }

    fun isDeviceValid(nodeInt: Int) : Boolean {
        val hostResult = _core_xr__is_device_valid(nodeInt)
        hostResult
    }

    fun getDeviceBatteryLevel(nodeInt: Int) : Float {
        val hostResult = _core_xr__get_device_battery_level(nodeInt)
        hostResult
    }

    fun getDeviceTouchpad(nodeInt: Int) : Vec2 {
        val hostResult = _core_xr__get_device_touchpad(nodeInt)
        hostResult
    }

    fun getDeviceGripValue(nodeInt: Int) : Float {
        val hostResult = _core_xr__get_device_grip_value(nodeInt)
        hostResult
    }

    fun getDeviceTriggerValue(nodeInt: Int) : Float {
        val hostResult = _core_xr__get_device_trigger_value(nodeInt)
        hostResult
    }

    fun stopHaptics(nodeInt: Int) {
        val hostResult = _core_xr__stop_haptics(nodeInt)
    }

    fun getDeviceThumbstick(nodeInt: Int) : Vec2 {
        val hostResult = _core_xr__get_device_thumbstick(nodeInt)
        hostResult
    }

    fun ManagerGet() : TuringScriptManager {
        val hostResult = _core_xr___manager_get(this.opaqu)
        TuringScriptManager(opaqu = hostResult)
    }
}

data class TuringerTransform(val opaqu: ULong) {

    fun getComponentByType(csType: Type) : Component {
        val hostResult = _core_turinger_transform__get_component_by_type(this.opaqu, csType)
        Component(opaqu = hostResult)
    }

    fun lookAt(target: TuringerTransform, worldUp: Vec3) {
        val hostResult = _core_turinger_transform__look_at(this.opaqu, target, worldUp)
    }

    fun getInstanceId() : Int {
        val hostResult = _core_turinger_transform__get_instance_id(this.opaqu)
        hostResult
    }

    fun tagGet() : String {
        val hostResult = _core_turinger_transform__tag_get(this.opaqu)
        val useMe = hostResult?.toKString() ?: error("null pointer returned")
        useMe
    }

    fun localEulerAnglesGet() : Vec3 {
        val hostResult = _core_turinger_transform__local_euler_angles_get(this.opaqu)
        hostResult
    }

    fun rotationGet() : Quat {
        val hostResult = _core_turinger_transform__rotation_get(this.opaqu)
        hostResult
    }

    fun worldToLocalMatrixGet() : Mat4 {
        val hostResult = _core_turinger_transform__world_to_local_matrix_get(this.opaqu)
        hostResult
    }

    fun hierarchyCountGet() : Int {
        val hostResult = _core_turinger_transform__hierarchy_count_get(this.opaqu)
        hostResult
    }

    fun getComponentsInChildrenByType(t: Type, includeInactive: Boolean) : Component {
        val hostResult = _get_components_in_children_by_type(this.opaqu, t, includeInactive)
        Component(opaqu = hostResult)
    }

    fun nameSet(value: String) {
        val hostResult = _core_turinger_transform__name_set(this.opaqu, value.cstr)
    }

    fun localRotationGet() : Quat {
        val hostResult = _core_turinger_transform__local_rotation_get(this.opaqu)
        hostResult
    }

    fun detachChildren() {
        val hostResult = _core_turinger_transform__detach_children(this.opaqu)
    }

    fun inverseTransformPoint(position: Vec3) : Vec3 {
        val hostResult = _core_turinger_transform__inverse_transform_point(this.opaqu, position)
        hostResult
    }

    fun getComponentInChildrenByType(t: Type, includeInactive: Boolean) : Component {
        val hostResult = _core_turinger_transform__get_component_in_children_by_type(this.opaqu, t, includeInactive)
        Component(opaqu = hostResult)
    }

    fun transformGet() : Transform {
        val hostResult = _core_turinger_transform__transform_get(this.opaqu)
        Transform(opaqu = hostResult)
    }

    fun lossyScaleGet() : Vec3 {
        val hostResult = _core_turinger_transform__lossy_scale_get(this.opaqu)
        hostResult
    }

    fun rootGet() : TuringerTransform {
        val hostResult = _core_turinger_transform__root_get(this.opaqu)
        TuringerTransform(opaqu = hostResult)
    }

    fun getComponentsByType(csType: Type) : Component {
        val hostResult = _get_components_by_type(this.opaqu, csType)
        Component(opaqu = hostResult)
    }

    fun getEnumerator() : IEnumerator {
        val hostResult = _core_turinger_transform__get_enumerator(this.opaqu)
        IEnumerator(opaqu = hostResult)
    }

    fun localScaleSet(value: Vec3) {
        val hostResult = _core_turinger_transform__local_scale_set(this.opaqu, value)
    }

    fun childCountGet() : Int {
        val hostResult = _core_turinger_transform__child_count_get(this.opaqu)
        hostResult
    }

    fun parentSet(value: TuringerTransform) {
        val hostResult = _core_turinger_transform__parent_set(this.opaqu, value)
    }

    fun getChild(index: Int) : TuringerTransform {
        val hostResult = _core_turinger_transform__get_child(this.opaqu, index)
        TuringerTransform(opaqu = hostResult)
    }

    fun transformDirection(direction: Vec3) : Vec3 {
        val hostResult = _core_turinger_transform__transform_direction(this.opaqu, direction)
        hostResult
    }

    fun hasChangedSet(value: Boolean) {
        val hostResult = _core_turinger_transform__has_changed_set(this.opaqu, value)
    }

    fun sendMessageUpwards(methodName: String, value: Object, options: Int) {
        val hostResult = _core_turinger_transform__send_message_upwards(this.opaqu, methodName.cstr, value, options)
    }

    fun findChild(n: String) : TuringerTransform {
        val hostResult = _core_turinger_transform__find_child(this.opaqu, n.cstr)
        TuringerTransform(opaqu = hostResult)
    }

    fun getComponentsInParentByType(t: Type, includeInactive: Boolean) : Component {
        val hostResult = _get_components_in_parent_by_type(this.opaqu, t, includeInactive)
        Component(opaqu = hostResult)
    }

    fun rotate(eulers: Vec3) {
        val hostResult = _core_turinger_transform__rotate(this.opaqu, eulers)
    }

    fun hasChangedGet() : Boolean {
        val hostResult = _core_turinger_transform__has_changed_get(this.opaqu)
        hostResult
    }

    fun localPositionGet() : Vec3 {
        val hostResult = _core_turinger_transform__local_position_get(this.opaqu)
        hostResult
    }

    fun translateRelative(translation: Vec3, relativeTo: TuringerTransform) {
        val hostResult = _core_turinger_transform__translate_relative(this.opaqu, translation, relativeTo)
    }

    fun localEulerAnglesSet(value: Vec3) {
        val hostResult = _core_turinger_transform__local_euler_angles_set(this.opaqu, value)
    }

    fun setLocalPositionAndRotation(localPosition: Vec3, localRotation: Quat) {
        val hostResult = _core_turinger_transform__set_local_position_and_rotation(this.opaqu, localPosition, localRotation)
    }

    fun forwardGet() : Vec3 {
        val hostResult = _core_turinger_transform__forward_get(this.opaqu)
        hostResult
    }

    fun getSiblingIndex() : Int {
        val hostResult = _core_turinger_transform__get_sibling_index(this.opaqu)
        hostResult
    }

    fun getComponentInParentByType(t: Type, includeInactive: Boolean) : Component {
        val hostResult = _core_turinger_transform__get_component_in_parent_by_type(this.opaqu, t, includeInactive)
        Component(opaqu = hostResult)
    }

    fun upGet() : Vec3 {
        val hostResult = _core_turinger_transform__up_get(this.opaqu)
        hostResult
    }

    fun getComponentIndex() : Int {
        val hostResult = _core_turinger_transform__get_component_index(this.opaqu)
        hostResult
    }

    fun rotateAroundLocal(axis: Vec3, angle: Float) {
        val hostResult = _core_turinger_transform__rotate_around_local(this.opaqu, axis, angle)
    }

    fun translate(translation: Vec3, relativeTo: Int) {
        val hostResult = _core_turinger_transform__translate(this.opaqu, translation, relativeTo)
    }

    fun broadcastMessage(methodName: String, parameter: Object, options: Int) {
        val hostResult = _core_turinger_transform__broadcast_message(this.opaqu, methodName.cstr, parameter, options)
    }

    fun eulerAnglesSet(value: Vec3) {
        val hostResult = _core_turinger_transform__euler_angles_set(this.opaqu, value)
    }

    fun sendMessage(methodName: String, value: Object, options: Int) {
        val hostResult = _core_turinger_transform__send_message(this.opaqu, methodName.cstr, value, options)
    }

    fun parentGet() : TuringerTransform {
        val hostResult = _core_turinger_transform__parent_get(this.opaqu)
        TuringerTransform(opaqu = hostResult)
    }

    fun localToWorldMatrixGet() : Mat4 {
        val hostResult = _core_turinger_transform__local_to_world_matrix_get(this.opaqu)
        hostResult
    }

    fun getComponentByName(csType: String) : Component {
        val hostResult = _core_turinger_transform__get_component_by_name(this.opaqu, csType.cstr)
        Component(opaqu = hostResult)
    }

    fun setParent(parent: TuringerTransform, worldPositionStays: Boolean) {
        val hostResult = _core_turinger_transform__set_parent(this.opaqu, parent, worldPositionStays)
    }

    fun rotateAround(point: Vec3, axis: Vec3, angle: Float) {
        val hostResult = _core_turinger_transform__rotate_around(this.opaqu, point, axis, angle)
    }

    fun hierarchyCapacitySet(value: Int) {
        val hostResult = _core_turinger_transform__hierarchy_capacity_set(this.opaqu, value)
    }

    fun upSet(value: Vec3) {
        val hostResult = _core_turinger_transform__up_set(this.opaqu, value)
    }

    fun inverseTransformDirection(direction: Vec3) : Vec3 {
        val hostResult = _core_turinger_transform__inverse_transform_direction(this.opaqu, direction)
        hostResult
    }

    fun localScaleGet() : Vec3 {
        val hostResult = _core_turinger_transform__local_scale_get(this.opaqu)
        hostResult
    }

    fun transformVector(vector: Vec3) : Vec3 {
        val hostResult = _core_turinger_transform__transform_vector(this.opaqu, vector)
        hostResult
    }

    fun transformPoint(position: Vec3) : Vec3 {
        val hostResult = _core_turinger_transform__transform_point(this.opaqu, position)
        hostResult
    }

    fun eulerAnglesGet() : Vec3 {
        val hostResult = _core_turinger_transform__euler_angles_get(this.opaqu)
        hostResult
    }

    fun isChildOf(parent: TuringerTransform) : Boolean {
        val hostResult = _core_turinger_transform__is_child_of(this.opaqu, parent)
        hostResult
    }

    fun rightSet(value: Vec3) {
        val hostResult = _core_turinger_transform__right_set(this.opaqu, value)
    }

    fun getChildCount() : Int {
        val hostResult = _core_turinger_transform__get_child_count(this.opaqu)
        hostResult
    }

    fun hideFlagsGet() : Int {
        val hostResult = _core_turinger_transform__hide_flags_get(this.opaqu)
        hostResult
    }

    fun rotateRelative(eulers: Vec3, relativeTo: Int) {
        val hostResult = _core_turinger_transform__rotate_relative(this.opaqu, eulers, relativeTo)
    }

    fun rotationSet(value: Quat) {
        val hostResult = _core_turinger_transform__rotation_set(this.opaqu, value)
    }

    fun gameObjectGet() : TuringerGameObject {
        val hostResult = _core_turinger_transform__game_object_get(this.opaqu)
        TuringerGameObject(opaqu = hostResult)
    }

    fun hierarchyCapacityGet() : Int {
        val hostResult = _core_turinger_transform__hierarchy_capacity_get(this.opaqu)
        hostResult
    }

    fun setAsFirstSibling() {
        val hostResult = _core_turinger_transform__set_as_first_sibling(this.opaqu)
    }

    fun rightGet() : Vec3 {
        val hostResult = _core_turinger_transform__right_get(this.opaqu)
        hostResult
    }

    fun localPositionSet(value: Vec3) {
        val hostResult = _core_turinger_transform__local_position_set(this.opaqu, value)
    }

    fun forwardSet(value: Vec3) {
        val hostResult = _core_turinger_transform__forward_set(this.opaqu, value)
    }

    fun nameGet() : String {
        val hostResult = _core_turinger_transform__name_get(this.opaqu)
        val useMe = hostResult?.toKString() ?: error("null pointer returned")
        useMe
    }

    fun compareTag(tag: String) : Boolean {
        val hostResult = _core_turinger_transform__compare_tag(this.opaqu, tag.cstr)
        hostResult
    }

    fun setAsLastSibling() {
        val hostResult = _core_turinger_transform__set_as_last_sibling(this.opaqu)
    }

    fun positionGet() : Vec3 {
        val hostResult = _core_turinger_transform__position_get(this.opaqu)
        hostResult
    }

    fun setSiblingIndex(index: Int) {
        val hostResult = _core_turinger_transform__set_sibling_index(this.opaqu, index)
    }

    fun positionSet(value: Vec3) {
        val hostResult = _core_turinger_transform__position_set(this.opaqu, value)
    }

    fun hideFlagsSet(value: Int) {
        val hostResult = _core_turinger_transform__hide_flags_set(this.opaqu, value)
    }

    fun setPositionAndRotation(position: Vec3, rotation: Quat) {
        val hostResult = _core_turinger_transform__set_position_and_rotation(this.opaqu, position, rotation)
    }

    fun find(n: String) : TuringerTransform {
        val hostResult = _core_turinger_transform__find(this.opaqu, n.cstr)
        TuringerTransform(opaqu = hostResult)
    }

    fun tagSet(value: String) {
        val hostResult = _core_turinger_transform__tag_set(this.opaqu, value.cstr)
    }

    fun localRotationSet(value: Quat) {
        val hostResult = _core_turinger_transform__local_rotation_set(this.opaqu, value)
    }

    fun inverseTransformVector(vector: Vec3) : Vec3 {
        val hostResult = _core_turinger_transform__inverse_transform_vector(this.opaqu, vector)
        hostResult
    }
}

