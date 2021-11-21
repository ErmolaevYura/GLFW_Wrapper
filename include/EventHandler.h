#pragma once

#include "Event.h"

#include <functional>

namespace GLFW_WRAPPER_NAMESPACE
{
    struct EventHandler
    {
        const EventType Type;

        EventHandler(EventType type)
            : Type(type)
        {
        }

        EventHandler(const EventHandler&) = default;
        EventHandler(EventHandler&&) = default;

        EventHandler& operator=(const EventHandler&) = delete;
        EventHandler& operator=(EventHandler&&) = delete;

        virtual ~EventHandler() = default;

        [[nodiscard]] bool IsApplicable(const Event& event) const
        {
            return bool{ event.Type == Type };
        }

        virtual void Process(const Event* event) = 0;
    };

    using EventHandlerPtr = std::shared_ptr<EventHandler>;
    using EventHandlerWPtr = std::weak_ptr<EventHandler>;

    template<typename HandleT>
    struct EventHandlerImp : EventHandler
    {
        using HandleType = HandleT;

        const HandleType Handle;

        EventHandlerImp(EventType type, HandleType handle)
            : EventHandler(type), Handle(std::move(handle))
        {
        }
    };

    struct CharHandler : EventHandlerImp<std::function<void(char32_t character)>>
    {
        CharHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::Char, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const CharEvent*>(ev) };
                Handle(event->Character);
            }
        }
    };

    struct CharmodeHandler : EventHandlerImp<std::function<void(char32_t character, KeyModifier mode)>>
    {
        CharmodeHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::Charmod, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const CharmodeEvent*>(ev) };
                Handle(event->Character, event->Mode);
            }
        }
    };

    struct ContentScaleHandler : EventHandlerImp<std::function<void(float xScale, float yScale)>>
    {
        ContentScaleHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::ContentScale, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const ContentScaleEvent*>(ev) };
                Handle(event->X, event->Y);
            }
        }
    };

    struct CursorEnterHandler : EventHandlerImp<std::function<void(bool isEnter)>>
    {
        CursorEnterHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::CursorEnter, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const CursorEnterEvent*>(ev) };
                Handle(event->IsEnter);
            }
        }
    };

    struct CursorPositionHandler : EventHandlerImp<std::function<void(double xPos, double yPos)>>
    {
        CursorPositionHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::CursorPosition, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const CursorPositionEvent*>(ev) };
                Handle(event->X, event->Y);
            }
        }
    };

    struct DropHandler : EventHandlerImp<std::function<void(const std::list<std::string>& paths, const char* const* raw)>>
    {
        DropHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::Drop, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const DropEvent*>(ev) };
                Handle(event->Paths, event->Raw);
            }
        }
    };

    struct FramebufferSizeHandler : EventHandlerImp<std::function<void(int width, int height)>>
    {
        FramebufferSizeHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::FramebufferSize, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const FramebufferSizeEvent*>(ev) };
                Handle(event->Width, event->Height);
            }
        }
    };

    struct KeyHandler : EventHandlerImp<std::function<void(KeyId key, char32_t scancode, KeyState state, KeyModifier mode)>>
    {
        KeyHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::Key, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const KeyEvent*>(ev) };
                Handle(event->Key, event->Scancode, event->State, event->Mode);
            }
        }
    };

    struct MouseButtonHandler : EventHandlerImp<std::function<void(MouseKeyId key, KeyState state, KeyModifier mode)>>
    {
        MouseButtonHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::MouseButton, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const MouseButtonEvent*>(ev) };
                Handle(event->Key, event->State, event->Mode);
            }
        }
    };

    struct ScrollHandler : EventHandlerImp<std::function<void(double x, double y)>>
    {
        ScrollHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::Scroll, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const ScrollEvent*>(ev) };
                Handle(event->X, event->Y);
            }
        }
    };

    struct WindowCloseHandler : EventHandlerImp<std::function<void()>>
    {
        WindowCloseHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::WindowClose, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
                Handle();
        }
    };

    struct WindowFocusHandler : EventHandlerImp<std::function<void(bool focus)>>
    {
        WindowFocusHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::WindowFocus, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const WindowFocusEvent*>(ev) };
                Handle(event->Focus);
            }
        }
    };

    struct WindowIconifyHandler : EventHandlerImp<std::function<void(bool iconify)>>
    {
        WindowIconifyHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::WindowIconify, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const WindowIconifyEvent*>(ev) };
                Handle(event->Iconify);
            }
        }
    };

    struct WindowMaximizeHandler : EventHandlerImp<std::function<void(bool maximize)>>
    {
        WindowMaximizeHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::WindowFocus, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const WindowMaximizeEvent*>(ev) };
                Handle(event->Maximize);
            }
        }
    };

    struct WindowPositionHandler : EventHandlerImp<std::function<void(int x, int y)>>
    {
        WindowPositionHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::WindowPosition, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const WindowPositionEvent*>(ev) };
                Handle(event->X, event->Y);
            }
        }
    };

    struct WindowRefreshHandler : EventHandlerImp<std::function<void()>>
    {
        WindowRefreshHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::WindowRefresh, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
                Handle();
        }
    };

    struct WindowSizeHandler : EventHandlerImp<std::function<void(int width, int height)>>
    {
        WindowSizeHandler(HandleType&& handle = nullptr)
            : EventHandlerImp(EventType::WindowSize, handle)
        {
        }

        void Process(const Event* ev) override
        {
            if (Handle && ev && ev->Type == Type)
            {
                const auto* event{ static_cast<const WindowSizeEvent*>(ev) };
                Handle(event->Width, event->Height);
            }
        }
    };
}