#include <stdio.h>
#include <stdlib.h>

int tam = 5;
int vidades[5];

void iniciar(int vet[5]) {
	int i = 0;
	
	for (i = 0; i < tam; i++) {
		vet[i] = -1;	
	}	
}

void carregar(int vet[5]) {
	int i = 0;
	
	for (i = 0; i < tam; i++) {
		scanf("%d", &vet[i]);
	}
}

void imprimir(int vet[5]) {
	int i = 0;
	
	for (i = 0; i < tam; i++) {
		printf("%d > %d. \n", i, vet[i]);	
	}	
}

int contarMaioresIdade(int vet[5]) {
	int i = 0;
	int cont = 0;
			
	for (i = 0; i < tam; i++) {
		if (vet[i] > 21) {
			cont = cont + 1;	
		}
	}
	
	return cont;
}

int somarIdades(int vet[5]) {
	int i, acum = 0;
			
	for (i = 0; i < tam; i++) {
		acum = acum + vet[i];
	}
	
	return acum;
}

int main(int argc, char *argv[]) {
	int opc = 0;
	int i = 0;
	
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
			iniciar(vidades);
			printf("vetor inicializado! \n");	
			
		} else if (opc == 2) {
			carregar(vidades);
			
		} else if (opc == 3) {
			imprimir(vidades);

		} else if (opc == 4) {
			int c = 0;
			
			c = contarMaioresIdade(vidades);
			
			printf("Encontrados %d maiores que 21. \n", c);
						
		} else if (opc == 5) {
			int ac = 0;
			
			ac = somarIdades(vidades);
			
			printf("Valor acumulado: %d \n", ac);
		}		
	}
		
	return 0;
}

