import * as Turing from "../../turing-api-assemblyscript/turing_api_assemblyscript";

export function on_load(): void {
    Turing.Log.info("AsmScript on_load!")
}

export function on_update(beat: f32): void {
    let note = Turing.create_color_note(beat+2);

    Turing.Beatmap.add_color_note(note);
}

export function on_exit(): void {

}
