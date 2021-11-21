#pragma once

// #define GLFW_INCLUDE_GLU
// #define GLFW_INCLUDE_GLCOREARB
// #define GLFW_INCLUDE_ES1
// #define GLFW_INCLUDE_ES2
// #define GLFW_INCLUDE_ES3
// #define GLFW_INCLUDE_ES31
// #define GLFW_INCLUDE_NONE
// #define GLFW_INCLUDE_GLEXT

#if defined(VK_VERSION_1_0) || defined(VK_VERSION_1_1) || defined(VK_VERSION_1_2)
#   define GLFW_INCLUDE_VULKAN
#endif // VK_VERSION_1_0 || VK_VERSION_1_1 || VK_VERSION_1_2

#include <GLFW/glfw3.h>