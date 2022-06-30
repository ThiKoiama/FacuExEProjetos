#include <stdio.h>
#include <stdlib.h>

/* MARÇAL, J. - Exemplo de Pilha com Ponteiros */

// Tde: Definição do elemento que será empilhado.
struct tdeElemento {
	// atributos
	int idade;
	
	//ponteiro ligação
	struct tdeElemento *no;
};

// Definição de tipos
typedef struct tdeElemento *tipoPilha; // Definição tipo: Ponteiro do tipo tdeElemento. 
typedef tipoPilha pilha;               // Definição tipo: 'pilha' baseada em tipo Ponteiro.

// Variável: topoPilha.
pilha topoPilha;

// Tda: Método de inicialização
tipoPilha* criar(pilha p) {
	p = NULL;
	return p;
}

// Tda: Método responsável por empilhar um novo elemento na pilha.
tipoPilha* empilhar(int vidade, pilha vtopo) {
	pilha elemento;
	
	elemento = malloc(sizeof(tipoPilha));
	elemento->idade = vidade;
	elemento->no = vtopo;
	
	return elemento;
}

// Tda: Método responsável por desempilhar um elemento da pilha. 
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

// Tda: Método responsável por exibir os valores da pilha.
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

// Tda: Método responsável por responder se a Pilha está vazia.
int vazia (pilha vtopo) {
	// implementação pendente (aluno deve implementar)
	// deve retornar: 0 (falso) = cheia
	//                1 (verdadeiro) = vazia
	return -1;
}

// Tda: Método responsável por exibir o elemento do topo.
void topo (pilha vtopo) {
	// implementação pendente (aluno deve implementar)
	// deverá exibir mensagem caso esteja vazia ou 
	// o valor do elemento do topo
}

// Tda: Método responsável por exibir o número de elementos da pilha.
int numeroElementos(pilha vtopo) {
	// implementação pendente (aluno deve implementar)
	// deverá exibir mensagem caso esteja vazia ou 
	// o número de elementos presentes na pilha
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


