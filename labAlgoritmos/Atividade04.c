#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct container
{
    int codigo;
    char fornecedor[25];
    float peso;
    struct container *no;
};

typedef struct container *tipoPilha;
typedef tipoPilha pilha;

pilha topoPilha;

tipoPilha *criar(pilha p)
{
    p = NULL;
    return p;
}

tipoPilha *empilhar(int vcodigo, char vfornecedor[25], float vpeso, pilha vtopo)
{
    pilha elemento;

    elemento = malloc(sizeof(tipoPilha));
    elemento->codigo = vcodigo;
    strcpy(elemento->fornecedor, vfornecedor);
    elemento->peso = vpeso;
    elemento->no = vtopo;
    return elemento;
}

tipoPilha *desempilhar(pilha vtopo)
{
    pilha aux;
    if (vtopo == NULL)
    {
        printf("Pilha vazia! \n");

        return;
    }
    else
    {
        aux = vtopo;

        aux = vtopo->no;
        free(vtopo);

        return aux;
    }
}

void imprimir(pilha vtopo)
{
    pilha aux;

    if (vtopo == NULL)
    {
        printf("Pilha vazia! \n");
    }
    else
    {
        aux = vtopo;

        while (aux != NULL)
        {
            printf("Codigo: %d, Fornecedor: %s, Peso: %0.2f\n", aux->codigo, aux->fornecedor, aux->peso);
            aux = aux->no;
        }
    }
}

int main(int argc, char *argv[])
{
    int opc = 0;

    topoPilha = criar(topoPilha);

    while (opc != 9)
    {
        printf("\n");
        printf(":: PILHA CONTAINERS :: \n");
        printf("1. Empilhar        \n");
        printf("2. Desempilhar     \n");
        printf("3. Imprimir        \n");
        printf("9. Sair \n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &opc);

        if (opc == 1)
        {
            int codigo;
            char fornecedor[25];
            float peso;
            printf("Digite o codigo do container: ");
            scanf("%d", &codigo);
            printf("Digite o fornecedor do container: ");
            scanf("%s", &fornecedor);
            printf("Digite o peso do container: ");
            scanf("%f", &peso);
            topoPilha = empilhar(codigo, fornecedor, peso, topoPilha);
        }
        else if (opc == 2)
        {
            topoPilha = desempilhar(topoPilha);
        }
        else if (opc == 3)
        {
            imprimir(topoPilha);
        }
    }

    return 0;
}
