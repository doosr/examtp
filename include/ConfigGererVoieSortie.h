// ConfigGererVoieSortie.h

#ifndef CONFIG_GERER_VOIE_SORTIE_H
#define CONFIG_GERER_VOIE_SORTIE_H

// Définitions des entrées
#define DETECTEUR_ENTREE    34  // Détecteur d'entrée (DE)
#define BOUTON_OUVERTURE    35  // Bouton d'ouverture (BO)
#define DETECTEUR_SORTIE    32  // Détecteur de sortie (DS)

// Définitions des sorties
#define BARRIERE            23  // Barrière (ouverte/fermée)
#define FEU_ROUGE           5   // Feu rouge
#define FEU_ORANGE          21  // Feu orange
#define FEU_VERT            22  // Feu vert

// Fréquences et délais
#define FREQUENCE_CLIGNOTEMENT_HZ 10 // Clignotement des feux (10 Hz)
#define TEMPS_INACTIVITE_SECONDES 20 // Temps avant l'alerte d'inactivité
#define TEMPS_FERMETURE_SECONDES   1  // Temps pour fermer la barrière

#endif // CONFIG_GERER_VOIE_SORTIE_H
