export module AppBuilder;

import app;
import plugins;

export using AppBuilder = app::Builder<
    plugins::Assets,
    plugins::ECS,
    plugins::Events,
    plugins::Functional,
    plugins::Messages,
    plugins::Resources,
    plugins::Scheduler,
    plugins::States>;
