#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h> //Pour isdigit et isspace
// Pour effacer et afficher le menu a chaque iteration
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif
// ================ POur qu el ataille du tableau soit variable 
#define maxlength 10

typedef struct{
	char nom[20];
//	char prenom[20];
	char adresse[40];
	long numero;
	char email[40];
}personne;


//======================== DON'T forget to donner une taille variablea au tableau 
typedef struct{
	personne liste_p[maxlength];
	int nb_per = 0;
}carnet;


int estAlphabetique(const char *str) {
    while (*str) {
        if (!isalpha(*str)) {
            return 0; 
        }
        str++;
    }
    return 1;
}

int estNumerique(long num) {
    // Vérifie si le numéro contient uniquement des chiffres
    while (num > 0) {
        if (!isdigit(num % 10 + '0')) {
            return 0; // Il y a un chiffre non numérique
        }
        num /= 10;
    }
    return 1; // Tous les chiffres sont numériques
}

int countDigits(long num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
        //printf("dans count %d\n",count);
    }
    return count;
}

// ========================Fonction pour vérifier si une chaîne est une adresse email valide========================//
int estEmailValide(const char *email) {
    // Dans cet exemple, on vérifie simplement la présence du caractère '@'
    return (strchr(email, '@') != NULL);
}
// ======================== Fonction qui creer et retourne une personne ========================//
personne creer_personne() {
    personne p;

    // Saisie du nom avec validation alphabétique
    do {
        printf("Saisir le nom (caracteres alphabetiques uniquement) :\t");
        if (scanf("%19s", p.nom) != 1 || !estAlphabetique(p.nom)) {
            printf("Erreur de saisie, veuillez entrer un nom valide.\n");
            while (getchar() != '\n'); // Vider le buffer d'entrée
        } else {
            break;
        }
    } while (1);

    printf("Saisir son adresse :\t");
    //scanf("%39s", p.adresse);
    if (scanf("%39s", p.adresse) != 1) {
        printf("Erreur de saisie, veuillez entrer une adresse valide.\n");
        while (getchar() != '\n'); // Vider le buffer d'entrée
    }

    // Validation du numéro avec une longueur maximale de 10 chiffres========================//
    do {
        printf("Saisir son numero (10 chiffres au maximum) :\t");
        if (scanf("%ld", &(p.numero)) != 1 || !estNumerique(p.numero) || countDigits(p.numero) > 10) {
            printf("Erreur de saisie, veuillez entrer un numéro valide (10 chiffres au maximum).\n");
            while (getchar() != '\n'); // Vider le buffer d'entrée
        } else {
            break;
        }
    } while (1);

    // ========================Validation de l'email========================//
    do {
        printf("Saisir son email :\t");
        if (scanf("%39s", p.email) != 1 || !estEmailValide(p.email)) {
            printf("Erreur de saisie, veuillez entrer une adresse email valide.\n");
            while (getchar() != '\n'); // Vider le buffer d'entrée
        } else {
            break;
        }
    } while (1);
    

    return p;
}



//==================fonction affichage===================//
void affiche_personne(personne p){
	printf("Informations de la personne:\n");
	printf("nom: %s\t", p.nom);
	printf("adresse: %s\t", p.adresse);
	printf("email: %s\t", p.email);
	printf("numero: %ld\n", p.numero);
}


//====================== affichage de la liste complet des contacts========================//
void affiche_complet(carnet c){
	int i;
	for(i=0;i<c.nb_per;i++){
		affiche_personne(c.liste_p[i]);
	}
}

//======================fonction d'ajout des personnes dans mon carnet de contact===========================//
int recherche_nom (carnet c, char nom[]);
int recherche_num(carnet c, long num);
void sauvegarderDansFichier(carnet c, const char *nomFichier);

