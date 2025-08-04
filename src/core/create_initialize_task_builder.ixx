export module create_initialize_task_builder;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_initialize_task_builder() -> core::scheduler::TaskBuilder<void>;
