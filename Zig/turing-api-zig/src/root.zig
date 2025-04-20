// Turing API - Zig
// License: GPL-2.0-only
// Authors: Westbot
// <auto-converted from the rust api />

const std = @import("std");
extern "env" fn _create_color_note(beat: f32) i32;
extern "env" fn _beatmap_add_color_note(color_note: i32) void;
extern "env" fn _beatmap_remove_color_note(color_note: i32) void;
extern "env" fn _beatmap_get_color_note_at_beat(beat: f32) i32;
extern "env" fn _color_note_set_position(color_note: i32, pos: i32) void;
extern "env" fn _color_note_get_position(color_note: i32) i32;
extern "env" fn _color_note_set_orientation(color_note: i32, orientation: i32) void;
extern "env" fn _color_note_get_orientation(color_note: i32) i32;
extern "env" fn _color_note_set_color(color_note: i32, color: i32) void;
extern "env" fn _color_note_get_color(color_note: i32) i32;
extern "env" fn _create_bomb_note(beat: f32) i32;
extern "env" fn _beatmap_add_bomb_note(bomb_note: i32) void;
extern "env" fn _beatmap_remove_bomb_note(bomb_note: i32) void;
extern "env" fn _beatmap_get_bomb_note_at_beat(beat: f32) i32;
extern "env" fn _bomb_note_set_position(bomb_note: i32, pos: i32) void;
extern "env" fn _bomb_note_get_position(bomb_note: i32) i32;
extern "env" fn _bomb_note_set_orientation(bomb_note: i32, orientation: i32) void;
extern "env" fn _bomb_note_get_orientation(bomb_note: i32) i32;
extern "env" fn _bomb_note_set_color(bomb_note: i32, color: i32) void;
extern "env" fn _bomb_note_get_color(bomb_note: i32) i32;
extern "env" fn _create_arc(beat: f32) i32;
extern "env" fn _beatmap_add_arc(arc: i32) void;
extern "env" fn _beatmap_remove_arc(arc: i32) void;
extern "env" fn _beatmap_get_arc_at_beat(beat: f32) i32;
extern "env" fn _arc_set_position(arc: i32, pos: i32) void;
extern "env" fn _arc_get_position(arc: i32) i32;
extern "env" fn _arc_set_orientation(arc: i32, orientation: i32) void;
extern "env" fn _arc_get_orientation(arc: i32) i32;
extern "env" fn _arc_set_color(arc: i32, color: i32) void;
extern "env" fn _arc_get_color(arc: i32) i32;
extern "env" fn _create_wall(beat: f32) i32;
extern "env" fn _beatmap_add_wall(wall: i32) void;
extern "env" fn _beatmap_remove_wall(wall: i32) void;
extern "env" fn _beatmap_get_wall_at_beat(beat: f32) i32;
extern "env" fn _wall_set_position(wall: i32, pos: i32) void;
extern "env" fn _wall_get_position(wall: i32) i32;
extern "env" fn _wall_set_orientation(wall: i32, orientation: i32) void;
extern "env" fn _wall_get_orientation(wall: i32) i32;
extern "env" fn _wall_set_color(wall: i32, color: i32) void;
extern "env" fn _wall_get_color(wall: i32) i32;
extern "env" fn _create_chain_head_note(beat: f32) i32;
extern "env" fn _beatmap_add_chain_head_note(chain_head_note: i32) void;
extern "env" fn _beatmap_remove_chain_head_note(chain_head_note: i32) void;
extern "env" fn _beatmap_get_chain_head_note_at_beat(beat: f32) i32;
extern "env" fn _chain_head_note_set_position(chain_head_note: i32, pos: i32) void;
extern "env" fn _chain_head_note_get_position(chain_head_note: i32) i32;
extern "env" fn _chain_head_note_set_orientation(chain_head_note: i32, orientation: i32) void;
extern "env" fn _chain_head_note_get_orientation(chain_head_note: i32) i32;
extern "env" fn _chain_head_note_set_color(chain_head_note: i32, color: i32) void;
extern "env" fn _chain_head_note_get_color(chain_head_note: i32) i32;
extern "env" fn _create_chain_link_note(beat: f32) i32;
extern "env" fn _beatmap_add_chain_link_note(chain_link_note: i32) void;
extern "env" fn _beatmap_remove_chain_link_note(chain_link_note: i32) void;
extern "env" fn _beatmap_get_chain_link_note_at_beat(beat: f32) i32;
extern "env" fn _chain_link_note_set_position(chain_link_note: i32, pos: i32) void;
extern "env" fn _chain_link_note_get_position(chain_link_note: i32) i32;
extern "env" fn _chain_link_note_set_orientation(chain_link_note: i32, orientation: i32) void;
extern "env" fn _chain_link_note_get_orientation(chain_link_note: i32) i32;
extern "env" fn _chain_link_note_set_color(chain_link_note: i32, color: i32) void;
extern "env" fn _chain_link_note_get_color(chain_link_note: i32) i32;
extern "env" fn _create_chain_note(beat: f32) i32;
extern "env" fn _beatmap_add_chain_note(chain_note: i32) void;
extern "env" fn _beatmap_remove_chain_note(chain_note: i32) void;
extern "env" fn _beatmap_get_chain_note_at_beat(beat: f32) i32;
extern "env" fn _chain_note_set_position(chain_note: i32, pos: i32) void;
extern "env" fn _chain_note_get_position(chain_note: i32) i32;
extern "env" fn _chain_note_set_orientation(chain_note: i32, orientation: i32) void;
extern "env" fn _chain_note_get_orientation(chain_note: i32) i32;
extern "env" fn _chain_note_set_color(chain_note: i32, color: i32) void;
extern "env" fn _chain_note_get_color(chain_note: i32) i32;
extern "env" fn _saber_set_color(saber: i32, color: i32) void;
extern "env" fn _saber_get_color(saber: i32) i32;
extern "env" fn _get_left_saber() i32;
extern "env" fn _get_right_saber() i32;
extern "env" fn _log(message: i32) void;
extern "env" fn _drop_reference(ptr: i32) void;
extern "env" fn _vec2_from_xy(x: f32, y: f32) i32;
extern "env" fn _vec3_from_xyz(x: f32, y: f32, z: f32) i32;
extern "env" fn _vec4_from_xyzw(x: f32, y: f32, z: f32, w: f32) i32;
extern "env" fn _quat_from_xyzw(x: f32, y: f32, z: f32, w: f32) i32;
extern "env" fn _color_set_rgb(color: i32, r: f32, g: f32, b: f32) void;
extern "env" fn _color_set_rgba(color: i32, r: f32, g: f32, b: f32, a: f32) void;
extern "env" fn _data_contains_persistent_i32(key: i32) bool;
extern "env" fn _data_contains_persistent_f32(key: i32) bool;
extern "env" fn _data_contains_persistent_str(key: i32) bool;
extern "env" fn _data_store_persistent_i32(key: i32, value: i32) void;
extern "env" fn _data_store_persistent_f32(key: i32, value: f32) void;
extern "env" fn _data_store_persistent_str(key: i32, value: i32) void;
extern "env" fn _data_access_persistent_i32(key: i32) i32;
extern "env" fn _data_access_persistent_f32(key: i32) f32;
extern "env" fn _data_access_persistent_str(key: i32) i32;
extern "env" fn _data_remove_persistent_i32(key: i32) void;
extern "env" fn _data_remove_persistent_f32(key: i32) void;
extern "env" fn _data_remove_persistent_str(key: i32) void;
extern "env" fn _vec2_get_x(vec2: i32) f32;
extern "env" fn _vec2_set_x(vec2: i32, x: f32) void;
extern "env" fn _vec2_get_y(vec2: i32) f32;
extern "env" fn _vec2_set_y(vec2: i32, y: f32) void;
extern "env" fn _vec3_get_x(vec3: i32) f32;
extern "env" fn _vec3_set_x(vec3: i32, x: f32) void;
extern "env" fn _vec3_get_y(vec3: i32) f32;
extern "env" fn _vec3_set_y(vec3: i32, y: f32) void;
extern "env" fn _vec3_get_z(vec3: i32) f32;
extern "env" fn _vec3_set_z(vec3: i32, z: f32) void;
extern "env" fn _vec4_get_x(vec4: i32) f32;
extern "env" fn _vec4_set_x(vec4: i32, x: f32) void;
extern "env" fn _vec4_get_y(vec4: i32) f32;
extern "env" fn _vec4_set_y(vec4: i32, y: f32) void;
extern "env" fn _vec4_get_z(vec4: i32) f32;
extern "env" fn _vec4_set_z(vec4: i32, z: f32) void;
extern "env" fn _vec4_get_w(vec4: i32) f32;
extern "env" fn _vec4_set_w(vec4: i32, w: f32) void;
extern "env" fn _quat_get_x(quat: i32) f32;
extern "env" fn _quat_set_x(quat: i32, x: f32) void;
extern "env" fn _quat_get_y(quat: i32) f32;
extern "env" fn _quat_set_y(quat: i32, y: f32) void;
extern "env" fn _quat_get_z(quat: i32) f32;
extern "env" fn _quat_set_z(quat: i32, z: f32) void;
extern "env" fn _quat_get_w(quat: i32) f32;
extern "env" fn _quat_set_w(quat: i32, w: f32) void;
extern "env" fn _color_get_r(color: i32) f32;
extern "env" fn _color_set_r(color: i32, r: f32) void;
extern "env" fn _color_get_g(color: i32) f32;
extern "env" fn _color_set_g(color: i32, g: f32) void;
extern "env" fn _color_get_b(color: i32) f32;
extern "env" fn _color_set_b(color: i32, b: f32) void;
extern "env" fn _color_get_a(color: i32) f32;
extern "env" fn _color_set_a(color: i32, a: f32) void;
pub fn concat_strings(allocator: std.mem.Allocator, str1: []const u8, str2: []const u8) ![]u8 {
    const new_len = str1.len + str2.len;
    const result = try allocator.alloc(u8, new_len);
    std.mem.copy(u8, result[0..str1.len], str1);
    std.mem.copy(u8, result[str1.len..], str2);
    return result;
}

