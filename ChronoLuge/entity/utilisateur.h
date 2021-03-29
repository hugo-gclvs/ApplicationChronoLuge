#ifndef UTILISATEUR_H
#define UTILISATEUR_H

/*
 * Inclusion des bibliothèques/classes
*/

#include <QObject>
#include <QDebug>
#include "entity/statistiques.h"

/**
 * @brief The Utilisateur class
 * @author: GONCALVES H
 * @desc: Méthode entité d'un utilisateur
 */
class Utilisateur : public QObject
{
    // Macro
        Q_OBJECT

public:

    // Constructeur - Destructeur
        explicit Utilisateur(QString pseudo, QString mdp, QString mail = "0", QString nom = "0", QString prenom = "0", int age = 0, QString pdp = "0", int idUtilisateur = 0);
        ~Utilisateur() override {}

    // Méthodes
        bool setStatistiques(Statistiques *statistiques);

        // Accesseurs
            QString getPseudo() const                       { return pseudo; }
            QString getMdp() const                          { return mdp; }
            QString getMail() const                         { return mail; }
            QString getNom() const                          { return nom; }
            QString getPrenom() const                       { return prenom; }
            int getAge() const                              { return age; }
            QString getPdp() const                          { return pdp; }
            int getIdUtilisateur() const                    { return idUtilisateur; }

            Statistiques *getMesStatistiques() const        { return mesStatistiques; }

        // Muttateurs
            void setPdp(QString pdp)                            { this->pdp = pdp; }


private:

    // Attributs
        QString pseudo;
        QString mdp;
        QString mail;
        QString nom;
        QString prenom;
        int age;
        QString pdp;
        int idUtilisateur;

        Statistiques *mesStatistiques;

};

#endif // UTILISATEUR_H
