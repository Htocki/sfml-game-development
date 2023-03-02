cmake_minimum_required(VERSION 3.25)

set(PROJ project)
set(EXEC executable)

project(${PROJ} LANGUAGES CXX)

add_executable(${EXEC} main.cpp)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
endif()

include(FetchContent)

# sfml
set(BUILD_SHARED_LIBS false)
FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        2.5.1
)

FetchContent_MakeAvailable(sfml)

target_link_libraries(${EXEC}
  PUBLIC
    sfml-graphics
    sfml-window
)