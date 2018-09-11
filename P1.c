/*P1.c*/
/*Andre de Oliveira Aguila Favoto*/
/*11811EAU013*/

#include <stdio.h>

int main(){
int i=0, estado=0;
char bits[256];
printf("Digite a sequencia de bits para teste: ");
scanf("%s", bits);
for(i=0; bits[i]!='\0'; i++){
	if(bits[i]=='1'){
		if(estado==0)
		estado++;
		else if(estado==1)
		estado--;
		else
		;
	}
	else
		if(estado==1)
		estado++;
		else if(estado==2)
		estado--;
		else
		;
	}
printf("Estado final: %d \n I) A sequencia original digitada e: %s", estado, bits);
if(estado==0)
printf("\nE multiplo de 3");
else
printf("\nNao e multiplo de 3");
getch();
return 0;
}
