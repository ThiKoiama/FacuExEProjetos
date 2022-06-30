#include <stdio.h>
#include <stdlib.h>

/* MARÇAL, J.                                             */
/* Manipulação de vetores com tipos de dados abastratos,  */
/* ponteiro e variáveis globais.                          */

/* variáveis globais */
int tamanhoVetor = 5;
int vetorIdades[5];

/* método (tda): obter posicao vacia vetor  */
int obterPosicaoVazia(int *vetor) {
	int i = 0;
	int posicaoVazia = -1;
	
	for(i = 0; i < tamanhoVetor; i++) {
		if ((vetor[i] == 0) && (posicaoVazia == -1)) {
			posicaoVazia = i;
		}
	}
	
	return posicaoVazia;
}

/* método (tda): adicionar idade */
int adicionarIdade(int idade, int *vetor) {
	int posicao = -1;
	int adicionou = 0;
	
	posicao = obterPosicaoVazia(vetor);
	
	if (posicao == -1) {
		adicionou = 0;
	} else {
		vetor[posicao] = idade;
		adicionou = 1;
	}	
	
	return adicionou;
}

/* método (tda): imprimir todos */
void imprimirTodos(int *vetor) {
	int i = 0;
	
	for(i = 0; i < tamanhoVetor; i++) {
		printf("Posicao: %d, valor: %d; \n", i, vetor[i]);
	}
}

/* método(tda): remover todos valores */
void removerTodos(int *vetor) {
	//pendente: deve percorrer todas as posições
	//e atribuir um valor que indique que a posi
	//ção está vazia.  
}

/* método(tda): remover valor posição X */
void removerTodos(int posicao, int *vetor) {
	//pendente: deve verificar se a posição infor
	//mada é válida, caso não seja, exibir mensa-
	//gem, caso seja, deverá atribuir um valor  q
	//indique que a posição está fazia.
}

/* método(tda): pesquisar valor */
void pesquisarIdade(int idade, int *vetor) {
	//pendente: percorrer todo o vetor e exibir a
	//posição onde a idade armazenada é igual a i
	//idade que está pesquisando.
}



int main(int argc, char *argv[]) {
	//carregando valores;
	adicionarIdade(15, vetorIdades);
	adicionarIdade(33, vetorIdades);
	adicionarIdade(18, vetorIdades);
	adicionarIdade(8, vetorIdades);
	
	//exibindo valores
	imprimirTodos(vetorIdades);
	
	return 0;
}
