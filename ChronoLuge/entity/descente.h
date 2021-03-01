#ifndef DESCENTE_H
#define DESCENTE_H

/*
 * Inclusion des bibliothèques/classes
*/

#include <QObject>
#include <QDateTime>

/**
 * @brief The Descente class
 * @author: GONCALVES H
 * @desc: Méthode entité d'une descente
 */
class Descente : public QObject
{
    // Macro
        Q_OBJECT
        Q_PROPERTY(QString date READ getDate CONSTANT)
        Q_PROPERTY(QString temps READ getTemps CONSTANT)
        Q_PROPERTY(double vitesse READ getVitesse CONSTANT)

public:

    // Constructeurs - Desctructeur
        explicit Descente(QString date, QString temps, double vitesse)      : date(date), temps(temps), vitesse(vitesse) {}
        explicit Descente(QObject *parent = nullptr)                        : QObject(parent) {}
        ~Descente() {}

    // Accesseurs
        QString getDate() const             { return date; }
        QString getTemps() const            { return temps; }
        double getVitesse() const           { return vitesse; }

private:

    // Attributs
        QString date;
        QString temps;
        double vitesse;

};

#endif // DESCENTE_H
