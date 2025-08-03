module;

#include <array>

#include <SFML/System/Vector2.hpp>

export module common.textures;

import states.Textures;

namespace textures {

export inline constexpr Textures::Texture demon_idle{
    { 0, 0 }
};

export inline constexpr std::array demon_move{
    Textures::Texture{ { 8 * 32, 0 } },
    Textures::Texture{ { 9 * 32, 0 } },
};

export inline constexpr std::array player_idle{
    Textures::Texture{ { 32, 0 } },
    Textures::Texture{ { 2 * 32, 0 } },
};

export inline constexpr Textures::Texture projectile{
    { 11 * 32, 0 }
};

export inline constexpr Textures::Texture fireball{
        { 10 * 32, 0 }
};

export inline constexpr std::array player_idle_back{
    Textures::Texture{ { 4 * 32, 0 } },
    Textures::Texture{ { 5 * 32, 0 } },
};

export inline constexpr Textures::Texture debug_tile{
    { 7 * 32, 0 }
};

export constexpr Textures::Texture vertical_door{
    { 0, 32 }
};

export constexpr Textures::Texture vertical_door_open{
    { 1 * 32, 32 }
};

export inline constexpr Textures::Texture horizontal_door{
    { 2 * 32, 32 }
};

export constexpr Textures::Texture horizontal_door_open{
    { 3 * 32, 32 }
};

export inline constexpr Textures::Texture trapdoor{
    { 4 * 32, 32 }
};

export constexpr Textures::Texture trapdoor_open{
    { 5 * 32, 32 }
};

export inline constexpr Textures::Texture nothing{
    { 127 * 32, 127 * 32 }
};

export inline constexpr std::array player_move{
    Textures::Texture{ { 32 * 12, 0 } },
    Textures::Texture{ { 32 * 13, 0 } },
};

export inline constexpr std::array player_with_weapon{
    Textures::Texture{ { 448, 0 }, { 46, 46 } },
    Textures::Texture{ { 494, 0 }, { 46, 46 } }
};

export inline constexpr std::array player_back_with_weapon{
    Textures::Texture{ { 540, 0 }, { 46, 46 } },
    Textures::Texture{ { 586, 0 }, { 46, 46 } }
};

export inline constexpr Textures::Texture player_shoot{
    { 632,  0 },
    {  46, 46 }
};

export inline constexpr Textures::Texture player_back_shoot{
    { 678,  0 },
    {  46, 46 }
};

export inline constexpr std::array player_move_gun{
    Textures::Texture{ { 724, 0 }, { 46, 46 } },
    Textures::Texture{ { 770, 0 }, { 46, 46 } }
};

export inline constexpr Textures::Texture player_damaged{
        { 816,  0 },
        {  46, 46 }
};

export inline constexpr std::array boss_attack{
    Textures::Texture{ { 1088, 0 }, { 64, 64 } },
    Textures::Texture{ { 1152, 0 }, { 64, 64 } }
};

export inline constexpr std::array home{
    Textures::Texture{ { 0, 1936 }, { 1920, 1080 } },
    Textures::Texture{ { 0, 3016 }, { 1920, 1080 } }
};

}   // namespace textures
