module;

#include <stack>

export module states.DialogState;

import modules.ecs;

export struct DialogState {
    std::stack<modules::ecs::ID> dialog_ids;
};
