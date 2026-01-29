///// Generated Go API /////
package turing_api

// Helper functions for string conversion
func cString(s string) []byte {
    b := []byte(s)
    b = append(b, 0)
    return b
}

func goString(b []byte) string {
    for i, v := range b {
        if v == 0 {
            return string(b[:i])
        }
    }
    return string(b)
}

//// WASM Imports ////
//go:wasmimport env _host_strcpy
func _host_strcpy(location *byte, size uint32)
//go:wasmimport env _host_f32_enqueue
func _host_f32_enqueue(f float32)
//go:wasmimport env _host_f32_dequeue
func _host_f32_dequeue() float32
//go:wasmimport env _log__warn
func _log__warn(msg *byte)
//go:wasmimport env _log__info
func _log__info(msg *byte)
//go:wasmimport env _log__debug
func _log__debug(msg *byte)
//go:wasmimport env _log__critical
func _log__critical(msg *byte)
//go:wasmimport env _note_manager__add_obstacle
func _note_manager__add_obstacle(beat float32, duration float32, line int32, layer int32, width int32, height int32, custom_data CustomData)
//go:wasmimport env _note_manager__add_color_note
func _note_manager__add_color_note(beat float32, line int32, layer int32, color int32, cut_direction int32, custom_data CustomData)
//go:wasmimport env _note_manager__time_to_beat
func _note_manager__time_to_beat(time float32) float32
//go:wasmimport env _note_manager__add_bomb_note
func _note_manager__add_bomb_note(beat float32, line int32, layer int32, custom_data CustomData)
//go:wasmimport env _turinger_game_object_manager__create_object
func _turinger_game_object_manager__create_object(name *byte) TuringerGameObject
//go:wasmimport env _turinger_game_object_manager__find
func _turinger_game_object_manager__find(name *byte) TuringerGameObject
//go:wasmimport env _turinger_game_object_manager__destroy_object
func _turinger_game_object_manager__destroy_object(listener TuringerGameObject)
//go:wasmimport env _turinger_game_object_manager__instance_get
func _turinger_game_object_manager__instance_get(opaqu uint64) TuringerGameObjectManager
//go:wasmimport env _get_components_in_parent_by_type
func _get_components_in_parent_by_type(opaqu uint64, cs_type Type, include_inactive bool) Component
//go:wasmimport env _turinger_game_object__send_message
func _turinger_game_object__send_message(opaqu uint64, method_name *byte)
//go:wasmimport env _turinger_game_object__get_component_in_parent_by_type
func _turinger_game_object__get_component_in_parent_by_type(opaqu uint64, cs_type Type) Component
//go:wasmimport env _turinger_game_object__is_static_get
func _turinger_game_object__is_static_get(opaqu uint64) bool
//go:wasmimport env _turinger_game_object__transform_get
func _turinger_game_object__transform_get(opaqu uint64) TuringerTransform
//go:wasmimport env _turinger_game_object__get_component_in_children_by_type
func _turinger_game_object__get_component_in_children_by_type(opaqu uint64, cs_type Type) Component
//go:wasmimport env _turinger_game_object__get_components_by_type
func _turinger_game_object__get_components_by_type(opaqu uint64, cs_type Type, results List1)
//go:wasmimport env _turinger_game_object__active_set
func _turinger_game_object__active_set(opaqu uint64, value bool)
//go:wasmimport env _turinger_game_object__broadcast_message
func _turinger_game_object__broadcast_message(opaqu uint64, method_name *byte)
//go:wasmimport env _turinger_game_object__game_object_get
func _turinger_game_object__game_object_get(opaqu uint64) GameObject
//go:wasmimport env _turinger_game_object__is_static_set
func _turinger_game_object__is_static_set(opaqu uint64, value bool)
//go:wasmimport env _turinger_game_object__add_component
func _turinger_game_object__add_component(opaqu uint64, component_type Type) Component
//go:wasmimport env _turinger_game_object__hide_flags_set
func _turinger_game_object__hide_flags_set(opaqu uint64, value int32)
//go:wasmimport env _turinger_game_object__send_message_upwards
func _turinger_game_object__send_message_upwards(opaqu uint64, method_name *byte)
//go:wasmimport env _turinger_game_object__compare_tag
func _turinger_game_object__compare_tag(opaqu uint64, tag *byte) bool
//go:wasmimport env _turinger_game_object__hide_flags_get
func _turinger_game_object__hide_flags_get(opaqu uint64) int32
//go:wasmimport env _turinger_game_object__tag_set
func _turinger_game_object__tag_set(opaqu uint64, value *byte)
//go:wasmimport env _turinger_game_object__get_instance_id
func _turinger_game_object__get_instance_id(opaqu uint64) int32
//go:wasmimport env _turinger_game_object__layer_get
func _turinger_game_object__layer_get(opaqu uint64) int32
//go:wasmimport env _get_components_in_children_by_type
func _get_components_in_children_by_type(opaqu uint64, cs_type Type, include_inactive bool) Component
//go:wasmimport env _turinger_game_object__layer_set
func _turinger_game_object__layer_set(opaqu uint64, value int32)
//go:wasmimport env _turinger_game_object__set_active_recursively
func _turinger_game_object__set_active_recursively(opaqu uint64, state bool)
//go:wasmimport env _turinger_game_object__get_component_index
func _turinger_game_object__get_component_index(opaqu uint64, component Component) int32
//go:wasmimport env _turinger_game_object__get_component_count
func _turinger_game_object__get_component_count(opaqu uint64) int32
//go:wasmimport env _turinger_game_object__get_component_at_index
func _turinger_game_object__get_component_at_index(opaqu uint64, index int32) Component
//go:wasmimport env _turinger_game_object__tag_get
func _turinger_game_object__tag_get(opaqu uint64) uint32
//go:wasmimport env _turinger_game_object__active_self_get
func _turinger_game_object__active_self_get(opaqu uint64) bool
//go:wasmimport env _turinger_game_object__name_get
func _turinger_game_object__name_get(opaqu uint64) uint32
//go:wasmimport env _turinger_game_object__get_component_by_type
func _turinger_game_object__get_component_by_type(opaqu uint64, cs_type Type) Component
//go:wasmimport env _turinger_game_object__active_in_hierarchy_get
func _turinger_game_object__active_in_hierarchy_get(opaqu uint64) bool
//go:wasmimport env _turinger_game_object__set_active
func _turinger_game_object__set_active(opaqu uint64, value bool)
//go:wasmimport env _turinger_game_object__active_get
func _turinger_game_object__active_get(opaqu uint64) bool
//go:wasmimport env _turinger_game_object__get_component_by_name
func _turinger_game_object__get_component_by_name(opaqu uint64, cs_type *byte) Component
//go:wasmimport env _turinger_game_object__name_set
func _turinger_game_object__name_set(opaqu uint64, value *byte)
//go:wasmimport env _turinger_game_object__scene_culling_mask_get
func _turinger_game_object__scene_culling_mask_get(opaqu uint64) uint64
//go:wasmimport env _turinger_transform__get_component_by_type
func _turinger_transform__get_component_by_type(opaqu uint64, cs_type Type) Component
//go:wasmimport env _turinger_transform__look_at
func _turinger_transform__look_at(opaqu uint64, world_position uint32)
//go:wasmimport env _turinger_transform__get_instance_id
func _turinger_transform__get_instance_id(opaqu uint64) int32
//go:wasmimport env _turinger_transform__tag_get
func _turinger_transform__tag_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__local_euler_angles_get
func _turinger_transform__local_euler_angles_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__rotation_get
func _turinger_transform__rotation_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__world_to_local_matrix_get
func _turinger_transform__world_to_local_matrix_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__hierarchy_count_get
func _turinger_transform__hierarchy_count_get(opaqu uint64) int32
//go:wasmimport env _get_components_in_children_by_type
func _get_components_in_children_by_type(opaqu uint64, t Type, include_inactive bool) Component
//go:wasmimport env _turinger_transform__name_set
func _turinger_transform__name_set(opaqu uint64, value *byte)
//go:wasmimport env _turinger_transform__local_rotation_get
func _turinger_transform__local_rotation_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__detach_children
func _turinger_transform__detach_children(opaqu uint64)
//go:wasmimport env _turinger_transform__inverse_transform_point
func _turinger_transform__inverse_transform_point(opaqu uint64, x float32, y float32, z float32) uint32
//go:wasmimport env _turinger_transform__get_component_in_children_by_type
func _turinger_transform__get_component_in_children_by_type(opaqu uint64, t Type, include_inactive bool) Component
//go:wasmimport env _turinger_transform__transform_get
func _turinger_transform__transform_get(opaqu uint64) Transform
//go:wasmimport env _turinger_transform__lossy_scale_get
func _turinger_transform__lossy_scale_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__root_get
func _turinger_transform__root_get(opaqu uint64) TuringerTransform
//go:wasmimport env _turinger_transform__get_components_by_type
func _turinger_transform__get_components_by_type(opaqu uint64, cs_type Type, results List1)
//go:wasmimport env _turinger_transform__get_enumerator
func _turinger_transform__get_enumerator(opaqu uint64) IEnumerator
//go:wasmimport env _turinger_transform__local_scale_set
func _turinger_transform__local_scale_set(opaqu uint64, value uint32)
//go:wasmimport env _turinger_transform__child_count_get
func _turinger_transform__child_count_get(opaqu uint64) int32
//go:wasmimport env _turinger_transform__parent_set
func _turinger_transform__parent_set(opaqu uint64, value TuringerTransform)
//go:wasmimport env _turinger_transform__get_child
func _turinger_transform__get_child(opaqu uint64, index int32) TuringerTransform
//go:wasmimport env _turinger_transform__transform_direction
func _turinger_transform__transform_direction(opaqu uint64, x float32, y float32, z float32) uint32
//go:wasmimport env _turinger_transform__has_changed_set
func _turinger_transform__has_changed_set(opaqu uint64, value bool)
//go:wasmimport env _turinger_transform__send_message_upwards
func _turinger_transform__send_message_upwards(opaqu uint64, method_name *byte, value Object, options int32)
//go:wasmimport env _turinger_transform__find_child
func _turinger_transform__find_child(opaqu uint64, n *byte) TuringerTransform
//go:wasmimport env _get_components_in_parent_by_type
func _get_components_in_parent_by_type(opaqu uint64, t Type, include_inactive bool) Component
//go:wasmimport env _turinger_transform__rotate
func _turinger_transform__rotate(opaqu uint64, axis uint32, angle float32)
//go:wasmimport env _turinger_transform__has_changed_get
func _turinger_transform__has_changed_get(opaqu uint64) bool
//go:wasmimport env _turinger_transform__local_position_get
func _turinger_transform__local_position_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__translate_relative
func _turinger_transform__translate_relative(opaqu uint64, translation uint32, relative_to TuringerTransform)
//go:wasmimport env _turinger_transform__local_euler_angles_set
func _turinger_transform__local_euler_angles_set(opaqu uint64, value uint32)
//go:wasmimport env _turinger_transform__set_local_position_and_rotation
func _turinger_transform__set_local_position_and_rotation(opaqu uint64, local_position uint32, local_rotation uint32)
//go:wasmimport env _turinger_transform__forward_get
func _turinger_transform__forward_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__get_sibling_index
func _turinger_transform__get_sibling_index(opaqu uint64) int32
//go:wasmimport env _turinger_transform__get_component_in_parent_by_type
func _turinger_transform__get_component_in_parent_by_type(opaqu uint64, t Type, include_inactive bool) Component
//go:wasmimport env _turinger_transform__up_get
func _turinger_transform__up_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__get_component_index
func _turinger_transform__get_component_index(opaqu uint64) int32
//go:wasmimport env _turinger_transform__rotate_around_local
func _turinger_transform__rotate_around_local(opaqu uint64, axis uint32, angle float32)
//go:wasmimport env _turinger_transform__translate
func _turinger_transform__translate(opaqu uint64, translation uint32)
//go:wasmimport env _turinger_transform__broadcast_message
func _turinger_transform__broadcast_message(opaqu uint64, method_name *byte, parameter Object, options int32)
//go:wasmimport env _turinger_transform__euler_angles_set
func _turinger_transform__euler_angles_set(opaqu uint64, value uint32)
//go:wasmimport env _turinger_transform__send_message
func _turinger_transform__send_message(opaqu uint64, method_name *byte, value Object, options int32)
//go:wasmimport env _turinger_transform__parent_get
func _turinger_transform__parent_get(opaqu uint64) TuringerTransform
//go:wasmimport env _turinger_transform__local_to_world_matrix_get
func _turinger_transform__local_to_world_matrix_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__get_component_by_name
func _turinger_transform__get_component_by_name(opaqu uint64, cs_type *byte) Component
//go:wasmimport env _turinger_transform__set_parent
func _turinger_transform__set_parent(opaqu uint64, parent TuringerTransform, world_position_stays bool)
//go:wasmimport env _turinger_transform__rotate_around
func _turinger_transform__rotate_around(opaqu uint64, axis uint32, angle float32)
//go:wasmimport env _turinger_transform__hierarchy_capacity_set
func _turinger_transform__hierarchy_capacity_set(opaqu uint64, value int32)
//go:wasmimport env _turinger_transform__up_set
func _turinger_transform__up_set(opaqu uint64, value uint32)
//go:wasmimport env _turinger_transform__inverse_transform_direction
func _turinger_transform__inverse_transform_direction(opaqu uint64, x float32, y float32, z float32) uint32
//go:wasmimport env _turinger_transform__local_scale_get
func _turinger_transform__local_scale_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__transform_vector
func _turinger_transform__transform_vector(opaqu uint64, x float32, y float32, z float32) uint32
//go:wasmimport env _turinger_transform__transform_point
func _turinger_transform__transform_point(opaqu uint64, x float32, y float32, z float32) uint32
//go:wasmimport env _turinger_transform__euler_angles_get
func _turinger_transform__euler_angles_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__is_child_of
func _turinger_transform__is_child_of(opaqu uint64, parent TuringerTransform) bool
//go:wasmimport env _turinger_transform__right_set
func _turinger_transform__right_set(opaqu uint64, value uint32)
//go:wasmimport env _turinger_transform__get_child_count
func _turinger_transform__get_child_count(opaqu uint64) int32
//go:wasmimport env _turinger_transform__hide_flags_get
func _turinger_transform__hide_flags_get(opaqu uint64) int32
//go:wasmimport env _turinger_transform__rotate_relative
func _turinger_transform__rotate_relative(opaqu uint64, axis uint32, angle float32, relative_to int32)
//go:wasmimport env _turinger_transform__rotation_set
func _turinger_transform__rotation_set(opaqu uint64, value uint32)
//go:wasmimport env _turinger_transform__game_object_get
func _turinger_transform__game_object_get(opaqu uint64) TuringerGameObject
//go:wasmimport env _turinger_transform__hierarchy_capacity_get
func _turinger_transform__hierarchy_capacity_get(opaqu uint64) int32
//go:wasmimport env _turinger_transform__set_as_first_sibling
func _turinger_transform__set_as_first_sibling(opaqu uint64)
//go:wasmimport env _turinger_transform__right_get
func _turinger_transform__right_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__local_position_set
func _turinger_transform__local_position_set(opaqu uint64, value uint32)
//go:wasmimport env _turinger_transform__forward_set
func _turinger_transform__forward_set(opaqu uint64, value uint32)
//go:wasmimport env _turinger_transform__name_get
func _turinger_transform__name_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__compare_tag
func _turinger_transform__compare_tag(opaqu uint64, tag *byte) bool
//go:wasmimport env _turinger_transform__set_as_last_sibling
func _turinger_transform__set_as_last_sibling(opaqu uint64)
//go:wasmimport env _turinger_transform__position_get
func _turinger_transform__position_get(opaqu uint64) uint32
//go:wasmimport env _turinger_transform__set_sibling_index
func _turinger_transform__set_sibling_index(opaqu uint64, index int32)
//go:wasmimport env _turinger_transform__position_set
func _turinger_transform__position_set(opaqu uint64, value uint32)
//go:wasmimport env _turinger_transform__hide_flags_set
func _turinger_transform__hide_flags_set(opaqu uint64, value int32)
//go:wasmimport env _turinger_transform__set_position_and_rotation
func _turinger_transform__set_position_and_rotation(opaqu uint64, position uint32, rotation uint32)
//go:wasmimport env _turinger_transform__find
func _turinger_transform__find(opaqu uint64, n *byte) TuringerTransform
//go:wasmimport env _turinger_transform__tag_set
func _turinger_transform__tag_set(opaqu uint64, value *byte)
//go:wasmimport env _turinger_transform__local_rotation_set
func _turinger_transform__local_rotation_set(opaqu uint64, value uint32)
//go:wasmimport env _turinger_transform__inverse_transform_vector
func _turinger_transform__inverse_transform_vector(opaqu uint64, x float32, y float32, z float32) uint32
//go:wasmimport env _gc_helper__create
func _gc_helper__create() GCHelper
//go:wasmimport env _gc_helper__wasm_garbage_collect
func _gc_helper__wasm_garbage_collect(opaqu uint64)
//go:wasmimport env _gc_helper__dispose
func _gc_helper__dispose(opaqu uint64)
//go:wasmimport env _gc_helper__invalidate_all_handles
func _gc_helper__invalidate_all_handles(opaqu uint64)
//go:wasmimport env _xr__get_device_tracking_state
func _xr__get_device_tracking_state(node_int int32) int32
//go:wasmimport env _xr__get_device_name
func _xr__get_device_name(node_int int32) uint32
//go:wasmimport env _xr__get_device_secondary_button_state
func _xr__get_device_secondary_button_state(node_int int32) bool
//go:wasmimport env _xr__get_device_primary_button_state
func _xr__get_device_primary_button_state(node_int int32) bool
//go:wasmimport env _xr__send_haptic_impulse
func _xr__send_haptic_impulse(node_int int32, amplitude float32, duration float32)
//go:wasmimport env _xr__is_device_valid
func _xr__is_device_valid(node_int int32) bool
//go:wasmimport env _xr__get_device_battery_level
func _xr__get_device_battery_level(node_int int32) float32
//go:wasmimport env _xr__get_device_touchpad
func _xr__get_device_touchpad(node_int int32) uint32
//go:wasmimport env _xr__get_device_grip_value
func _xr__get_device_grip_value(node_int int32) float32
//go:wasmimport env _xr__get_device_trigger_value
func _xr__get_device_trigger_value(node_int int32) float32
//go:wasmimport env _xr__stop_haptics
func _xr__stop_haptics(node_int int32)
//go:wasmimport env _xr__get_device_thumbstick
func _xr__get_device_thumbstick(node_int int32) uint32
//go:wasmimport env _xr___manager_get
func _xr___manager_get(opaqu uint64) TuringScriptManager
//go:wasmimport env _custom_data__create
func _custom_data__create() CustomData
//go:wasmimport env _list_create
func _list_create() List
//go:wasmimport env _custom_data__set_string
func _custom_data__set_string(custom_data CustomData, key *byte, value *byte)
//go:wasmimport env _custom_data__set_custom_data
func _custom_data__set_custom_data(custom_data CustomData, key *byte, value CustomData)
//go:wasmimport env _custom_data__list_add_string
func _custom_data__list_add_string(list List1, value *byte)
//go:wasmimport env _custom_data__set_custom_data_list
func _custom_data__set_custom_data_list(custom_data CustomData, key *byte, value List1)
//go:wasmimport env _custom_data__set_float
func _custom_data__set_float(custom_data CustomData, key *byte, value float32)
//go:wasmimport env _custom_data__list_add_int
func _custom_data__list_add_int(list List1, value int32)
//go:wasmimport env _custom_data__list_add_bool
func _custom_data__list_add_bool(list List1, value bool)
//go:wasmimport env _custom_data__set_int
func _custom_data__set_int(custom_data CustomData, key *byte, value int32)
//go:wasmimport env _custom_data__set_bool
func _custom_data__set_bool(custom_data CustomData, key *byte, value bool)
//go:wasmimport env _custom_data__list_add_custom_data_list
func _custom_data__list_add_custom_data_list(list List1, value List1)
//go:wasmimport env _custom_data__list_add_float
func _custom_data__list_add_float(list List1, value float32)
//go:wasmimport env _custom_data__list_add_custom_data
func _custom_data__list_add_custom_data(list List1, value CustomData)

