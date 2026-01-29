///// Generated Zig API /////
const std = @import("std");
const zalg = @import("zalgebra");

pub fn enqueue_vec2(v: zalg.Vec2) u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    return 2;
}

pub fn enqueue_vec3(v: zalg.Vec3) u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    return 3;
}

pub fn enqueue_vec4(v: zalg.Vec4) u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    _host_f32_enqueue(v.w);
    return 4;
}

pub fn enqueue_quat(q: zalg.Quat) u32 {
    _host_f32_enqueue(q.x);
    _host_f32_enqueue(q.y);
    _host_f32_enqueue(q.z);
    _host_f32_enqueue(q.w);
    return 4;
}

pub fn enqueue_mat4(m: zalg.Mat4) u32 {
    enqueue_vec4(m.c0);
    enqueue_vec4(m.c1);
    enqueue_vec4(m.c2);
    enqueue_vec4(m.c3);
    return 16;
}


pub fn dequeue_vec2() zalg.Vec2 {
    return zalg.Vec2.init(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
    );
}

pub fn dequeue_vec3() zalg.Vec3 {
    return zalg.Vec3.init(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
    );
}

pub fn dequeue_vec4() zalg.Vec4 {
    return zalg.Vec4.init(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
    );
}

pub fn dequeue_quat() zalg.Quat {
    return zalg.Quat.init(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
    );
}

pub fn dequeue_mat4() zalg.Mat4 {
    return zalg.Mat4{
        .c0 = dequeue_vec4(),
        .c1 = dequeue_vec4(),
        .c2 = dequeue_vec4(),
        .c3 = dequeue_vec4(),
    };
}