//====================VERSION Correct=======================//
//========================Fonction qui creer et ajoute une personne ===========================//
void ajouter_personne(carnet *c, int nbr) {
    int i;
    personne p;
//	long num ;
	char num[11];
    for (i = 0; i < nbr; i++) {
        // Saisie du nom avec validation alphabétique
        do {
            printf("Saisir le nom (caracteres alphabetiques uniquement) :\t");
            if (scanf("%19s", p.nom) != 1 || !estAlphabetique(p.nom)) {
                printf("Erreur de saisie, veuillez entrer un nom valide.\n");
                while (getchar() != '\n'); // Vider le buffer d'entrée
            } else {
                break;
            }
        } while (1);

        printf("Saisir son adresse :\t");
        //scanf("%39s", p.adresse);
        if (scanf("%39s", p.adresse) != 1) {
            printf("Erreur de saisie, veuillez entrer une adresse valide.\n");
            while (getchar() != '\n'); // Vider le buffer d'entrée
        }

        // Validation du numéro avec une longueur maximale de 10 chiffres
        do {
            printf("Saisir son numero (10 chiffres au maximum) :\t");
            scanf("%s",num);
             if (strlen(num) != 10 || num[0] != '0' ) {
                printf("Erreur de saisie, veuillez entrer un numéro valide (10 chiffres au maximum).\n");
               // printf("dans creation  %d\n",countDigits(num));
                while (getchar() != '\n'); // Vider le buffer d'entrée
            } else {
            	 // Convert the phone number string to a long
        		long phoneNumber = strtol(num, NULL, 10);
            	p.numero = phoneNumber;
                break;
            }
        } while (1);

        // Validation de l'email
        do {
            printf("Saisir son email :\t");
            if (scanf("%39s", p.email) != 1 || !estEmailValide(p.email)) {
                printf("Erreur de saisie, veuillez entrer une adresse email valide.\n");
                while (getchar() != '\n'); // Vider le buffer d'entrée
            } else {
                break;
            }
        } while (1);

        // Vérifier si le nom ou le numéro existe déjà dans le carnet
        if (recherche_nom(*c, p.nom) != -1 || recherche_num(*c, p.numero) != -1) {
        	if(recherche_nom(*c, p.nom) != -1){
        	printf("\n Impossible, ce nom existe deja !\n");
			}
			if(recherche_num(*c, p.numero) != -1){
        	    printf("\n Impossible, ce numero existe deja !\n");
			}
            i--; // Réduire le compteur pour répéter la saisie de la même personne
        } 
		else {
            c->liste_p[c->nb_per++] = p;
            sauvegarderDansFichier(*c,"contacts.txt");
        }
    }
    printf("Ajout effectuee avec succes\n");
}



//recherche par nom
int recherche_nom (carnet c, char nom[]){
	int i, pos = -1;

	for(i=0;i<c.nb_per;i++){
	   if(strcmp(c.liste_p[i].nom, nom) == 0){
	   	pos = i;
        }
	}
	   return pos;
}

//recherche par numero
int recherche_num(carnet c, long num){
	int i, pos = -1;

	for(i=0;i<c.nb_per;i++){
		if(c.liste_p[i].numero == num)
		  pos = i;
	}
	return pos;
}


// fonction pour modifier toutes les infos d'une personne en meme temps en le recherchant par numero
void modifier_par_num(carnet *c, long num){

	int pos = recherche_num(*c,num);
	if(pos != -1){
		c->liste_p[pos] = creer_personne();
		
		printf("contact modifiee avec succes !\n");
		sauvegarderDansFichier(*c,"contacts.txt");
	}else{
		printf("%ld introuvable dans les contacts !\n",num);
	}
}
// fonction pour modifier toutes les informations d'une personne en meme temps en le recherchant par son nom
void modifier_infos_par_nom(carnet *c, char nom[]){

	int pos = recherche_nom(*c,nom);
	if(pos != -1){
		c->liste_p[pos] = creer_personne();
		
		printf("contact modifiee avec succes !\n");
		sauvegarderDansFichier(*c,"contacts.txt");
	}else{
		printf("%s introuvable dans les contacts !\n",nom);
	}
}

// fonction pour modifier uniquement le nom
void modifier_nom(carnet *c, char nom[]){
	char new_name[20];
	int pos = recherche_nom(*c,nom);
	if(pos != -1){
		
		     // Saisie du nom avec validation alphabétique
        do {
            printf("Saisir le nouveau nom (caracteres alphabetiques uniquement) :\t");
            if (scanf("%s",new_name) != 1 || !estAlphabetique(new_name)) {
                printf("Erreur de saisie, veuillez entrer un nom valide.\n");
                while (getchar() != '\n'); // Vider le buffer d'entrée
            } else {
                break;
            }
        } while (1);
		
//		printf("saisir nouveau nom:");
//		scanf("%s",new_name);
		//gets(new_name);
	//	c->liste_p[pos].nom = new_name;
		strcpy(c->liste_p[pos].nom,new_name);
		sauvegarderDansFichier(*c,"contacts.txt");
		printf("nom modifie avec succes !");
	}else{
		printf("%s introuvable dans les contacts !\n",nom);
	}
}

