target_sources(${PROJECT_NAME} PRIVATE
        fire_weapon.cxx
        move_projectiles.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        fire_weapon.ixx
        move_projectiles.ixx
)
