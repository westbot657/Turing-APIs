@file:OptIn(
    kotlin.wasm.ExperimentalWasmInterop::class,
)
@file:Suppress("Unused")

///// Generated Kotlin API /////

import kotlinx.cinterop.*
import kotlin.native.concurrent.*

//// Wasm Bindings ////
@WasmImport("env", "_host_strcpy")
external fun _host_strcpy(location: CPointer<ByteVar>?, size: UInt)
@WasmImport("env", "_host_f32_enqueue")
external fun _host_f32_enqueue(f: Float);
@WasmImport("env", "_host_f32_dequeue")
external fun _host_f32_dequeue() : Float;
@WasmImport("env", "_test_global")
external fun _test_global(name: CPointer<ByteVar>?)
@WasmImport("env", "_global_2_test")
external fun _global_2_test(): Int
@WasmImport("env", "_my_test")
external fun _my_test(a: Byte, b: Short): CPointer<ByteVar>?
@WasmImport("env", "_my_class_object_func")
external fun _my_class_object_func(opaqu: Int, a: Short)
@WasmImport("env", "_color_note_set_position")
external fun _color_note_set_position(opaqu: Int, x: Float, y: Float, z: Float): Unit
@WasmImport("env", "_color_note_set_orientation")
external fun _color_note_set_orientation(opaqu: Int, x: Float, y: Float, z: Float, w: Float): Unit
@WasmImport("env", "_color_note_clone")
external fun _color_note_clone(opaqu: Int): ColorNote
@WasmImport("env", "_log_info")
external fun _log_info(msg: CPointer<ByteVar>?)
@WasmImport("env", "_log_warn")
external fun _log_warn(msg: CPointer<ByteVar>?)
@WasmImport("env", "_log_critical")
external fun _log_critical(msg: CPointer<ByteVar>?)
@WasmImport("env", "_log_debug")
external fun _log_debug(msg: CPointer<ByteVar>?)


@WasmExport(name = "_turing_api_semver")
fun _turing_api_semver() : ULong {
    (0uL shl 16) or (8uL shl 8) or 0uL
}

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
/// this is line 1
/// this is line 2
data class ColorNote(val opaqu: ULong) {

    fun setPosition(x: Float, y: Float, z: Float) : ColorNote {
        val hostResult = _color_note_set_position(this.opaqu, x, y, z)
        this
    }

    fun setOrientation(x: Float, y: Float, z: Float, w: Float) : ColorNote {
        val hostResult = _color_note_set_orientation(this.opaqu, x, y, z, w)
        this
    }

    fun clone() : ColorNote {
        val hostResult = _color_note_clone(this.opaqu)
        ColorNote(opaqu = hostResult)
    }
}
/// used to log messages to the console
/// idk, this is a second line
object Log {
    /// logs `msg` to the console
    fun info(msg: String) {
        val hostResult = _log_info(msg.cstr)
    }
    /// logs `msg` to the console as a warning
    fun warn(msg: String) {
        val hostResult = _log_warn(msg.cstr)
    }
    /// logs `msg` to the console as an error
    fun critical(msg: String) {
        val hostResult = _log_critical(msg.cstr)
    }
    /// logs `msg` to the console when in debug mode
    fun debug(msg: String) {
        val hostResult = _log_debug(msg.cstr)
    }
}

