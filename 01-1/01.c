#include <stdio.h>

int main()
{
  char nome[50];
  int idade;
  
  printf("\nColoque seu nome: ");
  scanf("%s", nome);

  printf("\nColoque sua idade: ");
  scanf("%d", &idade);
  
  if (idade >= 18)
  {
    printf("Apto para ingressar no ensino superior\n");
  }
  else 
  {
    printf("Não apto para ingressar no ensino superior\n");
  }
}
