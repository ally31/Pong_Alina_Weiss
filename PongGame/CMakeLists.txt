cmake_minimum_required(VERSION 3.11)

# Projektname und C++-Standard
project(PongGame)
set(CMAKE_CXX_STANDARD 17)

# Raylib-Cpp Setup (relative Pfad)
# Falls du raylib-cpp nicht als Submodul hast, wird es über FetchContent hinzugefügt
set(RAYLIB_CPP_DIR "${CMAKE_SOURCE_DIR}/PongGame/raylib-cpp/v451")

# Quellcode-Dateien
set(SRC_FILES
        ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/paddle.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/ball.cpp
)

# Header-Dateien
set(INCLUDE_DIRS
        ${CMAKE_CURRENT_LIST_DIR}/include
        ${RAYLIB_CPP_DIR}   # Hier den Pfad zu raylib-cpp angeben
)

# Füge das Executable hinzu
add_executable(PongGame ${SRC_FILES})

# Include-Pfade hinzufügen
target_include_directories(PongGame PRIVATE ${INCLUDE_DIRS})

# Verlinke Raylib (über FetchContent oder das bereits installierte Raylib)
target_link_libraries(PongGame raylib)

# Wenn auf macOS, verlinke zusätzliche Frameworks
if (APPLE)
    target_link_libraries(PongGame "-framework IOKit")
    target_link_libraries(PongGame "-framework Cocoa")
    target_link_libraries(PongGame "-framework OpenGL")
endif()
