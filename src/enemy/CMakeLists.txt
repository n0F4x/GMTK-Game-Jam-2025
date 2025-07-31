target_sources(${PROJECT_NAME} PRIVATE
        move_enemy.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        Enemy.ixx
        create_enemy.ixx
        move_enemy.ixx
        update_enemy.ixx
)
