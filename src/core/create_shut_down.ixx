export module create_shut_down;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_shut_down() -> core::scheduler::TaskBuilder<void>;
