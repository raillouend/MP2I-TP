#include <stdio.h>
#include <stdlib.h>

void print_tab(int* tab) {
	for (int i = 0; i<10; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");
}

int main() {
	int* tab = (int*) malloc(10*sizeof(int));
	for (int i = 0; i<10; i++) {
		tab[i] = 0;
	}
	
	print_tab(tab);
	tab[9] = -5;
	print_tab(tab);

	for (int i = 0; i<10; i++) {
		tab[i] = 1;
	}
	
	print_tab(tab);

	int* tab2 = tab;
	
	tab2[0] = 10;

	print_tab(tab);
	print_tab(tab2);

	return 0;
}
