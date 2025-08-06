import app;

import plugins;
import setup;
import create_run_task_builder;
import states.GlobalState;
import core.ecs;

auto main() -> int
{
    app::create()
        .plug_in(plugins::Scheduler{})
        .plug_in(plugins::Resources{})
        .plug_in(plugins::States{})
        .plug_in(plugins::Events{})
        .plug_in(plugins::Messages{})
        .plug_in(plugins::ECS{})
        .plug_in(plugins::Assets{})
        .plug_in(plugins::Functional{})
        .transform(setup)
        .run(create_run_task_builder());
}
