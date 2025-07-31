target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        GameTickTimer.ixx
        GlobalState.ixx
        load_textures.ixx
        SoundBufferLoader.ixx
        TextureLoader.ixx
        Textures.ixx
        Position.ixx
)
