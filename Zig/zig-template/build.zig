
const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.resolveTargetQuery(.{
        .cpu_arch = .wasm32,
        .os_tag = .wasi,
    });

    const optimize = b.standardOptimizeOption(.{});

    const api_module = b.addModule("turing_api", .{
        .root_source_file = b.path("../turing-api-zig/src/root.zig"),
    });

    const exe = b.addExecutable(.{
        .name = "output",
        .root_source_file = b.path("src/main.zig"),
        .target = target,
        .optimize = optimize,
    });

    exe.root_module.addImport("turing_api", api_module);
    exe.rdynamic = true;
    exe.entry = .disabled;

    b.installArtifact(exe);
}

