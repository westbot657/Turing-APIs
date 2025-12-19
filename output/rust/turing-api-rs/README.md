# turing-api

Rust bindings for the **Turing mod scripting API** for **Beat Saber**.

This library is intended to be used with the Turing mod and
relies on assumptions about the WASM runtime environment provided by Turing.
It is not expected to function in other contexts.

Crates using this library are typically expected to represent end-user
scripts or higher-level abstractions over the Turing API.

This API strictly follows semantic versioning, consistent with the versioning used by the Turing mod itself.

---

## Licensing note

This crate is licensed under **GPL-2.0-only**.

Scope:
- This license applies only to this crate and its framework/API code.
- End-user scripts executed by Turing-compatible runtimes are **not considered derivative works** and are not subject to GPL licensing.
- Hosts of the API (Turing.rs, C# Turinger, and other runtimes) are **exempt** from this license.
- Libraries or frameworks that wrap or re-abstract this crate are considered derivative works and must comply with GPL-2.0 or a compatible license.

The intent of this clarification is to make clear that this license governs the script API and framework layer, while leaving host runtimes and end-user content free.
