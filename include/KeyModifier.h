#pragma once

#include "Defines.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    enum class KeyModifier
    {
        None = 0x000,
        Shift = 0x0001,
        Control = 0x0002,
        Alt = 0x0004,
        Super = 0x0008,
        CapsLock = 0x0010,
        NumLock = 0x0020
    };

    constexpr KeyModifier operator~(const KeyModifier& mkt)
    {
        return static_cast<KeyModifier>(static_cast<int>(mkt));
    }

#define OPERATOR_DEFINE(T1, OP, T2) constexpr KeyModifier operator##OP(const T1& lhs, const T2& rhs) \
    { \
        return KeyModifier{ static_cast<int>(lhs) OP static_cast<int>(rhs) }; \
    }
    OPERATOR_DEFINE(KeyModifier, &, KeyModifier);
    OPERATOR_DEFINE(KeyModifier, &, int);
    OPERATOR_DEFINE(int, &, KeyModifier);
    OPERATOR_DEFINE(KeyModifier, | , KeyModifier);
    OPERATOR_DEFINE(KeyModifier, | , int);
    OPERATOR_DEFINE(int, | , KeyModifier);
    OPERATOR_DEFINE(KeyModifier, ^, KeyModifier);
    OPERATOR_DEFINE(KeyModifier, ^, int);
    OPERATOR_DEFINE(int, ^, KeyModifier);
#undef OPERATOR_DEFINE

#define OPERATOR_DEFINE(OP) constexpr KeyModifier& operator OP(KeyModifier& lhs, const int& rhs) \
    { \
        lhs OP rhs; \
        return lhs; \
    }
    OPERATOR_DEFINE(&= );
    OPERATOR_DEFINE(|= );
    OPERATOR_DEFINE(^= );
#undef OPERATOR_DEFINE
}