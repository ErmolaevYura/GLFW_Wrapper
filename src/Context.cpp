#include "pch.h"
#include "../include/Context.h"
#include "../include/Window.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    void MakeContextCurrent(Window& window)
    {
        glfwMakeContextCurrent(window);
    }

    Window GetCurrentContext()
    {
        return { glfwGetCurrentContext() };
    }

    void SwapInterval(int32_t interval)
    {
        glfwSwapInterval(interval);
    }

    bool ExtensionSupported(std::string_view extension)
    {
        return glfwExtensionSupported(extension.data());
    }

    GLProc GetProcAddress(const char* name)
    {
        return glfwGetProcAddress(name);
    }
}