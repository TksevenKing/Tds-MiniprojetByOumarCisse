#include<stdio.h>

//------------------------EXO 1 -----------------------------------------
//int main(){
//	
//	int a,b;
//	char op;
//	
//	printf("saisir la valeur de a :\n");
//	scanf("%d",&a);
//	printf("saisir la valeur de b :\n");
//	scanf("%d",&b);
//	
//	printf("choisissez l'operation que vous voulez faire entre +,-,*,/ :\n");
//	scanf(" %c",&op);
//	
//	
//	switch (op){
//		case '+': 
//	    	printf("la somme de %d et %d est: %d\n",a,b,a+b);
//	    	break;
//		case '-':
//			printf("la soustraction de %d et %d est: %d\n",a,b,a-b);
//			break;
//		case '*':
//			printf("la multiplication de %d et %d est: %d\n",a,b,a*b);
//			break;
//		case '/':
//			if(b!=0){
//				printf("la division de %d et %d est: %d\n",a,b,a/b);
//			}else{
//				printf("impossible saisire b!= de 0");
//			}
//		break;	
//		default:
//			printf("Error choisir entre +,-,*,/");
//			
//	}
//	
//return 0;
//}

//------------------------------EXO 2 --------------------------------------

//int main(){
//	
//	unsigned int age ;
//	int sexe;
//	
//	printf("saisir l'age :\n");
//	scanf("%d",&age);
//	
//	printf("saisir le sexe :\n");
//	printf("1-pour Homme\t 2-pour Femme\n");
//	scanf("%d",&sexe);
//	
//	if((age > 20 && sexe == 1)) {
//		printf("la personne est imposable\n");
//	}else if ( ((age >= 18 || age <= 35 ) && sexe == 0)){
//		printf("la personne est imposable\n");
//	}
//	else{
//		printf("n'est pas imposable.");
//	}
//	
//	return 0;
//}

//---------------------------EXO 3-----------------

//int main(){
//	
//	int nbcopie;
//	float result;
//	
//	printf("saisir le nombre de copies a effectuer : \n");
//	scanf("%d",&nbcopie);
//	
//	if(nbcopie <= 10){
//		printf("le facture est : %d",nbcopie);
//	}else if (nbcopie > 10 || nbcopie <= 30){
//		result = ((nbcopie - 10)*0.6) + 10;
//		printf("la facture est %.2f",result);
//	}else {
//		result = 10 + (20*0.6) + (nbcopie-30)*0.4;
//		printf("la facture est %.2f",result);
//		 
//	}
//}

//------------------------EXO 4--------------------------

//float prix;
//float remise;
//
//int main(){
//	
//	printf("saisir le prix initial du produit :\n");
//	scanf("%f",&prix);
//	
//	if(prix < 100){
//		remise = prix*0.30;
//		printf("Prix initial : %.2f DH, Remise : %.2f DH, Prix final : %.2f DH",prix,remise,prix-remise);	
//	}else if(prix >= 100 && prix <= 200){
//		remise = prix*0.40;
//		printf("Prix initial : %.2f DH, Remise : %.2f DH, Prix final : %.2f DH",prix,remise,prix-remise);				
//	}else{
//		remise = prix*0.5;
//		printf("Prix initial : %.2f DH, Remise : %.2f DH, Prix final : %.2f DH",prix,remise,prix-remise);
//			
//	}
//		
//	return 0;
//}

//-------------------------------EXO 5------------------------------
//
//int main(){
//	
//	int i,nbr;
//	
//	printf("saisir nombre :\n");
//	scanf("%d",&nbr);
//
//for(i=2;i < nbr;i++){
//	if(nbr % i == 0){
//		printf("%d n'est pas premier . \n",nbr);
//		break;
//	}		
//} 
//if(i == nbr){
//      printf("%d est Premier .\n",nbr);	
//}
//
//
//	return 0;
//}

//----------------------------------EXO 6---------------------------

//int main(){
//	
//	int nbr;
//	
//	printf("saisir nombre :\n");
//	scanf("%d",&nbr);
//	
//	if(nbr % 2 == 0){
//		printf("Voici les nombres pairs qui lui sont inferieurs : \n");
//		for(int i=1;i<nbr;i++){
//			if(i % 2 == 0)
//			printf("%d\t",i);
//		}
//	}
//	return 0;
//}

//------------------------------------EXO 7--------------------------


