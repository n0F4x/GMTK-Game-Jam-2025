export module create_reset_timers_task_builder;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_reset_timers_task_builder() -> core::scheduler::TaskBuilder<void>;
