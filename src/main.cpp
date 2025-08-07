import app;

import plugins;
import setup;
import create_run_task_builder;
import states.GlobalState;
import core.ecs;

import AppBuilder;

auto main() -> int
{
    AppBuilder{}.transform(setup).run(create_run_task_builder());
}
