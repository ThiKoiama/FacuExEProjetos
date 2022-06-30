#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ex5 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"");
    
    float pv,pb,pn,vv,vb,vn,vt;
	
	printf("Digite a quantidade de eleitores que tiveram votos válidos: ");
	scanf("%i", &vv);
	printf("Digite a quantidade de eleitores que tiveram votos brancos: ");
	scanf("%i", &vb);
	printf("Digite a quantidade de eleitores que tiveram votos nulos: ");
	scanf("%i", &vn);
    
    vt = vv+vb+vn;
   
    pv = (vv/vt)*100;
    pb = (vb/vt)*100;
    pn = (vn/vt)*100;
    
    printf("Porcentagem de: \nVálidos: %0.2f\nBrancos: %0.2f\nNulos: %0.2f\nTotal de votos: %i", pv,pb,pn,vt);	
	return 0;
}
