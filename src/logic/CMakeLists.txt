add_subdirectory(event_handlers)

target_sources(${PROJECT_NAME} PRIVATE
        progress_animations.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        handle_events.ixx
        pause_or_resume_game_on_input.ixx
        progress_animations.ixx
        destroy_dead_enemies.ixx
)
