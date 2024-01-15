// -------------------------------EXO 1 ------------------------------------

//#include <stdio.h>
//
//typedef struct {
//    double real;
//    double imag;
//} complex;
//
//double imag(complex z) {
//    return z.imag;
//}
//
//double real(complex z) {
//    return z.real;
//}
//
//complex mul(complex z1, complex z2) {
//    complex result;
//    result.real = z1.real * z2.real - z1.imag * z2.imag;
//    result.imag = z1.real * z2.imag + z1.imag * z2.real;
//    return result;
//}
//
//int main() {
//    complex z1 = {2.0, 3.0};
//    complex z2 = {1.0, -1.0};
//
//    printf("Imaginaire de z1 : %lf\n", imag(z1));
//    printf("Réel de z2 : %lf\n", real(z2));
//
//    complex resultat = mul(z1, z2);
//    printf("Multiplication de z1 et z2 : %lf + %lfi\n", resultat.real, resultat.imag);
//
//    return 0;
//}

// -------------------------------EXO 2 ------------------------------------

//#include <stdio.h>
//
//struct date {
//    int jour;
//    char mois[10];
//    int annee;
//};
//
//struct employe {
//    char nom[15], prenom[15];
//    struct date date_naissance, date_embauche;
//};
//
//int main() {
//    struct employe employes[4];
//
//    // Saisie des informations pour 4 employés
//    for (int i = 0; i < 4; i++) {
//        printf("Entrez le nom de l'employé %d : ", i + 1);
//        scanf("%s", employes[i].nom);
//
//        printf("Entrez le prénom de l'employé %d : ", i + 1);
//        scanf("%s", employes[i].prenom);
//
//        printf("Entrez la date de naissance de l'employé %d (jj mois aaaa) : ", i + 1);
//        scanf("%d %s %d", &employes[i].date_naissance.jour, employes[i].date_naissance.mois, &employes[i].date_naissance.annee);
//
//        printf("Entrez la date d'embauche de l'employé %d (jj mois aaaa) : ", i + 1);
//        scanf("%d %s %d", &employes[i].date_embauche.jour, employes[i].date_embauche.mois, &employes[i].date_embauche.annee);
//    }
//
//    // Affichage des employés
//    for (int i = 0; i < 4; i++) {
//        printf("Nom : %s\n", employes[i].nom);
//        printf("Prénom : %s\n", employes[i].prenom);
//        printf("Date de naissance : %d %s %d\n", employes[i].date_naissance.jour, employes[i].date_naissance.mois, employes[i].date_naissance.annee);
//        printf("Date d'embauche : %d %s %d\n", employes[i].date_embauche.jour, employes[i].date_embauche.mois, employes[i].date_embauche.annee);
//        printf("\n");
//    }
//
//    return 0;
//}


// -------------------------------EXO 3 ------------------------------------

//#include <stdio.h>
//
//struct etudiant {
//    char nom[15];
//    int CNE;
//    float notes[4], moyenne;
//};
//
//void trierEtudiants(struct etudiant *T, int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (T[j].moyenne < T[j + 1].moyenne) {
//                // Échange des positions
//                struct etudiant temp = T[j];
//                T[j] = T[j + 1];
//                T[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int main() {
//    struct etudiant T[5];
//
//    // Saisie des informations pour 5 étudiants
//    for (int i = 0; i < 5; i++) {
//        printf("Entrez le nom de l'étudiant %d : ", i + 1);
//        scanf("%s", T[i].nom);
//
//        printf("Entrez le CNE de l'étudiant %d : ", i + 1);
//        scanf("%d", &T[i].CNE);
//
//        printf("Entrez les notes de l'étudiant %d (4 notes) : ", i + 1);
//        for (int j = 0; j < 4; j++) {
//            scanf("%f", &T[i].notes[j]);
//        }
//
//        // Calcul de la moyenne
//        T[i].moyenne = 0;
//        for (int j = 0; j < 4; j++) {
//            T[i].moyenne += T[i].notes[j];
//        }
//        T[i].moyenne /= 4;
//    }
//
//    // Tri du tableau d'étudiants selon la moyenne
//    trierEtudiants(T, 5);
//
//    // Affichage des étudiants triés
//    printf("Tableau d'étudiants triés en ordre décroissant selon la moyenne :\n");
//    for (int i = 0; i < 5; i++) {
//        printf("Nom : %s, CNE : %d, Moyenne : %f\n", T[i].nom, T[i].CNE, T[i].moyenne);
//    }
//
//    return 0;
//}


