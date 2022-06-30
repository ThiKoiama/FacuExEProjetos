#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ex9 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"");
    
    float peso, alt, imc;
  
	printf("Digite o seu peso: ");
	scanf("%f", &peso);
    printf("Digite a sua altura: ");
	scanf("%f", &alt);

    imc = peso/(alt*alt);
	
    if(imc <18.5){
        printf("IMC: %0.2f - Abaixo do peso", imc);
    }else if(imc >= 18.5 && imc <= 24.9){
        printf("IMC: %0.2f - Peso normal", imc);
    }else if(imc >= 25 && imc <= 29.9){
        printf("IMC: %0.2f - Sobrepeso",imc);
    }else if(imc >= 30 && imc <= 34.9){
        printf("IMC: %0.2f - Obesidade grau I", imc);
    }else if(imc >= 35 && imc <= 39.9){
        printf("IMC: %0.2f - Obesidade grau II", imc);
    }
    else{
        printf("IMC: %0.2f - Obesidade mórbida ", imc);
    }
  
      
	return 0;
}
