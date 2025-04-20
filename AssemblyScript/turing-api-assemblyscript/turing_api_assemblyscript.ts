// Turing API - AsmScript
// License: GPL-2.0-only
// Authors: Westbot
// <auto-converted from the rust api />

@external("env", "_create_color_note")
export declare function _create_color_note(beat: f32): i32;
@external("env", "_beatmap_add_color_note")
export declare function _beatmap_add_color_note(color_note: i32): void;
@external("env", "_beatmap_remove_color_note")
export declare function _beatmap_remove_color_note(color_note: i32): void;
@external("env", "_beatmap_get_color_note_at_beat")
export declare function _beatmap_get_color_note_at_beat(beat: f32): i32;
@external("env", "_color_note_set_position")
export declare function _color_note_set_position(color_note: i32, pos: i32): void;
@external("env", "_color_note_get_position")
export declare function _color_note_get_position(color_note: i32): i32;
@external("env", "_color_note_set_orientation")
export declare function _color_note_set_orientation(color_note: i32, orientation: i32): void;
@external("env", "_color_note_get_orientation")
export declare function _color_note_get_orientation(color_note: i32): i32;
@external("env", "_color_note_set_color")
export declare function _color_note_set_color(color_note: i32, color: i32): void;
@external("env", "_color_note_get_color")
export declare function _color_note_get_color(color_note: i32): i32;
@external("env", "_create_bomb_note")
export declare function _create_bomb_note(beat: f32): i32;
@external("env", "_beatmap_add_bomb_note")
export declare function _beatmap_add_bomb_note(bomb_note: i32): void;
@external("env", "_beatmap_remove_bomb_note")
export declare function _beatmap_remove_bomb_note(bomb_note: i32): void;
@external("env", "_beatmap_get_bomb_note_at_beat")
export declare function _beatmap_get_bomb_note_at_beat(beat: f32): i32;
@external("env", "_bomb_note_set_position")
export declare function _bomb_note_set_position(bomb_note: i32, pos: i32): void;
@external("env", "_bomb_note_get_position")
export declare function _bomb_note_get_position(bomb_note: i32): i32;
@external("env", "_bomb_note_set_orientation")
export declare function _bomb_note_set_orientation(bomb_note: i32, orientation: i32): void;
@external("env", "_bomb_note_get_orientation")
export declare function _bomb_note_get_orientation(bomb_note: i32): i32;
@external("env", "_bomb_note_set_color")
export declare function _bomb_note_set_color(bomb_note: i32, color: i32): void;
@external("env", "_bomb_note_get_color")
export declare function _bomb_note_get_color(bomb_note: i32): i32;
@external("env", "_create_arc")
export declare function _create_arc(beat: f32): i32;
@external("env", "_beatmap_add_arc")
export declare function _beatmap_add_arc(arc: i32): void;
@external("env", "_beatmap_remove_arc")
export declare function _beatmap_remove_arc(arc: i32): void;
@external("env", "_beatmap_get_arc_at_beat")
export declare function _beatmap_get_arc_at_beat(beat: f32): i32;
@external("env", "_arc_set_position")
export declare function _arc_set_position(arc: i32, pos: i32): void;
@external("env", "_arc_get_position")
export declare function _arc_get_position(arc: i32): i32;
@external("env", "_arc_set_orientation")
export declare function _arc_set_orientation(arc: i32, orientation: i32): void;
@external("env", "_arc_get_orientation")
export declare function _arc_get_orientation(arc: i32): i32;
@external("env", "_arc_set_color")
export declare function _arc_set_color(arc: i32, color: i32): void;
@external("env", "_arc_get_color")
export declare function _arc_get_color(arc: i32): i32;
@external("env", "_create_wall")
export declare function _create_wall(beat: f32): i32;
@external("env", "_beatmap_add_wall")
export declare function _beatmap_add_wall(wall: i32): void;
@external("env", "_beatmap_remove_wall")
export declare function _beatmap_remove_wall(wall: i32): void;
@external("env", "_beatmap_get_wall_at_beat")
export declare function _beatmap_get_wall_at_beat(beat: f32): i32;
@external("env", "_wall_set_position")
export declare function _wall_set_position(wall: i32, pos: i32): void;
@external("env", "_wall_get_position")
export declare function _wall_get_position(wall: i32): i32;
@external("env", "_wall_set_orientation")
export declare function _wall_set_orientation(wall: i32, orientation: i32): void;
@external("env", "_wall_get_orientation")
export declare function _wall_get_orientation(wall: i32): i32;
@external("env", "_wall_set_color")
export declare function _wall_set_color(wall: i32, color: i32): void;
@external("env", "_wall_get_color")
export declare function _wall_get_color(wall: i32): i32;
@external("env", "_create_chain_head_note")
export declare function _create_chain_head_note(beat: f32): i32;
@external("env", "_beatmap_add_chain_head_note")
export declare function _beatmap_add_chain_head_note(chain_head_note: i32): void;
@external("env", "_beatmap_remove_chain_head_note")
export declare function _beatmap_remove_chain_head_note(chain_head_note: i32): void;
@external("env", "_beatmap_get_chain_head_note_at_beat")
export declare function _beatmap_get_chain_head_note_at_beat(beat: f32): i32;
@external("env", "_chain_head_note_set_position")
export declare function _chain_head_note_set_position(chain_head_note: i32, pos: i32): void;
@external("env", "_chain_head_note_get_position")
export declare function _chain_head_note_get_position(chain_head_note: i32): i32;
@external("env", "_chain_head_note_set_orientation")
export declare function _chain_head_note_set_orientation(chain_head_note: i32, orientation: i32): void;
@external("env", "_chain_head_note_get_orientation")
export declare function _chain_head_note_get_orientation(chain_head_note: i32): i32;
@external("env", "_chain_head_note_set_color")
export declare function _chain_head_note_set_color(chain_head_note: i32, color: i32): void;
@external("env", "_chain_head_note_get_color")
export declare function _chain_head_note_get_color(chain_head_note: i32): i32;
@external("env", "_create_chain_link_note")
export declare function _create_chain_link_note(beat: f32): i32;
@external("env", "_beatmap_add_chain_link_note")
export declare function _beatmap_add_chain_link_note(chain_link_note: i32): void;
@external("env", "_beatmap_remove_chain_link_note")
export declare function _beatmap_remove_chain_link_note(chain_link_note: i32): void;
@external("env", "_beatmap_get_chain_link_note_at_beat")
export declare function _beatmap_get_chain_link_note_at_beat(beat: f32): i32;
@external("env", "_chain_link_note_set_position")
export declare function _chain_link_note_set_position(chain_link_note: i32, pos: i32): void;
@external("env", "_chain_link_note_get_position")
export declare function _chain_link_note_get_position(chain_link_note: i32): i32;
@external("env", "_chain_link_note_set_orientation")
export declare function _chain_link_note_set_orientation(chain_link_note: i32, orientation: i32): void;
@external("env", "_chain_link_note_get_orientation")
export declare function _chain_link_note_get_orientation(chain_link_note: i32): i32;
@external("env", "_chain_link_note_set_color")
export declare function _chain_link_note_set_color(chain_link_note: i32, color: i32): void;
@external("env", "_chain_link_note_get_color")
export declare function _chain_link_note_get_color(chain_link_note: i32): i32;
@external("env", "_create_chain_note")
export declare function _create_chain_note(beat: f32): i32;
@external("env", "_beatmap_add_chain_note")
export declare function _beatmap_add_chain_note(chain_note: i32): void;
@external("env", "_beatmap_remove_chain_note")
export declare function _beatmap_remove_chain_note(chain_note: i32): void;
@external("env", "_beatmap_get_chain_note_at_beat")
export declare function _beatmap_get_chain_note_at_beat(beat: f32): i32;
@external("env", "_chain_note_set_position")
export declare function _chain_note_set_position(chain_note: i32, pos: i32): void;
@external("env", "_chain_note_get_position")
export declare function _chain_note_get_position(chain_note: i32): i32;
@external("env", "_chain_note_set_orientation")
export declare function _chain_note_set_orientation(chain_note: i32, orientation: i32): void;
@external("env", "_chain_note_get_orientation")
export declare function _chain_note_get_orientation(chain_note: i32): i32;
@external("env", "_chain_note_set_color")
export declare function _chain_note_set_color(chain_note: i32, color: i32): void;
@external("env", "_chain_note_get_color")
export declare function _chain_note_get_color(chain_note: i32): i32;
@external("env", "_saber_set_color")
export declare function _saber_set_color(saber: i32, color: i32): void;
@external("env", "_saber_get_color")
export declare function _saber_get_color(saber: i32): i32;
@external("env", "_get_left_saber")
export declare function _get_left_saber(): i32;
@external("env", "_get_right_saber")
export declare function _get_right_saber(): i32;
@external("env", "_log")
export declare function _log(message: i32): void;
@external("env", "_drop_reference")
export declare function _drop_reference(ptr: i32): void;
@external("env", "_vec2_from_xy")
export declare function _vec2_from_xy(x: f32, y: f32): i32;
@external("env", "_vec3_from_xyz")
export declare function _vec3_from_xyz(x: f32, y: f32, z: f32): i32;
@external("env", "_vec4_from_xyzw")
export declare function _vec4_from_xyzw(x: f32, y: f32, z: f32, w: f32): i32;
@external("env", "_quat_from_xyzw")
export declare function _quat_from_xyzw(x: f32, y: f32, z: f32, w: f32): i32;
@external("env", "_color_set_rgb")
export declare function _color_set_rgb(color: i32, r: f32, g: f32, b: f32): void;
@external("env", "_color_set_rgba")
export declare function _color_set_rgba(color: i32, r: f32, g: f32, b: f32, a: f32): void;
@external("env", "_data_contains_persistent_i32")
export declare function _data_contains_persistent_i32(key: i32): bool;
@external("env", "_data_contains_persistent_f32")
export declare function _data_contains_persistent_f32(key: i32): bool;
@external("env", "_data_contains_persistent_str")
export declare function _data_contains_persistent_str(key: i32): bool;
@external("env", "_data_store_persistent_i32")
export declare function _data_store_persistent_i32(key: i32, value: i32): void;
@external("env", "_data_store_persistent_f32")
export declare function _data_store_persistent_f32(key: i32, value: f32): void;
@external("env", "_data_store_persistent_str")
export declare function _data_store_persistent_str(key: i32, value: i32): void;
@external("env", "_data_access_persistent_i32")
export declare function _data_access_persistent_i32(key: i32): i32;
@external("env", "_data_access_persistent_f32")
export declare function _data_access_persistent_f32(key: i32): f32;
@external("env", "_data_access_persistent_str")
export declare function _data_access_persistent_str(key: i32): i32;
@external("env", "_data_remove_persistent_i32")
export declare function _data_remove_persistent_i32(key: i32): void;
@external("env", "_data_remove_persistent_f32")
export declare function _data_remove_persistent_f32(key: i32): void;
@external("env", "_data_remove_persistent_str")
export declare function _data_remove_persistent_str(key: i32): void;
@external("env", "_vec2_get_x")
export declare function _vec2_get_x(vec2: i32): f32;
@external("env", "_vec2_set_x")
export declare function _vec2_set_x(vec2: i32, x: f32): void;
@external("env", "_vec2_get_y")
export declare function _vec2_get_y(vec2: i32): f32;
@external("env", "_vec2_set_y")
export declare function _vec2_set_y(vec2: i32, y: f32): void;
@external("env", "_vec3_get_x")
export declare function _vec3_get_x(vec3: i32): f32;
@external("env", "_vec3_set_x")
export declare function _vec3_set_x(vec3: i32, x: f32): void;
@external("env", "_vec3_get_y")
export declare function _vec3_get_y(vec3: i32): f32;
@external("env", "_vec3_set_y")
export declare function _vec3_set_y(vec3: i32, y: f32): void;
@external("env", "_vec3_get_z")
export declare function _vec3_get_z(vec3: i32): f32;
@external("env", "_vec3_set_z")
export declare function _vec3_set_z(vec3: i32, z: f32): void;
@external("env", "_vec4_get_x")
export declare function _vec4_get_x(vec4: i32): f32;
@external("env", "_vec4_set_x")
export declare function _vec4_set_x(vec4: i32, x: f32): void;
@external("env", "_vec4_get_y")
export declare function _vec4_get_y(vec4: i32): f32;
@external("env", "_vec4_set_y")
export declare function _vec4_set_y(vec4: i32, y: f32): void;
@external("env", "_vec4_get_z")
export declare function _vec4_get_z(vec4: i32): f32;
@external("env", "_vec4_set_z")
export declare function _vec4_set_z(vec4: i32, z: f32): void;
@external("env", "_vec4_get_w")
export declare function _vec4_get_w(vec4: i32): f32;
@external("env", "_vec4_set_w")
export declare function _vec4_set_w(vec4: i32, w: f32): void;
@external("env", "_quat_get_x")
export declare function _quat_get_x(quat: i32): f32;
@external("env", "_quat_set_x")
export declare function _quat_set_x(quat: i32, x: f32): void;
@external("env", "_quat_get_y")
export declare function _quat_get_y(quat: i32): f32;
@external("env", "_quat_set_y")
export declare function _quat_set_y(quat: i32, y: f32): void;
@external("env", "_quat_get_z")
export declare function _quat_get_z(quat: i32): f32;
@external("env", "_quat_set_z")
export declare function _quat_set_z(quat: i32, z: f32): void;
@external("env", "_quat_get_w")
export declare function _quat_get_w(quat: i32): f32;
@external("env", "_quat_set_w")
export declare function _quat_set_w(quat: i32, w: f32): void;
@external("env", "_color_get_r")
export declare function _color_get_r(color: i32): f32;
@external("env", "_color_set_r")
export declare function _color_set_r(color: i32, r: f32): void;
@external("env", "_color_get_g")
export declare function _color_get_g(color: i32): f32;
@external("env", "_color_set_g")
export declare function _color_set_g(color: i32, g: f32): void;
@external("env", "_color_get_b")
export declare function _color_get_b(color: i32): f32;
@external("env", "_color_set_b")
export declare function _color_set_b(color: i32, b: f32): void;
@external("env", "_color_get_a")
export declare function _color_get_a(color: i32): f32;
@external("env", "_color_set_a")
export declare function _color_set_a(color: i32, a: f32): void;
export function toCString(str: string): u32 {
    return <u32>changetype<usize>(String.UTF8.encode(str, true));
}
export function readCString(ptr: u32): string {
    const str = String.UTF8.decodeUnsafe(ptr, u32.MAX_VALUE, true); // true = null-terminated
    return str;
}

