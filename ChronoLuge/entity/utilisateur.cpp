#include "utilisateur.h"

/**
 * @brief Utilisateur::Utilisateur
 * @param pseudo
 * @param mdp
 * @param mail
 * @param nom
 * @param prenom
 * @param age
 * @param pdp
 * @param idUtilisateur
 * - Initialisation des différents attributs
 */
Utilisateur::Utilisateur(QString pseudo, QString mdp, QString mail, QString nom, QString prenom, int age, QString lienPdp, int idUtilisateur) :
    pseudo(pseudo),
    mdp(mdp),
    mail(mail),
    nom(nom),
    prenom(prenom),
    age(age),
    lienPdp(lienPdp),
    idUtilisateur(idUtilisateur),
    mesStatistiques(nullptr)
{
}


/**
 * @brief Utilisateur::setStatistiques
 * @param statistiques
 * @return
 * @desc: Méthode de set des statistiques de l'utilisateur courant
 * - Initialisation des statistiques à l'utilisateur courant
 */
bool Utilisateur::setStatistiques(Statistiques *statistiques)
{
    // Initialisation des statistiques à l'utilisateur courant
        this->mesStatistiques = statistiques;

    return true;
}


