#pragma once

#include "data/variable.hpp"

#include <cinttypes>
#include <string>
#include <vector>

namespace DoulosEngine
{
    struct SInventoryVariable
    {
        static constexpr uint32_t const global_bit = 1 << 31;

        uint32_t id = 0;
        SVariable value;
    };

    struct SInventoryObject
    {
        uint32_t object_id;
        uint8_t quantity;
    };

    struct SInventory
    {
        std::vector<SInventoryVariable> global_variables;
        std::vector<SInventoryVariable> local_variables;
        std::vector<SInventoryObject> objects;
    };
}