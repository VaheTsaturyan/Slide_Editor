cmake_minimum_required(VERSION 3.10)
project(SlideEditor)

# Установить стандарт C++
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-D_GLIBCXX_ASSERTIONS=0)


# Добавляем все каталоги с заголовочными файлами
include_directories(
    ${CMAKE_SOURCE_DIR}/Cantroler/inc
    ${CMAKE_SOURCE_DIR}/Dacument/inc
    ${CMAKE_SOURCE_DIR}/Dacument/inc/Slide
    ${CMAKE_SOURCE_DIR}/Dacument/slideMeneger
    ${CMAKE_SOURCE_DIR}/Dacument/slideMeneger/Editor
    ${CMAKE_SOURCE_DIR}/Dacument/slideMeneger/Sterializer
    ${CMAKE_SOURCE_DIR}/UI/CLI/inc
    ${CMAKE_SOURCE_DIR}/UI/CLI/inc/Parser
)

# Добавляем все .cpp файлы из папок проекта
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/Cantroler/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/Dacument/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/Dacument/slideMeneger/*.cpp"
    "${CMAKE_SOURCE_DIR}/Dacument/slideMeneger/Editor/*.cpp"
    "${CMAKE_SOURCE_DIR}/Dacument/slideMeneger/Sterializer/*.cpp"
    "${CMAKE_SOURCE_DIR}/UI/CLI/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/main.cpp"
)

# Создаем исполняемый файл
add_executable(SlideEditor ${SOURCES})
