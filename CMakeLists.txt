cmake_minimum_required(VERSION 3.11)
project(dosgame)

set(CMAKE_GENERATOR Ninja)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
add_compile_options(-Wall -save-temps)

file(GLOB sources CONFIGURE_DEPENDS "src/*.c" "src/*.cpp" "src/*.h" "src/**/*.c" "src/**/*.cpp" "src/**/*.h" )

if(MSVC)
    add_executable(main WIN32 ${sources})
    add_compile_definitions(ALLEGRO_MSVC)
else()
    add_executable(main ${sources})
    add_compile_definitions(ALLEGRO_DJGPP)
endif()

add_custom_target(assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets
)

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(WIN32)
    target_link_libraries(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/alleg.lib)
else()
    target_link_libraries(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/liballeg.a)
endif()

add_dependencies(main assets)
