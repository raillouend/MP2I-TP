#include <stdio.h>

int main(){

	char* a = "salut";
	printf("a vaut %p où se trouve la chaîne %s.\n", a, a);
	
	//copie de la chaine vers laquelle pointe a à la main
	char b[6];
	int i=0;
	while(i < 6){
		b[i] = a[i];
		i++;
	}
	printf("b vaut %p où se trouve la chaîne %s.\n", b, b);

	printf("(a == b) = %s \n", a == b ? "true" : "false");

	return 0;
}
