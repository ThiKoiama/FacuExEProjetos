#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tdElemento
{
	int ra;
	char nome[20];
	float mensalidade;
	int idade;
	struct tdElemento *proximo;
} tdElemento;

typedef struct fila
{
	tdElemento *inicio;
	tdElemento *fim;
} fila;

int numeroElementos;

fila *criar()
{
	fila *q = (fila *)malloc(sizeof(fila));
	if (!q)
		exit(1);
	else
	{
		q->inicio = NULL;
		q->fim = NULL;
		numeroElementos = 0;
	}
	return q;
}

int filaVazia(fila *q)
{
	if (q == NULL)
		return 1;
	if (q->inicio == NULL)
		return 1;
	else
		return 0;
}

tdElemento lerValores()
{
	tdElemento elemento;
	printf("Digite o ra do aluno: ");
	scanf("%i", &elemento.ra);
	printf("Digite o nome do aluno: ");
	scanf("%s", &elemento.nome);
	printf("Digite a mensalidade do aluno: ");
	scanf("%f", &elemento.mensalidade);
	printf("Digite a idade do aluno: ");
	scanf("%i", &elemento.idade);
	return elemento;
}

tdElemento *alocar(tdElemento elemento)
{
	tdElemento *node = (tdElemento *)malloc(sizeof(tdElemento));
	if (!node)
		exit(1);
	else
	{
		node->ra = elemento.ra;
		strcpy(node->nome, elemento.nome);
		node->mensalidade = elemento.mensalidade;
		node->idade = elemento.idade;
		node->proximo = NULL;
		return node;
	}
}

void enfileirar(fila *q)
{
	tdElemento *node = alocar(lerValores());
	if (!node)
		exit(1);
	if (q->fim == NULL)
		q->inicio = node;
	else
		q->fim->proximo = node;
	q->fim = node;
	numeroElementos = numeroElementos + 1;
}

int desenfileirar(fila *q)
{
	if (filaVazia(q))
		return 0;

	tdElemento *node = q->inicio;
	q->inicio = q->inicio->proximo;
	numeroElementos = numeroElementos - 1;
	if (q->inicio != NULL)
		q->fim = NULL;
	free(node);
	return 1;
}

void imprimir(fila *q)
{
	if (filaVazia(q))
	{
		printf("Fila Vazia! \n");
		return;
	}
	tdElemento *aux = q->inicio;
	while (aux != NULL)
	{
		printf("%i, %s, %0.2f, %i", aux->ra, aux->nome, aux->mensalidade, aux->idade);
		printf("\n");
		aux = aux->proximo;
	}
	printf("\n");
}

void imprimirRA(fila *q, int ra)
{
	if (filaVazia(q))
	{
		printf("Fila Vazia! \n");
		return;
	}
	tdElemento *aux = q->inicio;
	while (aux != NULL)
	{
		if(ra == aux->ra )
		printf("%i, %s, %0.2f, %i", aux->ra, aux->nome, aux->mensalidade, aux->idade);
		aux = aux->proximo;
	}
	printf("\n");
}


void numElementos(){
	printf("O numero de Alunos e de: %i", numeroElementos);
}

int main(int argc, char *argv[])
{
	int opc = 0;
	fila *q = criar();

	while (opc != 99)
	{
		printf(" \n");
		printf(":: FILA ALUNOS ::\n");
		printf("1. Adicionar \n");
		printf("2. Atender \n");
		printf("3. Imprimir Todos \n");
		printf("4. Numero Alunos \n");
		printf("5. Localizar(RA)\n");
		printf("99. Sair\n");
		printf("Dig. opcao desejada: \n");

		scanf("%d", &opc);

		if (opc == 1)
		{

			enfileirar(q);
		}
		else if (opc == 2)
		{
			desenfileirar(q);
		}
		else if (opc == 3)
		{
			imprimir(q);
		}
		else if (opc == 4)
		{
			numElementos();
		}
		else if (opc == 5)
		{
			int ra;
			printf("Digite o ra: ");
			scanf("%i", &ra);
			imprimirRA(q, ra);

		}
	}

	return 0;
}
