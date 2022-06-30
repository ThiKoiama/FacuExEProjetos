#include <stdio.h>
#include <stdlib.h>

int tam = 100;
float vsalarios[100];

void iniciar(float vet[100])
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        vet[i] = 0;
    }
}

/*
void adicionar(float vet[100]) {
    int i = 0;

    for (i = 0; i < tam; i++) {
        scanf("%f", &vet[i]);
    }
}*/

void adicionar(float vet[100])
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        vet[i] = rand();
    }
    printf("100 valores adicionados no vetor!\n");
}

void removerY(float vet[100])
{
    int p, i = 0;
    printf("Digite a posicao do vetor que deseja apagar: ");
    scanf("%i", &p);
    for (i = 0; i < tam; i++)
    {
        if (i == p)
        {
            vet[i] = 0.0;
        }
    }
    printf("Apagado\n");
}

void removerSal(float vet[100])
{
    int i = 0;
    float sal = 0;
    printf("Digite o salario que deseja apagar: ");
    scanf("%f", &sal);
    for (i = 0; i < tam; i++)
    {
        if (vet[i] == sal)
        {
            vet[i] = 0.0;
        }
    }
    printf("Apagado\n");
}

void remover(float vet[100])
{
    int i = 0;
    for (i = 0; i < tam; i++)
    {
        vet[i] = 0.0;
    }
    printf("Apagado\n");
}

void imprimir(float vet[100])
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        printf("%d - %0.2f. \n", i, vet[i]);
    }
}

void pesqSal(float vet[100])
{
    float sal;
    int i = 0;
    printf("Digite o salario que deseja pesquisar: ");
    scanf("%f", &sal);
    for (i = 0; i < tam; i++)
    {
        if (vet[i] == sal)
        {
            printf("Salario existe na posicao %d\n", i);
        }
    }
}

void addSalVet(float vet[100])
{
    float sal;
    int p, i = 0;

    printf("Digite o salario que deseja adicionar: ");
    scanf("%f", &sal);
    printf("Digite em qual posicao quer salvar o salario (vetor tem que estar vazio): ");
    scanf("%i", &p);
    for (i = 0; i < tam; i++)
    {
        if (i == p && vet[i] == 0)
        {
            vet[p] = sal;
        }
        printf("Salvo\n");
    }
}

void imprimirmenorq(float vet[100])
{
    int i = 0;
    float menor;
    printf("Digite um salario: ");
    scanf("%f", &menor);
    for (i = 0; i < tam; i++)
    {
        if (vet[i] < menor)
        {
            printf("%0.2f\n", vet[i]);
        }
    }
}

int quantSal(float vet[100])
{
    int i = 0;
    int cont = 0;
    float sal;
    printf("Digite o salario: ");
    scanf("%f", &sal);
    for (i = 0; i < tam; i++)
    {
        if (vet[i] == sal)
        {
            cont = cont + 1;
        }
    }

    return cont;
}

float somarSalarios(float vet[100])
{
    int i;
    float acum = 0;

    for (i = 0; i < tam; i++)
    {
        acum = acum + vet[i];
    }

    return acum;
}
float somarSalariosX(float vet[100])
{
    int i;
    float acum = 0, sal;
    printf("Digite o salario: ");
    scanf("%f", &sal);

    for (i = 0; i < tam; i++)
    {
        if (vet[i] == sal)
        {
            acum = acum + vet[i];
        }
    }

    return acum;
}

int contSal(float vet[100])
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

int contSalMaior(float vet[100])
{
    int i = 0;
    int cont = 0;
    float maior;
    printf("Digite o salario: ");
    scanf("%f", &maior);
    for (i = 0; i < tam; i++)
    {
        if (vet[i] > maior)
        {
            cont = cont + 1;
        }
    }

    return cont;
}

void imprimirSalPos(float vet[100])
{
    int pos, i = 0;
    printf("Digite a posicao: ");
    scanf("%i", &pos);
    for (i = 0; i < tam; i++)
    {
        if (i == pos)
        {
            printf("Salario e: %0.2f", vet[i]);
        }
    }
}

void maiorValor(float vet[100])
{
    float maior;
    int i;
    maior = vet[0];
    for (i = 0; i < tam; i++)
    {
        if (vet[i] > maior)
            maior = vet[i];
    }
    printf("Maior salario e: %0.2f\n", maior);
}

void menorValor(float vet[100])
{
    float menor;
    int i;
    menor = vet[0];
    for (i = 0; i < tam; i++)
    {
        if (vet[i] < menor)
            menor = vet[i];
    }
    printf("Menor salario e: %0.2f\n", menor);
}

