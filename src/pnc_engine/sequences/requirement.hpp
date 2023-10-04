#pragma once

#include <cinttypes>

#include "inventory/inventory.hpp"

namespace DoulosEngine
{
    enum class EReqComparisonOp : uint8_t
    {
        Equal,
        NotEqual,
        LessThan,
        MoreThan,
        LessThanOrEqual,
        MoreThanOrEqual,
    };

    struct SNodeVariableRequirement
    {
        EReqComparisonOp op = EReqComparisonOp::Equal;
        SInventoryVariable variable;
    };

    struct SNodeObjectRequirement
    {
        EReqComparisonOp op = EReqComparisonOp::Equal;
        uint64_t object_id;
    };
}