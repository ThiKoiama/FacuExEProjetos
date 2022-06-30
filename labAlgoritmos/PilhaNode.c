#include <stdio.h>
#include <stdlib.h>

/* MAR�AL, J. - Exemplo de Pilha com Ponteiros */

// Tde: Defini��o do elemento que ser� empilhado.
struct tdeElemento {
	// atributos
	int idade;
	
	//ponteiro liga��o
	struct tdeElemento *no;
};

// Defini��o de tipos
typedef struct tdeElemento *tipoPilha; // Defini��o tipo: Ponteiro do tipo tdeElemento. 
typedef tipoPilha pilha;               // Defini��o tipo: 'pilha' baseada em tipo Ponteiro.

// Vari�vel: topoPilha.
pilha topoPilha;

// Tda: M�todo de inicializa��o
tipoPilha* criar(pilha p) {
	p = NULL;
	return p;
}

// Tda: M�todo respons�vel por empilhar um novo elemento na pilha.
tipoPilha* empilhar(int vidade, pilha vtopo) {
	pilha elemento;
	
	elemento = malloc(sizeof(tipoPilha));
	elemento->idade = vidade;
	elemento->no = vtopo;
	
	return elemento;
}

// Tda: M�todo respons�vel por desempilhar um elemento da pilha. 
tipoPilha* desempilhar(pilha vtopo) {
	pilha aux;
	
	if (vtopo == NULL)	 {
		printf("Pilha vazia! \n");
		
		return;
	} else {
		aux = vtopo;
		
		aux = vtopo->no;
		free(vtopo);
		
		return aux;
	}	
}

// Tda: M�todo respons�vel por exibir os valores da pilha.
void imprimir (pilha vtopo) {
	pilha aux;
	
	if (vtopo == NULL)	 {
		printf("Pilha vazia! \n");
	} else {
		aux = vtopo;
		
		while (aux != NULL) {
			printf("%d \n", aux->idade);
			aux = aux->no;
		}
	}
}

// Tda: M�todo respons�vel por responder se a Pilha est� vazia.
int vazia (pilha vtopo) {
	// implementa��o pendente (aluno deve implementar)
	// deve retornar: 0 (falso) = cheia
	//                1 (verdadeiro) = vazia
	return -1;
}

// Tda: M�todo respons�vel por exibir o elemento do topo.
void topo (pilha vtopo) {
	// implementa��o pendente (aluno deve implementar)
	// dever� exibir mensagem caso esteja vazia ou 
	// o valor do elemento do topo
}

// Tda: M�todo respons�vel por exibir o n�mero de elementos da pilha.
int numeroElementos(pilha vtopo) {
	// implementa��o pendente (aluno deve implementar)
	// dever� exibir mensagem caso esteja vazia ou 
	// o n�mero de elementos presentes na pilha
	return -1;
}


int main(int argc, char *argv[]) {
	int opc = 0;
	
	topoPilha = criar(topoPilha);
	
	while (opc != 9) {
		printf("\n");
		printf(":: PILHA IDADES :: \n");
		printf("1. Empilhar        \n");
		printf("2. Desempilhar     \n");
		printf("3. Imprimir        \n");
		printf("4. ... \n");
		printf("9. Sair \n");
		printf("Digite a opcao desejada: ");
		
		scanf("%d", &opc);
		
		if (opc == 1) {
			int idade;
			scanf("%d", &idade);
			topoPilha = empilhar(idade, topoPilha);
			
		} else if (opc == 2) {
			topoPilha = desempilhar(topoPilha);	
			
		} else if (opc == 3) {			
			imprimir(topoPilha);

		}		
	}
		
	return 0;
}


