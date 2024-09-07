#include <stdio.h>

void mostrar_fibonacci()
{
  const int qtde_valores = 20;
  int valores[20];

  valores[0] = 1;
  valores[1] = 1;

  for (int i = 1; i < qtde_valores; i++)
  {
    valores[i+1] = valores[i] + valores[i-1];
  }

  for (int i = 0; i < qtde_valores; i++)
  {
    printf("%d\n", valores[i]);
  }
}

void mostrar_anos_bissextos()
{
	const int current_year = 2024; // isso obviamente nao deveria ser uma constante
	for (int ano = 1; ano <= current_year; ano++)
	{
		if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
		{
			printf("\nO ano %d e bissexto", ano);
		}
	}
}

void testar_amostras()
{
	const int numero_amostras = 6;

	int fem_gostou = 0;
	int fem_nao_gostou = 0;
	int masc_gostou = 0;
	int masc_nao_gostou = 0;

	for (int i = 0; i < numero_amostras; i++)
	{
		char gostou_amostra;
		char sexo;
		printf("\nGostou da amostra? (s - sim, n - nao): ");

		// scanf_s(" %c", &gostou_amostra);
		printf("\nQual seu sexo (f - feminino, m - masculino): ");
		// scanf_s(" %c", &sexo);


		if (sexo == 'm')
		{
			if (gostou_amostra == 's')
			{
				masc_gostou++;
			}
			else if (gostou_amostra == 'n')
			{
				masc_nao_gostou++;
			}
		}
		else if (sexo == 'f')
		{
			if (gostou_amostra == 's')
			{
				fem_gostou++;
			}
			else if (gostou_amostra == 'n')
			{
				fem_nao_gostou++;
			}
		}

	}

	printf("\n%d homens e %d mulheres gostaram do produto.", masc_gostou, fem_gostou);
	printf("\n%d homens e %d mulheres nao gostaram do produto.", masc_nao_gostou, fem_nao_gostou);

	if ((masc_gostou + fem_gostou) / 2.0 > (masc_nao_gostou + fem_nao_gostou) / 2.0)
	{
		printf("\nDeve lancar");
	}
	else
	{
		printf("\nNão deve lancar");
	}
}

void sequencia()
{
	const int qtde_valores = 100;
	int valor = 1;

	for (int i = 0; i < qtde_valores; i++)
	{
		valor = valor + i;
		printf("\n%d", valor);
	}

}

int main()
{
  // --- Deixei os exercícios em funções, basta tirar o comentário do exercício que deseja testar ---

	mostrar_anos_bissextos();
	// testar_amostras();
	// sequencia();
  // mostrar_fibonacci();
}