//fonction pour modifier uniquement le numero
void modifier_num(carnet *c, long num1 ){
     
    char num [11];
	long new_num;
	int pos = recherche_num(*c,num1);
	if(pos != -1){
		
		        // Validation du numéro avec une longueur maximale de 10 chiffres
        do {
            printf("Saisir son nouveau numero (10 chiffres au maximum) :\t");
            scanf("%s",num);
             if (strlen(num) != 10 || num[0] != '0' ) {
                printf("Erreur de saisie, veuillez entrer un numéro valide (10 chiffres au maximum).\n");
               // printf("dans creation  %d\n",countDigits(num));
                while (getchar() != '\n'); // Vider le buffer d'entrée
            } else {
            	 // Convert the phone number string to a long
        		long phoneNumber = strtol(num, NULL, 10);
            	new_num = phoneNumber;
                break;
            }
        } while (1);
        
//		printf("saisir nouveau numero:");
//		scanf("%ld",&new_num);
		c->liste_p[pos].numero = new_num;
		sauvegarderDansFichier(*c,"contacts.txt");
		printf("Numero modifiee avec succes !");
	}else{
		printf("%ld introuvable dans les contacts !\n",num);
	}
}
void modifier_num_par_nom(carnet *c, char nom[]){
	char num[11];
	long new_num;
	int pos = recherche_nom(*c,nom);
	if(pos != -1){
		
				        // Validation du numéro avec une longueur maximale de 10 chiffres
        do {
            printf("Saisir son nouveau numero (10 chiffres au maximum) :\t");
            scanf("%s",num);
             if (strlen(num) != 10 || num[0] != '0' ) {
                printf("Erreur de saisie, veuillez entrer un numéro valide (10 chiffres au maximum).\n");
               // printf("dans creation  %d\n",countDigits(num));
                while (getchar() != '\n'); // Vider le buffer d'entrée
            } else {
            	 // Convert the phone number string to a long
        		long phoneNumber = strtol(num, NULL, 10);
            	new_num = phoneNumber;
                break;
            }
        } while (1);
        
//		printf("saisir nouveau numero:");
//		scanf("%ld",&new_num);
		c->liste_p[pos].numero = new_num;
		sauvegarderDansFichier(*c,"contacts.txt");
		printf("Numero modifiee avec succes !");
	}else{
		printf("%S introuvable dans les contacts !\n",nom);
	}
}
// fonction pour modifier uniquement l'adresse
void modifier_adresse(carnet *c, long num){
	char new_adresse[20];
	int pos = recherche_num(*c,num);
	if(pos != -1){
		printf("saisir nouvelle adresse:");
		scanf("%s",new_adresse);
		//gets(new_adresse);
		//c->liste_p[pos].adresse = new_adresse;
		strcpy(c->liste_p[pos].adresse,new_adresse);
		sauvegarderDansFichier(*c,"contacts.txt");
		printf("\nAdresse modifiee avec succes !\n");
	}else{
		printf("%ld introuvable dans les contacts !\n",num);
	}
}

// modifier adresse par nom 

void modifier_adresse_par_nom(carnet *c, char nom[]){
	char new_adresse[20];
	int pos = recherche_nom(*c,nom);
	if(pos != -1){
		printf("saisir nouvelle adresse:");
		scanf("%s",new_adresse);
		//gets(new_adresse);
		//c->liste_p[pos].adresse = new_adresse;
		strcpy(c->liste_p[pos].adresse,new_adresse);
		sauvegarderDansFichier(*c,"contacts.txt");
		printf("\nAdresse modifiee avec succes !\n");
	}else{
		printf("%s introuvable dans les contacts !\n",nom);
	}
}

