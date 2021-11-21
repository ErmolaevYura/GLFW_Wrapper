#pragma once

#include "Defines.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    struct InitHintsApi
    {
        static InitHintsApi JoystickHatButtons(bool hatButton);
        static InitHintsApi MacCocoaChdirResources(bool chdirResource);
        static InitHintsApi MacCocoaMenubar(bool menubar);
    };
}