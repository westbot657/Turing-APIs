//! Turing API - Zig
//! License: GPL-2.0-only
//! Authors: Westbot

// WASM imports
extern "env" fn _create_color_note(beat: f32) i32;

// API
pub const ColorNote = struct { ptr: i32 };
pub const BombNote = struct { ptr: i32 };
pub const Wall = struct { ptr: i32 };
pub const Arc = struct { ptr: i32 };
pub const ChainHeadNote = struct { ptr: i32 };
pub const ChainLinkNote = struct { ptr: i32 };
pub const ChainNote = struct { ptr: i32 };

pub fn create_color_note(beat: f32) ColorNote {
    return .{ .ptr = _create_color_note(beat) };
}