// fontion pour modifier uniquement l'email
void modifier_email(carnet *c,long num){
	char new_email[20];
	int pos = recherche_num(*c,num);
	if (pos != -1){
		
		        // Validation de l'email
        do {
            printf("Saisir son nouveau email :\t");
            if (scanf("%s", new_email) != 1 || !estEmailValide(new_email)) {
                printf("Erreur de saisie, veuillez entrer une adresse email valide.\n");
                while (getchar() != '\n'); // Vider le buffer d'entrée
            } else {
                break;
            }
        } while (1);
		
//		printf("saisir nouveau email:");
//		scanf("%s",new_email);
		strcpy(c->liste_p[pos].email,new_email);
		sauvegarderDansFichier(*c,"contacts.txt");
		printf("Email modifiee avec succes !");
	}else{
		printf("%ld introuvable dans les contacts !\n",num);
	}
}

// modifier email par nom 
void modifier_email_par_nom(carnet *c, char nom[]){
	char new_email[20];
	int pos = recherche_nom(*c,nom);
	if(pos != -1){
				        // Validation de l'email
        do {
            printf("Saisir son nouveau email :\t");
            if (scanf("%s", new_email) != 1 || !estEmailValide(new_email)) {
                printf("Erreur de saisie, veuillez entrer une adresse email valide.\n");
                while (getchar() != '\n'); // Vider le buffer d'entrée
            } else {
                break;
            }
        } while (1);
//		printf("saisir nouveau email:");
//		scanf("%s",new_email);
		strcpy(c->liste_p[pos].email,new_email);
		sauvegarderDansFichier(*c,"contacts.txt");
		printf("\nAdresse modifiee avec succes !\n");
	}else{
		printf("%s introuvable dans les contacts !\n",nom);
	}
}
// fonction pour supprimer un contact du carnet
void supprimer(carnet *c, long num){
	int i, pos;

	pos = recherche_num(*c,num);
	if (pos != -1){
		for(i=pos; i< c->nb_per-1; i++){
			c->liste_p[i] = c->liste_p[i+1]; //suppression du contact
		}
		c->nb_per--;
		sauvegarderDansFichier(*c,"contacts.txt");
		printf("Contact Supprimer avec succes !\n");
	}else{
		printf("%ld introuvable dans les contacts !\n",num);
	}
}
// fonction pour supprimer un contact du carnet par nom
void supprimer_par_nom(carnet *c, char nom[]){
	int i, pos;

	pos = recherche_nom(*c,nom);
	if (pos != -1){
		for(i=pos; i< c->nb_per-1; i++){
			c->liste_p[i] = c->liste_p[i+1]; //suppression du contact
		}
		c->nb_per--;
		sauvegarderDansFichier(*c,"contacts.txt");
		printf("Contact Supprimer avec succes !\n");
	}else{
		printf("%s introuvable dans les contacts !\n",nom);
	}
}

// affichage d'une personne donnée
void affiche_personne_d(carnet c,long num){
	personne p; int i, pos = -1;

	pos = recherche_num(c,num);
	if (pos != -1){
//		printf("nom: %s\n",p.nom);
//		printf("adresse: %s\n",p.adresse);
//		printf("numero: %ld\n",p.numero);
//		printf("email: %s\n",p.email);
        affiche_personne(c.liste_p[pos]);
	}else {
		printf("Personne a afficher introuvable !\n");
	}


}
// affichagepar nom
void affiche_personne_d(carnet c,char nom[]){
	personne p; int i, pos = -1;

	pos = recherche_nom(c,nom);
	if (pos != -1){
//		printf("nom: %s\n",p.nom);
//		printf("adresse: %s\n",p.adresse);
//		printf("numero: %ld\n",p.numero);
//		printf("email: %s\n",p.email);
        affiche_personne(c.liste_p[pos]);
	}else {
		printf("Personne a afficher introuvable !\n");
	}

}

//----------TRIE par NOM ----------
// Fonction de comparaison pour qsort par nom
int compareNoms(const void *a, const void *b) {
    return strcmp(((personne *)a)->nom, ((personne *)b)->nom);
}

// Fonction pour trier le carnet par nom
void trierParNom(carnet *c) {
    qsort(c->liste_p, c->nb_per, sizeof(personne), compareNoms);
    sauvegarderDansFichier(*c,"contacts.txt");
    printf("Contacts triees par nom avec succes.\n");
}

//-------------------TRIE par Numero-----------
// Fonction de comparaison pour qsort par numéro
int compareNumeros(const void *a, const void *b) {
    return ((personne *)a)->numero - ((personne *)b)->numero;
}

