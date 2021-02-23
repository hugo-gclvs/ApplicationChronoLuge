#ifndef VISUALISERTEMPSVITESSE_H
#define VISUALISERTEMPSVITESSE_H

#include <QObject>
#include <QtQml/QQmlListProperty>
#include <QVector>
#include <QSettings>

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

    /*Q_INVOKABLE int getNmbrDescentes() {
            return this->nmbrDescente;
    }*/

    // Accesseurs                                           { return etatConnexion; }
        QQmlListProperty<Descente> getDescentes()                                   { return QQmlListProperty<Descente>(this, mesDescentes); }
        PresenterVisualiserTempsVitesse *getPresenterVisualiserTempsVitesse()       { return monPresenter; }

    // Méthodes
        bool lierDescente(QString QRCode);
        bool rechercherDescentes();
        bool rechercherStatistiques();
        bool initDescentes(QVector<QString> *descentes);
        bool initStatistiques(QVector<QString> *statistiques);

        QSettings *etatConnexion = new QSettings("etatConnexion", "nonconnecte");
        QSettings *etatInscription = new QSettings("etatInscription", "noninscrit");

        /*QSettings getEtatConnexion() const;
        void setEtatConnexion(const QString &value) { etatConnexion.setValue("etatConnexion", value); }

        QSettings getEtatInscription() { return etatInscription.value("etatInscription"); }
        void setEtatInscription(const QString &value) { etatInscription.setValue("etatInscription", value); }*/

private:

        // Attributs
        ComHTTP *communicationHTTP;

        PresenterVisualiserTempsVitesse *monPresenter;
        VisualiserIdentification controllerIdentification;

        QList<Descente *> mesDescentes;



signals:
        void listeChanged();
};

#endif // VISUALISERTEMPSVITESSE_H
