QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui


# 附加头文件包含，一般要编译链接第三方库时配置include目录
# 注意：1、可以用绝对路径或相对路径 2、相对路径中的./可以省略 3、路径中不允许出现空格
INCLUDEPATH += D:/opencv/build/include \
    D:/opencv/build/include/opencv2

LIBS += D:/opencv/build/x64/vc15/lib/opencv_world454.lib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
