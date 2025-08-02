target_sources(${PROJECT_NAME} PRIVATE
        initUI.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        initUI.ixx
)
