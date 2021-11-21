#include "pch.h"
#include "../include/Monitor.h"
#include <stdexcept>

namespace GLFW_WRAPPER_NAMESPACE
{
    std::vector<Monitor> Monitor::GetAllMonitors()
    {
        auto count = int{};
        auto** monitorsPtr = glfwGetMonitors(&count);
        auto monitors = std::vector<Monitor>{};
        for (auto i = 0; i < count; ++i)
            monitors.emplace_back(monitorsPtr[i]);
        return monitors;
    }

    MonitorCallback Monitor::SetCallback(MonitorCallback func)
    {
        return glfwSetMonitorCallback(func);
    }

    void Monitor::ChoosMonitor(size_t index)
    {
        if (index == 0)
        {
            m_monitor = glfwGetPrimaryMonitor();
        }
        else
        {
            auto monitors = GetAllMonitors();
            if (index < monitors.size())
                m_monitor = monitors.at(index);
            else
                throw std::out_of_range("The selected index is greater than the number of monitors");
        }
    }

    std::array<int, 2> Monitor::GetPosition() const
    {
        std::array<int, 2> position{};
        glfwGetMonitorPos(m_monitor, &position[0], &position[1]);
        return position;
    }

    std::array<int, 4> Monitor::GetWorkarea() const
    {
        std::array<int, 4> workarea{};
        glfwGetMonitorWorkarea(m_monitor, &workarea[0], &workarea[1], &workarea[2], &workarea[3]);
        return workarea;
    }

    std::array<int, 2> Monitor::GetPhysicalSize() const
    {
        std::array<int, 2> size{};
        glfwGetMonitorPhysicalSize(m_monitor, &size[0], &size[1]);
        return size;
    }

    std::array<float, 2> Monitor::GetContentScale() const
    {
        std::array<float, 2> scale{};
        glfwGetMonitorContentScale(m_monitor, &scale[0], &scale[1]);
        return scale;
    }

    std::string_view Monitor::GetName() const
    {
        return glfwGetMonitorName(m_monitor);
    }

    void Monitor::SetUserPointer(void* pointer) const
    {
        glfwSetMonitorUserPointer(m_monitor, pointer);
    }

    void* Monitor::GetUserPointer() const
    {
        return glfwGetMonitorUserPointer(m_monitor);
    }

    std::vector<VideoMode> Monitor::GetVideoModes() const
    {
        auto count = int{};
        const auto* modes = glfwGetVideoModes(m_monitor, &count);
        std::vector<VideoMode> videoModes;
        for (auto i = 0; i < count; ++i)
            videoModes.emplace_back(&modes[i]);
        return videoModes;
    }

    VideoMode Monitor::GetVideoMode() const
    {
        return { glfwGetVideoMode(m_monitor) };
    }

    void Monitor::SetGamma(float gamma) const
    {
        glfwSetGamma(m_monitor, gamma);
    }

    GammaRamp Monitor::GetGammaRamp() const
    {
        return { glfwGetGammaRamp(m_monitor) };
    }

    void Monitor::SetGammaRamp(GammaRamp gamma) const
    {
        glfwSetGammaRamp(m_monitor, gamma);
    }
}