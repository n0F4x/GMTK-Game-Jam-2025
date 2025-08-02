target_sources(${PROJECT_NAME} PRIVATE
        create_player.cxx
        move_player.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        create_player.ixx
        move_player.ixx
        update_player.ixx
)
