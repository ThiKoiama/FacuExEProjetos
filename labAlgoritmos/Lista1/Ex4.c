#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ex4 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"");
	float n1,n2,tr,ct, mf = 0.0;
	
	printf("Digite a primeira nota: ");
	scanf("%f", &n1);
	printf("Digite a segunda nota: ");
	scanf("%f", &n2);
	printf("Digite a nota do trabalho: ");
	scanf("%f", &tr);
	printf("Digite a nota de corte: ");
	scanf("%f", &ct);
	
    mf = ((n1*40) + (n2*40) + (tr * 20))/100;
    
    if(mf>ct){
        printf("Nota: %0.2f\nAprovado!", mf);	
    }else{
        printf("Nota: %0.2f\nReprovado!", mf);	
    }
	
	return 0;
}
