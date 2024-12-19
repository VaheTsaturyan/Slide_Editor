QT += core gui widgets

CONFIG += c++17

# Проект
TEMPLATE = app
TARGET = Application

# Режимы сборки
CONFIG(debug, debug|release) {
    DEFINES += DEBUG
    QMAKE_CXXFLAGS += -g
} else {
    DEFINES += NDEBUG
    QMAKE_CXXFLAGS += -O3
}

# Включить предупреждения для компилятора
QMAKE_CXXFLAGS += -Wall -Wextra -Wpedantic

# Подключение Boost
INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/local/include/boost/json  # Добавление пути к Boost JSON

# Исходные файлы
SOURCES += \
    main.cpp \
    application/application.cpp \
    application/Dacument/Editor/editor.cpp \
    application/Dacument/Editor/Action.cpp \
    application/Dacument/Sterializer/Sterializer.cpp \
    application/Dacument/src/ithem.cpp \
    application/Dacument/src/page.cpp \
    application/Dacument/src/slide.cpp \
    application/Dacument/src/types.cpp \
    application/UI/CLI/Cantroler/src/controler.cpp \
    application/UI/CLI/SemanticAnalizer/src/semanticAnaliz.cpp \
    application/UI/CLI/SemanticAnalizer/src/semanticFactory.cpp \
    application/UI/CLI/ComandFactory/src/ComandCreate.cpp \
    application/UI/CLI/ComandFactory/src/comand.cpp \
    application/UI/CLI/Parser/src/lexer.cpp \
    application/UI/CLI/Parser/src/parser.cpp \
    application/UI/CLI/Parser/src/syntaxsAnalizert.cpp \
    application/Visualizetion/visualizer.cpp \
    application/Visualizetion/Shape/shape.cpp \
    application/Visualizetion/ShapeFactory/shapefactory.cpp \
    application/Logger/src/logger.cpp \
    application/Logger/src/outoutDivace.cpp

# Заголовочные файлы
HEADERS += \
    application/application.h \
    application/Dacument/Editor/editor.h \
    application/Dacument/Editor/Action.h \
    application/Dacument/Sterializer/Sterializer.h \
    application/Dacument/inc/Slide/item.h \
    application/Dacument/inc/Slide/page.h \
    application/Dacument/inc/Slide/slide.h \
    application/Dacument/inc/Slide/types.h \
    application/Dacument/inc/dacument.h \
    application/UI/CLI/cli.h \
    application/UI/CLI/types.h \
    application/UI/CLI/Cantroler/inc/controler.h \
    application/UI/CLI/SemanticAnalizer/inc/semanticAnaliz.h \
    application/UI/CLI/SemanticAnalizer/inc/semanticFactory.h \
    application/UI/CLI/ComandFactory/inc/comand.h \
    application/UI/CLI/ComandFactory/inc/comandCreate.h \
    application/UI/CLI/Parser/inc/lexer.h \
    application/UI/CLI/Parser/inc/parser.h \
    application/UI/CLI/Parser/inc/syntaxsAnalizer.h \
    application/Visualizetion/visualizer.h \
    application/Visualizetion/Shape/shape.h \
    application/Visualizetion/ShapeFactory/shapefactory.h \
    application/Logger/inc/logger.h \
    application/Logger/inc/outoutDivace.h

# Включить директории
INCLUDEPATH += \
    $$PWD \
    $$PWD/application \
    $$PWD/application/Dacument/inc \
    $$PWD/application/Dacument/Editor \
    $$PWD/application/Dacument/Sterializer \
    $$PWD/application/UI/CLI \
    $$PWD/application/UI/CLI/SemanticAnalizer/inc \
    $$PWD/application/UI/CLI/Cantroler/inc \
    $$PWD/application/UI/CLI/ComandFactory/inc \
    $$PWD/application/UI/CLI/Parser/inc \
    $$PWD/home/vts/repos/Slide_Editor/application/Visualizetion \
    $$PWD/home/vts/repos/Slide_Editor/application/Visualizetion/Shape \
    $$PWD/home/vts/repos/Slide_Editor/application/Visualizetion/ShapeFactory \
    $$PWD/home/vts/repos/Slide_Editor/application/Logger/inc \
    /usr/local/include/boost

# Линковка с Boost JSON (если необходимо)
LIBS += -lboost_json  # Линка с Boost JSON
