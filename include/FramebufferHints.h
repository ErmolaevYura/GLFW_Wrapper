#pragma once

#include "Defines.h"

#include <optional>

namespace GLFW_WRAPPER_NAMESPACE
{
    struct FramebufferHints
    {
        std::optional<int> RedBits{};
        std::optional<int> GreenBits{};
        std::optional<int> BlueBits{};
        std::optional<int> AlphaBits{};
        std::optional<int> DepthBits{};
        std::optional<int> StencilBits{};
        std::optional<int> Samples{};
        std::optional<bool> Doublebuffer{};
        std::optional<bool> Stereo{};
        std::optional<bool> SrgbCapable{};

        [[nodiscard]] static FramebufferHints Default()
        {
            FramebufferHints hint;
            hint.RedBits = 8;
            hint.GreenBits = 8;
            hint.BlueBits = 8;
            hint.AlphaBits = 8;
            hint.DepthBits = 24;
            hint.StencilBits = 8;
            hint.Samples = 0;
            hint.Doublebuffer = true;
            hint.Stereo = false;
            hint.SrgbCapable = false;
            return hint;
        }
    };

    struct FramebufferHintsApi
    {
        static void Apply(const FramebufferHints& hints);
        static FramebufferHintsApi Stereo(bool stereo = false);
        static FramebufferHintsApi SrgbCapable(bool srgbCapable = false);
        static FramebufferHintsApi Doublebuffer(bool doublebuffer = true);
        static FramebufferHintsApi RedBits(int redBits = 8);
        static FramebufferHintsApi GreenBits(int greenBits = 8);
        static FramebufferHintsApi BlueBits(int blueBits = 8);
        static FramebufferHintsApi AlphaBits(int alphaBits = 8);
        static FramebufferHintsApi DepthBits(int depthBits = 24);
        static FramebufferHintsApi StencilBits(int stencilBits = 8);
        static FramebufferHintsApi Samples(int samples = 0);
    };
}