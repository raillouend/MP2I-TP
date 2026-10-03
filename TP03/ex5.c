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

int main() {
	int tab0[] = {3, 8, -1, 7, 9, 4};
	int tab1[] = {3, 8, -1, 7, 8, 4};
	int tab2[] = {-3};
	int tab3[] = {5, 3, 11};
	int tab4[] = {23, 6, -2, 7};
	
	assert(maximum(tab0, 6) == 9);
	assert(maximum(tab1, 6) == 8);
	assert(maximum(tab2, 1) == -3);
	assert(maximum(tab3, 3) == 11);
	assert(maximum(tab4, 4) == 23);

	assert(indice_maxi(tab0, 6) == 4);
	assert(indice_maxi(tab1, 6) == 1);
	assert(indice_maxi(tab2, 1) == 0);
	assert(indice_maxi(tab3, 3) == 2);
	assert(indice_maxi(tab4, 4) == 0);
	
	return 0;
}
