QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MyThread.cpp \
    bomb.cpp \
    enemyplane.cpp \
    fight_1.cpp \
    fightscence.cpp \
    hero.cpp \
    main.cpp \
    mainsence.cpp \
    map.cpp \
    mypushbutton.cpp \
    uiscence.cpp \
    zidan.cpp

HEADERS += \
    MyThread.h \
    bomb.h \
    config.h \
    enemyplane.h \
    fight_1.h \
    fightscence.h \
    hero.h \
    mainsence.h \
    map.h \
    mypushbutton.h \
    uiscence.h \
    zidan.h

FORMS += \
    mainsence.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/res.qrc
