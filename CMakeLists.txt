# Minimum required CMake version
cmake_minimum_required(VERSION 3.16)

# Project name
project(Application)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define build types
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Build types" FORCE)

# Source files
set(SOURCES
    main.cpp
    application/application.cpp
    application/Dacument/Editor/editor.cpp
    application/Dacument/Editor/Action.cpp
    application/Dacument/Sterializer/Sterializer.cpp
    application/Dacument/src/ithem.cpp
    application/Dacument/src/page.cpp
    application/Dacument/src/slide.cpp
    application/Dacument/src/types.cpp
    application/UI/CLI/Cantroler/src/controler.cpp
    application/UI/CLI/SemanticAnalizer/src/semanticAnaliz.cpp
    application/UI/CLI/SemanticAnalizer/src/semanticFactory.cpp
    application/UI/CLI/ComandFactory/src/ComandCreate.cpp
    application/UI/CLI/ComandFactory/src/comand.cpp
    application/UI/CLI/Parser/src/lexer.cpp
    application/UI/CLI/Parser/src/parser.cpp
    application/UI/CLI/Parser/src/syntaxsAnalizert.cpp
    application/Visualizetion/visualizer.cpp
    
)

# Header files (optional: for IDEs and clarity)
set(HEADERS
    application/application.h
    application/Dacument/Editor/editor.h
    application/Dacument/Editor/Action.h
    application/Dacument/Sterializer/Sterializer.h
    application/Dacument/inc/Slide/item.h
    application/Dacument/inc/Slide/page.h
    application/Dacument/inc/Slide/slide.h
    application/Dacument/inc/Slide/types.h
    application/Dacument/inc/dacument.h
    application/UI/CLI/cli.h
    application/UI/CLI/types.h
    application/UI/CLI/Cantroler/inc/controler.h
    application/UI/CLI/SemanticAnalizer/inc/semanticAnaliz.h
    application/UI/CLI/SemanticAnalizer/inc/semanticFactory.h
    application/UI/CLI/ComandFactory/inc/comand.h
    application/UI/CLI/ComandFactory/inc/comandCreate.h
    application/UI/CLI/Parser/inc/lexer.h
    application/UI/CLI/Parser/inc/parser.h
    application/UI/CLI/Parser/inc/syntaxsAnalizer.h
    application/Visualizetion/visualizer.h
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/application
    ${CMAKE_SOURCE_DIR}/application/Dacument/inc
    ${CMAKE_SOURCE_DIR}/application/Dacument/Editor
    ${CMAKE_SOURCE_DIR}/application/Dacument/Sterializer
    ${CMAKE_SOURCE_DIR}/application/UI/CLI
    ${CMAKE_SOURCE_DIR}/application/UI/CLI/SemanticAnalizer/inc
    ${CMAKE_SOURCE_DIR}/application/UI/CLI/Cantroler/inc
    ${CMAKE_SOURCE_DIR}/application/UI/CLI/ComandFactory/inc
    ${CMAKE_SOURCE_DIR}/application/UI/CLI/Parser/inc
    ${CMAKE_SOURCE_DIR}/home/vts/repos/Slide_Editor/application/Visualizetion
)

# Compiler options for build types
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Configuring Debug build")
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG)
    target_compile_options(${PROJECT_NAME} PRIVATE -g)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Configuring Release build")
    target_compile_definitions(${PROJECT_NAME} PRIVATE NDEBUG)
    target_compile_options(${PROJECT_NAME} PRIVATE -O3)
endif()

# Optional: Add general compiler warnings
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()
