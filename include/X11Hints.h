#pragma once

#include "Defines.h"

#include <string_view>

namespace GLFW_WRAPPER_NAMESPACE
{
    struct X11HintsApi
    {
        [[nodiscard]] static X11HintsApi ClassName(std::string_view name);
        [[nodiscard]] static X11HintsApi InstanceName(std::string_view name);
    };
}