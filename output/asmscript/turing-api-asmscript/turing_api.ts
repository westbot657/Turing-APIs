
///// Generated AssemblyScript API /////


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
declare function _color_note_set_position(opaqu: u64, x: f32, y: f32, z: f32): void;
@external("env", "_color_note_set_orientation")
declare function _color_note_set_orientation(opaqu: u64, x: f32, y: f32, z: f32, w: f32): void;
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
    return (0u64 << 16) | (8u64 << 8) | 0u64;
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

class ColorNote {
    opaqu: u64;
    constructor(opaqu: u64) {
        this.opaqu = opaqu;
    }



    public set_position(x: f32, y: f32, z: f32): ColorNote {
        _color_note_set_position(this.opaqu, x, y, z);
        return this;
    }

    public set_orientation(x: f32, y: f32, z: f32, w: f32): ColorNote {
        _color_note_set_orientation(this.opaqu, x, y, z, w);
        return this;
    }

    public clone(): ColorNote {
        let turing_result = _color_note_clone(this.opaqu);
        return new ColorNote(turing_result);
    }
}
/// used to log messages to the console
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

