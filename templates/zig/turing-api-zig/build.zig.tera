const std = @import("std");

pub fn build(b: *std.Build) void {
    const optimizations = b.standardOptimizeOption(.{});

    const target = b.standardTargetOptions(.{
        .default_target = .{
            .cpu_arch = .wasm32,
            .os_tag = .wasi,
        }
    });

    const lib = b.addExecutable(.{
        .name = "turing_api",
        .root_module = b.createModule(.{
            .root_source_file = b.path("src/turing_api.zig"),
            .target = target,
            .optimize = optimizations,
        })
    });

    b.installArtifact(lib);

}
