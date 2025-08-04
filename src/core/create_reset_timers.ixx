export module create_reset_timers;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_reset_timers() -> core::scheduler::TaskBuilder<void>;