class Color {
    ptr: i32;

    constructor(ptr: i32) {
        this.ptr = ptr;

    }

    public static get_r(): f32 {
        return _color_get_r(this.ptr);
    }

    public static set_r(r: f32): void {
        _color_set_r(this.ptr, r);
    }

    public static get_g(): f32 {
        return _color_get_g(this.ptr);
    }

    public static set_g(g: f32): void {
        _color_set_g(this.ptr, g);
    }

    public static get_b(): f32 {
        return _color_get_b(this.ptr);
    }

    public static set_b(b: f32): void {
        _color_set_b(this.ptr, b);
    }

    public static get_a(): f32 {
        return _color_get_a(this.ptr);
    }

    public static set_a(a: f32): void {
        _color_set_a(this.ptr, a);
    }

    public static set_rgb(r: f32, g: f32, b: f32): void {
        _color_set_rgb(this.ptr, r, g, b);
    }

    public static set_rgba(r: f32, g: f32, b: f32, a: f32): void {
        _color_set_rgba(this.ptr, r, g, b, a);
    }

}

class Log {

    constructor() {

    }

    public static info(msg: string): void {
        _log(<i32>changetype<usize>(String.UTF8.encode("info: " + msg)));
    }

    public static warn(msg: string): void {
        _log(<i32>changetype<usize>(String.UTF8.encode("warn: " + msg)));
    }

