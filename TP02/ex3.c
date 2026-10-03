#include <stdio.h>
#include <stdlib.h>

int main() {

	/* Tableau des entiers entre 1 et 100 */
	int* entiers = (int*) malloc(100 * sizeof(int));

	for (int i = 0; i<100; i++) {
		entiers[i] = i+1;
		printf("%d\n", entiers[i]);
	}
	
	/* Double du tableau */
	int tab[] = {2, 5, 12, 31, 2, 17, 31, 42, 2};
	
	int* doubles = (int*) malloc(9*sizeof(int));
	for (int i = 0; i<9; i++) {
		doubles[i] = tab[i]*2;
		printf("%d\n", doubles[i]);
	}

	/* Elements pairs */	
	int* pairs = (int*) malloc(9*sizeof(int));
	int curseur = 0;
	for (int i = 0; i<9; i++) {
		if (tab[i]%2 == 0) {
			pairs[curseur] = tab[i];
			printf("%d\n", pairs[curseur]);
			curseur++;
		}
	}

	/* Chiffres décimaux */
	

	/* Alphabet */
	char* alphabet = (char*) malloc(26*sizeof(char));
	for (int i = 0; i<26; i++) {
		alphabet[i] = 'A'+i;
		printf("%c\n", alphabet[i]);
	}


	return 0;
}
