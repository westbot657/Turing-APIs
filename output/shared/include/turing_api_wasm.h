
//// Wasm Bindings ////

#ifdef __cplusplus
extern "C" {
#endif

void _host_strcpy(const char* location, uint32_t size);
void _test_global(const char* name);
int32_t _global_2_test();
uint32_t _my_test(int8_t a, int16_t b);



void _my_class_object_func(uint64_t opaqu, int16_t a);
void _log_info(const char* msg);
void _log_warn(const char* msg);
void _log_critical(const char* msg);
void _log_debug(const char* msg);


#ifdef __cplusplus
}
#endif