//export _turing_api_semver
func _turing_api_semver() uint64 {
    return (uint64(0) << 32) | (uint64(1) << 16) | uint64(0)
}

const APIVersion = "0.1.0"

//// Functions ////


//// Classes ////

type GameObject struct {
    opaqu uint64
}



type Transform struct {
    opaqu uint64
}



type TuringScriptManager struct {
    opaqu uint64
}



type Object struct {
    opaqu uint64
}



type List1 struct {
    opaqu uint64
}



type List struct {
    opaqu uint64
}



type Component struct {
    opaqu uint64
}



type Type struct {
    opaqu uint64
}



type IEnumerator struct {
    opaqu uint64
}



type Log struct {
}


func Log_warn(msg string) {
    turing_handle_msg := cString(msg)
    msgPtr := &turing_handle_msg[0]
    _log__warn(msgPtr)
}

func Log_info(msg string) {
    turing_handle_msg := cString(msg)
    msgPtr := &turing_handle_msg[0]
    _log__info(msgPtr)
}

func Log_debug(msg string) {
    turing_handle_msg := cString(msg)
    msgPtr := &turing_handle_msg[0]
    _log__debug(msgPtr)
}

func Log_critical(msg string) {
    turing_handle_msg := cString(msg)
    msgPtr := &turing_handle_msg[0]
    _log__critical(msgPtr)
}


