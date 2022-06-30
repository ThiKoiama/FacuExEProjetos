#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ex8 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"");
    
    float pf = 0.0, pg = 0.0, pa=0.0, Lalc, Lgas, precoGas, precoAlc;
  
	printf("Digite o valor do litro da gasolina: ");
	scanf("%f", &precoGas);
    printf("Digite o valor do litro do alc: ");
	scanf("%f", &precoAlc);
	printf("Digite a quantidade de litros comprados em gasolina : ");
	scanf("%f", &Lgas);
    printf("Digite a quantidade de litros comprados em álcool : ");
	scanf("%f", &Lalc);


    if(Lgas<=15){
        pg = Lgas*precoGas;
    }
    if(Lalc <=20){
        pa = Lalc*precoAlc;
    }
    if(Lalc >20){
        pa = (precoAlc - (precoAlc * 0.03))*Lalc ;
    }
    if(Lalc > 40){
         pa = (precoAlc - (precoAlc * 0.05))*Lalc ;
    }if(Lgas > 15){
        pg = (precoGas - (precoGas * 0.03))*Lgas ;
    }if(Lgas > 35){
         pg = (precoGas - (precoGas * 0.06))*Lgas ;
    }
    pf = pg+pa;

    printf("Preço a pagar: %0.2f\nValor de álcool: %0.2f\nValor de gasolina: %0.2f", pf, pa, pg);
      
	return 0;
}
