export module create_initialize_task_builder;

import modules.scheduler.TaskBuilder;

export [[nodiscard]]
auto create_initialize_task_builder() -> modules::scheduler::TaskBuilder<void>;
