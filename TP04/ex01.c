#include <stdio.h>
#include <assert.h>

int longueur(char* str) {
	int l = 0;
	while (str[l] != '\0') {
		l++;
	}
	return l;
}
		
void epele(char* str) {
	for (int i = 0; i<longueur(str); i++) {
		if (str[i] == ' ') {
			printf("espace\n");
		} else if(str[i] == '\t') {
			printf("tabulation\n");
		} else if(str[i] == '\t') {
			printf("à la ligne\n");
		} else {
			printf("%c\n", str[i]);
		}
	}
}

int main() {
	
	assert(longueur("") == 0);
	assert(longueur("mp2i") == 4);
	
	epele("Tes chaud 	bravo\n");
	
	return 0;
}
