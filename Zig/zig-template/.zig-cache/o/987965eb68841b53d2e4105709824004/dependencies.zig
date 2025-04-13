pub const packages = struct {
    pub const @"../../turing_api" = struct {
        pub const build_root = "W:\\Turing\\APIs\\Zig\\zig-template\\../../turing_api";
        pub const deps: []const struct { []const u8, []const u8 } = &.{};
    };
};

pub const root_deps: []const struct { []const u8, []const u8 } = &.{
    .{ "turing_api", "../../turing_api" },
};
