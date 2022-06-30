#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int opc = 0;
	int i = 0;
	int vidades[5];
	int tam = 5;
	
	while (opc != 9) {
		printf("\n");
		printf(":: MANIPULANDO VETOR :: \n");
		printf("1. Iniciar  \n");
		printf("2. Carregar \n");
		printf("3. Imprimir \n");
		printf("4. Contar > 21 \n");
		printf("5. Somar       \n");
		printf("9. Sair \n");
		printf("Digite a opcao desejada: ");
		
		scanf("%d", &opc);
		
		if (opc == 1) {			
			for (i = 0; i < tam; i++) {
				vidades[i] = -1;	
			}
			
			printf("vetor inicializado! \n");	
			
		} else if (opc == 2) {
			for (i = 0; i < tam; i++) {
				scanf("%d", &vidades[i]);
			}
			
		} else if (opc == 3) {
			for (i = 0; i < tam; i++) {
				printf("%d > %d. \n", i, vidades[i]);	
			}			

		} else if (opc == 4) {
			int cont = 0;
			
			for (i = 0; i < tam; i++) {
				if (vidades[i] > 21) {
					cont = cont + 1;	
				}
			}
			
			printf("Encontrados %d maiores que 21. \n", cont);
						
		} else if (opc == 5) {
			int acum = 0;
			
			for (i = 0; i < tam; i++) {
				acum = acum + vidades[i];
			}
			
			printf("Valor acumulado: %d \n", acum);

		}		
	}
		
	return 0;
}

