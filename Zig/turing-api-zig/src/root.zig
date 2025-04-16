// Turing API - Zig
// License: GPL-2.0-only
// Authors: Westbot
// <auto-converted from the rust api />

const std = @import("std");
extern "env" fn _create_color_note(beat: f32) i32;
extern "env" fn _beatmap_add_color_note(color_note: i32) void;
extern "env" fn _beatmap_remove_color_note(color_note: i32) void;
extern "env" fn _color_note_set_position(color_note: i32, pos: i32) void;
extern "env" fn _color_note_get_position(color_note: i32) i32;
extern "env" fn _color_note_set_orientation(color_note: i32, orientation: i32) void;
extern "env" fn _color_note_get_orientation(color_note: i32) i32;
extern "env" fn _color_note_set_color(color_note: i32, color: i32) void;
extern "env" fn _color_note_get_color(color_note: i32) i32;
extern "env" fn _create_bomb_note(beat: f32) i32;
extern "env" fn _beatmap_add_bomb_note(bomb_note: i32) void;
extern "env" fn _beatmap_remove_bomb_note(bomb_note: i32) void;
extern "env" fn _bomb_note_set_position(bomb_note: i32, pos: i32) void;
extern "env" fn _bomb_note_get_position(bomb_note: i32) i32;
extern "env" fn _bomb_note_set_orientation(bomb_note: i32, orientation: i32) void;
extern "env" fn _bomb_note_get_orientation(bomb_note: i32) i32;
extern "env" fn _bomb_note_set_color(bomb_note: i32, color: i32) void;
extern "env" fn _bomb_note_get_color(bomb_note: i32) i32;
extern "env" fn _create_arc(beat: f32) i32;
extern "env" fn _beatmap_add_arc(arc: i32) void;
extern "env" fn _beatmap_remove_arc(arc: i32) void;
extern "env" fn _arc_set_position(arc: i32, pos: i32) void;
extern "env" fn _arc_get_position(arc: i32) i32;
extern "env" fn _arc_set_orientation(arc: i32, orientation: i32) void;
extern "env" fn _arc_get_orientation(arc: i32) i32;
extern "env" fn _arc_set_color(arc: i32, color: i32) void;
extern "env" fn _arc_get_color(arc: i32) i32;
extern "env" fn _create_wall(beat: f32) i32;
extern "env" fn _beatmap_add_wall(wall: i32) void;
extern "env" fn _beatmap_remove_wall(wall: i32) void;
extern "env" fn _wall_set_position(wall: i32, pos: i32) void;
extern "env" fn _wall_get_position(wall: i32) i32;
extern "env" fn _wall_set_orientation(wall: i32, orientation: i32) void;
extern "env" fn _wall_get_orientation(wall: i32) i32;
extern "env" fn _wall_set_color(wall: i32, color: i32) void;
extern "env" fn _wall_get_color(wall: i32) i32;
extern "env" fn _create_chain_head_note(beat: f32) i32;
extern "env" fn _beatmap_add_chain_head_note(chain_head_note: i32) void;
extern "env" fn _beatmap_remove_chain_head_note(chain_head_note: i32) void;
extern "env" fn _chain_head_note_set_position(chain_head_note: i32, pos: i32) void;
extern "env" fn _chain_head_note_get_position(chain_head_note: i32) i32;
extern "env" fn _chain_head_note_set_orientation(chain_head_note: i32, orientation: i32) void;
extern "env" fn _chain_head_note_get_orientation(chain_head_note: i32) i32;
extern "env" fn _chain_head_note_set_color(chain_head_note: i32, color: i32) void;
extern "env" fn _chain_head_note_get_color(chain_head_note: i32) i32;
extern "env" fn _create_chain_link_note(beat: f32) i32;
extern "env" fn _beatmap_add_chain_link_note(chain_link_note: i32) void;
extern "env" fn _beatmap_remove_chain_link_note(chain_link_note: i32) void;
extern "env" fn _chain_link_note_set_position(chain_link_note: i32, pos: i32) void;
extern "env" fn _chain_link_note_get_position(chain_link_note: i32) i32;
extern "env" fn _chain_link_note_set_orientation(chain_link_note: i32, orientation: i32) void;
extern "env" fn _chain_link_note_get_orientation(chain_link_note: i32) i32;
extern "env" fn _chain_link_note_set_color(chain_link_note: i32, color: i32) void;
extern "env" fn _chain_link_note_get_color(chain_link_note: i32) i32;
extern "env" fn _create_chain_note(beat: f32) i32;
extern "env" fn _beatmap_add_chain_note(chain_note: i32) void;
extern "env" fn _beatmap_remove_chain_note(chain_note: i32) void;
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
extern "env" fn _vec2_from_native(x: f32, y: f32) i32;
extern "env" fn _vec3_from_native(x: f32, y: f32, z: f32) i32;
extern "env" fn _vec4_from_native(x: f32, y: f32, z: f32, w: f32) i32;
extern "env" fn _quat_from_native(x: f32, y: f32, z: f32, w: f32) i32;
extern "env" fn _color_set_rgb(color: i32, r: f32, g: f32, b: f32) void;
extern "env" fn _color_set_rgba(color: i32, r: f32, g: f32, b: f32, a: f32) void;
extern "env" fn _vec2_get_attr_x(vec2: i32) f32;
extern "env" fn _vec2_set_attr_x(vec2: i32, x: f32) void;
extern "env" fn _vec2_get_attr_y(vec2: i32) f32;
extern "env" fn _vec2_set_attr_y(vec2: i32, y: f32) void;
extern "env" fn _vec3_get_attr_x(vec3: i32) f32;
extern "env" fn _vec3_set_attr_x(vec3: i32, x: f32) void;
extern "env" fn _vec3_get_attr_y(vec3: i32) f32;
extern "env" fn _vec3_set_attr_y(vec3: i32, y: f32) void;
extern "env" fn _vec3_get_attr_z(vec3: i32) f32;
extern "env" fn _vec3_set_attr_z(vec3: i32, z: f32) void;
extern "env" fn _vec4_get_attr_x(vec4: i32) f32;
extern "env" fn _vec4_set_attr_x(vec4: i32, x: f32) void;
extern "env" fn _vec4_get_attr_y(vec4: i32) f32;
extern "env" fn _vec4_set_attr_y(vec4: i32, y: f32) void;
extern "env" fn _vec4_get_attr_z(vec4: i32) f32;
extern "env" fn _vec4_set_attr_z(vec4: i32, z: f32) void;
extern "env" fn _vec4_get_attr_w(vec4: i32) f32;
extern "env" fn _vec4_set_attr_w(vec4: i32, w: f32) void;
extern "env" fn _quat_get_attr_x(quat: i32) f32;
extern "env" fn _quat_set_attr_x(quat: i32, x: f32) void;
extern "env" fn _quat_get_attr_y(quat: i32) f32;
extern "env" fn _quat_set_attr_y(quat: i32, y: f32) void;
extern "env" fn _quat_get_attr_z(quat: i32) f32;
extern "env" fn _quat_set_attr_z(quat: i32, z: f32) void;
extern "env" fn _quat_get_attr_w(quat: i32) f32;
extern "env" fn _quat_set_attr_w(quat: i32, w: f32) void;
extern "env" fn _color_get_attr_r(color: i32) f32;
extern "env" fn _color_set_attr_r(color: i32, r: f32) void;
extern "env" fn _color_get_attr_g(color: i32) f32;
extern "env" fn _color_set_attr_g(color: i32, g: f32) void;
extern "env" fn _color_get_attr_b(color: i32) f32;
extern "env" fn _color_set_attr_b(color: i32, b: f32) void;
extern "env" fn _color_get_attr_a(color: i32) f32;
extern "env" fn _color_set_attr_a(color: i32, a: f32) void;pub fn concat_strings(allocator: std.mem.Allocator, str1: []const u8, str2: []const u8) ![]u8 {
    const new_len = str1.len + str2.len;
    const result = try allocator.alloc(u8, new_len);
    std.mem.copy(u8, result[0..str1.len], str1);
    std.mem.copy(u8, result[str1.len..], str2);
    return result;
}
pub const ColorNote = struct { ptr: i32 };
pub const BombNote = struct { ptr: i32 };
pub const Arc = struct { ptr: i32 };
pub const Wall = struct { ptr: i32 };
pub const ChainHeadNote = struct { ptr: i32 };
pub const ChainLinkNote = struct { ptr: i32 };
pub const ChainNote = struct { ptr: i32 };

