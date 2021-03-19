#include "visualisertempsvitesse.h"

/**
 * @brief VisualiserTempsVitesse::VisualiserTempsVitesse
 * @param parent
 * @desc: Construction de la classe controller VisualiserTempsVitesse
 * - Initialisation des différents attributs
 * - Set des controller avec l'objet courrant
 */
VisualiserTempsVitesse::VisualiserTempsVitesse(QObject *parent) :
    QObject(parent),
    communicationHTTP(new ComHTTP),
    monPresenter(new PresenterVisualiserTempsVitesse),
    controllerIdentification(new PresenterIdentification, communicationHTTP)
{
    // Set des controller avec l'objet courrant
        this->monPresenter->setController(this);
        this->communicationHTTP->setControllerTempsVitesse(this);
}


/**
 * @brief VisualiserTempsVitesse::lierDescente
 * @param QRCode
 * @return
 * @desc: Méthode de liaison d'une nouvelle descente
 * - Vérification de l'identification du client
 * - Récupération de l'idUtilisteur
 * - Envoi demande de liaison descentes
 * - Si l'utilisateur n'est pas identifié l'interface QML gère l'affichage de l'identification
 */
bool VisualiserTempsVitesse::lierDescente(QString QRCode)
{
    // Vérification de l'identification du client
        if (controllerIdentification.getEtatConnexion()->value("etatConnexion").toString() == "connecte") {

            // Récupération de l'idUtilisteur
                int idUtilisateur = controllerIdentification.getIdUtilisateur();

            // Envoi demande de liaison descentes
                communicationHTTP->lierDescente(idUtilisateur, QRCode);

            return true;

        } else {

            qDebug() << "/!\\ L'utilisateur doit s'identifier !";
            // L'interface QML gère l'affichage de l'identification

            return false;

        }
}


/**
 * @brief VisualiserTempsVitesse::rechercherDescentes
 * @return
 * @desc: Méthode de recherche des descentes d'un utilisateur
 * - Vérification de l'identification du client
 * - Récupération de l'idUtilisteur
 * - Envoi demande recherche descentes
 * - Si l'utilisateur n'est pas identifié l'interface QML gère l'affichage de l'identification
 */
bool VisualiserTempsVitesse::rechercherDescentes()
{
    // Vérification de l'identification du client
        if (controllerIdentification.getEtatConnexion()->value("etatConnexion").toString() == "connecte") {

            // Récupération de l'idUtilisteur
                int idUtilisateur = controllerIdentification.getIdUtilisateur();

            // Envoi demande recherche descentes
                communicationHTTP->rechercherDescentes(idUtilisateur);

            return true;

        } else {

            qDebug() << "/!\\ L'utilisateur doit s'identifier !";
            // L'interface QML gère l'affichage de l'identification

            return false;

        }
}


/**
 * @brief VisualiserTempsVitesse::rechercherStatistiques
 * @return
 * @desc: Méthode de recherche des statistiques d'un utilisateur
 * - Vérification de l'identification du client
 * - Récupération de l'idUtilisteur
 * - Envoi demande recherche statistiques
 * - Si l'utilisateur n'est pas identifié l'interface QML gère l'affichage de l'identification
 */
bool VisualiserTempsVitesse::rechercherStatistiques()
{
    // Vérification de l'identification du client
        if (controllerIdentification.getEtatConnexion()->value("etatConnexion").toString() == "connecte") {

            // Récupération de l'idUtilisteur
                int idUtilisateur = controllerIdentification.getIdUtilisateur();

            // Envoi demande recherche statistiques
                communicationHTTP->rechercherStatistiques(idUtilisateur);

            return true;

        } else {

            qDebug() << "/!\\ L'utilisateur doit s'identifier !";
            // L'interface QML gère l'affichage de l'identification

            return false;

        }
}

bool VisualiserTempsVitesse::majPP(int numPP)
{
    communicationHTTP->majPP(controllerIdentification.getIdUtilisateur(), numPP);
    return true;
}