// -------------------------------EXO 4 ------------------------------------

//#include <stdio.h>
//#include <stdlib.h>
//
//struct Repertoire {
//    char nom[20];
//    char prenom[20];
//    char telephone[15];
//};
//
//void afficherRepertoire(struct Repertoire *repertoire, int taille) {
//    for (int i = 0; i < taille; i++) {
//        printf("Nom : %s\n", repertoire[i].nom);
//        printf("Prénom : %s\n", repertoire[i].prenom);
//        printf("Téléphone : %s\n", repertoire[i].telephone);
//        printf("\n");
//    }
//}
//
//int main() {
//    int taille;
//
//    // Saisie de la taille du répertoire
//    printf("Entrez la taille du répertoire : ");
//    scanf("%d", &taille);
//
//    // Allocation dynamique du tableau de structures
//    struct Repertoire *repertoire = (struct Repertoire *)malloc(taille * sizeof(struct Repertoire));
//
//    if (repertoire == NULL) {
//        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
//        return 1;
//    }
//
//    // Saisie des données pour chaque entrée du répertoire
//    for (int i = 0; i < taille; i++) {
//        printf("Entrez le nom de la personne %d : ", i + 1);
//        scanf("%s", repertoire[i].nom);
//
//        printf("Entrez le prénom de la personne %d : ", i);
//return 0;
//}


// ---------------------------- EXO 6 ---------------------------------------

//#include <stdio.h>
//#include <stdlib.h>
//
//// Définition de la structure Panneau
//struct Panneau {
//    int largeur;
//    int longueur;
//    int epaisseur;
//    int typeBois; // 0 pour Pin, 1 pour Chêne, 2 pour Hêtre
//};
//
//// Fonction de saisie d'un panneau
//void saisirPanneau(struct Panneau *panneau) {
//    printf("Saisie d'un panneau :\n");
//    printf("Largeur (mm) : ");
//    scanf("%d", &panneau->largeur);
//    printf("Longueur (mm) : ");
//    scanf("%d", &panneau->longueur);
//    printf("Épaisseur (mm) : ");
//    scanf("%d", &panneau->epaisseur);
//    printf("Type de bois (0 pour Pin, 1 pour Chêne, 2 pour Hêtre) : ");
//    scanf("%d", &panneau->typeBois);
//}
//
//// Fonction d'affichage d'un panneau
//void afficherPanneau(struct Panneau *panneau) {
//    printf("Panneau :\n");
//    printf("Largeur : %d mm\n", panneau->largeur);
//    printf("Longueur : %d mm\n", panneau->longueur);
//    printf("Épaisseur : %d mm\n", panneau->epaisseur);
//    printf("Type de bois : %d\n", panneau->typeBois);
//}
//
//// Fonction de calcul du volume d'un panneau
//float calculerVolume(struct Panneau *panneau) {
//    return (float)(panneau->largeur * panneau->longueur * panneau->epaisseur) / 1000000; // Conversion en mètres cubes
//}
//
//int main() {
//    struct Panneau panneau1;
//
//    // Saisie du premier panneau
//    saisirPanneau(&panneau1);
//
//    // Affichage du premier panneau
//    afficherPanneau(&panneau1);
//
//    // Calcul du volume du premier panneau
//    float volume1 = calculerVolume(&panneau1);
//    printf("Volume : %.2f m^3\n", volume1);
//
//    return 0;
//}

// -------------------------------------------------EXO 7 ----------------------------------

