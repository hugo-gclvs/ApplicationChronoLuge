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

bool VisualiserTempsVitesse::rechercherDescentes()
{
    // Récupération de l'idUtilisteur
        int idUtilisateur = controllerIdentification.getIdUtilisateur();

    // Envoi demande recherche descentes
        communicationHTTP->rechercherDescentes(idUtilisateur);

        return true;
}

bool VisualiserTempsVitesse::initDescentes(QVector<QString> *descentes)
{

    if(descentes->at(0).toInt() == controllerIdentification.getIdUtilisateur()) {

        qDebug() << "Init Descentes utilisateur: " << descentes->at(0);
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

        return true;

    } else
        return false;
}