type NoteManager struct {
}


func NoteManager_addObstacle(beat float32, duration float32, line int32, layer int32, width int32, height int32, customData CustomData) {
    _note_manager__add_obstacle(beat, duration, line, layer, width, height, customData)
}

func NoteManager_addColorNote(beat float32, line int32, layer int32, color int32, cutDirection int32, customData CustomData) {
    _note_manager__add_color_note(beat, line, layer, color, cutDirection, customData)
}

func NoteManager_timeToBeat(time float32) float32 {
    return _note_manager__time_to_beat(time)
}

func NoteManager_addBombNote(beat float32, line int32, layer int32, customData CustomData) {
    _note_manager__add_bomb_note(beat, line, layer, customData)
}


type TuringerGameObjectManager struct {
    opaqu uint64
}


func TuringerGameObjectManager_createObject(name string) *TuringerGameObject {
    turing_handle_name := cString(name)
    namePtr := &turing_handle_name[0]
    turingResult := _turinger_game_object_manager__create_object(namePtr)
    return &TuringerGameObject{opaqu: turingResult}
}

func TuringerGameObjectManager_find(name string) *TuringerGameObject {
    turing_handle_name := cString(name)
    namePtr := &turing_handle_name[0]
    turingResult := _turinger_game_object_manager__find(namePtr)
    return &TuringerGameObject{opaqu: turingResult}
}

