#include <stdio.h>
#include <stdlib.h>

int tam = 100;
float vsalarios[100];

void adicionar(float vet[100])
{
	int i = 0;

	for (i = 0; i < tam; i++)
	{
		vet[i] = rand();
	}
	printf("100 valores adicionados no vetor!\n");
}

void imprimir(float vet[100])
{
	int i = 0;

	for (i = 0; i < tam; i++)
	{
		printf("%d - %0.2f. \n", i, vet[i]);
	}
}

void imprimirmenorq(float vet[100])
{
	int i = 0;
	float menor;
	printf("Digite um salario: ");
	scanf("%f", &menor);
	for (i = 0; i < tam; i++)
	{
		if (vet[i] < menor)
		{
			printf("%0.2f\n", vet[i]);
		}
	}
}

float somarSalarios(float vet[100])
{
	int i;
	float acum = 0;

	for (i = 0; i < tam; i++)
	{
		acum = acum + vet[i];
	}

	return acum;
}
float somarSalariosX(float vet[100])
{
	int i;
	float acum = 0, sal;
	printf("Digite o salario: ");
	scanf("%f", &sal);

	for (i = 0; i < tam; i++)
	{
		if (vet[i] == sal)
		{
			acum = acum + vet[i];
		}
	}

	return acum;
}

int main(int argc, char *argv[])
{
	int opc = 0;

	while (opc != 99)
	{
		printf("\n");
		printf(":: Salario :: \n");
		printf("1. Adicionar (100 valores gerados randomicamente)\n");
		printf("3. Imprimir todos\n");
		printf("7. Somar salarios \n");
		printf("8. Somar salarios X\n");
		printf("18. Imprimir salarios menores que X\n");
		printf("99. Sair \n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opc);
		if (opc == 1)
		{
			adicionar(vsalarios);
		}
		else if (opc == 3)
		{
			imprimir(vsalarios);
		}
		else if (opc == 7)
		{
			float total;
			total = somarSalarios(vsalarios);
			printf("Salarios somados: %0.2f\n", total);
		}
		else if (opc == 8)
		{
			float total;
			total = somarSalariosX(vsalarios);
			printf("Salarios somados: %0.2f\n", total);
		}

		else if (opc == 18)
		{
			imprimirmenorq(vsalarios);
		}
	}

	return 0;
}
