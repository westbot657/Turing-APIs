///// Generated Zig API /////
const std = @import("std");

//// Wasm Bindings ////
extern "C" fn _host_strcpy(location: [*]u8, size: u32) void;
extern "C" fn _test_global(name: [*:0]const u8) void;
extern "C" fn _global_2_test() i32;
extern "C" fn _my_test(a: i8, b: i16) u32;
extern "C" fn _my_class_object_func(opaqu: u64, a: i16) void;
extern "C" fn _color_note_set_position(opaqu: u64, x: f32, y: f32, z: f32) void;
extern "C" fn _color_note_set_orientation(opaqu: u64, x: f32, y: f32, z: f32, w: f32) void;
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


pub const ColorNote = struct {
    opaqu: u64,

    pub fn set_position(self: *const ColorNote, x: f32, y: f32, z: f32) *ColorNote {
        _color_note_set_position(self.opaqu, x, y, z);
return self;
    }


    pub fn set_orientation(self: *const ColorNote, x: f32, y: f32, z: f32, w: f32) *ColorNote {
        _color_note_set_orientation(self.opaqu, x, y, z, w);
return self;
    }


    pub fn clone(self: *const ColorNote) ColorNote {
        const turing_result = _color_note_clone(self.opaqu);
        return ColorNote{ .opaqu = turing_result };
    }

};

/// used to log messages to the console
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
