include_directories ("${PROJECT_SOURCE_DIR}/lib/src")
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK) 

add_executable(test_dlist test_dlist.cpp)
add_dependencies(test_dlist test_dlist)
add_test(test_dlist test_dlist)

target_link_libraries(test_dlist ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )


