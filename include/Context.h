#pragma once

#include "Defines.h"
#include <string_view>

namespace GLFW_WRAPPER_NAMESPACE
{
    using GLProc = void(*)();

    class Window;

    void MakeContextCurrent(Window& window);

    [[nodiscard]] Window GetCurrentContext();

    void SwapInterval(int32_t interval);

    [[nodiscard]] bool ExtensionSupported(std::string_view extension);

    [[nodiscard]] GLProc GetProcAddress(const char* name);
}