#ifndef PRESENTERVISUALISERTEMPSVITESSE_H
#define PRESENTERVISUALISERTEMPSVITESSE_H

#include <QObject>

class VisualiserTempsVitesse;

class PresenterVisualiserTempsVitesse : public QObject
{
    Q_OBJECT

public:
    explicit PresenterVisualiserTempsVitesse(QObject *parent = nullptr);

    void setController(VisualiserTempsVitesse *monController) { this->monController = monController; }

    bool lierDescente();
    bool rechercherHistorique();
    bool rechercherStatistiques();

private:
    VisualiserTempsVitesse *monController;

signals:

};

#endif // PRESENTERVISUALISERTEMPSVITESSE_H
