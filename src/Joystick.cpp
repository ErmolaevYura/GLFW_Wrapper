#include "pch.h"
#include "../include/Joystick.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    bool Joystick::UpdateGamepadMappings(std::string_view str)
    {
        return glfwUpdateGamepadMappings(str.data());
    }

    bool Joystick::Present() const
    {
        return glfwJoystickPresent(static_cast<int>(m_id));
    }

    std::vector<float> Joystick::GetAxes() const
    {
        int count{};
        const auto* values = glfwGetJoystickAxes(static_cast<int>(m_id), &count);
        std::vector<float> axes;
        for (decltype(count) i = 0; i < count; ++i)
        {
            if (values + i != nullptr)
                axes.emplace_back(values[i]);
            else
                axes.emplace_back(std::numeric_limits<float>::min());
        }
        return axes;
    }

    std::vector<KeyState> Joystick::GetButtons() const
    {
        int count{};
        const auto* buttonsRaw = glfwGetJoystickButtons(static_cast<int>(m_id), &count);
        std::vector<KeyState> buttons;
        for (decltype(count) i = 0; i < count; ++i)
        {
            if (buttonsRaw + i != nullptr)
                buttons.emplace_back(static_cast<KeyState>(buttonsRaw[i]));
            else
                buttons.emplace_back(KeyState::Undefined);
        }
        return buttons;
    }

    std::vector<JoystickHat> Joystick::GetHats() const
    {
        int count{};
        const auto* hatsRaw = glfwGetJoystickHats(static_cast<int>(m_id), &count);
        std::vector<JoystickHat> hats;
        for (decltype(count) i = 0; i < count; ++i)
        {
            if (hatsRaw + i != nullptr)
                hats.emplace_back(static_cast<JoystickHat>(hatsRaw[i]));
            else
                hats.emplace_back(JoystickHat::Undefined);
        }
        return hats;
    }

    std::string_view Joystick::GetName() const
    {
        return glfwGetJoystickName(static_cast<int>(m_id));
    }

    std::string_view Joystick::GetGUID() const
    {
        return glfwGetJoystickName(static_cast<int>(m_id));
    }

    void Joystick::SetUserPointer(void* pointer) const
    {
        glfwSetJoystickUserPointer(static_cast<int>(m_id), pointer);
    }

    void* Joystick::GetUserPointer() const
    {
        return glfwGetJoystickUserPointer(static_cast<int>(m_id));
    }

    bool Joystick::IsGamepad() const
    {
        return glfwJoystickIsGamepad(static_cast<int>(m_id));
    }

    std::string_view Joystick::GetGamepadName() const
    {
        return glfwGetGamepadName(static_cast<int>(m_id));
    }

    GamepadState Joystick::GetGamepadState() const
    {
        GLFWgamepadstate* state{ nullptr };
        glfwGetGamepadState(static_cast<int>(m_id), state);
        return state;
    }

    JoystickCallback Joystick::SetJoystickCallback(JoystickCallback func)
    {
        return glfwSetJoystickCallback(func);
    }
}