pub const Color = struct {
    ptr: i32,
    pub fn get_r(self: Color) f32 {
        return _color_get_r(self.ptr);
    }

    pub fn set_r(self: Color, r: f32) void {
        _color_set_r(self.ptr, r);
    }

    pub fn get_g(self: Color) f32 {
        return _color_get_g(self.ptr);
    }

    pub fn set_g(self: Color, g: f32) void {
        _color_set_g(self.ptr, g);
    }

    pub fn get_b(self: Color) f32 {
        return _color_get_b(self.ptr);
    }

    pub fn set_b(self: Color, b: f32) void {
        _color_set_b(self.ptr, b);
    }

    pub fn get_a(self: Color) f32 {
        return _color_get_a(self.ptr);
    }

    pub fn set_a(self: Color, a: f32) void {
        _color_set_a(self.ptr, a);
    }

    pub fn set_rgb(self: Color, r: f32, g: f32, b: f32) void {
        _color_set_rgb(self.ptr, r, g, b);
    }

    pub fn set_rgba(self: Color, r: f32, g: f32, b: f32, a: f32) void {
        _color_set_rgba(self.ptr, r, g, b, a);
    }
};

pub const Log = struct {
    
    pub fn info(msg: [*:0]const u8) void {
        var gpa = std.heap.GeneralPurposeAllocator(.{}){};
            const allocator = gpa.allocator();
            const s = try concat_strings(allocator, "info: ", msg);
            defer allocator.free(s);
            _log(@ptrCast(msg.ptr));
    }

    pub fn warn(msg: [*:0]const u8) void {
        var gpa = std.heap.GeneralPurposeAllocator(.{}){};
            const allocator = gpa.allocator();
            const s = try concat_strings(allocator, "warn: ", msg);
            defer allocator.free(s);
            _log(@ptrCast(msg.ptr));
    }

    pub fn critical(msg: [*:0]const u8) void {
        var gpa = std.heap.GeneralPurposeAllocator(.{}){};
            const allocator = gpa.allocator();
            const s = try concat_strings(allocator, "error: ", msg);
            defer allocator.free(s);
            _log(@ptrCast(msg.ptr));
    }

    pub fn debug(msg: [*:0]const u8) void {
        var gpa = std.heap.GeneralPurposeAllocator(.{}){};
            const allocator = gpa.allocator();
            const s = try concat_strings(allocator, "debug: ", msg);
            defer allocator.free(s);
            _log(@ptrCast(msg.ptr));
    }
};

