module;

#include <memory>

#include <SFML/Graphics/CircleShape.hpp>
module ui.initUI;

import extensions.scheduler.accessors.ecs.Registry;
import components.SFMLComponent;
import window.Window;

using namespace extensions::scheduler::accessors::ecs;

struct HealthBarStuff : SFDrawable {
    sf::CircleShape shape{ 50.f };

    HealthBarStuff()
    {
        shape.setFillColor(sf::Color(7, 201, 217));
        shape.setPosition({ 50, 50 });
    }

    void draw(window::Window& window) override
    {
        window.draw(shape);
    }
};

auto ui::createUI(Registry registry) -> void
{
    registry->create(SFMLComponent{ std::make_shared<HealthBarStuff>() });
}

