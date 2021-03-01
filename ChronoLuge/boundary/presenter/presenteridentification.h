#ifndef PRESENTERIDENTIFICATION_H
#define PRESENTERIDENTIFICATION_H

/*
 * Inclusion des bibliothèques/classes
*/

#include <QObject>
#include <QDebug>

/*
 * Inclusion de la classe Controller Identification
*/

class VisualiserIdentification;

/**
 * @brief The PresenterIdentification class
 * @author: GONCALVES H
 * @desc: Classe frontière entre le controller visualiserIdentifaction et l'UI d'identification
 */
class PresenterIdentification : public QObject
{
    Q_OBJECT

public:

    // Constructeur - Destructeur
        explicit PresenterIdentification(QObject *parent = nullptr)  : QObject(parent), monController(nullptr) {}
        ~PresenterIdentification() {}

    // Méthodes utilisable par l'UI
        Q_INVOKABLE bool creerCompte(QString pseudo, QString mdp, QString mail, QString nom, QString prenom, QString age);
        Q_INVOKABLE bool rechercherCompte(QString pseudo, QString mdp);
        Q_INVOKABLE VisualiserIdentification *getMonController() const              { return this->monController; }

    // Mutateur
        void setController(VisualiserIdentification *monController)                 { this->monController = monController; }

private:

    // Attributs
        VisualiserIdentification *monController;

};

#endif // PRESENTERIDENTIFICATION_H
