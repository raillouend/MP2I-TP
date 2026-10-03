#include <stdio.h>
#include <stdlib.h>


int lit_ligne(char* s, int nbc_max){
//hyp : nbc_max >= 0 
//hyp : s pointe vers une zone mémoire de nbc_max octets

//lit la première ligne du flux stdin et la copie dans s
//sans le \n et ds la limite de nbc_max caractères  
//retourne la taille de cette ligne en nb de caractères 
//donc 0 pour "\n" et -1 si celle-ci était réduite à EOF 

	int i = 0;	
	char c = getchar();
	
	//c est le caractère d'indice i de la ligne qu'on lit
	//s contient i caractères donc s[i] n'est pas encore initialisé
	while ( (i < nbc_max) && (c != EOF) && (c != '\n') ){
		s[i] = c;
		i = i + 1;
		c = getchar();
	}
	
	s[i] = '\0';
	if (c == EOF){
		i = i - 1;
	}
	
	return i;	
}


int main(){

	int nbc_max = 256;
	int nbl_max = 1024;
	printf("On lit au plus %d carcatères par lignes, et au plus %d lignes.\n", nbc_max, nbl_max);
	
	char l1[nbc_max+1];
	//+1 pour le caractère nul en fin de chaîne
	int lg_l1 = lit_ligne(l1,nbc_max);
	printf("la première ligne (de longueur %d) est :\n%s\n",lg_l1,l1);
	
	return 0;
}
