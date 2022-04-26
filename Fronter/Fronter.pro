QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Camera_module/camera_module.cpp \
    ../DL_module/DL_module.cpp \
    ../DL_module/detector.cpp \
    ../Database/SQLiteHelper.cpp \
    ../subwidget/subwidget.cpp \
    frame/form.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../Camera_module/camera_module.h \
    ../DL_module/DL_module.h \
    ../DL_module/detector.h \
    ../Database/SQLiteHelper.h \
    ../Database/sqlite3.h \
    ../Database/sqlite3ext.h \
    ../subwidget/subwidget.h \
    frame/form.h \
    mainwindow.h

FORMS += \
    ../subwidget/subwidget.ui \
    frame/form.ui \
    mainwindow.ui


# 附加头文件包含，一般要编译链接第三方库时配置include目录
# 注意：1、可以用绝对路径或相对路径 2、相对路径中的./可以省略 3、路径中不允许出现空格
INCLUDEPATH += D:/opencv/build/include \
    D:/opencv/build/include/opencv2

LIBS += D:/opencv/build/x64/vc15/lib/opencv_world454.lib  \
        D:/opencv/build/x64/vc15/lib/opencv_world454d.lib  \
        C:\Users\YRY\source\repos\StarWars-Companion/Database/sqlite.lib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../DL_module/README.md \
    ../DL_module/mobilenet.onnx \
    ../DL_module/yolov5s.onnx \
    ../Database/sqlite.lib \
    ../Database/star_war.db \
    ../subwidget/image/.DS_Store \
    ../subwidget/image/1/.DS_Store \
    ../subwidget/image/1/1.jpg \
    ../subwidget/image/1/2.jpg \
    ../subwidget/image/1/3.jpg \
    ../subwidget/image/1/4.jpg \
    ../subwidget/image/1/5.jpg \
    image/.DS_Store \
    image/0/1.jpg \
    image/0/2.jpg \
    image/0/3.jpg \
    image/1/1.jpg \
    image/1/2.jpg \
    image/1/3.jpg \
    image/10/1.jpg \
    image/10/2.jpg \
    image/10/3.jpg \
    image/11/1.jpg \
    image/11/2.jpg \
    image/11/3.jpg \
    image/12/1.jpg \
    image/12/2.jpg \
    image/12/3.jpg \
    image/13/1.jpg \
    image/13/2.jpg \
    image/13/3.jpg \
    image/14/1.jpg \
    image/14/2.jpg \
    image/14/3.jpg \
    image/15/1.jpg \
    image/15/2.jpg \
    image/15/3.jpg \
    image/16/1.jpg \
    image/16/2.jpg \
    image/16/3.jpg \
    image/17/1.jpg \
    image/17/2.jpg \
    image/17/3.jpg \
    image/18/1.jpg \
    image/18/2.jpg \
    image/18/3.jpg \
    image/19/1.jpg \
    image/19/2.jpg \
    image/19/3.jpg \
    image/2/1.jpg \
    image/2/2.jpg \
    image/2/3.jpg \
    image/20/1.jpg \
    image/20/2.jpg \
    image/20/3.jpg \
    image/21/1.jpg \
    image/21/2.jpg \
    image/21/3.jpg \
    image/22/1.jpg \
    image/22/2.jpg \
    image/22/3.jpg \
    image/23/1.jpg \
    image/23/2.jpg \
    image/23/3.jpg \
    image/24/1.jpg \
    image/24/2.jpg \
    image/24/3.jpg \
    image/25/1.jpg \
    image/25/2.jpg \
    image/25/3.jpg \
    image/26/1.jpg \
    image/26/2.jpg \
    image/26/3.jpg \
    image/27/1.jpg \
    image/27/2.jpg \
    image/27/3.jpg \
    image/28/1.jpg \
    image/28/2.jpg \
    image/28/3.jpg \
    image/29/1.jpg \
    image/29/2.jpg \
    image/29/3.jpg \
    image/3/1.jpg \
    image/3/2.jpg \
    image/3/3.jpg \
    image/30/1.jpg \
    image/30/2.jpg \
    image/30/3.jpg \
    image/31/1.jpg \
    image/31/2.jpg \
    image/31/3.jpg \
    image/32/1.jpg \
    image/32/2.jpg \
    image/32/3.jpg \
    image/33/1.jpg \
    image/33/2.jpg \
    image/33/3.jpg \
    image/34/1.jpg \
    image/34/2.jpg \
    image/34/3.jpg \
    image/35/1.jpg \
    image/35/2.jpg \
    image/35/3.jpg \
    image/36/1.jpg \
    image/36/2.jpg \
    image/36/3.jpg \
    image/37/1.jpg \
    image/37/2.jpg \
    image/37/3.jpg \
    image/38/1.jpg \
    image/38/2.jpg \
    image/38/3.jpg \
    image/39/1.jpg \
    image/39/2.jpg \
    image/39/3.jpg \
    image/4/1.jpg \
    image/4/2.jpg \
    image/4/3.jpg \
    image/40/1.jpg \
    image/40/2.jpg \
    image/40/3.jpg \
    image/41/1.jpg \
    image/41/2.jpg \
    image/41/3.jpg \
    image/42/1.jpg \
    image/42/2.jpg \
    image/42/3.jpg \
    image/43/1.jpg \
    image/43/2.jpg \
    image/43/3.jpg \
    image/44/1.jpg \
    image/44/2.jpg \
    image/44/3.jpg \
    image/45/1.jpg \
    image/45/2.jpg \
    image/45/3.jpg \
    image/46/1.jpg \
    image/46/2.jpg \
    image/46/3.jpg \
    image/47/1.jpg \
    image/47/2.jpg \
    image/47/3.jpg \
    image/48/1.jpg \
    image/48/2.jpg \
    image/48/3.jpg \
    image/49/1.png \
    image/49/2.jpg \
    image/49/3.jpg \
    image/5/1.jpg \
    image/5/2.jpg \
    image/5/3.jpg \
    image/50/1.jpg \
    image/50/2.jpg \
    image/50/3.jpg \
    image/6/1.jpg \
    image/6/2.jpg \
    image/6/3.jpg \
    image/7/1.jpg \
    image/7/2.jpg \
    image/7/3.jpg \
    image/8/1.jpg \
    image/8/2.jpg \
    image/8/3.jpg \
    image/9/1.jpg \
    image/9/2.jpg \
    image/9/3.jpg \
    image/icon.png

RESOURCES += \
    image/imageS.qrc \
    image/imageS.qrc








