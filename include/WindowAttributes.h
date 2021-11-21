#pragma once

#include "Defines.h"

typedef GLFWwindow GLFWwindow;

namespace GLFW_WRAPPER_NAMESPACE
{
    class WindowAttributes
    {
    public:
        WindowAttributes(GLFWwindow* window = nullptr)
            : m_window(window)
        {
        }

        [[nodiscard]] bool Focus() const;
        [[nodiscard]] bool Iconified() const;
        [[nodiscard]] bool Maximized() const;
        [[nodiscard]] bool Hovered() const;
        [[nodiscard]] bool Visible() const;
        [[nodiscard]] bool Resizable() const;
        [[nodiscard]] bool Decorated() const;
        [[nodiscard]] bool AutoIconify() const;
        [[nodiscard]] bool Floating() const;
        [[nodiscard]] bool TransparentFramebuffer() const;
        [[nodiscard]] bool FocusOnShow() const;

        WindowAttributes& Focus(bool focus);
        WindowAttributes& Iconified(bool iconified);
        WindowAttributes& Maximized(bool maximized);
        WindowAttributes& Hovered(bool hovered);
        WindowAttributes& Visible(bool visible);
        WindowAttributes& Resizable(bool resizable);
        WindowAttributes& Decorated(bool decorated);
        WindowAttributes& AutoIconify(bool autoIconify);
        WindowAttributes& Floating(bool floating);
        WindowAttributes& TransparentFramebuffer(bool transparent);
        WindowAttributes& FocusOnShow(bool focusOnShow);

    private:
        GLFWwindow* m_window;
    };
}