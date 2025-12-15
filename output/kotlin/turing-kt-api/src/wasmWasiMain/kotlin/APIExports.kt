@file:OptIn(
    kotlin.wasm.ExperimentalWasmInterop::class,
)
@file:Suppress("Unused")

///// Generated Kotlin API /////

import kotlinx.cinterop.*
import kotlin.native.concurrent.*

//// Wasm Bindings ////
// host helper to copy string bytes from host memory into guest buffer
@WasmImport("env", "_host_strcpy")
external fun _host_strcpy(location: CPointer<ByteVar>?, size: Int)

// FFI imports for global functions

@WasmImport("env", "_test_global")
external fun _test_global(name: CPointer<ByteVar>?)

@WasmImport("env", "_global_2_test")
external fun _global_2_test(): Int

@WasmImport("env", "_my_test")
external fun _my_test(a: Byte, b: Short): CPointer<ByteVar>?


// FFI imports for classes
@WasmImport("env", "_my_class_object_func")
external fun _my_class_object_func(opaqu: Int, a: Short)
@WasmImport("env", "_log_info")
external fun _log_info(msg: CPointer<ByteVar>?)
@WasmImport("env", "_log_warn")
external fun _log_warn(msg: CPointer<ByteVar>?)
@WasmImport("env", "_log_critical")
external fun _log_critical(msg: CPointer<ByteVar>?)
@WasmImport("env", "_log_debug")
external fun _log_debug(msg: CPointer<ByteVar>?)


//// Functions ////

fun testGlobal(name: String) {
    val hostResult = _test_global(name.cstr)
    
}

fun global2Test() : Int {
    val hostResult = _global_2_test()
    hostResult
}

fun myTest(a: Byte, b: Short) : String {
    val hostResult = _my_test(a, b)
    val useMe = hostResult?.toKString() ?: error("null pointer returned")
    useMe
    
}


//// Classes ////
data class MyClass(val opaqu: ULong) {
    
    fun objectFunc(a: Short) {
        val hostResult = _my_class_object_func(this.opaqu, a)
        
    }
    
}
object Log {
    
    fun info(msg: String) {
        val hostResult = _log_info(msg.cstr)
        
    }
    
    fun warn(msg: String) {
        val hostResult = _log_warn(msg.cstr)
        
    }
    
    fun critical(msg: String) {
        val hostResult = _log_critical(msg.cstr)
        
    }
    
    fun debug(msg: String) {
        val hostResult = _log_debug(msg.cstr)
        
    }
    
}


