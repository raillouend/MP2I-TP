#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int* negatif(int *tab, int n) {
	if (n == 0) {
		return NULL;
	}
	int* neg = (int*) malloc(n * sizeof(int));
	for (int i = 0; i<n; i++) {
		neg[i] = 255-tab[i];
	}
	return neg;
}

int main() {
	int img0[] = {0, 100, 200, 150, 125};
	int img1[] = {10, 25, 33, 101};
	int img2[] = {};
	int neg0[] = {255, 155, 55, 105, 130};
	int neg1[] = {245, 230, 222, 154};
	int *res0 = negatif(img0, 5);
	int *res1 = negatif(img1, 4);
	int *res2 = negatif(img2, 0);
	int i = 0;
	while (i < 4) {
		assert(neg0[i] == res0[i]);
		assert(neg1[i] == res1[i]);
		i++;
	}
	assert(neg0[4] == res0[4]);
	assert(res2 == NULL);

	return 0;
}
