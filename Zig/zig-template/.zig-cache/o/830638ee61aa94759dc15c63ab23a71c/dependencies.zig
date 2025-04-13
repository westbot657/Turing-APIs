pub const packages = struct {
    pub const @"../turing-api" = struct {
        pub const build_root = "w:\\Turing\\APIs\\Zig\\zig-template\\../turing-api";
        pub const build_zig = @import("../turing-api");
        pub const deps: []const struct { []const u8, []const u8 } = &.{
        };
    };
};

pub const root_deps: []const struct { []const u8, []const u8 } = &.{
    .{ "turing_api", "../turing-api" },
};
