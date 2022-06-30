#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int caixas;
    float peso;
	char marca[20];
	char placa[8];
}caminhao;

caminhao vetorCaminhao[10];
int inicioFila = -1, finalFila = -1;
int numeroValoresFila = 0;

int tamanhoVetor = 10;

void inicializarFila(caminhao *vetor) {
	int i = 0;

	for (i = 0; i < tamanhoVetor; i++) {
		strcpy(vetor[i].placa, "NULL");
		strcpy(vetor[i].marca, "NULL");
        vetor[i].peso = 0;
        vetor[i].caixas =0;
	}
}

void enfileirarCaminhao(caminhao *vetor, float peso, int caixa, char marca[20], char placa[8]) {
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
		
		vetor[finalFila].peso = peso;
		vetor[finalFila].caixas = caixa;
        
		strcpy(vetor[finalFila].marca, marca);
		strcpy(vetor[finalFila].placa, placa);

		numeroValoresFila = numeroValoresFila + 1;
		
		printf("Caminhao enfileirado! \n");
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
		
		printf("Caminhao desenfileirado! \n");
	}	
}

void patioCheio(){
    char cheioOuNao[30];

    if(numeroValoresFila == tamanhoVetor){
        strcpy(cheioOuNao, "Pista cheia");
    }else{
        strcpy(cheioOuNao, "Pista nao esta cheia");
    }
    printf("%s", cheioOuNao);
}

//ZUADO

void pesqPlaca(caminhao *vetor, char placa[8]){
	int i = 0;
    int p = inicioFila;
    char estaOunao[30];
    
    for (i = 0; i < tamanhoVetor; i++) {


		 if (p == (tamanhoVetor - 1)) {
			p = 0;
		} else {
			p = p + 1;
		}  
        if(p >= inicioFila && p<=finalFila){   
            if (strcmp(placa, vetor[p].placa) == 0){
                strcpy(estaOunao, "O caminhao esta na fila");
            }
            else{
                strcpy(estaOunao, "O caminhao nao esta na fila");
            }
        }else{
                strcpy(estaOunao, "O caminhao nao esta na fila");
        }
        
	}	
            printf("%s", estaOunao);
}

void pesado(caminhao *vetor){
	int i = 0;
    int p = inicioFila;
    float maispesado = 0;
    int caixas = 0;
    char placa[8];
    char marca[20];
    for (i = 0; i < tamanhoVetor; i++) {
        if (p == (tamanhoVetor - 1)) {
			p = 0;
		} else {
			p = p + 1;
		}
           
        if(p >= inicioFila && p<=finalFila){   
            if (vetor[p].peso> maispesado){
                maispesado = vetor[p].peso;
                caixas = vetor[p].caixas;
                strcpy(placa, vetor[p].placa);
                strcpy(marca, vetor[p].marca);
            }
        }
	}
    printf("Mais pesado:\nPlaca: %s\nMarca: %s\nPeso: %f\nQtd caixas: %i", placa, marca, maispesado, caixas);	
}


void menosCaixas(caminhao *vetor){
	int i = 0;
    int p = inicioFila;
    float maispesado = 0;
    int caixas = 999999;
    char placa[8];
    char marca[20];
    for (i = 0; i < tamanhoVetor; i++) {
        if (p == (tamanhoVetor - 1)) {
			p = 0;
		} else {
			p = p + 1;
		}
           
        if(p >= inicioFila && p<=finalFila){   
            if (vetor[p].caixas < caixas){
                maispesado = vetor[p].peso;
                caixas = vetor[p].caixas;
                strcpy(placa, vetor[p].placa);
                strcpy(marca, vetor[p].marca);
            }
        }
	}
    printf("Menos Caixas:\nPlaca: %s\nMarca: %s\nPeso: %f\nQtd caixas: %i", placa, marca, maispesado, caixas);	
}

    
void pesoTotal(caminhao *vetor){
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
            soma = soma + vetor[p].peso;
        }
        
	}	
    printf("A soma total de pesos e %0.2f ", soma);
    }


int main(int argc, char *argv[]) {
	int opc = 0;
	
	while (opc != 9) {
		printf("\n");
		printf(":: FILA CIRCULAR CAMINHOES:: \n");
        printf("0. Inicializar vetor           \n");
		printf("1. Enfileirar           \n");
		printf("2. Desenfileirar        \n");
		printf("3. Patio cheio?            \n");
		printf("4. Pesquisar placa              \n");
		printf("5. Mais pesado               \n");
		printf("6. Peso total da fila               \n");
		printf("7. Menor numero de caixas               \n");
		printf("8. Numero de caminhoes na fila               \n");
		printf("9. Sair \n");
		printf("Digite a opcao desejada: ");
		
		scanf("%d", &opc);
		
        if(opc ==0 ){
            inicializarFila(vetorCaminhao);
        }

		else if (opc == 1) {
			float vpeso = 0;
			char vplaca[8];
			char vmarca[20];
            int vcaixas;

			printf("Digite a placa do caminhao: ");
			scanf("%s", &vplaca);
			printf("Digite o nome do motorista: ");
			scanf("%s", &vmarca);
            printf("Digite o peso da carga: ");
            scanf("%f", &vpeso);
			printf("Digite a quantidade de caixas: ");
            scanf("%i", &vcaixas);
			enfileirarCaminhao(vetorCaminhao, vpeso, vcaixas, vmarca, vplaca);		
			
		} else if (opc == 2) {
			desenfileirar();
			
		} else if (opc == 3) {
			patioCheio(vetorCaminhao);
		} else if (opc == 4) {
           	char placa[8];
            printf("Digite a placa que deseja pesquisar: ");
            scanf("%s", &placa);
            pesqPlaca(vetorCaminhao, placa);
		} else if (opc == 5) {
            pesado(vetorCaminhao);
		}		
		 else if (opc == 6) {
             pesoTotal(vetorCaminhao);
        }	
		else if (opc == 7) {
			menosCaixas(vetorCaminhao);
		}		
		 else if (opc == 8) {
			 printf("O numero de caminhoes na fila e de: %i ", numeroValoresFila);
		}		
    }
    return 0;
}