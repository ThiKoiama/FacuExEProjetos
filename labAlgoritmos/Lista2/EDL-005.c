#include <stdio.h>
#include <stdlib.h>

int tam = 10;
int va[10], vb[10];

void iniciar(int vet[10])
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        vet[i] = 0;
    }
}

void adicionar(int vet[10])
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        printf("Digite o numero de posicao %d: ", i);
        scanf("%i", &vet[i]);
    }
}

float media(int vet[10])
{
    float media, acum;
    int i;
    for (i = 0; i < tam; i++)
    {
        acum = acum + vet[i];
    }
    media = acum / tam;

    return media;
}

int maiorValor(int vet[10])
{
    float maior;
    int i;
    maior = vet[0];
    for (i = 0; i < tam; i++)
    {
        if (vet[i] > maior)
            maior = vet[i];
    }
    return maior;
}

int menorValor(int vet[10])
{
    float menor;
    int i;
    menor = vet[0];
    for (i = 0; i < tam; i++)
    {
        if (vet[i] < menor)
            menor = vet[i];
    }
    return menor;
}

void imprimir(int vet[10])
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        printf("%d - %d. \n", i, vet[i]);
    }
}

void removerPosicao(int vet[10])
{
    int i = 0, p;
    printf("Digiteo valor da posicao que deseja apagar: ");
    scanf("%i", &p);
    for (i = 0; i < tam; i++)
    {
        if (i == p)
        {
            vet[i] = 0;
        }
    }
    printf("Apagado\n");
}
int contVet(int vet[10])
{
    int i = 0;
    int cont = 0;

    for (i = 0; i < tam; i++)
    {
        if (vet[i] != 0)
        {
            cont = cont + 1;
        }
    }

    return cont;
}

void par(int vetA[10], int vetB[10])
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        if (vetA[i] % 2 == 0)
        {
            vetB[i] = vetA[i];
        }
    }
}
void impar(int vetB[10], int vetA[10])
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        if (vetB[i] % 2 != 0)
        {
            vetA[i] = vetB[i];
        }
    }
}

int somar(int vet[10])
{
    int i;
    float acum = 0;

    for (i = 0; i < tam; i++)
    {
        acum = acum + vet[i];
    }

    return acum;
}

int main(int argc, char *argv[])
{
    int opc = 0, contA = 0, contB = 0, somaA = 0, somaB = 0, maiorA, maiorB, menorA, menorB;
    float medA = 0, medB = 0;
    while (opc != 99)
    {
        printf("\n");
        printf(":: MENU - VETORES A E B :: \n");
        printf("0. Iniciar Vetores  \n");
        printf("1. Adicionar Vetor A\n");
        printf("2. Adicionar Vetor B\n");
        printf("3. Remover do vetor A valor da posicao X\n");
        printf("4. Remover do vetor B valor da posicao X\n");
        printf("5. Imprimir vetor A\n");
        printf("6. Imprimir vetor B\n");
        printf("7. Contar valores vetor A\n");
        printf("8. Contar valores B\n");
        printf("9. Somar valores de cada vetor e apresentar\n");
        printf("10. Vetor com a maior quantidade de valores\n");
        printf("11. Vetor com a maior soma de valores\n");
        printf("12. Transferir valores Pares do vetor A para o B \n");
        printf("13. Transfeir valores Impares do vetor B para o A\n");
        printf("14. Media de valores de cada vetor\n");
        printf("15. Vetor que apresenta a maior media\n");
        printf("16. Maior valor de cada vetor\n");
        printf("17. Menor valor de cada vetor\n");
        printf("18. Vetor que apresenta o maior valor\n");
        printf("99. Sair \n");
        printf("----------------------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opc);
        if (opc == 0)
        {
            iniciar(va);
            iniciar(vb);
            printf("Vetores inicializados!\n");
        }
        else if (opc == 1)
        {
            adicionar(va);
        }
        else if (opc == 2)
        {
            adicionar(vb);
        }
        else if (opc == 3)
        {
            removerPosicao(va);
        }
        else if (opc == 4)
        {
            removerPosicao(vb);
        }
        else if (opc == 5)
        {
            imprimir(va);
        }
        else if (opc == 6)
        {
            imprimir(vb);
        }
        else if (opc == 7)
        {
            contA = contVet(va);
            printf("Ha %d valores no vetor A!", contA);
        }
        else if (opc == 8)
        {
            contB = contVet(vb);
            printf("Ha %d valores no vetor B!", contB);
        }
        else if (opc == 9)
        {
            somaA = somar(va);
            somaB = somar(vb);
            printf("Soma do vetor A e de: %d\nSoma do vetor B e de: %d", somaA, somaB);
        }
        else if (opc == 10)
        {
            if (contA > contB)
            {
                printf("O vetor A e o que tem mais valores");
            }
            else
            {
                printf("O vetor B e o que tem mais valores");
            }
        }
        else if (opc == 11)
        {
            if (somaA > somaB)
            {
                printf("O vetor A e o que tem a maior soma de valores");
            }
            else
            {
                printf("O vetor B e o que tem a maior soma de valores");
            }
        }
        else if (opc == 12)
        {
            par(va, vb);
        }
        else if (opc == 13)
        {
            impar(vb, va);
        }
        else if (opc == 14)
        {
            medA = media(va);
            medB = media(vb);
            printf("Media vetor A: %f\nMedia vetor B> %f", medA, medB);
        }
        else if (opc == 15)
        {
            if (medA > medB)
            {
                printf("Vetor A apresenta a maior media");
            }
            else
            {
                printf("Vetor B apresenta a maior media");
            }
        }
        else if (opc == 16)
        {
            maiorA = maiorValor(va);
            maiorB = maiorValor(vb);
            printf("Maior valor vetor A: %i\nMaior valor vetor B> %i", maiorA, maiorB);
        }
        else if (opc == 17)
        {
            menorA = menorValor(va);
            menorB = menorValor(vb);
            printf("Menor valor vetor A: %i\nMaior valor vetor B: %i", menorA, menorB);
        }
        else if (opc == 18)
        {
            if (maiorA > maiorB)
            {
                printf("O vetor A apresenta o maior valor");
            }
            else
            {
                printf("O vetor B apresenta o maior valor");
            }
        }
    }

    return 0;
}
