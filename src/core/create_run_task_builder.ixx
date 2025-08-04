export module create_run_task_builder;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_run_task_builder() -> core::scheduler::TaskBuilder<void>;
