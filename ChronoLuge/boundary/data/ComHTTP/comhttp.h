#ifndef COMHTTP_H
#define COMHTTP_H

/*
 * Inclusion des bibliothèques
*/

#include <QObject>
#include <QNetworkAccessManager>
#include <QIODevice>
#include <QNetworkReply>
#include <QDebug>
#include <QUrlQuery>
#include <QVector>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QJsonArray>

/*
 * Inclusion des classes Controller
*/
class VisualiserTempsVitesse;
class VisualiserIdentification;

/**
 * @brief Classe: CommunicationHTTP
 * @author: Goncalves H
 * @desc: Classe frontière entre les controllers et l'API REST
 * @protocol: HTTP
 */
class ComHTTP : public QObject
{
    Q_OBJECT

public:

    // Constructeur - Destructeur
        ComHTTP(QObject *parent = nullptr);
        ~ComHTTP() {}

    // Méthodes publiques
        void lierDescente(int idUtilisateur, QString QRCode);
        void nouveauCompte(QString pseudo, QString mdp, QString email, QString nom, QString prenom, int age);
        void rechercherCompte(QString pseudo, QString mdp);
        void rechercherDescentes(int idUtilisateur);
        void rechercherStatistiques(int idUtilisateur);

        // Mutateur
            void setControllerTempsVitesse(VisualiserTempsVitesse *controller)          { this->monControllerTempsVitesse = controller; }
            void setControllerIdentification(VisualiserIdentification *controller)      { this->monControllerIdentification = controller; }

private:

    // Attributs
        QNetworkAccessManager *managerHTTP;
        QNetworkRequest requete;

        // Mes controllers
            VisualiserTempsVitesse *monControllerTempsVitesse;
            VisualiserIdentification *monControllerIdentification;

    // Méthodes privées
        void requeteGet();
        void requetePost(QByteArray maRequete);

private slots:

    // Slots
        void lireReponse(QNetworkReply *reponse);

};
#endif // COMHTTP_H
