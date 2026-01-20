///// Generated Zig API /////
const std = @import("std");
const zalg = @import("zalgebra");

pub fn enqueue_vec2(v: zalg.Vec2) void {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
}

pub fn enqueue_vec3(v: zalg.Vec3) void {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
}

pub fn enqueue_vec4(v: zalg.Vec4) void {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    _host_f32_enqueue(v.w);
}

pub fn enqueue_quat(q: zalg.Quat) void {
    _host_f32_enqueue(q.x);
    _host_f32_enqueue(q.y);
    _host_f32_enqueue(q.z);
    _host_f32_enqueue(q.w);
}

pub fn enqueue_mat4(m: zalg.Mat4) void {
    enqueue_vec4(m.c0);
    enqueue_vec4(m.c1);
    enqueue_vec4(m.c2);
    enqueue_vec4(m.c3);
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
extern "C" fn _test_global(name: [*:0]const u8) void;
extern "C" fn _global_2_test() i32;
extern "C" fn _my_test(a: i8, b: i16) u32;
extern "C" fn _my_class_object_func(opaqu: u64, a: i16) void;
extern "C" fn _color_note_set_position(opaqu: u64, v: u32) void;
extern "C" fn _color_note_set_orientation(opaqu: u64, q: u32) void;
extern "C" fn _color_note_set(opaqu: u64, m: u32) void;
extern "C" fn _color_note_get_position(opaqu: u64) u32;
extern "C" fn _color_note_get_orientation(opaqu: u64) u32;
extern "C" fn _color_note_get_transform(opaqu: u64) u32;
extern "C" fn _color_note_clone(opaqu: u64) ColorNote;
extern "C" fn _log_info(msg: [*:0]const u8) void;
extern "C" fn _log_warn(msg: [*:0]const u8) void;
extern "C" fn _log_critical(msg: [*:0]const u8) void;
extern "C" fn _log_debug(msg: [*:0]const u8) void;

export fn _turing_api_semver() u64 {
    return ((0 << 16) | (8 << 8) | 0);
}

pub const TURING_API_VERSION: []const u8 = "0.8.0";

//// Functions ////


pub fn test_global(name: []const u8, allocator: std.mem.Allocator) !void {
    const turing_handle_name = try allocator.dupeZ(u8, name);
    defer allocator.free(turing_handle_name);
    _test_global(turing_handle_name.ptr);
}


pub fn global_2_test() i32 {
    return _global_2_test();
}


pub fn my_test(a: i8, b: i16, allocator: std.mem.Allocator) ![]u8 {
    const turing_result = _my_test(a, b);
    const turing_str = try allocator.alloc(u8, turing_result);
    defer allocator.free(turing_str);
    _host_strcpy(turing_str.ptr, turing_result);
    const result = try allocator.dupe(u8, std.mem.span(@as([*:0]const u8, @ptrCast(turing_str.ptr))));
    return result;
}


//// Classes ////

pub const MyClass = struct {
    opaqu: u64,

    pub fn object_func(self: *const MyClass, a: i16) void {
        _my_class_object_func(self.opaqu, a);
    }

};

/// this is line 1
/// this is line 2
pub const ColorNote = struct {
    opaqu: u64,

    pub fn set_position(self: *const ColorNote, v: u32) *ColorNote {
        const turing_handle_v = enqueue_vec3(v);
        _color_note_set_position(self.opaqu, turing_handle_v);
        return self;
    }


    pub fn set_orientation(self: *const ColorNote, q: u32) *ColorNote {
        const turing_handle_q = enqueue_quat(q);
        _color_note_set_orientation(self.opaqu, turing_handle_q);
        return self;
    }


    pub fn set_transform(self: *const ColorNote, m: u32) *ColorNote {
        const turing_handle_m = enqueue_mat4(m);
        _color_note_set(self.opaqu, turing_handle_m);
        return self;
    }


    pub fn get_position(self: *const ColorNote) u32 {
        _color_note_get_position(self.opaqu);
        return dequeue_vec3();
    }


    pub fn get_orientation(self: *const ColorNote) u32 {
        _color_note_get_orientation(self.opaqu);
        return dequeue_quat();
    }


    pub fn get_transform(self: *const ColorNote) u32 {
        _color_note_get_transform(self.opaqu);
        return dequeue_mat4();
    }


    pub fn clone(self: *const ColorNote) ColorNote {
        const turing_result = _color_note_clone(self.opaqu);
        return ColorNote{ .opaqu = turing_result };
    }

};

/// used to log messages to the console
/// idk, this is a second line
pub const Log = struct {
    /// logs `msg` to the console
    pub fn info(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log_info(turing_handle_msg.ptr);
    }

    /// logs `msg` to the console as a warning
    pub fn warn(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log_warn(turing_handle_msg.ptr);
    }

    /// logs `msg` to the console as an error
    pub fn critical(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log_critical(turing_handle_msg.ptr);
    }

    /// logs `msg` to the console when in debug mode
    pub fn debug(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log_debug(turing_handle_msg.ptr);
    }

};

