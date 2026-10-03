#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int longueur (char* s) { //copiez ici votre code de fonction longueur
	int l = 0;
	while (s[l] != '\0') {
		l++;
	}
	return l;
}


char* copie_bete (char* s){
//crée une chaine copie de s et renvoie son adresse
	int l = longueur(s);
	char copie[l+1];
	
	int i=0;
	while(i<l+1){ // Mais pourquoi encore l + 1 ???
		copie[i]=s[i];
		i++;
	}
	
	return copie;
}

char* copie(char* s) {
	int l = longueur(s);
	char* copie = (char*) malloc(l*sizeof(char));
	
	int i=0;
	while(i<l+1){
		copie[i]=s[i];
		i++;
	}
	
	return copie;
}

int main(){

	char* a = "salut";
	printf("a vaut %p où se trouve la chaine %s\n", a, a);
	
	char* cp1 = copie(a);
	printf("cp1 vaut %p où se trouve la chaine %s\n", cp1, cp1);
	
	free(cp1);

	return 0;
}
