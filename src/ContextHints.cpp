#include "pch.h"
#include "../include/ContextHints.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    void ContextHintsApi::Apply(const ContextHints& hints)
    {
        if (hints.Version)
        {
            ContextVersionMajor(hints.Version->Major);
            ContextVersionMinor(hints.Version->Minor);
        }
        if (hints.OpenGlForwardCompat)
            OpenGlForwardCompat(*hints.OpenGlForwardCompat);
        if (hints.OpenGlDebugContext)
            OpenGlDebugContext(*hints.OpenGlDebugContext);
        if (hints.ContextNoError)
            ContextNoError(*hints.ContextNoError);
        if (hints.OpenGlProfile)
            OpenGlProfile(*hints.OpenGlProfile);
        if (hints.ClientApi)
            ClientApi(*hints.ClientApi);
        if (hints.ContextCreationApi)
            ContextCreationApi(*hints.ContextCreationApi);
        if (hints.ContextReleaseBehavior)
            ContextReleaseBehavior(*hints.ContextReleaseBehavior);
        if (hints.ContextRobustness)
            ContextRobustness(*hints.ContextRobustness);
    }

    ContextHintsApi ContextHintsApi::ContextVersionMajor(int major)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
        return {};
    }

    ContextHintsApi ContextHintsApi::ContextVersionMinor(int minor)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
        return {};
    }

    ContextHintsApi ContextHintsApi::OpenGlForwardCompat(bool compat)
    {
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, compat);
        return {};
    }

    ContextHintsApi ContextHintsApi::OpenGlDebugContext(bool debug)
    {
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, debug);
        return {};
    }

    ContextHintsApi ContextHintsApi::ContextNoError(bool noError)
    {
        glfwWindowHint(GLFW_CONTEXT_NO_ERROR, noError);
        return {};
    }

    ContextHintsApi ContextHintsApi::ClientApi(ClientApiValue clientApi)
    {
        glfwWindowHint(GLFW_CLIENT_API, static_cast<int>(clientApi));
        return {};
    }

    ContextHintsApi ContextHintsApi::ContextCreationApi(ContextCreationApiValue creationApi)
    {
        glfwWindowHint(GLFW_CONTEXT_CREATION_API, static_cast<int>(creationApi));
        return {};
    }

    ContextHintsApi ContextHintsApi::OpenGlProfile(OpenGlProfileValue profile)
    {
        glfwWindowHint(GLFW_OPENGL_PROFILE, static_cast<int>(profile));
        return {};
    }

    ContextHintsApi ContextHintsApi::ContextRobustness(ContextRobustnessValue robustness)
    {
        glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, static_cast<int>(robustness));
        return {};
    }

    ContextHintsApi ContextHintsApi::ContextReleaseBehavior(ContextReleaseBehaviorValue releaseBehavior)
    {
        glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, static_cast<int>(releaseBehavior));
        return {};
    }
}