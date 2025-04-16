// Turing API - AssemblyScript
// License: GPL-2.0-only
// Authors: Westbot

// thank you typescript, for complaining about every single decorator >:(
@external("env", "_create_color_note")
export declare function _create_color_note(beat: f32): i32;

@external("env", "_beatmap_add_color_note")
export declare function _beatmap_add_color_note(note: i32): void;

@external("env", "_log")
export declare function _log(message: i32): void;

// AssemblyScript
export function toCString(str: string): u32 {
    return <u32>changetype<usize>(String.UTF8.encode(str, true));
}


export function readCString(ptr: u32): void {
    const str = String.UTF8.decodeUnsafe(ptr, u32.MAX_VALUE, true); // true = null-terminated
    console.log(str);
}



class ColorNote {
    id: i32;

    constructor(id: i32) {
        this.id = id;
    }
}

class Beatmap {

    public static add_color_note(note: ColorNote): void {
        _beatmap_add_color_note(note.id)
    }

}

class Log {

    public static info(msg: string): void {
        _log(toCString(msg))
    }

}

class TuringApi {

    public static create_color_note(beat: f32): ColorNote {
        let i = _create_color_note(beat);
        return new ColorNote(i);
    }

}


export { TuringApi, Log, Beatmap, ColorNote };