#include "statistiques.h"

/**
 * @brief Statistiques::Statistiques
 * @param nmbrDescente
 * @param vitesseMoye
 * @param vitesseMin
 * @param vitesseMax
 * @param tempsMoye
 * @param tempsMin
 * @param tempsMax
 * - Initialisation des différents attributs
 */
Statistiques::Statistiques(int nmbrDescente, double vitesseMoye, double vitesseMin, double vitesseMax, QString tempsMoye, QString tempsMin, QString tempsMax) :
    nmbrDescente(nmbrDescente),
    vitesseMoye(vitesseMoye),
    vitesseMin(vitesseMin),
    vitesseMax(vitesseMax),
    tempsMoye(tempsMoye),
    tempsMin(tempsMin),
    tempsMax(tempsMax)
{
}

