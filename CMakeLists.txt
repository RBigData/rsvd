cmake_minimum_required (VERSION 3.6.0)
project(rsvd)
enable_language(C)
enable_language(CXX)

include(cmake/Modules/restrict.cmake)

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)
find_package(Armadillo REQUIRED)

include_directories(${ARMADILLO_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")

file(GLOB SOURCES src/*.cpp)
file(GLOB INCLUDE src/rsvd.h)

set(rsvd ${SOURCES} ${INCLUDE})

add_library(rsvd STATIC ${SOURCES})
target_link_libraries(rsvd ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})

install(TARGETS rsvd DESTINATION lib)
install(FILES ${INCLUDE} DESTINATION include)


add_subdirectory(examples)
add_subdirectory(tests)
