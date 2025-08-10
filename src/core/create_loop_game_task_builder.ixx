export module create_loop_game_task_builder;

import ddge.modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_loop_game_task_builder() -> ddge::scheduler::TaskBuilder<void>;
