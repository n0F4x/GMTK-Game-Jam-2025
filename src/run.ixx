export module run;

import core.scheduler;

import initialize;
import loop_game;
import shutdown;

export inline constexpr auto run = core::scheduler::start_as(initialize)   //
                                       .then(loop_game)
                                       .then(shut_down);
