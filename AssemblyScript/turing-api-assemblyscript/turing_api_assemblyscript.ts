// Turing API - AssemblyScript
// License: GPL-2.0-only
// Authors: Westbot

// thank you typescript, for complaining about every single decorator >:(
@external("env", "_create_color_note")
export declare function _create_color_note(beat: f32): i32;

@external("env", "_beatmap_add_color_note")
export declare function _beatmap_add_color_note(note: i32): void;

class ColorNote {
    id: i32

    constructor(id: i32) {
        this.id = id;
    }
}

class Beatmap {

    public static add_color_note(note: ColorNote): void {
        _beatmap_add_color_note(note.id)
    }

}

class TuringApi {

    public static create_color_note(beat: f32): ColorNote {
        let i = _create_color_note(beat);
        return new ColorNote(i);
    }

}


export { TuringApi, Beatmap, ColorNote };