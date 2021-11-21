#pragma once

#include "Defines.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    bool VulkanSupported();
}

#if defined(VK_VERSION_1_0) || defined(VK_VERSION_1_1) || defined(VK_VERSION_1_2)

#include "Window.h"

#include <vulkan/vulkan_core.h>
#include <vector>
#include <string_view>

namespace GLFW_WRAPPER_NAMESPACE
{
    using VkFunc = void(*)();

    [[nodiscard]] std::pair<uint32_t, const char* const*> GetRequiredInstanceExtensionsRAW();

    [[nodiscard]] std::vector<std::string_view> GetRequiredInstanceExtensions();

    [[nodiscard]] VkFunc GetInstanceProcAddress(const VkInstance& instance, std::string_view name);

    [[nodiscard]] bool GetPhysicalDevicePresentationSupport(const VkInstance& instance, const VkPhysicalDevice& device, uint32_t queuefamily);

    [[nodiscard]] VkSurfaceKHR CreateWindowSurface(const Window& window, const VkInstance& instance, const VkAllocationCallbacks* allocator);
}

#endif // VK_VERSION_1_0 || VK_VERSION_1_1 || VK_VERSION_1_2