#include "pch.h"
#include "../include/GammaRamp.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    std::vector<uint16_t> GammaRamp::Red() const
    {
        std::vector<uint16_t> red;
        red.reserve(Raw->size);
        for (auto i = 0u; i < Raw->size; ++i)
            red.emplace_back(Raw->red[i]);
        return red;
    }

    std::vector<uint16_t> GammaRamp::Green() const
    {
        std::vector<uint16_t> green;
        green.reserve(Raw->size);
        for (auto i = 0u; i < Raw->size; ++i)
            green.emplace_back(Raw->green[i]);
        return green;
    }

    std::vector<uint16_t> GammaRamp::Blue() const
    {
        std::vector<uint16_t> blue;
        blue.reserve(Raw->size);
        for (auto i = 0u; i < Raw->size; ++i)
            blue.emplace_back(Raw->blue[i]);
        return blue;
    }

    std::vector<std::array<uint16_t, 3>> GammaRamp::Color() const
    {
        std::vector<std::array<uint16_t, 3>> color;
        color.reserve(Raw->size);
        for (auto i = 0u; i < Raw->size; ++i)
            color.emplace_back(std::array{ Raw->red[i], Raw->green[i], Raw->blue[i] });
        return color;
    }

    size_t GammaRamp::size() const
    {
        return Raw->size;
    }
}