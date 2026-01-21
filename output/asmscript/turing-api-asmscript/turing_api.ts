
///// Generated AssemblyScript API /////
import { Vec2, Vec3, Vec4, Quat, Mat4 } from "./linear_algebra";

//// Wasm Bindings ////
@external("env", "_host_strcpy")
declare function _host_strcpy(location: u32, size: u32): void;
@external("env", "_host_f32_enqueue")
declare function _host_f32_enqueue(f: f32): void;
@external("env", "_host_f32_dequeue")
declare function _host_f32_dequeue(): f32;

@external("env", "_test_global")
declare function _test_global(name: u32): void;
@external("env", "_global_2_test")
declare function _global_2_test(): i32;
@external("env", "_my_test")
declare function _my_test(a: i8, b: i16): u32;


@external("env", "_my_class_object_func")
declare function _my_class_object_func(opaqu: u64, a: i16): void;

@external("env", "_color_note_set_position")
declare function _color_note_set_position(opaqu: u64, v: u32): void;
@external("env", "_color_note_set_orientation")
declare function _color_note_set_orientation(opaqu: u64, q: u32): void;
@external("env", "_color_note_set_transform")
declare function _color_note_set_transform(opaqu: u64, m: u32): void;
@external("env", "_color_note_get_position")
declare function _color_note_get_position(opaqu: u64): u32;
@external("env", "_color_note_get_orientation")
declare function _color_note_get_orientation(opaqu: u64): u32;
@external("env", "_color_note_get_transform")
declare function _color_note_get_transform(opaqu: u64): u32;
@external("env", "_color_note_clone")
declare function _color_note_clone(opaqu: u64): ColorNote;
@external("env", "_log_info")
declare function _log_info(msg: u32): void;
@external("env", "_log_warn")
declare function _log_warn(msg: u32): void;
@external("env", "_log_critical")
declare function _log_critical(msg: u32): void;
@external("env", "_log_debug")
declare function _log_debug(msg: u32): void;
export function _turing_api_semver(): u64 {
    return (0u64 << 32) | (8u64 << 16) | 0u64;
}

//// Linear Algebra Helpers ////

// Vec2
function enqueue_vec2(v: Vec2): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    return 2;
}

function dequeue_vec2(): Vec2 {
    return new Vec2(
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

// Vec3
function enqueue_vec3(v: Vec3): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    return 3;
}

function dequeue_vec3(): Vec3 {
    return new Vec3(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

// Vec4
function enqueue_vec4(v: Vec4): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    _host_f32_enqueue(v.w);
    return 4;
}

function dequeue_vec4(): Vec4 {
    return new Vec4(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

// Quat
function enqueue_quat(q: Quat): u32 {
    _host_f32_enqueue(q.x);
    _host_f32_enqueue(q.y);
    _host_f32_enqueue(q.z);
    _host_f32_enqueue(q.w);
    return 4;
}

function dequeue_quat(): Quat {
    return new Quat(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

// Mat4 (column-major)
function enqueue_mat4(m: Mat4): u32 {
    for (let i: i32 = 0; i < 16; i++) {
        _host_f32_enqueue(m.m[i]);
    }
    return 16;
}

function dequeue_mat4(): Mat4 {
    let out = new Mat4();
    for (let i: i32 = 0; i < 16; i++) {
        out.m[i] = _host_f32_dequeue();
    }
    return out;
}

//// Functions ////


export function test_global(name: string): void {
    let turing_handle_name = String.UTF8.encode(name, true);
    _test_global(turing_handle_name);
}

export function global_2_test(): i32 {
    return _global_2_test();
}

export function my_test(a: i8, b: i16): string {
    let turing_result = _my_test(a, b);
    let turing_str = heap.alloc(usize(turing_result));
    _host_strcpy(u32(turing_str), turing_result);
    let turing_output = String.UTF8.decode(turing_str, true);
    heap.free(turing_str);
    return turing_output;
}


//// Classes ////

class MyClass {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }



    public object_func(a: i16): void {
        _my_class_object_func(this.opaqu, a);
    }
}
/// this is line 1
/// this is line 2
class ColorNote {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }



    public set_position(v: Vec3): ColorNote {
        let turing_handle_v = enqueue_vec3(v);
        _color_note_set_position(this.opaqu, turing_handle_v);
        return this;
    }

    public set_orientation(q: Quat): ColorNote {
        let turing_handle_q = enqueue_quat(q);
        _color_note_set_orientation(this.opaqu, turing_handle_q);
        return this;
    }

    public set_transform(m: Mat4): ColorNote {
        let turing_handle_m = enqueue_mat4(m);
        _color_note_set_transform(this.opaqu, turing_handle_m);
        return this;
    }

    public get_position(): Vec3 {
        _color_note_get_position(this.opaqu);
        return dequeue_vec3();
    }

    public get_orientation(): Quat {
        _color_note_get_orientation(this.opaqu);
        return dequeue_quat();
    }

    public get_transform(): Mat4 {
        _color_note_get_transform(this.opaqu);
        return dequeue_mat4();
    }

    public clone(): ColorNote {
        let turing_result = _color_note_clone(this.opaqu);
        return new ColorNote(turing_result);
    }
}
/// used to log messages to the console
/// idk, this is a second line
class Log {
    

    /// logs `msg` to the console
    public static info(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log_info(turing_handle_msg);
    }
    /// logs `msg` to the console as a warning
    public static warn(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log_warn(turing_handle_msg);
    }
    /// logs `msg` to the console as an error
    public static critical(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log_critical(turing_handle_msg);
    }
    /// logs `msg` to the console when in debug mode
    public static debug(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log_debug(turing_handle_msg);
    }

}

