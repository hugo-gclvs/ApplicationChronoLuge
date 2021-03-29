#include "visualiseridentification.h"

/**
 * @brief VisualiserIdentification::VisualiserIdentification
 * @param monPresenter
 * @param communicationHTTP
 * @param parent
 * @desc: Construction de la classe controller VisualiserIdentification
 * - Initialisation des différents attributs
 * - Set des controller avec l'objet courrant
 */
VisualiserIdentification::VisualiserIdentification(PresenterIdentification *monPresenter, ComHTTP *communicationHTTP, QObject *parent) :
    QObject(parent),
    monPresenter(monPresenter),
    monUtilisateur(nullptr),
    communicationHTTP(communicationHTTP)
{
    this->monPresenter->setController(this);
    this->communicationHTTP->setControllerIdentification(this);
}


/**
 * @brief VisualiserIdentification::creerCompte
 * @param pseudo
 * @param mdp
 * @param mail
 * @param nom
 * @param prenom
 * @param age
 * @return
 * @desc: Méthode de création de compte: le presenter appelle cette méthode quand l'utilisateur se créer un compte
 * - Vérification de la bonne saisie en créant une instance de utilisateur
 * - Envoi de l'utilisateur a la communication http
 */
bool VisualiserIdentification::creerCompte(QString pseudo, QString mdp, QString mail, QString nom, QString prenom, int age)
{
    // Vérification de la bonne saisie en créant une instance de utilisateur
        Utilisateur *userTemp = new Utilisateur(pseudo, mdp, mail, nom, prenom, age);

    // Envoi de l'utilisateur a la communication http
        communicationHTTP->nouveauCompte(userTemp->getPseudo(), userTemp->getMdp(), userTemp->getMail(), userTemp->getNom(), userTemp->getPrenom(), userTemp->getAge());

        userTemp->deleteLater();

    return true;
}


/**
 * @brief VisualiserIdentification::rechercherCompte
 * @param pseudo
 * @param mdp
 * @return
 * @desc: Méthode de recherche de compte: le presenter appelle cette méthode quand l'utilisateur se connecte à son compte
 * - Vérification de la bonne saisie en créant une instance de utilisateur
 * - Envoi de l'utilisateur a la communication http
 */
bool VisualiserIdentification::rechercherCompte(QString pseudo, QString mdp)
{
    // Vérification de la bonne saisie en créant une instance de utilisateur
        Utilisateur *userTemp = new Utilisateur(pseudo, mdp);

    // Envoi de l'utilisateur a la communication http
        communicationHTTP->rechercherCompte(userTemp->getPseudo(), userTemp->getMdp());

        userTemp->deleteLater();

    return true;
}


/**
 * @brief VisualiserIdentification::initUtilisateur
 * @param utilisateur
 * @return
 * @desc: Méthode d'inisialisation de l'utilisateur
 * - Initialisation de l'utilisateur avec ses informations
 */
bool VisualiserIdentification::initUtilisateur(QVector<QString> *utilisateur)
{
    qDebug() << "...initialisation de l'utilisateur";

    // Initialisation de l'utilisateur avec ses informations
        monUtilisateur = new Utilisateur(utilisateur->at(1), utilisateur->at(2), utilisateur->at(3), utilisateur->at(4), utilisateur->at(5), utilisateur->at(6).toInt(), utilisateur->at(7), utilisateur->at(0).toInt());

    qDebug() << "/!\\ Succès de l'initialisation de l'utilisateur !";

    return true;
}


/**
 * @brief VisualiserIdentification::setStatistiques
 * @param nmbrDescente
 * @param vitesseMoy
 * @param vitesseMin
 * @param vitesseMax
 * @param tempsMoy
 * @param tempsMin
 * @param tempsMax
 * @return
 * @desc: Méthode set des statistiques de l'utilisateur courant
 * - Vérification que le set des statistiques c'est bien passé
 */
bool VisualiserIdentification::setStatistiques(int nmbrDescente, double vitesseMoy, double vitesseMin, double vitesseMax, QString tempsMoy, QString tempsMin, QString tempsMax)
{
    // Vérification que le set des statistiques c'est bien passé
        if(monUtilisateur->setStatistiques(new Statistiques(nmbrDescente, vitesseMoy, vitesseMin, vitesseMax, tempsMoy, tempsMin, tempsMax)))
            return true;
        return false;
}

