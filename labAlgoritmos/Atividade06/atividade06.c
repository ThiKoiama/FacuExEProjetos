
#include <stdio.h>
#include <locale.h>

#define numeroElementos 1000
long long int vetorElementos[numeroElementos];

void carregarVetor()
{
    int i = 0;
    FILE *arq;
    arq = fopen("ED_Aula13b_Ordenacao_ArquivoCp.txt", "r");
    while (!feof(arq))
    {
        fscanf(arq, "%llu\n", &vetorElementos[i]);
        i++;
    }
    fclose(arq);
}

void imprimir(){
    int j;
    for (j = 0; j < numeroElementos; j++)
    {
        printf("%llu\n", vetorElementos[j]);
    }
}


void ordenarBubleSort(long long int *vetor) {
	int i, j;
    long long int aux = 0;
	
	for (i = 0; i < numeroElementos; i++) {
		for (j = 0; j < (numeroElementos - 1); j++) {
			if (vetor[j] > vetor[j + 1]) {
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
}

void shellsort(long long int *vetor)
{
    int i, j, k;
    long long int tmp;
    for (i = numeroElementos / 2; i > 0; i = i / 2)
    {
        for (j = i; j < numeroElementos; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (vetor[k+i] >= vetor[k])
                    break;
                else
                {
                    tmp = vetor[k];
                    vetor[k] = vetor[k+i];
                    vetor[k+i] = tmp;
                }
            }
        }
    }
}


int main(int argc, char *argv[])
{
    int opc = 0;

    while (opc != 9)
    {
        printf(" \n");
        printf(":: ORDENACAO ::..                  \n");
        printf("1. Carregar CP             \n");
        printf("2. Imprimir Vetor         \n");
        printf("3. Ordenar BubbleSort                   \n");
        printf("4. Ordenar ShellSort                  \n");
        printf("9. Sair                            \n");
        printf("Dig. opcao desejada:               \n");

        scanf("%d", &opc);

        if (opc == 1)
        {
            carregarVetor();
        }
        else if (opc == 2)
        {
           imprimir();
        }
        else if (opc == 3)
        {
          ordenarBubleSort(vetorElementos);
        }
        else if (opc == 4)
        {
          shellsort(vetorElementos);
        }
    }

    return 0;
}