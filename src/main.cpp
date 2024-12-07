#include "GererVoieSortie.h"

GererVoieSortie voieSortie;

// Interrupt Service Routines
void IRAM_ATTR detecteurEntreeISR() {
    voieSortie.mettreAJourEntrees(true, digitalRead(BOUTON_OUVERTURE), digitalRead(DETECTEUR_SORTIE));
}

void IRAM_ATTR boutonOuvertureISR() {
    voieSortie.mettreAJourEntrees(digitalRead(DETECTEUR_ENTREE), true, digitalRead(DETECTEUR_SORTIE));
}

void setup() {
    Serial.begin(9600);
    pinMode(DETECTEUR_ENTREE, INPUT_PULLUP);
    pinMode(BOUTON_OUVERTURE, INPUT_PULLUP);
    pinMode(DETECTEUR_SORTIE, INPUT_PULLUP);

    pinMode(BARRIERE, OUTPUT);
    pinMode(FEU_ROUGE, OUTPUT);
    pinMode(FEU_ORANGE, OUTPUT);
    pinMode(FEU_VERT, OUTPUT);

    // Attach interrupts
    attachInterrupt(digitalPinToInterrupt(DETECTEUR_ENTREE), detecteurEntreeISR, RISING);
    attachInterrupt(digitalPinToInterrupt(BOUTON_OUVERTURE), boutonOuvertureISR, RISING);
}

void loop() {
    voieSortie.transitionEtat();
    voieSortie.afficherSorties();
    delay(1000); // Simulate timer increment
}
