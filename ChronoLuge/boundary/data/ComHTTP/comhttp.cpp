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
 * @brief ComHTTP::majPP
 * @param idUtilisateur
 * @param pdp
 * @desc: Méthode de modification de photo de profil
 * - Définition de l'URL courrant de la requête (API REST)
 * - Création d'objets JSON (requete de destination, idUtilisateur, pdp) à envoyé dans la requete
 * - Appel de la méthode post la classe courante
 */
void ComHTTP::majPP(int idUtilisateur, int pdp)
{
    // Définition de l'URL courrant de la requête (API REST)
        this->requete.setUrl(QUrl("https://chronoluge.000webhostapp.com/nouvellePdp.php"));

    // Création d'objets JSON (requete de destination, pseudo, mdp, etc...) à envoyé dans la requete
        QJsonObject obj;

        obj["requeteDest"] = "postNewPdp";
        obj["idUtilisateur"] = idUtilisateur;
        obj["pdp"] = pdp;

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
 * @desc: Méthode privé de la classe courrante: envoyer une requête get a l'API
 * - Envoi de la requête get demander
 */
void ComHTTP::requeteGet()
{
    // Envoi de la requête get demander
        this->managerHTTP->get(requete);
}


/**
 * @brief ComHTTP::requetePost
 * @desc: Méthode privé de la classe courrante: envoyer une requête post a l'API
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
 * @desc: Slot de réponse de la demande faite à l'API
 * - Traitement de chaque réponses
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
        QString jsonData = QString(reponse->readAll());
        QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8());
        QJsonObject JsonObj= doc.object();

    // Vérification du statut de la réponse
        if (JsonObj["statut"].toInt())
        {
            qDebug() << "----> Nouvelle reception...";
            qDebug() << "----> Requete Source: "  << JsonObj["requeteSrc"].toString();

            // Traitement de la requete (récupération de la requete source, pour renvoi de la réponse)
                if (JsonObj["requeteSrc"].toString() == "postConnexion")
                {
                    // Ajout des données reçus dans le vecteur "maReponse"
                        maReponse->push_back(JsonObj.value("data")["idUtilisateur"].toString());
                        maReponse->push_back(JsonObj.value("data")["pseudo"].toString());
                        maReponse->push_back(JsonObj.value("data")["mdp"].toString());
                        maReponse->push_back(JsonObj.value("data")["mail"].toString());
                        maReponse->push_back(JsonObj.value("data")["nom"].toString());
                        maReponse->push_back(JsonObj.value("data")["prenom"].toString());
                        maReponse->push_back(JsonObj.value("data")["age"].toString());
                        maReponse->push_back(JsonObj.value("data")["pdp"].toString());

                    qDebug() << "/!\\ Succès de la connexion !";

                    // Initialisation de l'utilisateur et de la validation de connexion
                        this->monControllerIdentification->initUtilisateur(maReponse);
                        this->monControllerIdentification->getEtatConnexion()->setValue("etatConnexion", "connecte");

                    // Emission du signal comme quoi la connexion est valide
                        emit this->monControllerIdentification->postConnexion(true);

                    // Recherche de l'historique de descente du nouvel utilisateur
                        this->rechercherDescentes(monControllerIdentification->getIdUtilisateur());

                    // Recherche des statistiques du nouvel utilisateur
                        this->rechercherStatistiques(monControllerIdentification->getIdUtilisateur());

                }
                else if (JsonObj["requeteSrc"].toString() == "postInscription")
                {
                    qDebug() << "/!\\ Succès de l'inscription !";

                    // Initialisation de la validation d'inscription
                        this->monControllerIdentification->getEtatInscription()->setValue("etatInscription", "inscrit");

                    // Emission du signal comme quoi l'inscription est valide
                        emit this->monControllerIdentification->postInscription(true);

                }
                else if (JsonObj["requeteSrc"].toString() == "postNewPdp")
                {
                    qDebug() << "/!\\ Succès de la demande de modification de PP !";

                        qDebug() << "...initialisation de la nouvelle PP";
                        monControllerIdentification->getMonUtilisatateur()->setPdp(JsonObj["nouvellePdp"].toInt());

                    // Emission du signal comme quoi la nouvelle PP est valide
                        emit this->monControllerTempsVitesse->postNewPP(true, QString::number(monControllerIdentification->getMonUtilisatateur()->getPdp()-1));

                    qDebug() << "/!\\ Succès de la modification de PP !";
                }
                else if (JsonObj["requeteSrc"].toString() == "getHistorique")
                {
                    // Récupération et ajout de l'idUtilisateur dans le but de vérifié qu'il correspond à l'utilisateur courrant
                        maReponse->push_back(JsonObj.value("data")["idUtilisateur"].toString());

                    // Ajout de chaque descente dans le vector: chaque descente est un unique qstring (concaténation de chaque valeur de la descente)
                        for (int i = 1 ; i < JsonObj.value("data")["nmbrDescente"].toInt()+1 ;  i++)
                            maReponse->push_back(JsonObj.value("data")["descente"+QString::number(i)]["date"].toString() + " " + JsonObj.value("data")["descente"+QString::number(i)]["temps"].toString() + " " + JsonObj.value("data")["descente"+QString::number(i)]["vitesse"].toString());

                    // Appel de la méthode pour initialiser les descentes de l'utilisateur
                        this->monControllerTempsVitesse->initDescentes(maReponse);

                }
                else if (JsonObj["requeteSrc"].toString() == "postLierDescente")
                {
                    qDebug() << "/!\\ Liaison effectuee !";

                    // Emission du signal comme quoi la laison est valide
                        emit this->monControllerTempsVitesse->postLierDescente(true);

                }
                else if (JsonObj["requeteSrc"].toString() == "getStatistique")
                {
                    // Ajout des données reçus dans le vecteur "maReponse"
                        maReponse->push_back(JsonObj.value("data")["idUtilisateur"].toString());
                        maReponse->push_back(JsonObj.value("data")["nombreDescente"].toString());
                        maReponse->push_back(JsonObj.value("data")["vitesseMoy"].toString());
                        maReponse->push_back(JsonObj.value("data")["vitesseMin"].toString());
                        maReponse->push_back(JsonObj.value("data")["vitesseMax"].toString());
                        maReponse->push_back(JsonObj.value("data")["tempsMoy"].toString());
                        maReponse->push_back(JsonObj.value("data")["tempsMin"].toString());
                        maReponse->push_back(JsonObj.value("data")["tempsMax"].toString());

                    // Appel de la méthode pour initialiser les statistiques de l'utilisateur
                        this->monControllerTempsVitesse->initStatistiques(maReponse);

                }

        }
        else if (!JsonObj["statut"].toInt())
        {
            // Traitement des echec par le status
                if (JsonObj["requeteSrc"].toString() == "postConnexion")
                    emit this->monControllerIdentification->postConnexion(false);
                else if (JsonObj["requeteSrc"].toString() == "postInscription")
                    emit this->monControllerIdentification->postInscription(false);
                else if (JsonObj["requeteSrc"].toString() == "postLierDescente")
                    emit this->monControllerTempsVitesse->postLierDescente(false);
                else if (JsonObj["requeteSrc"].toString() == "postNewPdp")
                    emit this->monControllerTempsVitesse->postNewPP(false, QString::number(-1));
                else
                {
                    qDebug() << "/!\\ Message d'Erreur: "  << JsonObj["message"].toString();

                    maReponse->push_back(JsonObj["statut"].toString());
                    maReponse->push_back(JsonObj["requeteSrc"].toString());
                    maReponse->push_back(JsonObj["message"].toString());
                }

        } else
            // Traitement des erreurs (timeout)
                qDebug() << "/!\\ Reception invalide !";

    // Suppression du pointeur dynamique
        reponse->deleteLater();
}

