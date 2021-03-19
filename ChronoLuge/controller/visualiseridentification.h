#ifndef VISUALISERIDENTIFICATION_H
#define VISUALISERIDENTIFICATION_H

/*
 * Inclusion des bibliothèques/classes
*/

#include <QObject>
#include <QSettings>
#include "boundary/presenter/presenteridentification.h"
#include "boundary/data/ComHTTP/comhttp.h"
#include "entity/utilisateur.h"

/**
 * @brief The VisualiserIdentification class
 * @author: GONCALVES H
 * @desc: Classe de liaison entre les presenter VisualiserIdentification et les classes de communication (data)
 */
class VisualiserIdentification : public QObject
{
    Q_OBJECT

public:

    // Constructeurs - Destructeur
        explicit VisualiserIdentification(PresenterIdentification *monPresenter, ComHTTP *communicationHTTP, QObject *parent = nullptr);
        explicit VisualiserIdentification(QObject *parent = nullptr) : QObject(parent) {}
        ~VisualiserIdentification() override {}

    // Méthodes
        bool creerCompte(QString pseudo, QString mdp, QString mail, QString nom, QString prenom, int age);
        bool rechercherCompte(QString pseudo, QString mdp);
        bool initUtilisateur(QVector<QString> *utilisateur);

        // Mutateur
            bool setStatistiques(int nmbrDescente, double vitesseMoy, double vitesseMin, double vitesseMax, QString tempsMoy, QString tempsMin, QString tempsMax);

        // Accesseurs
            int getIdUtilisateur() const                                    { return this->monUtilisateur->getIdUtilisateur(); }
            PresenterIdentification *getPresenterIdentification() const     { return this->monPresenter; }
            QSettings *getEtatConnexion() const                             { return this->etatConnexion;}
            QSettings *getEtatInscription() const                           { return this->etatInscription;}
            Statistiques *getMesStatistiques() const                        { return this->monUtilisateur->getMesStatistiques(); }
            Utilisateur *getMonUtilisatateur() const                        { return this->monUtilisateur; }
            Q_INVOKABLE int getNumPdp() const                                           { return this->monUtilisateur->getPdp(); }

private:

    // Attributs

        // Presenter
        PresenterIdentification *monPresenter;

        // Entity
            Utilisateur *monUtilisateur;

        // Data
            ComHTTP *communicationHTTP;

        // Settings
            QSettings *etatConnexion = new QSettings("etatConnexion", "nonconnecte");
            QSettings *etatInscription = new QSettings("etatInscription", "noninscrit");

signals:
    void postConnexion(const bool &valeurReussite);             // Signal à émettre pour récuperer l'etat de connexion
    void postInscription(const bool &valeurReussite);           // Signal à émettre pour récuperer l'etat d'inscription

};

#endif // VISUALISERIDENTIFICATION_H
