#pragma once

#include "Defines.h"

#include <string_view>

namespace GLFW_WRAPPER_NAMESPACE
{
    struct MacHintsApi
    {
        static MacHintsApi CocoaRetinaFramebuffer(bool retinaFramebuffer = true);
        static MacHintsApi CocoaFrameName(std::string_view name);
        static MacHintsApi CocoaGraphicsSwitching(bool graphicsSwitching = false);
    };
}