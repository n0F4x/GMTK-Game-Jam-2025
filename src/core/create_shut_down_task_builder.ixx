export module create_shut_down_task_builder;

import ddge.modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_shut_down_task_builder() -> ddge::scheduler::TaskBuilder<void>;
