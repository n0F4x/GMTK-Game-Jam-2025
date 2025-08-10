export module create_run_task_builder;

import ddge.modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_run_task_builder() -> ddge::scheduler::TaskBuilder<void>;
