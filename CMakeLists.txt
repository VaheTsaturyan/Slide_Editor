cmake_minimum_required(VERSION 3.10)

# Название проекта
project(SlideEditor)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление файлов исходного кода
set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Cantroler/src/controler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Dacument/slideMeneger/Editor/editor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Dacument/slideMeneger/Sterializer/Sterializer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Dacument/slideMeneger/slideMeneger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Dacument/src/ithem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Dacument/src/page.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Dacument/src/slide.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Dacument/src/types.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UI/CLI/src/Parser/ComandCreate.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UI/CLI/src/Parser/comand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UI/CLI/src/Parser/lexer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UI/CLI/src/Parser/parser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UI/CLI/src/Parser/syntaxsAnalizert.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# Добавление исполняемого файла
add_executable(SlideEditor ${SOURCE_FILES})

# Указание директорий для включения
target_include_directories(SlideEditor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Cantroler/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Dacument/slideMeneger
    ${CMAKE_CURRENT_SOURCE_DIR}/Dacument/src
    ${CMAKE_CURRENT_SOURCE_DIR}/UI/CLI/inc
)

# Установка конфигурации для отладки
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -Wall -O0 -g")
set(CMAKE_BUILD_TYPE Debug)
