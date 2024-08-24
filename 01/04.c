#include <stdio.h> 
 
// Faça um algoritmo que mostra todos os valores primos de 0 a 50. 
 
int main() 
{ 
 // fazer loop de 0 a 50 
 // testar se o resto de sua divisao é 0 (exceto para o numero em si e para 2 e 3) 
 for (int i = 0; i < 50; i++) 
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
