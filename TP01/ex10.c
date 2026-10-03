#include <stdio.h>

int puissance(int n, int p) {
	int a = 1;

	for (int i = 1; i <= p; i++) {
		a *= n;
	}
	return a;
}

int somme(int M) {
	int a = 1;
	int i = 1;
	
	while (a<M) {
		i += 1;
		a += puissance(i, 4);
	}

	return i;
}

int main() {
	int M = 100;
	printf("Pour M = %d\n", M);
	printf("1⁴+2⁴+...+n⁴>=M quand n = %d\n", somme(M));
}
