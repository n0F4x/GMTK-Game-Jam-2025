export module create_app_is_running;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_app_is_running() -> core::scheduler::TaskBuilder<bool>;
