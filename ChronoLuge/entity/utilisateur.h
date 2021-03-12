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
        Q_PROPERTY(QString pseudo READ getPseudo)
        Q_PROPERTY(QString mdp READ getPrenom)
        Q_PROPERTY(QString mail READ getMail)
        Q_PROPERTY(QString nom READ getNom)
        Q_PROPERTY(QString prenom READ getPrenom)
        Q_PROPERTY(int age READ getAge)
        Q_PROPERTY(int pdp READ getPdp)

public:

    // Constructeur - Destructeur
        explicit Utilisateur(QString pseudo, QString mdp, QString mail = NULL, QString nom = NULL, QString prenom = NULL, int age = 0, int pdp = 0, int idUtilisateur = 0);
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
            int getPdp() const                              { return pdp; }
            int getIdUtilisateur() const                    { return idUtilisateur; }

            Statistiques *getMesStatistiques() const        { return mesStatistiques; }


private:

    // Attributs
        QString pseudo;
        QString mdp;
        QString mail;
        QString nom;
        QString prenom;
        int age;
        int pdp;
        int idUtilisateur;

        Statistiques *mesStatistiques;

};

#endif // UTILISATEUR_H
