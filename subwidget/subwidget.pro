QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG +=qt c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    subwidget.cpp

HEADERS += \
    subwidget.h

FORMS += \
    subwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#RESOURCES += \
#    image/imageS.qrc

INCLUDEPATH += /usr/local/include/opencv4 \
               /usr/local/include/opencv4/opencv2

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../SQL/sqlite/build/.libs/release/ -ltclsqlite3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../SQL/sqlite/build/.libs/debug/ -ltclsqlite3
else:unix: LIBS += -L$$PWD/../../../SQL/sqlite/build/.libs/ -ltclsqlite3

INCLUDEPATH += $$PWD/../../../SQL/sqlite/build/.libs
DEPENDPATH += $$PWD/../../../SQL/sqlite/build/.libs

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../SQL/sqlite/build/.libs/release/ -lsqlite3.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../SQL/sqlite/build/.libs/debug/ -lsqlite3.0
else:unix: LIBS += -L$$PWD/../../../SQL/sqlite/build/.libs/ -lsqlite3.0

INCLUDEPATH += $$PWD/../../../SQL/sqlite/build/.libs
DEPENDPATH += $$PWD/../../../SQL/sqlite/build/.libs


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/lib/release/ -lopencv_world.4.5.3
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/lib/debug/ -lopencv_world.4.5.3
#else:unix: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lopencv_world.4.5.3

#INCLUDEPATH += $$PWD/../../../../../../usr/local/lib
#DEPENDPATH += $$PWD/../../../../../../usr/local/lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/lib/release/ -lopencv_world.4.5.5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/lib/debug/ -lopencv_world.4.5.5
else:unix: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lopencv_world.4.5.5

INCLUDEPATH += $$PWD/../../../../../../usr/local/lib
DEPENDPATH += $$PWD/../../../../../../usr/local/lib
