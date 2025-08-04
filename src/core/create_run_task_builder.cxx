module create_run_task_builder;

import core.scheduler.TaskBuilder;
import extensions.scheduler;

import create_initialize_task_builder;
import create_loop_game_task_builder;
import create_shut_down_task_builder;

auto create_run_task_builder() -> core::scheduler::TaskBuilder<void>
{
    return extensions::scheduler::start_as(create_initialize_task_builder())   //
        .then(create_loop_game_task_builder())
        .then(create_shut_down_task_builder());
}
