#target_sources(${EXECUTABLE} PRIVATE main.c)
target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(${EXECUTABLE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/HW_api.c)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/components)
target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components)