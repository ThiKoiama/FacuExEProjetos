#include <stdio.h>
#include <stdlib.h>

/*  MARÇAL: Exemplo de Filas Circulares com Vetores em C */
/*  no exemplo está sendo abordado TDE, TDA e Ponteiros  */


struct stAluno {
	int ra;
	char nome[10];
};

// variáveis para manipulação da fila circular
struct stAluno vetorAlunos[5];
int inicioFila = -1, finalFila = -1;
int numeroValoresFila = 0;

// variáveis auxiliares para manipulação fila
int tamanhoVetor = 5;

void inicializarFila(struct stAluno *vetor) {
	int i = 0;

	for (i = 0; i < tamanhoVetor; i++) {
		vetor[i].ra = -1;
		strcpy(vetor[i].nome, "NULL");
	}
}

void enfileirarAluno(struct stAluno *vetor, int ra, char nome[10]) {
	if (numeroValoresFila == tamanhoVetor) {
		printf("Fila cheia! \n");
	} else {
		if (finalFila == -1) {
			finalFila = 0;
			inicioFila = 0;
		} else {
			if (finalFila == (tamanhoVetor - 1)) {
				finalFila = 0;
			} else {
				finalFila = finalFila + 1;
			}
		}
		
		vetor[finalFila].ra = ra;
		strcpy(vetor[finalFila].nome, nome);

		numeroValoresFila = numeroValoresFila + 1;
		
		printf("ALUNO enfileirado! \n");
	}	
}

void desenfileirar() {
	if (numeroValoresFila == 0) {
		printf("Fila vazia! \n");
	} else {
		if (inicioFila == (tamanhoVetor - 1)) {
			inicioFila = 0;
		} else {
			inicioFila = inicioFila + 1;
		}
		
		numeroValoresFila = numeroValoresFila -1;
		
		if (numeroValoresFila == 0) {
			inicioFila = -1;
			finalFila = -1;
		}
		
		printf("ALUNO desenfileirado! \n");
	}	
}

void exibir(struct stAluno *vetor) {
	int p = inicioFila;
	int i = 0;

	printf("Inicio fila   : %d; \n", inicioFila);
	printf("Final fila    : %d; \n", finalFila);
	printf("Numero valores: %d; \n", numeroValoresFila);

	for (i = 0; i < tamanhoVetor; i++) {
		printf("POSICAO %d: RA: %d - NOME: %s; \n", p, vetor[p].ra, vetor[p].nome);
		
		if (p == (tamanhoVetor - 1)) {
			p = 0;
		} else {
			p = p + 1;
		}
	}	
}



int main(int argc, char *argv[]) {
	int opc = 0;
	
	while (opc != 9) {
		printf("\n");
		printf(":: FILA CIRCULAR RAs :: \n");
		printf("1. enfileirar           \n");
		printf("2. desenfileirar        \n");
		printf("3. exibir               \n");
		printf("9. Sair \n");
		printf("Digite a opcao desejada: ");
		
		scanf("%d", &opc);
		
		if (opc == 1) {
			int vra = 0;
			char vnome[10];
			
			printf("Digite o ra: ");
			scanf("%d", &vra);
			printf("Digite o nome: ");
			scanf("%s", &vnome);
			
			enfileirarAluno(vetorAlunos, vra, vnome);		
			
		} else if (opc == 2) {
			desenfileirar();
			
		} else if (opc == 3) {
			exibir(vetorAlunos);

		}		
	}
		
	return 0;
}

