#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int maximum(int *tableau, int n) {
	int max = tableau[0];
	for (int i = 0; i<n; i++) {
		if (max< tableau[i]) {
			max = tableau[i];
		}
	}

	return max;
}

int indice_maxi(int* tab, int n) {
	int max = tab[0];
	int indice = 0;

	for (int i = 0; i<n; i++) {
		if (max < tab[i]) {
			max = tab[i];
			indice = i;
		}
	}

	return indice;
}

int deuxieme_plus_grand(int *tableau, int n) {
	int max1 = tableau[0];
	int max2 = tableau[1];
	for (int i = 0; i<n; i++) {
		if (max1< tableau[i]) {
			max2 = max1;
			max1 = tableau[i];
		}
	}

	return max2;
}

int indice_deuxieme_plus_grand(int *tab, int n) {
	int max1 = tab[0];
	int max2 = tab[1];

	int indice1 = 0;
	int indice2 = 1;

	for (int i = 0; i<n; i++) {
		if (max1 < tab[i]) {
			max2 = max1;
			max1 = tab[i];
			indice2 = indice1;
			indice1 = i;
		}
	}

	return indice2;
}

int main() {
	int tab0[] = {3, 8, -1, 7, 9, 4};
	int tab1[] = {3, 8, -1, 7, 8, 4};
	int tab2[] = {-3};
	int tab3[] = {5, 3, 11};
	int tab4[] = {23, 6, -2, 7};
	
	assert(
	int indice = 0;
== 9);
	assert(maximum(tab1, 6) == 8);
	assert(maximum(tab2, 1) == -3);
	assert(maximum(tab3, 3) == 11);
	assert(maximum(tab4, 4) == 23);

	assert(indice_maxi(tab0, 6) == 4);
	assert(indice_maxi(tab1, 6) == 1);
	assert(indice_maxi(tab2, 1) == 0);
	assert(indice_maxi(tab3, 3) == 2);
	assert(indice_maxi(tab4, 4) == 0);
	
	int tab5[] = {-5, -7};
	int tab6[] = {7, 5, -2, 3, 7, 6, 5, 4, 7, 2, 7, 3};
	
	assert(deuxieme_plus_grand(tab0, 6) == 8);
	assert(indice_deuxieme_plus_grand(tab0, 6) == 1);
	assert(deuxieme_plus_grand(tab1, 6) == 8);
	assert(indice_deuxieme_plus_grand(tab1, 6) == 4);
	assert(deuxieme_plus_grand(tab3, 3) == 5);
	assert(indice_deuxieme_plus_grand(tab3, 3) == 0);
	assert(deuxieme_plus_grand(tab4, 4) == 7);
	assert(indice_deuxieme_plus_grand(tab4, 4) == 3);

	assert(deuxieme_plus_grand(tab5, 2) == -7);
	assert(indice_deuxieme_plus_grand(tab5, 2) == 1);
	assert(deuxieme_plus_grand(tab6, 12) == 7);
	assert(indice_deuxieme_plus_grand(tab6, 12) == 4);

	return 0;
}
