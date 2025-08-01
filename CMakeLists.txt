cmake_minimum_required(VERSION 3.30)
project(game)

add_executable(${PROJECT_NAME})

find_package(engine CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE engine::engine)

find_package(SFML CONFIG REQUIRED COMPONENTS Graphics Audio)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Audio)

find_package(GLEW REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)

add_subdirectory(src)

target_compile_options(${PROJECT_NAME} PRIVATE
        -ftime-trace=file.json
)
