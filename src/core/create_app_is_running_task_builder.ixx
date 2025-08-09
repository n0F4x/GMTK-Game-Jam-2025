export module create_app_is_running_task_builder;

import modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_app_is_running_task_builder() -> modules::scheduler::TaskBuilder<bool>;
