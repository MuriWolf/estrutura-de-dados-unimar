
#include <stdio.h>

int main()
{
	int a, b;
	int operacao = 0;
	int* pa = &a;
	int* pb = &b;

	printf("Digite um operador (1 - soma): ");
	scanf_s("%d", &operacao, sizeof(operacao));

	printf("Digite um valor de A: ");                                                           
	scanf_s("%d", pa);

	printf("Digite um valor de B: ");
	scanf_s("%d", pb);

	if (operacao == 1)
	{
		printf("%d", *pa + *pb);
	}
}