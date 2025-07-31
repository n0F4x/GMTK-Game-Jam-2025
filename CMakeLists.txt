cmake_minimum_required(VERSION 3.30)
project(game)

add_executable(${PROJECT_NAME})

find_package(engine CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE engine::engine)

find_package(SFML CONFIG REQUIRED COMPONENTS Graphics)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)

add_subdirectory(src)

target_compile_options(${PROJECT_NAME} PRIVATE
        -ftime-trace=file.json
)
