#pragma once

#include "common/defines.h"
#include <stddef.h>

LOUTILS_API size_t getTableCount_toml(const char* content);
LOUTILS_API size_t getTomlTableSize(const char* tomlContent, const char* name);
