export module create_render_task_builder;

import ddge.modules.execution.TaskBuilder;

export [[nodiscard]]
auto create_render_task_builder() -> ddge::exec::TaskBuilder<void>;
