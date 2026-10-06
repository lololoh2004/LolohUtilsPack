#pragma once

#include <string_view>
#include <type_traits>
#include "lo_utils/c11/term/term_sys_wrap.h"
#include "lo_utils/c11/term/term_out.h"
#include "lo_utils/common/presets.h"

namespace term{

template <typename T = std::string_view>
void msg(T val = "DEBUG_TEXT", const char* entry = "???", rgb textColor = COLOR_DEFLT) {
    termSetTextClr(textColor);

    if constexpr      (std::is_same_v<T, const char*> || std::is_same_v<T, char*>)
        termMsgChar(val, entry);

    else if constexpr (std::is_same_v<T, std::string_view>)
        termMsgCharLen(val.data(), val.size(), entry);

    else if constexpr (std::is_same_v<T, std::string>)
        termMsgChar(val.c_str(), entry);

    else if constexpr (std::is_integral_v<T>)
        termMsgInt(static_cast<int>(val), entry);

    else if constexpr (std::is_floating_point_v<T>)
        termMsgFloat(static_cast<float>(val), entry);

    else if constexpr (std::is_pointer_v<T>)
        termMsgPtr(val, entry);

    else
        static_assert(sizeof(T) == 0, "This type isnt supported in termMsg!");

    termResetTextClr();
}

inline void clear(modePriority mode = TYPE_OPTI) {
    termClear(mode);
}

inline void wait(const char* text = "Press ENTER to continue..\n") {
    termWait(text);
}

}