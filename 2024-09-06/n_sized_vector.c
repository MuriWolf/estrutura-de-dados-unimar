
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vector_size = 0;
    
    printf("Digite o tamanho do vetor de inteiros (int): ");
    scanf("%d", &vector_size);
    
    int* vector;
    vector = (int*)calloc(vector_size, sizeof(int));
    
    for (int i = 0; i < vector_size; i++) {
        scanf("%d", (vector + i));
    }
    
    for (int i = 0; i < vector_size; i++) {
        printf("\n%d", *(vector + i));
    }
}