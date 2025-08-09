export module create_loop_game_task_builder;

import modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_loop_game_task_builder() -> modules::scheduler::TaskBuilder<void>;
