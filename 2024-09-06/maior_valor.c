#include <stdio.h>

int main() {
  int vetor[5];
  int maior_valor;
  
  for (int i = 0; i < 5; i++) {
      printf("Digite um valor para o vetor: ");
      scanf("%d", &vetor[i]);
  }
  
  maior_valor = vetor[0];
  for (int i = 0; i < 5; i++) {
    if (vetor[i] > maior_valor) {
        maior_valor = vetor[i];
    }
  }
  
  printf("\nO maior valor eh: %d", maior_valor);
}