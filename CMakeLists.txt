cmake_minimum_required(VERSION 3.9.4)
project(RLBotBMCPP LANGUAGES CXX)

file(GLOB source_files ${PROJECT_SOURCE_DIR}/src/*.cc)

add_subdirectory(RLBotBMLib)

add_library(RLBotBMCPP STATIC ${source_files})

include_directories(${PROJECT_SOURCE_DIR}/RLBotBMLib/src)
target_link_libraries(RLBotBMCPP PUBLIC RLBotBMLib)

target_include_directories(RLBotBMCPP PUBLIC inc lib/inc)
target_compile_features(RLBotBMCPP PUBLIC cxx_std_17)

#link linux libraries
if (UNIX)
    target_link_libraries(RLBotBMCPP ${CMAKE_DL_LIBS})
endif (UNIX)