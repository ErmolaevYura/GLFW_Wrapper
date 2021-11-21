#include "pch.h"
#include "../include/Vulkan.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    bool VulkanSupported()
    {
        return glfwVulkanSupported();
    }
}

#ifdef GLFW_INCLUDE_VULKAN

#include <vulkan/vulkan_core.h>

#include <vector>
#include <mutex>

namespace GLFW_WRAPPER_NAMESPACE
{
    std::pair<uint32_t, const char* const*> GetRequiredInstanceExtensionsRAW()
    {
        uint32_t count{};
        const auto** extensions = glfwGetRequiredInstanceExtensions(&count);
        return { count, extensions };
    }

    std::vector<std::string_view> GetRequiredInstanceExtensions()
    {
        uint32_t count{};
        const auto** extensionRaw = glfwGetRequiredInstanceExtensions(&count);
        std::vector<std::string_view> extensions;
        for (size_t i = 0; i < count; ++i)
            extensions.emplace_back(extensionRaw[i]);
        return extensions;
    }

    VkFunc GetInstanceProcAddress(const VkInstance& instance, std::string_view name)
    {
        return glfwGetInstanceProcAddress(instance, name.data());
    }

    bool GetPhysicalDevicePresentationSupport(const VkInstance& instance, const VkPhysicalDevice& device, uint32_t queuefamily)
    {
        return glfwGetPhysicalDevicePresentationSupport(instance, device, queuefamily);
    }

    VkSurfaceKHR CreateWindowSurface(const Window& window, const VkInstance& instance, const VkAllocationCallbacks* allocator)
    {
        VkSurfaceKHR surface;
        const auto vk = glfwCreateWindowSurface(instance, window, allocator, &surface);
        if (vk != VkResult::VK_SUCCESS)
            throw std::runtime_error{"Failed to create window surface!"};
        return surface;
    }
}

#endif // GLFW_INCLUDE_VULKAN