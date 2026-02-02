///// Generated AssemblyScript API /////
import { Vec2, Vec3, Vec4, Quat, Mat4 } from "../turing-api-asmscript/linear_algebra";


//// Wasm Bindings ////


@external("env", "_host_strcpy")
export declare function _host_strcpy(location: u32, size: u32): void;
@external("env", "_host_bufcpy")
export declare function _host_bufcpy(location: u32, size: u32): void;
@external("env", "_host_f32_enqueue")
export declare function _host_f32_enqueue(f: f32): void;
@external("env", "_host_f32_dequeue")
export declare function _host_f32_dequeue(): f32;
@external("env", "_host_u32_enqueue")
export declare function _host_u32_enqueue(f: u32): void;
@external("env", "_host_u32_dequeue")
export declare function _host_u32_dequeue(): u32;


@external("env", "_do_thing")
declare function _do_thing(random: u64): u64;
@external("env", "_log__debug")
declare function _log__debug(msg: u32): void;
@external("env", "_log__critical")
declare function _log__critical(msg: u32): void;
@external("env", "_log__warn")
declare function _log__warn(msg: u32): void;
@external("env", "_log__info")
declare function _log__info(msg: u32): void;
@external("env", "_vivify__upload_buffer")
declare function _vivify__upload_buffer(buf: u32): void;
@external("env", "_vivify__get_buffer")
declare function _vivify__get_buffer(): u32;

export function _turing_api_semver(): u64 {
    return (1u64 << 32) | (0u64 << 16) | 0u64;
}

export const TURING_API_VERSION = "1.0.0";


//// Linear Algebra Helpers ////

export function __enqueue_vec2(v: Vec2): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    return 2;
}

export function __dequeue_vec2(): Vec2 {
    return new Vec2(
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

export function __enqueue_vec3(v: Vec3): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    return 3;
}

export function __dequeue_vec3(): Vec3 {
    return new Vec3(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

export function __enqueue_vec4(v: Vec4): u32 {
    _host_f32_enqueue(v.x);
    _host_f32_enqueue(v.y);
    _host_f32_enqueue(v.z);
    _host_f32_enqueue(v.w);
    return 4;
}

export function __dequeue_vec4(): Vec4 {
    return new Vec4(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

export function __enqueue_quat(q: Quat): u32 {
    _host_f32_enqueue(q.x);
    _host_f32_enqueue(q.y);
    _host_f32_enqueue(q.z);
    _host_f32_enqueue(q.w);
    return 4;
}

export function __dequeue_quat(): Quat {
    return new Quat(
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue(),
        _host_f32_dequeue()
    );
}

export function __enqueue_mat4(m: Mat4): u32 {
    for (let i: i32 = 0; i < 16; i++) {
        _host_f32_enqueue(m.m[i]);
    }
    return 16;
}

export function __dequeue_mat4(): Mat4 {
    let out = new Mat4();
    for (let i: i32 = 0; i < 16; i++) {
        out.m[i] = _host_f32_dequeue();
    }
    return out;
}




//// Functions ////


export function do_thing(random: Random): Something {
    let turing_result = _do_thing(random.handle);
    return new Something(turing_result);
}

//// Classes ////
/// Used to log messages to the console
@final
export class Log {
    

    /// Only logs in debug mode
    public static debug(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log__debug(turing_handle_msg);
    }
    /// Highlights red
    public static critical(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log__critical(turing_handle_msg);
    }
    /// Highlights yellow
    public static warn(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log__warn(turing_handle_msg);
    }
    /// Highlights blue
    public static info(msg: string): void {
        let turing_handle_msg = String.UTF8.encode(msg, true);
        _log__info(turing_handle_msg);
    }

}
/// Vivify compatibility systems
@final
export class Vivify {
    

    /// Uploads a data buffer to beat saber
    public static upload_buffer(buf: Array<u32>): void {
        _host_u32_enqueue(u32(buf.length));
        let turing_view_buf = Uint32Array.wrap(buf);
        let turing_handle_buf = turing_view_buf.dataStart;
        _vivify__upload_buffer(turing_handle_buf);
    }
    /// Fetches a data buffer from beat saber
    public static get_buffer(): Array<u32> {
        let turing_result = _vivify__get_buffer();
        let turing_buf = heap.alloc(usize(turing_result) * sizeof<u32>());
        _host_bufcpy(u32(turing_buf), turing_result);
        let view = Uint32Array.wrap(turing_buf, turing_result);
        let arr = Array.from(view);
        heap.free(turing_buf);
        return arr;
    }

}

@final
export class Random {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}

@final
export class Something {
    
    handle: u64;

    constructor(handle: u64) {
        this.handle = handle;
    }
    


}



