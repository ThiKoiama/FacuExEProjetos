#include <stdio.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL, "");
	
	int qtdPao, qtdBroa;
	float total, guardar;
	
	printf("Digite a quantidade de pães vendidos:\n");
	scanf("%i", &qtdPao);
	printf("Digite a quantidade de broas vendidas:\n");
	scanf("%i", &qtdBroa);
	total = (qtdPao*0.12)+(qtdBroa*1.5);
	guardar = total *0.1;
	printf("Arrecadou ao total: %.2f\n", total);
	printf("Deve guardar na poupança: %.2f\n", guardar);

	getch();
	return 0;
}
