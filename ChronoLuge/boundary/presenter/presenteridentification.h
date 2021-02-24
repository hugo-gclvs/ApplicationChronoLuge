#ifndef PRESENTERIDENTIFICATION_H
#define PRESENTERIDENTIFICATION_H

#include <QObject>
#include <QDebug>

class VisualiserIdentification;

class PresenterIdentification : public QObject
{
    Q_OBJECT
public:

    explicit PresenterIdentification(QObject *parent = nullptr);
    ~PresenterIdentification();

    Q_INVOKABLE void creerCompte(QString pseudo, QString mdp, QString mail, QString nom, QString prenom, QString age);
    Q_INVOKABLE void rechercherCompte(QString pseudo, QString mdp);
    Q_INVOKABLE VisualiserIdentification *getMonController() const              { return monController; }

    void setController(VisualiserIdentification *monController)     { this->monController = monController; }

private:
    VisualiserIdentification *monController;

signals:

};

#endif // PRESENTERIDENTIFICATION_H
