QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Camera_module/camera_module.cpp \
    ../DL_module/DL_module.cpp \
    ../DL_module/detector.cpp \
    ../Database/SQLiteHelper.cpp \
    ../subwidget/subwidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../Camera_module/camera_module.h \
    ../DL_module/DL_module.h \
    ../DL_module/detector.h \
    ../Database/SQLiteHelper.h \
    ../subwidget/subwidget.h \
    mainwindow.h

FORMS += \
    ../subwidget/subwidget.ui \
    mainwindow.ui


# 附加头文件包含，一般要编译链接第三方库时配置include目录
# 注意：1、可以用绝对路径或相对路径 2、相对路径中的./可以省略 3、路径中不允许出现空格

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
INCLUDEPATH += -L$$PWD/..

INCLUDEPATH += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\include)
INCLUDEPATH += $$quote(C:\Users\zhuze\OneDrive - Macau University of Science and Technology\Bill\3th-2\Software_proj_manage\StarWars-Companion\Database)
LIBS += $$quote(C:\Users\zhuze\OneDrive - Macau University of Science and Technology\Bill\3th-2\Software_proj_manage\StarWars-Companion\Database\sqlite.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_calib3d453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_calib3d453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_core453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_core453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_dnn453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_dnn453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_features2d453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_features2d453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_flann453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_flann453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_gapi453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_gapi453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_highgui453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_highgui453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_imgcodecs453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_imgcodecs453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_imgproc453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_imgproc453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_ml453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_ml453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_objdetect453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_objdetect453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_photo453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_photo453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_stitching453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_stitching453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_video453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_video453d.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_videoio453.lib)
LIBS += $$quote(C:\Program Files (x86)\Intel\openvino_2021.4.752\opencv\lib\opencv_videoio453d.lib)

DISTFILES += \
    ../DL_module/mobilenet.onnx \
    ../subwidget/image/.DS_Store \
    ../subwidget/image/1/.DS_Store \
    ../subwidget/image/1/1.jpg \
    ../subwidget/image/1/2.jpg \
    ../subwidget/image/1/3.jpg \
    ../subwidget/image/1/4.jpg \
    ../subwidget/image/1/5.jpg

RESOURCES += \
    image/imageS.qrc







