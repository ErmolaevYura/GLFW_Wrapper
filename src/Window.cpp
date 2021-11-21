#include "pch.h"
#include "../include/Window.h"
#include "../include/EventHandlerManager.h"
#include "../include/WindowInputApi.h"

#include <algorithm>
#include <atomic>
#include <vector>

namespace
{
    using namespace GLFW_WRAPPER_NAMESPACE;

    size_t CreateWindowId()
    {
        static auto id = std::atomic_size_t{ 0 };
        return ++id;
    }

    void WindowPositionCallback(GLFWwindow* window, int xPos, int yPos)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<WindowPositionEvent>(xPos, yPos);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void WindowSizeCallback(GLFWwindow* window, int width, int height)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<WindowSizeEvent>(width, height);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void WindowCloseCallback(GLFWwindow* window)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<WindowCloseEvent>();
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void WindowRefreshCallback(GLFWwindow* window)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<WindowRefreshEvent>();
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void WindowFocusCallback(GLFWwindow* window, int focus)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<WindowFocusEvent>(focus == GL_TRUE);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void WindowMaximizeCallback(GLFWwindow* window, int miximize)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<WindowMaximizeEvent>(miximize == GL_TRUE);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void WindowIconifyCallback(GLFWwindow* window, int iconify)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<WindowIconifyEvent>(iconify == GL_TRUE);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<FramebufferSizeEvent>(width, height);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void ContentScaleCallback(GLFWwindow* window, float xScale, float yScale)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<ContentScaleEvent>(xScale, yScale);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void CharCallback(GLFWwindow* window, unsigned int character)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<CharEvent>(character);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void CharmodeCallback(GLFWwindow* window, unsigned int character, int mode)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<CharmodeEvent>(character, static_cast<KeyModifier>(mode));
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void CursorEnterCallback(GLFWwindow* window, int isEnter)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<CursorEnterEvent>(isEnter == GL_TRUE);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void CursorPositionCallback(GLFWwindow* window, double xPos, double yPos)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<CursorPositionEvent>(xPos, yPos);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void DropCallback(GLFWwindow* window, int count, const char** rawPaths)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        std::list<std::string> paths;
        for (int i = 0; i < count; ++i)
            paths.emplace_back(rawPaths[i]);
        const auto event = std::make_unique<DropEvent>(paths, rawPaths);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void KeyCallback(GLFWwindow* window, int key, int scancode, int state, int mode)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<KeyEvent>(static_cast<KeyId>(key),
                                                      scancode,
                                                      static_cast<KeyState>(state),
                                                      static_cast<KeyModifier>(mode));
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void MouseButtonCallback(GLFWwindow* window, int key, int state, int mode)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<MouseButtonEvent>(static_cast<MouseKeyId>(key),
                                                              static_cast<KeyState>(state),
                                                              static_cast<KeyModifier>(mode));
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }

    void MouseScrollCallback(GLFWwindow* window, double x, double y)
    {
        auto* userData = static_cast<UserData*>(glfwGetWindowUserPointer(window));
        const auto event = std::make_unique<ScrollEvent>(x, y);
        if (userData && userData->HandlerManager)
            userData->HandlerManager->Handle(event.get());
    }
}

namespace GLFW_WRAPPER_NAMESPACE
{
    Window::Window(GLFWwindow* window) noexcept
        : m_window(window), m_windowAttributes(window), m_contextAttributes(window)
    {
        if (m_window)
        {
            m_userData.reset(static_cast<UserData*>(glfwGetWindowUserPointer(m_window)));
        }
    }

    Window::Window(const WindowParams& wParams, const InputParams& iParams, const Monitor& monitor, const Window& share)
    {
        m_window = glfwCreateWindow(wParams.Size[0], wParams.Size[1], wParams.Title.c_str(), monitor, share);

        if (m_window != nullptr)
        {
            m_isCreated = true;

            m_userData = std::make_unique<UserData>();
            m_userData->Id = CreateWindowId();

            m_userData->HandlerManager = std::make_unique<EventHandlerManager>();
            glfwSetWindowUserPointer(m_window, static_cast<void*>(m_userData.get()));

            const InputApi api{ m_window };
            if (iParams.UseKeyboard)
                api.SetStickyKeysMode(true);

            if (iParams.UseMouse)
            {
                api.SetCursorMode(CursorMode::Normal);
                api.SetCursor(StandartCursorForm::ArrowCursor);
            }

            BindsEventCallback(iParams.events);
        }

        m_windowAttributes = WindowAttributes{ m_window };
        m_contextAttributes = ContextAttributes{ m_window };
    }

