#include "dyn_libs.h"
#include "term.h"

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    #define DL_OPEN(path) LoadLibraryA(path)
    #define DL_GET_PTR(h_inst, func_name) (void*)GetProcAddress((HMODULE)(h_inst), func_name)
#else
    #include <dlfcn.h>
    #define DL_OPEN(path) dlopen(path, RTLD_LAZY)
    #define DL_GET_PTR(h_inst, func_name) dlsym(h_inst, func_name)
#endif


DL_HANDLE getDLHandle(const char* path){
    DL_HANDLE handle = handle = DL_OPEN(path);
    if (!handle){
        termMsg("Dynamic lib handle is null!\n", "[DLIB]");
        return NULL;
    }
    return handle;
}
void* getDLFuncPtr(DL_HANDLE handle, const char* func_name){
    return DL_GET_PTR(handle, func_name);
}