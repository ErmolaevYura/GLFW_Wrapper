#pragma once

#include "Enums.h"

#include <optional>

namespace GLFW_WRAPPER_NAMESPACE
{
    struct GLVersion
    {
        int Major;
        int Minor;
    };

    struct ContextHints
    {
        std::optional<GLVersion> Version{};
        std::optional<bool> OpenGlForwardCompat{};
        std::optional<bool> OpenGlDebugContext{};
        std::optional<bool> ContextNoError{};
        std::optional<OpenGlProfileValue> OpenGlProfile{};
        std::optional<ClientApiValue> ClientApi{};
        std::optional<ContextCreationApiValue> ContextCreationApi{};
        std::optional<ContextRobustnessValue> ContextRobustness{};
        std::optional<ContextReleaseBehaviorValue> ContextReleaseBehavior{};

        [[nodiscard]] static ContextHints Default()
        {
            ContextHints hint;
            hint.Version = { 3, 2 };
            hint.OpenGlForwardCompat = false;
            hint.OpenGlDebugContext = false;
            hint.ContextNoError = false;
            hint.OpenGlProfile = OpenGlProfileValue::Any;
            hint.ClientApi = ClientApiValue::Opengl;
            hint.ContextCreationApi = ContextCreationApiValue::Native;
            hint.ContextRobustness = ContextRobustnessValue::No;
            hint.ContextReleaseBehavior = ContextReleaseBehaviorValue::Any;
            return hint;
        }
    };

    struct ContextHintsApi
    {
        static void Apply(const ContextHints& hints);
        static ContextHintsApi ContextVersionMajor(int major = 3);
        static ContextHintsApi ContextVersionMinor(int minor = 2);
        static ContextHintsApi OpenGlForwardCompat(bool compat = false);
        static ContextHintsApi OpenGlDebugContext(bool debug = false);
        static ContextHintsApi ContextNoError(bool noError = false);
        static ContextHintsApi ClientApi(ClientApiValue clientApi = ClientApiValue::Opengl);
        static ContextHintsApi ContextCreationApi(ContextCreationApiValue creationApi = ContextCreationApiValue::Native);
        static ContextHintsApi OpenGlProfile(OpenGlProfileValue profile = OpenGlProfileValue::Any);
        static ContextHintsApi ContextRobustness(ContextRobustnessValue robustness = ContextRobustnessValue::No);
        static ContextHintsApi ContextReleaseBehavior(ContextReleaseBehaviorValue releaseBehavior = ContextReleaseBehaviorValue::Any);
    };
}