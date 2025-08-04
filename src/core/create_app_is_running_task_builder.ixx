export module create_app_is_running_task_builder;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_app_is_running_task_builder() -> core::scheduler::TaskBuilder<bool>;
