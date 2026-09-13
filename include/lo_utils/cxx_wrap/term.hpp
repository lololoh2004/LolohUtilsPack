#pragma once

#include <type_traits>
#include "lo_utils/term.h"
#include "lo_utils/common/presets.h"

namespace term{

template <typename T>
void msg(T val, const char* entry = "???", rgb textColor = COLOR_DEFLT) {
    termSetTextClr(textColor);
    if constexpr (std::is_integral_v<T>)            termMsgInt(static_cast<int>(val), entry);
    else if constexpr (std::is_floating_point_v<T>) termMsgFloat(static_cast<float>(val), entry);
    else if constexpr (std::is_pointer_v<T>)        termMsgPtr(val, entry);
    else                                            static_assert(sizeof(T) == 0, "This type isnt supported in termMsg!");
    termResetTextClr();
}

inline void msg(const char* text = "DEBUG TEXT", const char* entry = "???", rgb textColor = COLOR_DEFLT) {
    termSetTextClr(textColor);
    termMsgChar(text, entry);
    termResetTextClr();
}

inline void clear(modePriority mode = TYPE_OPTI) {
    ::termClear(mode);
}

inline void wait(const char* text = "Press ENTER to continue..\n") {
    ::termWait(text);
}

}