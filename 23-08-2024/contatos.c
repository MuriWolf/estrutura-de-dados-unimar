#include <stdio.h>
#include <string.h>

//• Exercício 3: Crie uma estrutura chamada Contato com os campos : nome(até 50
//	caracteres), telefone(até 15 caracteres) e e - mail(até 50 caracteres).Crie um
//	programa que permita ao usuário armazenar até 10 contatos em um vetor de
//	estruturas, exibir os contatos e procurar um contato pelo nome.
//

typedef struct
{
	char nome[50];
	char telefone[15];
	char email[50];
} Contato;

const int max_contatos = 10;

int buscar_contatos(int qtde_contatos, Contato contatos[qtde_contatos], char nome[50]);

int main()
{
	int qtde_contatos = 0;
	do {
		printf("\nDigite quantos contatos deseja armazenar (até 10): ");
		scanf("%d", &qtde_contatos);
	} while (qtde_contatos < 1 && qtde_contatos > 10);
  
  Contato contatos[qtde_contatos];

	for (int i = 0; i < qtde_contatos; i++)
	{
    printf("\nDigite o nome do contato %d: ", i+1);
    scanf(" %[^\n]s", contatos[i].nome);

    printf("Digite o telefone do contato %d: ", i+1);
    scanf(" %[^\n]s", contatos[i].telefone);
	
    printf("Digite o email do contato %d: ", i+1);
    scanf(" %[^\n]s", contatos[i].email);
  }

  int escolha = 0;

  while (1)
  {
    do
    {
      printf("\nDeseja pesquisar alguem? (1 - sim, 0 - sair): ");
      scanf("%d", &escolha);
    } while (escolha != 1 && escolha != 0);

    if (escolha == 0)
    {
      break;   
    }
    
    char nome[50];
    printf("\nDigite o nome de quem deseja ver: ");
    scanf(" %[^\n]s", nome);
    
    int id = buscar_contatos(qtde_contatos, contatos, nome);

    if (id == -1)
    {
      printf("\nNome nao encontrado");
    }
    else 
    {
      printf("\n\nDados do contato\n");
      printf("\nNome: %s", contatos[id].nome);
      printf("\nTelefone: %s", contatos[id].telefone);
      printf("\nEmail: %s\n", contatos[id].email);
    }
    
  }
  return 0;
}


int buscar_contatos(int qtde_contatos, Contato contatos[qtde_contatos], char nome[50])
{
  for (int i = 0; i < qtde_contatos; i++)
  {
    if (strcmp(contatos[i].nome, nome) == 0)
    {
      return i;
    }
  }
  return -1;
}

