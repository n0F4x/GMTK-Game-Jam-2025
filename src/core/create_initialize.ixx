export module create_initialize;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_initialize() -> core::scheduler::TaskBuilder<void>;
