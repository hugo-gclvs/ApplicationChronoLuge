#ifndef VISUALISERTEMPSVITESSE_H
#define VISUALISERTEMPSVITESSE_H

/*
 * Inclusion des bibliothèques/classes
*/

#include <QObject>
#include <QtQml/QQmlListProperty>
#include <QVector>
#include "entity/descente.h"
#include "boundary/presenter/presentervisualisertempsvitesse.h"
#include "boundary/data/ComHTTP/comhttp.h"
#include "controller/visualiseridentification.h"

/**
 * @brief The VisualiserTempsVitesse class
 * @author: GONCALVES H
 * @desc: Classe de liaison entre les presenterVisualiserTempsVitesse, le controller VisualiserIdentification et les classes de communication (data)
 */
class VisualiserTempsVitesse : public QObject
{
    // Macro
        Q_OBJECT
        Q_PROPERTY(QQmlListProperty<Descente> liste READ getDescentes NOTIFY listeChanged)

public:

    // Constructeur - Destructeur
        explicit VisualiserTempsVitesse(QObject *parent = nullptr);
        ~VisualiserTempsVitesse() override {}

    // Méthodes
        bool lierDescente(QString QRCode);
        bool rechercherDescentes();
        bool rechercherStatistiques();
        bool majPP(int numPP);
        bool initDescentes(QVector<QString> *descentes);
        bool initStatistiques(QVector<QString> *statistiques);

        // Accesseurs
            QQmlListProperty<Descente> getDescentes()                                       { return QQmlListProperty<Descente>(this, mesDescentes); }
            PresenterVisualiserTempsVitesse *getPresenterVisualiserTempsVitesse()           { return monPresenter; }
            PresenterIdentification *getPresenterIdentification()                           { return controllerIdentification.getPresenterIdentification(); }
            QString getMesStatistiques(int maStat);
            QString getMonUtilisateur(int monUtilisateur);

        // Méthodes utilisable par l'UI
            Q_INVOKABLE QString getEtatConnexion()                                          { return controllerIdentification.getEtatConnexion()->value("etatConnexion").toString(); }
            Q_INVOKABLE QString getEtatInscription()                                        { return controllerIdentification.getEtatInscription()->value("etatInscription").toString(); }
            Q_INVOKABLE VisualiserIdentification *getControllerVisualiserIdentification()   { return &controllerIdentification; }

            void nouvellePP(QString image) { communicationHTTP->nouvellePP(image); }

private:

    // Attributs
        ComHTTP *communicationHTTP;                                 // Ma communication HTTP
        PresenterVisualiserTempsVitesse *monPresenter;              // Mon presenter
        VisualiserIdentification controllerIdentification;          // Mon controller identification
        QList<Descente *> mesDescentes;                             // Mes Descentes

signals:
        void listeChanged();                                            // Signal à émettre quand l'historique est actualisé
        void postLierDescente(const bool &etat);                        // Signal à émettre pour récuperer l'etat de validation d'un liaison
        void postNewPP(bool valeurReussite, QString valeurPdp);         // Signal à émettre pour récuperer l'etat de la nouvelle PP

};

#endif // VISUALISERTEMPSVITESSE_H
