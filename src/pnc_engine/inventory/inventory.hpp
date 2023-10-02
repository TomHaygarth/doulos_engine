#pragma once

#include "data/variable.hpp"

#include <cinttypes>
#include <string>
#include <vector>

namespace DoulosEngine
{
    struct SInventoryVariable
    {
        std::string name;
        SVariable value;
    };

    struct SInventoryObject
    {
        uint32_t object_id;
        uint8_t quantity;
    };

    struct SInventory
    {
        std::vector<SInventoryVariable> variables;
        std::vector<SInventoryObject> objects;
    };
}