    public static critical(msg: string): void {
        _log(<i32>changetype<usize>(String.UTF8.encode("error: " + msg)));
    }

    public static debug(msg: string): void {
        _log(<i32>changetype<usize>(String.UTF8.encode("debug: " + msg)));
    }

}

class Vec2 {
    ptr: i32;

    constructor(ptr: i32) {
        this.ptr = ptr;

    }

    public static from_xy(x: f32, y: f32): Vec2 {
        return new Vec2(_vec2_from_xy(x, y));
    }

    public static get_x(): f32 {
        return _vec2_get_x(this.ptr);
    }

    public static get_y(): f32 {
        return _vec2_get_y(this.ptr);
    }

}

class Vec3 {
    ptr: i32;

    constructor(ptr: i32) {
        this.ptr = ptr;

    }

    public static from_xyz(x: f32, y: f32, z: f32): Vec3 {
        return new Vec3(_vec3_from_xyz(x, y, z));
    }

    public static get_x(): f32 {
        return _vec3_get_x(this.ptr);
    }

    public static get_y(): f32 {
        return _vec3_get_y(this.ptr);
    }

    public static get_z(): f32 {
        return _vec3_get_z(this.ptr);
    }

}

class Vec4 {
    ptr: i32;

    constructor(ptr: i32) {
        this.ptr = ptr;

    }

