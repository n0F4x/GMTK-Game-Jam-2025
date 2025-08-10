export module AppBuilder;

import prelude;
import modules.app;

export using AppBuilder = modules::app::Builder<
    plugins::Assets,
    plugins::ECS,
    plugins::Events,
    plugins::Functional,
    plugins::Messages,
    plugins::Resources,
    plugins::Scheduler,
    plugins::States>;