// Fonction pour trier le carnet par numéro
void trierParNumero(carnet *c) {
    qsort(c->liste_p, c->nb_per, sizeof(personne), compareNumeros);
    sauvegarderDansFichier(*c,"contacts.txt");
    printf("Contacts triees par numero avec succes.\n");
}
//---------------------------------------------

//Fonction pour sauvegarder les contacts dans un fichier

void sauvegarderDansFichier(carnet c, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w+");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    for (int i = 0; i < c.nb_per; i++) {
        fprintf(fichier, "%s %s %s %ld\n", c.liste_p[i].nom, c.liste_p[i].adresse, c.liste_p[i].email, c.liste_p[i].numero);
    }

    fclose(fichier);
//    printf("Contacts sauvegardes dans le fichier avec succes.\n");
}

//Fonction pour charger les contacts depuis un fichier



carnet carnetDuFichier(const char *nomFichier) {
    carnet c;
    FILE *fichier = fopen(nomFichier, "r");

    char nom[20] , adresse[20] , email[30];
    long numero ;
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        c.nb_per = 0;
        return c;
    }

    int i = 0;
    while (fscanf(fichier, "%s %s %s %ld",nom, adresse,email, &numero) == 4) { // == 4 patr ce que le fscanf() return le nombre de champs trouvees
        strcpy(c.liste_p[i].nom,nom);
        strcpy(c.liste_p[i].adresse,adresse);
		strcpy(c.liste_p[i].email,email);
		c.liste_p[i].numero = numero;
		
		i++;
        if (i >= maxlength) {
            break; // Limite du nombre de contacts atteinte
        }
      
    }

    c.nb_per = i;

    fclose(fichier);
//    printf("Contacts charges depuis le fichier avec succes.\n");

    return c;
}

carnet chargerDepuisFichier(const char *nomFichier) {
    carnet c;
    FILE *fichier = fopen(nomFichier, "r");

    char nom[20] , adresse[20] , email[30];
    long numero ;
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        c.nb_per = 0;
        return c;
    }

    int i = 0;
    while (fscanf(fichier, "%s %s %s %ld",nom, adresse,email, &numero) == 4) { // == 4 patr ce que le fscanf() return le nombre de champs trouvees
        strcpy(c.liste_p[i].nom,nom);
        strcpy(c.liste_p[i].adresse,adresse);
		strcpy(c.liste_p[i].email,email);
		c.liste_p[i].numero = numero;
		
		i++;
        if (i >= maxlength) {
            break; // Limite du nombre de contacts atteinte
        }
      
        printf("nom: %s | adr: %s | email: %s | numero: 0%ld \n \n", nom, adresse, email ,numero);
    }

    c.nb_per = i;

    fclose(fichier);
//    printf("Contacts charges depuis le fichier avec succes.\n");

    return c;
}


//menu
int menu(){
	int choix;

//system ("color 3F");
printf("\t\t\t\t\t GESTION DES CONTACTS \n");
printf("\t\t\t ===================================================== \n");
					printf("\t\t\t 1.Ajouter un ou plusieurs contacts:\n");
					printf("\t\t\t 2.Modifier le nom d'un contact\n");
					printf("\t\t\t 3.Modifier le numero d'un contact\n");
					printf("\t\t\t 4.Modifier l'adresse d'un contact\n");
					printf("\t\t\t 5.Modifier l'email d'un contact\n");
					printf("\t\t\t 6.Modifier toutes les informations du contact en meme temps\n");
					printf("\t\t\t 7.Afficher la liste des contacts\n");
					printf("\t\t\t 8.Afficher les informations d'un contact donnee\n");
					printf("\t\t\t 9.Supprimer un contact\n");
					printf("\t\t\t 10.Trier la liste des contacts par ordre alphabetique de nom(fonction nom dispo)\n");
//					printf("\t\t 11.Sauvegarder dans un fichier \n");
					//printf("\t\t 12.Afficher tous les contacts \n");
					printf("\t\t\t 13.QUITTER\n");
printf("\t\t\t ===================================================== \n");
printf("Entrez votre choix : ");
	scanf("%d",&choix);
	return choix;
}

