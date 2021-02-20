#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QZXing.h>
#include <QZXingFilter.h>
#include <QIcon>

#include "controller/visualisertempsvitesse.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/image/image/logo.png"));

    qmlRegisterType<Descente>("Historique", 1, 0, "Descente");
    VisualiserTempsVitesse controllerVisualiserTempsVitesse;

    controllerVisualiserTempsVitesse.rechercherDescentes();

    QZXing::registerQMLTypes();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("controleur", &controllerVisualiserTempsVitesse);

    const QUrl url(QStringLiteral("qrc:/view/boundary/presenter/view/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