    public static from_xyzw(x: f32, y: f32, z: f32, w: f32): Vec4 {
        return new Vec4(_vec4_from_xyzw(x, y, z, w));
    }

    public static get_x(): f32 {
        return _vec4_get_x(this.ptr);
    }

    public static get_y(): f32 {
        return _vec4_get_y(this.ptr);
    }

    public static get_z(): f32 {
        return _vec4_get_z(this.ptr);
    }

    public static get_w(): f32 {
        return _vec4_get_w(this.ptr);
    }

}

class Quat {
    ptr: i32;

    constructor(ptr: i32) {
        this.ptr = ptr;

    }

    public static from_xyzw(x: f32, y: f32, z: f32, w: f32): Quat {
        return new Quat(_quat_from_xyzw(x, y, z, w));
    }

    public static get_x(): f32 {
        return _quat_get_x(this.ptr);
    }

    public static get_y(): f32 {
        return _quat_get_y(this.ptr);
    }

    public static get_z(): f32 {
        return _quat_get_z(this.ptr);
    }

    public static get_w(): f32 {
        return _quat_get_w(this.ptr);
    }

}

class ColorNote {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(): Color {
        let ptr = _color_note_get_color(this.ptr);
    return new Color(ptr);
    }
    public static set_color(color: Color): void {
        _color_note_set_color(this.ptr, color.ptr);
    }
    public static get_position(): Vec3 {
        let ptr = _color_note_get_position(this.ptr);
    return new Vec3(ptr);
    }
    public static set_position(position: Vec3): void {
        _color_note_set_position(this.ptr, position.ptr);
    }
    public static get_orientation(): Quat {
        let ptr = _color_note_get_orientation(this.ptr);
    return new Quat(ptr);
    }
    public static set_orientation(orientation: Quat): void {
        _color_note_set_orientation(this.ptr, orientation.ptr);
    }
}
class BombNote {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(): Color {
        let ptr = _bomb_note_get_color(this.ptr);
    return new Color(ptr);
    }
    public static set_color(color: Color): void {
        _bomb_note_set_color(this.ptr, color.ptr);
    }
    public static get_position(): Vec3 {
        let ptr = _bomb_note_get_position(this.ptr);
    return new Vec3(ptr);
    }
    public static set_position(position: Vec3): void {
        _bomb_note_set_position(this.ptr, position.ptr);
    }
    public static get_orientation(): Quat {
        let ptr = _bomb_note_get_orientation(this.ptr);
    return new Quat(ptr);
    }
    public static set_orientation(orientation: Quat): void {
        _bomb_note_set_orientation(this.ptr, orientation.ptr);
    }
}
class Arc {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(): Color {
        let ptr = _arc_get_color(this.ptr);
    return new Color(ptr);
    }
    public static set_color(color: Color): void {
        _arc_set_color(this.ptr, color.ptr);
    }
    public static get_position(): Vec3 {
        let ptr = _arc_get_position(this.ptr);
    return new Vec3(ptr);
    }
    public static set_position(position: Vec3): void {
        _arc_set_position(this.ptr, position.ptr);
    }
    public static get_orientation(): Quat {
        let ptr = _arc_get_orientation(this.ptr);
    return new Quat(ptr);
    }
    public static set_orientation(orientation: Quat): void {
        _arc_set_orientation(this.ptr, orientation.ptr);
    }
}
class Wall {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(): Color {
        let ptr = _wall_get_color(this.ptr);
    return new Color(ptr);
    }
    public static set_color(color: Color): void {
        _wall_set_color(this.ptr, color.ptr);
    }
    public static get_position(): Vec3 {
        let ptr = _wall_get_position(this.ptr);
    return new Vec3(ptr);
    }
    public static set_position(position: Vec3): void {
        _wall_set_position(this.ptr, position.ptr);
    }
    public static get_orientation(): Quat {
        let ptr = _wall_get_orientation(this.ptr);
    return new Quat(ptr);
    }
    public static set_orientation(orientation: Quat): void {
        _wall_set_orientation(this.ptr, orientation.ptr);
    }
}
class ChainHeadNote {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(): Color {
        let ptr = _chain_head_note_get_color(this.ptr);
    return new Color(ptr);
    }
    public static set_color(color: Color): void {
        _chain_head_note_set_color(this.ptr, color.ptr);
    }
    public static get_position(): Vec3 {
        let ptr = _chain_head_note_get_position(this.ptr);
    return new Vec3(ptr);
    }
    public static set_position(position: Vec3): void {
        _chain_head_note_set_position(this.ptr, position.ptr);
    }
    public static get_orientation(): Quat {
        let ptr = _chain_head_note_get_orientation(this.ptr);
    return new Quat(ptr);
    }
    public static set_orientation(orientation: Quat): void {
        _chain_head_note_set_orientation(this.ptr, orientation.ptr);
    }
}
class ChainLinkNote {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(): Color {
        let ptr = _chain_link_note_get_color(this.ptr);
    return new Color(ptr);
    }
    public static set_color(color: Color): void {
        _chain_link_note_set_color(this.ptr, color.ptr);
    }
    public static get_position(): Vec3 {
        let ptr = _chain_link_note_get_position(this.ptr);
    return new Vec3(ptr);
    }
    public static set_position(position: Vec3): void {
        _chain_link_note_set_position(this.ptr, position.ptr);
    }
    public static get_orientation(): Quat {
        let ptr = _chain_link_note_get_orientation(this.ptr);
    return new Quat(ptr);
    }
    public static set_orientation(orientation: Quat): void {
        _chain_link_note_set_orientation(this.ptr, orientation.ptr);
    }
}
class ChainNote {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(): Color {
        let ptr = _chain_note_get_color(this.ptr);
    return new Color(ptr);
    }
    public static set_color(color: Color): void {
        _chain_note_set_color(this.ptr, color.ptr);
    }
    public static get_position(): Vec3 {
        let ptr = _chain_note_get_position(this.ptr);
    return new Vec3(ptr);
    }
    public static set_position(position: Vec3): void {
        _chain_note_set_position(this.ptr, position.ptr);
    }
    public static get_orientation(): Quat {
        let ptr = _chain_note_get_orientation(this.ptr);
    return new Quat(ptr);
    }
    public static set_orientation(orientation: Quat): void {
        _chain_note_set_orientation(this.ptr, orientation.ptr);
    }
}

