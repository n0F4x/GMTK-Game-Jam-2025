export module create_update_task_builder;

import ddge.modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_update_task_builder() -> ddge::scheduler::TaskBuilder<void>;
