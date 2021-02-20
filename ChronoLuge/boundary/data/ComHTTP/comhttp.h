#ifndef COMHTTP_H
#define COMHTTP_H

#include <QWidget>
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

class ComHTTP : public QWidget
{
    Q_OBJECT

public:
    ComHTTP(QWidget *parent = nullptr);
    ~ComHTTP();

    void lierDescente(int idUtilisateur, QString QRCode);
    void nouveauCompte(QString pseudo, QString mdp, QString email, QString nom, QString prenom, int age);
    void rechercherCompte(QString pseudo, QString mdp);
    void rechercherHistorique(int idUtilisateur);
    void rechercherStatistiques(int idUtilisateur);

private:
    QNetworkAccessManager *managerHTTP;
    QNetworkRequest requete;

    void requeteGet();
    void requetePost(QByteArray maRequete);

private slots:
    void lireReponse(QNetworkReply *reponse);

};
#endif // COMHTTP_H
