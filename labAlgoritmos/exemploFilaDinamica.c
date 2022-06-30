#include <stdio.h>
#include <stdlib.h>

/* MAR�AL, J. - Filas Din�micas */

/* TDE: Defini��o do elemento que ser� utilizado na Fila */
struct tdeElemento {
	int codigo;
	
	/* Ponteiro/n� do tipo do elemento apontar� para o pr�ximo elemento */
	struct tdeElemento *proximo;
};

/* Vari�veis globais */
typedef struct tdeElemento tipoElemento;
int numeroElementos;


/* TDA: Inicializa a fila atribuindo NULL ao n� de liga��o */
void iniciar(tipoElemento *Fila) {
	Fila->proximo = NULL;
	numeroElementos = 0;	
}

/* TDA: Cria um elemento, carrega os valores e retorna o  ponteiro dele */
tipoElemento *criar() {
	tipoElemento *novo = (tipoElemento *) malloc(sizeof(tipoElemento));
	
	if (!novo){
		printf("Memoria insuficiente! \n");		
	} else {
		printf("Codigo: \n");
		scanf("%d", &novo->codigo);
		
		return novo;
	}
}

void enfileirar(tipoElemento *Fila) {
	/* Declaracao de ponteiro Elemento q/ recebe o endere�o de um elemento do tipo tde */
	tipoElemento *novo = criar();
	
	/* Atribui��o de NULL para o .proximo do novo elemento */
	novo->proximo = NULL;
	
	if (vazia(Fila)) {
		Fila->proximo = novo;
	} else {
		tipoElemento *tmp = Fila->proximo;
		
		/* Percorre a fila e localiza a ultima posi��o     */
		while (tmp->proximo != NULL){
			tmp = tmp->proximo;
		}
		
		tmp->proximo = novo;
	}
	
	numeroElementos = numeroElementos + 1;
}

/* TDA: Verifica se a fila est� vazia e retorna 0 = Sim (vazia) e 1 = N�o (cheia) */
int vazia(tipoElemento *Fila) {
	if (Fila->proximo == NULL)
		return 1;
	else 
		return 0;
}

/* TDA: Remove um elemento da Fila caso n�o esteja vazia e retorna um ponteiro do Pr�ximo elemento */
tipoElemento *desenfileirar(tipoElemento *Fila) {
	if (Fila->proximo == NULL) {
		printf("Vazia! \n");
		return NULL;
		
	} else {
		tipoElemento *tmp = Fila->proximo;
		Fila->proximo = tmp->proximo;
		
		numeroElementos = numeroElementos - 1;
		
		return tmp;
	}
}

/* TDA: Libera da mem�ria todos os elementos da Fila */
void liberar(tipoElemento *Fila) {	
	if (vazia(Fila) == 0) {
		tipoElemento *proximo, *atual;
		
		atual = Fila->proximo;
		while (atual != NULL) {
			proximo = atual->proximo;
			free(atual);
			atual = proximo;
		}	
	}	
}

/* TDA - Exibe na tela todos os elementos da Fila */
void imprimir(tipoElemento *Fila) {
	if (vazia(Fila) == 1) {
		printf("Vazia ! \n");
		return;
		
	} else {
		tipoElemento *tmp;
		tmp = Fila->proximo;
		
		while (tmp != NULL) {
			printf("Codigo: %d \n", tmp->codigo);
			tmp = tmp->proximo;
		}
	}
}


int main(int argc, char *argv[]) {
	int opc = 0;
	
	/* Criando um ponteiro do tipo Fila */
	tipoElemento *Fila = (tipoElemento *) malloc(sizeof(tipoElemento));
		
	/* Inicializando o ponteiro */
	iniciar(Fila);
	
	while(opc != 99) {
		printf(" \n");
		printf(":: FILA CLIENTES ::.. \n");
		printf("1. criar \n");
		printf("2. adicionar \n");
		printf("3. remover \n");
		printf("4. imprimir \n");
		printf("99. sair\n");
		printf("Dig. opcao desejada: \n");
		
		scanf("%d", &opc);
		
		if (opc == 1) {
			liberar(Fila);
			iniciar(Fila);
			
		} else if (opc == 2) {
			enfileirar(Fila);
			
		} else if (opc == 3) {			
			desenfileirar(Fila);
						
		} else if (opc == 4) {			
			imprimir(Fila);			
		}
	}
	
	free(Fila);
	return 0;
}


