#ifndef DESCENTE_H
#define DESCENTE_H

#include <QObject>
#include <QDate>

class Descente : public QObject
{
    Q_OBJECT
    /*Q_PROPERTY(QDate date READ getDate)
    Q_PROPERTY(QString temps READ getTemps)
    Q_PROPERTY(double vitesse READ getVitesse)*/

public:

    // Constructeur
        explicit Descente(QDate date, QString temps, double vitesse);

    // Accesseurs
        QDate getDate() const           { return date; }
        QString getTemps() const        { return temps; }
        double getVitesse() const       { return vitesse; }

private:

    // Attributs
        QDate date;
        QString temps;
        double vitesse;

signals:

};

#endif // DESCENTE_H
