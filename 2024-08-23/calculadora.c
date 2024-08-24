
#include <stdio.h>

int somar(int n1, int n2) {
	return n1 + n2;
}

int subtrair(int n1, int n2) {
	return n1 - n2;
}

int multiplicar(int n1, int n2) {
	return n1 * n2;
}

int dividir(int n1, int n2) {
	if (n2 == 0) {
		return 0;
	}
	return n1 / n2;
}

int main() {
	int n1, n2, escolha;
	int resultado = 0;
	while (1) {

		printf("\nDigite \n1- somar, \n2-subtrair, \n3- multiplicar, \n 4-dividir \n0 para sair: ");
		scanf_s("%d", &escolha);

		if (escolha == 0) {
			return 0;
		}

		printf("\nDigite o primeiro numero inteiro: ");
		scanf_s("%d", &n1);

		printf("\nDigite o segundo numero inteiro: ");
		scanf_s("%d", &n2);

		switch (escolha)
		{
			case 1:
				resultado = somar(n1, n2);
				break;
			case 2:
				resultado = subtrair(n1, n2);
				break;
			case 3:
				resultado = multiplicar(n1, n2);
				break;
			case 4:
				resultado = dividir(n1, n2);
				break;
			default:
				break;
		}

		printf("The result is %d", resultado);
	}

	return 0;
}