    Window::Window(Window&& rhs) noexcept
        : m_window(rhs.m_window), m_userData(std::move(rhs.m_userData)), m_isCreated(rhs.m_isCreated)
    {
        rhs.m_window = nullptr;
        rhs.m_isCreated = false;

        m_windowAttributes = WindowAttributes{ m_window };
        m_contextAttributes = ContextAttributes{ m_window };
    }

    Window& Window::operator=(Window&& rhs) noexcept
    {
        m_window = rhs.m_window;
        rhs.m_window = nullptr;

        m_isCreated = rhs.m_isCreated;
        rhs.m_isCreated = false;

        m_userData = std::move(rhs.m_userData);

        m_windowAttributes = WindowAttributes{ m_window };
        m_contextAttributes = ContextAttributes{ m_window };

        return *this;
    }

    Window::~Window()
    {
        Destroy();
    }

    void Window::Destroy()
    {
        if (m_isCreated)
            glfwDestroyWindow(m_window);
        m_window = nullptr;
        m_userData = {};
        m_isCreated = false;
    }

    Window& Window::BindsEventCallback(EventType events)
    {
        if (static_cast<bool>(events & EventType::WindowPosition))
            glfwSetWindowPosCallback(m_window, &WindowPositionCallback);
        if (static_cast<bool>(events & EventType::WindowSize))
            glfwSetWindowSizeCallback(m_window, &WindowSizeCallback);
        if (static_cast<bool>(events & EventType::FramebufferSize))
            glfwSetFramebufferSizeCallback(m_window, &FramebufferSizeCallback);
        if (static_cast<bool>(events & EventType::ContentScale))
            glfwSetWindowContentScaleCallback(m_window, &ContentScaleCallback);

        if (static_cast<bool>(events & EventType::WindowClose))
            glfwSetWindowCloseCallback(m_window, &WindowCloseCallback);
        if (static_cast<bool>(events & EventType::WindowRefresh))
            glfwSetWindowRefreshCallback(m_window, &WindowRefreshCallback);
        if (static_cast<bool>(events & EventType::WindowFocus))
            glfwSetWindowFocusCallback(m_window, &WindowFocusCallback);
        if (static_cast<bool>(events & EventType::WindowIconify))
            glfwSetWindowIconifyCallback(m_window, &WindowIconifyCallback);
        if (static_cast<bool>(events & EventType::WindowMaximize))
            glfwSetWindowMaximizeCallback(m_window, &WindowMaximizeCallback);

        if (static_cast<bool>(events & EventType::Char))
            glfwSetCharCallback(m_window, &CharCallback);
        if (static_cast<bool>(events & EventType::Charmod))
            glfwSetCharModsCallback(m_window, &CharmodeCallback);
        if (static_cast<bool>(events & EventType::CursorEnter))
            glfwSetCursorEnterCallback(m_window, &CursorEnterCallback);
        if (static_cast<bool>(events & EventType::CursorPosition))
            glfwSetCursorPosCallback(m_window, &CursorPositionCallback);
        if (static_cast<bool>(events & EventType::Drop))
            glfwSetDropCallback(m_window, &DropCallback);
        if (static_cast<bool>(events & EventType::Key))
            glfwSetKeyCallback(m_window, &KeyCallback);
        if (static_cast<bool>(events & EventType::MouseButton))
            glfwSetMouseButtonCallback(m_window, &MouseButtonCallback);
        if (static_cast<bool>(events & EventType::Scroll))
            glfwSetScrollCallback(m_window, &MouseScrollCallback);

        return *this;
    }

    Window& Window::RegisterHandler(const EventHandlerPtr& handler)
    {
        m_userData->HandlerManager->RegisterHandler(handler);
        return *this;
    }

