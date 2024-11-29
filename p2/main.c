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
  int i;
  int len_s1 = strlen(s1);
  int len_s2 = strlen(s2);
  int min_len = (len_s1 < len_s2) ? len_s1 : len_s2;

	for (i = 0; i < min_len; i++) {
		if (s1[i] > s2[i]) {
			return s1;
		} else if ((int) s2[i] > (int) s1[i]) {
			return s2;
		}
	}

  if (len_s1 == len_s2) {
    return NULL;
  } else {
    return (len_s1 < len_s2) ? s2 : s1;
  }
}

Node* insert_on_species_tree(Node* root, Specie* new_specie) {
  int minor_string_length = 0;
  int i = 0;

  if (root == NULL) {
		root = (Node*)calloc(1, sizeof(Node));
    root->value = new_specie;
		root->left = NULL;
		root->right = NULL;

    return root;
	} else {
    char* bigger_ascii_string = compare_strings_ascii(new_specie->scientific_name, root->value->scientific_name);

    if (bigger_ascii_string != NULL) {
      if (strcmp(root->value->scientific_name, bigger_ascii_string) == 0) {
        root->left = insert_on_species_tree(root->left, new_specie);
      }
      else if (strcmp(new_specie->scientific_name, bigger_ascii_string) == 0) {
        root->right = insert_on_species_tree(root->right, new_specie);
      }
    }
  }

	return root;
}

Specie* create_specie() {
	Specie* new_specie = (Specie*)calloc(1, sizeof(Specie));
  int conservation_status_input = 0;

  printf("\nInforme o nome cientifico: ");
	scanf("%s", new_specie->scientific_name);

	printf("\nInforme o nome popular: ");
	scanf("%s", new_specie->popular_name);

	printf("\nPopulacao estimada: ");
	scanf("%d", &new_specie->estimated_population);

	printf("\nRegiao de ocorrencia: ");
	scanf("%s", new_specie->occurrence_region);

  printf("got here");

	do {
		printf("\nStatus de conservacao:\n1- nao ameacada\n2- ameacada\n\n");
		scanf("%d", &conservation_status_input);
	} while (conservation_status_input != NONTHREATENED && conservation_status_input != THREATENED);

  printf("got here");

	if (conservation_status_input == NONTHREATENED) {
		strcpy(new_specie->conservation_status, "nao ameacada");
	}
	else {
		strcpy(new_specie->conservation_status, "ameacada");
	}


	return new_specie;
}

void show_specie(Specie* specie) {
  printf("\n\nNome cientifico: %s\nNome popular: %s\nPopulacao estimada: %d\nRegiao de ocorrencia: %s\nStatus de conservacao: %s", specie->scientific_name, specie->popular_name, specie->estimated_population, specie->occurrence_region, specie->conservation_status);
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

void show_all_species_in_order(Node* root) {
  if (root != NULL) {
    show_all_species_in_order(root->left);
    show_specie(root->value);
    show_all_species_in_order(root->right);
  }
}

void show_all_species_pre_order(Node* root) {
  if (root != NULL) {
    show_specie(root->value);
    show_all_species_in_order(root->left);
    show_all_species_in_order(root->right);
  }
}

void show_all_species_post_order(Node* root) {
  if (root != NULL) {
    show_all_species_in_order(root->left);
    show_all_species_in_order(root->right);
    show_specie(root->value);
  }
}

Node* get_minor_node(Node* root) {
  if (root->left != NULL) {
    return get_minor_node(root->left);
  } else {
    Node* aux = root;
    
    if (root->right != NULL) {
      root = root->right;
    } else root->right = NULL;

    return aux;

  }
}

Node* remove_specie_from_tree(Node* root, char name[50]) {
  if (root == NULL) return root;

  char* bigger_ascii_string = compare_strings_ascii(name, root->value->scientific_name);
  
  // se as strings sao iguais, entao a remocao é feita 
  if (bigger_ascii_string == NULL) {
    // Caso folha
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL; // O nó é removido
    } else if (root->left == NULL) {
      Node* temp = root->right;
      free(root);
      return temp; // Retorna o filho direito
    } else if (root->right == NULL) {
      Node* temp = root->left;
      free(root);
      return temp; // Retorna o filho esquerdo
    }
    
    // caso dois filhos
    Node* temp = get_minor_node(root->right);
    if (temp != NULL) {
      root->value = temp->value;
      root->right = remove_specie_from_tree(root->right, temp->value->scientific_name);
    }
    
  } else {
    if (strcmp(root->value->scientific_name, bigger_ascii_string) == 0) {
      root->left = remove_specie_from_tree(root->left, name);
    } else if (strcmp(name, bigger_ascii_string) == 0) {
      root->right = remove_specie_from_tree(root->right, name);
    }
  }

  return root; 
}

int count_nodes(Node* root) {
  if (root == NULL) return 0;
  return 1 + count_nodes(root->left) + count_nodes(root->right);
}

void export_species_to_array_in_order(Node* root) {
  if (root == NULL) return;

  export_species_to_array_in_order(root->left);
  export_species_to_array_in_order(root->right);
}

int show_menu() {
	int choice;
	do {
		printf("\n\n1. Inserir nova especie\n2. Buscar especie\n3. Listar especies\n4. Excluir especie\n5. Exportar catalogo ordenado\n6. Exibir estatisticas\n7. Sair\n\n");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 7);

	return choice;
}

void free_tree(Node* root) {
  if (root != NULL) {
    free_tree(root->left);
    free(root->value);
    free_tree(root->right);
    free(root);
  }
}

int main() {
	Specie* new_specie;

  Node* root = NULL;

	while (1) {
		int choice = show_menu();
    int show_species_choise = 0;

		switch (choice)
		{
		case 1:
			new_specie = create_specie();
      root = insert_on_species_tree(root, new_specie);

			break;
    case 2:
      if (root != NULL) {
        char specie_to_search[50];
        printf("\nDigite o nome da especie que deseja procurar: ");
        scanf("%s", specie_to_search);

        search_specie_by_scientific_name(root, specie_to_search);
      }
      else {
        printf("\nERRO: Nenhuma especie foi cadastrada. Tente adicionar alguma.");
      }
      break;
    case 3:
      if (root != NULL) {
        do {
          printf("\n\n1. In-order\n2. Pre-order\n3. Post-order\n");
          scanf("%d", &show_species_choise);
        } while (show_species_choise < 1 || show_species_choise > 3);

        printf("\nESPECIES CADASTRADAS");

        if (show_species_choise == 1) {
          show_all_species_in_order(root);
        } else if (show_species_choise == 2) {
          show_all_species_pre_order(root);
        } else {
          show_all_species_post_order(root);
        }
      }

      break;
    case 4:
      if (root != NULL) {
        char specie_to_remove[50];
        printf("\nDigite o nome da especie que deseja deletar: ");
        scanf("%s", specie_to_remove);

        root = remove_specie_from_tree(root, specie_to_remove);
      }

      break;
    case 5:
      if (root != NULL) {
        
      }
            
		case 7:
      free_tree(root);
			printf("\nSaindo do programa...\n");
			return 0;
		default:
			printf("Entrada nao identificada");
			break;
		}
	}
}

