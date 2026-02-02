
///// Raw Wasm Bindings /////

// Note on using this file directly:
// Some types cannot properly be passed across FFI
// such as strings and structs.
// Due to this, there are mechanisms in place to
// transfer those data types, such as `_host_strcpy`,
// `_host_f32_enqueue`, etc...
// The places where these mechanisms are meant to be used
// may be poorly documented within this file

#pragma once

#ifdef __cplusplus
extern "C" {
#endif


    //// Core functions ////

    /// When a string is to be passed from the host to wasm,
    /// it instead returns it's length, including the NUL terminator.
    /// The wasm is responsible for allocating that space and then
    /// calling this function, passing the pointer to the allocated
    /// space, and the size received.
    void _host_strcpy(const char* location, uint32_t size);
    
    /// This function allows types such as Vec3 and Mat4 to be passed back and forth
    void _host_f32_enqueue(float f);
    
    /// Inverted behavior to `_host_f32_enqueue`
    float _host_f32_dequeue();
    
    /// Same as `_host_f32_enqueue` but bit-casts u32 into it instead
    void _host_u32_enqueue(uint32_t u);
    
    /// Same as `_host_f32_dequeue` but bit-casts to u32 before returning
    uint32_t _host_u32_dequeue();
    









//// Global Functions ////

    
    Something _do_thing(
    
        Random random
        
    
)



//// Classes ////

    void _log__debug(
    
        const char* msg
        
    
)

    void _log__critical(
    
        const char* msg
        
    
)

    void _log__warn(
    
        const char* msg
        
    
)

    void _log__info(
    
        const char* msg
        
    
)

    void _vivify__upload_buffer(
    
        const void* buf
        
    
)

    uint32_t _vivify__get_buffer(
    
)



#ifdef __cplusplus
%}
#endif

