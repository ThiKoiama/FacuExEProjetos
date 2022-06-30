#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ex7 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"");
    
    float pf, pp,pa,pl;
    int pera, alface, laranja;
	
	printf("Digite a quantidade de peras compradas: ");
	scanf("%i", &pera);
	printf("Digite a quantidade de alfaces compradas: ");
	scanf("%i", &alface);
    printf("Digite a quantidade de laranjas compradas: ");
	scanf("%i", &laranja);
	
    if(alface <=2){
        pa = alface * 2 ;
    }
    if(alface > 2){
        pa = alface * 1.5;
    }if(pera <= 5){
        pp = pera * 1.5;
    }if(pera > 5){
        pp = pera * 1.2;
    }if(laranja <=6 ){
        pl = laranja * 0.5;
    }if(laranja>6) {
        pl = laranja * 0.4;
    }
    
    pf = pp+pa+pl;

    printf("Preço a pagar: %0.2f", pf);
      
	return 0;
}
