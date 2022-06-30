#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ex6 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"");
    
    float pf, pt, ipi, lucro, icms;
    int ano;
	
	printf("Digite o preço de fábrica do véiculo: ");
	scanf("%f", &pf);
	printf("Digite o ano do veículo: ");
	scanf("%i", &ano);
	
    if(ano <=2000){
         icms = pf * 0.05;
         ipi = pf * 0.1;
         lucro = pf * 0.25;
         pt = pf + icms + ipi + lucro;

         printf("Valor original: %0.2f\nIPI: %0.2f\nICMS: %0.2f\nLucro: %0.2f\nPreço final: %0.2f", pf,icms,ipi,lucro,pt);	
    }
       else if(ano >2000 && ano <=2010){
         icms = pf * 0.07;
         lucro = pf * 0.2;
         ipi = pf * 0.11;
         pt = pf + icms + ipi + lucro;
         printf("Valor original: %0.2f\nIPI: %0.2f\nICMS: %0.2f\nLucro: %0.2f\nPreço final: %0.2f", pf,icms,ipi,lucro,pt);	
    }
        else{
         icms = pf * 0.07;
         lucro = pf * 0.2;
         ipi = pf * 0.13;
         pt = pf + icms + ipi + lucro;

         printf("Valor original: %0.2f\nIPI: %0.2f\nICMS: %0.2f\nLucro: %0.2f\nPreço final: %0.2f", pf,icms,ipi,lucro,pt);	
    }
    
	return 0;
}
