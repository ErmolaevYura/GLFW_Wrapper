#include "pch.h"
#include "../include/ContextAttributes.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    ClientApiValue ContextAttributes::ClientApi() const
    {
        return ClientApiValue{ glfwGetWindowAttrib(m_window, GLFW_CLIENT_API) };
    }

    ContextCreationApiValue ContextAttributes::ContextCreationApi() const
    {
        return ContextCreationApiValue{ glfwGetWindowAttrib(m_window, GLFW_CONTEXT_CREATION_API) };
    }

    int ContextAttributes::ContextVersionMajor() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_CONTEXT_VERSION_MAJOR);
    }

    int ContextAttributes::ContextVersionMinor() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_CONTEXT_VERSION_MINOR);
    }

    int ContextAttributes::ContextRevision() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_CONTEXT_REVISION);
    }

    bool ContextAttributes::OpenGlForwardCompat() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_OPENGL_FORWARD_COMPAT);
    }

    bool ContextAttributes::OpenGlDebugContext() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_OPENGL_DEBUG_CONTEXT);
    }

    OpenGlProfileValue ContextAttributes::OpenGlProfile() const
    {
        return OpenGlProfileValue{ glfwGetWindowAttrib(m_window, GLFW_OPENGL_PROFILE) };
    }

    ContextRobustnessValue ContextAttributes::ContextRobustness() const
    {
        return ContextRobustnessValue{ glfwGetWindowAttrib(m_window, GLFW_CONTEXT_ROBUSTNESS) };
    }

    ContextAttributes& ContextAttributes::ClientApi(ClientApiValue clientApi)
    {
        glfwSetWindowAttrib(m_window, GLFW_FOCUS_ON_SHOW, static_cast<int>(clientApi));
        return *this;
    }

    ContextAttributes& ContextAttributes::ContextCreationApi(ContextCreationApiValue creationApi)
    {
        glfwSetWindowAttrib(m_window, GLFW_FOCUS_ON_SHOW, static_cast<int>(creationApi));
        return *this;
    }

    ContextAttributes& ContextAttributes::ContextVersionMajor(int major)
    {
        glfwSetWindowAttrib(m_window, GLFW_CONTEXT_VERSION_MAJOR, major);
        return *this;
    }

    ContextAttributes& ContextAttributes::ContextVersionMinor(int minor)
    {
        glfwSetWindowAttrib(m_window, GLFW_CONTEXT_VERSION_MINOR, minor);
        return *this;
    }

    ContextAttributes& ContextAttributes::ContextRevision(int revision)
    {
        glfwSetWindowAttrib(m_window, GLFW_CONTEXT_REVISION, revision);
        return *this;
    }

    ContextAttributes& ContextAttributes::OpenGlForwardCompat(bool compat)
    {
        glfwSetWindowAttrib(m_window, GLFW_OPENGL_FORWARD_COMPAT, compat);
        return *this;
    }

    ContextAttributes& ContextAttributes::OpenGlDebugContext(bool debug)
    {
        glfwSetWindowAttrib(m_window, GLFW_OPENGL_DEBUG_CONTEXT, debug);
        return *this;
    }

    ContextAttributes& ContextAttributes::OpenGlProfile(OpenGlProfileValue profile)
    {
        glfwSetWindowAttrib(m_window, GLFW_OPENGL_PROFILE, static_cast<int>(profile));
        return *this;
    }

    ContextAttributes& ContextAttributes::ContextRobustness(ContextRobustnessValue robustness)
    {
        glfwSetWindowAttrib(m_window, GLFW_CONTEXT_ROBUSTNESS, static_cast<int>(robustness));
        return *this;
    }
}