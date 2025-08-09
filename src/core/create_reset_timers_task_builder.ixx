export module create_reset_timers_task_builder;

import modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_reset_timers_task_builder() -> modules::scheduler::TaskBuilder<void>;
