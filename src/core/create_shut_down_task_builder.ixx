export module create_shut_down_task_builder;

import ddge.modules.execution.TaskBuilder;

export [[nodiscard]]
auto create_shut_down_task_builder() -> ddge::exec::TaskBuilder<void>;
