#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ex1 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"");
	float n1,n2;
	
	printf("Digite o primeiro número: ");
	scanf("%f", &n1);
	printf("Digite o segundo número: ");
	scanf("%f", &n2);
	
	if(n1 == n2){
		printf("Os números são iguais");	
	}else if(n1>n2){
	 	printf("O primeiro valor é maior que o segundo!");
	}
	else{
		printf("O segundo valor é maior que o primeiro!");
	}
	
	
	return 0;
}
