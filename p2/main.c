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
	char occurrence_region[50];
	char conservation_status[50];
} Specie;

typedef struct Node {
	Specie* value; // não sei se devo iniciar como ponteiro
	struct Node* left;
	struct Node* right;
} Node;

char* compare_strings_ascii(char s1[50], char s2[50]) {
	int is_s1_ASCII_bigger = 0, minor_string_length = 0, i;

	minor_string_length = strlen(s1) < strlen(s2) ? (int) strlen(s1) : (int) strlen(s2);

	for (i = 0; i < minor_string_length; i++) {
		if ((int) s1[i] > (int) s2[i]) {
			return s1;
		} else if ((int) s2[i] > (int) s1[i]) {
			return s2;
		}
	}

	return s1;
}

Node* insert_on_species_tree(Node* root, Specie* new_specie) {
  int minor_string_length = 0;
  int i = 0;

  if (root == NULL) {
		root = (Node*)calloc(1, sizeof(Node));
    root->value = new_specie;
		root->left = NULL;
		root->right = NULL;

	}

	char* bigger_ascii_string = compare_strings_ascii(new_specie->scientific_name, root->value->scientific_name);

	for (i = 0; i < minor_string_length; i++) {
		if (strcmp(root->value->scientific_name, bigger_ascii_string) == 0) {
      root->left = insert_on_species_tree(root->left, new_specie);
			break;
		}
		else if (strcmp(new_specie->scientific_name, bigger_ascii_string) == 0) {
      root->right = insert_on_species_tree(root->right, new_specie);
			break;
		}
	}

	return root;
}

Specie* create_specie() {
	Specie* new_specie = (Specie*)calloc(1, sizeof(Specie));
	enum ConservationStatusCodes conservation_status_code;

	printf("\nInforme o nome cientifico: ");
	scanf("%s", new_specie->scientific_name);

	printf("\nInforme o nome popular: ");
	scanf("%s", new_specie->popular_name);

	printf("\nPopulacao estimada: ");
	scanf("%d", &new_specie->estimated_population);

	printf("\nRegiao de ocorrencia: ");
	scanf("%s", new_specie->occurrence_region);


	do {
		printf("\nStatus de conservacao:\n1- nao ameacada\n2- ameacada\n\n");
		scanf("%d", &conservation_status_code);
	} while (conservation_status_code != 1 && conservation_status_code != 2);

	if (conservation_status_code == 1) {
		strcpy(new_specie->conservation_status, "nao ameacada");
	}
	else {
		strcpy(new_specie->conservation_status, "ameacada");
	}

	return new_specie;
}

void show_specie(Specie* specie) {
  printf("\n\nNome cientifico: %s\nNome popular: %s\nPopulacao estimada: %s\nRegiao de ocorrencia: %s\nStatus de conservacao: %s", specie->scientific_name, specie->popular_name, specie->estimated_population, specie->occurrence_region, specie->conservation_status);
}

void search_specie_by_scientific_name(Node* root, char name[50]) {
  if (root != NULL) {
    search_specie_by_scientific_name(root->left, name);
    if (strcmp(name, root->value->scientific_name) == 0) {
      show_specie(root->value);
    }
    search_specie_by_scientific_name(root->right, name);
  }
}


int show_menu() {
	int choice;
	do {
		printf("\n\n1. Inserir nova especie\n2. Buscar especie\n3. Listar especies\n4. Excluir especie\n5. Exportar catalogo ordenado\n6. Exibir estatisticas\n7. Sair\n\n");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 7);

	return choice;
}


int main() {
	Specie* new_specie;

  Node* root = NULL;

	while (1) {
		int choice = show_menu();

		switch (choice)
		{
		case 1:
			new_specie = create_specie();

      if (root == NULL) {
        printf("is null");
      }

      insert_on_species_tree(root, new_specie);

			break;
    case 2:

      if (root == NULL) {
          printf("\nERRO: Nenhuma especie foi cadastrada. Tente adicionar alguma.");
      } else {
        char specie_to_search[50];
        printf("\nDigite o nome da especie que deseja procurar: ");
        scanf("%s", specie_to_search);

        search_specie_by_scientific_name(root, specie_to_search);
      }
      break;
      
		case 7:
			printf("\nSaindo do programa...\n");
			return 0;
		default:
			printf("Entrada nao identificada");
			break;
		}
	}
}

