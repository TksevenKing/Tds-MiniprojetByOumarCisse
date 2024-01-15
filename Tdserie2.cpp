#include<stdio.h>
#include<string.h>
#define Nmax 20
#include"header.h"
//#include"fonctions.cpp"

//------------------------EXO-1------------------------------------------
//char menu(){
//	char choix;
//	
//	printf("---------MENU---------\n");
//	
//	printf("A- Saisie et affichage\n");
//	printf("B- Moyenne\n");
//	printf("C- Suppression du Max et affichage\n");
//	printf("D- Suppression du Min et affichage\n");
//	printf("E- Ajout d'un entier à une position donnée \n");
//	printf("Q- Quitter\n");
//	
//	scanf(" %c",&choix);
//	
//	
//	
//	return choix;
//}
//void affichage(int tab[],int n){
//	int i;
//	
//	for(i=0;i<n;i++){
//		printf("[%d]",tab[i]);
//	}
//	printf("\n");
//}
//
//void saisie(int tab[], int* n){
//	
//	int i;
//	
//	printf("saisir le nombre d'elts du tableau:\n");
//	scanf("%d",n);
//	
//	for(i=0;i<(*n);i++){
//		printf("saisir l'elt [%d]=",i+1);
//		scanf("%d",&tab[i]);
//	}
//}
//
//void moyenne(int tab[],int n){
//	
//	float s=0, moy=0;
//    int i;
//	for(i=0;i<n;i++){
//		s = s + tab[i];
//	}	
//	moy = s/n;
//	printf("La moyenne des elts du tableau est = %.2f\n",moy);
//	printf("\n");
//}
//int rechercheposMax(int tab[],int n){
//	int i,posmax=-1,max;
//	
//	max = tab[0];
//	for(i=1;i<n;i++){
//		if (tab[i]>max){
//			max = tab[i];
//			posmax = i;
//		}
//	}
//	 return posmax;
//}
//int rechercheMax(int tab[],int n){
//	int i,max;
//	
//	max = tab[0];
//	for(i=1;i<n;i++){
//		if (tab[i]>max){
//			max = tab[i];
//		}
//	}
//	 return max;
//}
//int rechercheposMin(int tab[],int n){
//	int i,posmin=-1,min;
//	
//	min = tab[0];
//	for(i=1;i<n;i++){
//		if (tab[i]<min){
//			min = tab[i];
//			posmin = i;
//		}
//	}
//	 return posmin;
//}
//void suppressionMax(int tab[],int n){ //sans tableau d'aide 
//	int i,max;
//	int deb=0, fin=n-1,temp;
//	
//	max = rechercheMax(tab,n);
//	
//	while(deb < fin){
//		if(tab[deb] == max){
//			temp = tab[deb];
//		tab[deb] = tab[fin];
//		tab[fin] = temp;
//		fin--; 
//		}else {
//			deb++;
//		}
//	}
//	printf("Apres suppression du max:\n");
//	for(i=0;i<=fin;i++){
//		printf("[%d]",tab[i]);
//	}
//	printf("\n");
//}
//void suppression2(int tab[],int n){ //avec tableau d'aide
//	int max,i,j=0,taille=1;
//	
//	max = rechercheMax(tab,n);
//	int tabaide[n];
//	
//	for(i=0;i<n;i++){
//		if(max != tab[i]){
//			tabaide[j] = tab[i];
//			j++;
//			taille++;
//		}
//	}
//	for(j=0;j<taille-1;j++){
//		printf("[%d]",tabaide[j]);
//	}
//}
//int rechercheMin(int tab[],int n){
//	int i,min;
//	
//	min = tab[0];
//	
//	for(i=0;i<n;i++){
//		if(tab[i]<=min){
//			min = tab[i];
//		}
//	}
//	return min;
//}
//void suppressionMin(int tab[],int n){
//    int i,min;
//	int deb=0, fin=n-1,temp;
//	
//	min = rechercheMin(tab,n);
//	
//	while(deb < fin){
//		if(tab[deb] == min){
//			temp = tab[deb];
//		    tab[deb] = tab[fin];
//		    tab[fin] = temp;
//		    fin--; 
//		}else {
//			deb++;
//		}
//	}
//	printf("Apres suppression du min:\n");
//	for(i=0;i<=fin;i++){
//		printf("[%d]",tab[i]);
//	}	
//	printf("\n");
//}
//void ajout(int tab[],int n){
//	int i,val,pos;
//	
//	do{
//		printf("saisir la valeur a ajouter au tableau:\n");
//		scanf("%d",&val);
//		printf("saisir la position a laquelle vous voulez ajouter l'elt:(pos < a la taille du tableau )\n");
//		scanf("%d",&pos);
//	}while(pos > n);
//	
//	for(i=n;i>pos;i--){
//		tab[i] = tab[i-1];
//	}
//    tab[pos] = val;
//	//affichage du tableau apres ajout
//	for(i=0;i<=n;i++){
//		printf("[%d]",tab[i]);
//	}
//	printf("\n");
//}
//int main(){
//	
//	int tab[Nmax],n;
//	char choix;
//	
//	
//	do{
//		choix = menu();
//		
//		switch (choix){
//			case 'A': 
//			    printf("saisie des elts du tableau:\n");
//			    saisie(tab,&n);
//			    affichage(tab,n);
//			    break;
//			case 'B':
//			    moyenne(tab,n);
//			    break;
//			case 'C':
//			    suppressionMax(tab,n);
//			    break;
//			case 'D':
//			    suppressionMin(tab,n);
//			    break;
//			case 'E':
//			    ajout(tab,n);
//			    break;
//			case 'Q':
//			    printf("vous avez quitter le programme Aurevoir !\n");
//			    break;			    
//			default : 
//				printf("veuillez choisir entre A,B,C,D,E et Q\n");
//				break;	
//        }
//
//	}while(choix != 'Q');
//	
//	//printf("avant suppression\n");
//	
//	//printf("apres suppression");
//	//suppression2(tab,n);
//	//suppressionMax(tab,n);
//	//suppressionMin(tab,n);
//	//ajout(tab,n);
//	
//	
//	
//	return 0;
//}
// -------------------------------EXO-2-------------------------------------
//void afficheMatrice(int imat[5][5]){
//	int i,j;
//	
//	for(i=0;i<5;i++){
//		for(j=0;j<5;j++){
//			printf("%d ",imat[i][j]);
//		}
//			printf("\n");
//	}
//}
//
//
//int main(){
//	
//	int i,j,imat[5][5];
//	
//	printf("remplir la matrice [5,5]:\n");
//		for(i=0;i<5;i++){
//	    	for(j=0;j<5;j++){
//			scanf("%d",&imat[i][j]);
//		}
//	}
//	
//	afficheMatrice(imat);
//	return 0;
//}
//-------------------------------EXO-3---------------------------------------------

