set(TARGET rap_matrix)
set(SRC_LIST matrix.c)

find_library(PI_LIBRARY wiringPi PATHS ${PROJECT_SOURCE_DIR}/lib)
message(STATUS "PI_LIBRARY= " ${PI_LIBRARY})

find_library(PIDEV_LIBRARY wiringPiDev PATHS ${PROJECT_SOURCE_DIR}/lib)
message(STATUS "PIDEV_LIBRARY= " ${PIDEV_LIBRARY})

add_executable(${TARGET} ${SRC_LIST})
target_link_libraries(${TARGET} ${PI_LIBRARY})
target_link_libraries(${TARGET} ${PIDEV_LIBRARY})

