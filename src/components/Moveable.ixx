module;

#include <SFML/System/Vector2.hpp>

export module components.Moveable;

/**
 * An entity with this component can be moved (not teleported).
 * It won't be able to go through SOLID components.
 *
 * To move a MOVABLE entity, set the speed in this component.
 */
export struct Moveable {
    /**
     * AI, PlayerInput and other things can change this to set the entity's speed.
     * If the entity has MovementSpeed component, the velocity will be capped to that.
     */
    sf::Vector2f velocity;


    /**
     * A feedback from the engine telling the direction the entity was moving.
     * This is updated before rendering, so it can be used to do directional animations
     */
    sf::Vector2f lastStep;
};
