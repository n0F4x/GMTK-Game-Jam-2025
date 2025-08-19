export module create_reset_timers_task_builder;

import ddge.modules.execution.TaskBuilder;

export [[nodiscard]]
auto create_reset_timers_task_builder() -> ddge::exec::TaskBuilder<void>;
