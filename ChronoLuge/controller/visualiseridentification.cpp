#include "visualiseridentification.h"

VisualiserIdentification::VisualiserIdentification(PresenterIdentification *monPresenter, ComHTTP *communicationHTTP, QObject *parent) :
    QObject(parent),
    monPresenter(monPresenter),
    monUtilisateur(nullptr),
    communicationHTTP(communicationHTTP)
{
    this->monPresenter->setController(this);
    this->communicationHTTP->setControllerIdentification(this);



    //connect(this, SIGNAL(postInscription()), this, SLOT(postInscriptionSucces()));
}

void VisualiserIdentification::creerCompte(QString pseudo, QString mdp, QString mail, QString nom, QString prenom, int age)
{
    // Vérification de la bonne saisie en créant une instance de utilisateur
        Utilisateur *userTemp = new Utilisateur(pseudo, mdp, mail, nom, prenom, age);

    // Envoi de l'utilisateur a la communication http
        communicationHTTP->nouveauCompte(userTemp->getPseudo(), userTemp->getMdp(), userTemp->getMail(), userTemp->getNom(), userTemp->getPrenom(), userTemp->getAge());

        userTemp->deleteLater();
}

void VisualiserIdentification::rechercherCompte(QString pseudo, QString mdp)
{
    // Vérification de la bonne saisie en créant une instance de utilisateur
        Utilisateur *userTemp = new Utilisateur(pseudo, mdp);

    // Envoi de l'utilisateur a la communication http
        communicationHTTP->rechercherCompte(userTemp->getPseudo(), userTemp->getMdp());

        userTemp->deleteLater();
}

void VisualiserIdentification::initUtilisateur(QVector<QString> *utilisateur)
{
    // Initialisation de l'utilisateur
        monUtilisateur = new Utilisateur(utilisateur->at(1), utilisateur->at(2), utilisateur->at(3), utilisateur->at(4), utilisateur->at(5), utilisateur->at(6).toInt(), utilisateur->at(7).toInt(), utilisateur->at(0).toInt());

}

void VisualiserIdentification::setStatistiques(int nmbrDescente, double vitesseMoy, double vitesseMin, double vitesseMax, QString tempsMoy, QString tempsMin, QString tempsMax)
{
    monUtilisateur->setStatistiques(new Statistiques(nmbrDescente, vitesseMoy, vitesseMin, vitesseMax, tempsMoy, tempsMin, tempsMax));
}

