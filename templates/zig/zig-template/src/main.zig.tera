const std = @import("std");
const api = @import("turing_api");
var gpa = std.heap.GeneralPurposeAllocator(.{}){};
const global_allocator = gpa.allocator();

export fn on_load() void {
    api.Log.info("Log.info from zig!", global_allocator) catch {};
}

export fn on_update() void {

}

export fn on_exit() void {

}

