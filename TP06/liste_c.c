#include <stdio.h>
#include <stdlib.h>

#define type_elem int // modifier affiche_liste en conséquent

struct cellule_s {
	type_elem val;
	struct cellule_s* suivante;
};



typedef struct cellule_s cellule;
typedef cellule* liste_c;

liste_c creer_cellule(type_elem v) {
	liste_c c = (liste_c) malloc(sizeof(cellule));
	c->val = v;
	c->suivante = NULL;
	
	

	return c;
}

void affiche_elem(cellule* l) {
	printf("%d ", l->val);
}

void affiche_liste(cellule* l) {
	while (l != NULL) {
		affiche_elem(l);
		l = l->suivante;
	}
	printf("\n");
}

cellule* creer_depuis_tableau(type_elem* tab, int n) {
	liste_c c = creer_cellule(tab[0]); // Premier élement
	liste_c c1 = c; // element que l'on vas modifier
	for (int i = 1; i<n; i++) {
		c1-> suivante = creer_cellule(tab[i]);
		c1 = c1->suivante;
	}
	return c;
}

void liberer_liste_c(liste_c l) {
	liste_c c1 = l;
	liste_c c2 = l->suivante;
	free(c1);
	while (c2 != NULL) {
		c1 = c2;
		c2 = c1->suivante;
		free(c1);
	}
}

int nb_elem(liste_c l) {
	int nb = 0;
	while (l != NULL) {
		nb++;
		l = l->suivante;
	}
	return nb;
}
	
int main() {
	int tab[4] = {5, 6, 7, 657};
	liste_c c1 = creer_depuis_tableau(tab, 4);

	affiche_liste(c1);
	printf("Le nombre d'élement est : %d\n", nb_elem(c1));
	liberer_liste_c(c1);
	
	affiche_liste(c1); // affiche Erreur de segmentation (core dumped)

	return 0;
}
