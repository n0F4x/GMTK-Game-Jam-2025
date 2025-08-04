import app;

import plugins;
import setup;
import create_run_task_builder;
import states.GlobalState;
import core.ecs;

auto main() -> int
{
    app::create()
        .plug_in(plugins::scheduler)
        .plug_in(plugins::resources)
        .plug_in(plugins::states)
        .plug_in(plugins::events)
        .plug_in(plugins::messages)
        .plug_in(plugins::ecs)
        .plug_in(plugins::assets)
        .plug_in(plugins::functional)
        .transform(setup)
        .run(create_run_task_builder());
}
