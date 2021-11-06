#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"


void afficheVoisinMarque(int *t, int ordre, int s){
	printf("Sommet marqué selon le sommet %d : ",s);
	for(int i =0 ; i < ordre ; i++){
		if(t[i]==1){
			printf("(%d) ", i+1);
		}
	}
}
void marquerVoisin(int **adjacence , int ordre, int s){
	int *marques;
	int x,y;

	marques = (int*) malloc(ordre * sizeof(int));
	/*
	for(x=0;x<ordre;x++){
		marques[x] =  (int*) malloc(sizeof(int));

	}
	*/
	for(x=0;x<ordre;x++){
			marques[x] = 0;
		}
	marques[s-1] = 1;
	for(x=0;x<ordre;x++){
		if(marques[x]){
			for(y=0;y<ordre;y++){
				if(adjacence[x][y] && !marques[y]){
					marques[y] = 1;
				}
			}
		}
	}
	afficheVoisinMarque(marques,ordre,s);
}

void allouerTableau2(int** t, int n) {
	*t = (int*) malloc(n * sizeof(int));
}



void afficherMatrice(int *t, int n){
	int i = 0;
	for(i = 0; i<n; i++ ){
		printf("%d\t ", t[i]);
	}
}
void afficherMatrice2D(int **t, int l){
	int i;
	for(i = 0; i<l ; i++){
		afficherMatrice(t[i], l);
		printf("\n");
	}
}

void adjacence(int* t,int noeud2){
	t[noeud2-1] = 1;
}

void adjacence2D(int **t,int noeud1, int noeud2){
	adjacence(t[noeud1-1],noeud2);
	adjacence(t[noeud2-1],noeud1);
}

void afficheVoisin(int *t, int n){
	int i = 0;
	for(i = 0; i<n; i++ ){
		if(t[i]== 1){
			printf("(%d) ", i+1);
		}
	}
	printf("\n");
}
void chargeGraphe(int **t, int ordre){
	for(int i =0; i<ordre; i++){
		printf("(%d) : ",i+1);
		afficheVoisin(t[i],ordre);
	}
}

void chargeExercice(){
	printf("Tapez le nombre de noeud dans le graphe : ");
			int ordre;
			scanf("%d",&ordre);
			int **adjacence = NULL ;
			// Alloue les lignes de la matrice
			adjacence = (int**) malloc(ordre * sizeof(int*));

			// Alloue les colonnes de la matrice
			for(int i=0;i < ordre; i++){
				allouerTableau2(&(adjacence[i]), ordre);
			}

			int choix;
			int noeud1;
			int noeud2;
			do{
				printf("---Menu---\n");
				printf("1- Ajouter un voisin \n");
				printf("0- Initialisation de la matrice \n");
				printf("Votre choix : ");
				scanf("%d",&choix);
				if(choix == 1){

					do{
						printf("Quel noeud a un voisin ? : ");
					    scanf("%d",&noeud1);
					    if(noeud1 > ordre || noeud1< 0){
					    	printf("Le noeud n'existe pas \n");
					    }
					}while(noeud1>ordre || noeud1 < 0);
					do{
						printf("Avec quel noeud ? : ");
					    scanf("%d",&noeud2);
					    if(noeud2>ordre || noeud2 < 0){
					    printf("Le noeud n'existe pas \n");
					    }else if(noeud1 == noeud2){
					    	printf("Un noeud ne peut être voisin de lui-même \n");
					    }
					}while(noeud2>ordre || noeud2 < 0 || noeud1 == noeud2);
					adjacence2D(adjacence,noeud1,noeud2);

				}else if(choix != 0){
					printf("\nChoix incorrecte \n");
				}
			}while(choix !=0);
			afficherMatrice2D(adjacence,ordre);
			printf("---------- Affichage Graphe format (Sommet) : (voisin1)  (voisin2) ---------- \n");
			chargeGraphe(adjacence,ordre);

			int ref;
			do{
				printf("Donner un sommet de référence pour le marquage des voisin : ");
				scanf("%d",&ref);
				if(ref > ordre || ref < 0){
					printf("Ce sommet n'est pas dans le graphe !! ");
				}
			}while(ref > ordre || ref < 0);
			marquerVoisin(adjacence,ordre,ref);
}


