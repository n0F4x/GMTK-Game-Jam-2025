module create_run;

import core.scheduler.TaskBuilder;
import extensions.scheduler;

import create_initialize;
import create_loop_game;
import create_shut_down;

auto create_run() -> core::scheduler::TaskBuilder<void>
{
    return extensions::scheduler::start_as(create_initialize())   //
        .then(create_loop_game())
        .then(create_shut_down());
}
