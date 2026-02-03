@Suppress("unused")
@OptIn(ExperimentalWasmInterop::class)
@WasmExport(name = "on_load")
fun onLoad() {
}

@Suppress("unused")
@OptIn(ExperimentalWasmInterop::class)
@WasmExport(name = "on_update")
fun onUpdate() {
}

@Suppress("unused")
@OptIn(ExperimentalWasmInterop::class)
@WasmExport(name = "on_exit")
fun onExit() {}
