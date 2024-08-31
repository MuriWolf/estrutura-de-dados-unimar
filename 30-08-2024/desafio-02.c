#include <stdio.h>
#include <math.h>

int main() {
    int vetor[5] = { 10, 20, 30, 40, 50 };
    int* pvetor;
    pvetor = vetor;
    
    for (int i = 0; i < ceil(5 / 2.0); i++) {
        int buffer = *(pvetor + i);
        *(pvetor + i) = *(pvetor + 4 - i);
        *(pvetor + 4 - i) = buffer;
    }
    
    for (int i = 0; i < 5; i++) {
        printf("\n%d", *(pvetor + i));
    }
    
    return 0;
}
