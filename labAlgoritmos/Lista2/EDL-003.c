#include <stdio.h>
#include <stdlib.h>

int tam = 10;
int vidades[10];

void iniciar(int vet[10])
{
	int i = 0;

	for (i = 0; i < tam; i++)
	{
		vet[i] = 0;
	}
}

void adicionar(int vet[10])
{
	int i = 0;

	for (i = 0; i < tam; i++)
	{
		printf("Digite a idade de posicao %d: ", i);
		scanf("%i", &vet[i]);
	}
}

void adicionarX(int vet[10])
{
	int p, idade;
	printf("Digite a idade: ");
	scanf("%f", &idade);
	printf("Digite a posicao que deseja armazenar: ");
	scanf("%i", &p);
	if (vet[p] == 0)
	{
		vet[p] = idade;
		printf("Armazenado");
	}
	else
	{
		printf("Posicao Ocupada");
	}
}

int contVet(int vet[10])
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

void imprimirX(int vet[10])
{
	int i = 0, p;
	printf("Digite uma posicao: ");
	scanf("%i", &p);
	for (i = 0; i < tam; i++)
	{
		if (i == p)
		{
			printf("%i\n", vet[i]);
		}
	}
}

void removerIdade(int vet[10])
{
	int i = 0, p;
	printf("Digite a posicao que deseja apagar: ");
	scanf("%i", &p);
	for (i = 0; i < tam; i++)
	{
		if (i == p)
		{
			vet[i] = 0;
		}
	}
	printf("Apagado\n");
}

void remover(int vet[10])
{
	int i = 0;
	for (i = 0; i < tam; i++)
	{
		vet[i] = 0;
	}
	printf("Apagado\n");
}

void imprimir(int vet[10])
{
	int i = 0;

	for (i = 0; i < tam; i++)
	{
		printf("%d - %d. \n", i, vet[i]);
	}
}
void imprimirPares(int vet[10])
{
	int i = 0;

	for (i = 0; i < tam; i++)
	{
		if (vet[i] % 2 == 0)
		{
			printf("%d - %d. \n", i, vet[i]);
		}
	}
}

int somar(int vet[10])
{
	int i;
	int acum = 0;

	for (i = 0; i < tam; i++)
	{
		acum = acum + vet[i];
	}

	return acum;
}
int somarImpar(int vet[10])
{
	int i;
	int acum = 0;

	for (i = 0; i < tam; i++)
	{
		if (vet[i] % 2 != 0)
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
		printf(":: MENU - IDADES:: \n");
		printf("0. Iniciar Vetor  \n");
		printf("1. Adicionar\n");
		printf("2. Adicionar Idade na Posicao X \n");
		printf("3. Imprimir Posicao X\n");
		printf("4. Imprimir Todas\n");
		printf("5. Remover Idade da Posicao X\n");
		printf("6. Remover Todas\n");
		printf("7. Contas Idades\n");
		printf("8. Somar Idades\n");
		printf("9. Somar Idades Impares\n");
		printf("10. Imprimir Idades Pares\n");
		printf("99. Sair \n");
		printf("----------------------------------------\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opc);
		if (opc == 0)
		{
			iniciar(vidades);
			printf("Vetor inicializado!\n");
		}
		else if (opc == 1)
		{
			adicionar(vidades);
		}
		else if (opc == 2)
		{
			adicionarX(vidades);
		}
		else if (opc == 3)
		{
			imprimirX(vidades);
		}
		else if (opc == 4)
		{
			imprimir(vidades);
		}
		else if (opc == 5)
		{
			removerIdade(vidades);
		}
		else if (opc == 6)
		{
			remover(vidades);
		}
		else if (opc == 7)
		{
			int qtd;
			qtd = contVet(vidades);
			printf("Existem %d idades cadastradas!\n", qtd);
		}
		else if (opc == 8)
		{
			int soma;
			soma = somar(vidades);
			printf("Soma das idades e %d!\n", soma);
		}
		else if (opc == 9)
		{
			int soma;
			soma = somarImpar(vidades);
			printf("Soma das idades impares e %d!\n", soma);
		}
		else if (opc == 10)
		{
			imprimirPares(vidades);
		}
	}
	return 0;
}
