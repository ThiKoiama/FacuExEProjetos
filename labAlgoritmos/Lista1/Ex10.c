#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ex10 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"");
    
    float vm ,pf, vj;
    int dia;
	
	printf("Digite o valor da mensalidade: ");
	scanf("%f", &vm);
	printf("Digite o dia que deseja realizar o pagamento: ");
	scanf("%i", &dia);
	
    if(dia>=1 && dia <=5){
         pf = vm;
         printf("Valor original: %0.2f\nJuros: %0.2f\n Valor Final: %0.2f\n", vm,vj,pf);	
    }
       else if(dia>=6 && dia <=10){
        vj = vm * 0.05 ;  
        pf = vm+vj;
        printf("Valor original: %0.2f\nJuros: %0.2f\nValor Final: %0.2f\n", vm,vj,pf);	
    }
        else if(dia>=11 && dia <=20){
        vj = vm * 0.08 ;  
        pf = vm+vj;
        printf("Valor original: %0.2f\nJuros: %0.2f\nValor Final: %0.2f\n", vm,vj,pf);	
    }
       else {
        vj = vm * 0.1 ;  
        pf = vm+vj;
        printf("Valor original: %0.2f\nJuros: %0.2f\nValor Final: %0.2f\n", vm,vj,pf);	
    }
    
	return 0;
}
