cmake_minimum_required(VERSION 3.9.4)
project(RLBot-BM_CPP LANGUAGES CXX)

file(GLOB source_files ${PROJECT_SOURCE_DIR}/src/*.cc)
set(RLBOT-BM_DIR ${PROJECT_SOURCE_DIR}/RLBot-BM)

add_subdirectory(RLBot-BM)

add_library(${PROJECT_NAME} STATIC ${source_files})

include_directories(${RLBOT-BM_DIR}/src)
target_link_libraries(${PROJECT_NAME} PUBLIC RLBot-BM)

target_include_directories(${PROJECT_NAME} PUBLIC inc lib/inc)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

#link linux libraries
if (UNIX)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS})
endif (UNIX)