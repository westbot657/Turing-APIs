

extern(C) {
    @extern("env") void _log(const char* msg);
}

extern(C) void log(const char* msg) {
    _log(msg);
}


