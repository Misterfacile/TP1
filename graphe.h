

#ifndef GRAPHE_H_
#define GRAPHE_H_


void marquerVoisin(int **adjacence , int ordre, int s);
void afficheVoisinMarque(int *t, int ordre, int s);
void allouerTableau2(int** t, int n);
void afficherMatrice(int *t, int n);
void afficherMatrice2D(int **t, int l);
void adjacence(int* t,int noeud2);
void adjacence2D(int **t,int noeud1, int noeud2);
void afficheVoisin(int *t, int n);
void chargeGraphe(int **t, int ordre);
void chargeExercice();
#endif /* GRAPHE_H_ */
