#include "pch.h"
#include "../include/WindowAttributes.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    bool WindowAttributes::Focus() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_FOCUSED);
    }

    bool WindowAttributes::Iconified() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_ICONIFIED);
    }

    bool WindowAttributes::Maximized() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_MAXIMIZED);
    }

    bool WindowAttributes::Hovered() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_HOVERED);
    }

    bool WindowAttributes::Visible() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_VISIBLE);
    }

    bool WindowAttributes::Resizable() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_RESIZABLE);
    }

    bool WindowAttributes::Decorated() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_DECORATED);
    }

    bool WindowAttributes::AutoIconify() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_AUTO_ICONIFY);
    }

    bool WindowAttributes::Floating() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_FLOATING);
    }

    bool WindowAttributes::TransparentFramebuffer() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_TRANSPARENT_FRAMEBUFFER);
    }

    bool WindowAttributes::FocusOnShow() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_FOCUS_ON_SHOW);
    }

    WindowAttributes& WindowAttributes::Focus(bool focus)
    {
        glfwSetWindowAttrib(m_window, GLFW_FOCUSED, focus); return *this;
    }

    WindowAttributes& WindowAttributes::Iconified(bool iconified)
    {
        glfwSetWindowAttrib(m_window, GLFW_ICONIFIED, iconified);
        return *this;
    }

    WindowAttributes& WindowAttributes::Maximized(bool maximized)
    {
        glfwSetWindowAttrib(m_window, GLFW_MAXIMIZED, maximized);
        return *this;
    }

    WindowAttributes& WindowAttributes::Hovered(bool hovered)
    {
        glfwSetWindowAttrib(m_window, GLFW_HOVERED, hovered);
        return *this;
    }

    WindowAttributes& WindowAttributes::Visible(bool visible)
    {
        glfwSetWindowAttrib(m_window, GLFW_VISIBLE, visible);
        return *this;
    }

    WindowAttributes& WindowAttributes::Resizable(bool resizable)
    {
        glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, resizable);
        return *this;
    }

    WindowAttributes& WindowAttributes::Decorated(bool decorated)
    {
        glfwSetWindowAttrib(m_window, GLFW_DECORATED, decorated);
        return *this;
    }

    WindowAttributes& WindowAttributes::AutoIconify(bool autoIconify)
    {
        glfwSetWindowAttrib(m_window, GLFW_AUTO_ICONIFY, autoIconify);
        return *this;
    }

    WindowAttributes& WindowAttributes::Floating(bool floating)
    {
        glfwSetWindowAttrib(m_window, GLFW_FLOATING, floating);
        return *this;
    }

    WindowAttributes& WindowAttributes::TransparentFramebuffer(bool transparent)
    {
        glfwSetWindowAttrib(m_window, GLFW_TRANSPARENT_FRAMEBUFFER, transparent);
        return *this;
    }

    WindowAttributes& WindowAttributes::FocusOnShow(bool focusOnShow)
    {
        glfwSetWindowAttrib(m_window, GLFW_FOCUS_ON_SHOW, focusOnShow);
        return *this;
    }
}