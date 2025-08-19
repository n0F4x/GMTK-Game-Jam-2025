export module create_initialize_task_builder;

import ddge.modules.execution.TaskBuilder;

export [[nodiscard]]
auto create_initialize_task_builder() -> ddge::exec::TaskBuilder<void>;
