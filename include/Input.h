#pragma once

#include "Joystick.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    void PollEvents();

    void WaitEvents();

    void WaitEventsTimeout(double timeout);

    void PostEmptyEvent();

    [[nodiscard]] double GetTime();

    void SetTime(double time);

    [[nodiscard]] uint64_t GetTimerValue();

    [[nodiscard]] uint64_t GetTimerFrequency();

    [[nodiscard]] bool RawMouseMotionSuppored();

    [[nodiscard]] std::string_view GetKeyName(PrintKey key, int scancode);

    [[nodiscard]] int GetKeyScancode(KeyId key);
}