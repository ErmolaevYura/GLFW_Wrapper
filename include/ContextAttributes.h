#pragma once

#include "Enums.h"

struct GLFWwindow;

namespace GLFW_WRAPPER_NAMESPACE
{
    class ContextAttributes
    {
    public:
        ContextAttributes(GLFWwindow* window = nullptr)
            : m_window(window)
        {
        }

        [[nodiscard]] ClientApiValue ClientApi() const;
        [[nodiscard]] ContextCreationApiValue ContextCreationApi() const;
        [[nodiscard]] int ContextVersionMajor() const;
        [[nodiscard]] int ContextVersionMinor() const;
        [[nodiscard]] int ContextRevision() const;
        [[nodiscard]] bool OpenGlForwardCompat() const;
        [[nodiscard]] bool OpenGlDebugContext() const;
        [[nodiscard]] OpenGlProfileValue OpenGlProfile() const;
        [[nodiscard]] ContextRobustnessValue ContextRobustness() const;

        ContextAttributes& ClientApi(ClientApiValue clientApi);
        ContextAttributes& ContextCreationApi(ContextCreationApiValue creationApi);
        ContextAttributes& ContextVersionMajor(int major);
        ContextAttributes& ContextVersionMinor(int minor);
        ContextAttributes& ContextRevision(int revision);
        ContextAttributes& OpenGlForwardCompat(bool compat);
        ContextAttributes& OpenGlDebugContext(bool debug);
        ContextAttributes& OpenGlProfile(OpenGlProfileValue profile);
        ContextAttributes& ContextRobustness(ContextRobustnessValue robustness);

    private:
        GLFWwindow* m_window;
    };
}