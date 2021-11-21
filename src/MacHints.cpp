#include "pch.h"
#include "../include/MacHints.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    MacHintsApi MacHintsApi::CocoaRetinaFramebuffer(bool retinaFramebuffer)
    {
        glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, retinaFramebuffer);
        return {};
    }

    MacHintsApi MacHintsApi::CocoaFrameName(std::string_view name)
    {
        glfwWindowHintString(GLFW_COCOA_FRAME_NAME, name.data());
        return {};
    }

    MacHintsApi MacHintsApi::CocoaGraphicsSwitching(bool graphicsSwitching)
    {
        glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, graphicsSwitching);
        return {};
    }
}