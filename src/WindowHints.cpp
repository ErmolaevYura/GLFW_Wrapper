#include "pch.h"
#include "../include/WindowHints.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    void WindowHintsApi::Apply(const WindowHints& hints)
    {
        if (hints.Visible)
            Visible(*hints.Visible);
        if (hints.AutoIconify)
            AutoIconify(*hints.AutoIconify);
        if (hints.CenterCursor)
            CenterCursor(*hints.CenterCursor);
        if (hints.Decorated)
            Decorated(*hints.Decorated);
        if (hints.Floating)
            Floating(*hints.Floating);
        if (hints.Focused)
            Focused(*hints.Focused);
        if (hints.FocusOnShow)
            FocusOnShow(*hints.FocusOnShow);
        if (hints.Maximized)
            Maximized(*hints.Maximized);
        if (hints.Resizable)
            Resizable(*hints.Resizable);
        if (hints.ScaleToMonitor)
            ScaleToMonitor(*hints.ScaleToMonitor);
        if (hints.TransparentFramebuffer)
            TransparentFramebuffer(*hints.TransparentFramebuffer);
    }

    WindowHintsApi WindowHintsApi::Focused(bool focused)
    {
        glfwWindowHint(GLFW_FOCUSED, focused);
        return {};
    }

    WindowHintsApi WindowHintsApi::Resizable(bool resizable)
    {
        glfwWindowHint(GLFW_RESIZABLE, resizable);
        return {};
    }

    WindowHintsApi WindowHintsApi::Visible(bool visible)
    {
        glfwWindowHint(GLFW_VISIBLE, visible);
        return {};
    }

    WindowHintsApi WindowHintsApi::Decorated(bool decorated)
    {
        glfwWindowHint(GLFW_DECORATED, decorated);
        return {};
    }

    WindowHintsApi WindowHintsApi::AutoIconify(bool autoIconify)
    {
        glfwWindowHint(GLFW_AUTO_ICONIFY, autoIconify);
        return {};
    }

    WindowHintsApi WindowHintsApi::Floating(bool floating)
    {
        glfwWindowHint(GLFW_FLOATING, floating);
        return {};
    }

    WindowHintsApi WindowHintsApi::Maximized(bool maximized)
    {
        glfwWindowHint(GLFW_MAXIMIZED, maximized);
        return {};
    }

    WindowHintsApi WindowHintsApi::CenterCursor(bool centerCursor)
    {
        glfwWindowHint(GLFW_CENTER_CURSOR, centerCursor);
        return {};
    }

    WindowHintsApi WindowHintsApi::TransparentFramebuffer(bool transparent)
    {
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, transparent);
        return {};
    }

    WindowHintsApi WindowHintsApi::FocusOnShow(bool focusOnShow)
    {
        glfwWindowHint(GLFW_FOCUS_ON_SHOW, focusOnShow);
        return {};
    }

    WindowHintsApi WindowHintsApi::ScaleToMonitor(bool scaleToMonitor)
    {
        glfwWindowHint(GLFW_SCALE_TO_MONITOR, scaleToMonitor);
        return {};
    }
}