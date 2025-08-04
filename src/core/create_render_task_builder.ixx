export module create_render_task_builder;

import core.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_render_task_builder() -> core::scheduler::TaskBuilder<void>;
