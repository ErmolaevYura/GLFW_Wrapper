#pragma once

#include "Enums.h"
#include "GamepadState.h"

#include <string_view>
#include <vector>

namespace GLFW_WRAPPER_NAMESPACE
{
    using JoystickCallback = void(*)(int, int);

    class Joystick
    {
    public:
        static bool UpdateGamepadMappings(std::string_view str);

        Joystick(JoystickId id)
            : m_id(id)
        {
        }

        [[nodiscard]] JoystickId Id() const
        {
            return m_id;
        }

        [[nodiscard]] bool Present() const;

        [[nodiscard]] std::vector<float> GetAxes() const;

        [[nodiscard]] std::vector<KeyState> GetButtons() const;

        [[nodiscard]] std::vector<JoystickHat> GetHats() const;

        [[nodiscard]] std::string_view GetName() const;

        [[nodiscard]] std::string_view GetGUID() const;

        void SetUserPointer(void* pointer) const;

        [[nodiscard]] void* GetUserPointer() const;

        [[nodiscard]] bool IsGamepad() const;

        [[nodiscard]] std::string_view GetGamepadName() const;

        [[nodiscard]] GamepadState GetGamepadState() const;

        [[nodiscard]] static JoystickCallback SetJoystickCallback(JoystickCallback func);

    private:
        JoystickId m_id;
    };
}