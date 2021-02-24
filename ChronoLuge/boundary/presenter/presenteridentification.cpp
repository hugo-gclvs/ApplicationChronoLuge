#include "presenteridentification.h"
#include "controller/visualiseridentification.h"

PresenterIdentification::PresenterIdentification(QObject *parent) : QObject(parent), monController(nullptr)
{
}

PresenterIdentification::~PresenterIdentification()
{

}

void PresenterIdentification::creerCompte(QString pseudo, QString mdp, QString mail, QString nom, QString prenom, QString age)
{
    this->monController->creerCompte(pseudo, mdp, mail, nom, prenom, age.toInt());
}

void PresenterIdentification::rechercherCompte(QString pseudo, QString mdp)
{
    this->monController->rechercherCompte(pseudo, mdp);
}
