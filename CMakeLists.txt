cmake_minimum_required(VERSION 3.28)
project(bomberman LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(bomberman src/main.cpp
                src/TileMapView.h src/TileMapView.cpp
                src/TileMap.h src/TileMap.cpp
                src/Tile.h    src/Tile.cpp)


add_custom_target(copy_resources ALL 
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/resources
        ${PROJECT_BINARY_DIR}/resources
        COMMENT "copying resources into binary directory")

add_dependencies(bomberman copy_resources)

target_compile_features(bomberman PRIVATE cxx_std_17)
target_link_libraries(bomberman PRIVATE SFML::Graphics)
