set(PROJECT_NAME PCRemoteControl)

project(${PROJECT_NAME})

set(SOURCES
    apihandler.cpp
    apihandler.h
    commandcodes.cpp
    commandcodes.h
    images.qrc
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    project_pch.h
    settingsinfo.cpp
    settingsinfo.h
    winapifunctions.cpp
    winapifunctions.h
    httpserverholder.h
    httpserverholder.cpp
    mainhandlerfactory.h
    mainhandlerfactory.cpp
)

add_executable(${PROJECT_NAME} WIN32 ${SOURCES})


target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt5::Widgets
        Qt5::Network
        HelperLibrary
        PropertyBrowser3
        CustomStylePlugin
        CustomWidgets
        HttpServer2
        Ole32
        User32
)

target_precompile_headers(${PROJECT_NAME} PRIVATE project_pch.h)

aviaNames()
makeAI()
deployTr()