//#include <stdio.h>
//#include <stdlib.h>
//
//// Définition de la structure Produit
//struct Produit {
//    int reference;
//    float prix;
//    int quantiteDisponible;
//};
//
//// Fonction de saisie d'un produit
//void saisirProduit(struct Produit *produit) {
//    printf("Saisie d'un produit :\n");
//    printf("Référence : ");
//    scanf("%d", &produit->reference);
//    printf("Prix (DH) : ");
//    scanf("%f", &produit->prix);
//    printf("Quantité disponible : ");
//    scanf("%d", &produit->quantiteDisponible);
//}
//
//// Fonction d'affichage d'un produit
//void afficherProduit(struct Produit *produit) {
//    printf("Produit :\n");
//    printf("Référence : %d\n", produit->reference);
//    printf("Prix : %.2f DH\n", produit->prix);
//    printf("Quantité disponible : %d\n", produit->quantiteDisponible);
//}
//
//// Fonction de saisie d'une commande
//void saisirCommande(struct Produit *produit) {
//    int quantiteCommandee;
//    printf("Saisie de la commande :\n");
//    printf("Quantité commandée : ");
//    scanf("%d", &quantiteCommandee);
//
//    if (quantiteCommandee <= produit->quantiteDisponible) {
//        printf("Commande validée :\n");
//        printf("Référence : %d\n", produit->reference);
//        printf("Prix unitaire : %.2f DH\n", produit->prix);
//        printf("Quantité commandée : %d\n", quantiteCommandee);
//        printf("Prix total : %.2f DH\n", produit->prix * quantiteCommandee);
//    } else {
//        printf("Stock insuffisant pour satisfaire la commande.\n");
//    }
//}
//
//int main() {
//    struct Produit produit1;
//
//    // Saisie du premier produit
//    saisirProduit(&produit1);
//
//    // Affichage du premier produit
//    afficherProduit(&produit1);
//
//    // Saisie de la commande pour le premier produit
//    saisirCommande(&produit1);
//
//    return 0;
//}


// ---------------------------------------EXO 8 ---------------------------------------------

//#include <stdio.h>
//#include <stdlib.h>
//
//// Définition de la structure TypeTableau
//typedef struct {
//    int nb_elem;
//    int *tab;
//} TypeTableau;
//
//// Fonction de création d'un tableau
//TypeTableau CreationTableau(int n) {
//    TypeTableau T;
//    T.nb_elem = n;
//    T.tab = (int *)malloc(n * sizeof(int));
//    return T;
//}
//
//// Fonction de libération de la mémoire occupée par un tableau
//void DestructionTableau(TypeTableau T) {
//    free(T.tab);
//}
//
//// Fonction de saisie d'un tableau
//void SimpleLectureTableau(TypeTableau T) {
//    printf("Saisie du tableau :\n");
//    for (int i = 0; i < T.nb_elem; i++) {
//        printf("Element %d : ", i + 1);
//        scanf("%d", &T.tab[i]);
//    }
//}
//
//// Fonction d'affichage d'un tableau
//void Affichage(TypeTableau T) {
//    printf("Affichage du tableau :\n");
//    for (int i = 0; i < T.nb_elem; i++) {
//        printf("%d ", T.tab[i]);
//    }
//    printf("\n");
//}
//
//// Fonction de création d'un nouveau tableau avec le double des éléments
//TypeTableau DoubleTableau(TypeTableau T) {
//    TypeTableau NouveauT = CreationTableau(T.nb_elem);
//    for (int i = 0; i < T.nb_elem; i++) {
//        NouveauT.tab[i] = 2 * T.tab[i];
//    }
//    return NouveauT;
//}
//
//int main() {
//    int n;
//    printf("Entrez la taille du tableau : ");
//    scanf("%d", &n);
//
//    // Création du tableau initial
//    TypeTableau MonTableau = CreationTableau(n);
//
//    // Saisie du tableau initial
//    SimpleLectureTableau(MonTableau);
//
//    // Affichage du tableau initial
//    Affichage(MonTableau);
//
//    // Création d'un nouveau tableau avec le double des éléments
//    TypeTableau NouveauTableau = DoubleTableau(MonTableau);
//
//    // Affichage du nouveau tableau
//    Affichage(NouveauTableau);
//
//    // Libération de la mémoire occupée par les tableaux
//    DestructionTableau(MonTableau);
//    DestructionTableau(NouveauTableau);
//
//    return 0;
//}