func TuringerGameObjectManager_destroyObject(listener TuringerGameObject) {
    _turinger_game_object_manager__destroy_object(listener)
}


func (self *TuringerGameObjectManager) instanceGet() *TuringerGameObjectManager {
    turingResult := _turinger_game_object_manager__instance_get(self.opaqu)
    return &TuringerGameObjectManager{opaqu: turingResult}
}

type TuringerGameObject struct {
    opaqu uint64
}



func (self *TuringerGameObject) getComponentsInParentByType(csType Type, includeInactive bool) *Component {
    turingResult := _get_components_in_parent_by_type(self.opaqu, csType, includeInactive)
    return &Component{opaqu: turingResult}
}

func (self *TuringerGameObject) sendMessage(methodName string) {
    turing_handle_method_name := cString(methodName)
    methodNamePtr := &turing_handle_method_name[0]
    _turinger_game_object__send_message(self.opaqu, methodNamePtr)
}

func (self *TuringerGameObject) getComponentInParentByType(csType Type) *Component {
    turingResult := _turinger_game_object__get_component_in_parent_by_type(self.opaqu, csType)
    return &Component{opaqu: turingResult}
}

func (self *TuringerGameObject) isStaticGet() bool {
    return _turinger_game_object__is_static_get(self.opaqu)
}

