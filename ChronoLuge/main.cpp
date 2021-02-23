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
    QQmlApplicationEngine engine;
    VisualiserTempsVitesse controllerVisualiserTempsVitesse;

    app.setWindowIcon(QIcon(":/image/image/logo.png"));

    qmlRegisterType<Descente>("Descente", 1, 0, "Descente");
    qmlRegisterType<VisualiserTempsVitesse>("ControllerVisualiserTempsVitesse", 1, 0, "VisualiserTempsVitesse");
    qmlRegisterType<QZXing>("QZXing", 3, 1, "QZXing");


    //controllerVisualiserTempsVitesse.etatConnexion->setValue("etatConnexion", "nonconnecte");

    /*if(controllerVisualiserTempsVitesse.etatConnexion->value("etatConnexion") == "connecte")
        qDebug() << "connecté !!!!!";
    else
        qDebug() << "pas connecté !!!!!";*/

    //controllerVisualiserTempsVitesse.etatInscription->setValue("etatInscription", "noninscrit");

    /*if(controllerVisualiserTempsVitesse.etatInscription->value("etatInscription") == "inscrit")
        qDebug() << "inscrit !!!!!";
    else
        qDebug() << "pas inscrit !!!!!";*/

    controllerVisualiserTempsVitesse.rechercherDescentes();
    controllerVisualiserTempsVitesse.rechercherStatistiques();



    engine.rootContext()->setContextProperty("presenterVisualiserTempsVitesse", controllerVisualiserTempsVitesse.getPresenterVisualiserTempsVitesse());

    const QUrl url(QStringLiteral("qrc:/view/boundary/presenter/view/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
