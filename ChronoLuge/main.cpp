/*
 * Inclusion des bibliothèques/classes
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QZXing.h>
#include <QZXingFilter.h>
#include <QIcon>
#include "controller/visualisertempsvitesse.h"

/**
 * @brief qMain
 * @param argc
 * @param argv
 * @return
 * @desc: main
 */
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    // Création de l'application principale
        QGuiApplication app(argc, argv);
        QQmlApplicationEngine engine;

    // Création du controller principal
        VisualiserTempsVitesse controllerVisualiserTempsVitesse;

    // Set de l'icone de l'appli pour windows
        app.setWindowIcon(QIcon(":/image/image/logo.png"));

    // Enregistrement des types pour le QML
        qmlRegisterType<Descente>("Descente", 1, 0, "Descente");
        qmlRegisterType<VisualiserTempsVitesse>("ControllerVisualiserTempsVitesse", 1, 0, "ControllerVisualiserTempsVitesse");
        qmlRegisterType<VisualiserIdentification>("ControllerIdentification", 1, 0, "ControllerIdentification");
        QZXing::registerQMLTypes();

    // Set des etats de connexion et d'inscription si necessaire
        controllerVisualiserTempsVitesse.getControllerVisualiserIdentification()->getEtatConnexion()->setValue("etatConnexion", "nonconnecte");
        controllerVisualiserTempsVitesse.getControllerVisualiserIdentification()->getEtatInscription()->setValue("etatInscription", "noninscrit");

    // Ajout des propriétés "presenter" au QML
        engine.rootContext()->setContextProperty("presenterIdentification", controllerVisualiserTempsVitesse.getPresenterIdentification());
        engine.rootContext()->setContextProperty("presenterVisualiserTempsVitesse", controllerVisualiserTempsVitesse.getPresenterVisualiserTempsVitesse());

    // Set de la partie QML
        const QUrl url(QStringLiteral("qrc:/view/boundary/presenter/view/main.qml"));
        QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) { if (!obj && url == objUrl) QCoreApplication::exit(-1); }, Qt::QueuedConnection); engine.load(url);

    // Lancement de la boucle evenementielle de l'application
        return app.exec();
}
