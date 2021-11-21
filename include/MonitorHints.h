#pragma once

#include "Defines.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    [[nodiscard]] static constexpr int DontCare();

    struct MonitorHintsApi
    {
        static MonitorHintsApi RefreshRate(int value = DontCare());
    };
}