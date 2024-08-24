#include <stdio.h>

typedef struct 
{
  char nome[50];
  char genero[30];
} Quadrinho;

int main()
{
  int qtdeQuadrinhos;
  printf("Informe a quantidade de quadrinhos: ");
  scanf("%i", &qtdeQuadrinhos);
  
  Quadrinho quadrinhos[qtdeQuadrinhos];

  for (int i = 0; i < qtdeQuadrinhos; i++)
  {
    printf("\nDigite o nome do quadrinho %i: ", i+1);
    scanf("%s", quadrinhos[i].nome);

    printf("Digite o genero do quadrinho %i: ", i+1);
    scanf("%s", quadrinhos[i].genero); 
  }

  while (1)
  {
    int escolha;
    printf("\n\nDigite o numero de cadastro para ver as informacoes (1 - %i). \n0 para sair\n", qtdeQuadrinhos);
    scanf("%i", &escolha);
    if (escolha == 0)
    {
      break;
    }
    else if (escolha <= qtdeQuadrinhos && escolha > 0)
    {
      printf("\nNome: %s, Genero: %s", quadrinhos[escolha-1].nome, quadrinhos[escolha-1].genero);
    }
    else
    {
      printf("\nEscolha inválida.");
    }
  }
}
