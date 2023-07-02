add_executable(test_1
    test_1.cpp
    )

target_link_libraries(test_1
    PRIVATE
    lebedev_quadrature
    )

install(TARGETS test_1 DESTINATION bin)
