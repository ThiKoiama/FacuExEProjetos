#include <stdio.h>
#include <stdlib.h>

float retangulo(float n1, float n2)
{
	float area;
	area = n1*n2;
	return area;
}
float triangulo(float n1, float n2)
{
	float area;
	area = (n1*n2)/2;
	return area;
}
float trapezio(float n1, float n2, float n3)
{
	float area;
	area = ((n1+n2)*n3)/2;
	return area;
}

int main(int argc, char *argv[])
{
	int opc = 0;
	float n1, n2, area, n3;
	while (opc != 9)
	{
		printf("\n");
		printf(":: MENU :: \n");
		printf("1. Area Retangulo  \n");
		printf("2. Area Triangulo \n");
		printf("3. Area Trapezio\n");
		printf("9. Sair\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opc);
		if (opc == 1)
		{
			printf("Digite a largura do retangulo: ");
			scanf("%f", &n1);
			printf("Digite a altura do retangulo: ");
			scanf("%f", &n1);
			area = retangulo(n1, n2);
			printf("A area e de: %0.2f ", area);
		}
		else if (opc == 2)
		{
			printf("Digite a largura do triangulo: ");
			scanf("%f", &n1);
			printf("Digite a altura do triangulo: ");
			scanf("%f", &n1);
			area = triangulo(n1, n2);
			printf("A area e de: %0.2f ", area);
			
		}
		else if (opc == 3)
		{	
			printf("Digite a base maior do trapezio: ");
			scanf("%f", &n1);
			printf("Digite a base menor do trapezio: ");
			scanf("%f", &n2);
			printf("Digite a altura do trapezio: ");
			scanf("%f", &n3);
			area = trapezio(n1, n2, n3);
			printf("A area e de: %0.2f ", area);
		
		}
	}

	return 0;
}
