
add_executable(tcp_test WIN32
    main.cpp
    mainwindow.cpp
    mainwindow.ui
    myclient.cpp
    myserver.cpp
    myserverthread.cpp
)

target_link_libraries(tcp_test PRIVATE
    Qt5::Widgets
    Qt5::Network
)
