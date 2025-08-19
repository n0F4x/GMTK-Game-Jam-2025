export module create_update_timers_task_builder;

import ddge.modules.execution.TaskBuilder;

export [[nodiscard]]
auto create_update_timers_task_builder() -> ddge::exec::TaskBuilder<void>;
