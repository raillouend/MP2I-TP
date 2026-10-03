#include <stdio.h>
/* Je pensais qu'un algorythme recursif allais être moins long
 * après avoir écris ce programme je me suis rendu compte que non.
 * Je donc trouvé pertinent de le laisser*/

int marche(int n) {
	if (n == 0) {
		printf("|");
		return 0;
	} else {
		marche(n-1);
		printf("--|");
		return 0;
	}
}

int escalier_recursif(int n) {
	if (n == 0) {
		printf("----\n");
		return 0;
	} else {
		escalier_recursif(n-1);
		marche(n);
		printf("----\n");
		return 0;
	}
}
void escalier(int n) {
	for (int ligne = 0; ligne<=n; ligne++) {
		if (ligne>0) {
			printf("|");
		}
		for (int colonne = 0; colonne < ligne; colonne++) {
			printf("--|");
		}
		printf("----\n");
	}
}

int main() {
	int n;

	printf("Entrez le nombre de marche de l'escalier :\n");
	scanf("%d", &n);

	escalier(n);

	escalier_recursif(n);
}