//// Wasm Bindings ////
extern "C" fn _host_strcpy(location: [*]u8, size: u32) void;
extern "C" fn _host_f32_enqueue(f: f32) void;
extern "C" fn _host_f32_dequeue() f32;
extern "C" fn _log__warn(msg: [*:0]const u8) void;
extern "C" fn _log__info(msg: [*:0]const u8) void;
extern "C" fn _log__debug(msg: [*:0]const u8) void;
extern "C" fn _log__critical(msg: [*:0]const u8) void;
extern "C" fn _note_manager__add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: CustomData) void;
extern "C" fn _note_manager__add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: CustomData) void;
extern "C" fn _note_manager__time_to_beat(time: f32) f32;
extern "C" fn _note_manager__add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: CustomData) void;
extern "C" fn _turinger_game_object_manager__create_object(name: [*:0]const u8) TuringerGameObject;
extern "C" fn _turinger_game_object_manager__find(name: [*:0]const u8) TuringerGameObject;
extern "C" fn _turinger_game_object_manager__destroy_object(listener: TuringerGameObject) void;
extern "C" fn _turinger_game_object_manager__instance_get(opaqu: u64) TuringerGameObjectManager;
extern "C" fn _get_components_in_parent_by_type(opaqu: u64, cs_type: Type, include_inactive: bool) Component;
extern "C" fn _turinger_game_object__send_message(opaqu: u64, method_name: [*:0]const u8) void;
extern "C" fn _turinger_game_object__get_component_in_parent_by_type(opaqu: u64, cs_type: Type) Component;
extern "C" fn _turinger_game_object__is_static_get(opaqu: u64) bool;
extern "C" fn _turinger_game_object__transform_get(opaqu: u64) TuringerTransform;
extern "C" fn _turinger_game_object__get_component_in_children_by_type(opaqu: u64, cs_type: Type) Component;
extern "C" fn _turinger_game_object__get_components_by_type(opaqu: u64, cs_type: Type, results: List1) void;
extern "C" fn _turinger_game_object__active_set(opaqu: u64, value: bool) void;
extern "C" fn _turinger_game_object__broadcast_message(opaqu: u64, method_name: [*:0]const u8) void;
extern "C" fn _turinger_game_object__game_object_get(opaqu: u64) GameObject;
extern "C" fn _turinger_game_object__is_static_set(opaqu: u64, value: bool) void;
extern "C" fn _turinger_game_object__add_component(opaqu: u64, component_type: Type) Component;
extern "C" fn _turinger_game_object__hide_flags_set(opaqu: u64, value: i32) void;
extern "C" fn _turinger_game_object__send_message_upwards(opaqu: u64, method_name: [*:0]const u8) void;
extern "C" fn _turinger_game_object__compare_tag(opaqu: u64, tag: [*:0]const u8) bool;
extern "C" fn _turinger_game_object__hide_flags_get(opaqu: u64) i32;
extern "C" fn _turinger_game_object__tag_set(opaqu: u64, value: [*:0]const u8) void;
extern "C" fn _turinger_game_object__get_instance_id(opaqu: u64) i32;
extern "C" fn _turinger_game_object__layer_get(opaqu: u64) i32;
extern "C" fn _get_components_in_children_by_type(opaqu: u64, cs_type: Type, include_inactive: bool) Component;
extern "C" fn _turinger_game_object__layer_set(opaqu: u64, value: i32) void;
extern "C" fn _turinger_game_object__set_active_recursively(opaqu: u64, state: bool) void;
extern "C" fn _turinger_game_object__get_component_index(opaqu: u64, component: Component) i32;
extern "C" fn _turinger_game_object__get_component_count(opaqu: u64) i32;
extern "C" fn _turinger_game_object__get_component_at_index(opaqu: u64, index: i32) Component;
extern "C" fn _turinger_game_object__tag_get(opaqu: u64) u32;
extern "C" fn _turinger_game_object__active_self_get(opaqu: u64) bool;
extern "C" fn _turinger_game_object__name_get(opaqu: u64) u32;
extern "C" fn _turinger_game_object__get_component_by_type(opaqu: u64, cs_type: Type) Component;
extern "C" fn _turinger_game_object__active_in_hierarchy_get(opaqu: u64) bool;
extern "C" fn _turinger_game_object__set_active(opaqu: u64, value: bool) void;
extern "C" fn _turinger_game_object__active_get(opaqu: u64) bool;
extern "C" fn _turinger_game_object__get_component_by_name(opaqu: u64, cs_type: [*:0]const u8) Component;
extern "C" fn _turinger_game_object__name_set(opaqu: u64, value: [*:0]const u8) void;
extern "C" fn _turinger_game_object__scene_culling_mask_get(opaqu: u64) u64;
extern "C" fn _turinger_transform__get_component_by_type(opaqu: u64, cs_type: Type) Component;
extern "C" fn _turinger_transform__look_at(opaqu: u64, world_position: u32) void;
extern "C" fn _turinger_transform__get_instance_id(opaqu: u64) i32;
extern "C" fn _turinger_transform__tag_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__local_euler_angles_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__rotation_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__world_to_local_matrix_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__hierarchy_count_get(opaqu: u64) i32;
extern "C" fn _get_components_in_children_by_type(opaqu: u64, t: Type, include_inactive: bool) Component;
extern "C" fn _turinger_transform__name_set(opaqu: u64, value: [*:0]const u8) void;
extern "C" fn _turinger_transform__local_rotation_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__detach_children(opaqu: u64) void;
extern "C" fn _turinger_transform__inverse_transform_point(opaqu: u64, x: f32, y: f32, z: f32) u32;
extern "C" fn _turinger_transform__get_component_in_children_by_type(opaqu: u64, t: Type, include_inactive: bool) Component;
extern "C" fn _turinger_transform__transform_get(opaqu: u64) Transform;
extern "C" fn _turinger_transform__lossy_scale_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__root_get(opaqu: u64) TuringerTransform;
extern "C" fn _turinger_transform__get_components_by_type(opaqu: u64, cs_type: Type, results: List1) void;
extern "C" fn _turinger_transform__get_enumerator(opaqu: u64) IEnumerator;
extern "C" fn _turinger_transform__local_scale_set(opaqu: u64, value: u32) void;
extern "C" fn _turinger_transform__child_count_get(opaqu: u64) i32;
extern "C" fn _turinger_transform__parent_set(opaqu: u64, value: TuringerTransform) void;
extern "C" fn _turinger_transform__get_child(opaqu: u64, index: i32) TuringerTransform;
extern "C" fn _turinger_transform__transform_direction(opaqu: u64, x: f32, y: f32, z: f32) u32;
extern "C" fn _turinger_transform__has_changed_set(opaqu: u64, value: bool) void;
extern "C" fn _turinger_transform__send_message_upwards(opaqu: u64, method_name: [*:0]const u8, value: Object, options: i32) void;
extern "C" fn _turinger_transform__find_child(opaqu: u64, n: [*:0]const u8) TuringerTransform;
extern "C" fn _get_components_in_parent_by_type(opaqu: u64, t: Type, include_inactive: bool) Component;
extern "C" fn _turinger_transform__rotate(opaqu: u64, axis: u32, angle: f32) void;
extern "C" fn _turinger_transform__has_changed_get(opaqu: u64) bool;
extern "C" fn _turinger_transform__local_position_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__translate_relative(opaqu: u64, translation: u32, relative_to: TuringerTransform) void;
extern "C" fn _turinger_transform__local_euler_angles_set(opaqu: u64, value: u32) void;
extern "C" fn _turinger_transform__set_local_position_and_rotation(opaqu: u64, local_position: u32, local_rotation: u32) void;
extern "C" fn _turinger_transform__forward_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__get_sibling_index(opaqu: u64) i32;
extern "C" fn _turinger_transform__get_component_in_parent_by_type(opaqu: u64, t: Type, include_inactive: bool) Component;
extern "C" fn _turinger_transform__up_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__get_component_index(opaqu: u64) i32;
extern "C" fn _turinger_transform__rotate_around_local(opaqu: u64, axis: u32, angle: f32) void;
extern "C" fn _turinger_transform__translate(opaqu: u64, translation: u32) void;
extern "C" fn _turinger_transform__broadcast_message(opaqu: u64, method_name: [*:0]const u8, parameter: Object, options: i32) void;
extern "C" fn _turinger_transform__euler_angles_set(opaqu: u64, value: u32) void;
extern "C" fn _turinger_transform__send_message(opaqu: u64, method_name: [*:0]const u8, value: Object, options: i32) void;
extern "C" fn _turinger_transform__parent_get(opaqu: u64) TuringerTransform;
extern "C" fn _turinger_transform__local_to_world_matrix_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__get_component_by_name(opaqu: u64, cs_type: [*:0]const u8) Component;
extern "C" fn _turinger_transform__set_parent(opaqu: u64, parent: TuringerTransform, world_position_stays: bool) void;
extern "C" fn _turinger_transform__rotate_around(opaqu: u64, axis: u32, angle: f32) void;
extern "C" fn _turinger_transform__hierarchy_capacity_set(opaqu: u64, value: i32) void;
extern "C" fn _turinger_transform__up_set(opaqu: u64, value: u32) void;
extern "C" fn _turinger_transform__inverse_transform_direction(opaqu: u64, x: f32, y: f32, z: f32) u32;
extern "C" fn _turinger_transform__local_scale_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__transform_vector(opaqu: u64, x: f32, y: f32, z: f32) u32;
extern "C" fn _turinger_transform__transform_point(opaqu: u64, x: f32, y: f32, z: f32) u32;
extern "C" fn _turinger_transform__euler_angles_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__is_child_of(opaqu: u64, parent: TuringerTransform) bool;
extern "C" fn _turinger_transform__right_set(opaqu: u64, value: u32) void;
extern "C" fn _turinger_transform__get_child_count(opaqu: u64) i32;
extern "C" fn _turinger_transform__hide_flags_get(opaqu: u64) i32;
extern "C" fn _turinger_transform__rotate_relative(opaqu: u64, axis: u32, angle: f32, relative_to: i32) void;
extern "C" fn _turinger_transform__rotation_set(opaqu: u64, value: u32) void;
extern "C" fn _turinger_transform__game_object_get(opaqu: u64) TuringerGameObject;
extern "C" fn _turinger_transform__hierarchy_capacity_get(opaqu: u64) i32;
extern "C" fn _turinger_transform__set_as_first_sibling(opaqu: u64) void;
extern "C" fn _turinger_transform__right_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__local_position_set(opaqu: u64, value: u32) void;
extern "C" fn _turinger_transform__forward_set(opaqu: u64, value: u32) void;
extern "C" fn _turinger_transform__name_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__compare_tag(opaqu: u64, tag: [*:0]const u8) bool;
extern "C" fn _turinger_transform__set_as_last_sibling(opaqu: u64) void;
extern "C" fn _turinger_transform__position_get(opaqu: u64) u32;
extern "C" fn _turinger_transform__set_sibling_index(opaqu: u64, index: i32) void;
extern "C" fn _turinger_transform__position_set(opaqu: u64, value: u32) void;
extern "C" fn _turinger_transform__hide_flags_set(opaqu: u64, value: i32) void;
extern "C" fn _turinger_transform__set_position_and_rotation(opaqu: u64, position: u32, rotation: u32) void;
extern "C" fn _turinger_transform__find(opaqu: u64, n: [*:0]const u8) TuringerTransform;
extern "C" fn _turinger_transform__tag_set(opaqu: u64, value: [*:0]const u8) void;
extern "C" fn _turinger_transform__local_rotation_set(opaqu: u64, value: u32) void;
extern "C" fn _turinger_transform__inverse_transform_vector(opaqu: u64, x: f32, y: f32, z: f32) u32;
extern "C" fn _gc_helper__create() GCHelper;
extern "C" fn _gc_helper__wasm_garbage_collect(opaqu: u64) void;
extern "C" fn _gc_helper__dispose(opaqu: u64) void;
extern "C" fn _gc_helper__invalidate_all_handles(opaqu: u64) void;
extern "C" fn _xr__get_device_tracking_state(node_int: i32) i32;
extern "C" fn _xr__get_device_name(node_int: i32) u32;
extern "C" fn _xr__get_device_secondary_button_state(node_int: i32) bool;
extern "C" fn _xr__get_device_primary_button_state(node_int: i32) bool;
extern "C" fn _xr__send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32) void;
extern "C" fn _xr__is_device_valid(node_int: i32) bool;
extern "C" fn _xr__get_device_battery_level(node_int: i32) f32;
extern "C" fn _xr__get_device_touchpad(node_int: i32) u32;
extern "C" fn _xr__get_device_grip_value(node_int: i32) f32;
extern "C" fn _xr__get_device_trigger_value(node_int: i32) f32;
extern "C" fn _xr__stop_haptics(node_int: i32) void;
extern "C" fn _xr__get_device_thumbstick(node_int: i32) u32;
extern "C" fn _xr___manager_get(opaqu: u64) TuringScriptManager;
extern "C" fn _custom_data__create() CustomData;
extern "C" fn _list_create() List;
extern "C" fn _custom_data__set_string(custom_data: CustomData, key: [*:0]const u8, value: [*:0]const u8) void;
extern "C" fn _custom_data__set_custom_data(custom_data: CustomData, key: [*:0]const u8, value: CustomData) void;
extern "C" fn _custom_data__list_add_string(list: List1, value: [*:0]const u8) void;
extern "C" fn _custom_data__set_custom_data_list(custom_data: CustomData, key: [*:0]const u8, value: List1) void;
extern "C" fn _custom_data__set_float(custom_data: CustomData, key: [*:0]const u8, value: f32) void;
extern "C" fn _custom_data__list_add_int(list: List1, value: i32) void;
extern "C" fn _custom_data__list_add_bool(list: List1, value: bool) void;
extern "C" fn _custom_data__set_int(custom_data: CustomData, key: [*:0]const u8, value: i32) void;
extern "C" fn _custom_data__set_bool(custom_data: CustomData, key: [*:0]const u8, value: bool) void;
extern "C" fn _custom_data__list_add_custom_data_list(list: List1, value: List1) void;
extern "C" fn _custom_data__list_add_float(list: List1, value: f32) void;
extern "C" fn _custom_data__list_add_custom_data(list: List1, value: CustomData) void;

