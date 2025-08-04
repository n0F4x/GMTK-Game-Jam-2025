export module create_run;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_run() -> core::scheduler::TaskBuilder<void>;
