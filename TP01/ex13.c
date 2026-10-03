#include <stdio.h>

int prochain_syracuse(int Un) {
	if (Un%2 == 0) {
		return Un/2;
	} else {
		return 3*Un + 1;
	}
}

int terme_syracuse(int x, int n) {
	int Un = x;
	for (int i = 1; i <= n; i++) {
		Un = prochain_syracuse(Un);
	}
	return Un;
}

int duree_vol(int x) {
	int Un = x;
	int n = 0;
	while (Un != 1) {
		Un = prochain_syracuse(Un);
		n += 1;
	}

	return n;
}

int plus_long_vol(int n) {
	int plus_long = 0;
	for (int i = 1; i <= n; i++) {
		if (duree_vol(i) > plus_long) {
			plus_long = duree_vol(i);
		}
	}

	return plus_long;
}

int main() {
	
	
}

