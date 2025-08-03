target_sources(${PROJECT_NAME} PRIVATE
        app_is_running.cxx
        initialize.cxx
        loop_game.cxx
        render.cxx
        reset_timers.cxx
        run.cxx
        shut_down.cxx
        update.cxx
        update_timers.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        app_is_running.ixx
        initialize.ixx
        loop_game.ixx
        render.ixx
        reset_timers.ixx
        run.ixx
        setup.ixx
        shut_down.ixx
        update.ixx
        update_timers.ixx
)
