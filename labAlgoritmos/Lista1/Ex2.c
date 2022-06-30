#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ex2 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"");
	float n1,n2,area;
	
	printf("Digite o valor da base do retângulo: ");
	scanf("%f", &n1);
	printf("Digite o valor da altura do retângulo: ");
	scanf("%f", &n2);
	area = n1*n2;
	printf("A área do retângulo é de %0.2f ", area);
	
	
	
	return 0;
}
