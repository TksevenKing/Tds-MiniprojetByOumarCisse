#include<stdio.h>
#include<string.h>
#include"header.h"

// --------------------------EXO 1 ------------------------------------------


//int main() {
//    char *nom;
//    int taille = 30;
//
//    // Allocation dynamique de la chaîne de caractères
//    nom = (char *)malloc(taille * sizeof(char));
//
//    if (nom == NULL) {
//        fprintf(stderr, "Erreur d'allocation de mémoire");
//        return 1;
//    }
//
//    // Saisie du nom
//    printf("Entrez un nom : ");
//    scanf("%s", nom);
//
//    // Inversion des caractères avec des pointeurs
//    char *debut = nom;
//    char *fin = nom + strlen(nom) - 1;
//
//    while (debut < fin) {
//        // Échange des caractères
//        char temp = *debut;
//        *debut = *fin;
//        *fin = temp;
//
//        // Déplacement des pointeurs
//        debut++;
//        fin--;
//    }
//
//    // Affichage du nom inversé
//    printf("Nom inversé : %s\n", nom);
//
//    // Libération de la mémoire allouée
//    free(nom);
//
//    return 0;
//}


//----------------------------------- EXO 2 -----------------------------------------------

//
//int estPalindrome(char *mot) {
//    char *debut = mot;
//    char *fin = mot + strlen(mot) - 1;
//
//    while (debut < fin) {
//        if (*debut != *fin) {
//            return 0; // Le mot n'est pas un palindrome
//        }
//
//        debut++;
//        fin--;
//    }
//
//    return 1; // Le mot est un palindrome
//}
//
//int main() {
//    char *mot;
//    int taille = 30;
//
//    // Allocation dynamique de la chaîne de caractères
//    mot = (char *)malloc(taille * sizeof(char));
//
//    if (mot == NULL) {
//        fprintf(stderr, "Erreur d'allocation de mémoire");
//        return 1;
//    }
//
//    // Saisie du mot
//    printf("Entrez un mot : ");
//    scanf("%s", mot);
//
//    // Vérification si le mot est un palindrome
//    if (estPalindrome(mot)) {
//        printf("%s est un palindrome.\n", mot);
//    } else {
//        printf("%s n'est pas un palindrome.\n", mot);
//    }
//
//    // Libération de la mémoire allouée
//    free(mot);
//
//    return 0;
//}

// ----------------------------------- EXO 3 ----------------------------------------


