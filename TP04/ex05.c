#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* tableau_somme(int n1, int n2, int tab[n1][n2]) {
	int* tab_somme = (int*) malloc(n1 * sizeof(int));
	
	for (int i = 0; i < n1; i++) {
		int somme = 0;
		for (int j = 0; j < n2; j++) {
			somme += tab[i][j];
		}
		tab_somme[i] = somme;
	}

	return tab_somme;
}

int main() {
	int tab1[5][2] = {{2,3}, {4,5}, {6,7}, {8,9}, {1,2}};
        int tab2[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

        int* res1 = tableau_somme(5, 2, tab1);
        int* res2 = tableau_somme(3, 4, tab2);

	for (int i = 0; i < 5; i++) {
                printf("%d\n", res1[i]);
        }
	
	for (int i = 0; i < 3; i++) {
                printf("%d\n", res2[i]);
        }

	free(res1);
	free(res2);

	return 0;
}
