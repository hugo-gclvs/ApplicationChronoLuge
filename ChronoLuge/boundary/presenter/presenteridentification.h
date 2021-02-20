#ifndef PRESENTERIDENTIFICATION_H
#define PRESENTERIDENTIFICATION_H

#include <QObject>
#include <QDebug>

class PresenterIdentification : public QObject
{
    Q_OBJECT
public:
    explicit PresenterIdentification(QObject *parent = nullptr);

    Q_INVOKABLE void afficherMessage(const QString &msg) {
        qDebug() << msg;
    }

signals:

};

#endif // PRESENTERIDENTIFICATION_H
