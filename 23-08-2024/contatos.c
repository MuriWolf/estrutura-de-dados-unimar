#include <stdio.h>
#include <string.h>

//• Exercício 3: Crie uma estrutura chamada Contato com os campos : nome(até 50
//	caracteres), telefone(até 15 caracteres) e e - mail(até 50 caracteres).Crie um
//	programa que permita ao usuário armazenar até 10 contatos em um vetor de
//	estruturas, exibir os contatos e procurar um contato pelo nome.

typedef struct
{
	char nome[50];
	char telefone[15];
	char email[50];
} Contato;

const int max_contatos = 10;

int main()
{
	int qtde_contatos = 0;
	do {
		printf("\nDigite quantos contatos deseja armazenar (até 10): ");
		scanf_s("%d", &qtde_contatos);
	} while (qtde_contatos < 1 && qtde_contatos > 10);

	for (int i = 1; i < qtde_contatos; i++)
	{

	}
}