target_sources(${PROJECT_NAME} PRIVATE
        create_enemies.cxx
        move_enemy.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        create_enemies.ixx
        move_enemy.ixx
        update_enemy.ixx
)
