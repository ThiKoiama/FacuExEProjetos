#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int numero;
    char tamanho[5];
    int qtd;
} pedido;

pedido ListaPedidos[10];

int tam = 10;

void inicializandoVetor(pedido *vetor, int tam) {
	int i = 0;
	
	for (i = 0; i < tam; i++) {
		vetor[i].numero = 0;
		strcpy(vetor[i].tamanho, "NULL");
        vetor[i].qtd = 0;
	}	
}

int obterPosicaoVazia(pedido *vetor, int tam) {
	int i = 0;
	int posicao = -1;
	
	for (i = 0; i < tam; i++) {
		if ((vetor[i].numero == 0) && (posicao == -1)) {
			posicao = i;
		}
	}
	
	return posicao;
}

void adicionarPedido(int numero, char tamanho[5], int qtd, pedido *vetor, int tam) {
	int posicao = -1;
	
	posicao = obterPosicaoVazia(vetor, tam);
	
	if (posicao >= 0) {
		vetor[posicao].numero = numero;
		strcpy(vetor[posicao].tamanho, tamanho);
        vetor[posicao].qtd = qtd;
	}

	
}

void imprimirPedidos(pedido *vetor, int tam) {
	int i = 0;
	
	for (i = 0; i < tam; i++) {
        if(vetor[i].numero > 0)
		printf(" \n");
        printf("%d - Numero pedido: %d, Tamanho: %s, Qtd: %d\n", i+1, vetor[i].numero, vetor[i].tamanho, vetor[i].qtd);
	}	
}

void remover(int numero, pedido *vetor, int tam)
{
    int i = 0;
        for (i = 0; i < tam; i++){
        if(vetor[i].numero == numero){
            vetor[i].numero = 0;
            strcpy(vetor[i].tamanho, "NULL");
            vetor[i].qtd = 0;
        }
        }
        printf("Pedido Removido!\n");
    }

int qtdPagar(pedido *vetor,  int tam)
{
    int count = 0, i;

    for (i = 0; i < tam; i++)
    {
        if (vetor[i].numero > 0 && vetor[i].tamanho != "NULL" && vetor[i].qtd != 0)
        {
            count += 1;
        }
    }
    return count;
}



int main(int argc, char *argv[]) {
	int opc = 0;
    pedido pedidos;

    while (opc != 9)
    {
        printf(" \n");
        printf(":: Pastel Delicia - Pedidos :: \n");
        printf("0. Inicializar Vetor\n");
        printf("1. Cadastrar\n");
        printf("2. Imprimir \n");
        printf("3. Quantidades a pagar \n");
        printf("4. Pagamento\n");
        printf("9. Sair\n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &opc);
		
		if (opc == 0) {
			inicializandoVetor(ListaPedidos, tam);
			
		}  else if (opc == 1)
        {
            printf(" \n");
            printf(":: Tamanhos \n");
            printf("P - Pequeno \n");
            printf("M - Medio \n");
            printf("G - Grande\n");
            printf(" \n");
            printf("Digite o numero do pedido: ");
            scanf("%i", &pedidos.numero);
            printf("Digite o tamanho do pedido: ");
            scanf("%s", &pedidos.tamanho);
            printf("Digite a quantidade: ");
            scanf("%i", &pedidos.qtd);
            adicionarPedido(pedidos.numero, pedidos.tamanho, pedidos.qtd, ListaPedidos, tam);
        }
        else if (opc == 2)
        {
            imprimirPedidos(ListaPedidos, tam);
        }
        else if (opc == 3)
        {

            int count = qtdPagar(ListaPedidos, tam);
            printf("Quantidade de pedidos a serem pagos: %d\n", count);
        }
        else if (opc == 4)
        {

            int numero;
            printf("Digite o numero do pedido para ser removido: ");
            scanf("%i", &numero);
            remover(numero, ListaPedidos, tam);

        }
	}
	
	return 0;
}
