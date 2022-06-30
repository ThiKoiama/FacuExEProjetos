#include <stdio.h>
#include <stdlib.h>

/* MARÇAL, J.                                        */
/* Manipulação de Pilhas de valores inteiros com uso */
/* de vetores e tipos de dados abstratos (tda)       */

int vetorIdades[5];
int tamanhoVetor = 5;
int topoPilha = -1;

void empilhar(int idade, int *vetor) {
	if (topoPilha == tamanhoVetor - 1) {
		printf("Pilha cheia! \n");
	} else {
		topoPilha = topoPilha + 1;
		vetor[topoPilha] = idade;
		printf("Empilhado posicao: %d \n", topoPilha);
	}
}

void desempilhar() {
	if (topoPilha == -1) {
		printf("Pilha vazia! \n");
	} else {
		topoPilha = topoPilha -1;
		printf("Desempilhada posicao: %d \n", topoPilha + 1);
	}
}

void imprimirTodos(int *vetor) {
	int teto = -1;
	
	if (topoPilha == -1) {
		printf("Pilha vazia! \n");
	} else {
		for (teto = topoPilha; teto >= 0; teto--) {
			printf("Posicao: %d - valor: %d; \n", teto, vetor[teto]);
		}
	}
}

int main(int argc, char *argv[]) {
	int opc = 0;
	int valor = 0;
	
	while (opc != 9) {
		printf(" \n");
		printf(":: PILHA DE IDADES :: \n");
		printf("1. empilhar           \n");
		printf("2. desempilhar        \n");
		printf("3. imprimir           \n");
		printf("9. Sair               \n");
		printf("Digite a opcao desejada: ");
		
		scanf("%d", &opc);
		
		if (opc == 1) {
			printf("Digite uma idade: ");	
			scanf("%d", &valor);
			
			empilhar(valor, vetorIdades);
			
		} else if (opc == 2) {
			desempilhar();

		} else if (opc == 3) {
			imprimirTodos(vetorIdades);
			
		}		
	}
	
	return 0;
}
