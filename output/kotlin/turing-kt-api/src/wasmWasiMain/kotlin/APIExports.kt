@file:OptIn(
    kotlin.wasm.ExperimentalWasmInterop::class,
)
@file:Suppress("Unused")

// Generated Kotlin WASI (no-macro) template
// This variant avoids Tera macro calls to improve compatibility with the
// templates executed by the generator.

// Kotlin WASI template (naming adapted to Kotlin conventions)
// - Kotlin functions and parameters use lowerCamelCase
// - Kotlin classes and types use PascalCase

import kotlinx.cinterop.*
import kotlin.native.concurrent.*

// host helper to copy string bytes from host memory into guest buffer
@WasmImport("turing_api", "_host_strcpy")
external fun _host_strcpy(location: CPointer<ByteVar>?, size: Int)

// FFI imports for global functions

@WasmImport("turing_api", "_test_global")
external fun _test_global(name: CPointer<ByteVar>?)

@WasmImport("turing_api", "_global_2_test")
external fun _global_2_test(): Int

@WasmImport("turing_api", "_my_test")
external fun _my_test(a: Byte, b: Short): CPointer<ByteVar>?


// FFI imports for classes



@WasmImport("turing_api", "_my_class_object_func")
external fun _my_class_object_func(opaqu: Int, a: Short)



@WasmImport("turing_api", "_log_info")
external fun _log_info(msg: CPointer<ByteVar>?)

@WasmImport("turing_api", "_log_warn")
external fun _log_warn(msg: CPointer<ByteVar>?)

@WasmImport("turing_api", "_log_critical")
external fun _log_critical(msg: CPointer<ByteVar>?)

@WasmImport("turing_api", "_log_debug")
external fun _log_debug(msg: CPointer<ByteVar>?)




//// Functions ////

@WasmExport("testGlobal")
fun testGlobal(name: String) {
    
    
    // pass Kotlin string as C string using `.cstr`
    // (the FFI import expects `CPointer<ByteVar>?`)
    
    

    // call the host function; string params are passed as `.cstr`
    val hostResult = _test_global(name.cstr)

    
}

@WasmExport("global2Test")
fun global2Test() : Int {
    

    // call the host function; string params are passed as `.cstr`
    val hostResult = _global_2_test()

    
    hostResult
    
}

@WasmExport("myTest")
fun myTest(a: Byte, b: Short) : String {
    
    
    
    
    

    // call the host function; string params are passed as `.cstr`
    val hostResult = _my_test(a, b)

    
    // hostResult is a C string pointer; convert to Kotlin String
    val useMe = hostResult?.toKString() ?: error("null pointer returned")
    useMe
    
}


//// Classes ////

data class MyClass(val opaqu: Int)

object MyClassApi {
    

    
    @WasmExport("objectFunc")
    fun objectFunc(opaqu: Int, a: Short) {
        
        
        

        // call host; pass `self` or `opaqu` followed by params (string params use `.cstr`)
        val hostResult = _my_class_object_func(opaqu, a)

        
    }
    
}

data class Log(val opaqu: Int)

object LogApi {
    
    @WasmExport("info")
    fun info(msg: String) {
        
        
        // string param handling uses `.cstr` when calling host
        
        

        // call host; string params passed as `.cstr`
        val hostResult = _log_info(msg.cstr)

        
    }
    
    @WasmExport("warn")
    fun warn(msg: String) {
        
        
        // string param handling uses `.cstr` when calling host
        
        

        // call host; string params passed as `.cstr`
        val hostResult = _log_warn(msg.cstr)

        
    }
    
    @WasmExport("critical")
    fun critical(msg: String) {
        
        
        // string param handling uses `.cstr` when calling host
        
        

        // call host; string params passed as `.cstr`
        val hostResult = _log_critical(msg.cstr)

        
    }
    
    @WasmExport("debug")
    fun debug(msg: String) {
        
        
        // string param handling uses `.cstr` when calling host
        
        

        // call host; string params passed as `.cstr`
        val hostResult = _log_debug(msg.cstr)

        
    }
    

    
}


