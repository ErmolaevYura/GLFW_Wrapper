#pragma once

#include "Enums.h"
#include "EventType.h"
#include "KeyModifier.h"

#include <list>
#include <memory>
#include <string>

namespace GLFW_WRAPPER_NAMESPACE
{
    struct Event
    {
        const EventType Type;

        Event(EventType type)
            : Type(type)
        {
        }

        Event(const Event& ev) noexcept = default;
        Event(Event&& ev) = default;

        Event& operator=(const Event& ev) = delete;
        Event& operator=(Event&& ev) = delete;

        virtual ~Event() = default;
    };

    using EventPtr = std::shared_ptr<Event>;

    struct CharEvent : Event
    {
        const char32_t Character;

        CharEvent(char32_t character)
            : Event(EventType::Char), Character(character)
        {
        }
    };

    struct CharmodeEvent : Event
    {
        const char32_t Character;
        const KeyModifier Mode;

        CharmodeEvent(char32_t character, KeyModifier mode)
            : Event(EventType::Charmod), Character(character), Mode(mode)
        {
        }
    };

    struct ContentScaleEvent : Event
    {
        const float X;
        const float Y;

        ContentScaleEvent(float x, float y)
            : Event(EventType::ContentScale), X(x), Y(y)
        {
        }
    };

    struct CursorEnterEvent : Event
    {
        const bool IsEnter;

        CursorEnterEvent(bool isEnter)
            : Event(EventType::CursorEnter), IsEnter(isEnter)
        {
        }
    };

    struct CursorPositionEvent : Event
    {
        const double X;
        const double Y;

        CursorPositionEvent(double x, double y)
            : Event(EventType::CursorPosition), X(x), Y(y)
        {
        }
    };

    struct DropEvent : Event
    {
        const std::list<std::string> Paths;
        const char* const* Raw;

        DropEvent(const std::list<std::string>& paths, const char* const* raw)
            : Event(EventType::Drop), Paths(paths), Raw(raw)
        {
        }
    };

    struct FramebufferSizeEvent : Event
    {
        const int Width;
        const int Height;

        FramebufferSizeEvent(int width, int height)
            : Event(EventType::FramebufferSize), Width(width), Height(height)
        {
        }
    };

    struct KeyEvent : Event
    {
        const KeyId Key;
        const char32_t Scancode;
        const KeyState State;
        const KeyModifier Mode;

        KeyEvent(KeyId key, char32_t scancode, KeyState state, KeyModifier mode)
            : Event(EventType::Key), Key(key), Scancode(scancode), State(state), Mode(mode)
        {
        }
    };

    struct MouseButtonEvent : Event
    {
        const MouseKeyId Key;
        const KeyState State;
        const KeyModifier Mode;

        MouseButtonEvent(MouseKeyId key, KeyState state, KeyModifier mode)
            : Event(EventType::MouseButton), Key(key), State(state), Mode(mode)
        {
        }
    };

    struct ScrollEvent : Event
    {
        const double X;
        const double Y;

        ScrollEvent(double x, double y)
            : Event(EventType::Scroll), X(x), Y(y)
        {
        }
    };

    struct WindowCloseEvent : Event
    {
        WindowCloseEvent()
            : Event(EventType::WindowClose)
        {
        }
    };

    struct WindowFocusEvent : Event
    {
        const bool Focus;

        WindowFocusEvent(bool focus)
            : Event(EventType::WindowFocus), Focus(focus)
        {
        }
    };

    struct WindowIconifyEvent : Event
    {
        const bool Iconify;

        WindowIconifyEvent(bool iconify)
            : Event(EventType::WindowIconify), Iconify(iconify)
        {
        }
    };

    struct WindowMaximizeEvent : Event
    {
        const bool Maximize;

        WindowMaximizeEvent(bool maximize)
            : Event(EventType::WindowMaximize), Maximize(maximize)
        {
        }
    };

    struct WindowPositionEvent : Event
    {
        const int X;
        const int Y;

        WindowPositionEvent(int x, int y)
            : Event(EventType::WindowPosition), X(x), Y(y)
        {
        }
    };

    struct WindowRefreshEvent : Event
    {
        WindowRefreshEvent()
            : Event(EventType::WindowRefresh)
        {
        }
    };

    struct WindowSizeEvent : Event
    {
        const int Width;
        const int Height;

        WindowSizeEvent(int width, int height)
            : Event(EventType::WindowSize), Width(width), Height(height)
        {
        }
    };
}