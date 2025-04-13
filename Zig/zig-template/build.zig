const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{
        .default_target = .{
            .cpu_arch = .wasm32,
            .os_tag = .freestanding,
        },
    });
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "script",
        .root_source_file = b.path("src/main.zig"),
        .target = target,
        .optimize = optimize,
    });

    const api_dep = b.dependency("turing_api", .{});
    exe.root_module.addImport("turing-api", api_dep.module("turing-api"));

    exe.root_module.export_symbol_names = &[_][]const u8{
        "on_load",
        "on_update",
        "on_exit",
    };

    exe.entry = .disabled;
    exe.linkage = .static;

    b.installArtifact(exe);
}
