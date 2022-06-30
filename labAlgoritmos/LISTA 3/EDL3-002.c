#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int code;
    float height;
    float width;
    float profundity;
    char brand[15];
    char company[15];
} containner;

containner PilhaContainners[10];
int tamanhoVetor = 10;
int topoPilha = -1;

void push(containner novoCont, containner *vetor)
{
    if (topoPilha == tamanhoVetor - 1)
    {
        printf("Lista de containers cheia! \n");
    }
    else
    {
        topoPilha = topoPilha + 1;
        vetor[topoPilha].code = novoCont.code;
        vetor[topoPilha].height = novoCont.height;
        vetor[topoPilha].width = novoCont.width;
        vetor[topoPilha].profundity = novoCont.profundity;
        strcpy(vetor[topoPilha].brand, novoCont.brand);
        strcpy(vetor[topoPilha].company, novoCont.company);
        printf("Containner cadastrada na posicao: %d\n", topoPilha);
    }
}

void pop(containner *vetor)
{
    if (topoPilha == -1)
    {
        printf("Pilha vazia! \n");
    }
    else
    {
        topoPilha = topoPilha - 1;
        printf("Desempilhada posicao: %d \n", topoPilha + 1);
    }
}

void isEmpty()
{
    if (topoPilha == -1)
    {
        printf("Pilha vazia! \n");
    }
    else{
        printf("Nao esta vazio!");
    }
}

void isFull()
{
    if (topoPilha == tamanhoVetor - 1)
    {
        printf("Lista de pedidos cheia! \n");
    }
    else{
        printf("Nao esta cheia");
    }
}

int getNumberElements(containner *vetor)
{
    int teto = -1, count = 0;

    for (teto = topoPilha; teto >= 0; teto--)
    {
        count += 1;
    }
    return count;
}

void printAll(containner *vetor)
{
    int teto = -1;

    if (topoPilha == -1)
    {
        printf("Pilha vazia! \n");
    }
    else
    {
        for (teto = topoPilha; teto >= 0; teto--)
        {
            printf(" \n");
            printf("%d - Codigo Containner %d, Altura: %0.2f, Largura: %0.2f, Profundidade: %0.2f, Marca: %s, Empresa: %s\n", teto, vetor[teto].code, vetor[teto].height, vetor[teto].width, vetor[teto].profundity, vetor[teto].brand, vetor[teto].company);
        }
    }
}

void printEnterp(containner pesq, containner *vetor)
{
    int teto = -1;

    if (topoPilha == -1)
    {
        printf("Pilha vazia! \n");
    }
    else
    {
        for (teto = topoPilha; teto >= 0; teto--)
            if (strcmp(pesq.company,vetor[teto].company) == 0 )
            {
                printf(" \n");
                printf("%d - Codigo Containner %d, Altura: %0.2f, Largura: %0.2f, Profundidade: %0.2f, Marca: %s, Empresa: %s\n", teto, vetor[teto].code, vetor[teto].height, vetor[teto].width, vetor[teto].profundity, vetor[teto].brand, vetor[teto].company);
            }       
    }
}

void printCode(containner pesq, containner *vetor)
{
    int teto = -1;

    if (topoPilha == -1)
    {
        printf("Pilha vazia! \n");
    }
    else
    {
      
      
        for (teto = topoPilha; teto >= 0; teto--)
            if (pesq.code == vetor[teto].code)
            {
                printf(" \n");
                printf("%d - Codigo Containner %d, Altura: %0.2f, Largura: %0.2f, Profundidade: %0.2f, Marca: %s, Empresa: %s\n", teto, vetor[teto].code, vetor[teto].height, vetor[teto].width, vetor[teto].profundity, vetor[teto].brand, vetor[teto].company);
            }
    }
}

void printTop(containner *vetor)
{
    int teto = topoPilha;

    printf(" \n");
    printf("%d - Codigo Containner %d, Altura: %0.2f, Largura: %0.2f, Profundidade: %0.2f, Marca: %s, Empresa: %s\n", teto, vetor[teto].code, vetor[teto].height, vetor[teto].width, vetor[teto].profundity, vetor[teto].brand, vetor[teto].company);
}

void remover(containner *vetor)
{
    int teto = -1;

    if (topoPilha == -1)
    {
        printf("Cadastro vazia! \n");
    }
    else
    {

        topoPilha = topoPilha - 1;
        printf("Desempilhada posicao: %d \n", topoPilha + 1);
    }
}

int main()

{
    int opc = 0;
    
    containner containners;

    while (opc != 10)
    {
        printf(" \n");
        printf(":: Containners :: \n");
        printf("1. Cadastrar (Push)\n");
        printf("2. Apagar (Pop) \n");
        printf("3. Esta Vazio? \n");
        printf("4. Esta Cheio?\n");
        printf("5. Imprimir todos\n");
        printf("6. Imprimir a partir da empresa\n");
        printf("7. Imprimir o elemento do topo\n");
        printf("8. Imprimir a partir de codigo\n");
        printf("9. Quantidade de elementos na pilha\n");
        printf("10. Sair\n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &opc);

        if (opc == 1)
        {
            printf("Digite o codigo do containner: ");
            scanf("%i", &containners.code);
            printf("Digite a altura do containner: ");
            scanf("%f", &containners.height);
            printf("Digite a largura do containner: ");
            scanf("%i", &containners.width);
            printf("Digite a profundidade do containner: ");
            scanf("%i", &containners.profundity);
            printf("Digite a marca do containner: ");
            scanf("%s", containners.brand);
            printf("Digite a empresa do containner: ");
            scanf("%s", containners.company);
            push(containners, PilhaContainners);
        }

        else if (opc == 2)
        {
            pop(PilhaContainners);
        }
        else if (opc == 3)
        {
            isEmpty(PilhaContainners);
        }
        else if (opc == 4)
        {
            isFull(PilhaContainners);
        }
        else if (opc == 5)
        {
            printAll(PilhaContainners);
        }
        else if (opc == 6)
        {
            printf("Digite a empresa do containner: ");
            scanf("%s", containners.company);
            printEnterp(containners, PilhaContainners);
        }
        else if (opc == 7)
        {
            printTop(PilhaContainners);
        }
        else if (opc == 8)
        {
            printf("Digite o codigo do containner: ");
            scanf("%i", &containners.code);
            printCode(containners, PilhaContainners);
        }
        else if (opc == 9)
        {
            int qtd = 0;
            qtd = getNumberElements(PilhaContainners);
            printf("Quantidade de containners registrados: %d", qtd);
        }
    }

    return 0;
}
