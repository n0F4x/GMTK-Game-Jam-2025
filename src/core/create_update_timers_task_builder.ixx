export module create_update_timers_task_builder;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_update_timers_task_builder() -> core::scheduler::TaskBuilder<void>;
