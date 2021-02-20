#include "comhttp.h"

ComHTTP::ComHTTP(QWidget *parent) : QWidget(parent),
    managerHTTP(new QNetworkAccessManager)
{
    connect(managerHTTP, SIGNAL(finished(QNetworkReply*)), this, SLOT(lireReponse(QNetworkReply*)));
    requete.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
}

ComHTTP::~ComHTTP()
{
}


void ComHTTP::lierDescente(int numLuge, QString QRCode)
{
    requete.setUrl(QUrl("http://localhost/WampFile/PROJET/lierDescente.php"));

    QJsonObject obj;

    obj["requeteDest"] = "postDescente";
    obj["numLuge"] = numLuge;
    obj["QRCode"] = QRCode;

    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();

    this->requetePost(data);
}

void ComHTTP::nouveauCompte(QString pseudo, QString mdp, QString email, QString nom, QString prenom, int age)
{
    requete.setUrl(QUrl("http://localhost/WampFile/PROJET/identification.php"));

    QJsonObject obj;

    obj["requeteDest"] = "postInscription";
    obj["pseudo"] = pseudo;
    obj["mdp"] = mdp;
    obj["email"] = email;
    obj["nom"] = nom;
    obj["prenom"] = prenom;
    obj["age"] = age;

    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();

    this->requetePost(data);
}

void ComHTTP::rechercherCompte(QString pseudo, QString mdp)
{
    requete.setUrl(QUrl("http://localhost/WampFile/PROJET/identification.php"));

    QJsonObject obj;

    obj["requeteDest"] = "postConnexion";
    obj["pseudo"] = pseudo;
    obj["mdp"] = mdp;

    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();

    this->requetePost(data);
}

void ComHTTP::rechercherHistorique(int idUtilisateur)
{
    QString monUrl("http://localhost/WampFile/PROJET/historique.php?idUtilisateur=");

    monUrl += QString::number(idUtilisateur);
    requete.setUrl(QUrl(monUrl));

    this->requeteGet();
}

void ComHTTP::rechercherStatistiques(int idUtilisateur)
{
    QString monUrl("http://localhost/WampFile/PROJET/statistique.php?idUtilisateur=");

    monUrl += QString::number(idUtilisateur);
    requete.setUrl(QUrl(monUrl));

    this->requeteGet();
}

void ComHTTP::requeteGet()
{
    managerHTTP->get(requete);
}

void ComHTTP::requetePost(QByteArray mesDonnees)
{
    managerHTTP->post(requete, mesDonnees);
}


void ComHTTP::lireReponse(QNetworkReply *reponse)
{
    if (reponse->error()) {
        qDebug() << reponse->errorString();
        return;
    }

    QVector<QString> maReponse;

    QString jsonData = (QString)reponse->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8());
    QJsonObject JsonObj= doc.object();

    if (JsonObj["statut"].toInt()) {

        qDebug() << "Message: "  << JsonObj["message"].toString();

        if (JsonObj["requeteSrc"].toString() == "postConnexion") {

            maReponse.push_back(JsonObj.value(QString("data"))["idUtilisateur"].toString());
            maReponse.push_back(JsonObj.value(QString("data"))["pseudo"].toString());
            maReponse.push_back(JsonObj.value(QString("data"))["mdp"].toString());
            maReponse.push_back(JsonObj.value(QString("data"))["nom"].toString());
            maReponse.push_back(JsonObj.value(QString("data"))["prenom"].toString());
            maReponse.push_back(JsonObj.value(QString("data"))["age"].toString());
            maReponse.push_back(JsonObj.value(QString("data"))["pdp"].toString());

        }
        else if (JsonObj["requeteSrc"].toString() == "postInscription") {

            qDebug() << "Message: "  << JsonObj["message"].toString();

        }
        else if (JsonObj["requeteSrc"].toString() == "getHistorique") {

            qDebug() << JsonObj.value(QString("data"))["idUtilisateur"].toString();
            maReponse.push_back(JsonObj.value(QString("data"))["idUtilisateur"].toString());

            for (int i = 1 ; i < JsonObj.value(QString("data"))["nmbrDescente"].toInt()+1 ;  i++) {

                qDebug() << JsonObj.value(QString("data"))["descente"+QString::number(i)]["date"].toString() + " " + JsonObj.value(QString("data"))["descente"+QString::number(i)]["temps"].toString() + " " + JsonObj.value(QString("data"))["descente"+QString::number(i)]["vitesse"].toString();
                maReponse.push_back(JsonObj.value(QString("data"))["descente"+QString::number(i)]["date"].toString() + " " + JsonObj.value(QString("data"))["descente"+QString::number(i)]["temps"].toString() + " " + JsonObj.value(QString("data"))["descente"+QString::number(i)]["vitesse"].toString());

            }

        }
        else if (JsonObj["requeteSrc"].toString() == "getStatistique") {

        }

    } else {

        qDebug() << "Message: "  << JsonObj["message"].toString();

        maReponse.push_back(JsonObj["statut"].toString());
        maReponse.push_back(JsonObj["requeteSrc"].toString());
        maReponse.push_back(JsonObj["message"].toString());

    }

    //methodeRetourController(maReponse);

    reponse->deleteLater();

}

