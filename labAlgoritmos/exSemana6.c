#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "");

	float salBruto, prestacao;
	printf("Digite o seu sal�rio bruto: ");
	scanf("%f", &salBruto);
	printf("Digite o valor da presta��o desejada: ");
	scanf("%f", &prestacao);
	if(prestacao <= salBruto*0.3){
		printf("Empr�stimo pode ser concedido!");
	}
	else{
		printf("Emprestimo n�o pode ser concedido!");
	}
	getch();
	return 0;
}
