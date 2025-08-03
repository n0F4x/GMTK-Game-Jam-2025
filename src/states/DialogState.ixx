module;

#include <stack>

export module states.DialogState;

import core.ecs;

export struct DialogState {
    std::stack<core::ecs::ID> dialog_ids;
};
