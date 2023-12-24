QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arms.cpp \
    armsbeginner.cpp \
    armsexp.cpp \
    armsinter.cpp \
    bmipage.cpp \
    checklist.cpp \
    chestbeginner.cpp \
    chestexp.cpp \
    chestinter.cpp \
    choosediet.cpp \
    exparms.cpp \
    expchest.cpp \
    explegs.cpp \
    expshoulders.cpp \
    filesystems.cpp \
    history.cpp \
    legsbeginner.cpp \
    legsexpert.cpp \
    legsinter.cpp \
    loginpage.cpp \
    loseweight.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    shoulderbeginner.cpp \
    shoulderexpert.cpp \
    shoulderint.cpp \
    wieghtgain.cpp \
    wieghtmaintain.cpp \
    workoutpage.cpp

HEADERS += \
    arms.h \
    armsbeginner.h \
    armsexp.h \
    armsinter.h \
    bmipage.h \
    checklist.h \
    chestbeginner.h \
    chestexp.h \
    chestinter.h \
    choosediet.h \
    exparms.h \
    expchest.h \
    explegs.h \
    expshoulders.h \
    filesystems.h \
    history.h \
    legsbeginner.h \
    legsexpert.h \
    legsinter.h \
    loginpage.h \
    loseweight.h \
    mainmenu.h \
    mainwindow.h \
    shoulderbeginner.h \
    shoulderexpert.h \
    shoulderint.h \
    state.h \
    wieghtgain.h \
    wieghtmaintain.h \
    workoutpage.h

FORMS += \
    arms.ui \
    armsbeginner.ui \
    armsexp.ui \
    armsinter.ui \
    bmipage.ui \
    checklist.ui \
    chestbeginner.ui \
    chestexp.ui \
    chestinter.ui \
    choosediet.ui \
    exparms.ui \
    expchest.ui \
    explegs.ui \
    expshoulders.ui \
    history.ui \
    legsbeginner.ui \
    legsexpert.ui \
    legsinter.ui \
    loginpage.ui \
    loseweight.ui \
    mainmenu.ui \
    mainwindow.ui \
    shoulderbeginner.ui \
    shoulderexpert.ui \
    shoulderint.ui \
    wieghtgain.ui \
    wieghtmaintain.ui \
    workoutpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

DISTFILES += \
    checklist.txt
