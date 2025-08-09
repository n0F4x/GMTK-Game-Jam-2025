export module create_shut_down_task_builder;

import modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_shut_down_task_builder() -> modules::scheduler::TaskBuilder<void>;
