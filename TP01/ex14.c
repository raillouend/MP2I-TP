#include <stdio.h>
#include <stdbool.h>

int racine_entiere(int a) {
	int n = 0;

	while (n*n <= a) {
		n += 1;
	}

	return n-1;
}

bool divise(int a, int b) {
	return b%a == 0;
}

bool est_premier(int a) {
	/* Cette fonction fais au maximum a comparaisons de reste.
	 * Ce nombre est réductible si l'on ne cherche la divisibilité de a qu'avec des nombres premiers.*/
	bool premier = 1;
	for (int i = 2; i < a; i++) {
		if (divise(i, a)) {
			premier = 0;
		}
	}
	return premier;
}

int main() {
	
}
