#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int A;   /* variável do tipo inteira */
	int *P;  /* ponteiro para inteiro    */
	
	A = 125;
	P = &A;
	
	printf("Valor    A: %i \n", A);
	printf("Endereco A: %x \n", &A);
	
	printf(" \n");
	printf("Conteudo P: %x \n", P);
	printf("Endereco P: %x \n", &P);
	printf("Valor    P: %i \n", *P);
	
	printf(" \n");
	*P = 10;
	printf("Valor    A: %i \n", A);
	printf("Endereco A: %x \n", &A);
	
	
	
	
	
	return 0;
}
