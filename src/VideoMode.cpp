#include "pch.h"
#include "../include/VideoMode.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    int32_t VideoMode::Width() const
    {
        return Raw->width;
    }

    int32_t VideoMode::Height() const
    {
        return Raw->height;
    }

    int32_t VideoMode::RedBits() const
    {
        return Raw->redBits;
    }

    int32_t VideoMode::GreenBits() const
    {
        return Raw->greenBits;
    }

    int32_t VideoMode::BlueBits() const
    {
        return Raw->blueBits;
    }

    int32_t VideoMode::RefreshRate() const
    {
        return Raw->refreshRate;
    }
}