#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "");
	
	int tipo;
	float valorCusto, valorVenda, valorTotal;
	
	printf("Digite o valor de custo do produto: ");
	scanf("%f", &valorCusto);
	printf("1-Perec�vel\n");
	printf("2-N�o Perec�vel\n");
	printf("Digite o numero do tipo do produto: ");
	scanf("%i", &tipo);
	valorVenda = valorCusto + (valorCusto * 0.4);
	if(tipo==1){
		if(valorVenda>20){
			valorTotal = valorVenda - (valorVenda*0.2);
			printf("Produto se encontra na Promo��o 1\n");
			printf("Valor Total: %.2f", valorTotal);		
		}
		else{
			if(valorVenda>10 && valorVenda<=20){
				valorTotal = valorVenda - (valorVenda*0.1);
				printf("Produto se encontra na Promo��o 2\n");
				printf("Valor Total: %.2f", valorTotal);
			}
			else{
				valorTotal = valorVenda - (valorVenda*0.15);
				printf("Produto se encontra na Promo��o 3\n");
				printf("Valor Total: %.2f", valorTotal);
			}			
		}
	}	
	else{
		if(tipo==2){
			if(valorVenda > 50){
				valorTotal = valorVenda - (valorVenda*0.05);
				printf("Produto se encontra na Promo��o 4\n");
				printf("Valor Total: %.2f", valorTotal);
			}else{
				valorTotal = valorVenda;
				printf("Produto se encontra na Promo��o 0\n");
				printf("Valor Total: %.2f", valorTotal);
			}
		}else{
			printf("Numero n�o corresponde a nenhum tipo!");
		}	
	}
	


	getch();
	return 0;
}
