#pragma once

#include <bitset>
#include <cinttypes>

using action_mask_t = std::bitset<64>;

namespace DoulosEngine
{
    struct SObject
    {
        uint64_t id = 0;
        action_mask_t supported_actions = 0;
    };
}