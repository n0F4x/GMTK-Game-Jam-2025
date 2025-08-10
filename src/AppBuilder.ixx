export module AppBuilder;

import ddge.prelude;
import ddge.modules.app;

export using AppBuilder = ddge::app::Builder<
    ddge::plugins::Assets,
    ddge::plugins::ECS,
    ddge::plugins::Events,
    ddge::plugins::Functional,
    ddge::plugins::Messages,
    ddge::plugins::Resources,
    ddge::plugins::Scheduler,
    ddge::plugins::States>;
