#pragma once

#include "Defines.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    enum class ClientApiValue
    {
        Opengl = 0x00030001,                // GLFW_OPENGL_API
        Es = 0x00030002,                    // GLFW_OPENGL_ES_API
        No = 0                              // GLFW_NO_API
    };

    enum class ContextAttr
    {
        ClientApi = 0x00022001,
        ContextVersionMajor,
        ContextVersionMinor,
        ContextRevision,
        OpenglForwardCompat,
        OpenglDebugContext,
        OpenglProfile,
        ContextRobustness
    };

    enum class ContextCreationApiValue
    {
        Native = 0x00036001,                // GLFW_NATIVE_CONTEXT_API
        Egl = 0x00036002,                   // GLFW_EGL_CONTEXT_API
        Osmesa = 0x00036003                 // GLFW_OSMESA_CONTEXT_API
    };

    enum class ContextReleaseBehaviorValue
    {
        Any = 0,                            // GLFW_ANY_RELEASE_BEHAVIOR
        Flush = 0x00035001,                 // GLFW_RELEASE_BEHAVIOR_FLUSH
        None = 0x00035002                   // GLFW_RELEASE_BEHAVIOR_NONE
    };

    enum class ContextRobustnessValue
    {
        No = 0,                             // GLFW_NO_ROBUSTNESS
        NoResetNotification = 0x00031001,   // GLFW_NO_RESET_NOTIFICATION
        LoseContextOnReset = 0x00031002     // GLFW_LOSE_CONTEXT_ON_RESET
    };

    enum class CursorMode
    {
        Normal = 0x00034001,
        Hidden,
        Disable
    };

    enum class GamepadAxes
    {
        LeftX = 0,
        LeftY,
        RightX,
        RightY,
        LeftTrigger,
        RightTrigger,
        Last = RightTrigger
    };

    enum class GamepadKey
    {
        A = 0, B, X, Y,
        LeftBumper, RightBumper,
        Back, Start,
        Guide,
        LeftThumb, RightThumb,
        DpadUp, DpadRight, DpadDown, DpadLeft,
        Last = DpadLeft,
        Cross = A, Circle = B, Square = X, Triangle = Y
    };

    enum class JoystickHat
    {
        Undefined = -1,
        Centered = 0,
        Up,
        Right = 2,
        Down = 4,
        Left = 8,
        RightUp = Right | Up,
        RightDown = Right | Down,
        LeftUp = Left | Up,
        LeftDown = Left | Down
    };

    enum class JoystickId
    {
        Joystick1 = 0,
        Joystick2,
        Joystick3,
        Joystick4,
        Joystick5,
        Joystick6,
        Joystick7,
        Joystick8,
        Joystick9,
        Joystick10,
        Joystick11,
        Joystick12,
        Joystick13,
        Joystick14,
        Joystick15,
        Joystick16,
        JoystickLast = Joystick16
    };

    enum class OpenGlProfileValue
    {
        Any = 0,                            // GLFW_OPENGL_ANY_PROFILE
        Core = 0x00032001,                  // GLFW_OPENGL_CORE_PROFILE
        Compat = 0x00032002                 // GLFW_OPENGL_COMPAT_PROFILE
    };

    enum class PrintKey
    {
        Unknown = -1,
        Apostrophe = 39,
        Comma = 44, Minus, Period, Slash,
        Key0, Key1, Key2, Key3, Key4, Key5, Key6, Key7, Key8, Key9,
        Semicolon = 59,
        Equal = 61,
        A = 65, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        LeftBracket, Backslash, RightBracket,
        World1 = 161, World2,
        KP0 = 320, KP1, KP2, KP3, KP4, KP5, KP6, KP7, KP8, KP9,
        KPDecimal, KPDivide, KPMultiply, KPSubtract, KPAdd, KPEqual
    };

    enum class ErrorCode
    {
    };

    enum class KeyId
    {
        Unknown = -1,
        Space = 32,
        Apostrophe = 39,
        Comma = 44, Minus, Period, Slash,
        Key0, Key1, Key2, Key3, Key4, Key5, Key6, Key7, Key8, Key9,
        Semicolon = 59,
        Equal = 61,
        A = 65, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        LeftBracket, Backslash, RightBracket, GraveAccent = 96,
        World1 = 161, World2,
        Escape = 256, Enter, Tab, Backspace,
        Insert, Delete, Right, Left, Down, Up,
        PageUp, PageDown, Home, End,
        CapsLock = 280, ScrollLock, NumLock, PrintScreen, Pause,
        F1 = 290, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24, F25,
        Pad0 = 320, Pad1, Pad2, Pad3, Pad4, Pad, Pad6, Pad7, Pad8, Pad9,
        PadDecimal, PadDivide, PadMultiply, PadSubtract, PadAdd, PadEnter, PadEqual,
        LeftShift = 340, LeftControl, LeftAlt, LeftSuper,
        RightShift, RightControl, RightAlt, RightSuper,
        Menu,
        Last = Menu
    };

    enum class KeyState
    {
        Undefined = -1,
        Release = 0,
        Press,
        Repeat
    };

    enum class MonitorEvent
    {
        Connected = 0x00040001,
        Disconnected
    };

    enum class MouseKeyId
    {
        None = -1,
        Key1 = 0,
        Key2,
        Key3,
        Key4,
        Key5,
        Key6,
        Key7,
        Key8,
        Last = Key8,
        Left = Key1,
        Right = Key2,
        Middle = Key3
    };

    enum class StandartCursorForm
    {
        ArrowCursor = 0x00036001,
        IbeamCursor,
        CrosshairCursor,
        HandCursor,
        HResizeCursor,
        VResizeCursor
    };

    enum class WindowAttr
    {
        Focused = 0x00020001,
        Iconified,
        Resizable,
        Visible,
        Decorated,
        AutoIconify,
        Floating,
        Maximized,
        TransparentFramebuffer,
        Hovered,
        FocusOnShow
    };
}