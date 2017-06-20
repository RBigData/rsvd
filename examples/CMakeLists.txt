add_executable(basic basic.cpp)
target_link_libraries(basic rsvd)

add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark rsvd)

add_executable(comparison comparison.cpp)
target_link_libraries(comparison rsvd)

add_executable(pure_c pure_c.c)
target_link_libraries(pure_c rsvd)

#install(TARGETS basic DESTINATION bin)
#install(TARGETS benchmark DESTINATION bin)
#install(TARGETS comparison DESTINATION bin)
#install(TARGETS pure_c DESTINATION bin)