void media(float vet[100])
{
    float media, acum;
    int i;
    for (i = 0; i < tam; i++)
    {
        acum = acum + vet[i];
    }
    media = acum / tam;
    printf("Media salarial de: %0.2f\n", media);
}

void aplicarAcres(float vet[100])
{
    int i;
    float p, porcent;
    printf("Digite quantos porcento em acrescimo para ser aplicado: ");
    scanf("%f", &p);
    porcent = p / 100;
    for (i = 0; i < tam; i++)
    {
        vet[i] = (vet[i] * porcent) + vet[i];
    }
    printf("Aplicado\n");
}

void aplicarDesc(float vet[100])
{
    int i;
    float p, porcent, sal;
    printf("Digite um salario: ");
    scanf("%f", &sal);
    printf("Digite quantos porcento em desconto para ser aplicado: ");
    scanf("%f", &p);
    porcent = p / 100;
    for (i = 0; i < tam; i++)
    {
        if (vet[i] > sal)
        {
            vet[i] = vet[i] - (vet[i] * porcent);
        }
    }
    printf("Aplicado\n");
}

int main(int argc, char *argv[])
{
    int opc = 0;

    while (opc != 99)
    {
        printf("\n");
        printf(":: Salario :: \n");
        printf("0. Iniciar Vetor  \n");
        printf("1. Adicionar (100 valores gerados randomicamente)\n");
        printf("2. Remover posicao Y\n");
        printf("3. Imprimir todos\n");
        printf("----------------------------------------\n");
        printf("4. Pesquisar salario X \n");
        printf("5. Adicionar na posicao\n");
        printf("6. Pesquisar a quantidade salarios X \n");
        printf("7. Somar salarios \n");
        printf("8. Somar salarios X\n");
        printf("9. Contar salarios\n");
        printf("10. Contar salarios X\n");
        printf("11. Contar salarios maiores que X\n");
        printf("12. Maior salario \n");
        printf("13. Menor salario\n");
        printf("14. Media salarios\n");
        printf("15. Remover salarios valor X\n");
        printf("16. Remover todos salarios\n");
        printf("17. Imprimir salario posicao Y\n");
        printf("18. Imprimir salarios menores que X\n");
        printf("19. Aplicar acrescimo de Z%% em todos salarios\n");
        printf("20. Aplicar desconto de Z%% em salarios maiores que X\n");
        printf("99. Sair \n");
        printf("----------------------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opc);
        if (opc == 0)
        {
            iniciar(vsalarios);
            printf("Vetor inicializado!\n");
        }
        else if (opc == 1)
        {
            adicionar(vsalarios);
        }
        else if (opc == 2)
        {
            removerY(vsalarios);
        }
        else if (opc == 3)
        {
            imprimir(vsalarios);
        }
        else if (opc == 4)
        {
            pesqSal(vsalarios);
        }
        else if (opc == 5)
        {
            addSalVet(vsalarios);
        }
        else if (opc == 6)
        {
            int qtd = 0;
            qtd = quantSal(vsalarios);
            printf("Existem %d vetores com esse salario!\n", qtd);
        }
        else if (opc == 7)
        {
            float total;
            total = somarSalarios(vsalarios);
            printf("Salarios somados: %0.2f\n", total);
        }
        else if (opc == 8)
        {
            float total;
            total = somarSalariosX(vsalarios);
            printf("Salarios somados: %0.2f\n", total);
        }
        else if (opc == 9)
        {
            int qtd = 0;
            qtd = contSal(vsalarios);
            printf("Existem %d salarios no vetor!\n", qtd);
        }
        else if (opc == 10)
        {
            int qtd = 0;
            qtd = quantSal(vsalarios);
            printf("Existem %d vetores com esse salario!", qtd);
        }
        else if (opc == 11)
        {
            int qtd = 0;
            qtd = contSalMaior(vsalarios);
            printf("Existem %d vetores com salarios maiores!\n", qtd);
        }
        else if (opc == 12)
        {
            maiorValor(vsalarios);
        }
        else if (opc == 13)
        {
            menorValor(vsalarios);
        }
        else if (opc == 14)
        {
            media(vsalarios);
        }
        else if (opc == 15)
        {
            removerSal(vsalarios);
        }
        else if (opc == 16)
        {
            remover(vsalarios);
        }
        else if (opc == 17)
        {
            imprimirSalPos(vsalarios);
        }
        else if (opc == 18)
        {
            imprimirmenorq(vsalarios);
        }
        else if (opc == 19)
        {
            aplicarAcres(vsalarios);
        }
        else if (opc == 20)
        {
            aplicarDesc(vsalarios);
        }
    }

    return 0;
}
