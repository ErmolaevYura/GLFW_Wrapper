#pragma once

#include "Defines.h"

#include <array>

struct GLFWimage;

namespace GLFW_WRAPPER_NAMESPACE
{
    struct Image
    {
        GLFWimage* Raw;

        Image(GLFWimage* raw)
            : Raw(raw)
        {
        }

        [[nodiscard]] int Width() const;

        [[nodiscard]] int Height() const;

        [[nodiscard]] const unsigned char* Pixels() const;

        operator std::array<int, 2>() const
        {
            return { Width(), Height() };
        }

        operator GLFWimage*() const
        {
            return Raw;
        }

        operator const GLFWimage*() const
        {
            return Raw;
        }
    };
}