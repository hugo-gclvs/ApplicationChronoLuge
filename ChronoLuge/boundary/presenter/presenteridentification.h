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

    Q_INVOKABLE void afficherMessage(const QString &msg) {
        qDebug() << msg;
    }

    void setController(VisualiserIdentification *monController) { this->monController = monController; }

private:
    VisualiserIdentification *monController;

signals:

};

#endif // PRESENTERIDENTIFICATION_H
