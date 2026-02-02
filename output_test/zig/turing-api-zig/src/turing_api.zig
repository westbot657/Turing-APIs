
///// Generated Zig API /////
const std = @import("std");
const zalg = @import("zalgebra");



//// Core Systems ////
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
extern "C" fn _host_bufcpy(location: [*]u32, size: u32) void;
extern "C" fn _host_f32_enqueue(f: f32) void;
extern "C" fn _host_f32_dequeue() f32;
extern "C" fn _host_u32_enqueue(u: u32) void;
extern "C" fn _host_u32_dequeue() u32;



export fn _turing_api_semver() u64 {
    return (1 << 32) | (0 << 16) | 0;
}
pub const TURING_API_VERSION: []const u8 = "1.0.0";
extern "C" fn _do_thing(random: Random) Something;
extern "C" fn _log__debug(msg: [*c]const u8) void;
extern "C" fn _log__critical(msg: [*c]const u8) void;
extern "C" fn _log__warn(msg: [*c]const u8) void;
extern "C" fn _log__info(msg: [*c]const u8) void;
extern "C" fn _vivify__upload_buffer(buf: *const anyopaque) void;
extern "C" fn _vivify__get_buffer() u32;

//// Functions ////


pub fn do_thing(random: Random) Something {
    return _do_thing(random);
}


//// Classes ////
/// Used to log messages to the console
pub const Log = struct {
    
    /// Only logs in debug mode
    pub fn debug(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log__debug(turing_handle_msg.ptr);
    }
    /// Highlights red
    pub fn critical(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log__critical(turing_handle_msg.ptr);
    }
    /// Highlights yellow
    pub fn warn(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log__warn(turing_handle_msg.ptr);
    }
    /// Highlights blue
    pub fn info(msg: []const u8, allocator: std.mem.Allocator) !void {
        const turing_handle_msg = try allocator.dupeZ(u8, msg);
        defer allocator.free(turing_handle_msg);
        _log__info(turing_handle_msg.ptr);
    }
};
/// Vivify compatibility systems
pub const Vivify = struct {
    
    /// Uploads a data buffer to beat saber
    pub fn upload_buffer(buf: []const u32) void {
        _host_u32_enqueue(@intCast(buf.len));
        _vivify__upload_buffer(buf.ptr);
    }
    /// Fetches a data buffer from beat saber
    pub fn get_buffer(allocator: std.mem.Allocator) ![]u32 {
        const turing_result = _vivify__get_buffer();
        const turing_buf = try allocator.alloc(u32, turing_result);
        _host_bufcpy(turing_buf.ptr, turing_result);
        return turing_buf;
    }
};

pub const Random = struct {
    opaqu: u64,
};

pub const Something = struct {
    opaqu: u64,
};















