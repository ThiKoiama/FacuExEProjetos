#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ex3 */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"");
	int n1,n2,n3;
	
	printf("Digite o primeiro número: ");
	scanf("%i", &n1);
	printf("Digite o segundo número: ");
	scanf("%i", &n2);
	printf("Digite o terceiro número: ");
	scanf("%i", &n3);
	
	if(n1 == n2 || n1==n3 || n2==n3){
		printf("Não são permitidos números repetidos!");	
	}else if(n1>n2 && n1>n3 && n2>n3 ){
	 	printf("%i, %i, %i", n3,n2,n1);
	}
	else if(n1>n2 && n1>n3 && n3>n2){
	 	printf("%i, %i, %i", n2,n3,n1);
	}
	else if(n2>n1 && n2>n3 && n1>n3){
	 	printf("%i, %i, %i", n3,n1,n2);
	}
	else if(n2>n1 && n2>n3 && n3>n1){
	 	printf("%i, %i, %i", n1,n3,n2);
	}
	else if(n3>n1 && n3>n2 && n2>n1){
	 	printf("%i, %i, %i", n1,n2,n3);
	}
	else{
		printf("%i, %i, %i", n1,n3,n2);
	}
	return 0;
}