export fn _turing_api_semver() u64 {
    return ((0 << 32) | (1 << 16) | 0);
}

pub const TURING_API_VERSION: []const u8 = "0.1.0";

//// Functions ////


//// Classes ////

pub const GameObject = struct {
    opaqu: u64,
};


pub const Transform = struct {
    opaqu: u64,
};


pub const TuringScriptManager = struct {
    opaqu: u64,
};


pub const Object = struct {
    opaqu: u64,
};


pub const List1 = struct {
    opaqu: u64,
};


pub const List = struct {
    opaqu: u64,
};


pub const Component = struct {
    opaqu: u64,
};


pub const Type = struct {
    opaqu: u64,
};


pub const IEnumerator = struct {
    opaqu: u64,
};


pub const Log = struct {

    pub fn warn(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log__warn(turing_handle_msg.ptr);
    }


    pub fn info(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log__info(turing_handle_msg.ptr);
    }


    pub fn debug(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log__debug(turing_handle_msg.ptr);
    }


    pub fn critical(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log__critical(turing_handle_msg.ptr);
    }

};


pub const NoteManager = struct {

    pub fn add_obstacle(beat: f32, duration: f32, line: i32, layer: i32, width: i32, height: i32, custom_data: CustomData) void {
        _note_manager__add_obstacle(beat, duration, line, layer, width, height, custom_data);
    }


    pub fn add_color_note(beat: f32, line: i32, layer: i32, color: i32, cut_direction: i32, custom_data: CustomData) void {
        _note_manager__add_color_note(beat, line, layer, color, cut_direction, custom_data);
    }


    pub fn time_to_beat(time: f32) f32 {
        return _note_manager__time_to_beat(time);
    }


    pub fn add_bomb_note(beat: f32, line: i32, layer: i32, custom_data: CustomData) void {
        _note_manager__add_bomb_note(beat, line, layer, custom_data);
    }

};