func (self *TuringerGameObject) transformGet() *TuringerTransform {
    turingResult := _turinger_game_object__transform_get(self.opaqu)
    return &TuringerTransform{opaqu: turingResult}
}

func (self *TuringerGameObject) getComponentInChildrenByType(csType Type) *Component {
    turingResult := _turinger_game_object__get_component_in_children_by_type(self.opaqu, csType)
    return &Component{opaqu: turingResult}
}

func (self *TuringerGameObject) getComponentsByType(csType Type, results List1) {
    _turinger_game_object__get_components_by_type(self.opaqu, csType, results)
}

func (self *TuringerGameObject) activeSet(value bool) {
    _turinger_game_object__active_set(self.opaqu, value)
}

func (self *TuringerGameObject) broadcastMessage(methodName string) {
    turing_handle_method_name := cString(methodName)
    methodNamePtr := &turing_handle_method_name[0]
    _turinger_game_object__broadcast_message(self.opaqu, methodNamePtr)
}

func (self *TuringerGameObject) gameObjectGet() *GameObject {
    turingResult := _turinger_game_object__game_object_get(self.opaqu)
    return &GameObject{opaqu: turingResult}
}

func (self *TuringerGameObject) isStaticSet(value bool) {
    _turinger_game_object__is_static_set(self.opaqu, value)
}

func (self *TuringerGameObject) addComponent(componentType Type) *Component {
    turingResult := _turinger_game_object__add_component(self.opaqu, componentType)
    return &Component{opaqu: turingResult}
}

func (self *TuringerGameObject) hideFlagsSet(value int32) {
    _turinger_game_object__hide_flags_set(self.opaqu, value)
}

func (self *TuringerGameObject) sendMessageUpwards(methodName string) {
    turing_handle_method_name := cString(methodName)
    methodNamePtr := &turing_handle_method_name[0]
    _turinger_game_object__send_message_upwards(self.opaqu, methodNamePtr)
}

func (self *TuringerGameObject) compareTag(tag string) bool {
    turing_handle_tag := cString(tag)
    tagPtr := &turing_handle_tag[0]
    return _turinger_game_object__compare_tag(self.opaqu, tagPtr)
}

func (self *TuringerGameObject) hideFlagsGet() int32 {
    return _turinger_game_object__hide_flags_get(self.opaqu)
}

func (self *TuringerGameObject) tagSet(value string) {
    turing_handle_value := cString(value)
    valuePtr := &turing_handle_value[0]
    _turinger_game_object__tag_set(self.opaqu, valuePtr)
}

func (self *TuringerGameObject) getInstanceId() int32 {
    return _turinger_game_object__get_instance_id(self.opaqu)
}

func (self *TuringerGameObject) layerGet() int32 {
    return _turinger_game_object__layer_get(self.opaqu)
}

func (self *TuringerGameObject) getComponentsInChildrenByType(csType Type, includeInactive bool) *Component {
    turingResult := _get_components_in_children_by_type(self.opaqu, csType, includeInactive)
    return &Component{opaqu: turingResult}
}

func (self *TuringerGameObject) layerSet(value int32) {
    _turinger_game_object__layer_set(self.opaqu, value)
}

func (self *TuringerGameObject) setActiveRecursively(state bool) {
    _turinger_game_object__set_active_recursively(self.opaqu, state)
}

func (self *TuringerGameObject) getComponentIndex(component Component) int32 {
    return _turinger_game_object__get_component_index(self.opaqu, component)
}

func (self *TuringerGameObject) getComponentCount() int32 {
    return _turinger_game_object__get_component_count(self.opaqu)
}

func (self *TuringerGameObject) getComponentAtIndex(index int32) *Component {
    turingResult := _turinger_game_object__get_component_at_index(self.opaqu, index)
    return &Component{opaqu: turingResult}
}

func (self *TuringerGameObject) tagGet() string {
    turingResult := _turinger_game_object__tag_get(self.opaqu)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], uint32(turingResult))
    return goString(turingStr)
}

func (self *TuringerGameObject) activeSelfGet() bool {
    return _turinger_game_object__active_self_get(self.opaqu)
}

func (self *TuringerGameObject) nameGet() string {
    turingResult := _turinger_game_object__name_get(self.opaqu)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], uint32(turingResult))
    return goString(turingStr)
}

func (self *TuringerGameObject) getComponentByType(csType Type) *Component {
    turingResult := _turinger_game_object__get_component_by_type(self.opaqu, csType)
    return &Component{opaqu: turingResult}
}

func (self *TuringerGameObject) activeInHierarchyGet() bool {
    return _turinger_game_object__active_in_hierarchy_get(self.opaqu)
}

func (self *TuringerGameObject) setActive(value bool) {
    _turinger_game_object__set_active(self.opaqu, value)
}

func (self *TuringerGameObject) activeGet() bool {
    return _turinger_game_object__active_get(self.opaqu)
}

func (self *TuringerGameObject) getComponentByName(csType string) *Component {
    turing_handle_cs_type := cString(csType)
    csTypePtr := &turing_handle_cs_type[0]
    turingResult := _turinger_game_object__get_component_by_name(self.opaqu, csTypePtr)
    return &Component{opaqu: turingResult}
}

func (self *TuringerGameObject) nameSet(value string) {
    turing_handle_value := cString(value)
    valuePtr := &turing_handle_value[0]
    _turinger_game_object__name_set(self.opaqu, valuePtr)
}

func (self *TuringerGameObject) sceneCullingMaskGet() uint64 {
    return _turinger_game_object__scene_culling_mask_get(self.opaqu)
}

type TuringerTransform struct {
    opaqu uint64
}



func (self *TuringerTransform) getComponentByType(csType Type) *Component {
    turingResult := _turinger_transform__get_component_by_type(self.opaqu, csType)
    return &Component{opaqu: turingResult}
}

