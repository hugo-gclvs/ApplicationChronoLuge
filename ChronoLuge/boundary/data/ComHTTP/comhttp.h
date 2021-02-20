#ifndef COMHTTP_H
#define COMHTTP_H

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

class VisualiserTempsVitesse;
class VisualiserIdentification;

class ComHTTP : public QObject
{
    Q_OBJECT

public:
    ComHTTP(QObject *parent = nullptr);
    ~ComHTTP();

    void lierDescente(int idUtilisateur, QString QRCode);
    void nouveauCompte(QString pseudo, QString mdp, QString email, QString nom, QString prenom, int age);
    void rechercherCompte(QString pseudo, QString mdp);
    void rechercherDescentes(int idUtilisateur);
    void rechercherStatistiques(int idUtilisateur);

    void setControllerTempsVitesse(VisualiserTempsVitesse *controller) { this->monControllerTempsVitesse = controller; }
    void setControllerIdentification(VisualiserIdentification *controller) { this->monControllerIdentification = controller; }

private:
    QNetworkAccessManager *managerHTTP;
    QNetworkRequest requete;

    VisualiserTempsVitesse *monControllerTempsVitesse;
    VisualiserIdentification *monControllerIdentification;

    void requeteGet();
    void requetePost(QByteArray maRequete);

private slots:
    void lireReponse(QNetworkReply *reponse);

};
#endif // COMHTTP_H
