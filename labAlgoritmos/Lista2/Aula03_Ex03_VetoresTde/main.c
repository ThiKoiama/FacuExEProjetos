#include <stdio.h>
#include <stdlib.h>

struct tdeAluno {
	int ra;
	char nome[10];
	float peso;
};

int main(int argc, char *argv[]) {
	int opc = 0, i = 0;
	struct tdeAluno vAlunos[3];
	int tam = 3;
	
	while (opc != 9) {
		printf("\n");
		printf(":: LISTA ALUNOS :: \n");
		printf("1. Iniciar  \n");
		printf("2. Carregar \n");
		printf("3. Imprimir \n");
		printf("4. ... \n");
		printf("9. Sair \n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opc);
		
		if (opc == 1) {
			for (i = 0; i < tam; i++) {
				vAlunos[i].ra = 0;
				strcpy(vAlunos[i].nome, "NULL");
				vAlunos[i].peso = 0.0;	
			}
			
		} else if (opc == 2) {
			for (i = 0; i < tam; i++) {
				scanf("%d", &vAlunos[i].ra);
				scanf("%s", &vAlunos[i].nome);
				scanf("%f", &vAlunos[i].peso);				
			}			
			
		} else if (opc == 3) {
			for (i = 0; i < tam; i++) {
				printf("%d - %s - %f \n", vAlunos[i].ra, vAlunos[i].nome, vAlunos[i].peso);
			}			
			
		} else if (opc == 4) {
			printf("Opcao 4 selecionada! \n");	
			
		}		
	}
		
	return 0;
}

