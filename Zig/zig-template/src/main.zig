const turing_api = @import("turing-api");

pub export fn on_load() void {}

pub export fn on_update(beat: f32) void {
    // _ = beat;
    const x: turing_api.ColorNote = turing_api.create_color_note(beat);
    _ = x;
}

pub export fn on_exit() void {}
