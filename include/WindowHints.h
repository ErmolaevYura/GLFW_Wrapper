#pragma once

#include "Defines.h"

#include <optional>

namespace GLFW_WRAPPER_NAMESPACE
{
    struct WindowHints
    {
        std::optional<bool> Visible{};
        std::optional<bool> Focused{};
        std::optional<bool> Resizable{};
        std::optional<bool> Decorated{};
        std::optional<bool> AutoIconify{};
        std::optional<bool> Floating{};
        std::optional<bool> Maximized{};
        std::optional<bool> CenterCursor{};
        std::optional<bool> TransparentFramebuffer{};
        std::optional<bool> FocusOnShow{};
        std::optional<bool> ScaleToMonitor{};

        [[nodiscard]] static WindowHints Default()
        {
            WindowHints hint;
            hint.Visible = true;
            hint.Focused = true;
            hint.Resizable = true;
            hint.Decorated = true;
            hint.AutoIconify = true;
            hint.Floating = false;
            hint.Maximized = false;
            hint.CenterCursor = true;
            hint.TransparentFramebuffer = false;
            hint.FocusOnShow = true;
            hint.ScaleToMonitor = false;
            return hint;
        }
    };

    struct WindowHintsApi
    {
        static void Apply(const WindowHints& hints);
        static WindowHintsApi Focused(bool focused = true);
        static WindowHintsApi Resizable(bool resizable = true);
        static WindowHintsApi Visible(bool visible = true);
        static WindowHintsApi Decorated(bool decorated = true);
        static WindowHintsApi AutoIconify(bool autoIconify = true);
        static WindowHintsApi Floating(bool floating = false);
        static WindowHintsApi Maximized(bool maximized = false);
        static WindowHintsApi CenterCursor(bool centerCursor = true);
        static WindowHintsApi TransparentFramebuffer(bool transparent = false);
        static WindowHintsApi FocusOnShow(bool focusOnShow = true);
        static WindowHintsApi ScaleToMonitor(bool scaleToMonitor = false);
    };
}