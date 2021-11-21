#pragma once

#include "Enums.h"

#include <string_view>

namespace GLFW_WRAPPER_NAMESPACE
{
    using ErrorCallback = void(*)(int, const char*);

    struct GlfwVersion
    {
        int Major;
        int Minor;
        int Revision;
    };

    [[nodiscard]] GlfwVersion GetCompileVersion();

    [[nodiscard]] GlfwVersion GetVersion();

    [[nodiscard]] std::string_view GetVersionString();

    [[nodiscard]] ErrorCode GetError(std::string_view description);

    ErrorCallback SetErrorCallback(ErrorCallback errorCallback);

    void DefaultHints();

    bool Init();

    void Terminate();
}

std::wostream& operator<<(std::wostream& os, GLFW_WRAPPER_NAMESPACE::GlfwVersion version);