#pragma once

#include <cinttypes>

namespace DoulosEngine
{
    struct SVariable
    {
        enum class EType : uint8_t
        {
            Bool,
            Int,
            Float
        } type;

        union entry_value_t
        {
            bool b;
            int32_t i;
            float f;
        } value;
    }
}