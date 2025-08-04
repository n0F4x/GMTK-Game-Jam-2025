export module create_update;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_update() -> core::scheduler::TaskBuilder<void>;
