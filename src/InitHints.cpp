#include "pch.h"
#include "../include/InitHints.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    InitHintsApi InitHintsApi::JoystickHatButtons(bool hatButton)
    {
        glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, hatButton);
        return {};
    }

    InitHintsApi InitHintsApi::MacCocoaChdirResources(bool chdirResource)
    {
        glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, chdirResource);
        return {};
    }

    InitHintsApi InitHintsApi::MacCocoaMenubar(bool menubar)
    {
        glfwInitHint(GLFW_COCOA_MENUBAR, menubar);
        return {};
    }
}