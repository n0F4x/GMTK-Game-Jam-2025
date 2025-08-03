module run;

import core.scheduler.TaskBuilder;
import extensions.scheduler;

import initialize;
import loop_game;
import shut_down;

const core::scheduler::TaskBuilder<void> run =
    extensions::scheduler::start_as(initialize)   //
        .then(loop_game)
        .then(shut_down);