func (self *TuringerTransform) lookAt(worldPosition Vec3) {
    _turinger_transform__look_at(self.opaqu, worldPosition)
}

func (self *TuringerTransform) getInstanceId() int32 {
    return _turinger_transform__get_instance_id(self.opaqu)
}

func (self *TuringerTransform) tagGet() string {
    turingResult := _turinger_transform__tag_get(self.opaqu)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], uint32(turingResult))
    return goString(turingStr)
}

func (self *TuringerTransform) localEulerAnglesGet() uint32 {
    return _turinger_transform__local_euler_angles_get(self.opaqu)
}

func (self *TuringerTransform) rotationGet() uint32 {
    return _turinger_transform__rotation_get(self.opaqu)
}

func (self *TuringerTransform) worldToLocalMatrixGet() uint32 {
    return _turinger_transform__world_to_local_matrix_get(self.opaqu)
}

func (self *TuringerTransform) hierarchyCountGet() int32 {
    return _turinger_transform__hierarchy_count_get(self.opaqu)
}

func (self *TuringerTransform) getComponentsInChildrenByType(t Type, includeInactive bool) *Component {
    turingResult := _get_components_in_children_by_type(self.opaqu, t, includeInactive)
    return &Component{opaqu: turingResult}
}

func (self *TuringerTransform) nameSet(value string) {
    turing_handle_value := cString(value)
    valuePtr := &turing_handle_value[0]
    _turinger_transform__name_set(self.opaqu, valuePtr)
}

func (self *TuringerTransform) localRotationGet() uint32 {
    return _turinger_transform__local_rotation_get(self.opaqu)
}

func (self *TuringerTransform) detachChildren() {
    _turinger_transform__detach_children(self.opaqu)
}

func (self *TuringerTransform) inverseTransformPoint(x float32, y float32, z float32) uint32 {
    return _turinger_transform__inverse_transform_point(self.opaqu, x, y, z)
}

func (self *TuringerTransform) getComponentInChildrenByType(t Type, includeInactive bool) *Component {
    turingResult := _turinger_transform__get_component_in_children_by_type(self.opaqu, t, includeInactive)
    return &Component{opaqu: turingResult}
}

func (self *TuringerTransform) transformGet() *Transform {
    turingResult := _turinger_transform__transform_get(self.opaqu)
    return &Transform{opaqu: turingResult}
}

func (self *TuringerTransform) lossyScaleGet() uint32 {
    return _turinger_transform__lossy_scale_get(self.opaqu)
}

func (self *TuringerTransform) rootGet() *TuringerTransform {
    turingResult := _turinger_transform__root_get(self.opaqu)
    return &TuringerTransform{opaqu: turingResult}
}

func (self *TuringerTransform) getComponentsByType(csType Type, results List1) {
    _turinger_transform__get_components_by_type(self.opaqu, csType, results)
}

func (self *TuringerTransform) getEnumerator() *IEnumerator {
    turingResult := _turinger_transform__get_enumerator(self.opaqu)
    return &IEnumerator{opaqu: turingResult}
}

func (self *TuringerTransform) localScaleSet(value Vec3) {
    _turinger_transform__local_scale_set(self.opaqu, value)
}

func (self *TuringerTransform) childCountGet() int32 {
    return _turinger_transform__child_count_get(self.opaqu)
}

func (self *TuringerTransform) parentSet(value TuringerTransform) {
    _turinger_transform__parent_set(self.opaqu, value)
}

func (self *TuringerTransform) getChild(index int32) *TuringerTransform {
    turingResult := _turinger_transform__get_child(self.opaqu, index)
    return &TuringerTransform{opaqu: turingResult}
}

func (self *TuringerTransform) transformDirection(x float32, y float32, z float32) uint32 {
    return _turinger_transform__transform_direction(self.opaqu, x, y, z)
}

func (self *TuringerTransform) hasChangedSet(value bool) {
    _turinger_transform__has_changed_set(self.opaqu, value)
}

func (self *TuringerTransform) sendMessageUpwards(methodName string, value Object, options int32) {
    turing_handle_method_name := cString(methodName)
    methodNamePtr := &turing_handle_method_name[0]
    _turinger_transform__send_message_upwards(self.opaqu, methodNamePtr, value, options)
}

func (self *TuringerTransform) findChild(n string) *TuringerTransform {
    turing_handle_n := cString(n)
    nPtr := &turing_handle_n[0]
    turingResult := _turinger_transform__find_child(self.opaqu, nPtr)
    return &TuringerTransform{opaqu: turingResult}
}

func (self *TuringerTransform) getComponentsInParentByType(t Type, includeInactive bool) *Component {
    turingResult := _get_components_in_parent_by_type(self.opaqu, t, includeInactive)
    return &Component{opaqu: turingResult}
}

func (self *TuringerTransform) rotate(axis Vec3, angle float32) {
    _turinger_transform__rotate(self.opaqu, axis, angle)
}

func (self *TuringerTransform) hasChangedGet() bool {
    return _turinger_transform__has_changed_get(self.opaqu)
}

func (self *TuringerTransform) localPositionGet() uint32 {
    return _turinger_transform__local_position_get(self.opaqu)
}

func (self *TuringerTransform) translateRelative(translation Vec3, relativeTo TuringerTransform) {
    _turinger_transform__translate_relative(self.opaqu, translation, relativeTo)
}

func (self *TuringerTransform) localEulerAnglesSet(value Vec3) {
    _turinger_transform__local_euler_angles_set(self.opaqu, value)
}

func (self *TuringerTransform) setLocalPositionAndRotation(localPosition Vec3, localRotation Quat) {
    _turinger_transform__set_local_position_and_rotation(self.opaqu, localPosition, localRotation)
}

func (self *TuringerTransform) forwardGet() uint32 {
    return _turinger_transform__forward_get(self.opaqu)
}

func (self *TuringerTransform) getSiblingIndex() int32 {
    return _turinger_transform__get_sibling_index(self.opaqu)
}

func (self *TuringerTransform) getComponentInParentByType(t Type, includeInactive bool) *Component {
    turingResult := _turinger_transform__get_component_in_parent_by_type(self.opaqu, t, includeInactive)
    return &Component{opaqu: turingResult}
}

