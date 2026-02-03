import * as Turing from "../../turing-api-asmscript/turing_api";
import {Vec2, Vec3, Vec4, Quat, Mat4} from "../../turing-api-asmscript/linear_algebra"

export function on_load(): void {
    Turing.Log.info("AsmScript on_load() called!")
}

export function on_update(beat: f32): void {
    let note = Turing.create_color_note(beat+2);
    Turing.Beatmap.add_color_note(note);
}

export function on_exit(): void {

}