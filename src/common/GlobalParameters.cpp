/**
 * @file GlobalParameters.cpp
 * @brief Global parameters initialization
 */

#include "../../include/utils/GlobalParameters.h"
#include "../../include/enums/CompiledOS.h"

#ifdef _WIN32
CompiledOS GlobalParameters::environment = CompiledOS::WINDOWS;
#elif __linux__
CompiledOS GlobalParameters::environment = CompiledOS::LINUX;
#elif __APPLE__
CompiledOS GlobalParameters::environment = CompiledOS::MAC;
#else
CompiledOS GlobalParameters::environment = CompiledOS::LINUX;
#endif

bool GlobalParameters::is_running_on_windows() {
    return environment == CompiledOS::WINDOWS;
}

bool GlobalParameters::is_running_on_linux() {
    return environment == CompiledOS::LINUX;
}
