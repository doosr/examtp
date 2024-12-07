#include "GererVoieSortie.h"

// Constructeur
GererVoieSortie::GererVoieSortie() : etatActuel(VEILLE), DE(false), BO(false), DS(false), timer(0) {}

// Mettre à jour les entrées
void IRAM_ATTR GererVoieSortie::mettreAJourEntrees(bool de, bool bo, bool ds) {
    DE = de;
    BO = bo;
    DS = ds;
}

// Afficher l'état actuel
void IRAM_ATTR GererVoieSortie::afficherEtat() {
    switch (etatActuel) {
        case VEILLE:
            Serial.println("État : VEILLE");
            break;
        case ATTENTE_ACTION:
            Serial.println("État : ATTENTE_ACTION");
            break;
        case OUVERTURE:
            Serial.println("État : OUVERTURE");
            break;
        case FERMETURE:
            Serial.println("État : FERMETURE");
            break;
        case ALERTE_INACTIVITE:
            Serial.println("État : ALERTE_INACTIVITE");
            break;
        case ALERTE_NON_DETECTE:
            Serial.println("État : ALERTE_NON_DETECTE");
            break;
    }
}

// Transition entre les états
void IRAM_ATTR GererVoieSortie::transitionEtat() {
    switch (etatActuel) {
        case VEILLE:
            if (DE) etatActuel = ATTENTE_ACTION;
            break;

        case ATTENTE_ACTION:
            if (BO) etatActuel = OUVERTURE;
            else if (timer >= TEMPS_INACTIVITE_SECONDES) etatActuel = ALERTE_INACTIVITE;
            break;

        case OUVERTURE:
            if (DS) etatActuel = FERMETURE;
            else if (timer >= TEMPS_INACTIVITE_SECONDES) etatActuel = ALERTE_NON_DETECTE;
            break;

        case FERMETURE:
            etatActuel = VEILLE;
            break;

        case ALERTE_INACTIVITE:
        case ALERTE_NON_DETECTE:
            etatActuel = VEILLE;
            break;
    }
    afficherEtat();
}

// Afficher les sorties (feux et barrière)
void IRAM_ATTR GererVoieSortie::afficherSorties() {
    switch (etatActuel) {
        case VEILLE:
            digitalWrite(FEU_ROUGE, HIGH);
            digitalWrite(FEU_ORANGE, LOW);
            digitalWrite(FEU_VERT, LOW);
            digitalWrite(BARRIERE, LOW);
            break;

        case ATTENTE_ACTION:
            digitalWrite(FEU_ROUGE, LOW);
            digitalWrite(FEU_ORANGE, HIGH);
            digitalWrite(FEU_VERT, LOW);
            digitalWrite(BARRIERE, LOW);
            break;

        case OUVERTURE:
            digitalWrite(FEU_ROUGE, LOW);
            digitalWrite(FEU_ORANGE, LOW);
            digitalWrite(FEU_VERT, HIGH);
            digitalWrite(BARRIERE, HIGH);
            break;

        case FERMETURE:
            digitalWrite(FEU_ROUGE, HIGH);
            digitalWrite(FEU_ORANGE, LOW);
            digitalWrite(FEU_VERT, LOW);
            digitalWrite(BARRIERE, LOW);
            break;

        case ALERTE_INACTIVITE:
        case ALERTE_NON_DETECTE:
            digitalWrite(FEU_ORANGE, HIGH); // Simulate clignotement
            break;
    }
}