pub const TuringerGameObjectManager = struct {
    opaqu: u64,

    pub fn create_object(name: []const u8, allocator: std.mem.Allocator) TuringerGameObject {
        const turing_handle_name = try allocator.dupeZ(u8, name);
        defer allocator.free(turing_handle_name);
        const turing_result = _turinger_game_object_manager__create_object(turing_handle_name.ptr);
        return TuringerGameObject{ .opaqu = turing_result };
    }


    pub fn find(name: []const u8, allocator: std.mem.Allocator) TuringerGameObject {
        const turing_handle_name = try allocator.dupeZ(u8, name);
        defer allocator.free(turing_handle_name);
        const turing_result = _turinger_game_object_manager__find(turing_handle_name.ptr);
        return TuringerGameObject{ .opaqu = turing_result };
    }


    pub fn destroy_object(listener: TuringerGameObject) void {
        _turinger_game_object_manager__destroy_object(listener);
    }


    pub fn instance_get(self: *const TuringerGameObjectManager) TuringerGameObjectManager {
        const turing_result = _turinger_game_object_manager__instance_get(self.opaqu);
        return TuringerGameObjectManager{ .opaqu = turing_result };
    }

};


pub const TuringerGameObject = struct {
    opaqu: u64,

    pub fn get_components_in_parent_by_type(self: *const TuringerGameObject, cs_type: Type, include_inactive: bool) Component {
        const turing_result = _get_components_in_parent_by_type(self.opaqu, cs_type, include_inactive);
        return Component{ .opaqu = turing_result };
    }


    pub fn send_message(self: *const TuringerGameObject, method_name: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _turinger_game_object__send_message(self.opaqu, turing_handle_method_name.ptr);
    }


    pub fn get_component_in_parent_by_type(self: *const TuringerGameObject, cs_type: Type) Component {
        const turing_result = _turinger_game_object__get_component_in_parent_by_type(self.opaqu, cs_type);
        return Component{ .opaqu = turing_result };
    }


    pub fn is_static_get(self: *const TuringerGameObject) bool {
        return _turinger_game_object__is_static_get(self.opaqu);
    }


    pub fn transform_get(self: *const TuringerGameObject) TuringerTransform {
        const turing_result = _turinger_game_object__transform_get(self.opaqu);
        return TuringerTransform{ .opaqu = turing_result };
    }


    pub fn get_component_in_children_by_type(self: *const TuringerGameObject, cs_type: Type) Component {
        const turing_result = _turinger_game_object__get_component_in_children_by_type(self.opaqu, cs_type);
        return Component{ .opaqu = turing_result };
    }


    pub fn get_components_by_type(self: *const TuringerGameObject, cs_type: Type, results: List1) void {
        _turinger_game_object__get_components_by_type(self.opaqu, cs_type, results);
    }


    pub fn active_set(self: *const TuringerGameObject, value: bool) void {
        _turinger_game_object__active_set(self.opaqu, value);
    }


    pub fn broadcast_message(self: *const TuringerGameObject, method_name: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _turinger_game_object__broadcast_message(self.opaqu, turing_handle_method_name.ptr);
    }


    pub fn game_object_get(self: *const TuringerGameObject) GameObject {
        const turing_result = _turinger_game_object__game_object_get(self.opaqu);
        return GameObject{ .opaqu = turing_result };
    }


    pub fn is_static_set(self: *const TuringerGameObject, value: bool) void {
        _turinger_game_object__is_static_set(self.opaqu, value);
    }


    pub fn add_component(self: *const TuringerGameObject, component_type: Type) Component {
        const turing_result = _turinger_game_object__add_component(self.opaqu, component_type);
        return Component{ .opaqu = turing_result };
    }


    pub fn hide_flags_set(self: *const TuringerGameObject, value: i32) void {
        _turinger_game_object__hide_flags_set(self.opaqu, value);
    }


    pub fn send_message_upwards(self: *const TuringerGameObject, method_name: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _turinger_game_object__send_message_upwards(self.opaqu, turing_handle_method_name.ptr);
    }


    pub fn compare_tag(self: *const TuringerGameObject, tag: []const u8, allocator: std.mem.Allocator) bool {
        const turing_handle_tag = try allocator.dupeZ(u8, tag);
        defer allocator.free(turing_handle_tag);
        return _turinger_game_object__compare_tag(self.opaqu, turing_handle_tag.ptr);
    }


    pub fn hide_flags_get(self: *const TuringerGameObject) i32 {
        return _turinger_game_object__hide_flags_get(self.opaqu);
    }


    pub fn tag_set(self: *const TuringerGameObject, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _turinger_game_object__tag_set(self.opaqu, turing_handle_value.ptr);
    }


    pub fn get_instance_id(self: *const TuringerGameObject) i32 {
        return _turinger_game_object__get_instance_id(self.opaqu);
    }


    pub fn layer_get(self: *const TuringerGameObject) i32 {
        return _turinger_game_object__layer_get(self.opaqu);
    }


    pub fn get_components_in_children_by_type(self: *const TuringerGameObject, cs_type: Type, include_inactive: bool) Component {
        const turing_result = _get_components_in_children_by_type(self.opaqu, cs_type, include_inactive);
        return Component{ .opaqu = turing_result };
    }


    pub fn layer_set(self: *const TuringerGameObject, value: i32) void {
        _turinger_game_object__layer_set(self.opaqu, value);
    }


    pub fn set_active_recursively(self: *const TuringerGameObject, state: bool) void {
        _turinger_game_object__set_active_recursively(self.opaqu, state);
    }


    pub fn get_component_index(self: *const TuringerGameObject, component: Component) i32 {
        return _turinger_game_object__get_component_index(self.opaqu, component);
    }


    pub fn get_component_count(self: *const TuringerGameObject) i32 {
        return _turinger_game_object__get_component_count(self.opaqu);
    }


    pub fn get_component_at_index(self: *const TuringerGameObject, index: i32) Component {
        const turing_result = _turinger_game_object__get_component_at_index(self.opaqu, index);
        return Component{ .opaqu = turing_result };
    }


    pub fn tag_get(self: *const TuringerGameObject, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _turinger_game_object__tag_get(self.opaqu);
        const turing_str = try allocator.alloc(u8, turing_result);
        defer allocator.free(turing_str);
        _host_strcpy(turing_str.ptr, turing_result);
        const result = try allocator.dupe(u8, std.mem.span(@as([*:0]const u8, @ptrCast(turing_str.ptr))));
        return result;
    }


    pub fn active_self_get(self: *const TuringerGameObject) bool {
        return _turinger_game_object__active_self_get(self.opaqu);
    }


    pub fn name_get(self: *const TuringerGameObject, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _turinger_game_object__name_get(self.opaqu);
        const turing_str = try allocator.alloc(u8, turing_result);
        defer allocator.free(turing_str);
        _host_strcpy(turing_str.ptr, turing_result);
        const result = try allocator.dupe(u8, std.mem.span(@as([*:0]const u8, @ptrCast(turing_str.ptr))));
        return result;
    }


    pub fn get_component_by_type(self: *const TuringerGameObject, cs_type: Type) Component {
        const turing_result = _turinger_game_object__get_component_by_type(self.opaqu, cs_type);
        return Component{ .opaqu = turing_result };
    }


    pub fn active_in_hierarchy_get(self: *const TuringerGameObject) bool {
        return _turinger_game_object__active_in_hierarchy_get(self.opaqu);
    }


    pub fn set_active(self: *const TuringerGameObject, value: bool) void {
        _turinger_game_object__set_active(self.opaqu, value);
    }


    pub fn active_get(self: *const TuringerGameObject) bool {
        return _turinger_game_object__active_get(self.opaqu);
    }


    pub fn get_component_by_name(self: *const TuringerGameObject, cs_type: []const u8, allocator: std.mem.Allocator) Component {
        const turing_handle_cs_type = try allocator.dupeZ(u8, cs_type);
        defer allocator.free(turing_handle_cs_type);
        const turing_result = _turinger_game_object__get_component_by_name(self.opaqu, turing_handle_cs_type.ptr);
        return Component{ .opaqu = turing_result };
    }


    pub fn name_set(self: *const TuringerGameObject, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _turinger_game_object__name_set(self.opaqu, turing_handle_value.ptr);
    }


    pub fn scene_culling_mask_get(self: *const TuringerGameObject) u64 {
        return _turinger_game_object__scene_culling_mask_get(self.opaqu);
    }

};


