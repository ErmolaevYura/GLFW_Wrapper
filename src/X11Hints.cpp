#include "pch.h"
#include "../include/X11Hints.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    X11HintsApi X11HintsApi::ClassName(std::string_view name)
    {
        glfwWindowHintString(GLFW_X11_CLASS_NAME, name.data());
        return {};
    }

    X11HintsApi X11HintsApi::InstanceName(std::string_view name)
    {
        glfwWindowHintString(GLFW_X11_INSTANCE_NAME, name.data());
        return {};
    }
}