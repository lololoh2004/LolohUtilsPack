#include "lo_utils/c11/dyn_libs.h"
#include "../../../include/lo_utils/c11/term/term_sys_wrap.h"

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    #define DL_OPEN(path) LoadLibraryA(path)
    #define DL_GET_PTR(h_inst, func_name) (void*)GetProcAddress((HMODULE)(h_inst), func_name)
    #define DL_ERROR() GetLastError()
    #define DL_CLOSE(h_inst) FreeLibrary(h_inst)
#else
    #include <dlfcn.h>
    #define DL_OPEN(path) dlopen(path, RTLD_LAZY)
    #define DL_GET_PTR(h_inst, func_name) dlsym(h_inst, func_name)
    #define DL_ERROR() dlerror()
    #define DL_CLOSE(h_inst) dlclose(h_inst)

    #include <stddef.h>
#endif


DL_HANDLE getDLHandle(const char* path){
    if (path == NULL) return NULL;

    DL_HANDLE handle = DL_OPEN(path);
    if (!handle){
        termMsgChar("Dynamic lib handle is null !\n", "[DLIB]");
        return NULL;
    }
    return handle;
}
void* getDLFuncPtr(DL_HANDLE handle, const char* func_name){
    if (!handle || !func_name) return NULL;

    void* ptr = (void*)DL_GET_PTR(handle, func_name);
    if (!ptr) {
        termMsgChar("Failed to get function pointer in dynlib\n", "[DLIB]");
    }

    return DL_GET_PTR(handle, func_name);
}