target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        Animation.ixx
        Drawable.ixx
        Enemy.ixx
        Health.ixx
        Hitbox.ixx
        MovementSpeed.ixx
        Player.ixx
        Position.ixx
        SFMLComponent.ixx
        Solid.ixx
        Tile.ixx
        Velocity.ixx
        Weapon.ixx
        WeaponProjectile.ixx
)
