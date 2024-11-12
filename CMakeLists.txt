cmake_minimum_required(VERSION 3.11)

# Projektname und C++-Standard
project(PongGame)
set(CMAKE_CXX_STANDARD 17)

# Raylib-Version und Setup
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET oder REQUIRED

# Falls Raylib nicht gefunden wird, wird es von GitHub heruntergeladen und eingebaut
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # Keine Beispielprogramme bauen
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# Füge das PongGame Verzeichnis zu den Unterordnern hinzu
add_subdirectory(PongGame)
