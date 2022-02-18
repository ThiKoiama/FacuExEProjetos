#include<stdio.h>
#include<locale.h>



int main()
{
	setlocale(LC_ALL,"");
	
	char nome[15];
	float salfx, saltotal;
	int cv;
	
	FILE* arq;
	
	// abrindo arquivo em modo leitura
	arq = fopen("vendidos.txt","r");

	while(!feof(arq))
	{
		// lendo a linha e guardando em memória
		fscanf(arq, "%s %f %i\n", nome, &salfx, &cv);
		
		saltotal = (200 * cv)+salfx;
		
		printf("%s %.2f\n", nome, saltotal);
	
	}

	fclose(arq);
	return 0;
}
