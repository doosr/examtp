#ifndef GERER_VOIE_SORTIE_H
#define GERER_VOIE_SORTIE_H

#include <Arduino.h>
#include "ConfigGererVoieSortie.h"

// Définition des états possibles de la FSM
enum Etat {
    VEILLE,
    ATTENTE_ACTION,
    OUVERTURE,
    FERMETURE,
    ALERTE_INACTIVITE,
    ALERTE_NON_DETECTE
};

// Classe pour gérer la voie de sortie
class IRAM_ATTR GererVoieSortie {
private:
    volatile Etat etatActuel;  // État actuel
    volatile bool DE;          // Détecteur d'entrée
    volatile bool BO;          // Bouton d'ouverture
    volatile bool DS;          // Détecteur de sortie
    volatile int timer;        // Timer pour gérer les délais

    // Méthodes privées
    void IRAM_ATTR afficherEtat(); // Afficher l'état actuel

public:
    // Constructeur
    GererVoieSortie();

    // Méthodes publiques
    void IRAM_ATTR mettreAJourEntrees(bool de, bool bo, bool ds);
    void IRAM_ATTR transitionEtat();
    void IRAM_ATTR afficherSorties(); // Affiche les sorties (feux et barrière)
};

#endif // GERER_VOIE_SORTIE_H
