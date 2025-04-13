
use turing_api::{*, Beatmap, Log};

#[no_mangle]
unsafe extern "C" fn on_load() {
    // This is called once when the map is loaded in.
}

#[no_mangle]
unsafe extern "C" fn on_update(beat: f32) {
    // This is called every frame that the map is playing
}

#[no_mangle]
unsafe extern "C" fn on_exit() {
    // This is called when the map is exited. i.e. when you complete or fail the level
}