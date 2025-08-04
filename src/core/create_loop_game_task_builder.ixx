export module create_loop_game_task_builder;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_loop_game_task_builder() -> core::scheduler::TaskBuilder<void>;
