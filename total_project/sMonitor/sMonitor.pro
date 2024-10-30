#-------------------------------------------------
#
# Project created by QtCreator 2024-10-13T18:47:32
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = sMonitor
TEMPLATE = app


SOURCES += main.cpp\
        menu.cpp \
    fops.cpp \
    fullShow.cpp \
    click_label.cpp \
    login.cpp \
    steng.cpp \
    mqtt/qmqtt_client.cpp \
    mqtt/qmqtt_client_p.cpp \
    mqtt/qmqtt_frame.cpp \
    mqtt/qmqtt_message.cpp \
    mqtt/qmqtt_network.cpp \
    mqtt/qmqtt_router.cpp \
    mqtt/qmqtt_routesubscription.cpp \
    mqtt/qmqtt_socket.cpp \
    mqtt/qmqtt_ssl_socket.cpp \
    mqtt/qmqtt_timer.cpp \
    mqtt/qmqtt_websocket.cpp \
    mqtt/qmqtt_websocketiodevice.cpp

HEADERS  += menu.h \
    fops.h \
    fullShow.h \
    click_label.h \
    login.h \
    steng.h \
    mqtt/qmqtt.h \
    mqtt/qmqtt_client.h \
    mqtt/qmqtt_client_p.h \
    mqtt/qmqtt_frame.h \
    mqtt/qmqtt_global.h \
    mqtt/qmqtt_message.h \
    mqtt/qmqtt_message_p.h \
    mqtt/qmqtt_network_p.h \
    mqtt/qmqtt_networkinterface.h \
    mqtt/qmqtt_routedmessage.h \
    mqtt/qmqtt_router.h \
    mqtt/qmqtt_routesubscription.h \
    mqtt/qmqtt_socket_p.h \
    mqtt/qmqtt_socketinterface.h \
    mqtt/qmqtt_ssl_socket_p.h \
    mqtt/qmqtt_timer_p.h \
    mqtt/qmqtt_timerinterface.h \
    mqtt/qmqtt_websocket_p.h \
    mqtt/qmqtt_websocketiodevice_p.h

FORMS    += menu.ui \
    fops.ui \
    fullShow.ui \
    login.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    images/up.png \
    images/settings.png \
    images/right.png \
    images/reset.png \
    images/manual_model.png \
    images/left.png \
    images/file_manager.png \
    images/exception.png \
    images/down.png \
    images/capture.png \
    images/camera.png \
    images/auto_model.png   \
    mqtt/qmqtt.pri \
    mqtt/qmqtt.qbs

#x86

#INCLUDEPATH += /usr/local/include
#LIBS += -L/usr/local/lib/libopencv_highgui.so \
#        /usr/local/lib/libopencv_core.so \
#        /usr/local/lib/libopencv_imgproc.so \
#        /usr/local/lib/libopencv_imgcodecs.so \
#        /usr/local/lib/libopencv_face.so \
#        /usr/local/lib/libopencv_objdetect.so \
#        /usr/local/lib/libopencv_videoio.so


#arm

INCLUDEPATH += /usr/local/arm/opencv-arm/include \
                /usr/local/arm/opencv-arm/include/opencv \
                /usr/local/arm/opencv-arm/include/opencv2
LIBS += /usr/local/arm/opencv-arm/lib/libopencv_highgui.so \
        /usr/local/arm/opencv-arm/lib/libopencv_core.so \
        /usr/local/arm/opencv-arm/lib/libopencv_imgproc.so \
        /usr/local/arm/opencv-arm/lib/libopencv_imgcodecs.so \
        /usr/local/arm/opencv-arm/lib/libopencv_video.so \
        /usr/local/arm/opencv-arm/lib/libopencv_videoio.so \
        /usr/local/arm/opencv-arm/lib/libopencv_objdetect.so

SUBDIRS += \
    mqtt/qmqtt.pro





