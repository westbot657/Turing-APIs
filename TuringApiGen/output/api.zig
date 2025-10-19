
///// Generated Zig API /////
const std = @import("std");
const types = @import("types.zig");

var gpa = std.heap.GeneralPurposeAllocator(.{}){};
const allocator = gpa.allocator();

extern "C" fn _host_strcpy(location: [*]u8, size: u32) void;

//// Wasm Bindings ////
extern "C" fn _test_global(name: [*:0]const u8) void;
extern "C" fn _global_2_test() i32;
extern "C" fn _my_test(a: i8, b: i16) u32;



extern "C" fn _my_class_object_func(opaqu: *const anyopaque, a: i16) void;
extern "C" fn _log_info(msg: [*:0]const u8) void;
extern "C" fn _log_warn(msg: [*:0]const u8) void;
extern "C" fn _log_critical(msg: [*:0]const u8) void;
extern "C" fn _log_debug(msg: [*:0]const u8) void;


//// Functions ////

pub fn testGlobal(name: []const u8) !void {
    const name_cstr = try allocator.dupeZ(u8, name);
    defer allocator.free(name_cstr);
    _test_global(name_cstr);
    return;
}
pub fn global2Test() !i32 {
    const _res = _global_2_test();
    return _res;
}
pub fn myTest(a: i8, b: i16) ![]u8 {
    const _res = _my_test(a, b);
    const str = try allocator.alloc(u8, _res);
    _host_strcpy(str.ptr, _res);
    return str;
}

//// Classes ////

pub const MyClass = struct {
    opaqu: *const anyopaque,

    pub fn objectFunc(self: MyClass, a: i16) !void {
        _my_class_object_func(self.opaqu,a);
        return;
    }
};

pub const Log = struct {
    
    // No fields
    

    pub fn info(msg: []const u8) !void {
        const msg_cstr = try allocator.dupeZ(u8, msg);
        defer allocator.free(msg_cstr);
        _log_info(msg_cstr);
        return;
    }
    pub fn warn(msg: []const u8) !void {
        const msg_cstr = try allocator.dupeZ(u8, msg);
        defer allocator.free(msg_cstr);
        _log_warn(msg_cstr);
        return;
    }
    pub fn critical(msg: []const u8) !void {
        const msg_cstr = try allocator.dupeZ(u8, msg);
        defer allocator.free(msg_cstr);
        _log_critical(msg_cstr);
        return;
    }
    pub fn debug(msg: []const u8) !void {
        const msg_cstr = try allocator.dupeZ(u8, msg);
        defer allocator.free(msg_cstr);
        _log_debug(msg_cstr);
        return;
    }
};



