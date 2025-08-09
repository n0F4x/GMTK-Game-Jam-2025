module;

#include <string>

export module components.Spawner;

import modules.scheduler.accessors;

export struct Spawner {
    bool is_active;
    int  remaining_spawns;
    char tile_char;
    char enemy_type;
    int health;
    float damage;
    float movement_speed;
};
