#include "pch.h"
#include "../include/WindowInputApi.h"
#include "../include/EventHandler.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    CursorMode InputApi::GetCursorMode() const
    {
        return CursorMode{ glfwGetInputMode(m_window, GLFW_CURSOR) };
    }

    void InputApi::SetCursorMode(CursorMode mode) const
    {
        glfwSetInputMode(m_window, GLFW_CURSOR, static_cast<int>(mode));
    }

    bool InputApi::GetStickyKeysMode() const
    {
        return glfwGetInputMode(m_window, GLFW_STICKY_KEYS);
    }

    void InputApi::SetStickyKeysMode(bool enable) const
    {
        glfwSetInputMode(m_window, GLFW_STICKY_KEYS, enable);
    }

    bool InputApi::GetStickyMouseMode() const
    {
        return glfwGetInputMode(m_window, GLFW_STICKY_MOUSE_BUTTONS);
    }

    void InputApi::SetStickyMouseMode(bool enable) const
    {
        glfwSetInputMode(m_window, GLFW_STICKY_MOUSE_BUTTONS, enable);
    }

    bool InputApi::GetLockKeysMode() const
    {
        return glfwGetInputMode(m_window, GLFW_LOCK_KEY_MODS);
    }

    void InputApi::SetLockKeysMode(bool enable) const
    {
        glfwSetInputMode(m_window, GLFW_LOCK_KEY_MODS, enable);
    }

    bool InputApi::GetRawMouseMode() const
    {
        return glfwGetInputMode(m_window, GLFW_RAW_MOUSE_MOTION);
    }

    void InputApi::SetRawMouseMode(bool enable) const
    {
        glfwSetInputMode(m_window, GLFW_RAW_MOUSE_MOTION, enable);
    }

    KeyState InputApi::GetKey(KeyId key) const
    {
        return KeyState{ glfwGetKey(m_window, static_cast<int>(key)) };
    }

    KeyState InputApi::GetMouseButton(MouseKeyId key) const
    {
        return KeyState{ glfwGetMouseButton(m_window, static_cast<int>(key)) };
    }

    std::array<double, 2> InputApi::GetCursorPos() const
    {
        std::array<double, 2> pos{};
        glfwGetCursorPos(m_window, &pos[0], &pos[1]);
        return pos;
    }

    void InputApi::SetCursorPos(std::array<double, 2> pos) const
    {
        glfwSetCursorPos(m_window, pos[0], pos[1]);
    }

    void InputApi::SetCursor(Cursor cursor) const
    {
        glfwSetCursor(m_window, cursor);
    }

    void InputApi::SetClipboard(std::string_view str) const
    {
        glfwSetClipboardString(m_window, str.data());
    }

    std::string_view InputApi::GetClipboard() const
    {
        return { glfwGetClipboardString(m_window) };
    }
}