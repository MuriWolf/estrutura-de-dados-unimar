#include <stdio.h> 
 
 
int main() 
{
  int numero = 0;
  printf("Digite um numero: ");
  scanf("%d", &numero);

 for (int i = 0; i < numero; i++) 
 { 
  // casos especiais 
  if (i < 3) 
  { 
   if (i == 2) 
   { 
    printf("%d\n", i); 
   } 
  }
  else 
  {
    int isPrime = 1;
    for (int j = 2; j < i; j++) 
    { 
      if (i % j == 0)
      {
        isPrime = 0;
        break;
      }
    }

    if (isPrime == 1)
    {
      printf("%d\n", i);
    }
  }
   
 } 
}