//// cet EXO est entrain de creer un tableau de 12 case dont chaque indice correspond a un  mois de l'annee 
////et les cases contienne le nombre de jours correspondant au mois d'indice i 
////si i= 2(mois de fevrier) alors []=28; sinon si i est est pair et fait parti des sept(7) premiers mois
//// oubien si e est impair et ne fait pas parti des 7 premiers mois , alors le nbre de jour du mois est 30 
////sinon le nbre de jour est 31
////Procedure d'initialisation
//void initialisation(int inbJours[]){
//	int i;
//	
//	inbJours[0] = 0;
//	for(i=1;i<=12;i++){
//		if(i == 2){
//			inbJours[i] = 28;
//		}else if(((i%2 == 0) && (i <= 7)) || ((i%2 != 0) && (i>7))){
//			inbJours[i] = 30;
//		}else {
//			inbJours[i] = 31;
//		}
//	}
//}
////void impression(int inbJours){
////	int i;
////	
////	for(i=1;i<=12;i++){
////		printf("[%d]",inbJours[i]);
////	}
////	printf("\n");
////
////}
//int main(){
//	
//	int inbJours[12];
//	
//	initialisation(inbJours);
//	affichage(inbJours,13);
//   
//	
//	
//	return 0;
//}
//------------------------------------EXO-4----------------------------------------

//void longueurChaine(char cTab[]){
//	int cpt=0,i=0;
//	
//	while(cTab[i] != '\0'){
//		i++;
//		cpt++;
//	}
//	printf("la longueur de la chaine est :%d\n",cpt);
//}
//int main(){
//    char cTab1[] = "oumar";
//    char cTab2[] = "cisse";
//		
//	longueurChaine(cTab1);
//	longueurChaine(ctab2);
//	return 0;
//}

