#include <stdio.h>
#include <stdlib.h>

/* MAR�AL, J. */ 
/* Exemplo de manipula��o de vetor com tipo de dado estruturado, */ 
/* tipo de dado abstrato e ponteiros.                            */


/* Tipo de dado estruturado */
struct tdeAluno {
	int codigo;
	char nome[5];
};

/* Vari�veis globais: vetor + tde; vari�vel auxiliar tamanho     */
struct tdeAluno vetorAlunos[5];  
int tamanhoVetor = 5;

/* Tda (m�todo) impress�o com argumento do tipo ponteiro         */
void imprimirTodos(struct tdeAluno *vetor) {
	int i = 0;
	
	for (i = 0; i < tamanhoVetor; i++) {
		printf("Posicao: %d: CODIGO: %d - NOME: %s; \n", i, vetor[i].codigo, vetor[i].nome);
	}	
}


int main(int argc, char *argv[]) {
	//Carregando valores vetor
	vetorAlunos[0].codigo = 10;
	strcpy(vetorAlunos[0].nome, "Ana");

	vetorAlunos[1].codigo = 20;
	strcpy(vetorAlunos[1].nome, "Beto");

	vetorAlunos[2].codigo = 30;
	strcpy(vetorAlunos[2].nome, "Carla");

	vetorAlunos[3].codigo = 40;
	strcpy(vetorAlunos[3].nome, "Danilo");

	//Impressao valores, passagem do vetor como par�metro
	imprimirTodos(vetorAlunos);
	
	return 0;
}

