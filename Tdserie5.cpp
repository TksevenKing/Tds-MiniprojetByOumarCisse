// ---------------------------- EXO 8 ---------------------------------------

//#include <stdio.h>
//
//int compte_c(FILE *fichier) {
//    int count = 0;
//    int caractere;
//
//    while ((caractere = fgetc(fichier)) != EOF) {
//        count++;
//    }
//
//    return count;
//}
//
//int compte_mots(FILE *fichier) {
//    int count = 0;
//    int caractere;
//    int estDansMot = 0; // Indicateur pour savoir si nous sommes à l'intérieur d'un mot
//
//    while ((caractere = fgetc(fichier)) != EOF) {
//        if (caractere == ' ' || caractere == '\n' || caractere == '\t') {
//            if (estDansMot) {
//                count++;
//                estDansMot = 0; // On indique que nous sommes en dehors d'un mot
//            }
//        } else {
//            estDansMot = 1; // On indique que nous sommes à l'intérieur d'un mot
//        }
//    }
//
//    if (estDansMot) {
//        count++; // Compter le dernier mot s'il n'est pas suivi d'un espace ou d'un retour à la ligne
//    }
//
//    return count;
//}
//
//int compte_lignes(FILE *fichier) {
//    int count = 0;
//    int caractere;
//
//    while ((caractere = fgetc(fichier)) != EOF) {
//        if (caractere == '\n') {
//            count++;
//        }
//    }
//
//    return count;
//}
//
//int main() {
//    FILE *fichier = fopen("exemple.txt", "r"); // Remplacez "exemple.txt" par le nom de votre fichier
//
//    if (fichier == NULL) {
//        printf("Erreur lors de l'ouverture du fichier.\n");
//        return 1;
//    }
//
//    printf("Nombre de caractères : %d\n", compte_c(fichier));
//
//    fseek(fichier, 0, SEEK_SET); // Réinitialise le curseur du fichier
//
//    printf("Nombre de mots : %d\n", compte_mots(fichier));
//
//    fseek(fichier, 0, SEEK_SET);
//
//    printf("Nombre de lignes : %d\n", compte_lignes(fichier));
//
//    fclose(fichier);
//    return 0;
//}


// ----------------------------------EXO 9 ----------------------------------------

//#include <stdio.h>
//#include <stdlib.h>
//
//void trierEtEcrireDansFichier(FILE *fichier) {
//    int tableau[10];
//
//    // Lecture des valeurs du fichier dans le tableau
//    for (int i = 0; i < 10; i++) {
//        fscanf(fichier, "%d", &tableau[i]);
//    }
//
//    // Tri du tableau en ordre croissant
//    for (int i = 0; i < 10 - 1; i++) {
//        for (int j = 0; j < 10 - i - 1; j++) {
//            if (tableau[j] > tableau[j + 1]) {
//                // Échange des éléments
//                int temp = tableau[j];
//                tableau[j] = tableau[j + 1];
//                tableau[j + 1] = temp;
//            }
//        }
//    }
//
//    // Écriture du tableau trié dans le fichier
//    fseek(fichier, 0, SEEK_SET);
//    for (int i = 0; i < 10; i++) {
//        fprintf(fichier, "%d ", tableau[i]);
//    }
//}
//
//int main() {
//    FILE *fichier = fopen("valeurs.txt", "r+"); // Remplacez "valeurs.txt" par le nom de votre fichier
//
//    if (fichier == NULL) {
//        printf("Erreur lors de l'ouverture du fichier.\n");
//        return 1;
//    }
//
//    trierEtEcrireDansFichier(fichier);
//
//    fclose(fichier);
//    return 0;
//}

//----------------------------------EXO 10 -------------------------------------------

//#include <stdio.h>
//
//int main() {
//    FILE *fichier = fopen("c:\\fichier.data", "r"); // Remplacez "c:\\fichier.data" par le nom de votre fichier
//
//    if (fichier == NULL) {
//        printf("Erreur lors de l'ouverture du fichier.\n");
//        return 1;
//    }
//
//    char nom[20];
//    char article[20];
//    int nombre;
//    float prix;
//
//    while (fscanf(fichier, "%s %s %d %f", nom, article, &nombre, &prix) != EOF) {
//        printf("Nom: %s, Article: %s, Nombre: %d, Prix: %.2f\n", nom, article, nombre, prix);
//    }
//
//    fclose(fichier);
//    return 0;
//}

// --------------------------------EXO 11 ------------------------------------------

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//    char nom[20];
//    char article[20];
//    int nombre;
//    float prix;
//} TypeArticle;
//
//int main() {
//    FILE *fichier = fopen("c:\\fichier.data", "r"); // Remplacez "c:\\fichier.data" par le nom de votre fichier
//
//    if (fichier == NULL) {
//        printf("Erreur lors de l'ouverture du fichier.\n");
//        return 1;
//    }
//
//    TypeArticle tableau[100]; // Vous pouvez ajuster la taille du tableau en fonction du nombre d'articles dans le fichier
//
//    int i = 0;
//
//    while (fscanf(fichier, "%s %s %d %f", tableau[i].nom, tableau[i].article, &tableau[i].nombre, &tableau[i].prix) != EOF) {
//        i++;
//    }
//
//    fclose(fichier);
//
//    for (int j = 0; j < i; j++) {
//        printf("Nom: %s, Article: %s, Nombre: %d, Prix: %.2f\n", tableau[j].nom, tableau[j].article, tableau[j].nombre, tableau[j].prix);
//    }
//
//    return 0;
//}

