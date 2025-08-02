module player.idle_animation;

import common.textures;
import components.Animation;

[[nodiscard]]
auto idle_animation() noexcept -> const Animation&
{
    static const Animation result{
        .textures{
                  textures::player_idle[0],
                  textures::player_idle[0],
                  textures::player_idle[0],

                  textures::player_idle[1],
                  textures::player_idle[1],
                  textures::player_idle[1],
                  textures::player_idle[1],
                  textures::player_idle[1],
                  textures::player_idle[1],
                  textures::player_idle[1],

                  textures::player_idle[0],
                  textures::player_idle[0],
                  }
    };

    return result;
}
