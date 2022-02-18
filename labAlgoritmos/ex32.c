#include <stdio.h>
#include <locale.h>
int main()
{
    int qtdLata, qtdGarrafa1, qtdGarrafa2;
    float qtdLitros;
    
    setlocale(LC_ALL, "");
    printf("Digite a quantidade de latinhas compradas: ");
    scanf("%i", &qtdLata);
    printf("Digite a quantidade de Garrafas de 600mL compradas: ");
    scanf("%i", &qtdGarrafa1);
    printf("Digite a quantidade de Garrafas de 2L compradas: ");
    scanf("%i", &qtdGarrafa2);
    qtdLitros = (qtdLata * 0.35) + (qtdGarrafa1 * 0.6) + (qtdGarrafa2 * 2);
    printf("Quantidade de litros comprados foram: %.2f", qtdLitros);
    getch();
    

    return 0;
}
