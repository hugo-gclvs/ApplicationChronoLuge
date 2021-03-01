#ifndef VISUALISERIDENTIFICATION_H
#define VISUALISERIDENTIFICATION_H

#include <QObject>
#include <QSettings>

#include "boundary/presenter/presenteridentification.h"
#include "boundary/data/ComHTTP/comhttp.h"

#include "entity/utilisateur.h"

class VisualiserIdentification : public QObject
{
    Q_OBJECT

public:

    // Constructeur
        explicit VisualiserIdentification(PresenterIdentification *monPresenter, ComHTTP *communicationHTTP, QObject *parent = nullptr);
        explicit VisualiserIdentification(QObject *parent = nullptr) : QObject(parent) {}
        ~VisualiserIdentification() {}

    // Méthodes
        void creerCompte(QString pseudo, QString mdp, QString mail, QString nom, QString prenom, int age);
        void rechercherCompte(QString pseudo, QString mdp);

        void initUtilisateur(QVector<QString> *utilisateur);
        void setStatistiques(int nmbrDescente, double vitesseMoy, double vitesseMin, double vitesseMax, QString tempsMoy, QString tempsMin, QString tempsMax);

        int getIdUtilisateur()                                      { return monUtilisateur->getIdUtilisateur(); }
        PresenterIdentification *getPresenterIdentification()       { return monPresenter; }
        QSettings *getEtatConnexion() const                         { return etatConnexion;}
        QSettings *getEtatInscription() const                       { return etatInscription;}

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
    void postConnexion(const bool &valeurReussite);
    void postInscription(const bool &valeurReussite);

};

#endif // VISUALISERIDENTIFICATION_H
