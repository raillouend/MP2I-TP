#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double moyenne(double *tab, int n) {
	double somme = 0;
	for (int i = 0; i<n; i++) {
		somme += tab[i];
	}
	return (double) somme / n;
}

double variance(double* tab, int n) {
	double moy = moyenne(tab, n);
	double var = 0;
	for (int i = 0; i<n; i++) {
		var += (moy-tab[i]) * (moy-tab[i]);
	}
	return (double) var/n;
}

int main() {
	double tab0[] = {2, 5, 5};
	double tab1[] = {3, 8, 7, -2, -1};
	double tab2[] = {6};
	double tab3[] = {2.2, 8.2, 2.2};
	assert(moyenne(tab0, 3) == 4.0);
	assert(moyenne(tab1, 5) == 3.0);
	assert(moyenne(tab2, 1) == 6.0);
	printf("%f\n", moyenne(tab3, 3));
	/*assert(moyenne(tab3, 3) == 4.2); Bonne valeur mais problème au niveau de la condition*/

	double tab4[] = {4.};
	double tab5[] = {1., 2., 3., 4., 5.};
	assert(variance(tab4, 1) == 0.0);
	assert(variance(tab5, 5) == 2.0);

	return 0;
}