//-----------------------------------EXO-5-----------------------------------------

//void crypt(char chaine[]){
//	int i;
//	
//	while(chaine[i] != '\0'){
//		chaine[i] = chaine[i] + 5;
//		i++;
//	}
//	puts(chaine);
//}
//
//int main(){
//	
//	char cMessage[] = "je m'appelle oumar cisse ";
//	
//	puts(cMessage);
//	crypt(cMessage);
//	return 0;
//}

//-------------------------------EXO-5-m serie bizzare

//int main(){
//	int tab[20];
//	int n;
//	
//	printf("saisir la taille du tableau :\n");
//	scanf("%d",&n);
//	
//	//saisiefloat(tab,&n);
//	saisie(tab,&n);
//	affichage(tab,n);
//	moyenne(tab,20);
//	printf("voici la position du min %d",rechercheposMin(tab,20));
//	printf("voici le  min %d",rechercheMin(tab,20));
//	
//	
//	
//    return 0;
//}

// ----------------------------------- EXO 6 ------------------------------------

// ----------------------------------- EXO 7 ------------------------------


//
//int addition(int A, int B) {
//    return A + B;
//}
//
//int soustraction(int A, int B) {
//    return A - B;
//}
//
//int multiplication(int A, int B) {
//    return A * B;
//}
//
//int division(int A, int B) {
//    if (B != 0) {
//        return A / B;
//    } else {
//        printf("Erreur : division par zéro\n");
//        return 0;
//    }
//}
//
//int modulo(int A, int B) {
//    if (B != 0) {
//        return A % B;
//    } else {
//        printf("Erreur : division par zéro\n");
//        return 0;
//    }
//}
//
//int main() {
//    int A, B, resultat;
//    char operateur, choix;
//
//    do {
//        printf("Entrez une expression (ex: 2 + 5) ou 'Q' pour quitter : ");
//        scanf("%d %c %d", &A, &operateur, &B);
//
//        if (operateur == 'Q') {
//            printf("Programme terminé.\n");
//            break;
//        }
//
//        switch (operateur) {
//            case '+':
//                resultat = addition(A, B);
//                break;
//            case '-':
//                resultat = soustraction(A, B);
//                break;
//            case '*':
//                resultat = multiplication(A, B);
//                break;
//            case '/':
//                resultat = division(A, B);
//                break;
//            case '%':
//                resultat = modulo(A, B);
//                break;
//            default:
//                printf("Opérateur invalide. Réessayez.\n");
//                continue;  // Revenir au début de la boucle sans afficher le résultat
//        }
//
//        printf("Résultat : %d\n", resultat);
//
//        printf("Voulez-vous recommencer (O/N) ? ");
//        scanf(" %c", &choix);
//    } while (choix == 'O' || choix == 'o');
//
//    return 0;
//}

//-----------------------------------------EXO 8 ----------------------------------


//
//int aPlusDeDixCaracteres(char *nom) {
//    return strlen(nom) > 10;
//}
//
//int main() {
//    char nom[20];
//
//    printf("Entrez une suite de noms (terminée par 'fin') :\n");
//
//    do {
//        // Lecture d'un nom
//        printf("Nom : ");
//        scanf("%s", nom);
//
//        // Vérification si le nom a plus de dix caractères
//        if (aPlusDeDixCaracteres(nom)) {
//            printf("Le nom \"%s\" a plus de dix caractères.\n", nom);
//        }
//
//    } while (strcmp(nom, "fin") != 0); // La boucle continue tant que le nom n'est pas "fin"
//
//    return 0;
//}

// ------------------------------------EXO 9 -----------------------------------------

