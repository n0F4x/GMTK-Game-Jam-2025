module;

#include <array>

#include <SFML/System/Vector2.hpp>

export module common.textures;

import states.Textures;

namespace textures {

export inline constexpr Textures::Texture demon{
    { 0, 0 }
};

export inline constexpr std::array player_idle{
    Textures::Texture{ { 32, 0 } },
    Textures::Texture{ { 2 * 32, 0 } },
};

export inline constexpr Textures::Texture projectile{
    { 3 * 32, 0 }
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

export inline constexpr std::array player_with_weapon{
    Textures::Texture{ { 448, 0 }, { 46, 46 } },
    Textures::Texture{ { 494, 0 }, { 46, 46 } }
};

export inline constexpr std::array player_back_with_weapon{
    Textures::Texture{ { 540, 0 }, { 46, 46 } },
    Textures::Texture{ { 586, 0 }, { 46, 46 } }
};

export inline constexpr std::array player_shoot{
    Textures::Texture{ { 632, 0 }, { 46, 46 } },
    Textures::Texture{ { 678, 0 }, { 46, 46 } }
};


export inline constexpr std::array player_move_gun{
    Textures::Texture{ { 724, 0 }, { 46, 46 } },
    Textures::Texture{ { 770, 0 }, { 46, 46 } }
};

export inline constexpr std::array player_move{
    Textures::Texture{ { 32 * 12, 0 } },
    Textures::Texture{ { 32 * 13, 0 } },
};


}   // namespace textures
