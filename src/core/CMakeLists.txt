target_sources(${PROJECT_NAME} PRIVATE
        create_app_is_running_task_builder.cxx
        create_initialize_task_builder.cxx
        create_loop_game_task_builder.cxx
        create_render_task_builder.cxx
        create_reset_timers_task_builder.cxx
        create_run_task_builder.cxx
        create_shut_down_task_builder.cxx
        create_update_task_builder.cxx
        create_update_timers_task_builder.cxx
        setup.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        create_app_is_running_task_builder.ixx
        create_initialize_task_builder.ixx
        create_loop_game_task_builder.ixx
        create_render_task_builder.ixx
        create_reset_timers_task_builder.ixx
        create_run_task_builder.ixx
        create_shut_down_task_builder.ixx
        create_update_task_builder.ixx
        create_update_timers_task_builder.ixx
        setup.ixx
)
