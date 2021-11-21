#pragma once

#include "Defines.h"

#include <array>
#include <vector>

struct GLFWgammaramp;

namespace GLFW_WRAPPER_NAMESPACE
{
    struct GammaRamp
    {
        const GLFWgammaramp* Raw;

        GammaRamp(const GLFWgammaramp* gamma)
            : Raw(gamma)
        {
        }

        [[nodiscard]] std::vector<std::array<uint16_t, 3>> Color() const;

        [[nodiscard]] std::vector<uint16_t> Red() const;

        [[nodiscard]] std::vector<uint16_t> Green() const;

        [[nodiscard]] std::vector<uint16_t> Blue() const;

        [[nodiscard]] size_t size() const;

        operator const GLFWgammaramp*() const
        {
            return Raw;
        }
    };
}