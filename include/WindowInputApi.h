#pragma once

#include "Cursor.h"
#include "Enums.h"

#include <string_view>
#include <array>

struct GLFWwindow;

namespace GLFW_WRAPPER_NAMESPACE
{
    class InputApi
    {
    public:
        InputApi(GLFWwindow* window)
            : m_window(window)
        {
        }

        [[nodiscard]] CursorMode GetCursorMode() const;

        void SetCursorMode(CursorMode mode) const;

        [[nodiscard]] bool GetStickyKeysMode() const;

        void SetStickyKeysMode(bool enable) const;

        [[nodiscard]] bool GetStickyMouseMode() const;

        void SetStickyMouseMode(bool enable) const;

        [[nodiscard]] bool GetLockKeysMode() const;

        void SetLockKeysMode(bool enable) const;

        [[nodiscard]] bool GetRawMouseMode() const;

        void SetRawMouseMode(bool enable) const;

        [[nodiscard]] KeyState GetKey(KeyId key) const;

        [[nodiscard]] KeyState GetMouseButton(MouseKeyId key) const;

        [[nodiscard]] std::array<double, 2> GetCursorPos() const;

        void SetCursorPos(std::array<double, 2> pos) const;

        void SetCursor(Cursor cursor) const;

        [[nodiscard]] std::string_view GetClipboard() const;

        void SetClipboard(std::string_view str) const;

    private:
        GLFWwindow* m_window;
    };
}