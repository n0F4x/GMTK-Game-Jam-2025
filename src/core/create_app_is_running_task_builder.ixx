export module create_app_is_running_task_builder;

import ddge.modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_app_is_running_task_builder() -> ddge::scheduler::TaskBuilder<bool>;
