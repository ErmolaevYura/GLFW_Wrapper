#include "pch.h"
#include "../include/MonitorHints.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    constexpr int DontCare()
    {
        return GLFW_DONT_CARE;
    }

    MonitorHintsApi MonitorHintsApi::RefreshRate(int value)
    {
        glfwWindowHint(GLFW_REFRESH_RATE, value);
        return {};
    }
}