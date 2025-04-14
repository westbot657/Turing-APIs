const std = @import("std");

pub fn build(b: *std.Build) void {
    // const target: std.Target = .{
    //     .cpu = .{
    //         .arch = .wasm32,
    //         .model = ??,
    //     },
    //     .os_tag = .freestanding,
    // };
    const target = b.standardTargetOptions(.{
        .default_target = .{
            .cpu_arch = .wasm32,
            .os_tag = .freestanding,
        },
    });
    const optimize = b.standardOptimizeOption(.{});

    const lib = b.addExecutable(.{
        .name = "turing-api",
        .root_source_file = b.path("src/root.zig"),
        .target = target,
        .optimize = optimize,
    });

    lib.entry = .disabled;

    lib.linkage = .static;

    b.installArtifact(lib);

    _ = b.addModule("turing-api", .{
        .root_source_file = b.path("src/root.zig"),
    });
}
