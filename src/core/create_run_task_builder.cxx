module create_run_task_builder;

import modules.scheduler;

import create_initialize_task_builder;
import create_loop_game_task_builder;
import create_shut_down_task_builder;

auto create_run_task_builder() -> modules::scheduler::TaskBuilder<void>
{
    return modules::scheduler::start_as(create_initialize_task_builder())   //
        .then(create_loop_game_task_builder())
        .then(create_shut_down_task_builder());
}
