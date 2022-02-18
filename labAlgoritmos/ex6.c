#include <stdio.h>
#include <locale.h>

int main()
{
    float peso, resultado, massa;
    int nPlaneta;
    
    setlocale(LC_ALL, "");
    printf("Digite o peso: ");
    scanf("%f", &peso);
    massa = peso/10;
    printf("Digite o número do planeta: ");
    scanf("%i", &nPlaneta);
    switch (nPlaneta){
      	case 1:
   		resultado = massa*0.37;
		printf("Mercúrio - Peso de: %.2f", resultado);
		break;
		case 2:
		resultado = massa*0.88;
		printf("Vênus - Peso de: %.2f", resultado);
		break;
		case 3:
		resultado = massa*0.38;
		printf("Marte - Peso de: %.2f", resultado);
		break;
		case 4:
		resultado = massa*2.64;
		printf("Júpiter - Peso de: %.2f", resultado);
		break;
		case 5:
		resultado = massa*1.15;
		printf(" Saturno - Peso de: %.2f", resultado);
		break;
		case 6:
		resultado = massa*1.17;
		printf(" Urano - Peso de: %.2f", resultado);
		break; 
		default :
    	printf ("Nenhum planeta possui esse número!");     		
	  }
	  getch();
    
    return 0;
}

    
