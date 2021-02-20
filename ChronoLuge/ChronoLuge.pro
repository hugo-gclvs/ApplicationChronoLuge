QT += quick gui network widgets

CONFIG += c++11 qzxing_multimedia
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        #boundary/presenter/presenteridentification.cpp \
        #boundary/presenter/presentervisualisertempsvitesse.cpp \
        #controller/visualiseridentification.cpp \
        #controller/visualisertempsvitesse.cpp \
        entity/descente.cpp \
        entity/statistiques.cpp \
        entity/utilisateur.cpp \
        main.cpp \
        boundary/data/ComHTTP/comhttp.cpp

HEADERS += \
        #boundary/presenter/presenteridentification.h \
        #boundary/presenter/presentervisualisertempsvitesse.h \
        #controller/visualiseridentification.h \
        #controller/visualisertempsvitesse.h \
        entity/descente.h \
        entity/statistiques.h \
        entity/utilisateur.h \
        boundary/data/ComHTTP/comhttp.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(boundary/data/QZXing/QZXing.pri)

DISTFILES += \
    ../build-Android/android-custom/AndroidManifest.xml \
    ../build-Android/android-custom/build.gradle \
    ../build-Android/android-custom/gradle/wrapper/gradle-wrapper.jar \
    ../build-Android/android-custom/gradle/wrapper/gradle-wrapper.properties \
    ../build-Android/android-custom/gradlew \
    ../build-Android/android-custom/gradlew.bat \
    ../build-Android/android-custom/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/../build-Android/android-custom


