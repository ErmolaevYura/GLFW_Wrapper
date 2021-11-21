#pragma once

#include "Defines.h"

#include <array>

struct GLFWvidmode;

namespace GLFW_WRAPPER_NAMESPACE
{
    struct VideoMode
    {
        const GLFWvidmode* Raw;

        VideoMode(const GLFWvidmode* mode)
            : Raw(mode)
        {
        }

        [[nodiscard]] int32_t Width() const;

        [[nodiscard]] int32_t Height() const;

        [[nodiscard]] std::array<int32_t, 2> Size() const
        {
            return { Width(), Height() };
        }

        [[nodiscard]] int32_t RedBits() const;

        [[nodiscard]] int32_t GreenBits() const;

        [[nodiscard]] int32_t BlueBits() const;

        [[nodiscard]] int32_t RefreshRate() const;

        operator const GLFWvidmode*() const
        {
            return Raw;
        }
    };
}