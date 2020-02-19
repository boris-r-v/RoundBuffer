file(GLOB LIB_SOURSEC ${PROJECT_SOURCE_DIR}/lib/src/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/lib/src )

add_library(dlist SHARED ${LIB_SOURSEC})