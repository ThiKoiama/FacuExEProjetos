#include <stdio.h>
#include <stdlib.h>

int tam = 10;
float valt[10];

void iniciar(float vet[10])
{
	int i = 0;

	for (i = 0; i < tam; i++)
	{
		vet[i] = 0;
	}
}

void adicionar(float vet[10])
{
	int p;
	float alt;
	printf("Digite a altura: ");
	scanf("%f", &alt);
	printf("Digite a posicao que deseja armazenar: ");
	scanf("%i", &p);
	if (p <= 10 && p >= 0)
	{
		vet[p] = alt;
		printf("Armazenado");
	}
	else
	{
		printf("Posicao nao existe");
	}
}

int contVet(float vet[10])
{
	int i = 0;
	int cont = 0;

	for (i = 0; i < tam; i++)
	{
		if (vet[i] != 0)
		{
			cont = cont + 1;
		}
	}

	return cont;
}

int contVetVaz(float vet[10])
{
	int i = 0;
	int cont = 0;

	for (i = 0; i < tam; i++)
	{
		if (vet[i] == 0)
		{
			cont = cont + 1;
		}
	}

	return cont;
}

void imprimirpesq(float vet[10])
{
	int i = 0, p;
	printf("Digite uma posicao: ");
	scanf("%i", &p);
	for (i = 0; i < tam; i++)
	{
		if (i == p)
		{
			printf("%0.2f\n", vet[i]);
		}
	}
}
float somar(float vet[10])
{
	int i;
	float acum = 0;

	for (i = 0; i < tam; i++)
	{
		acum = acum + vet[i];
	}

	return acum;
}

int main(int argc, char *argv[])
{
	int opc = 0;
	while (opc != 99)
	{
		printf("\n");
		printf(":: MENU :: \n");
		printf("0. Iniciar Vetor  \n");
		printf("1. Adicionar  \n");
		printf("2. Ler \n");
		printf("3. Somar\n");
		printf("4. Contar\n");
		printf("5. Contar posicoes vazias\n");
		printf("99. Sair \n");
		printf("----------------------------------------\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opc);
		if (opc == 0)
		{
			iniciar(valt);
			printf("Vetor inicializado!\n");
		}
		else if (opc == 1)
		{
			adicionar(valt);
		}
		else if (opc == 2)
		{
			imprimirpesq(valt);
		}
		else if (opc == 3)
		{
			float soma;
			soma = somar(valt);
			printf("Soma de %0.2f", soma);
		}
		else if (opc == 4)
		{
			int qtd;
			qtd = contVet(valt);
			printf("Existem %d alturass cadastradas!\n", qtd);
		}
		else if (opc == 5)
		{
			int qtd;
			qtd = contVetVaz(valt);
			printf("Existem %d vetores vazios!\n", qtd);
		}
	}

	return 0;
}
