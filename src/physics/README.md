# Collision checking, entity movement module

## Primary components
- Position: entities without position cannot be moved.
- Moveable: Describes the speed the entity wants to move with.
- Solid: The object is solid.
- Hitbox: Entity with a hitbox cannot go through solid entities.

## Extra components
- MovementSpeed: if the entity is moveable, the movement speed will be capped at this.

## Movement

It is a double-query
TODO write description