func (self *TuringerTransform) upGet() uint32 {
    return _turinger_transform__up_get(self.opaqu)
}

func (self *TuringerTransform) getComponentIndex() int32 {
    return _turinger_transform__get_component_index(self.opaqu)
}

func (self *TuringerTransform) rotateAroundLocal(axis Vec3, angle float32) {
    _turinger_transform__rotate_around_local(self.opaqu, axis, angle)
}

func (self *TuringerTransform) translate(translation Vec3) {
    _turinger_transform__translate(self.opaqu, translation)
}

func (self *TuringerTransform) broadcastMessage(methodName string, parameter Object, options int32) {
    turing_handle_method_name := cString(methodName)
    methodNamePtr := &turing_handle_method_name[0]
    _turinger_transform__broadcast_message(self.opaqu, methodNamePtr, parameter, options)
}

func (self *TuringerTransform) eulerAnglesSet(value Vec3) {
    _turinger_transform__euler_angles_set(self.opaqu, value)
}

func (self *TuringerTransform) sendMessage(methodName string, value Object, options int32) {
    turing_handle_method_name := cString(methodName)
    methodNamePtr := &turing_handle_method_name[0]
    _turinger_transform__send_message(self.opaqu, methodNamePtr, value, options)
}

func (self *TuringerTransform) parentGet() *TuringerTransform {
    turingResult := _turinger_transform__parent_get(self.opaqu)
    return &TuringerTransform{opaqu: turingResult}
}

func (self *TuringerTransform) localToWorldMatrixGet() uint32 {
    return _turinger_transform__local_to_world_matrix_get(self.opaqu)
}

func (self *TuringerTransform) getComponentByName(csType string) *Component {
    turing_handle_cs_type := cString(csType)
    csTypePtr := &turing_handle_cs_type[0]
    turingResult := _turinger_transform__get_component_by_name(self.opaqu, csTypePtr)
    return &Component{opaqu: turingResult}
}

func (self *TuringerTransform) setParent(parent TuringerTransform, worldPositionStays bool) {
    _turinger_transform__set_parent(self.opaqu, parent, worldPositionStays)
}

func (self *TuringerTransform) rotateAround(axis Vec3, angle float32) {
    _turinger_transform__rotate_around(self.opaqu, axis, angle)
}

func (self *TuringerTransform) hierarchyCapacitySet(value int32) {
    _turinger_transform__hierarchy_capacity_set(self.opaqu, value)
}

func (self *TuringerTransform) upSet(value Vec3) {
    _turinger_transform__up_set(self.opaqu, value)
}

func (self *TuringerTransform) inverseTransformDirection(x float32, y float32, z float32) uint32 {
    return _turinger_transform__inverse_transform_direction(self.opaqu, x, y, z)
}

func (self *TuringerTransform) localScaleGet() uint32 {
    return _turinger_transform__local_scale_get(self.opaqu)
}

func (self *TuringerTransform) transformVector(x float32, y float32, z float32) uint32 {
    return _turinger_transform__transform_vector(self.opaqu, x, y, z)
}

func (self *TuringerTransform) transformPoint(x float32, y float32, z float32) uint32 {
    return _turinger_transform__transform_point(self.opaqu, x, y, z)
}

func (self *TuringerTransform) eulerAnglesGet() uint32 {
    return _turinger_transform__euler_angles_get(self.opaqu)
}

func (self *TuringerTransform) isChildOf(parent TuringerTransform) bool {
    return _turinger_transform__is_child_of(self.opaqu, parent)
}

func (self *TuringerTransform) rightSet(value Vec3) {
    _turinger_transform__right_set(self.opaqu, value)
}

func (self *TuringerTransform) getChildCount() int32 {
    return _turinger_transform__get_child_count(self.opaqu)
}

func (self *TuringerTransform) hideFlagsGet() int32 {
    return _turinger_transform__hide_flags_get(self.opaqu)
}

func (self *TuringerTransform) rotateRelative(axis Vec3, angle float32, relativeTo int32) {
    _turinger_transform__rotate_relative(self.opaqu, axis, angle, relativeTo)
}

func (self *TuringerTransform) rotationSet(value Quat) {
    _turinger_transform__rotation_set(self.opaqu, value)
}

func (self *TuringerTransform) gameObjectGet() *TuringerGameObject {
    turingResult := _turinger_transform__game_object_get(self.opaqu)
    return &TuringerGameObject{opaqu: turingResult}
}

func (self *TuringerTransform) hierarchyCapacityGet() int32 {
    return _turinger_transform__hierarchy_capacity_get(self.opaqu)
}

func (self *TuringerTransform) setAsFirstSibling() {
    _turinger_transform__set_as_first_sibling(self.opaqu)
}

func (self *TuringerTransform) rightGet() uint32 {
    return _turinger_transform__right_get(self.opaqu)
}

func (self *TuringerTransform) localPositionSet(value Vec3) {
    _turinger_transform__local_position_set(self.opaqu, value)
}

func (self *TuringerTransform) forwardSet(value Vec3) {
    _turinger_transform__forward_set(self.opaqu, value)
}

func (self *TuringerTransform) nameGet() string {
    turingResult := _turinger_transform__name_get(self.opaqu)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], uint32(turingResult))
    return goString(turingStr)
}

func (self *TuringerTransform) compareTag(tag string) bool {
    turing_handle_tag := cString(tag)
    tagPtr := &turing_handle_tag[0]
    return _turinger_transform__compare_tag(self.opaqu, tagPtr)
}

func (self *TuringerTransform) setAsLastSibling() {
    _turinger_transform__set_as_last_sibling(self.opaqu)
}

func (self *TuringerTransform) positionGet() uint32 {
    return _turinger_transform__position_get(self.opaqu)
}

func (self *TuringerTransform) setSiblingIndex(index int32) {
    _turinger_transform__set_sibling_index(self.opaqu, index)
}

func (self *TuringerTransform) positionSet(value Vec3) {
    _turinger_transform__position_set(self.opaqu, value)
}