pub const Color = struct { ptr: i32 };

pub const Log = struct {  };
pub fn info(msg: [*:0]const u8) void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
        const allocator = gpa.allocator();
        const s = try concat_strings(allocator, "info", msg);
        defer allocator.free(s);
        _log(@ptrCast(msg.ptr));
}

pub fn warn(msg: [*:0]const u8) void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
        const allocator = gpa.allocator();
        const s = try concat_strings(allocator, "warn", msg);
        defer allocator.free(s);
        _log(@ptrCast(msg.ptr));
}

pub fn critical(msg: [*:0]const u8) void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
        const allocator = gpa.allocator();
        const s = try concat_strings(allocator, "error", msg);
        defer allocator.free(s);
        _log(@ptrCast(msg.ptr));
}

pub fn debug(msg: [*:0]const u8) void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
        const allocator = gpa.allocator();
        const s = try concat_strings(allocator, "debug", msg);
        defer allocator.free(s);
        _log(@ptrCast(msg.ptr));
}

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

pub const Beatmap = struct {  };
pub fn add_chain_note(chain_note: ChainNote) void {
    _beatmap_add_chain_note(chain_note.ptr);
}
pub fn remove_chain_note(chain_note: ChainNote) void {
    _beatmap_remove_chain_note(chain_note.ptr);
}
pub fn add_chain_link_note(chain_link_note: ChainLinkNote) void {
    _beatmap_add_chain_link_note(chain_link_note.ptr);
}
pub fn remove_chain_link_note(chain_link_note: ChainLinkNote) void {
    _beatmap_remove_chain_link_note(chain_link_note.ptr);
}
pub fn add_chain_head_note(chain_head_note: ChainHeadNote) void {
    _beatmap_add_chain_head_note(chain_head_note.ptr);
}
pub fn remove_chain_head_note(chain_head_note: ChainHeadNote) void {
    _beatmap_remove_chain_head_note(chain_head_note.ptr);
}
pub fn add_wall(wall: Wall) void {
    _beatmap_add_wall(wall.ptr);
}
pub fn remove_wall(wall: Wall) void {
    _beatmap_remove_wall(wall.ptr);
}
pub fn add_arc(arc: Arc) void {
    _beatmap_add_arc(arc.ptr);
}
pub fn remove_arc(arc: Arc) void {
    _beatmap_remove_arc(arc.ptr);
}
pub fn add_bomb_note(bomb_note: BombNote) void {
    _beatmap_add_bomb_note(bomb_note.ptr);
}
pub fn remove_bomb_note(bomb_note: BombNote) void {
    _beatmap_remove_bomb_note(bomb_note.ptr);
}
pub fn add_color_note(color_note: ColorNote) void {
    _beatmap_add_color_note(color_note.ptr);
}
pub fn remove_color_note(color_note: ColorNote) void {
    _beatmap_remove_color_note(color_note.ptr);
}

