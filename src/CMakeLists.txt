add_subdirectory(common)
add_subdirectory(events)
add_subdirectory(player)
add_subdirectory(enemy)
add_subdirectory(window)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        initialize.ixx
        loop_game.ixx
        render.ixx
        run.ixx
        setup.ixx
        should_exit.ixx
        shutdown.ixx
        update.ixx
)

target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
)
