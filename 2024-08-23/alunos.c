#include <stdio.h>

//Exercício 1: Crie uma estrutura chamada Aluno com os seguintes campos : nome
//(até 50 caracteres), idade, matrícula e média.Em seguida, escreva um programa
//que lê os dados de 5 alunos e os armazena em um vetor de estruturas.
//Finalmente, exiba os dados dos alunos na tela.

typedef struct
{
	char nome[50];
	int idade;
	char matricula[30];
	double media;
} Aluno;

int main()
{
	const int qtde_alunos = 5;

	Aluno alunos[qtde_alunos];

	for (int i = 0; i < qtde_alunos; i++)
	{
		printf("\nDigite o nome: ");
		scanf_s("%s", alunos[i].nome, (50 * sizeof(char)));

		printf("Digite a idade: ");
		scanf_s("%d", &alunos[i].idade, sizeof(int));

		printf("Digite a matricula: ");
		scanf_s("%s", alunos[i].matricula, (30 * sizeof(char)));

		printf("Digite a media: ");
		scanf_s("%lf", &alunos[i].media, sizeof(double));
	}

	for (int i = 0; i < qtde_alunos; i++)
	{
		printf("\n\nAluno %d: ", i+1);
		printf("\n%s", alunos->nome);
		printf("\n%d", alunos->idade);
		printf("\n%s", alunos->matricula);
		printf("\n%.1f", alunos->media);
	}

}
