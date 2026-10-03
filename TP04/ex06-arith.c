#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int* nombre = (int*) malloc(argc * sizeof(int));
	int compteur = 1;
	int resultat = atoi(argv[1]);

	for (int i = 1; i < argc; i++) {
		if (argv[i] == "+") {
			resultat += nombre[compteur];
			compteur += 1;
		} else if (argv[i] == "x") {
			resultat *= nombre[compteur];
			compteur += 1;
		} else {
			nombre[i+1] = atoi(argv[i]);
		}
	}

	printf("%d\n", resultat);	
	
	free(nombre);

	return 0;
}
