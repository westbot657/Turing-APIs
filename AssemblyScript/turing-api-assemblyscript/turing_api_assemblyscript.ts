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

    public static get_r(self: Color): f32 {
        return _color_get_r(self.ptr);
    }

    public static set_r(self: Color, r: f32): void {
        _color_set_r(self.ptr, r);
    }

    public static get_g(self: Color): f32 {
        return _color_get_g(self.ptr);
    }

    public static set_g(self: Color, g: f32): void {
        _color_set_g(self.ptr, g);
    }

    public static get_b(self: Color): f32 {
        return _color_get_b(self.ptr);
    }

    public static set_b(self: Color, b: f32): void {
        _color_set_b(self.ptr, b);
    }

    public static get_a(self: Color): f32 {
        return _color_get_a(self.ptr);
    }

    public static set_a(self: Color, a: f32): void {
        _color_set_a(self.ptr, a);
    }

    public static set_rgb(self: Color, r: f32, g: f32, b: f32): void {
        _color_set_rgb(self.ptr, r, g, b);
    }

    public static set_rgba(self: Color, r: f32, g: f32, b: f32, a: f32): void {
        _color_set_rgba(self.ptr, r, g, b, a);
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

class ColorNote {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(self: ColorNote): Color {
        let ptr = _color_note_get_color(self.ptr);
    return new Color(ptr);
    }
}
class BombNote {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(self: BombNote): Color {
        let ptr = _bomb_note_get_color(self.ptr);
    return new Color(ptr);
    }
}
class Arc {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(self: Arc): Color {
        let ptr = _arc_get_color(self.ptr);
    return new Color(ptr);
    }
}
class Wall {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(self: Wall): Color {
        let ptr = _wall_get_color(self.ptr);
    return new Color(ptr);
    }
}
class ChainHeadNote {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(self: ChainHeadNote): Color {
        let ptr = _chain_head_note_get_color(self.ptr);
    return new Color(ptr);
    }
}
class ChainLinkNote {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(self: ChainLinkNote): Color {
        let ptr = _chain_link_note_get_color(self.ptr);
    return new Color(ptr);
    }
}
class ChainNote {
    ptr: i32;
    constructor(ptr: i32) {
        this.ptr = ptr;
    }
    public static get_color(self: ChainNote): Color {
        let ptr = _chain_note_get_color(self.ptr);
    return new Color(ptr);
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
    public static add_bomb_note(bomb_note: BombNote): void {
        _beatmap_add_bomb_note(bomb_note.ptr);
    }
    public static remove_bomb_note(bomb_note: BombNote): void {
        _beatmap_remove_bomb_note(bomb_note.ptr);
    }
    public static add_arc(arc: Arc): void {
        _beatmap_add_arc(arc.ptr);
    }
    public static remove_arc(arc: Arc): void {
        _beatmap_remove_arc(arc.ptr);
    }
    public static add_wall(wall: Wall): void {
        _beatmap_add_wall(wall.ptr);
    }
    public static remove_wall(wall: Wall): void {
        _beatmap_remove_wall(wall.ptr);
    }
    public static add_chain_head_note(chain_head_note: ChainHeadNote): void {
        _beatmap_add_chain_head_note(chain_head_note.ptr);
    }
    public static remove_chain_head_note(chain_head_note: ChainHeadNote): void {
        _beatmap_remove_chain_head_note(chain_head_note.ptr);
    }
    public static add_chain_link_note(chain_link_note: ChainLinkNote): void {
        _beatmap_add_chain_link_note(chain_link_note.ptr);
    }
    public static remove_chain_link_note(chain_link_note: ChainLinkNote): void {
        _beatmap_remove_chain_link_note(chain_link_note.ptr);
    }
    public static add_chain_note(chain_note: ChainNote): void {
        _beatmap_add_chain_note(chain_note.ptr);
    }
    public static remove_chain_note(chain_note: ChainNote): void {
        _beatmap_remove_chain_note(chain_note.ptr);
    }
}

export { Beatmap, Log, Color, ColorNote, BombNote, Arc, Wall, ChainHeadNote, ChainLinkNote, ChainNote }