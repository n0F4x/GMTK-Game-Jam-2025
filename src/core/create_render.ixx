export module create_render;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_render() -> core::scheduler::TaskBuilder<void>;
