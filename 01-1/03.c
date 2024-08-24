#include <stdio.h>

int main()
{
  int valor = 1;
  printf("Digite um valor: ");
  scanf("%d", &valor);

  for (int i = 1; i <= valor; i++)
  {
    if (i % 2 == 0)
    {
      printf("\n%d", i);
    }
  }
}
