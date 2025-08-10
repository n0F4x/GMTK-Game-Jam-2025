export module create_initialize_task_builder;

import ddge.modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_initialize_task_builder() -> ddge::scheduler::TaskBuilder<void>;
