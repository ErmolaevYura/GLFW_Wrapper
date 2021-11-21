#pragma once

#include "ContextAttributes.h"
#include "EventHandlerManager.h"
#include "Image.h"
#include "Monitor.h"
#include "WindowAttributes.h"

#include <memory>

struct GLFWwindow;

namespace GLFW_WRAPPER_NAMESPACE
{
    class Window;
    using WindowPtr = std::shared_ptr<Window>;

    struct UserData
    {
        size_t Id{};
        std::unique_ptr<EventHandlerManager> HandlerManager{};
    };

    struct WindowParams
    {
        const std::array<int32_t, 2> Size;
        const bool Fullscreen{ false };
        const std::string Title{ "OpenGL Example" };
        const uint32_t MonitorIndex{ 0 };

        WindowParams(int32_t width, int32_t height)
            : Size{ width, height }
        {
        }

        WindowParams(std::array<int32_t, 2> size = { 1280, 720 })
            : Size(size)
        {
        }

        WindowParams(std::array<int32_t, 2> size, bool fullscreen, uint32_t monitorIndex = {})
            : Size(size), Fullscreen(fullscreen), MonitorIndex(monitorIndex)
        {
        }

        WindowParams(std::array<int32_t, 2> size, bool fullscreen, std::string_view title, uint32_t monitorIndex = {})
            : Size(size), Fullscreen(fullscreen), Title(title), MonitorIndex(monitorIndex)
        {
        }
    };

    struct InputParams
    {
        bool UseKeyboard{ true };
        bool UseMouse{ true };
        EventType events{ EventType::AllEvents & ~EventType::WindowClose };
    };

    class Window
    {
    public:
        Window(GLFWwindow* window) noexcept;

        Window(const WindowParams& wParams,
               const InputParams& iParams,
               const Monitor& monitor = { nullptr },
               const Window& share = { nullptr });

        Window(Window&& rhs) noexcept;
        Window& operator=(Window&& rhs) noexcept;

        Window(const Window&) = delete;
        Window operator=(const Window&) = delete;

        ~Window();

        void Destroy();

        void Detach()
        {
            m_window = nullptr;
        }

        [[nodiscard]] GLFWwindow* Raw() const
        {
            return m_window;
        }

        [[nodiscard]] GLFWwindow* Raw()
        {
            return m_window;
        }

        [[nodiscard]] size_t Id() const
        {
            return m_userData->Id;
        }

        Window& BindsEventCallback(EventType events);

        Window& RegisterHandler(const EventHandlerPtr& handler);

        Window& RemoveHandlers(EventType type);

        Window& MakeContext();

        [[nodiscard]] bool ShouldClose() const;

        Window& SetShouldClose(bool value);

        Window& SetTitle(std::string_view title);

        Window& SetIcon(const std::vector<Image>& images);

        [[nodiscard]] std::array<int, 2> GetPosition() const;

        Window& SetPosition(std::array<int, 2> position);

        [[nodiscard]] std::array<int, 2> GetSize() const;

        Window& SetSizeLimits(std::array<int, 4> size);

        Window& SetAspectRation(std::array<int, 2> ratio);

        Window& SetSize(std::array<int, 2> size);

        [[nodiscard]] std::array<int, 2> GetFramebufferSize() const;

        [[nodiscard]] std::array<int, 4> GetFrameSize() const;

        [[nodiscard]] std::array<float, 2> GetContentScale() const;

        [[nodiscard]] float GetOpacity() const;

        Window& SetOpacity(float opacity);

        Window& Iconify();

        Window& Restore();

        Window& Maximize();

        Window& Show();

        Window& Hide();

        Window& Focus();

        Window& RequestAttention();

        [[nodiscard]] Monitor GetMonitor() const;

        Window& SetMonitor(Monitor monitor, const std::array<int, 4>& size, int refreshRate);

        Window& SwapBuffer();

        operator bool() const
        {
            return bool{ m_window != nullptr };
        }

        operator GLFWwindow* ()
        {
            return m_window;
        }

        operator GLFWwindow* () const
        {
            return m_window;
        }

        [[nodiscard]] WindowAttributes WindowAttr() const
        {
            return m_windowAttributes;
        }

        [[nodiscard]] ContextAttributes ContextAttr() const
        {
            return m_contextAttributes;
        }

    private:
        GLFWwindow* m_window;
        std::unique_ptr<UserData> m_userData{};
        bool m_isCreated{};
        WindowAttributes m_windowAttributes;
        ContextAttributes m_contextAttributes;
    };
}