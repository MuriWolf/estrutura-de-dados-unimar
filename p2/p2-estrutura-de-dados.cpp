#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum ConservationStatusCodes {
	NONTHREATENED = 1,
	THREATENED = 2
};

typedef struct {
	char scientific_name[50]; // key to the tree
	char popular_name[50];
	int estimated_population;
	char occurence_region[50];
	char conservation_status[50];
} Especie;

typedef struct Node {
	Especie* value; // não sei se devo iniciar como ponteiro
	struct Node* left;
	struct Node* right;
} Node;

int compare_strings_ascii(char s1[50], char s2[50]) {
	int is_new_especie_ASCII_bigger = 0, minor_string_length = 0, i;

	minor_string_length = strlen(s1) < strlen(s2) ? (int) strlen(s1) : (int) strlen(s2);

	for (i = 0; i < minor_string_length; i++) {
		printf("%c", s1[i]);
	}

	return 1;
}

Node* insert_on_especies_tree(Node* root, Especie* new_especie) {
	int is_new_especie_ASCII_bigger = 0, minor_string_length = 0, i;

	minor_string_length = abs( (int) strlen(new_especie->scientific_name) - (int) strlen(root->value->scientific_name) );

	if (root == NULL) {
		root = (Node*)calloc(1, sizeof(Node));
		root->left = NULL;
		root->right = NULL;
	}

	if (minor_string_length == 0) {
		printf("\n\nERRO: Nao foi possivel comparar os nomes das especies.");
	}
	else {
		for (i = 0; i < minor_string_length; i++) {
			if (new_especie->scientific_name[i] < root->value->scientific_name[i]) {
				is_new_especie_ASCII_bigger = 1;
				break;
			}
			else if (new_especie->scientific_name[i] > root->value->scientific_name[i]) {
				is_new_especie_ASCII_bigger = 0;
				break;
			}
		}

	}
	// nome é menor que o nó atual

	// nome é maior que o nó atual

	return root;
}

Especie* create_especie() {
	Especie* new_especie = (Especie*)calloc(1, sizeof(Especie));
	ConservationStatusCodes conservation_status_code;

	printf("\nInforme o nome cientifico: ");
	scanf_s("%s", new_especie->scientific_name, sizeof(new_especie->scientific_name));

	printf("\nInforme o nome popular: ");
	scanf_s("%s", new_especie->popular_name, sizeof(new_especie->popular_name));

	printf("\nPopulacao estimada: ");
	scanf_s("%d", &new_especie->estimated_population);

	printf("\nRegiao de ocorrencia: ");
	scanf_s("%s", new_especie->occurence_region, sizeof(new_especie->occurence_region));


	do {
		printf("\nStatus de conservacao:\n1- nao ameacada\n2- ameacada\n\n");
		scanf_s("%d", &conservation_status_code);
	} while (conservation_status_code != 1 && conservation_status_code != 2);

	if (conservation_status_code == 1) {
		strcpy_s(new_especie->conservation_status, "nao ameacada");
	}
	else {
		strcpy_s(new_especie->conservation_status, "ameacada");
	}

	return new_especie;
}


int show_menu() {
	int choice;
	do {
		printf("\n\n1. Inserir nova especie\n2. Buscar especie\n3. Listar especies\n4. Excluir especie\n5. Exportar catalogo ordenado\n6. Exibir estatisticas\n7. Sair\n\n");
		scanf_s("%d", &choice);
	} while (choice < 1 || choice > 7);

	return choice;
}


int main() {
	int choice;
	Especie* new_especie;

	char s1[50] = "hello me";
	char s2[50] = "hello you dumbass";

	compare_strings_ascii(s1, s2);


	while (1) {
		choice = show_menu();

		switch (choice)
		{
		case 1:
			new_especie = create_especie();

			break;
		case 7:
			printf("\nSaindo do programa...\n");
			return 0;
		default:
			printf("Entrada nao identificada");
			break;
		}
	}


	return 0;
}