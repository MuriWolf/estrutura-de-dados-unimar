
#include <stdio.h>
#include <stdlib.h>

#define array_length 5

void printf_int_array(int* array, int size) {
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

void insertion_sort(int* array, int size, int is_reversed) {
	int i, j;
	int temp;
	for (i = 1; i < size; i++) {
		temp = array[i];
		j = i - 1;
		while (j >= 0 && is_reversed ? array[j] < temp : array[j] > temp) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = temp;
	}
}


int main() {
	int array[array_length];
	
	for (size_t i = 0; i < array_length; i++)
	{
		printf("Digite um valor inteiro: ");
		scanf("%d", &array[i]);
	}

	int order;
	do {
		printf("Informe se deseja ordenar crescente ou decrescente\n\n0 - crescente\n1 - decrescente\n\n");
		scanf("%d", &order);
	} while (order != 0 && order != 1);

	insertion_sort(array, array_length, order);
	printf("\nReverse insertion sort: ");
	printf_int_array(array, array_length);

	return 0;
}