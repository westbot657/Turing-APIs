const std = @import("std");


pub fn build(b: *std.Build) void {
    const optimize = b.standardOptimizeOption(.{});

    const target = b.standardTargetOptions(.{
        .default_target = .{
            .cpu_arch = .wasm32,
            .os_tag = .wasi,
        }
    });

    const mod = b.addModule("core", .{
        .root_source_file = b.path("../core-zig/src/core.zig"),
        .target = target
    });

    const exe = b.addExecutable(.{
        .name = "turing_template",
        .root_module = b.createModule(.{
            .root_source_file = b.path("src/main.zig"),
            .target = target,
            .optimize = optimize,
            .imports = &.{
                .{ .name = "core", .module = mod }
            }
        })
    });

    b.installArtifact(exe);


}