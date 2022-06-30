#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    float preco;
	char modelo[20];
	char placa[8];
}carro;

carro vetorCarros[5];
int inicioFila = -1, finalFila = -1;
int numeroValoresFila = 0;

int tamanhoVetor = 5;

void inicializarFila(carro *vetor) {
	int i = 0;

	for (i = 0; i < tamanhoVetor; i++) {
		strcpy(vetor[i].placa, "NULL");
		strcpy(vetor[i].modelo, "NULL");
        vetor[i].preco = 0;
	}
}

void enfileirarCarro(carro *vetor, float preco, char modelo[20], char placa[8]) {
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
		
		vetor[finalFila].preco = preco;
		strcpy(vetor[finalFila].modelo, modelo);
		strcpy(vetor[finalFila].placa, placa);

		numeroValoresFila = numeroValoresFila + 1;
		
		printf("Carro enfileirado! \n");
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
		
		printf("Carro desenfileirado! \n");
	}	
}

void exibir(carro *vetor) {
	int p = inicioFila;
	int i = 0;

	printf("Inicio fila   : %d; \n", inicioFila);
	printf("Final fila    : %d; \n", finalFila);
	printf("Numero valores: %d; \n", numeroValoresFila);

	for (i = 0; i < tamanhoVetor; i++) {
		printf("POSICAO %d: Modelo: %s - Placa: %s - Preco: %0.2f; \n", p, vetor[p].modelo, vetor[p].placa, vetor[p].preco);
		if (p == (tamanhoVetor - 1)) {
			p = 0;
		} else {
			p = p + 1;
		}
	}	
}

float maior(carro *vetor){
	int i = 0;
    int p = inicioFila;
    float maior = 0;
    
    for (i = 0; i < tamanhoVetor; i++) {
        if (p == (tamanhoVetor - 1)) {
			p = 0;
		} else {
			p = p + 1;
		}
           
        if(p >= inicioFila && p<=finalFila){   
            if (vetor[p].preco > maior){
                maior = vetor[p].preco;
            }
        }
	}	
    return maior;
}



void soma(carro *vetor){
    int i = 0;
    int p = inicioFila;
    float soma = 0;
    
    for (i = 0; i < tamanhoVetor; i++) {
        if (p == (tamanhoVetor - 1)) {
			p = 0;
		} else {
			p = p + 1;
		}
           
        if(p >= inicioFila && p<=finalFila){   
            soma = soma + vetor[p].preco;
        }
        
	}	
    printf("A soma e de %0.2f ", soma);
}

int main(int argc, char *argv[]) {
	int opc = 0;
	
	while (opc != 9) {
		printf("\n");
		printf(":: FILA CIRCULAR CARROS :: \n");
		printf("0. Inicializar vetor           \n");
		printf("1. Enfileirar           \n");
		printf("2. Desenfileirar        \n");
		printf("3. Imprimir               \n");
		printf("4. Maior valor               \n");
		printf("5. Soma todos valores               \n");
		printf("9. Sair \n");
		printf("Digite a opcao desejada: ");
		
		scanf("%d", &opc);
		

		if(opc ==0){
			inicializarFila(vetorCarros);
		}
		else if (opc == 1) {
			float vpreco = 0;
			char vplaca[8];
			char vmodelo[20];

			printf("Digite a placa do carro: ");
			scanf("%s", &vplaca);
			printf("Digite o modelo do carro: ");
			scanf("%s", &vmodelo);
            printf("Digite o preco do carro: ");
            scanf("%f", &vpreco);
			
			enfileirarCarro(vetorCarros, vpreco, vmodelo, vplaca);		
			
		} else if (opc == 2) {
			desenfileirar();
			
		} else if (opc == 3) {
			exibir(vetorCarros);
		} else if (opc == 4) {
			float maiorValor = maior(vetorCarros);
            printf("O maior valor e %0.2f: ", maiorValor);
		} else if (opc == 5) {
			soma(vetorCarros);
		}		
    }
    return 0;
}