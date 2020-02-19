include_directories ("${PROJECT_SOURCE_DIR}/lib/src")

add_executable(run main.cpp)

target_link_libraries(run dlist)
