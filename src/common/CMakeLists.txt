target_sources(${PROJECT_NAME} PRIVATE
        GlobalState.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        GameTickTimer.ixx
        GlobalState.ixx
        SoundBufferLoader.ixx
        TextureLoader.ixx
        ShaderLoader.ixx
        Drawable.ixx
        Textures.ixx
        Shaders.ixx
        load_textures.ixx
        load_shaders.ixx
        Position.ixx
)
