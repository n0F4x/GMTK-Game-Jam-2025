module;

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
module ui.initUI;

import extensions.scheduler.accessors.ecs.Registry;
import extensions.scheduler.accessors.states.State;
import common.Fonts;
import components.SFMLComponent;
import window.Window;

using namespace extensions::scheduler::accessors;

struct HealthBarStuff : SFDrawable {
    sf::CircleShape shape{ 50.f };
    sf::Text        text;

    explicit HealthBarStuff(const sf::Font& font) : text{ font }
    {
        shape.setFillColor(sf::Color(7, 201, 217));
        shape.setPosition({ 50, 50 });

        text.setString("Hello GMTK!");
        text.setPosition({ 50, 200 });
    }

    void draw(window::Window& window) override
    {
        window.draw(shape);
        window.draw(text);
    }
};

auto ui::createUI(const Registry registry, State<Fonts> fonts) -> void
{
    // const sf::Font& font = *(fonts->std_font.get());
    // registry->create(SFMLComponent{ std::make_shared<HealthBarStuff>(font) });
}
