cmake_minimum_required(VERSION 3.16)

project(Povilization_QML VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.10)

qt_add_executable(appPovilization_QML
    main.cpp
    src/Cell.h
    src/Cell.cpp
    src/GameMap.h
    src/GameMap.cpp
    src/GameEngine.h
    src/GameEngine.cpp
    src/GameTypes.h
    src/Unit.h
    src/Unit.cpp
    src/Player.h
    src/Player.cpp
    src/MovementCalculator.h
    src/MovementCalculator.cpp
    src/Village.h
    src/Village.cpp
    src/TerrainGenerator.h
    src/TerrainGenerator.cpp
)

qt_add_qml_module(appPovilization_QML
    URI Povilization_QML
    QML_FILES
        qml/Main.qml
        qml/StartScreen.qml
        qml/GameScreen.qml
        qml/MapView.qml
        qml/HudPanel.qml
        qml/ContextMenu.qml
        SOURCES externallib/FastNoiseLite.h
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appPovilization_QML PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPovilization_QML
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPovilization_QML
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appPovilization_QML
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