pub const TuringerTransform = struct {
    opaqu: u64,

    pub fn get_component_by_type(self: *const TuringerTransform, cs_type: Type) Component {
        const turing_result = _turinger_transform__get_component_by_type(self.opaqu, cs_type);
        return Component{ .opaqu = turing_result };
    }


    pub fn look_at(self: *const TuringerTransform, world_position: zalg.Vec3) void {
        const turing_handle_world_position = enqueue_vec3(world_position);
        _turinger_transform__look_at(self.opaqu, turing_handle_world_position);
    }


    pub fn get_instance_id(self: *const TuringerTransform) i32 {
        return _turinger_transform__get_instance_id(self.opaqu);
    }


    pub fn tag_get(self: *const TuringerTransform, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _turinger_transform__tag_get(self.opaqu);
        const turing_str = try allocator.alloc(u8, turing_result);
        defer allocator.free(turing_str);
        _host_strcpy(turing_str.ptr, turing_result);
        const result = try allocator.dupe(u8, std.mem.span(@as([*:0]const u8, @ptrCast(turing_str.ptr))));
        return result;
    }


    pub fn local_euler_angles_get(self: *const TuringerTransform) zalg.Vec3 {
        _turinger_transform__local_euler_angles_get(self.opaqu);
        return dequeue_vec3();
    }


    pub fn rotation_get(self: *const TuringerTransform) zalg.Quat {
        _turinger_transform__rotation_get(self.opaqu);
        return dequeue_quat();
    }


    pub fn world_to_local_matrix_get(self: *const TuringerTransform) zalg.Mat4 {
        _turinger_transform__world_to_local_matrix_get(self.opaqu);
        return dequeue_mat4();
    }


    pub fn hierarchy_count_get(self: *const TuringerTransform) i32 {
        return _turinger_transform__hierarchy_count_get(self.opaqu);
    }


    pub fn get_components_in_children_by_type(self: *const TuringerTransform, t: Type, include_inactive: bool) Component {
        const turing_result = _get_components_in_children_by_type(self.opaqu, t, include_inactive);
        return Component{ .opaqu = turing_result };
    }


    pub fn name_set(self: *const TuringerTransform, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _turinger_transform__name_set(self.opaqu, turing_handle_value.ptr);
    }


    pub fn local_rotation_get(self: *const TuringerTransform) zalg.Quat {
        _turinger_transform__local_rotation_get(self.opaqu);
        return dequeue_quat();
    }


    pub fn detach_children(self: *const TuringerTransform) void {
        _turinger_transform__detach_children(self.opaqu);
    }


    pub fn inverse_transform_point(self: *const TuringerTransform, x: f32, y: f32, z: f32) zalg.Vec3 {
        _turinger_transform__inverse_transform_point(self.opaqu, x, y, z);
        return dequeue_vec3();
    }


    pub fn get_component_in_children_by_type(self: *const TuringerTransform, t: Type, include_inactive: bool) Component {
        const turing_result = _turinger_transform__get_component_in_children_by_type(self.opaqu, t, include_inactive);
        return Component{ .opaqu = turing_result };
    }


    pub fn transform_get(self: *const TuringerTransform) Transform {
        const turing_result = _turinger_transform__transform_get(self.opaqu);
        return Transform{ .opaqu = turing_result };
    }


    pub fn lossy_scale_get(self: *const TuringerTransform) zalg.Vec3 {
        _turinger_transform__lossy_scale_get(self.opaqu);
        return dequeue_vec3();
    }


    pub fn root_get(self: *const TuringerTransform) TuringerTransform {
        const turing_result = _turinger_transform__root_get(self.opaqu);
        return TuringerTransform{ .opaqu = turing_result };
    }


    pub fn get_components_by_type(self: *const TuringerTransform, cs_type: Type, results: List1) void {
        _turinger_transform__get_components_by_type(self.opaqu, cs_type, results);
    }


    pub fn get_enumerator(self: *const TuringerTransform) IEnumerator {
        const turing_result = _turinger_transform__get_enumerator(self.opaqu);
        return IEnumerator{ .opaqu = turing_result };
    }


    pub fn local_scale_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _turinger_transform__local_scale_set(self.opaqu, turing_handle_value);
    }


    pub fn child_count_get(self: *const TuringerTransform) i32 {
        return _turinger_transform__child_count_get(self.opaqu);
    }


    pub fn parent_set(self: *const TuringerTransform, value: TuringerTransform) void {
        _turinger_transform__parent_set(self.opaqu, value);
    }


    pub fn get_child(self: *const TuringerTransform, index: i32) TuringerTransform {
        const turing_result = _turinger_transform__get_child(self.opaqu, index);
        return TuringerTransform{ .opaqu = turing_result };
    }


    pub fn transform_direction(self: *const TuringerTransform, x: f32, y: f32, z: f32) zalg.Vec3 {
        _turinger_transform__transform_direction(self.opaqu, x, y, z);
        return dequeue_vec3();
    }


    pub fn has_changed_set(self: *const TuringerTransform, value: bool) void {
        _turinger_transform__has_changed_set(self.opaqu, value);
    }


    pub fn send_message_upwards(self: *const TuringerTransform, method_name: []const u8, value: Object, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _turinger_transform__send_message_upwards(self.opaqu, turing_handle_method_name.ptr, value, options);
    }


    pub fn find_child(self: *const TuringerTransform, n: []const u8, allocator: std.mem.Allocator) TuringerTransform {
        const turing_handle_n = try allocator.dupeZ(u8, n);
        defer allocator.free(turing_handle_n);
        const turing_result = _turinger_transform__find_child(self.opaqu, turing_handle_n.ptr);
        return TuringerTransform{ .opaqu = turing_result };
    }


    pub fn get_components_in_parent_by_type(self: *const TuringerTransform, t: Type, include_inactive: bool) Component {
        const turing_result = _get_components_in_parent_by_type(self.opaqu, t, include_inactive);
        return Component{ .opaqu = turing_result };
    }


    pub fn rotate(self: *const TuringerTransform, axis: zalg.Vec3, angle: f32) void {
        const turing_handle_axis = enqueue_vec3(axis);
        _turinger_transform__rotate(self.opaqu, turing_handle_axis, angle);
    }


    pub fn has_changed_get(self: *const TuringerTransform) bool {
        return _turinger_transform__has_changed_get(self.opaqu);
    }


    pub fn local_position_get(self: *const TuringerTransform) zalg.Vec3 {
        _turinger_transform__local_position_get(self.opaqu);
        return dequeue_vec3();
    }


    pub fn translate_relative(self: *const TuringerTransform, translation: zalg.Vec3, relative_to: TuringerTransform) void {
        const turing_handle_translation = enqueue_vec3(translation);
        _turinger_transform__translate_relative(self.opaqu, turing_handle_translation, relative_to);
    }


    pub fn local_euler_angles_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _turinger_transform__local_euler_angles_set(self.opaqu, turing_handle_value);
    }


    pub fn set_local_position_and_rotation(self: *const TuringerTransform, local_position: zalg.Vec3, local_rotation: zalg.Quat) void {
        const turing_handle_local_position = enqueue_vec3(local_position);
        const turing_handle_local_rotation = enqueue_quat(local_rotation);
        _turinger_transform__set_local_position_and_rotation(self.opaqu, turing_handle_local_position, turing_handle_local_rotation);
    }


    pub fn forward_get(self: *const TuringerTransform) zalg.Vec3 {
        _turinger_transform__forward_get(self.opaqu);
        return dequeue_vec3();
    }


    pub fn get_sibling_index(self: *const TuringerTransform) i32 {
        return _turinger_transform__get_sibling_index(self.opaqu);
    }


    pub fn get_component_in_parent_by_type(self: *const TuringerTransform, t: Type, include_inactive: bool) Component {
        const turing_result = _turinger_transform__get_component_in_parent_by_type(self.opaqu, t, include_inactive);
        return Component{ .opaqu = turing_result };
    }


    pub fn up_get(self: *const TuringerTransform) zalg.Vec3 {
        _turinger_transform__up_get(self.opaqu);
        return dequeue_vec3();
    }


    pub fn get_component_index(self: *const TuringerTransform) i32 {
        return _turinger_transform__get_component_index(self.opaqu);
    }


    pub fn rotate_around_local(self: *const TuringerTransform, axis: zalg.Vec3, angle: f32) void {
        const turing_handle_axis = enqueue_vec3(axis);
        _turinger_transform__rotate_around_local(self.opaqu, turing_handle_axis, angle);
    }


    pub fn translate(self: *const TuringerTransform, translation: zalg.Vec3) void {
        const turing_handle_translation = enqueue_vec3(translation);
        _turinger_transform__translate(self.opaqu, turing_handle_translation);
    }


    pub fn broadcast_message(self: *const TuringerTransform, method_name: []const u8, parameter: Object, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _turinger_transform__broadcast_message(self.opaqu, turing_handle_method_name.ptr, parameter, options);
    }


    pub fn euler_angles_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _turinger_transform__euler_angles_set(self.opaqu, turing_handle_value);
    }


    pub fn send_message(self: *const TuringerTransform, method_name: []const u8, value: Object, options: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_method_name = try allocator.dupeZ(u8, method_name);
        defer allocator.free(turing_handle_method_name);
        _turinger_transform__send_message(self.opaqu, turing_handle_method_name.ptr, value, options);
    }


    pub fn parent_get(self: *const TuringerTransform) TuringerTransform {
        const turing_result = _turinger_transform__parent_get(self.opaqu);
        return TuringerTransform{ .opaqu = turing_result };
    }


    pub fn local_to_world_matrix_get(self: *const TuringerTransform) zalg.Mat4 {
        _turinger_transform__local_to_world_matrix_get(self.opaqu);
        return dequeue_mat4();
    }


    pub fn get_component_by_name(self: *const TuringerTransform, cs_type: []const u8, allocator: std.mem.Allocator) Component {
        const turing_handle_cs_type = try allocator.dupeZ(u8, cs_type);
        defer allocator.free(turing_handle_cs_type);
        const turing_result = _turinger_transform__get_component_by_name(self.opaqu, turing_handle_cs_type.ptr);
        return Component{ .opaqu = turing_result };
    }


    pub fn set_parent(self: *const TuringerTransform, parent: TuringerTransform, world_position_stays: bool) void {
        _turinger_transform__set_parent(self.opaqu, parent, world_position_stays);
    }


    pub fn rotate_around(self: *const TuringerTransform, axis: zalg.Vec3, angle: f32) void {
        const turing_handle_axis = enqueue_vec3(axis);
        _turinger_transform__rotate_around(self.opaqu, turing_handle_axis, angle);
    }


    pub fn hierarchy_capacity_set(self: *const TuringerTransform, value: i32) void {
        _turinger_transform__hierarchy_capacity_set(self.opaqu, value);
    }


    pub fn up_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _turinger_transform__up_set(self.opaqu, turing_handle_value);
    }


    pub fn inverse_transform_direction(self: *const TuringerTransform, x: f32, y: f32, z: f32) zalg.Vec3 {
        _turinger_transform__inverse_transform_direction(self.opaqu, x, y, z);
        return dequeue_vec3();
    }


    pub fn local_scale_get(self: *const TuringerTransform) zalg.Vec3 {
        _turinger_transform__local_scale_get(self.opaqu);
        return dequeue_vec3();
    }


    pub fn transform_vector(self: *const TuringerTransform, x: f32, y: f32, z: f32) zalg.Vec3 {
        _turinger_transform__transform_vector(self.opaqu, x, y, z);
        return dequeue_vec3();
    }


    pub fn transform_point(self: *const TuringerTransform, x: f32, y: f32, z: f32) zalg.Vec3 {
        _turinger_transform__transform_point(self.opaqu, x, y, z);
        return dequeue_vec3();
    }


    pub fn euler_angles_get(self: *const TuringerTransform) zalg.Vec3 {
        _turinger_transform__euler_angles_get(self.opaqu);
        return dequeue_vec3();
    }


    pub fn is_child_of(self: *const TuringerTransform, parent: TuringerTransform) bool {
        return _turinger_transform__is_child_of(self.opaqu, parent);
    }


    pub fn right_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _turinger_transform__right_set(self.opaqu, turing_handle_value);
    }


    pub fn get_child_count(self: *const TuringerTransform) i32 {
        return _turinger_transform__get_child_count(self.opaqu);
    }


    pub fn hide_flags_get(self: *const TuringerTransform) i32 {
        return _turinger_transform__hide_flags_get(self.opaqu);
    }


    pub fn rotate_relative(self: *const TuringerTransform, axis: zalg.Vec3, angle: f32, relative_to: i32) void {
        const turing_handle_axis = enqueue_vec3(axis);
        _turinger_transform__rotate_relative(self.opaqu, turing_handle_axis, angle, relative_to);
    }


    pub fn rotation_set(self: *const TuringerTransform, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _turinger_transform__rotation_set(self.opaqu, turing_handle_value);
    }


    pub fn game_object_get(self: *const TuringerTransform) TuringerGameObject {
        const turing_result = _turinger_transform__game_object_get(self.opaqu);
        return TuringerGameObject{ .opaqu = turing_result };
    }


    pub fn hierarchy_capacity_get(self: *const TuringerTransform) i32 {
        return _turinger_transform__hierarchy_capacity_get(self.opaqu);
    }


    pub fn set_as_first_sibling(self: *const TuringerTransform) void {
        _turinger_transform__set_as_first_sibling(self.opaqu);
    }


    pub fn right_get(self: *const TuringerTransform) zalg.Vec3 {
        _turinger_transform__right_get(self.opaqu);
        return dequeue_vec3();
    }


    pub fn local_position_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _turinger_transform__local_position_set(self.opaqu, turing_handle_value);
    }


    pub fn forward_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _turinger_transform__forward_set(self.opaqu, turing_handle_value);
    }


    pub fn name_get(self: *const TuringerTransform, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _turinger_transform__name_get(self.opaqu);
        const turing_str = try allocator.alloc(u8, turing_result);
        defer allocator.free(turing_str);
        _host_strcpy(turing_str.ptr, turing_result);
        const result = try allocator.dupe(u8, std.mem.span(@as([*:0]const u8, @ptrCast(turing_str.ptr))));
        return result;
    }


    pub fn compare_tag(self: *const TuringerTransform, tag: []const u8, allocator: std.mem.Allocator) bool {
        const turing_handle_tag = try allocator.dupeZ(u8, tag);
        defer allocator.free(turing_handle_tag);
        return _turinger_transform__compare_tag(self.opaqu, turing_handle_tag.ptr);
    }


    pub fn set_as_last_sibling(self: *const TuringerTransform) void {
        _turinger_transform__set_as_last_sibling(self.opaqu);
    }


    pub fn position_get(self: *const TuringerTransform) zalg.Vec3 {
        _turinger_transform__position_get(self.opaqu);
        return dequeue_vec3();
    }


    pub fn set_sibling_index(self: *const TuringerTransform, index: i32) void {
        _turinger_transform__set_sibling_index(self.opaqu, index);
    }


    pub fn position_set(self: *const TuringerTransform, value: zalg.Vec3) void {
        const turing_handle_value = enqueue_vec3(value);
        _turinger_transform__position_set(self.opaqu, turing_handle_value);
    }


    pub fn hide_flags_set(self: *const TuringerTransform, value: i32) void {
        _turinger_transform__hide_flags_set(self.opaqu, value);
    }


    pub fn set_position_and_rotation(self: *const TuringerTransform, position: zalg.Vec3, rotation: zalg.Quat) void {
        const turing_handle_position = enqueue_vec3(position);
        const turing_handle_rotation = enqueue_quat(rotation);
        _turinger_transform__set_position_and_rotation(self.opaqu, turing_handle_position, turing_handle_rotation);
    }


    pub fn find(self: *const TuringerTransform, n: []const u8, allocator: std.mem.Allocator) TuringerTransform {
        const turing_handle_n = try allocator.dupeZ(u8, n);
        defer allocator.free(turing_handle_n);
        const turing_result = _turinger_transform__find(self.opaqu, turing_handle_n.ptr);
        return TuringerTransform{ .opaqu = turing_result };
    }


    pub fn tag_set(self: *const TuringerTransform, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _turinger_transform__tag_set(self.opaqu, turing_handle_value.ptr);
    }


    pub fn local_rotation_set(self: *const TuringerTransform, value: zalg.Quat) void {
        const turing_handle_value = enqueue_quat(value);
        _turinger_transform__local_rotation_set(self.opaqu, turing_handle_value);
    }


    pub fn inverse_transform_vector(self: *const TuringerTransform, x: f32, y: f32, z: f32) zalg.Vec3 {
        _turinger_transform__inverse_transform_vector(self.opaqu, x, y, z);
        return dequeue_vec3();
    }

};


