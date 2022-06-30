#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ra;
    char nome[30];
    int idade;
    float valorMensalidade;
} aluno;

aluno VetorAlunos[100]; // MUDAR PARA 100

int tam = 100; // MUDAR PARA 100

void inicializandoVetor(aluno *vetor, int tam)
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        vetor[i].ra = 0;
        strcpy(vetor[i].nome, "NULL");
        vetor[i].idade = 0;
        vetor[i].valorMensalidade = 0;
    }
}

int obterPosicaoVazia(aluno *vetor, int tam)
{
    int i = 0;
    int posicao = -1;

    for (i = 0; i < tam; i++)
    {
        if ((vetor[i].ra == 0) && (posicao == -1))
        {
            posicao = i;
        }
    }

    return posicao;
}

void cadastrar(int ra, char nome[30], int idade, float valorMensalidade, aluno *vetor, int tam)
{
    int posicao = -1;

    posicao = obterPosicaoVazia(vetor, tam);

    if (posicao >= 0)
    {
        vetor[posicao].ra = ra;
        strcpy(vetor[posicao].nome, nome);
        vetor[posicao].idade = idade;
        vetor[posicao].valorMensalidade = valorMensalidade;
    }
}

void imprimirAluno(aluno *vetor, int tam, int ra)
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        if (vetor[i].ra == ra)
            printf(" RA: %d\nNome: %s\n Idade: %d\n Valor da mensalidade: %0.2f", vetor[i].ra, vetor[i].nome, vetor[i].idade, vetor[i].valorMensalidade);
    }
}

float mediaMensalidade(aluno *vetor, int tam)
{
    int i = 0;
    int contAlunos = 0;
    float somaMensalidades = 0;
    float media;
    for (i = 0; i < tam; i++)
    {
        if (vetor[i].ra != 0 && vetor[i].idade != 0)
        {
            contAlunos = contAlunos + 1;
            somaMensalidades = somaMensalidades + vetor[i].valorMensalidade;
        }
    }
    media = somaMensalidades/contAlunos;
   return media;
}

void remover(int ra, aluno *vetor, int tam)
{
    int i = 0;
    for (i = 0; i < tam; i++)
    {
        if (vetor[i].ra == ra)
        {
            vetor[i].ra = 0;
            strcpy(vetor[i].nome, "NULL");
            vetor[i].idade = 0;
            vetor[i].valorMensalidade = 0;
        }
    }
    printf("Aluno Removido!\n");
}

void maiorIdade(aluno *vetor, int tam)
{
    int maior = 0, i;

    for (i = 0; i < tam; i++)
    {
        if (vetor[i].ra > 0 && vetor[i].nome != "NULL" && vetor[i].idade != 0)
        {
            if (vetor[i].idade > maior)
            {
                maior = vetor[i].idade;
            }
        }
    }
    printf("A maior idade e: %d", maior);
}

void idades(aluno *vetor, int tam, int idade)
{
    int i = 0;
    int contAlunosMaior = 0, contAlunosMenor = 0;
    for (i = 0; i < tam; i++)
    {
        if (vetor[i].ra > 0 && vetor[i].nome != "NULL" && vetor[i].idade != 0)
        {
            if (vetor[i].idade > idade)
            {
                contAlunosMaior = contAlunosMaior + 1;
            }
            else
            {
                contAlunosMenor = contAlunosMenor + 1;
            }
        }
    }

    printf("Quantidade de maiores que a idade digitada: %d\nQuantidade de menores que a idade digitada: %d", contAlunosMaior, contAlunosMenor);
}


void acimaMedia(aluno *vetor, int tam)
{
    int i;
    float media = 0;
    media = mediaMensalidade(vetor, tam);
    for (i = 0; i < tam; i++)
    {
        if (vetor[i].ra > 0 && vetor[i].nome != "NULL" && vetor[i].idade != 0)
        {
            if (vetor[i].valorMensalidade > media)
            {
                printf("RA: %d\nNome: %s\nIdade: %d\nValor da mensalidade: %0.2f", vetor[i].ra, vetor[i].nome, vetor[i].idade, vetor[i].valorMensalidade);
                printf("\n");
            }
        }
    }
};
int main(int argc, char *argv[])
{
    int opc = 0;
    aluno alunos;
    while (opc != 9)
    {
        printf(" \n");
        printf(":: Vetor Alunos :: \n");
        printf("0. Inicializar Vetor\n");
        printf("1. Cadastrar\n");
        printf("2. Pesquisar \n");
        printf("3. Remover \n");
        printf("4. Maior Idade\n");
        printf("5. Media mensalidade\n");
        printf("6. Numeros de alunos acima e abaixo da idade X\n");
        printf("7. Relacao alunos com mensalidade acima da media\n");
        printf("9. Sair\n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &opc);

        if (opc == 0)
        {
            inicializandoVetor(VetorAlunos, tam);
        }
        else if (opc == 1)
        {
            printf("Digite o RA do aluno: ");
            scanf("%i", &alunos.ra);
            printf("Digite o nome do aluno: ");
            scanf("%s", &alunos.nome);
            printf("Digite a idade do aluno: ");
            scanf("%i", &alunos.idade);
            printf("Digite o valor da mensalidade do aluno: ");
            scanf("%f", &alunos.valorMensalidade);
            cadastrar(alunos.ra, alunos.nome, alunos.idade, alunos.valorMensalidade, VetorAlunos, tam);
        }
        else if (opc == 2)
        {
            printf("Digite o RA do aluno: ");
            scanf("%i", &alunos.ra);
            imprimirAluno(VetorAlunos, tam, alunos.ra);
        }
        else if (opc == 3)
        {
            printf("Digite o RA do aluno: ");
            scanf("%i", &alunos.ra);
            remover(alunos.ra, VetorAlunos, tam);
        }
        else if (opc == 4)
        {
            maiorIdade(VetorAlunos, tam);
        }
        else if (opc == 5)
        {
            float media;
           media = mediaMensalidade(VetorAlunos, tam);
           printf("Media mensalidade: %0.2f", media);
            
        }
        else if (opc == 6)
        {
            int idade;
            printf("Digite uma idade: ");
            scanf("%d", &idade);
            idades(VetorAlunos, tam, idade);
        }
        else if (opc == 7)
        {
            acimaMedia(VetorAlunos, tam);
        }
    }

    return 0;
}
