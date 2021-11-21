#include "pch.h"
#include "../include/Image.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    int Image::Width() const
    {
        return Raw->width;
    }

    int Image::Height() const
    {
        return Raw->height;
    }

    const unsigned char* Image::Pixels() const
    {
        return Raw->pixels;
    }
}