#pragma once

#include "GammaRamp.h"
#include "VideoMode.h"

#include <vector>
#include <string_view>

struct GLFWmonitor;

namespace GLFW_WRAPPER_NAMESPACE
{
    using MonitorCallback = void(*)(GLFWmonitor*, int);

    class Monitor
    {
    public:
        static std::vector<Monitor> GetAllMonitors();

        static MonitorCallback SetCallback(MonitorCallback func);

        Monitor(GLFWmonitor* monitor)
            : m_monitor(monitor)
        {
        }

        Monitor(size_t index = 0)
        {
            ChoosMonitor(index);
        }

        void ChoosMonitor(size_t index);

        [[nodiscard]] std::array<int, 2> GetPosition() const;

        [[nodiscard]] std::array<int, 4> GetWorkarea() const;

        [[nodiscard]] std::array<int, 2> GetPhysicalSize() const;

        [[nodiscard]] std::array<float, 2> GetContentScale() const;

        [[nodiscard]] std::string_view GetName() const;

        void SetUserPointer(void* pointer) const;

        [[nodiscard]] void* GetUserPointer() const;

        [[nodiscard]] std::vector<VideoMode> GetVideoModes() const;

        [[nodiscard]] VideoMode GetVideoMode() const;

        void SetGamma(float gamma) const;

        [[nodiscard]] GammaRamp GetGammaRamp() const;

        void SetGammaRamp(GammaRamp gamma) const;

        operator GLFWmonitor*()
        {
            return m_monitor;
        }

        operator GLFWmonitor*() const
        {
            return m_monitor;
        }

    private:
        GLFWmonitor* m_monitor{ nullptr };
    };
}