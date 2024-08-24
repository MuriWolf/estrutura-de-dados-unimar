#include <stdio.h>
#include <string.h>

typedef struct
{
	char nome[50];
	char numero[50];
	double saldo;
} Conta;

double depositar(double saldo, double valor)
{
	if (valor < 0)
	{
		printf("\nNao foi possivel efetuar o deposito. Digite um valor maior.");
		return saldo;
	}
	saldo += valor;
	printf("\Deposito efetuado. Saldo atual: %.2f", saldo);
	return saldo;
}

double sacar(double saldo, double valor)
{
	if (saldo - valor < 0)
	{
		printf("\nNao foi possivel efetuar o saque. Digite um valor menor.");
		return saldo;
	}
	saldo -= valor;
	printf("\nSaque efetuado. Saldo atual: %.2f", saldo);
	return saldo;
}

int main()
{
	Conta conta;

	strcpy_s(conta.nome, "Leon Kannedy");
	strcpy_s(conta.nome, "0324233134");
	conta.saldo = 1400.24;

	while (1)
	{
		int escolha = 100;
		double valor = 0;

		printf("\nOPCOES\n\n1 - sacar\n2 - depositar\n0 - sair\n\n");
		scanf_s("%d", &escolha);

		if (escolha == 0)
		{
			return 0;
		}

		printf("\nDigite o valor: ");
		scanf_s("%lf", &valor, sizeof(double));

		switch (escolha)
		{
		case 1:
			conta.saldo = sacar(conta.saldo, valor);
			break;
		case 2:
			conta.saldo = depositar(conta.saldo, valor);
			break;
		case 0:
			break;
		default:
			break;
		};
	}
}

