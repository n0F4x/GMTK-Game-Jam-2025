module;

#include <stack>

export module states.DialogState;

import ddge.modules.ecs;

export struct DialogState {
    std::stack<ddge::ecs::ID> dialog_ids;
};
