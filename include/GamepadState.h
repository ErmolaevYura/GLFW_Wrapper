#pragma once

#include "Enums.h"

#include <array>

struct GLFWgamepadstate;

namespace GLFW_WRAPPER_NAMESPACE
{
    struct GamepadState
    {
        static constexpr auto KeyCount = static_cast<int>(GamepadKey::Last) + 1;
        static constexpr auto AxesCount = static_cast<int>(GamepadAxes::Last) + 1;

        GLFWgamepadstate* Raw;

        GamepadState(GLFWgamepadstate* raw)
            : Raw(raw)
        {
        }

        [[nodiscard]] std::array<KeyState, KeyCount> GetButtons() const;

        [[nodiscard]] KeyState GetButton(GamepadKey) const;

        [[nodiscard]] std::array<float, AxesCount> GetAxes() const;

        [[nodiscard]] float GetAxes(GamepadAxes axes) const;

        operator GLFWgamepadstate*() const
        {
            return Raw;
        }

        operator const GLFWgamepadstate*() const
        {
            return Raw;
        }
    };
}