target_sources(${PROJECT_NAME} PRIVATE
        animations.cxx
        create_player.cxx
        move_player.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        animations.ixx
        create_player.ixx
        move_player.ixx
        update_player.ixx
        follow_player.ixx
)
