module player.animations;

import common.textures;
import components.Animation;

[[nodiscard]]
auto generate_id() -> unsigned
{
    static unsigned next_id{};
    return next_id++;
}

[[nodiscard]]
auto idle_animation_front() noexcept -> const Animation&
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
                  },
        .id = generate_id(),
    };

    return result;
}

[[nodiscard]]
auto idle_animation_back() noexcept -> const Animation&
{
    static const Animation result{
        .textures{
                  textures::player_idle_back[0],
                  textures::player_idle_back[0],
                  textures::player_idle_back[0],

                  textures::player_idle_back[1],
                  textures::player_idle_back[1],
                  textures::player_idle_back[1],
                  textures::player_idle_back[1],
                  textures::player_idle_back[1],
                  textures::player_idle_back[1],
                  textures::player_idle_back[1],

                  textures::player_idle_back[0],
                  textures::player_idle_back[0],
                  },
        .id = generate_id(),
    };

    return result;
}

auto run_animation_front() noexcept -> const Animation&
{
    return idle_animation_front();
}

auto run_animation_back() noexcept -> const Animation&
{
    return idle_animation_back();
}
