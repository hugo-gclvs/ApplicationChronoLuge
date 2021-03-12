#ifndef STATISTIQUES_H
#define STATISTIQUES_H

/*
 * Inclusion des bibliothèques/classes
*/

#include <QObject>

/**
 * @brief The Statistiques class
 * @author: GONCALVES H
 * @desc: Méthode entité des statistiques
 */
class Statistiques : public QObject
{
    // Macro
        Q_OBJECT
        Q_PROPERTY(int nmbrDescente READ getNmbrDescente)
        Q_PROPERTY(double vitesseMoye READ getVitesseMoye)
        Q_PROPERTY(double vitesseMin READ getVitesseMin)
        Q_PROPERTY(double vitesseMax READ getVitesseMax)
        Q_PROPERTY(QString tempsMoye READ getTempsMoye)
        Q_PROPERTY(QString tempsMin READ getTempsMin)
        Q_PROPERTY(QString tempsMax READ getTempsMax)

public:

    // Constructeur - Destructeur
        explicit Statistiques(int nmbrDescente, double vitesseMoye, double vitesseMin, double vitesseMax, QString tempsMoye, QString tempsMin, QString tempsMax);
        ~Statistiques() override {}

    // Accesseurs
        int getNmbrDescente() const             { return nmbrDescente;  }
        double getVitesseMoye() const           { return vitesseMoye;   }
        double getVitesseMin() const            { return vitesseMin;    }
        double getVitesseMax() const            { return vitesseMax;    }
        QString getTempsMoye() const            { return tempsMoye;     }
        QString getTempsMin() const             { return tempsMin;      }
        QString getTempsMax() const             { return tempsMax;      }

private:

    // Attributs
        int nmbrDescente;
        double vitesseMoye;
        double vitesseMin;
        double vitesseMax;
        QString tempsMoye;
        QString tempsMin;
        QString tempsMax;

};

#endif // STATISTIQUES_H
