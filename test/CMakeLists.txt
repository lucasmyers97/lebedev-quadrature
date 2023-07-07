# Test including with header only capabilities
add_executable(test_header_only
    test_header_only.cpp
    )
target_link_libraries(test_header_only
    PRIVATE
    lebedev_quadrature
    )

# This is how a user would create a static or shared library to reduce compile times
add_library(lebedev_implementation
    lebedev_implementation.cpp)
target_link_libraries(lebedev_implementation
    PUBLIC
    lebedev_quadrature)
target_include_directories(lebedev_implementation
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

# Test including shared or static library 
add_executable(test_no_header_only
    test_no_header_only.cpp)
target_link_libraries(test_no_header_only
    lebedev_implementation)

# Testing evaluating spherical integral of scalar function
add_executable(scalar_function_test
    scalar_function_test.cpp)
target_link_libraries(scalar_function_test
    lebedev_quadrature)

# Testing evaluating spherical integral of vector function
add_executable(vector_function_test
    scalar_function_test.cpp)
target_link_libraries(vector_function_test
    lebedev_quadrature)

install(TARGETS test_header_only DESTINATION bin)
install(TARGETS lebedev_implementation DESTINATION lib)
install(TARGETS test_no_header_only DESTINATION bin)
install(TARGETS scalar_function_test DESTINATION bin)
install(TARGETS vector_function_test DESTINATION bin)
