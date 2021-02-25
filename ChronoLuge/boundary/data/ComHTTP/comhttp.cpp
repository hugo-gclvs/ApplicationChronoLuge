#include "comhttp.h"
#include "controller/visualisertempsvitesse.h"

/**
 * @brief ComHTTP::ComHTTP
 * @param parent
 * @desc: Construction de la classe ComHTTP
 * - Initialisation des différents attributs
 * - Connection entre les différents signals et slots de la classe QNetworkAccessManager
 * - Definition de l'entete de la communication
 */
ComHTTP::ComHTTP(QObject *parent) : QObject(parent),
    managerHTTP(new QNetworkAccessManager),
    monControllerTempsVitesse(nullptr),
    monControllerIdentification(nullptr)
{
    // Connection entre les différents signals et slots de la classe QNetworkAccessManager
        connect(this->managerHTTP, SIGNAL(finished(QNetworkReply*)), this, SLOT(lireReponse(QNetworkReply*)));

    // Definition de l'entete de la communication
        this->requete.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
}


/**
 * @brief ComHTTP::lierDescente
 * @param idUtilisateur
 * @param QRCode
 * @desc: Méthode de liaison d'une nouvelle descente
 * - Définition de l'URL courrant de la requête (API REST)
 * - Création d'objets JSON (requete de destination, idUtilisateur et QRCode (contenu)) à envoyé dans la requete
 * - Appel de la méthode post la classe courante
 */
void ComHTTP::lierDescente(int idUtilisateur, QString QRCode)
{
    // Définition de l'URL courrant de la requête (API REST)
        this->requete.setUrl(QUrl("https://chronoluge.000webhostapp.com/lierDescente.php"));

    // Création d'objets JSON (requete de destination, idUtilisateur et QRCode (contenu)) à envoyé dans la requete
        QJsonObject obj;

        obj["requeteDest"]  = "postLierDescente";
        obj["idUtilisateur"] = idUtilisateur;
        obj["QRCode"] = QRCode;

        QJsonDocument doc(obj);
        QByteArray data = doc.toJson();

    // Appel de la méthode post la classe courante
        this->requetePost(data);
}


/**
 * @brief ComHTTP::nouveauCompte
 * @param pseudo
 * @param mdp
 * @param email
 * @param nom
 * @param prenom
 * @param age
 * @desc: Méthode de création d'un nouveau compte utilisateur
 * - Définition de l'URL courrant de la requête (API REST)
 * - Création d'objets JSON (requete de destination, pseudo, mdp, etc...) à envoyé dans la requete
 * - Appel de la méthode post la classe courante
 */
void ComHTTP::nouveauCompte(QString pseudo, QString mdp, QString email, QString nom, QString prenom, int age)
{
    // Définition de l'URL courrant de la requête (API REST)
        this->requete.setUrl(QUrl("https://chronoluge.000webhostapp.com/identification.php"));

    // Création d'objets JSON (requete de destination, pseudo, mdp, etc...) à envoyé dans la requete
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

    // Appel de la méthode post la classe courante
        this->requetePost(data);
}


/**
 * @brief ComHTTP::rechercherCompte
 * @param pseudo
 * @param mdp
 * @desc: Méthode de recherche de compte: vérifier si l'identification est correcte
 * - Définition de l'URL courrant de la requête (API REST)
 * - Création d'objets JSON (requete de destination, pseudo et mdp) à envoyé dans la requete
 * - Appel de la méthode post la classe courante
 */
void ComHTTP::rechercherCompte(QString pseudo, QString mdp)
{
    // Définition de l'URL courrant de la requête (API REST)
        this->requete.setUrl(QUrl("https://chronoluge.000webhostapp.com/identification.php"));

    // Création d'objets JSON (requete de destination, pseudo et mdp) à envoyé dans la requete
        QJsonObject obj;

        obj["requeteDest"] = "postConnexion";
        obj["pseudo"] = pseudo;
        obj["mdp"] = mdp;

        QJsonDocument doc(obj);
        QByteArray data = doc.toJson();

    // Appel de la méthode post la classe courante
        this->requetePost(data);
}


/**
 * @brief ComHTTP::rechercherDescentes
 * @param idUtilisateur
 * @desc: Méthode de recherche de descente: récuperer les descentes de l'utilisteur connecté
 * - Définition de l'URL courrant de la requête (API REST)
 * - Ajout de l'idUtilisateur dans l'URI
 * - Appel de la méthode get la classe courante
 */
void ComHTTP::rechercherDescentes(int idUtilisateur)
{
    // Définition de l'URL courrant de la requête (API REST) + Ajout de l'idUtilisateur dans l'URI
        this->requete.setUrl(QUrl("https://chronoluge.000webhostapp.com/historique.php?idUtilisateur=" + QString::number(idUtilisateur)));

    // Appel de la méthode get la classe courante
        this->requeteGet();
}


/**
 * @brief ComHTTP::rechercherStatistiques
 * @param idUtilisateur
 * @desc: Méthode de recherche de statistiques: récuperer les statistiques de l'utilisteur connecté
 * - Définition de l'URL courrant de la requête (API REST)
 * - Ajout de l'idUtilisateur dans l'URI
 * - Appel de la méthode get la classe courante
 */