func (self *TuringerTransform) hideFlagsSet(value int32) {
    _turinger_transform__hide_flags_set(self.opaqu, value)
}

func (self *TuringerTransform) setPositionAndRotation(position Vec3, rotation Quat) {
    _turinger_transform__set_position_and_rotation(self.opaqu, position, rotation)
}

func (self *TuringerTransform) find(n string) *TuringerTransform {
    turing_handle_n := cString(n)
    nPtr := &turing_handle_n[0]
    turingResult := _turinger_transform__find(self.opaqu, nPtr)
    return &TuringerTransform{opaqu: turingResult}
}

func (self *TuringerTransform) tagSet(value string) {
    turing_handle_value := cString(value)
    valuePtr := &turing_handle_value[0]
    _turinger_transform__tag_set(self.opaqu, valuePtr)
}

func (self *TuringerTransform) localRotationSet(value Quat) {
    _turinger_transform__local_rotation_set(self.opaqu, value)
}

func (self *TuringerTransform) inverseTransformVector(x float32, y float32, z float32) uint32 {
    return _turinger_transform__inverse_transform_vector(self.opaqu, x, y, z)
}

type GcHelper struct {
    opaqu uint64
}


func GcHelper_create() *GcHelper {
    turingResult := _gc_helper__create()
    return &GcHelper{opaqu: turingResult}
}


func (self *GcHelper) wasmGarbageCollect() {
    _gc_helper__wasm_garbage_collect(self.opaqu)
}

func (self *GcHelper) dispose() {
    _gc_helper__dispose(self.opaqu)
}

func (self *GcHelper) invalidateAllHandles() {
    _gc_helper__invalidate_all_handles(self.opaqu)
}

type Xr struct {
    opaqu uint64
}


func Xr_getDeviceTrackingState(nodeInt int32) int32 {
    return _xr__get_device_tracking_state(nodeInt)
}

func Xr_getDeviceName(nodeInt int32) string {
    turingResult := _xr__get_device_name(nodeInt)
    turingStr := make([]byte, turingResult)
    _host_strcpy(&turingStr[0], uint32(turingResult))
    return goString(turingStr)
}

func Xr_getDeviceSecondaryButtonState(nodeInt int32) bool {
    return _xr__get_device_secondary_button_state(nodeInt)
}

func Xr_getDevicePrimaryButtonState(nodeInt int32) bool {
    return _xr__get_device_primary_button_state(nodeInt)
}

func Xr_sendHapticImpulse(nodeInt int32, amplitude float32, duration float32) {
    _xr__send_haptic_impulse(nodeInt, amplitude, duration)
}

func Xr_isDeviceValid(nodeInt int32) bool {
    return _xr__is_device_valid(nodeInt)
}

func Xr_getDeviceBatteryLevel(nodeInt int32) float32 {
    return _xr__get_device_battery_level(nodeInt)
}

func Xr_getDeviceTouchpad(nodeInt int32) uint32 {
    return _xr__get_device_touchpad(nodeInt)
}

func Xr_getDeviceGripValue(nodeInt int32) float32 {
    return _xr__get_device_grip_value(nodeInt)
}

func Xr_getDeviceTriggerValue(nodeInt int32) float32 {
    return _xr__get_device_trigger_value(nodeInt)
}

func Xr_stopHaptics(nodeInt int32) {
    _xr__stop_haptics(nodeInt)
}

func Xr_getDeviceThumbstick(nodeInt int32) uint32 {
    return _xr__get_device_thumbstick(nodeInt)
}


func (self *Xr) ManagerGet() *TuringScriptManager {
    turingResult := _xr___manager_get(self.opaqu)
    return &TuringScriptManager{opaqu: turingResult}
}

type CustomData struct {
    opaqu uint64
}


func CustomData_create() *CustomData {
    turingResult := _custom_data__create()
    return &CustomData{opaqu: turingResult}
}

func CustomData_listCreate() *List {
    turingResult := _list_create()
    return &List{opaqu: turingResult}
}

func CustomData_setString(customData CustomData, key string, value string) {
    turing_handle_key := cString(key)
    keyPtr := &turing_handle_key[0]
    turing_handle_value := cString(value)
    valuePtr := &turing_handle_value[0]
    _custom_data__set_string(customData, keyPtr, valuePtr)
}

func CustomData_setCustomData(customData CustomData, key string, value CustomData) {
    turing_handle_key := cString(key)
    keyPtr := &turing_handle_key[0]
    _custom_data__set_custom_data(customData, keyPtr, value)
}

func CustomData_listAddString(list List1, value string) {
    turing_handle_value := cString(value)
    valuePtr := &turing_handle_value[0]
    _custom_data__list_add_string(list, valuePtr)
}

func CustomData_setCustomDataList(customData CustomData, key string, value List1) {
    turing_handle_key := cString(key)
    keyPtr := &turing_handle_key[0]
    _custom_data__set_custom_data_list(customData, keyPtr, value)
}

func CustomData_setFloat(customData CustomData, key string, value float32) {
    turing_handle_key := cString(key)
    keyPtr := &turing_handle_key[0]
    _custom_data__set_float(customData, keyPtr, value)
}

func CustomData_listAddInt(list List1, value int32) {
    _custom_data__list_add_int(list, value)
}

func CustomData_listAddBool(list List1, value bool) {
    _custom_data__list_add_bool(list, value)
}

func CustomData_setInt(customData CustomData, key string, value int32) {
    turing_handle_key := cString(key)
    keyPtr := &turing_handle_key[0]
    _custom_data__set_int(customData, keyPtr, value)
}

func CustomData_setBool(customData CustomData, key string, value bool) {
    turing_handle_key := cString(key)
    keyPtr := &turing_handle_key[0]
    _custom_data__set_bool(customData, keyPtr, value)
}

func CustomData_listAddCustomDataList(list List1, value List1) {
    _custom_data__list_add_custom_data_list(list, value)
}

func CustomData_listAddFloat(list List1, value float32) {
    _custom_data__list_add_float(list, value)
}

func CustomData_listAddCustomData(list List1, value CustomData) {
    _custom_data__list_add_custom_data(list, value)
}

