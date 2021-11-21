#include "pch.h"
#include "../include/GamepadState.h"

#include <limits>

namespace GLFW_WRAPPER_NAMESPACE
{
    std::array<KeyState, GamepadState::KeyCount> GamepadState::GetButtons() const
    {
        std::array<KeyState, KeyCount> buttons{};
        if (Raw)
        {
            for (size_t i = 0; i < KeyCount; ++i)
            {
                if (Raw->buttons + i != nullptr)
                    buttons[i] = static_cast<KeyState>(Raw->buttons[i]);
                else
                    buttons[i] = KeyState::Undefined;
            }
        }
        else
        {
            buttons.fill(KeyState::Undefined);
        }
        return buttons;
    }

    KeyState GamepadState::GetButton(GamepadKey key) const
    {
        const auto index = static_cast<int>(key);
        if (Raw && Raw->buttons + index)
            return static_cast<KeyState>(Raw->buttons[index]);
        return KeyState::Undefined;
    }

    std::array<float, GamepadState::AxesCount> GamepadState::GetAxes() const
    {
        std::array<float, AxesCount> axes{};
        if (Raw)
        {
            for (size_t i = 0; i < AxesCount; ++i)
            {
                if (Raw->axes + i != nullptr)
                    axes[i] = Raw->axes[i];
                else
                    axes[i] = std::numeric_limits<float>::max();
            }
        }
        else
        {
            axes.fill(0.0f);
        }
        return axes;
    }

    float GamepadState::GetAxes(GamepadAxes axes) const
    {
        const auto index = static_cast<int>(axes);
        if (Raw && Raw->buttons + index)
            return Raw->buttons[index];
        return std::numeric_limits<float>::max();
    }
}