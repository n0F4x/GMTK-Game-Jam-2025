target_sources(${PROJECT_NAME} PRIVATE
        despawn_dialog.cxx
        spawn_dialog.cxx
)

target_sources(${PROJECT_NAME} PRIVATE
        FILE_SET private_cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        despawn_dialog.ixx
        Dialog.ixx
        spawn_dialog.ixx
        update_dialogs.ixx
)
