export module create_loop_game_task_builder;

import ddge.modules.execution.TaskBuilder;

export [[nodiscard]]
auto create_loop_game_task_builder() -> ddge::exec::TaskBuilder<void>;
