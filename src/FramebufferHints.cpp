#include "pch.h"
#include "../include/FramebufferHints.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    void FramebufferHintsApi::Apply(const FramebufferHints& hints)
    {
        if (hints.RedBits)
            RedBits(*hints.RedBits);
        if (hints.GreenBits)
            GreenBits(*hints.GreenBits);
        if (hints.BlueBits)
            BlueBits(*hints.BlueBits);
        if (hints.AlphaBits)
            AlphaBits(*hints.AlphaBits);
        if (hints.DepthBits)
            DepthBits(*hints.DepthBits);
        if (hints.StencilBits)
            StencilBits(*hints.StencilBits);
        if (hints.Samples)
            Samples(*hints.Samples);
        if (hints.Doublebuffer)
            Doublebuffer(*hints.Doublebuffer);
        if (hints.Stereo)
            Stereo(*hints.Stereo);
        if (hints.SrgbCapable)
            SrgbCapable(*hints.SrgbCapable);
    }

    FramebufferHintsApi FramebufferHintsApi::Stereo(bool stereo)
    {
        glfwWindowHint(GLFW_STEREO, stereo);
        return {};
    }

    FramebufferHintsApi FramebufferHintsApi::SrgbCapable(bool srgbCapable)
    {
        glfwWindowHint(GLFW_SRGB_CAPABLE, srgbCapable);
        return {};
    }

    FramebufferHintsApi FramebufferHintsApi::Doublebuffer(bool doublebuffer)
    {
        glfwWindowHint(GLFW_DOUBLEBUFFER, doublebuffer);
        return {};
    }

    FramebufferHintsApi FramebufferHintsApi::RedBits(int redBits)
    {
        glfwWindowHint(GLFW_RED_BITS, redBits);
        return {};
    }

    FramebufferHintsApi FramebufferHintsApi::GreenBits(int greenBits)
    {
        glfwWindowHint(GLFW_GREEN_BITS, greenBits);
        return {};
    }

    FramebufferHintsApi FramebufferHintsApi::BlueBits(int blueBits)
    {
        glfwWindowHint(GLFW_BLUE_BITS, blueBits);
        return {};
    }

    FramebufferHintsApi FramebufferHintsApi::AlphaBits(int alphaBits)
    {
        glfwWindowHint(GLFW_ALPHA_BITS, alphaBits);
        return {};
    }

    FramebufferHintsApi FramebufferHintsApi::DepthBits(int depthBits)
    {
        glfwWindowHint(GLFW_DEPTH_BITS, depthBits);
        return {};
    }

    FramebufferHintsApi FramebufferHintsApi::StencilBits(int stencilBits)
    {
        glfwWindowHint(GLFW_STENCIL_BITS, stencilBits);
        return {};
    }

    FramebufferHintsApi FramebufferHintsApi::Samples(int samples)
    {
        glfwWindowHint(GLFW_SAMPLES, samples);
        return {};
    }
}