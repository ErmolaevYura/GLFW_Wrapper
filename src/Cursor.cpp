#include "pch.h"
#include "../include/Cursor.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    Cursor::Cursor(Image image, std::array<int, 2> pos)
    {
        Raw = glfwCreateCursor(image, pos.front(), pos.back());
    }

    Cursor::Cursor(StandartCursorForm form)
    {
        Raw = glfwCreateStandardCursor(static_cast<int>(form));
    }

    Cursor::~Cursor()
    {
        glfwDestroyCursor(Raw);
    }
}