pub const GcHelper = struct {
    opaqu: u64,

    pub fn create() GCHelper {
        const turing_result = _gc_helper__create();
        return GcHelper{ .opaqu = turing_result };
    }


    pub fn wasm_garbage_collect(self: *const GcHelper) void {
        _gc_helper__wasm_garbage_collect(self.opaqu);
    }


    pub fn dispose(self: *const GcHelper) void {
        _gc_helper__dispose(self.opaqu);
    }


    pub fn invalidate_all_handles(self: *const GcHelper) void {
        _gc_helper__invalidate_all_handles(self.opaqu);
    }

};


pub const Xr = struct {
    opaqu: u64,

    pub fn get_device_tracking_state(node_int: i32) i32 {
        return _xr__get_device_tracking_state(node_int);
    }


    pub fn get_device_name(node_int: i32, allocator: std.mem.Allocator) ![]u8 {
        const turing_result = _xr__get_device_name(node_int);
        const turing_str = try allocator.alloc(u8, turing_result);
        defer allocator.free(turing_str);
        _host_strcpy(turing_str.ptr, turing_result);
        const result = try allocator.dupe(u8, std.mem.span(@as([*:0]const u8, @ptrCast(turing_str.ptr))));
        return result;
    }


    pub fn get_device_secondary_button_state(node_int: i32) bool {
        return _xr__get_device_secondary_button_state(node_int);
    }


    pub fn get_device_primary_button_state(node_int: i32) bool {
        return _xr__get_device_primary_button_state(node_int);
    }


    pub fn send_haptic_impulse(node_int: i32, amplitude: f32, duration: f32) void {
        _xr__send_haptic_impulse(node_int, amplitude, duration);
    }


    pub fn is_device_valid(node_int: i32) bool {
        return _xr__is_device_valid(node_int);
    }


    pub fn get_device_battery_level(node_int: i32) f32 {
        return _xr__get_device_battery_level(node_int);
    }


    pub fn get_device_touchpad(node_int: i32) zalg.Vec2 {
        _xr__get_device_touchpad(node_int);
        return dequeue_vec2();
    }


    pub fn get_device_grip_value(node_int: i32) f32 {
        return _xr__get_device_grip_value(node_int);
    }


    pub fn get_device_trigger_value(node_int: i32) f32 {
        return _xr__get_device_trigger_value(node_int);
    }


    pub fn stop_haptics(node_int: i32) void {
        _xr__stop_haptics(node_int);
    }


    pub fn get_device_thumbstick(node_int: i32) zalg.Vec2 {
        _xr__get_device_thumbstick(node_int);
        return dequeue_vec2();
    }


    pub fn _manager_get(self: *const Xr) TuringScriptManager {
        const turing_result = _xr___manager_get(self.opaqu);
        return TuringScriptManager{ .opaqu = turing_result };
    }

};


