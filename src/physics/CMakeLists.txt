target_sources(${PROJECT_NAME} PRIVATE
        physics.cxx
        collider.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        physics.ixx
        collider.ixx
)
