#ifndef VISUALISERTEMPSVITESSE_H
#define VISUALISERTEMPSVITESSE_H

#include <QObject>
#include <QtQml/QQmlListProperty>

#include "../entity/descente.h"

#include "../boundary/presenter/presentervisualisertempsvitesse.h"

class VisualiserTempsVitesse : public QObject
{
    Q_OBJECT
    /*Q_PROPERTY(bool etatConnexion READ getEtatConnexion)
    Q_PROPERTY(QQmlListProperty<Descente> historique READ getHistorique)*/

public:

    // Constructeur
        VisualiserTempsVitesse(PresenterVisualiserTempsVitesse *monPresenter, QObject *parent = nullptr);
        ~VisualiserTempsVitesse() override;

    // Accesseurs
        bool getEtatConnexion() const                       { return etatConnexion; }
        QQmlListProperty<Descente> getHistorique()          { return QQmlListProperty<Descente>(this, historique); }

    // Méthodes
        bool lierDescente(int numLuge, int idUtilisateur);


private:

    // Attributs
        PresenterVisualiserTempsVitesse *monPresenter;
        QList<Descente *> historique;
        bool etatConnexion;

signals:

};

#endif // VISUALISERTEMPSVITESSE_H
