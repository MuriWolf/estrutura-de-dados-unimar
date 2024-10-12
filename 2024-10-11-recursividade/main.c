#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int somatoria_recursiva(int n) {
	if (n == 0) {
		return n;
	}
	else {
		return n + somatoria_recursiva(n - 1);
	}
}

int potencia_recursiva(int n, int m) {
	if (m == 1) {
		return n;
	}
	else {
		return n * potencia_recursiva(n, m - 1);
	}
}

int main() {

	printf("%d\n", somatoria_recursiva(10));

	printf("\n%d\n", potencia_recursiva(2, 3));

	return 0;
}