pub const CustomData = struct {
    opaqu: u64,

    pub fn create() CustomData {
        const turing_result = _custom_data__create();
        return CustomData{ .opaqu = turing_result };
    }


    pub fn list_create() List {
        const turing_result = _list_create();
        return List{ .opaqu = turing_result };
    }


    pub fn set_string(custom_data: CustomData, key: []const u8, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _custom_data__set_string(custom_data, turing_handle_key.ptr, turing_handle_value.ptr);
    }


    pub fn set_custom_data(custom_data: CustomData, key: []const u8, value: CustomData, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        _custom_data__set_custom_data(custom_data, turing_handle_key.ptr, value);
    }


    pub fn list_add_string(list: List1, value: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_value = try allocator.dupeZ(u8, value);
        defer allocator.free(turing_handle_value);
        _custom_data__list_add_string(list, turing_handle_value.ptr);
    }


    pub fn set_custom_data_list(custom_data: CustomData, key: []const u8, value: List1, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        _custom_data__set_custom_data_list(custom_data, turing_handle_key.ptr, value);
    }


    pub fn set_float(custom_data: CustomData, key: []const u8, value: f32, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        _custom_data__set_float(custom_data, turing_handle_key.ptr, value);
    }


    pub fn list_add_int(list: List1, value: i32) void {
        _custom_data__list_add_int(list, value);
    }


    pub fn list_add_bool(list: List1, value: bool) void {
        _custom_data__list_add_bool(list, value);
    }


    pub fn set_int(custom_data: CustomData, key: []const u8, value: i32, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        _custom_data__set_int(custom_data, turing_handle_key.ptr, value);
    }


    pub fn set_bool(custom_data: CustomData, key: []const u8, value: bool, allocator: std.mem.Allocator) !void {
        const turing_handle_key = try allocator.dupeZ(u8, key);
        defer allocator.free(turing_handle_key);
        _custom_data__set_bool(custom_data, turing_handle_key.ptr, value);
    }


    pub fn list_add_custom_data_list(list: List1, value: List1) void {
        _custom_data__list_add_custom_data_list(list, value);
    }


    pub fn list_add_float(list: List1, value: f32) void {
        _custom_data__list_add_float(list, value);
    }


    pub fn list_add_custom_data(list: List1, value: CustomData) void {
        _custom_data__list_add_custom_data(list, value);
    }

};

