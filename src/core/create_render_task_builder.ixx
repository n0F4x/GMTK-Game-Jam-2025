export module create_render_task_builder;

import modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_render_task_builder() -> modules::scheduler::TaskBuilder<void>;
