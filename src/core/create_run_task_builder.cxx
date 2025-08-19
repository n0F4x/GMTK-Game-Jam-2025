module create_run_task_builder;

import ddge.modules.execution;

import create_initialize_task_builder;
import create_loop_game_task_builder;
import create_shut_down_task_builder;

auto create_run_task_builder() -> ddge::exec::TaskBuilder<void>
{
    return ddge::exec::start_as(create_initialize_task_builder())   //
        .then(create_loop_game_task_builder())
        .then(create_shut_down_task_builder());
}
