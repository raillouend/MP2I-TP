#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	printf("\n");

	return 0;
}