export function create_color_note(beat: f32): ColorNote {
    let ptr = _create_color_note(beat);
    return new ColorNote(ptr);
}

export function create_bomb_note(beat: f32): BombNote {
    let ptr = _create_bomb_note(beat);
    return new BombNote(ptr);
}

export function create_arc(beat: f32): Arc {
    let ptr = _create_arc(beat);
    return new Arc(ptr);
}

export function create_wall(beat: f32): Wall {
    let ptr = _create_wall(beat);
    return new Wall(ptr);
}

export function create_chain_head_note(beat: f32): ChainHeadNote {
    let ptr = _create_chain_head_note(beat);
    return new ChainHeadNote(ptr);
}

export function create_chain_link_note(beat: f32): ChainLinkNote {
    let ptr = _create_chain_link_note(beat);
    return new ChainLinkNote(ptr);
}

export function create_chain_note(beat: f32): ChainNote {
    let ptr = _create_chain_note(beat);
    return new ChainNote(ptr);
}

class Beatmap {
    constructor() {
    }
    public static add_color_note(color_note: ColorNote): void {
        _beatmap_add_color_note(color_note.ptr);
    }
    public static remove_color_note(color_note: ColorNote): void {
        _beatmap_remove_color_note(color_note.ptr);
    }
    public static get_color_note_at_beat(beat: f32): ColorNote {
        _beatmap_get_color_note_at_beat(beat);
    }
    public static add_bomb_note(bomb_note: BombNote): void {
        _beatmap_add_bomb_note(bomb_note.ptr);
    }
    public static remove_bomb_note(bomb_note: BombNote): void {
        _beatmap_remove_bomb_note(bomb_note.ptr);
    }
    public static get_bomb_note_at_beat(beat: f32): BombNote {
        _beatmap_get_bomb_note_at_beat(beat);
    }
    public static add_arc(arc: Arc): void {
        _beatmap_add_arc(arc.ptr);
    }
    public static remove_arc(arc: Arc): void {
        _beatmap_remove_arc(arc.ptr);
    }
    public static get_arc_at_beat(beat: f32): Arc {
        _beatmap_get_arc_at_beat(beat);
    }
    public static add_wall(wall: Wall): void {
        _beatmap_add_wall(wall.ptr);
    }
    public static remove_wall(wall: Wall): void {
        _beatmap_remove_wall(wall.ptr);
    }
    public static get_wall_at_beat(beat: f32): Wall {
        _beatmap_get_wall_at_beat(beat);
    }
    public static add_chain_head_note(chain_head_note: ChainHeadNote): void {
        _beatmap_add_chain_head_note(chain_head_note.ptr);
    }
    public static remove_chain_head_note(chain_head_note: ChainHeadNote): void {
        _beatmap_remove_chain_head_note(chain_head_note.ptr);
    }
    public static get_chain_head_note_at_beat(beat: f32): ChainHeadNote {
        _beatmap_get_chain_head_note_at_beat(beat);
    }
    public static add_chain_link_note(chain_link_note: ChainLinkNote): void {
        _beatmap_add_chain_link_note(chain_link_note.ptr);
    }
    public static remove_chain_link_note(chain_link_note: ChainLinkNote): void {
        _beatmap_remove_chain_link_note(chain_link_note.ptr);
    }
    public static get_chain_link_note_at_beat(beat: f32): ChainLinkNote {
        _beatmap_get_chain_link_note_at_beat(beat);
    }
    public static add_chain_note(chain_note: ChainNote): void {
        _beatmap_add_chain_note(chain_note.ptr);
    }
    public static remove_chain_note(chain_note: ChainNote): void {
        _beatmap_remove_chain_note(chain_note.ptr);
    }
    public static get_chain_note_at_beat(beat: f32): ChainNote {
        _beatmap_get_chain_note_at_beat(beat);
    }
}

export { Beatmap, Log, Color, ColorNote, BombNote, Arc, Wall, ChainHeadNote, ChainLinkNote, ChainNote }