#include <stdio.h>
#include <stdlib.h>

typedef struct tdElemento
{
	int cod;
	float valor;
	int idade;
	int cadeira;
	struct tdElemento *proximo;
} tdElemento;

typedef struct fila
{
	tdElemento *inicio;
	tdElemento *fim;
} fila;

int numeroElementos;
float somaValor = 0;

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
	printf("Digite o codigo do ingresso: ");
	scanf("%i", &elemento.cod);
	printf("Digite o valor do ingresso: ");
	scanf("%f", &elemento.valor);
	printf("Digite a idade do torcedor: ");
	scanf("%i", &elemento.idade);
	printf("Digite o numero da cadeira: ");
	scanf("%i", &elemento.cadeira);
	return elemento;
}

tdElemento *alocar(tdElemento elemento)
{
	tdElemento *node = (tdElemento *)malloc(sizeof(tdElemento));
	if (!node)
		exit(1);
	else
	{
		node->cod = elemento.cod;
		node->valor = elemento.valor;
		node->cadeira = elemento.cadeira;
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
		printf("%i, %0.2f, %i, %i", aux->cod, aux->valor, aux->idade, aux->cadeira);
		printf("\n");
		aux = aux->proximo;
	}
	printf("\n");
}


void somaValores(fila *q)
{
	if (filaVazia(q))
	{
		printf("Fila Vazia! \n");
		return;
	}
	tdElemento *aux = q->inicio;
	while (aux != NULL)
	{
		somaValor = somaValor + aux->valor;
		aux = aux->proximo;
	}
	printf("Soma dos valores e de: %0.2f", somaValor);
}


void numElementos(){
	printf("O numero de Alunos e de: %i", numeroElementos);
}

int maisNovo(fila *q){
	int menor=200;
	if (filaVazia(q))
	{
		printf("Fila Vazia! \n");
		return;
	}
	tdElemento *aux = q->inicio;
	while(aux != NULL){
		if(menor>aux->idade){
			menor = aux->idade;	
		}
		aux = aux->proximo;
	}
	return menor;
	
}
int maisVelho(fila *q){
	int maior=0;
	if (filaVazia(q))
	{
		printf("Fila Vazia! \n");
		return;
	}
	tdElemento *aux = q->inicio;
	while(aux != NULL){
		if(maior<aux->idade){
			maior = aux->idade;	
		}
		aux = aux->proximo;
	}
	return maior;
}
void imprimirMaisVelho(fila *q){
	if (filaVazia(q))
	{
		printf("Fila Vazia! \n");
		return;
	}
	tdElemento *aux = q->inicio;
	int maior = maisVelho(q);
	while (aux != NULL)
	{	
		if(maior == aux->idade){
		printf("Maior idade: %i, %0.2f, %i, %i\n", aux->cod, aux->valor, aux->idade, aux->cadeira);
		
		}
		aux = aux->proximo;
	}

}
void imprimirMaisNovo(fila *q){
	if (filaVazia(q))
	{
		printf("Fila Vazia! \n");
		return;
	}
	tdElemento *aux = q->inicio;
	int menor = maisNovo(q);
	while (aux != NULL)
	{	
		if(menor == aux->idade){
		printf("Menor idade: %i, %0.2f, %i, %i\n", aux->cod, aux->valor, aux->idade, aux->cadeira);
		
		}
		aux = aux->proximo;
	}

}

int main(int argc, char *argv[])
{
	int opc = 0;
	fila *q = criar();

	while (opc != 99)
	{
		printf(" \n");
		printf(":: FILA TORCEDORES ::\n");
		printf("1. Adicionar \n");
		printf("2. Desenfileirar \n");
		printf("3. Numero Torcedores \n");
		printf("4. Imprimir Todos \n");
		printf("5. Torcedor mais novo e mais velho\n");
		printf("6. Soma valores ingressos\n");
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
			numElementos();
		}
		else if (opc == 4)
		{
			imprimir(q);
			
		}
		else if (opc == 5)
		{
			imprimirMaisNovo(q);
			imprimirMaisVelho(q);
		}
		else if (opc == 6)
		{
			somaValores(q);
		}
	}

	return 0;
}