pub const Vec2 = struct {
    ptr: i32,
    pub fn from_xy(x: f32, y: f32) Vec2 {
        return .{ .ptr = _vec2_from_xy(x, y) };
    }

    pub fn get_x(self: Vec2) f32 {
        return _vec2_get_x(self.ptr);
    }

    pub fn get_y(self: Vec2) f32 {
        return _vec2_get_y(self.ptr);
    }
};

pub const Vec3 = struct {
    ptr: i32,
    pub fn from_xyz(x: f32, y: f32, z: f32) Vec3 {
        return .{ .ptr = _vec3_from_xyz(x, y, z) };
    }

    pub fn get_x(self: Vec3) f32 {
        return _vec3_get_x(self.ptr);
    }

    pub fn get_y(self: Vec3) f32 {
        return _vec3_get_y(self.ptr);
    }

    pub fn get_z(self: Vec3) f32 {
        return _vec3_get_z(self.ptr);
    }
};

pub const Vec4 = struct {
    ptr: i32,
    pub fn from_xyzw(x: f32, y: f32, z: f32, w: f32) Vec4 {
        return .{ .ptr = _vec4_from_xyzw(x, y, z, w) };
    }

    pub fn get_x(self: Vec4) f32 {
        return _vec4_get_x(self.ptr);
    }

    pub fn get_y(self: Vec4) f32 {
        return _vec4_get_y(self.ptr);
    }

    pub fn get_z(self: Vec4) f32 {
        return _vec4_get_z(self.ptr);
    }

    pub fn get_w(self: Vec4) f32 {
        return _vec4_get_w(self.ptr);
    }
};

