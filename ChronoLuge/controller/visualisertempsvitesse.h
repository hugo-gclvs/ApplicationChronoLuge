#ifndef VISUALISERTEMPSVITESSE_H
#define VISUALISERTEMPSVITESSE_H

#include <QObject>
#include <QtQml/QQmlListProperty>
#include <QVector>

#include "entity/descente.h"

#include "boundary/presenter/presentervisualisertempsvitesse.h"
#include "boundary/data/ComHTTP/comhttp.h"

#include "controller/visualiseridentification.h"


Q_DECLARE_METATYPE(QQmlListProperty< Descente  > )

class VisualiserTempsVitesse : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Descente> liste READ getDescentes NOTIFY listeChanged)

public:

    // Constructeur
        explicit VisualiserTempsVitesse(QObject *parent = nullptr);
        ~VisualiserTempsVitesse() override;

    // Accesseurs
        QQmlListProperty<Descente> getDescentes()                                       { return QQmlListProperty<Descente>(this, mesDescentes); }
        Q_INVOKABLE VisualiserIdentification *getControllerVisualiserIdentification()   { return &controllerIdentification; }
        PresenterVisualiserTempsVitesse *getPresenterVisualiserTempsVitesse()           { return monPresenter; }
        PresenterIdentification *getPresenterIdentification()                           { return controllerIdentification.getPresenterIdentification(); }
        Q_INVOKABLE QString getEtatConnexion()                                          { return controllerIdentification.getEtatConnexion()->value("etatConnexion").toString(); }
        Q_INVOKABLE QString getEtatInscription()                                        { return controllerIdentification.getEtatInscription()->value("etatInscription").toString(); }

    // Méthodes
        bool lierDescente(QString QRCode);
        Q_INVOKABLE bool rechercherDescentes();
        bool rechercherStatistiques();
        bool initDescentes(QVector<QString> *descentes);
        bool initStatistiques(QVector<QString> *statistiques);

private:

    // Attributs
        ComHTTP *communicationHTTP;

        PresenterVisualiserTempsVitesse *monPresenter;
        VisualiserIdentification controllerIdentification;

        QList<Descente *> mesDescentes;

signals:
        void listeChanged();
        void postLierDescente(const bool &etat);
};

#endif // VISUALISERTEMPSVITESSE_H
