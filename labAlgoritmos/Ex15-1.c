#include <stdio.h>
#include <locale.h>


float tripulantes[24][4], media1, media2, media3, media4;

void mediasTemperaturas(){
	int l;
	for(l=0;l<24;l++){
			media1 = media1+tripulantes[l][0];
			media2 = media2+tripulantes[l][1];
			media3 = media3+tripulantes[l][2];
			media4 = media4+tripulantes[l][3];
			}
			
			media1=media1/24;
			media2=media2/24;
			media3=media3/24;
			media4=media4/24;

		printf("Temperatura média do tripulante 1: %.2f\n", media1);
		printf("Temperatura média do tripulante 2: %.2f\n", media2);
		printf("Temperatura média do tripulante 3: %.2f\n", media3);
		printf("Temperatura média do tripulante 4: %.2f\n", media4);

}
void menorMedia(){
	if(media1<media2 && media1<media3 && media1<media4){
		printf("O tripulante da cápsula 1 possui a menor temperatura média!\n");
	}
	else if(media2<media1 && media2<media3 && media2<media4){
		printf("O tripulante da cápsula 2 possui a menor temperatura média!\n");
	}
	else if(media3<media1 && media3<media2 && media3<media4){
		printf("O tripulante da cápsula 3 possui a menor temperatura média!\n");
	}
	else{
		printf("O tripulante da cápsula 4 possui a menor temperatura média!\n");
	}


}
void menorValor(){

	float menor=0;
	int l, c, h=0,t=0;
	for(l=0;l<24;l++){
		for(c=0;c<4;c++){
			 if(l == 0 && c == 0){
    			menor = tripulantes[l][c];
				}
   			else{
    			if(tripulantes[l][c] < menor){
     			menor = tripulantes[l][c];
     			h = l;
     			t = c;
			}
		}
	}
}
	printf("O menor valor de temperatura encontrado foi: %.2f na hora %i e no tripulante da cápsula %i!\n", menor, h, t+1);

}

int main(){
	setlocale(LC_ALL, "");
	int l, c;

	for(l=0;l<24;l++){
		for(c=0;c<4;c++){
			printf("Digite a temperatura na hora %i do tripulante da cápsula %i: ", l,c+1);
			scanf("%f", &tripulantes[l][c]);	
		}
	}
	 printf("==================================================================================================================\n");
	 mediasTemperaturas();
	 menorMedia();
	 menorValor();
	 printf("==================================================================================================================\n");
	getch();
	return 0;
}
