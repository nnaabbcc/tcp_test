
add_executable(udp_test WIN32
    main.cpp
    mainwindow.cpp
    mainwindow.ui
    MyReaderThread.cpp
    MyReaderThreadObject.cpp
    MyUdpClient.cpp
    MyUdpServer.cpp
    MyWriterThread.cpp
)

target_link_libraries(udp_test PRIVATE
    Qt5::Widgets
    Qt5::Network
)