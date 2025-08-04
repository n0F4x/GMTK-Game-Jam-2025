export module create_loop_game;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_loop_game() -> core::scheduler::TaskBuilder<void>;