int main(){
	int choix , nbr;
	long numero;
	char nom[20];
	carnet c;
	c = carnetDuFichier("contacts.txt") ; 
system ("color 3F");
	while(1){
		// Effacer l'écran
		system(CLEAR);
		choix = menu();
	switch (choix){
		case 1:
			system("color 6B");
			printf("saisir le nombre de contact que vous voulez ajouter:\t");
			scanf("%d",&nbr);
			printf("\n");
			printf("\t\t  ++++++++++AJOUT DE CONTACT++++++++++  \n");
			for(int i=0;i<nbr;i++){
				printf("personne %d:\n",i+1);
					ajouter_personne(&c,1);

			}
			//printf("Ajout Effectuee avec succes\n");
			break;
		case 2:
			
		    printf("saisir le nom actuel du contact:\t");
            scanf("%s",nom);
            printf("\n");
            printf("\t\t  ++++++++++MODIFICATION DU CONTACT++++++++++  \n");
			modifier_nom(&c,nom);
			break;

//            printf("saisir le nom actuel du contact:\n");
////            getchar(); // Pour absorber le retour chariot en attente
////            fgets(nom, sizeof(nom), stdin);
//            scanf("%s",nom);
//            printf("\t\t  ++++++++++MODIFICATION DU CONTACT++++++++++  \n");
//            modifier_nom(&c, nom);
//            printf("nom modifié avec succes !");
//            break;
		case 3:
			  printf("\t\t  1. Modifier par nom\n");
			    printf("\t\t  2. Modifier par numero\n");
			    printf("Entrez votre choix : ");
			    int choixNum;
			    scanf("%d", &choixNum);

			    switch (choixNum) {
			        case 1:
			        	printf("\nEntrez le nom du contact : ");
			        	scanf("%s",nom);
			            modifier_num_par_nom(&c,nom); 
			            break;
			        case 2: 
			        	printf("\nEntrez le numero du contact : ");
			        	scanf("%ld",&numero);
			            modifier_num(&c,numero); 
			            break; 
			        default:
			            printf("Choix invalide.\n");
			            break;
			    }
			    break; 
			break;
		case 4:
				 printf("\t\t  1. Modifier par nom\n");
			    printf("\t\t  2. Modifier par numero\n");
			    printf("Entrez votre choix : ");
			    int choixadr;
			    scanf("%d", &choixadr);

			    switch (choixadr) {
			        case 1:
			        	printf("\nEntrez le nom du contact : ");
			        	scanf("%s",nom);
			            modifier_adresse_par_nom(&c,nom);
			            break;
			        case 2: 
			        	printf("\nEntrez le numero du contact : ");
			        	scanf("%ld",&numero);
			            modifier_adresse(&c,numero);
			            break; 
			        default:
			            printf("Choix invalide.\n");
			            break;
			    }
			    break; 
//			printf("saisir son numero:\t");
//			scanf("%ld",&numero);
//			printf("\n");
//			printf("VOICI LES INFORMATIONS ACTUELLE DE LA PERSONNE \n ");
//			affiche_personne_d(c,numero);
//			printf("\t\t  ++++++++++MODIFICATION De L'ADRESSE++++++++++  \n");
//			modifier_adresse(&c,numero);
//			affiche_personne_d(c,numero);
		//	break;
		case 5:
				 printf("\t\t  1. Modifier par nom\n");
			    printf("\t\t  2. Modifier par numero\n");
			    printf("Entrez votre choix : ");
			    int choixemail;
			    scanf("%d", &choixemail);

			    switch (choixemail) {
			        case 1:
			        	printf("\nEntrez le nom du contact : ");
			        	scanf("%s",nom);
			            modifier_email_par_nom(&c,nom);
			            break;
			        case 2: 
			        	printf("\nEntrez le numero du contact : ");
			        	scanf("%ld",&numero);
			            modifier_email(&c,numero);
			            break; 
			        default:
			            printf("Choix invalide.\n");
			            break;
			    }
			    break;
//			printf("saisir son numero:\t");
//			scanf("%ld",&numero);
//			printf("\n");
//			printf("VOICI LES INFORMATIONS ACTUELLE DE LA PERSONNE \n ");
//			affiche_personne_d(c,numero);
//			printf("\t\t  ++++++++++MODIFICATION De L'EMAIL++++++++++  \n");
//			modifier_email(&c,numero);
//			affiche_personne_d(c,numero);
//			break;
		case 6:
				printf("\t\t  1. Modifier par nom\n");
			    printf("\t\t  2. Modifier par numero\n");
			    printf("Entrez votre choix : ");
			    int choixall;
			    scanf("%d", &choixall);

			    switch (choixall) {
			        case 1:
			        	printf("\nEntrez le nom du contact : ");
			        	scanf("%s",nom);
			            modifier_infos_par_nom(&c,nom);
			            break;
			        case 2: 
			        	printf("\nEntrez le numero du contact : ");
			        	scanf("%ld",&numero);
			            modifier_par_num(&c,numero);
			            break; 
			        default:
			            printf("Choix invalide.\n");
			            break;
			    }
			    break;
//			printf("saisir son numero:\t");
//			scanf("%ld",&numero);
//			printf("\n");
//			printf("VOICI LES INFORMATIONS ACTUELLE DE LA PERSONNE \n ");
//			affiche_personne_d(c,numero);
//			printf("\t\t  ++++++++++MODIFICATION De Toutes Les INFORMATIONS ++++++++++  \n");
//			modifier_par_num(&c,numero);
//			break;
		case 7:
            printf("\t\t  ++++++++++ LISTE DES CONTACTS DU CARNET ++++++++++  \n");
 		    c = chargerDepuisFichier("contacts.txt");
			break;

		case 8:
			printf("\t\t  ++++++++++ AFFICHER Les INFORMATIONS D'une PERSONNE DONNEE ++++++++++  \n");
			printf("saisir son numero:\t");
			scanf("%ld",&numero);
			printf("\n");
			affiche_personne_d(c,numero);
			break;
		case 9:
			system("color 4A");
			printf("\t\t  ++++++++++ SUPRESSION DE CONTACT ++++++++++  \n");
				printf("\t\t  1. suppression par nom\n");
			    printf("\t\t  2. suppression par numero\n");
			    printf("Entrez votre choix : ");
			    int choixsup;
			    scanf("%d", &choixsup);

			    switch (choixsup) {
			        case 1:
			        	printf("\nEntrez le nom du contact : ");
			        	scanf("%s",nom);
			            supprimer_par_nom(&c,nom);
			            break;
			        case 2: 
			        	printf("\nEntrez le numero du contact : ");
			        	scanf("%ld",&numero);
			            supprimer(&c,numero);
			            break; 
			        default:
			            printf("Choix invalide.\n");
			            break;
			    }
			    break;
//			printf("saisir son numero:\n");
//			scanf("%ld",&numero);
//			supprimer(&c,numero);
//			break;
		case 10:
						    printf("\t\t  ++++++++++ TRIER LES CONTACTS ++++++++++  \n");
			    printf("\t\t  1. Trier par nom\n");
			    printf("\t\t  2. Trier par numero\n");
			    printf("\t\t  3. Retourner au menu principal\n");
			    printf("Entrez votre choix : ");
			    int choixTri;
			    scanf("%d", &choixTri);

			    switch (choixTri) {
			        case 1:
			            trierParNom(&c);
			           // affiche_complet(c);
			            c = chargerDepuisFichier("contacts.txt");
			            break;
			        case 2:
			            trierParNumero(&c);
			            //affiche_complet(c);
			             c = chargerDepuisFichier("contacts.txt");
			            break;
			        case 3:
			            // Retourner au menu principal
			            break;
			        default:
			            printf("Choix invalide.\n");
			            break;
			    }
			    break;
//		case 11: // Nouvelle option pour sauvegarder dans un fichier
//		    printf("\t\t  ++++++++++ SAUVEGARDER DANS UN FICHIER ++++++++++  \n");
//		    sauvegarderDansFichier(c, "contacts.txt");
//		    break;
		case 13:
		    printf("Au revoir! Vous avez quitter le programme.\n");
		    exit(0); //Quitter le programme
		    break;
		default:
			printf("Saisir un nombre entre 1 et 13 :\n");
			break;
	}

	        // Attendre une entrée de l'utilisateur avant de continuer
        printf("\nAppuyez sur Entree pour revenir au menu principal...");
        getchar(); // Capture le retour à la ligne précédent
        getchar(); // Capture l'entrée de l'utilisateur

  }
	return 0;
}
