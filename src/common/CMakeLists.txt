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
        FontLoader.ixx
        Fonts.ixx
        load_fonts.ixx
        load_textures.ixx
        load_shaders.ixx
        ShaderLoader.ixx
        Shaders.ixx
        SoundBufferLoader.ixx
        TextureLoader.ixx
        Textures.ixx
)
