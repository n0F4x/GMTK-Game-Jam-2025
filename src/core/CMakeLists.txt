target_sources(${PROJECT_NAME} PRIVATE
        create_app_is_running.cxx
        create_initialize.cxx
        create_loop_game.cxx
        create_render.cxx
        create_reset_timers.cxx
        create_run.cxx
        create_shut_down.cxx
        create_update.cxx
        create_update_timers.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        create_app_is_running.ixx
        create_initialize.ixx
        create_loop_game.ixx
        create_render.ixx
        create_reset_timers.ixx
        create_run.ixx
        create_shut_down.ixx
        create_update.ixx
        create_update_timers.ixx
        setup.ixx
)
