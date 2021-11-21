#include "pch.h"
#include "../include/GLFW_Wrapper.h"

#include <sstream>

namespace GLFW_WRAPPER_NAMESPACE
{
    GlfwVersion GetCompileVersion()
    {
        return { GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION };
    }

    GlfwVersion GetVersion()
    {
        GlfwVersion version{};
        glfwGetVersion(&version.Major, &version.Minor, &version.Revision);
        return version;
    }

    std::string_view GetVersionString()
    {
        return { glfwGetVersionString() };
    }

    ErrorCode GetError(std::string_view description)
    {
        const auto* ptr = description.data();
        return ErrorCode{ glfwGetError(&ptr) };
    }

    ErrorCallback SetErrorCallback(ErrorCallback errorCallback)
    {
        return glfwSetErrorCallback(errorCallback);
    }

    void DefaultHints()
    {
        glfwDefaultWindowHints();
    }

    bool Init()
    {
        return bool{ glfwInit() == GL_TRUE };
    }

    void Terminate()
    {
        glfwTerminate();
    }
}

std::wostream& operator<<(std::wostream& os, GLFW_WRAPPER_NAMESPACE::GlfwVersion version)
{
    os << std::to_wstring(version.Major)
        << L"." << std::to_wstring(version.Minor)
        << L"." << std::to_wstring(version.Revision);
    return os;
}