#include<stdio.h>
#include<locale.h>



int main()
{
	setlocale(LC_ALL,"");
	
	float mm, pol;
	
	FILE* arq;
	

	arq = fopen("chuva.txt","r");

	while(!feof(arq))
	{
	
		fscanf(arq, "%f\n", &mm);
		
		pol = mm/25.4;
		
		printf("%.2f\n", pol);
	
	}

	fclose(arq);
	return 0;
}