pub const Quat = struct {
    ptr: i32,
    pub fn from_xyzw(x: f32, y: f32, z: f32, w: f32) Quat {
        return .{ .ptr = _quat_from_xyzw(x, y, z, w) };
    }

    pub fn get_x(self: Quat) f32 {
        return _quat_get_x(self.ptr);
    }

    pub fn get_y(self: Quat) f32 {
        return _quat_get_y(self.ptr);
    }

    pub fn get_z(self: Quat) f32 {
        return _quat_get_z(self.ptr);
    }

    pub fn get_w(self: Quat) f32 {
        return _quat_get_w(self.ptr);
    }
};

pub const ColorNote = struct {
    ptr: i32,
    pub fn get_color(self: ColorNote) Color {
        return .{ .ptr = _color_note_get_color(self.ptr) };
    }
    pub fn set_color(self: ColorNote, color: Color) void {
        _color_note_set_color(self.ptr, color.ptr);
    }
    pub fn get_position(self: ColorNote) Vec3 {
        return .{ .ptr = _color_note_get_position(self.ptr) };
    }
    pub fn set_position(self: ColorNote, position: Vec3) void {
        _color_note_set_position(self.ptr, position.ptr);
    }
    pub fn get_orientation(self: ColorNote) Quat {
        return .{ .ptr = _color_note_get_orientation(self.ptr) };
    }
    pub fn set_orientation(self: ColorNote, orientation: Quat) void {
        _color_note_set_orientation(self.ptr, orientation.ptr);
    }
};
pub const BombNote = struct {
    ptr: i32,
    pub fn get_color(self: BombNote) Color {
        return .{ .ptr = _bomb_note_get_color(self.ptr) };
    }
    pub fn set_color(self: BombNote, color: Color) void {
        _bomb_note_set_color(self.ptr, color.ptr);
    }
    pub fn get_position(self: BombNote) Vec3 {
        return .{ .ptr = _bomb_note_get_position(self.ptr) };
    }
    pub fn set_position(self: BombNote, position: Vec3) void {
        _bomb_note_set_position(self.ptr, position.ptr);
    }
    pub fn get_orientation(self: BombNote) Quat {
        return .{ .ptr = _bomb_note_get_orientation(self.ptr) };
    }
    pub fn set_orientation(self: BombNote, orientation: Quat) void {
        _bomb_note_set_orientation(self.ptr, orientation.ptr);
    }
};
pub const Arc = struct {
    ptr: i32,
    pub fn get_color(self: Arc) Color {
        return .{ .ptr = _arc_get_color(self.ptr) };
    }
    pub fn set_color(self: Arc, color: Color) void {
        _arc_set_color(self.ptr, color.ptr);
    }
    pub fn get_position(self: Arc) Vec3 {
        return .{ .ptr = _arc_get_position(self.ptr) };
    }
    pub fn set_position(self: Arc, position: Vec3) void {
        _arc_set_position(self.ptr, position.ptr);
    }
    pub fn get_orientation(self: Arc) Quat {
        return .{ .ptr = _arc_get_orientation(self.ptr) };
    }
    pub fn set_orientation(self: Arc, orientation: Quat) void {
        _arc_set_orientation(self.ptr, orientation.ptr);
    }
};
pub const Wall = struct {
    ptr: i32,
    pub fn get_color(self: Wall) Color {
        return .{ .ptr = _wall_get_color(self.ptr) };
    }
    pub fn set_color(self: Wall, color: Color) void {
        _wall_set_color(self.ptr, color.ptr);
    }
    pub fn get_position(self: Wall) Vec3 {
        return .{ .ptr = _wall_get_position(self.ptr) };
    }
    pub fn set_position(self: Wall, position: Vec3) void {
        _wall_set_position(self.ptr, position.ptr);
    }
    pub fn get_orientation(self: Wall) Quat {
        return .{ .ptr = _wall_get_orientation(self.ptr) };
    }
    pub fn set_orientation(self: Wall, orientation: Quat) void {
        _wall_set_orientation(self.ptr, orientation.ptr);
    }
};
pub const ChainHeadNote = struct {
    ptr: i32,
    pub fn get_color(self: ChainHeadNote) Color {
        return .{ .ptr = _chain_head_note_get_color(self.ptr) };
    }
    pub fn set_color(self: ChainHeadNote, color: Color) void {
        _chain_head_note_set_color(self.ptr, color.ptr);
    }
    pub fn get_position(self: ChainHeadNote) Vec3 {
        return .{ .ptr = _chain_head_note_get_position(self.ptr) };
    }
    pub fn set_position(self: ChainHeadNote, position: Vec3) void {
        _chain_head_note_set_position(self.ptr, position.ptr);
    }
    pub fn get_orientation(self: ChainHeadNote) Quat {
        return .{ .ptr = _chain_head_note_get_orientation(self.ptr) };
    }
    pub fn set_orientation(self: ChainHeadNote, orientation: Quat) void {
        _chain_head_note_set_orientation(self.ptr, orientation.ptr);
    }
};
pub const ChainLinkNote = struct {
    ptr: i32,
    pub fn get_color(self: ChainLinkNote) Color {
        return .{ .ptr = _chain_link_note_get_color(self.ptr) };
    }
    pub fn set_color(self: ChainLinkNote, color: Color) void {
        _chain_link_note_set_color(self.ptr, color.ptr);
    }
    pub fn get_position(self: ChainLinkNote) Vec3 {
        return .{ .ptr = _chain_link_note_get_position(self.ptr) };
    }
    pub fn set_position(self: ChainLinkNote, position: Vec3) void {
        _chain_link_note_set_position(self.ptr, position.ptr);
    }
    pub fn get_orientation(self: ChainLinkNote) Quat {
        return .{ .ptr = _chain_link_note_get_orientation(self.ptr) };
    }
    pub fn set_orientation(self: ChainLinkNote, orientation: Quat) void {
        _chain_link_note_set_orientation(self.ptr, orientation.ptr);
    }
};
pub const ChainNote = struct {
    ptr: i32,
    pub fn get_color(self: ChainNote) Color {
        return .{ .ptr = _chain_note_get_color(self.ptr) };
    }
    pub fn set_color(self: ChainNote, color: Color) void {
        _chain_note_set_color(self.ptr, color.ptr);
    }
    pub fn get_position(self: ChainNote) Vec3 {
        return .{ .ptr = _chain_note_get_position(self.ptr) };
    }
    pub fn set_position(self: ChainNote, position: Vec3) void {
        _chain_note_set_position(self.ptr, position.ptr);
    }
    pub fn get_orientation(self: ChainNote) Quat {
        return .{ .ptr = _chain_note_get_orientation(self.ptr) };
    }
    pub fn set_orientation(self: ChainNote, orientation: Quat) void {
        _chain_note_set_orientation(self.ptr, orientation.ptr);
    }
};

