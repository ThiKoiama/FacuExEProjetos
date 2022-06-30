#include <stdio.h>
#include <stdlib.h>

/* Definindo o nó da lista */
struct nLista {
	int valor;
	
	struct nLista *prox;
	struct nLista *ante;
};


/* Definindo um tipo tLista baseado na estrutura do nLista */
typedef struct nLista tLista; 


/* Cria um novo elemento, atribui o valor informado e retorna 
   o valor  */
tLista *Criar(int valor) {
	tLista *temp;
	temp = (tLista *) malloc(sizeof temp);
	
	temp->valor = valor;
	temp->prox = NULL;
	temp->ante = NULL;
	
	return temp;
}


/* Insere um valor no final da lista */
void InserirFinal(int valor, tLista *lista) {
	tLista *temp;
	
	//Percorrendo até o ultimo elemento da lista.
	temp = lista;
	while ((temp->prox == NULL) == 0) {
		temp = temp->prox;
	}
	
	//Criando e inserindo o novo elemento no final da lista.
	temp->prox = (Criar(valor));
	
	//Vinculando o ponteiro ANTE ao final da lista.
	(temp->prox)->ante = temp;			
}


/* Percorre a lista do início para o final exibindo os 
   valores*/
void Imprimir (tLista *lista) {
	tLista *temp;
	
	temp = lista;
	
	while ((temp == NULL) == 0) {
		printf("%d \n", temp->valor);
		temp = temp->prox;
	} 
}


/* Remove o registro caso o localize */
tLista *Remover(int valor, tLista *lista) {
	tLista *temp;
	
	temp = lista;
	
	while ((temp == NULL) == 0) {		
		if (temp->valor == valor) 
		{	
			/* somente um registro */			
			if ((temp->ante == NULL) && (temp->prox == NULL)) {
				free(temp);
				temp = NULL;
				return temp;
			}
			else 
			{
				/* primeiro registro */
				if ((temp->ante == NULL) && (temp->prox != NULL)) {
					temp = temp->prox;
					temp->ante->prox = NULL;
					temp->ante = NULL;
					
					lista = temp;
					free(temp);
					return lista;										
				} 
				else 
				{					
					/* ultimo registro */
					if ((temp->ante != NULL) && (temp->prox == NULL)) {
						temp = temp->ante;
						temp->prox->ante = NULL;
						temp->prox = NULL;
						
						/* retorna a mesma lista */
						return lista;
					}
					else
					{
						/* registro do meio */
						if ((temp->ante != NULL) && (temp->prox != NULL)) {
							temp->ante->prox = temp->prox;
							temp->prox->ante = temp->ante;
							
							free(temp);
							/* retorna a mesma lista */
							return lista;
						}
					}
				}
				
			}			
		}
		else
		{
			temp = temp->prox;
		}
	}	
}


int main(int argc, char *argv[]) {
	int opc = 0;
	
	/* Declarando um ponteiro pLista do tipo tLista */
	tLista *pLista = (tLista *) malloc(sizeof(tLista));	
		
	while(opc != 99) {
		printf(" \n");
		printf(":: LISTA DUPLAMENTE ENCADEADA ::.. \n");
		printf("0. Criar                           \n");
		printf("1. Inserir inicio                  \n");
		printf("2. Inserir final                   \n");
		printf("3. Remover (valor X)               \n");
		printf("4. Remover inicio                  \n");
		printf("5. Remover final                   \n");
		printf("6. Imprimir inicio > final         \n");
		printf("7. Imprimir final > inicio         \n");
		printf("8. Localizar                       \n");
		printf("99. sair                           \n");
		printf("Dig. opcao desejada:               \n");
		
		scanf("%d", &opc);
		
		if (opc == 0) {
			int i;
			printf("Digite o valor desejado: ");
			scanf("%d", &i);
			
			pLista = Criar(i);
			
		} else if (opc == 1) {
			printf("Nao implementado! \n");
			
		} else if (opc == 2) {
			int i;
			printf("Digite o valor desejado: ");
			scanf("%d", &i);
			
			InserirFinal(i, pLista);
			
		} else if (opc == 3) {			
			int i;
			printf("Digite o valor desejado: ");
			scanf("%d", &i);
			
			pLista = Remover(i, pLista);
		
		} else if (opc == 4) {			
			printf("Nao implementado! \n");
			
		} else if (opc == 5) {			
			printf("Nao implementado! \n");

		} else if (opc == 6) {		
			Imprimir(pLista);
				
		} else if (opc == 7) {			
			printf("Nao implementado! \n");
		
		} else if (opc == 8) {			
			printf("Nao implementado! \n");
		}
	}
	
	return 0;
}


