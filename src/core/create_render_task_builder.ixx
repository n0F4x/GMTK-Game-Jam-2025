export module create_render_task_builder;

import ddge.modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_render_task_builder() -> ddge::scheduler::TaskBuilder<void>;
