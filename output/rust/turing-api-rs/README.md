# turing-api

Rust bindings for the **Turing mod scripting API** for **Beat Saber**.

This library is intended to be used with the Turing mod and
relies on assumptions about the WASM runtime environment provided by Turing.
It is not expected to function in other contexts.

Crates using this library are typically expected to represent end-user
scripts or higher-level abstractions over the Turing API.

This API strictly follows semantic versioning, consistent with the versioning used by the Turing mod itself.
