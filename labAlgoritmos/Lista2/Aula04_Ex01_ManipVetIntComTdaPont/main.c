#include <stdio.h>
#include <stdlib.h>

/* MAR�AL, J.                                             */
/* Manipula��o de vetores com tipos de dados abastratos,  */
/* ponteiro e vari�veis globais.                          */

/* vari�veis globais */
int tamanhoVetor = 5;
int vetorIdades[5];

/* m�todo (tda): obter posicao vacia vetor  */
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

/* m�todo (tda): adicionar idade */
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

/* m�todo (tda): imprimir todos */
void imprimirTodos(int *vetor) {
	int i = 0;
	
	for(i = 0; i < tamanhoVetor; i++) {
		printf("Posicao: %d, valor: %d; \n", i, vetor[i]);
	}
}

/* m�todo(tda): remover todos valores */
void removerTodos(int *vetor) {
	//pendente: deve percorrer todas as posi��es
	//e atribuir um valor que indique que a posi
	//��o est� vazia.  
}

/* m�todo(tda): remover valor posi��o X */
void removerTodos(int posicao, int *vetor) {
	//pendente: deve verificar se a posi��o infor
	//mada � v�lida, caso n�o seja, exibir mensa-
	//gem, caso seja, dever� atribuir um valor  q
	//indique que a posi��o est� fazia.
}

/* m�todo(tda): pesquisar valor */
void pesquisarIdade(int idade, int *vetor) {
	//pendente: percorrer todo o vetor e exibir a
	//posi��o onde a idade armazenada � igual a i
	//idade que est� pesquisando.
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
