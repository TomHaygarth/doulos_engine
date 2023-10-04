#pragma once

#include "inventory/inventory.hpp"
#include "sequences/requirement.hpp"

#include <cinttypes>
#include <vector>

namespace DoulosEngine
{
    enum class ESequenceNodeType
    {
        Dialogue,
        Choice,
        AddItem,
        RemoveItem,
        UpdateVariable,
        EventTrigger
    };

    struct SSequenceNodeBase
    {
        uint64_t id = 0;
        ESequenceNodeType const type;
        std::vector<SNodeVariableRequirement> variable_requirements;
        std::vector<SNodeObjectRequirement> object_requirements;

        bool visited = false;

        SSequenceNodeBase(ESequenceNodeType const node_type) : type(node_type) {}
        virtual ~SSequenceNodeBase() = default;
    };

    struct SSequenceDialogueNode : public SSequenceNodeBase
    {
        SSequenceDialogueNode() : SSequenceNodeBase(ESequenceNodeType::Dialogue) {};
    };

    struct SSequenceChoiceNode : public SSequenceNodeBase
    {
        SSequenceChoiceNode() : SSequenceNodeBase(ESequenceNodeType::Choice) {};
    };

    struct SSequenceAddItemNode : public SSequenceNodeBase
    {
        SSequenceAddItemNode() : SSequenceNodeBase(ESequenceNodeType::AddItem) {};
        uint32_t item_id = 0;
        uint8_t quantity = 0;
    };

    struct SSequenceRemoveItemNode : public SSequenceNodeBase
    {
        SSequenceRemoveItemNode() : SSequenceNodeBase(ESequenceNodeType::RemoveItem) {};
        uint32_t item_id = 0;
        uint8_t quantity = 0;
    };

    struct SSequenceUpdateVariableNode : public SSequenceNodeBase
    {
        SSequenceUpdateVariableNode() : SSequenceNodeBase(ESequenceNodeType::UpdateVariable) {};
        SInventoryVariable variable;

        enum class EOp : uint8_t
        {
            ADD,
            SUBTRACT,
            MULTIPLY,
            DIVIDE,

            SET
        } op;
    };

    struct ISequenceEventTriggerNode : public SSequenceNodeBase
    {
        ISequenceEventTriggerNode() : SSequenceNodeBase(ESequenceNodeType::EventTrigger) {};
    };
}