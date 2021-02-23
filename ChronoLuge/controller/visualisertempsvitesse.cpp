#include "visualisertempsvitesse.h"

VisualiserTempsVitesse::VisualiserTempsVitesse(QObject *parent) :
    QObject(parent),
    communicationHTTP(new ComHTTP),
    monPresenter(new PresenterVisualiserTempsVitesse),
    controllerIdentification(new PresenterIdentification, communicationHTTP)
{
    this->monPresenter->setController(this);
    this->communicationHTTP->setControllerTempsVitesse(this);
}

VisualiserTempsVitesse::~VisualiserTempsVitesse()
{

}

bool VisualiserTempsVitesse::lierDescente(QString QRCode)
{
    // Récupération de l'idUtilisteur
        int idUtilisateur = controllerIdentification.getIdUtilisateur();

    // Envoi demande recherche descentes
        communicationHTTP->lierDescente(idUtilisateur, QRCode);

        return true;
}

bool VisualiserTempsVitesse::rechercherDescentes()
{
    // Récupération de l'idUtilisteur
        int idUtilisateur = controllerIdentification.getIdUtilisateur();

    // Envoi demande recherche descentes
        communicationHTTP->rechercherDescentes(idUtilisateur);

        return true;
}

bool VisualiserTempsVitesse::rechercherStatistiques()
{
    // Récupération de l'idUtilisteur
        int idUtilisateur = controllerIdentification.getIdUtilisateur();

    // Envoi demande recherche descentes
        communicationHTTP->rechercherStatistiques(idUtilisateur);

        return true;
}

bool VisualiserTempsVitesse::initDescentes(QVector<QString> *descentes)
{

    if(descentes->at(0).toInt() == controllerIdentification.getIdUtilisateur()) {

        qDebug() << "Initialisation des descentes de l'idUtilisateur: " << descentes->at(0).toInt();
        mesDescentes.clear();

        for(int i = 1 ; i < descentes->count() ; i++) {

            QStringList splitInfoDescente = descentes->at(i).split(" ");

            //qDebug() << splitInfoDescente.at(0) << " " << splitInfoDescente.at(1) << " " << splitInfoDescente.at(2) << " " << splitInfoDescente.at(3);

            Descente * descente = new Descente(splitInfoDescente.at(0) + " " + splitInfoDescente.at(1), splitInfoDescente.at(2), splitInfoDescente.at(3).toDouble());
            mesDescentes.append(descente);

            /*qDebug() << mesDescentes.at(i-1)->getDate();
            qDebug() << mesDescentes.at(i-1)->getTemps();
            qDebug() << mesDescentes.at(i-1)->getVitesse();*/

        }

        listeChanged();

        return true;

    } else
        return false;
}

bool VisualiserTempsVitesse::initStatistiques(QVector<QString> *statistiques)
{
    if(statistiques->at(0).toInt() == controllerIdentification.getIdUtilisateur()) {

        qDebug() << "Initialisation des statistiques de l'idUtilisateur: " << statistiques->at(0).toInt();

        //controllerIdentification.setStatistiques(statistiques->at(1).toInt(), statistiques->at(2).toDouble(), statistiques->at(3).toDouble(), statistiques->at(4).toDouble(), statistiques->at(5), statistiques->at(6), statistiques->at(7));

        return true;

    } else
        return false;
}
