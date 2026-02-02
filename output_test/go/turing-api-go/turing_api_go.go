


///// Generated Go API /////
package turing_api

//// Wasm Bindings ////

//go:wasmimport env _host_strcpy
func _host_strcpy(location *byte, size uint32)
//go:wasmimport env _host_bufcpy
func _host_bufcpy(location *uint32, size uint32)
//go:wasmimport env _host_f32_enqueue
func _host_f32_enqueue(f: float32)
//go:wasmimport env _host_f32_dequeue
func _host_f32_dequeue() float32
//go:wasmimport env _host_u32_enqueue
func _host_u32_enqueue(u: uint32)
//go:wasmimport env _host_u32_dequeue
func _host_u32_dequeue() uint32


//go:wasmimport env _do_thing
func _do_thing(random Random) Something
//go:wasmimport env _log__debug
func _log__debug(msg uint32) void
//go:wasmimport env _log__critical
func _log__critical(msg uint32) void
//go:wasmimport env _log__warn
func _log__warn(msg uint32) void
//go:wasmimport env _log__info
func _log__info(msg uint32) void
//go:wasmimport env _vivify__upload_buffer
func _vivify__upload_buffer(buf *void) void
//go:wasmimport env _vivify__get_buffer
func _vivify__get_buffer() uint32

//export _turing_api_semver
func _turing_api_semver() uint64 {
    return (uint64(1) << 32) | (uint64(0) << 16) | uint64(0)
}

const TURING_API_VERSION = "1.0.0"

//// Functions ////


func doThing(random Random) Something {
    
    return _do_thing(random)
}

//// Classes ////
/// Used to log messages to the console
type Log struct {
    
}

/// Only logs in debug mode
func Log_debug(msg string) void {
    
    turingHMsg := []byte(msg)
    turingHMsg = append(turingHMsg, 0)
    turingHandleMsg := &turingHMsg[0]
    _log__debug(turingHandleMsg)
}
/// Highlights red
func Log_critical(msg string) void {
    
    turingHMsg := []byte(msg)
    turingHMsg = append(turingHMsg, 0)
    turingHandleMsg := &turingHMsg[0]
    _log__critical(turingHandleMsg)
}
/// Highlights yellow
func Log_warn(msg string) void {
    
    turingHMsg := []byte(msg)
    turingHMsg = append(turingHMsg, 0)
    turingHandleMsg := &turingHMsg[0]
    _log__warn(turingHandleMsg)
}
/// Highlights blue
func Log_info(msg string) void {
    
    turingHMsg := []byte(msg)
    turingHMsg = append(turingHMsg, 0)
    turingHandleMsg := &turingHMsg[0]
    _log__info(turingHandleMsg)
}

/// Vivify compatibility systems
type Vivify struct {
    
}

/// Uploads a data buffer to beat saber
func Vivify_uploadBuffer(buf []uint32) void {
    
    _host_u32_enqueue(len(buf))
    turingHBuf := []uint32(buf)
    turingHandleBuf := &turingHBuf[0]
    _vivify__upload_buffer(turingHandleBuf)
}
/// Fetches a data buffer from beat saber
func Vivify_getBuffer() []uint32 {
    
    turingResult := _vivify__get_buffer()
    turingBuf := make([]uint32, turingResult)
    _host_bufcpy(&turingBuf[0], turingResult)
    return turingBuf
}


type Random struct {
    opaqu uint32
}



type Something struct {
    opaqu uint32
}