// --------------------------------EXO 12 -----------------------------------------

//#include <stdio.h>
//
//typedef struct {
//    int numero;
//    char nom[20];
//    float prixHT;
//    int qte;
//} TYPEART;
//
//int main() {
//    FILE *farticle = fopen("articles.data", "w");
//
//    if (farticle == NULL) {
//        printf("Erreur lors de l'ouverture du fichier.\n");
//        return 1;
//    }
//
//    // Remplissage du fichier avec des données de votre choix
//    TYPEART article1 = {1, "Crayon", 0.5, 100};
//    TYPEART article2 = {2, "Cahier", 2.5, 50};
//    TYPEART article3 = {3, "Stylo", 1.0, 80};
//
//    fprintf(farticle, "%d %s %.2f %d\n", article1.numero, article1.nom, article1.prixHT, article1.qte);
//    fprintf(farticle, "%d %s %.2f %d\n", article2.numero, article2.nom,
//
//    fclose(farticle);
//    return 0;
//}


// -------------------------------EXO 13 -----------------------------------
//#include <stdio.h>
//
//void createG(char* fileF1, char* fileF2, char* fileG);
//void generateH(char* fileG, char* fileH);
//
//int main() {
//    char fileF1[] = "F1.txt";
//    char fileF2[] = "F2.txt";
//    char fileG[] = "G.txt";
//    char fileH[] = "H.txt";
//
//    createG(fileF1, fileF2, fileG);
//    generateH(fileG, fileH);
//
//    return 0;
//}
//
//void createG(char* fileF1, char* fileF2, char* fileG) {
//    FILE* f1 = fopen(fileF1, "r");
//    FILE* f2 = fopen(fileF2, "r");
//    FILE* g = fopen(fileG, "w");
//
//    if (f1 == NULL || f2 == NULL || g == NULL) {
//        perror("Erreur lors de l'ouverture des fichiers");
//        return;
//    }
//
//    int valueF1, valueF2;
//
//    while (fscanf(f1, "%d", &valueF1) == 1) {
//        rewind(f2);
//
//        while (fscanf(f2, "%d", &valueF2) == 1) {
//            if (valueF2 % valueF1 == 0) {
//                fprintf(g, "%d ", valueF2);
//            }
//        }
//    }
//
//    fclose(f1);
//    fclose(f2);
//    fclose(g);
//}
//
//void generateH(char* fileG, char* fileH) {
//    FILE* g = fopen(fileG, "r");
//    FILE* h = fopen(fileH, "w");
//
//    if (g == NULL || h == NULL) {
//        perror("Erreur lors de l'ouverture des fichiers");
//        return;
//    }
//
//    int currentValue, previousValue = 0;
//    int count = 0;
//
//    while (fscanf(g, "%d", &currentValue) == 1) {
//        if (currentValue != previousValue) {
//            if (count > 0) {
//                fprintf(h, "%d %d\n", previousValue, count);
//            }
//
//            count = 1;
//            previousValue = currentValue;
//        } else {
//            count++;
//        }
//    }
//
//    // Traitement du dernier élément
//    if (count > 0) {
//        fprintf(h, "%d %d\n", previousValue, count);
//    }
//
//    fclose(g);
//    fclose(h);
//}


//------------------------------------- EXO 14 ------------------------------------

//#include <stdio.h>
//
//void createG(char* fileF, char* fileG);
//void removeZeros(char* fileG);
//
//int main() {
//    char fileF[] = "F.txt";
//    char fileG[] = "G.txt";
//
//    createG(fileF, fileG);
//    removeZeros(fileG);
//
//    return 0;
//}
//
//void createG(char* fileF, char* fileG) {
//    FILE* f = fopen(fileF, "r");
//    FILE* g = fopen(fileG, "w");
//
//    if (f == NULL || g == NULL) {
//        perror("Erreur lors de l'ouverture des fichiers");
//        return;
//    }
//
//    int value, sum, count;
//
//    while (fscanf(f, "%d", &value) == 1) {
//        if (value != 0) {
//            sum = count = value;
//            while (fscanf(f, "%d", &value) == 1 && value != 0) {
//                sum += value;
//                count++;
//            }
//
//            fprintf(g, "%.2f\n", (float)sum / count);
//        }
//    }
//
//    fclose(f);
//    fclose(g);
//}
//
//void removeZeros(char* fileG) {
//    FILE* g = fopen(fileG, "r");
//
//    if (g == NULL) {
//        perror("Erreur lors de l'ouverture du fichier");
//        return;
//    }
//
//    FILE* temp = fopen("temp.txt", "w");
//
//    if (temp == NULL) {
//        perror("Erreur lors de la création du fichier temporaire");
//        fclose(g);
//        return;
//    }
//
//    int value;
//    while (fscanf(g, "%d", &value) == 1) {
//        if (value != 0) {
//            fprintf(temp, "%d\n", value);
//        }
//    }
//
//    fclose(g);
//    fclose(temp);
//
//    remove(fileG);
//    rename("temp.txt", fileG);
//}

//------------------------------------- FIN --------------------------------------------//