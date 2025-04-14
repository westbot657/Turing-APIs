import { TuringApi, Beatmap } from "../../turing-api-assemblyscript/turing_api_assemblyscript";

export function on_load(): void {
    
}

export function on_update(beat: f32): void {
    let note = TuringApi.create_color_note(beat+2);

    Beatmap.add_color_note(note);
}

export function on_exit(): void {

}
