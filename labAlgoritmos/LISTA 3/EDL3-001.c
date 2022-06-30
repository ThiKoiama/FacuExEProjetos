#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float totalPedido;
	char nomeMot[20];
	char placa[8];
}carro;

carro filaDrive[10];
int inicioFila = -1, finalFila = -1;
int numeroValoresFila = 0;
int tamanhoVetor = 10;


void metodo(carro *vetor) {
	int p = inicioFila;
	int i = 0;
	int soma, pedios;
	float media;
	if (numeroValoresFila == 0) {
		printf("Fila vazia! \n");
	} 
	for (i = 0; i < tamanhoVetor; i++) {
        if (p == (tamanhoVetor - 1)) {
			p = 0;
		} else {
			p = p + 1;
		}
		if(p >= inicioFila && p<=finalFila){   
            soma = soma + vetor[p].totalPedido;
        }	   
}
	media = soma/numeroValoresFila;
	printf("Soma total dos pedidos: %s\nNumero de pedidos existentes: %s\n Valor medio dos pedidos: %s ",soma,numeroValoresFila,media);

}


int main(int argc, char *argv[]) {
	metodo(filaDrive);
    return 0;
}