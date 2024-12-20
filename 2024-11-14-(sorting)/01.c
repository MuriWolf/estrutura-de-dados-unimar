
#include <stdio.h>
#include <stdlib.h>

void printf_int_array(int* array, int size) {
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

void insertion_sort(int* array, int size) {
	int i, j;
	int temp;
	for (i = 1; i < size; i++) {
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > temp) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = temp;
	}
}

void reverse_insertion_sort(int* array, int size) {
	int i, j;
	int temp;
	for (i = 1; i < size; i++) {
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] < temp) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = temp;
	}
}


void bubble_sort(int* array, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void reverse_bubble_sort(int* array, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] < array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}


int main() {
	int array[5] = { 4, 9, 11, 3, 1 };

	reverse_insertion_sort(array, 5);
	printf("\nReverse insertion sort: ");
	printf_int_array(array, 5);

	reverse_bubble_sort(array, 5);
	printf("\nReverse bubble sort: ");
	printf_int_array(array, 5);

	return 0;
}