#pragma once

#include "Enums.h"
#include "Image.h"

#include <array>

struct GLFWcursor;

namespace GLFW_WRAPPER_NAMESPACE
{
    struct Cursor
    {
        GLFWcursor* Raw;

        Cursor(Image image, std::array<int, 2> pos);

        Cursor(StandartCursorForm form);

        Cursor(const Cursor&) = delete;
        Cursor(Cursor&& cursor) noexcept
            : Raw(cursor.Raw)
        {
            cursor.Raw = nullptr;
        }

        Cursor& operator=(const Cursor&) = delete;
        Cursor& operator=(Cursor&& cursor) noexcept
        {
            Raw = cursor.Raw;
            cursor.Raw = nullptr;
            return *this;
        }

        ~Cursor();

        operator GLFWcursor*() const
        {
            return Raw;
        }

        operator const GLFWcursor*() const
        {
            return Raw;
        }
    };
}