//int main(){
//	//Question-1
//	int nbr ; 
//	
//	for(int i=0;i<20;i++){
//		
//    	printf("saisir nombre :\n");
//        scanf("%d",&nbr);
//    
//    if(nbr % 2 == 0)
//	    printf("le carre de %d est : %d\n",nbr,nbr*nbr);	
//	}
////Question-2
//	
//	int nbpair = 0, nbentree = 0;
//	
//	do {
//		printf("saisir nombre :\n");
//        scanf("%d",&nbr);
//        nbentree ++;
//        
//        if(nbr % 2 == 0){
//        	nbpair ++;
//            printf("le carre de %d est : %d\n",nbr,nbr*nbr);	
//		}
//	
//	}while(nbr != 100);
//	
//	printf("le nbre total d'entree est : %d et le nbre total d'entree paires est : %d\n",nbentree,nbpair);
//	
//	return 0;
//}

//------------------------------EXO 8------------------------------

//int main(){
//	
//	int i,j;
//
//
//for( i=0; i<=6; i++){
//	for(j=1;j<(6-i);j++){
//		printf("%d",j);
//	}
//	printf("\n");
//}
//
//for( i=0; i<10; i++){
//	for(j=1;j<=(10-i);j++){
//		printf("%d",i);
//	}
//	
//	printf("\n"); //pour le EOL en C
//	for(int k=0;k<=i;k++) //Pour Ranger les chiffres a droite 
//			printf(" ");
//}
//	return 0;
//}

//--------------------------------EXO 9-------------------

//
//
//int main() {
//    int nombre, total = 0, somme = 0, minimum = 0, somme_positives = 0, minimum_positives_found = 0, minimum_positives;
//
//    printf("Entrez une suite de nombres entiers (terminée par 999):\n");
//
//    while (1) {
//        scanf("%d", &nombre);
//
//        if (nombre == 999) {
//            break;
//        }
//
//        total++;
//
//        // Calcul de la somme des valeurs
//        somme += nombre;
//
//        // Calcul du minimum
//        if (total == 1 || nombre < minimum) {
//            minimum = nombre;
//        }
//
//        // Calcul de la somme des valeurs strictement positives
//        if (nombre > 0) {
//            somme_positives += nombre;
//
//            // Calcul du minimum des valeurs strictement positives
//            if (!minimum_positives_found || nombre < minimum_positives) {
//                minimum_positives = nombre;
//                minimum_positives_found = 1;
//            }
//        }
//    }
//
//    printf("Le nombre total de valeurs de la suite : %d\n", total);
//    printf("La somme des valeurs : %d\n", somme);
//    printf("Le minimum : %d\n", minimum);
//    printf("La somme des valeurs strictement positives : %d\n", somme_positives);
//
//    if (minimum_positives_found) {
//        printf("Le minimum des valeurs strictement positives : %d\n", minimum_positives);
//    } else {
//        printf("Aucune valeur strictement positive trouvée.\n");
//    }
//
//    return 0;
//}

// --------------------------------------EXO 10 ----------------------------------


//void afficherTriangleIsocel(int N) {
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j <= N - i; j++) {
//            printf(" ");
//        }
//        for (int j = 1; j <= 2 * i - 1; j++) {
//            printf("*");
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    int N;
//
//    printf("Entrez le nombre de lignes du triangle isocèle : ");
//    scanf("%d", &N);
//
//    afficherTriangleIsocel(N);
//
//    return 0;
//}

//----------------------------------EXO 11 -------------------------------------------

//int main() {
//    int entier = 0;
//    int choix;
//
//    do {
//        printf("La valeur de l'entier est : %d\n", entier);
//        printf("Menu :\n");
//        printf("1. Ajouter 2\n");
//        printf("2. Multiplier par 3\n");
//        printf("3. Soustraire 5\n");
//        printf("4. Quitter\n");
//
//        printf("Entrez un entier entre 1 et 4 : ");
//        scanf("%d", &choix);
//
//        switch (choix) {
//            case 1:
//                entier += 2;
//                break;
//            case 2:
//                entier *= 3;
//                break;
//            case 3:
//                entier -= 5;
//                break;
//            case 4:
//                printf("Programme terminé.\n");
//                break;
//            default:
//                printf("Choix invalide. Veuillez réessayer.\n");
//        }
//    } while (choix != 4);
//
//    return 0;
//}
















