void ComHTTP::rechercherStatistiques(int idUtilisateur)
{
    // Définition de l'URL courrant de la requête (API REST) + Ajout de l'idUtilisateur dans l'URI
        this->requete.setUrl(QUrl("https://chronoluge.000webhostapp.com/statistique.php?idUtilisateur=" + QString::number(idUtilisateur)));

    // Appel de la méthode get la classe courante
        this->requeteGet();
}


/**
 * @brief ComHTTP::requeteGet
 * desc: Méthode privé de la classe courrante: envoyer une requête get a l'API
 * - Envoi de la requête get demander
 */
void ComHTTP::requeteGet()
{
    // Envoi de la requête get demander
        this->managerHTTP->get(requete);
}


/**
 * @brief ComHTTP::requetePost
 * desc: Méthode privé de la classe courrante: envoyer une requête post a l'API
 * - Envoi de la requête post demander
 */
void ComHTTP::requetePost(QByteArray mesDonnees)
{
    // Envoi de la requête post demander
        this->managerHTTP->post(requete, mesDonnees);
}


/**
 * @brief ComHTTP::lireReponse
 * @param reponse
 * desc: Slot de réponse de la demande faite à l'API
 * - Si erreur recontré, affichage de l'erreur en question + On quitte le slot
 * - Création et initialisation des différentes variables utiles à la méthode
 */
void ComHTTP::lireReponse(QNetworkReply *reponse)
{
    // Si erreur recontré, affichage de l'erreur en question + On quitte le slot
        if (reponse->error()) {
            qDebug() << reponse->errorString();
            return;
        }

    // Création et initialisation des différentes variables utiles à la méthode
        QVector<QString> *maReponse = new QVector<QString>;
        QString jsonData = (QString)reponse->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8());
        QJsonObject JsonObj= doc.object();

    if (JsonObj["statut"].toInt()) {

        qDebug() << "Nouvelle reception...";
        qDebug() << "Requete Source: "  << JsonObj["requeteSrc"].toString();

        if (JsonObj["requeteSrc"].toString() == "postConnexion") {

            maReponse->push_back(JsonObj.value(QString("data"))["idUtilisateur"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["pseudo"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["mdp"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["mail"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["nom"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["prenom"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["age"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["pdp"].toString());

            qDebug() << "Succès de la connexion !";

            // Initialisation de l'utilisateur et de la validation de connexion
                this->monControllerIdentification->initUtilisateur(maReponse);
                this->monControllerIdentification->getEtatConnexion()->setValue("etatConnexion", "connecte");

            // Emission du signal comme quoi la connexion est valide
                emit this->monControllerIdentification->postConnexion(true);

            // Recherche de l'historique du nouvel utilisateur
                rechercherDescentes(monControllerIdentification->getIdUtilisateur());

        }
        else if (JsonObj["requeteSrc"].toString() == "postInscription") {

            this->monControllerIdentification->getEtatInscription()->setValue("etatInscription", "inscrit");
            qDebug() << "Succès de l'inscription !";
            emit this->monControllerIdentification->postInscription(true);

        }
        else if (JsonObj["requeteSrc"].toString() == "getHistorique") {

            maReponse->push_back(JsonObj.value(QString("data"))["idUtilisateur"].toString());

            for (int i = 1 ; i < JsonObj.value(QString("data"))["nmbrDescente"].toInt()+1 ;  i++) {

                //qDebug() << JsonObj.value(QString("data"))["descente"+QString::number(i)]["date"].toString() + " " + JsonObj.value(QString("data"))["descente"+QString::number(i)]["temps"].toString() + " " + JsonObj.value(QString("data"))["descente"+QString::number(i)]["vitesse"].toString();
                maReponse->push_back(JsonObj.value(QString("data"))["descente"+QString::number(i)]["date"].toString() + " " + JsonObj.value(QString("data"))["descente"+QString::number(i)]["temps"].toString() + " " + JsonObj.value(QString("data"))["descente"+QString::number(i)]["vitesse"].toString());

            }

            this->monControllerTempsVitesse->initDescentes(maReponse);

        }
        else if (JsonObj["requeteSrc"].toString() == "postLierDescente") {

            qDebug() << "Liaison effectuee";
            emit this->monControllerTempsVitesse->postLierDescente(true);

        }
        else if (JsonObj["requeteSrc"].toString() == "getStatistique") {

            maReponse->push_back(JsonObj.value(QString("data"))["idUtilisateur"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["nombreDescente"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["vitesseMoy"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["vitesseMin"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["vitesseMax"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["tempsMoy"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["tempsMin"].toString());
            maReponse->push_back(JsonObj.value(QString("data"))["tempsMax"].toString());

            this->monControllerTempsVitesse->initStatistiques(maReponse);

        }

    } else if (!JsonObj["statut"].toInt()) {

        if (JsonObj["requeteSrc"].toString() == "postConnexion")
            emit this->monControllerIdentification->postConnexion(false);
        else if (JsonObj["requeteSrc"].toString() == "postInscription")
            emit this->monControllerIdentification->postInscription(false);
        else if (JsonObj["requeteSrc"].toString() == "postLierDescente")
            emit this->monControllerTempsVitesse->postLierDescente(false);
        else {
            qDebug() << "Message d'Erreur: "  << JsonObj["message"].toString();

            maReponse->push_back(JsonObj["statut"].toString());
            maReponse->push_back(JsonObj["requeteSrc"].toString());
            maReponse->push_back(JsonObj["message"].toString());
        }

    } else
        qDebug() << "Reception invalide";

    reponse->deleteLater();
}

