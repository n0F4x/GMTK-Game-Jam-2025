export module create_run_task_builder;

import ddge.modules.execution.TaskBuilder;

export [[nodiscard]]
auto create_run_task_builder() -> ddge::exec::TaskBuilder<void>;
