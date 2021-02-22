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

    Q_PROPERTY(bool etatConnexion READ getEtatConnexion)
    Q_PROPERTY(QQmlListProperty<Descente> liste READ getDescentes NOTIFY listeChanged)
    //Q_PROPERTY(int nmbrDescente READ getNmbrDescente)

public:

    // Constructeur
        explicit VisualiserTempsVitesse(QObject *parent = nullptr);
        ~VisualiserTempsVitesse() override;

    /*Q_INVOKABLE int getNmbrDescentes() {
            return this->nmbrDescente;
    }*/

    // Accesseurs
        bool getEtatConnexion() const                                               { return etatConnexion; }
        QQmlListProperty<Descente> getDescentes()                                   { return QQmlListProperty<Descente>(this, mesDescentes); }
        int getNmbrDescente() const                                                 { return nmbrDescente; }
        PresenterVisualiserTempsVitesse *getPresenterVisualiserTempsVitesse()       { return monPresenter; }

    // Méthodes
        bool lierDescente(int numLuge, int idUtilisateur);
        bool rechercherDescentes();
        bool initDescentes(QVector<QString> *descentes);

private:

        // Attributs
        ComHTTP *communicationHTTP;

        PresenterVisualiserTempsVitesse *monPresenter;
        VisualiserIdentification controllerIdentification;

        QList<Descente *> mesDescentes;
        int nmbrDescente;
        bool etatConnexion;

signals:
        void listeChanged();
};

#endif // VISUALISERTEMPSVITESSE_H
