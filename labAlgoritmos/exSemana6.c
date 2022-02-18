#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "");

	float salBruto, prestacao;
	printf("Digite o seu salário bruto: ");
	scanf("%f", &salBruto);
	printf("Digite o valor da prestação desejada: ");
	scanf("%f", &prestacao);
	if(prestacao <= salBruto*0.3){
		printf("Empréstimo pode ser concedido!");
	}
	else{
		printf("Emprestimo não pode ser concedido!");
	}
	getch();
	return 0;
}
