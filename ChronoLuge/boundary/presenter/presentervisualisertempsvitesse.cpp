#include "presentervisualisertempsvitesse.h"
#include "controller/visualisertempsvitesse.h"

PresenterVisualiserTempsVitesse::PresenterVisualiserTempsVitesse(QObject *parent) : QObject(parent), monController(nullptr)
{

}

bool PresenterVisualiserTempsVitesse::lierDescente(QString QRCode)
{
    if(monController->lierDescente(QRCode))
        return true;
    return false;
}
