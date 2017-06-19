add_executable(basic basic.cpp)
target_link_libraries(basic rsvd)

add_executable(comparison comparison.cpp)
target_link_libraries(comparison rsvd)

install(TARGETS basic DESTINATION bin)
install(TARGETS comparison DESTINATION bin)
