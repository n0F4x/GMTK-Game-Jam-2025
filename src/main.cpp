import app;

import plugins;
import window.setup;
import run;
import common.GlobalState;
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
        .register_state<GlobalState>()
        .transform(window::setup)
        .run(run);
}
