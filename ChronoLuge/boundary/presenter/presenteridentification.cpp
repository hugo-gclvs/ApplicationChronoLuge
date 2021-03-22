#include "presenteridentification.h"
#include "controller/visualiseridentification.h"

/**
 * @brief PresenterIdentification::creerCompte
 * @param pseudo
 * @param mdp
 * @param mail
 * @param nom
 * @param prenom
 * @param age
 * @return
 * @desc: Méthode de création de compte: l'UI appelle cette méthode quand l'utilisateur se créer un compte
 */
bool PresenterIdentification::creerCompte(QString pseudo, QString mdp, QString mail, QString nom, QString prenom, QString age)
{
    if(this->monController->creerCompte(pseudo, mdp, mail, nom, prenom, age.toInt()))
        return true;
    return false;
}


/**
 * @brief PresenterIdentification::rechercherCompte
 * @param pseudo
 * @param mdp
 * @return
 * @desc: Méthode de recherche de compte: l'UI appelle cette méthode quand l'utilisateur se connecte
 */
bool PresenterIdentification::rechercherCompte(QString pseudo, QString mdp)
{
    if(this->monController->rechercherCompte(pseudo, mdp))
        return true;
    return false;
}

void PresenterIdentification::setEtatInscription()
{
    this->monController->getEtatInscription()->setValue("etatInscription", "inscrit");
}
