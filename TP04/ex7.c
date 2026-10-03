#include <stdio.h>
#include <stdlib.h>


void copie_bis(char* tab1, char* tab2, int n) {
	for (int i = 0; i<n; i++) {
		tab2[i] = tab1[i];
	}
}



int main() {

	char tab1[8] = "Bonjour";
	char tab2[8] = "1234567";
	
	printf("%s\n", tab2);
	
	copie_bis(tab1, tab2, 8);
	
	printf("%s\n", tab2);

	return 0;
}
