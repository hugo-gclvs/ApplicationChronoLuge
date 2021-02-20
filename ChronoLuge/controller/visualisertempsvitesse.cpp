#include "visualisertempsvitesse.h"

VisualiserTempsVitesse::VisualiserTempsVitesse(PresenterVisualiserTempsVitesse *monPresenter, QObject *parent) :
    QObject(parent),
    monPresenter(monPresenter)
{
    this->monPresenter->setController(this);
}

VisualiserTempsVitesse::~VisualiserTempsVitesse()
{

}
