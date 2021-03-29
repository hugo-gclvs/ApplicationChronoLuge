#ifndef PRESENTERVISUALISERTEMPSVITESSE_H
#define PRESENTERVISUALISERTEMPSVITESSE_H

/*
 * Inclusion des bibliothèques/classes
*/

#include <QObject>
#include "string.h"

using namespace std;



/*
 * Inclusion de la classe Controller VisualiserTempsVitesse
*/

class VisualiserTempsVitesse;

/**
 * @brief The PresenterVisualiserTempsVitesse class
 * @author: GONCALVES H
 * @desc: Classe frontière entre le controller VisualiserTempsVitesse et l'UI d'affichage des descentes (profil et liaison)
 */
class PresenterVisualiserTempsVitesse : public QObject
{
    Q_OBJECT

public:

    // Constructeur - Destructeur
        explicit PresenterVisualiserTempsVitesse(QObject *parent = nullptr) : QObject(parent), monController(nullptr) {}
        ~PresenterVisualiserTempsVitesse() override {}

    // Méthodes utilisable par l'UI
        Q_INVOKABLE VisualiserTempsVitesse *getControllerVisualiserTempsVitesse()   { return monController; }
        Q_INVOKABLE bool lierDescente(QString QRCode);
        Q_INVOKABLE bool rechercherHistorique();
        Q_INVOKABLE bool rechercherStatistiques();
        Q_INVOKABLE void majPP(int numPP);
        Q_INVOKABLE QString getMesStatistiques(int maStat);
        Q_INVOKABLE QString getMonUtilisateur(int monUtilisateur);
        Q_INVOKABLE void nouvellePP(QString path);

    // Mutateur
        void setController(VisualiserTempsVitesse *monController)                   { this->monController = monController; }

private:

    // Attributs
        VisualiserTempsVitesse *monController;

};

#endif // PRESENTERVISUALISERTEMPSVITESSE_H
