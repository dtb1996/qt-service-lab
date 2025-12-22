cmake_minimum_required(VERSION 3.16)

project(QtServiceLab VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

if(NOT DEFINED ENV{CI_BUILD})
    qt_standard_project_setup(REQUIRES 6.8)
endif()

qt_add_executable(appQtServiceLab
    src/main.cpp
)

qt_add_qml_module(appQtServiceLab
    URI QtServiceLab
    VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
    QML_FILES
        qml/Main.qml
        qml/screens/FeedScreen.qml
        qml/components/LoadingOverlay.qml
        qml/components/ErrorBanner.qml
        qml/components/AppButton.qml
    SOURCES
        src/app/AppState.h src/app/AppState.cpp
        src/app/AppController.h src/app/AppController.cpp
        src/services/FakeApiService.h src/services/FakeApiService.cpp
        src/services/ServiceTypes.h
        src/models/FeedModel.h src/models/FeedModel.cpp
        src/models/FeedItem.h
        src/utils/RandomDelay.h src/utils/RandomDelay.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQtServiceLab PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQtServiceLab
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQtServiceLab
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appQtServiceLab
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