    Window& Window::RemoveHandlers(EventType type)
    {
        m_userData->HandlerManager->RemoveHandlers(type);
        return *this;
    }

    Window& Window::MakeContext()
    {
        glfwMakeContextCurrent(m_window);
        return *this;
    }

    bool Window::ShouldClose() const
    {
        return bool{ glfwWindowShouldClose(m_window) == GL_TRUE };
    }

    Window& Window::SetShouldClose(bool value)
    {
        glfwSetWindowShouldClose(m_window, value ? GL_TRUE : GL_FALSE);
        return *this;
    }

    Window& Window::SetTitle(std::string_view title)
    {
        glfwSetWindowTitle(m_window, title.data());
        return *this;
    }

    Window& Window::SetIcon(const std::vector<Image>& images)
    {
        std::vector<const GLFWimage*> glfwImages;
        glfwImages.reserve(images.size());
        for (const auto& image : images)
            glfwImages.emplace_back(image);
        glfwSetWindowIcon(m_window, static_cast<int>(glfwImages.size()), glfwImages.front());
        return *this;
    }

    std::array<int, 2> Window::GetPosition() const
    {
        std::array<int, 2> position{};
        glfwGetWindowPos(m_window, &position[0], &position[1]);
        return position;
    }

    Window& Window::SetPosition(std::array<int, 2> position)
    {
        glfwSetWindowPos(m_window, position[0], position[1]);
        return *this;
    }

    std::array<int, 2> Window::GetSize() const
    {
        std::array<int, 2> size{};
        glfwGetWindowSize(m_window, &size[0], &size[1]);
        return size;
    }

    Window& Window::SetSizeLimits(std::array<int, 4> size)
    {
        glfwSetWindowSizeLimits(m_window, size[0], size[1], size[2], size[3]);
        return *this;
    }

    Window& Window::SetAspectRation(std::array<int, 2> ratio)
    {
        glfwSetWindowAspectRatio(m_window, ratio[0], ratio[1]);
        return *this;
    }

    Window& Window::SetSize(std::array<int, 2> size)
    {
        glfwSetWindowSize(m_window, size[0], size[1]);
        return *this;
    }

    std::array<int, 2> Window::GetFramebufferSize() const
    {
        std::array<int, 2> size{};
        glfwGetFramebufferSize(m_window, &size[0], &size[1]);
        return size;
    }

    std::array<int, 4> Window::GetFrameSize() const
    {
        std::array<int, 4> size{};
        glfwGetWindowFrameSize(m_window, &size[0], &size[1], &size[2], &size[3]);
        return size;
    }

    std::array<float, 2> Window::GetContentScale() const
    {
        std::array<float, 2> scale{};
        glfwGetWindowContentScale(m_window, &scale[0], &scale[1]);
        return scale;
    }

    float Window::GetOpacity() const
    {
        return glfwGetWindowOpacity(m_window);
    }

    Window& Window::SetOpacity(float opacity)
    {
        glfwSetWindowOpacity(m_window, opacity);
        return *this;
    }

    Window& Window::Iconify()
    {
        glfwIconifyWindow(m_window);
        return *this;
    }

    Window& Window::Restore()
    {
        glfwRestoreWindow(m_window);
        return *this;
    }

    Window& Window::Maximize()
    {
        glfwMaximizeWindow(m_window);
        return *this;
    }

    Window& Window::Show()
    {
        glfwShowWindow(m_window);
        return *this;
    }

    Window& Window::Hide()
    {
        glfwHideWindow(m_window);
        return *this;
    }

    Window& Window::Focus()
    {
        glfwFocusWindow(m_window);
        return *this;
    }

    Window& Window::RequestAttention()
    {
        glfwRequestWindowAttention(m_window);
        return *this;
    }

    Monitor Window::GetMonitor() const
    {
        return { glfwGetWindowMonitor(m_window) };
    }

    Window& Window::SetMonitor(Monitor monitor, const std::array<int, 4>& size, int refreshRate)
    {
        glfwSetWindowMonitor(m_window, monitor, size[0], size[1], size[2], size[3], refreshRate);
        return *this;
    }

    Window& Window::SwapBuffer()
    {
        glfwSwapBuffers(m_window);
        return *this;
    }
}