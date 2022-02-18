#include<stdio.h>
#include<locale.h>
#define MAX 50
int main()
{
	setlocale(LC_ALL,"");
    int num, vetorBinario[MAX], i = 0, j, v[MAX], k, x, l;
	FILE* arq;
	arq = fopen("decimais.txt","r");
	while(!feof(arq))
	{
		fscanf(arq, "%i\n", &v[i]);
		i++;
		l++;
	}	
	for(i=0; i<l;i++){	
		while(v[i] > 0)
	{
		vetorBinario[k] = v[i] % 2;
		k++;
		v[i] = v[i]/ 2;
		if(!v[i]>0){
			x=k;
			k=0;
		}
	}
		for(j = x - 1; j >= 0; j--){
		printf("%i", vetorBinario[j]);	
}

	printf("\n");
}
	fclose(arq);
	return 0;
}


