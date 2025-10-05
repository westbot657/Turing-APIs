
foreign import "_log" proc(msg: cstring) -> void

log :: proc(msg: cstring) {
    _log(msg)
}



