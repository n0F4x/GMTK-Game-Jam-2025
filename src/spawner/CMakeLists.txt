target_sources(${PROJECT_NAME} PRIVATE
        tick_spawner.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        tick_spawner.ixx
        SpawnerTimer.ixx
        update_spawner.ixx
)