/**
 * @brief VisualiserTempsVitesse::initDescentes
 * @param descentes
 * @return
 * @desc: Méthode d'initialisation des descentes de l'utilisateur courant
 * - Vérification que les descentes sont bien celle de l'utilisateur courant
 * - Suppression des descentes de l'affichage
 * - Création et initialisation d'une entité descente pour chaque nouvelle descente
 * - Emission du signal listeChanged, pour prevenir la vue d'un changement
 */
bool VisualiserTempsVitesse::initDescentes(QVector<QString> *descentes)
{
    // Vérification que les descentes sont bien celle de l'utilisateur courant
        if(descentes->at(0).toInt() == controllerIdentification.getIdUtilisateur()) {

            qDebug() << "...initialisation des descentes de l'idUtilisateur: " << descentes->at(0).toInt();

            // Suppression des descentes de l'affichage
                mesDescentes.clear();

            // Création et inisialisation d'une entité descente pour chaque nouvelle descente
                for(int i = 1 ; i < descentes->count() ; i++)
                {
                    // Split du string reçu
                        QStringList splitInfoDescente = descentes->at(i).split(" ");

                    // Création et inisialisation d'une entité descente pour chaque nouvelle descente
                        Descente * descente = new Descente(splitInfoDescente.at(0) + "\nà " + splitInfoDescente[1].replace(":", "h"), splitInfoDescente.at(2), splitInfoDescente.at(3).toDouble());

                    // Copies de la descente dans le l'attribut QList
                        mesDescentes.append(descente);

                }

            // Emission du signal listeChanged, pour prevenir la vue d'un changement
                emit listeChanged();

            qDebug() << "/!\\ Succès de l'initialisation des descentes de l'utilisateur !";

            return true;

        } else
            return false;

}


/**
 * @brief VisualiserTempsVitesse::initStatistiques
 * @param statistiques
 * @return
 * @desc: Méthode d'initialisation des statistiques de l'utilisateur courant
 * - Vérification que les statistiques sont bien celle de l'utilisateur courant
 * - Set des nouvelles statistiques au controller identification
 */
bool VisualiserTempsVitesse::initStatistiques(QVector<QString> *statistiques)
{
    // Vérification que les statistiques sont bien celle de l'utilisateur courant
        if(statistiques->at(0).toInt() == controllerIdentification.getIdUtilisateur()) {

            qDebug() << "...initialisation des statistiques de l'idUtilisateur: " << statistiques->at(0).toInt();

            // Set des nouvelles statistiques au controller identification
                if(controllerIdentification.setStatistiques(statistiques->at(1).toInt(), statistiques->at(2).toDouble(), statistiques->at(3).toDouble(), statistiques->at(4).toDouble(), statistiques->at(5), statistiques->at(6), statistiques->at(7))) {
                    qDebug() << "/!\\ Succès de l'initialisation des statistiques de l'utilisateur !";
                    return true;
                } else
                    return false;

        } else
            return false;
}

QString VisualiserTempsVitesse::getMesStatistiques(int maStat)
{
    switch (maStat) {
        case 1:
            return QString::number(controllerIdentification.getMesStatistiques()->getNmbrDescente());
        case 2:
            return QString::number(controllerIdentification.getMesStatistiques()->getVitesseMoye());
        case 3:
            return QString::number(controllerIdentification.getMesStatistiques()->getVitesseMin());
        case 4:
            return QString::number(controllerIdentification.getMesStatistiques()->getVitesseMax());
        case 5:
            return controllerIdentification.getMesStatistiques()->getTempsMoye();
        case 6:
            return controllerIdentification.getMesStatistiques()->getTempsMin();
        case 7:
            return controllerIdentification.getMesStatistiques()->getTempsMax();
    }
    return "ERREUR";
}

QString VisualiserTempsVitesse::getMonUtilisateur(int monUtilisateur)
{
    switch (monUtilisateur) {
        case 1:
            return controllerIdentification.getMonUtilisatateur()->getNom();
        case 2:
            return controllerIdentification.getMonUtilisatateur()->getPrenom();
        case 3:
            return QString::number(controllerIdentification.getMonUtilisatateur()->getAge());
        case 4:
            return controllerIdentification.getMonUtilisatateur()->getPseudo();
    }
    return "ERREUR";
}
