#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool cherche_element(int* tab, int n, int elt) {
	bool present = 0;
	for (int i = 0; i<n; i++) {
		if (tab[i] == elt) {
			present = 1;
		}
	}
	return present;
}

int indice_element(int *tab, int n, int elt) {
	for (int i = 0; i<n; i++) {
		if (tab[i] == elt) {
			return i;
		}
	}
	return n;
}

int nombre_occurrences(int* tab, int n, int elt) {
	int occurences = 0;
	for (int i = 0; i<n; i++) {
		if (tab[i] == elt) {
			occurences += 1;
		}
	}
	return occurences;
}

int main() {
	int tab0[] = {2, 5, 7};
	int tab1[] = {3, 1, -1, 3, 8};
	int tab2[] = {};
	assert(!cherche_element(tab0, 3, 3));
	assert(cherche_element(tab0, 3, 7));
	assert(cherche_element(tab0, 3, 5));
	assert(cherche_element(tab0, 3, 2));
	assert(cherche_element(tab1, 5, 3));
	assert(!cherche_element(tab1, 5, 7));
	for (int i=0; i<10; i++) {
		assert(!cherche_element(tab2, 0, i));
	}

	assert(indice_element(tab0, 3, 3) == 3);
	assert(indice_element(tab0, 3, 7) == 2);
	assert(indice_element(tab0, 3, 2) == 0);
	assert(indice_element(tab1, 5, 3) == 0);
	assert(indice_element(tab1, 5, -1) == 2);
	assert(indice_element(tab1, 5, 8) == 4);
	assert(indice_element(tab1, 5, 7) == 5);
	assert(indice_element(tab2, 0, 11) == 0);

	assert(nombre_occurrences(tab0, 3, 3) == 0);
	assert(nombre_occurrences(tab0, 3, 7) == 1);
	assert(nombre_occurrences(tab1, 5, 3) == 2);
	assert(nombre_occurrences(tab2, 0, 8) == 0);
	
	return 0;
}

