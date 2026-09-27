#include "lo_utils/c11/dyn_libs.h"
#include "lo_utils/c11/term.h"

#ifdef _WIN32
    #include <windows.h>
    #define DL_CLOSE(h_inst) FreeLibrary(h_inst)
#else
    #include <dlfcn.h>
    #define DL_CLOSE(h_inst) dlclose(h_inst)
#endif


void freeDLHandle(DL_HANDLE handle) {
    if (handle) {
        DL_CLOSE(handle);
    }
}