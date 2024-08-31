#include <stdio.h>

int main() {
    int notas[5];
    int* pnotas = NULL;
    pnotas = notas;
    int soma = 0;

    for (int i = 0; i < 5; i++) {
      printf("\nDigite a nota %d: ", i+1);
      scanf("%d", (pnotas + i));
    }
    
    for (int i = 0; i < 5; i++) {
        soma += *(pnotas + i);
    }
    
    printf("A media eh: %.1f", soma / 5.0);
    return 0;
}