//
//
//// Fonction pour saisir une chaîne de caractères
//void saisir(char *chaine) {
//    printf("Entrez une chaîne de caractères : ");
//    scanf(" %[^\n]s", chaine);
//}
//
//// Fonction pour afficher une chaîne de caractères
//void afficher(char *chaine) {
//    printf("La chaîne est : %s\n", chaine);
//}
//
//// Fonction pour inverser une chaîne de caractères
//void inverser(char *chaine) {
//    int longueur = strlen(chaine);
//    for (int i = 0, j = longueur - 1; i < j; i++, j--) {
//        char temp = chaine[i];
//        chaine[i] = chaine[j];
//        chaine[j] = temp;
//    }
//}
//
//// Fonction pour compter le nombre de mots dans une chaîne
//int compterMots(char *chaine) {
//    int mots = 0;
//    int longueur = strlen(chaine);
//    int estDansUnMot = 0; // 0 si en dehors d'un mot, 1 si dans un mot
//
//    for (int i = 0; i < longueur; i++) {
//        if (chaine[i] == ' ') {
//            estDansUnMot = 0;
//        } else if (estDansUnMot == 0) {
//            mots++;
//            estDansUnMot = 1;
//        }
//    }
//
//    return mots;
//}
//
//int main() {
//    char chaine[100]; // Taille maximale de la chaîne
//
//    int choix;
//
//    do {
//        printf("\nMenu :\n");
//        printf("1. Saisir une chaîne\n");
//        printf("2. Afficher la chaîne\n");
//        printf("3. Inverser la chaîne\n");
//        printf("4. Compter les mots\n");
//        printf("5. Quitter\n");
//        printf("Entrez votre choix : ");
//        scanf("%d", &choix);
//
//        switch (choix) {
//            case 1:
//                saisir(chaine);
//                break;
//            case 2:
//                afficher(chaine);
//                break;
//            case 3:
//                inverser(chaine);
//                printf("La chaîne inversée est : %s\n", chaine);
//                break;
//            case 4:
//                printf("Le nombre de mots dans la chaîne est : %d\n", compterMots(chaine));
//                break;
//            case 5:
//                printf("Programme terminé.\n");
//                break;
//            default:
//                printf("Choix invalide. Veuillez réessayer.\n");
//        }
//
//        printf("Frapper une touche pour revenir au menu...\n");
//        getchar(); // Attend une touche
//        getchar(); // Attend une autre touche
//
//    } while (choix != 5);
//
//    return 0;
//}

// ----------------------------------------EXO 10 -------------------------------------



// Fonction pour calculer la distance de Hamming entre deux chaînes de caractères
int distanceH(char *S1, char *S2) {
    int distance = 0;
    int longueur = strlen(S1);

    for (int i = 0; i < longueur; i++) {
        if (S1[i] != S2[i]) {
            distance++;
        }
    }

    return distance;
}

// Fonction pour calculer la distance de Hamming d'un langage (tableau de chaînes de caractères)
int distanceH_langage(char **langage, int nombreDeMots, int longueurDesMots) {
    int distanceMin = -1;  // Initialisation à une valeur impossible
    int distanceActuelle;

    for (int i = 0; i < nombreDeMots - 1; i++) {
        for (int j = i + 1; j < nombreDeMots; j++) {
            distanceActuelle = distanceH(langage[i], langage[j]);
            if (distanceMin == -1 || distanceActuelle < distanceMin) {
                distanceMin = distanceActuelle;
            }
        }
    }

    return distanceMin;
}

// Fonction pour convertir un nombre en binaire sur un octet
char *binaire(int N) {
    char *resultat = malloc(9);  // 8 bits + le caractère de fin de chaîne '\0'

    for (int i = 7; i >= 0; i--) {
        resultat[7 - i] = ((N >> i) & 1) + '0';
    }

    resultat[8] = '\0';

    return resultat;
}

// Fonction pour calculer la distance de Hamming entre deux nombres entiers
int distanceNombre(int A, int B) {
    char *binaireA = binaire(A);
    char *binaireB = binaire(B);

    int distance = distanceH(binaireA, binaireB);

    free(binaireA);
    free(binaireB);

    return distance;
}

int main() {
    // Exemple d'utilisation

    // Distance de Hamming entre deux chaînes de caractères
    char S1[] = "aabb";
    char S2[] = "xayy";
    printf("Distance de Hamming entre \"%s\" et \"%s\" : %d\n", S1, S2, distanceH(S1, S2));

    // Distance de Hamming d'un langage
    char *langage[] = {"aabb", "xayy", "tghy", "xgyy"};
    int nombreDeMots = 4;
    int longueurDesMots = strlen(langage[0]);
    printf("Distance de Hamming du langage : %d\n", distanceH_langage(langage, nombreDeMots, longueurDesMots));

    // Distance de Hamming entre deux nombres entiers
    int A = 7;
    int B = 4;
    printf("Distance de Hamming entre %d et %d : %d\n", A, B, distanceNombre(A, B));

    return 0;
}








