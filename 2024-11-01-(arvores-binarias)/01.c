#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* esq;
	struct Node* dir;
} Node;

Node* create_node(int size) {
	Node* new_node;
	if (size < 1) {
		new_node = NULL;
	}
	else {
		new_node = (Node*)calloc(1, sizeof(Node));
		printf("\nDigite o valor: ");
		scanf_s("%d", &new_node->value);
		new_node->esq = create_node(size / 2);
		new_node->dir = create_node(size - size / 2 - 1);
	}
	return new_node;
}

// raiz - esq - dir
void pre_order(Node* node) {
	if (node == NULL) return;
	printf("%d ", node->value);
	pre_order(node->esq);
	pre_order(node->dir);
}

// esq - dir - raiz
void post_order(Node* node) {
	if (node == NULL) return;
	pre_order(node->esq);
	pre_order(node->dir);
	printf("%d ", node->value);
}

// esq - raiz - dir
void in_order(Node* node) {
	if (node == NULL) return;
	pre_order(node->esq);
	printf("%d ", node->value);
	pre_order(node->dir);
}

void get_nodes(Node* node) {
	if (node == NULL) return;
	else if (node->esq || node->dir) printf("%d ", node->value);
	get_nodes(node->esq);
	get_nodes(node->dir);
}

int get_height(Node* node) {
	if (node == NULL) return -1;
	int e = get_height(node->esq);
	int d =get_height(node->dir);
	if (d > e) return d + 1;
	return e + 1;
}

int find_node(Node* node, int searched_value) {
	if (node == NULL) return NULL;
	if (node->value == searched_value) {
		return node->value;
	}
	else {
		return NULL;
	}
	find_node(node->esq, searched_value);
	find_node(node->dir, searched_value);
}

int main() {
	Node* node;
	node = create_node(10);

	printf("\npre order: \n");
	pre_order(node);

	printf("\npost order: \n");
	post_order(node);

	printf("\nin order: \n");
	in_order(node);

	printf("\nnodes: \n");
	get_nodes(node);

	int search_value;
	printf("\nDigite um valor para busca-lo na arvore: ");
	scanf_s("%d", &search_value);

	if (find_node(node, search_value) != NULL) {
		printf("Valor encontrado!");
	}
	else {
		printf("Valor nao encontrado!");
	}

	printf("\naltura da arvore: %d", get_height(node));

	return 0;
}
