export module create_app_is_running_task_builder;

import ddge.modules.execution.TaskBuilder;

export [[nodiscard]]
auto create_app_is_running_task_builder() -> ddge::exec::TaskBuilder<bool>;
