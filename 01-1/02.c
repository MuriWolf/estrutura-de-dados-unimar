#include <stdio.h>

const int qtde_notas = 5;

int main()
{
  int total_notas = 0;

  for (int i = 0; i < qtde_notas; i++)
  {
    int nota = 0; 
    printf("\nDigite a nota %d: ", i+1);
    scanf("%d", &nota);
    
    total_notas += nota;
  }

  printf("A media de notas é %.1f\n", total_notas / (float) qtde_notas);
}
