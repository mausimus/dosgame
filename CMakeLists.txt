cmake_minimum_required(VERSION 3.11)
project(dos-app)

set(CMAKE_GENERATOR Ninja)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
add_compile_options(-Wall -save-temps)

file(GLOB sources CONFIGURE_DEPENDS "src/*.c" "src/*.cpp" "src/*.h" "src/**/*.c" "src/**/*.cpp" "src/**/*.h" )

add_executable(main ${sources})

add_custom_target(assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets
)

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/liballeg.a)

add_dependencies(main assets)
