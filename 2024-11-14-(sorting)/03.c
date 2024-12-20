
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define array_length 5

typedef struct {
	char name[100];
	int grade;
} Student;

void printf_student_array(Student* students, int size) {
	for (size_t i = 0; i < size; i++)
	{
		printf("\nnome: %s\n", students[i].name);
		printf("nota: %d\n", students[i].grade);
	}
	printf("\n");
}

void bubble_sort(Student* array, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j].grade > array[j + 1].grade) {
				int temp_grade = array[j].grade;
				char temp_name[100];
				strcpy_s(temp_name, array[j].name);

				array[j].grade = array[j + 1].grade;
				strcpy_s(array[j].name, array[j + 1].name);

				array[j + 1].grade = temp_grade;
				strcpy_s(array[j + 1].name, temp_name);
			}
		}
	}
}

int main() {
	Student array[array_length];
	
	for (size_t i = 0; i < array_length; i++)
	{
		printf("\nDigite o nome do aluno: ");
		scanf_s("%s", array[i].name, sizeof(array[i].name));

		printf("Digite um valor inteiro: ");
		scanf_s("%d", &array[i].grade);
	}

	bubble_sort(array, array_length);
	printf("\nAlunos ordenados por nota: \n");
	printf_student_array(array, array_length);

	return 0;
}