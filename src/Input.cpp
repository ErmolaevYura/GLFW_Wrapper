#include "pch.h"
#include "../include/Input.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    void PollEvents()
    {
        glfwPollEvents();
    }

    void WaitEvents()
    {
        glfwWaitEvents();
    }

    void WaitEventsTimeout(double timeout)
    {
        glfwWaitEventsTimeout(timeout);
    }

    void PostEmptyEvent()
    {
        glfwPostEmptyEvent();
    }

    double GetTime()
    {
        return glfwGetTime();
    }

    void SetTime(double time)
    {
        glfwSetTime(time);
    }

    uint64_t GetTimerValue()
    {
        return glfwGetTimerValue();
    }

    uint64_t GetTimerFrequency()
    {
        return glfwGetTimerFrequency();
    }

    bool RawMouseMotionSuppored()
    {
        return glfwRawMouseMotionSupported();
    }

    std::string_view GetKeyName(PrintKey key, int scancode)
    {
        return { glfwGetKeyName(static_cast<int>(key), scancode) };
    }

    int GetKeyScancode(KeyId key)
    {
        return glfwGetKeyScancode(static_cast<int>(key));
    }
}