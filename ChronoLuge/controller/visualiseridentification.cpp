#include "visualiseridentification.h"

VisualiserIdentification::VisualiserIdentification(PresenterIdentification *monPresenter, ComHTTP *communicationHTTP, QObject *parent) :
    QObject(parent),
    monPresenter(monPresenter),
    monUtilisateur(nullptr),
    communicationHTTP(communicationHTTP)
{
    this->monPresenter->setController(this);
    this->communicationHTTP->setControllerIdentification(this);
}
