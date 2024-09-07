#include <stdio.h>
#include <string.h>

typedef struct {
	char codigo[20];
	int idade;
	char nome[50];
	char raca[50];
} Cachorro;

const int qtde_cachorros = 10;

int main(void) {
	Cachorro vcachorro[qtde_cachorros];
	Cachorro* pcachorro;
	pcachorro = vcachorro;
	int qtde_pinschers = 0;

	for (int i = 0; i < qtde_cachorros; i++) {
    	printf("\nDigite o codigo: ");
    	scanf("%s", (pcachorro+i)->codigo);
    
    	printf("Digite a idade: ");
    	scanf("%s", &(pcachorro+i)->idade);
    
    	printf("Digite o nome: ");
    	scanf("%s", (pcachorro+i)->nome);
    
    	printf("Digite a raca: ");
    	scanf("%s", (pcachorro+i)->raca);

		if (strcmp((pcachorro+i)->raca, "pinscher") == 0) {
			qtde_pinschers++;
		}
	}

	printf("\nquantidade de pinchers: %d", qtde_pinschers);
	
	return 0;
}
