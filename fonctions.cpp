#include<stdio.h>

// ==== MENU ====== //
char menu(){
	char choix;
	
	printf("---------MENU---------\n");
	
	printf("A- Saisie et affichage\n");
	printf("B- Moyenne\n");
	printf("C- Suppression du Max et affichage\n");
	printf("D- Suppression du Min et affichage\n");
	printf("E- Ajout d'un entier à une position donnée \n");
	printf("Q- Quitter\n");
	
	scanf(" %c",&choix);
	
	
	
	return choix;
}

// ================================== =================================== //
void affichage(int tab[],int n){
	int i;
	
	for(i=0;i<n;i++){
		printf("[%d]",tab[i]);
	}
	printf("\n");
}

// ================================== =================================== //
void affichagefloat(float tab[],int n){
	int i;
	
	for(i=0;i<n;i++){
		printf("[%.2f]",tab[i]);
	}
	printf("\n");
}

// ================================== =================================== //
void saisie(int tab[], int* n){
	
	int i;
	
//	printf("saisir le nombre d'elts du tableau:\n");
//	scanf("%d",n);
	
	for(i=0;i<(*n);i++){
		printf("saisir l'elt [%d]=",i+1);
		scanf("%d",&tab[i]);
	}
}

// ================================== =================================== //
void saisiefloat(float tab[], int* n){
	
	int i;
//	
//	printf("saisir le nombre d'elts du tableau:\n");
//	scanf("%d",n);
	
	for(i=0;i<(*n);i++){
		printf("saisir l'elt [%d]=",i+1);
		scanf("%.2f",&tab[i]);
	}
}

// ================================== =================================== //
void moyenne(int tab[],int n){
	
	float  moy=0;
    int i, s = 0;
	for(i=0;i<n;i++){
		s = s + tab[i];
	}	
	moy = s/n;
	printf("La moyenne des elts du tableau est = %.2f\n",moy);
	printf("\n");
}

// ================================== =================================== //
void moyennefloat(float tab[],int n){
	
	float s=0, moy=0;
    int i;
	for(i=0;i<n;i++){
		s = s + tab[i];
	}	
	moy = s/n;
	printf("La moyenne des elts du tableau est = %.2f\n",moy);
	printf("\n");
}

// ================================== =================================== //
int rechercheposMax(int tab[],int n){
	int i,posmax=-1,max;
	
	max = tab[0];
	for(i=1;i<n;i++){
		if (tab[i]>max){
			max = tab[i];
			posmax = i;
		}
	}
	 return posmax;
}

// ================================== =================================== //
int rechercheMax(int tab[],int n){
	int i,max;
	
	max = tab[0];
	for(i=1;i<n;i++){
		if (tab[i]>max){
			max = tab[i];
		}
	}
	 return max;
}

// ================================== =================================== //
int rechercheposMin(int tab[],int n){
	int i,posmin=-1,min;
	
	min = tab[0];
	for(i=1;i<n;i++){
		if (tab[i]<min){
			min = tab[i];
			posmin = i;
		}
	}
	 return posmin;
}

// ================================== =================================== //
void suppressionMax(int tab[],int n){ //sans tableau d'aide 
	int i,max;
	int deb=0, fin=n-1,temp;
	
	max = rechercheMax(tab,n);
	
	while(deb < fin){
		if(tab[deb] == max){
			temp = tab[deb];
		tab[deb] = tab[fin];
		tab[fin] = temp;
		fin--; 
		}else {
			deb++;
		}
	}
	printf("Apres suppression du max:\n");
	for(i=0;i<=fin;i++){
		printf("[%d]",tab[i]);
	}
	printf("\n");
}

// ================================== =================================== //
void suppressiontabaide(int tab[],int n){ //avec tableau d'aide
	int max,i,j=0,taille=1;
	
	max = rechercheMax(tab,n);
	int tabaide[n];
	
	for(i=0;i<n;i++){
		if(max != tab[i]){
			tabaide[j] = tab[i];
			j++;
			taille++;
		}
	}
	for(j=0;j<taille-1;j++){
		printf("[%d]",tabaide[j]);
	}
}

// ================================== =================================== //
int rechercheMin(int tab[],int n){
	int i,min;
	
	min = tab[0];
	
	for(i=0;i<n;i++){
		if(tab[i]<=min){
			min = tab[i];
		}
	}
	return min;
}

// ================================== =================================== //
void suppressionMin(int tab[],int n){
    int i,min;
	int deb=0, fin=n-1,temp;
	
	min = rechercheMin(tab,n);
	
	while(deb < fin){
		if(tab[deb] == min){
			temp = tab[deb];
		    tab[deb] = tab[fin];
		    tab[fin] = temp;
		    fin--; 
		}else {
			deb++;
		}
	}
	printf("Apres suppression du min:\n");
	for(i=0;i<=fin;i++){
		printf("[%d]",tab[i]);
	}	
	printf("\n");
}

// ================================== =================================== //
void ajout(int tab[],int n){
	int i,val,pos;
	
	do{
		printf("saisir la valeur a ajouter au tableau:\n");
		scanf("%d",&val);
		printf("saisir la position a laquelle vous voulez ajouter l'elt:(pos < a la taille du tableau )\n");
		scanf("%d",&pos);
	}while(pos < n);
	
	for(i=n;i>pos;i--){
		tab[i] = tab[i-1];
	}
    tab[pos] = val;
	//affichage du tableau apres ajout
	for(i=0;i<=n;i++){
		printf("[%d]",tab[i]);
	}
	printf("\n");
}

// ================================== =================================== //
void longueurChaine(char cTab[]){
	int cpt=0,i=0;
	
	while(cTab[i] != '\0'){
		i++;
		cpt++;
	}
	printf("la longueur de la chaine est :%d\n",cpt);
}

// ================================== =================================== //



