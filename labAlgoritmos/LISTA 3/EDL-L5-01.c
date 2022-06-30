#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    float totalPedido;
	char nomeMot[20];
	char placa[8];
}carro;

carro vetorDrive[10];
int inicioFila = -1, finalFila = -1;
int numeroValoresFila = 0;

int tamanhoVetor = 10;

void inicializarFila(carro *vetor) {
	int i = 0;

	for (i = 0; i < tamanhoVetor; i++) {
		strcpy(vetor[i].placa, "NULL");
		strcpy(vetor[i].nomeMot, "NULL");
        vetor[i].totalPedido = 0;
	}
}

void enfileirarCarro(carro *vetor, float totalPedido, char nomeMot[20], char placa[8]) {
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
		
		vetor[finalFila].totalPedido = totalPedido;
		strcpy(vetor[finalFila].nomeMot, nomeMot);
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
		printf("POSICAO %d: Nome do motorista: %s - Placa: %s\n", p, vetor[p].nomeMot, vetor[p].placa);
		if (p == (tamanhoVetor - 1)) {
			p = 0;
		} else {
			p = p + 1;
		}
	}	
}

//ZUADO
void pesqPlaca(carro *vetor, char placa[8]){
	int i = 0;
    char estaOunao[30];
    int p = inicioFila;
    for (i = 0; i < tamanhoVetor; i++) {
        if (p == (tamanhoVetor - 1)) {
			p = 0;
		} else {
			p = p + 1;
		}
		if(p >= inicioFila && p<=finalFila){   
            if (strcmp(vetor[p].placa, placa)){
                strcpy(estaOunao, "O veiculo esta na fila");
			}
            else{
                strcpy(estaOunao, "O veiculo nao esta na fila");	
			}
        }
		
            
}
		printf("%s", estaOunao);

}



int main(int argc, char *argv[]) {
	int opc = 0;
	
	while (opc != 9) {
		printf("\n");
		printf(":: FILA CIRCULAR DRIVE THRU :: \n");
        printf("0. Inicializar vetor           \n");
		printf("1. Enfileirar           \n");
		printf("2. Desenfileirar        \n");
		printf("3. Listar Fila              \n");
		printf("4. Numero de veiculos para atender              \n");
		printf("5. Pesquisar placa               \n");
		printf("9. Sair \n");
		printf("Digite a opcao desejada: ");
		
		scanf("%d", &opc);
		
        if(opc ==0 ){
            inicializarFila(vetorDrive);
        }

		else if (opc == 1) {
			float vtotal = 0;
			char vplaca[8];
			char vnome[20];

			printf("Digite a placa do carro: ");
			scanf("%s", &vplaca);
			printf("Digite o nome do motorista: ");
			scanf("%s", &vnome);
            printf("Digite o valor do pedido: ");
            scanf("%f", &vtotal);
			
			enfileirarCarro(vetorDrive, vtotal, vnome, vplaca);		
			
		} else if (opc == 2) {
			desenfileirar();
			
		} else if (opc == 3) {
			exibir(vetorDrive);
		} else if (opc == 4) {
            printf("O numero de veiculos na fila e de: %i ", numeroValoresFila);
		} else if (opc == 5) {
			char placa[8];
            
            printf("Digite a placa que deseja pesquisar: ");
            scanf("%s", &placa);
            
            pesqPlaca(vetorDrive, placa);
		}		
    }
    return 0;
}