//int main() {
//    float T[3][4];
//    float somme = 0;
//
//    // Calcul de la somme en utilisant le formalisme usuel des tableaux à deux indices
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 4; j++) {
//            somme += T[i][j];
//        }
//    }
//
//    printf("Somme des éléments du tableau : %f\n", somme);
//    
//    // Calcul de la somme en utilisant le formalisme pointeur
//    float *ptr = &T[0][0];
//
//    for (int i = 0; i < 3 * 4; i++) {
//        somme += *(ptr + i);
//    }
//
//    printf("Somme des éléments du tableau : %f\n", somme);
//    
//    return 0;
//}

// ----------------------------------- EXO 4 ----------------------------------------

//int main() {
//    int b[3][5];
//    int *a = *b, i;
//
//    // Initialisation du tableau
//    for (i = 0; i < 15; *a++ = i++);
//
//    // Modification des éléments du tableau
//    **b = 15;
//    *(*(b + 1)) = 16;
//    *(b[0] + 1) = 17;
//    *(*b + 8) = 18;
//    *(b[1] + 2) = 19;
//    *(*(b + 1) + 5) = 20;
//    *(b[2] + 3) = 21;
//    *(*(b + 2) + 2); // Cette instruction ne fait rien, elle manque d'une opération comme une affectation
//
//    // Affichage du tableau
//    for (int row = 0; row < 3; row++) {
//        for (int col = 0; col < 5; col++) {
//            printf("%d ", b[row][col]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}


// -------------------------------- EXO 5 --------------------------------------


//
//int frequenceMot(char *phrase, char *mot) {
//    int freq = 0;
//    char *ptr = phrase;
//
//    while ((ptr = strstr(ptr, mot)) != NULL) {
//        freq++;
//        ptr++;
//    }
//
//    return freq;
//}
//
//int main() {
//    char phrase[100], mot[20];
//
//    // Saisie de la phrase et du mot
//    printf("Entrez une phrase : ");
//    gets(phrase);
//
//    printf("Entrez un mot : ");
//    scanf("%s", mot);
//
//    // Calcul de la fréquence d'occurrence du mot dans la phrase
//    int resultat = frequenceMot(phrase, mot);
//
//    // Affichage du résultat
//    printf("La fréquence d'occurrence du mot \"%s\" dans la phrase est : %d\n", mot, resultat);
//
//    return 0;
//}

// -------------------------------EXO 6 ------------------------------------------

//
//
//void traitementPhrase(char *phrase) {
//    // Suppression des blancs au début de la phrase
//    while (*phrase == ' ') {
//        strcpy(phrase, phrase + 1);
//    }
//
//    // Correction des espaces entre les mots
//    char *ptr = phrase;
//
//    while (*ptr != '\0') {
//        if (*ptr == ' ' && *(ptr + 1) == ' ') {
//            strcpy(ptr, ptr + 1);
//        } else {
//            ptr++;
//        }
//    }
//}
//
//int main() {
//    char phrase[100];
//
//    // Saisie de la phrase
//    printf("Entrez une phrase : ");
//    gets(phrase);
//
//    // Traitement de la phrase
//    traitementPhrase(phrase);
//
//    // Affichage du résultat
//    printf("Phrase traitée : %s\n", phrase);
//
//    return 0;
//}

//----------------------------------EXO 7 -------------------------------------



//int search(float tableau[], int taille, float valeur) {
//    for (int i = 0; i < taille; i++) {
//        if (tableau[i] == valeur) {
//            return i; // Retourne la position si la valeur est trouvée
//        }
//    }
//
//    return -1; // Retourne -1 si la valeur n'est pas présente dans le tableau
//}
//
//int main() {
//    int taille;
//    
//    // Saisie de la taille du tableau
//    printf("Entrez la taille du tableau : ");
//    scanf("%d", &taille);
//
//    if (taille <= 0) {
//        fprintf(stderr, "La taille du tableau doit être supérieure à zéro.\n");
//        return 1;
//    }
//
//    // Allocation dynamique du tableau
//    float *tableau = (float *)malloc(taille * sizeof(float));
//
//    if (tableau == NULL) {
//        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
//        return 1;
//    }
//
//    // Saisie des valeurs du tableau
//    printf("Entrez les valeurs du tableau :\n");
//    for (int i = 0; i < taille; i++) {
//        printf("Valeur %d : ", i + 1);
//        scanf("%f", &tableau[i]);
//    }
//
//    // Saisie de la valeur à rechercher
//    float valeurRecherchee;
//    printf("Entrez la valeur à rechercher : ");
//    scanf("%f", &valeurRecherchee);
//
//    // Appel de la fonction search et affichage du résultat
//    int position = search(tableau, taille, valeurRecherchee);
//
//    if (position != -1) {
//        printf("La valeur %f a été trouvée à la position %d du tableau.\n", valeurRecherchee, position);
//    } else {
//        printf("La valeur %f n'a pas été trouvée dans le tableau.\n", valeurRecherchee);
//    }
//
//    // Libération de la mémoire allouée pour le tableau
//    free(tableau);
//
//    return 0;
//}

//----------------------------------------EXO 8 ---------------------------------------



//void compressRLE(int *tableau, int taille) {
//    int i = 0;
//
//    while (i < taille) {
//        int count = 1;
//
//        // Compter le nombre d'occurrences de la valeur actuelle
//        while (i < taille - 1 && tableau[i] == tableau[i + 1]) {
//            count++;
//            i++;
//        }
//
//        // Afficher le nombre d'occurrences suivi de la valeur
//        printf("%d%d", count, tableau[i]);
//
//        i++;
//    }
//}
//
//int main() {
//    // Exemple d'utilisation
//    int tableau[] = {4, 4, 4, 4, 4, 3, 3, 3, 2, 2, 1, 1, 0};
//    int taille = sizeof(tableau) / sizeof(tableau[0]);
//
//    printf("Tableau original : ");
//    for (int i = 0; i < taille; i++) {
//        printf("%d ", tableau[i]);
//    }
//
//    printf("\nTableau compressé : ");
//    compressRLE(tableau, taille);
//
//    return 0;
//}

// --------------------------------------- FIN -----------------------------------------//
