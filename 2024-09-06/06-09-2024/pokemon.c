#include <stdio.h>

typedef struct {
    char nome[50];
    char poder[50];
    double dano_ataque;
} Pokemon;

const int qtde_pokemons = 2; 

int main() {
    Pokemon pokemons[qtde_pokemons];
    Pokemon* ppokemons;
    ppokemons = pokemons;
    
    for (int i = 0; i < qtde_pokemons; i++) {
        printf("\nDigite o nome do pokemon: ");
        scanf("%s", (ppokemons + i)->nome);
        
        printf("Digite o poder do pokemon: ");
        scanf("%s", (ppokemons + i)->poder);
        
        printf("Digite o dano de ataque do pokemon: ");
        scanf("%lf", &(ppokemons + i)->dano_ataque);
    }
    
    for (int i = 0; i < qtde_pokemons; i++) {
        printf("\n\nDados do pokemon %i", i+1);
        printf("\nNome: %s", (ppokemons + i)->nome);
        printf("\nNome: %s", (ppokemons + i)->poder);
        printf("\nNome: %.2lf", (ppokemons + i)->dano_ataque);
    }
}