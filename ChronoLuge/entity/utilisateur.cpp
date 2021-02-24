#include "utilisateur.h"

Utilisateur::Utilisateur(QString pseudo, QString mdp, QString mail, QString nom, QString prenom, int age, int pdp, int idUtilisateur) :
    pseudo(pseudo), mdp(mdp), mail(mail), nom(nom), prenom(prenom), age(age), pdp(pdp), idUtilisateur(idUtilisateur),
    mesStatistiques(nullptr)
{
}

Utilisateur::~Utilisateur()
{

}

void Utilisateur::setStatistiques(Statistiques *statistiques)
{
    this->mesStatistiques = statistiques;
}


