#include "presentervisualisertempsvitesse.h"
#include "controller/visualisertempsvitesse.h"

/**
 * @brief PresenterVisualiserTempsVitesse::lierDescente
 * @param QRCode
 * @return
 * @desc: Méthode de liaison de descente: l'UI appelle cette méthode quand l'utilisateur scanne un QRCode
 */
bool PresenterVisualiserTempsVitesse::lierDescente(QString QRCode)
{
    if(this->monController->lierDescente(QRCode))
        return true;
    return false;
}


/**
 * @brief PresenterVisualiserTempsVitesse::rechercherHistorique
 * @return
 * @desc: Méthode de recherche de descente(historique): l'UI appelle cette méthode quand l'utilisateur à besoin de ses descentes
 */
bool PresenterVisualiserTempsVitesse::rechercherHistorique()
{
    if(this->monController->rechercherDescentes())
        return true;
    return false;
}


/**
 * @brief PresenterVisualiserTempsVitesse::rechercherStatistiques
 * @return
 * @desc: Méthode de recherche des statistiques: l'UI appelle cette méthode quand l'utilisateur à besoin de ses statistiques
 */
bool PresenterVisualiserTempsVitesse::rechercherStatistiques()
{
    if(this->monController->rechercherStatistiques())
        return true;
    return false;
}


/**
 * @brief PresenterVisualiserTempsVitesse::majPP
 * @param numPP
 * @desc: Méthode de mise à jour de la photo de profil utilisateur
 */
void PresenterVisualiserTempsVitesse::majPP(int numPP)
{
    monController->majPP(numPP);
}


/**
 * @brief PresenterVisualiserTempsVitesse::getMesStatistiques
 * @param maStat
 * @return
 * @desc: Méthode de récupération des statistiques de l'utilsateur pour l'UI
 */
QString PresenterVisualiserTempsVitesse::getMesStatistiques(int maStat)
{
    return monController->getMesStatistiques(maStat);
}


/**
 * @brief PresenterVisualiserTempsVitesse::getMonUtilisateur
 * @param monUtilisateur
 * @return
 * @desc: Méthode de récupération des infos de l'utilsateur pour l'UI
 */
QString PresenterVisualiserTempsVitesse::getMonUtilisateur(int monUtilisateur)
{
    return monController->getMonUtilisateur(monUtilisateur);
}
