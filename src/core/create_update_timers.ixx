export module create_update_timers;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_update_timers() -> core::scheduler::TaskBuilder<void>;
