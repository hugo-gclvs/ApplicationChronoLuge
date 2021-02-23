#ifndef DESCENTE_H
#define DESCENTE_H

#include <QObject>
#include <QDateTime>

class Descente : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString date READ getDate CONSTANT)
    Q_PROPERTY(QString temps READ getTemps CONSTANT)
    Q_PROPERTY(double vitesse READ getVitesse CONSTANT)

public:

    // Constructeur
        explicit Descente(QString date, QString temps, double vitesse);
        explicit Descente(QObject *parent = nullptr) : QObject(parent) {}
        ~Descente();

    // Accesseurs
        QString getDate() const           { return date; }
        QString getTemps() const        { return temps; }
        double getVitesse() const       { return vitesse; }

private:

    // Attributs
        QString date;
        QString temps;
        double vitesse;

signals:

};

#endif // DESCENTE_H
