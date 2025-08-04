export module create_shut_down_task_builder;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_shut_down_task_builder() -> core::scheduler::TaskBuilder<void>;