pub fn create_color_note(beat: f32) ColorNote {
    return .{ .ptr = _create_color_note(beat) };
}

pub fn create_bomb_note(beat: f32) BombNote {
    return .{ .ptr = _create_bomb_note(beat) };
}

pub fn create_arc(beat: f32) Arc {
    return .{ .ptr = _create_arc(beat) };
}

pub fn create_wall(beat: f32) Wall {
    return .{ .ptr = _create_wall(beat) };
}

pub fn create_chain_head_note(beat: f32) ChainHeadNote {
    return .{ .ptr = _create_chain_head_note(beat) };
}

pub fn create_chain_link_note(beat: f32) ChainLinkNote {
    return .{ .ptr = _create_chain_link_note(beat) };
}

pub fn create_chain_note(beat: f32) ChainNote {
    return .{ .ptr = _create_chain_note(beat) };
}

pub const Beatmap = struct {
    
    pub fn add_color_note(color_note: ColorNote) void {
        _beatmap_add_color_note(color_note.ptr);
    }
    pub fn remove_color_note(color_note: ColorNote) void {
        _beatmap_remove_color_note(color_note.ptr);
    }
    pub fn get_color_note_at_beat(beat: f32) ColorNote {
        _beatmap_get_color_note_at_beat(beat);
    }
    pub fn add_bomb_note(bomb_note: BombNote) void {
        _beatmap_add_bomb_note(bomb_note.ptr);
    }
    pub fn remove_bomb_note(bomb_note: BombNote) void {
        _beatmap_remove_bomb_note(bomb_note.ptr);
    }
    pub fn get_bomb_note_at_beat(beat: f32) BombNote {
        _beatmap_get_bomb_note_at_beat(beat);
    }
    pub fn add_arc(arc: Arc) void {
        _beatmap_add_arc(arc.ptr);
    }
    pub fn remove_arc(arc: Arc) void {
        _beatmap_remove_arc(arc.ptr);
    }
    pub fn get_arc_at_beat(beat: f32) Arc {
        _beatmap_get_arc_at_beat(beat);
    }
    pub fn add_wall(wall: Wall) void {
        _beatmap_add_wall(wall.ptr);
    }
    pub fn remove_wall(wall: Wall) void {
        _beatmap_remove_wall(wall.ptr);
    }
    pub fn get_wall_at_beat(beat: f32) Wall {
        _beatmap_get_wall_at_beat(beat);
    }
    pub fn add_chain_head_note(chain_head_note: ChainHeadNote) void {
        _beatmap_add_chain_head_note(chain_head_note.ptr);
    }
    pub fn remove_chain_head_note(chain_head_note: ChainHeadNote) void {
        _beatmap_remove_chain_head_note(chain_head_note.ptr);
    }
    pub fn get_chain_head_note_at_beat(beat: f32) ChainHeadNote {
        _beatmap_get_chain_head_note_at_beat(beat);
    }
    pub fn add_chain_link_note(chain_link_note: ChainLinkNote) void {
        _beatmap_add_chain_link_note(chain_link_note.ptr);
    }
    pub fn remove_chain_link_note(chain_link_note: ChainLinkNote) void {
        _beatmap_remove_chain_link_note(chain_link_note.ptr);
    }
    pub fn get_chain_link_note_at_beat(beat: f32) ChainLinkNote {
        _beatmap_get_chain_link_note_at_beat(beat);
    }
    pub fn add_chain_note(chain_note: ChainNote) void {
        _beatmap_add_chain_note(chain_note.ptr);
    }
    pub fn remove_chain_note(chain_note: ChainNote) void {
        _beatmap_remove_chain_note(chain_note.ptr);
    }
    pub fn get_chain_note_at_beat(beat: f32) ChainNote {
        _beatmap_get_chain_note_at_beat(beat);
    }
};

