#pragma once

#include "Defines.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    enum class EventType
    {
        Empty = 0x00000,
        // window events
        WindowPosition = 0x00001,
        WindowSize = 0x00002,
        WindowClose = 0x00004,
        WindowRefresh = 0x00008,
        WindowFocus = 0x00010,
        WindowIconify = 0x00020,
        WindowMaximize = 0x00040,
        FramebufferSize = 0x00080,
        ContentScale = 0x00100,
        // input events
        Char = 0x00200,
        Charmod = 0x00400,
        CursorEnter = 0x00800,
        CursorPosition = 0x01000,
        Drop = 0x02000,
        Key = 0x04000,
        MouseButton = 0x08000,
        Scroll = 0x10000,
        // other
        SizeEvents = WindowPosition | WindowSize | FramebufferSize | ContentScale,
        WindowEvents = WindowClose | WindowRefresh | WindowFocus | WindowIconify | WindowMaximize,
        InputEvents = Char | Charmod | CursorEnter | CursorPosition | Drop | Key | MouseButton | Scroll,
        AllEvents = SizeEvents | WindowEvents | InputEvents
    };

    constexpr EventType operator~(const EventType& et)
    {
        return static_cast<EventType>(~static_cast<int>(et));
    }

#define OPERATOR_DEFINE(T1, OP, T2) constexpr EventType operator OP(const T1& lhs, const T2& rhs) \
    { \
        return EventType{ static_cast<int>(lhs) OP static_cast<int>(rhs) }; \
    }
    OPERATOR_DEFINE(EventType, &, EventType);
    OPERATOR_DEFINE(EventType, &, int);
    OPERATOR_DEFINE(int, &, EventType);
    OPERATOR_DEFINE(EventType, | , EventType);
    OPERATOR_DEFINE(EventType, | , int);
    OPERATOR_DEFINE(int, | , EventType);
    OPERATOR_DEFINE(EventType, ^, EventType);
    OPERATOR_DEFINE(EventType, ^, int);
    OPERATOR_DEFINE(int, ^, EventType);
#undef OPERATOR_DEFINE

#define OPERATOR_DEFINE(OP) inline EventType& operator OP(EventType& lhs, const int& rhs) \
    { \
        lhs OP rhs; \
        return lhs; \
    }
    OPERATOR_DEFINE(&= );
    OPERATOR_DEFINE(|= );
    OPERATOR_DEFINE(^= );
#undef OPERATOR_DEFINE
}