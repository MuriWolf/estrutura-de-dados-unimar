#include <stdio.h>

int main() {
  int vetor[10];
  int* pvetor = NULL;
  pvetor = vetor;

  *(pvetor) = 1;
  *(pvetor + 1) = 1;

  for (int i = 2; i < 10; i++) {
    *(pvetor + i) = *(pvetor + i - 1) + *(pvetor + i - 2);
  }

  for (int i = 0; i < 10; i++) {
    printf("%d\n", *(pvetor + i));
  }

  return 0;
}
