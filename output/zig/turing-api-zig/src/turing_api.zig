///// Generated Zig API /////
const std = @import("std");

//// Wasm Bindings ////
extern "C" fn _host_strcpy(location: [*]u8, size: u32) void;
extern "C" fn _test_global(name: [*:0]const u8) void;
extern "C" fn _global_2_test() i32;
extern "C" fn _my_test(a: i8, b: i16) u32;
extern "C" fn _my_class_object_func(opaqu: u64, a: i16) void;
extern "C" fn _log_info(msg: [*:0]const u8) void;
extern "C" fn _log_warn(msg: [*:0]const u8) void;
extern "C" fn _log_critical(msg: [*:0]const u8) void;
extern "C" fn _log_debug(msg: [*:0]const u8) void;

export fn _turing_api_semver() u64 {
    return ((0 << 16) | (0 << 8) | 1);
}

pub const API_VERSION: []const u8 = "0.0.1";

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
