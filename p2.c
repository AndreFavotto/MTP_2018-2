/*P2.c */
/* Andre_de_Oliveira_Aguila_Favoto */
/*11811EAU013 */
#include <stdio.h>
int bin_dec(char bin[]){
	int size=0, i=0,cont=0, dec=0, pot=0;
	for(size; bin[size]!='\0'; size++);
	for(i=0; i<=size; i++){
		if(bin[size-i]=='1'){
			pot=1;
			for(cont=1; cont<i; cont++)
			pot=pot*2;
			dec=dec+pot;
		}
	}
	printf("%d", dec);
}

void bin_hex(char bin[]){
	int size=0, poshex=0, posbin=0, cont, dec, pot, contpot;
	for(size; bin[size]!='\0'; size++);
	char hex[size/4];
	while(poshex<size/4){
		for(posbin; bin[posbin]!='\0'; posbin+=4){
			dec=0;
			for(cont=0; cont<4; cont++){
				if(bin[posbin+cont]=='1'){
					pot=1;
					for(contpot=1; contpot<4-cont; contpot++)
					pot=pot*2;
					dec=dec+pot;
				}
			}
			if(dec<10)
			hex[poshex]=dec+48;
			else
			hex[poshex]=dec+55;
			poshex++;
		}
	}
	printf("%s", hex);
}

void hex_dec(char shex[]){
	int len, dec=0, i, parcela, pot;
	for(len=0;shex[len]!='\0';len++);
	int hex[len];
	for(i=0;i<len;i++)
	{
		if(shex[i]>=48 && shex[i]<=57)
		hex[i]=shex[i]-48;
		if(shex[i]>=65 && shex[i]<=70)
		hex[i]=shex[i]-55;
		if(shex[i]>=97 && shex[i]<=102)
		hex[i] = shex[i]-87;
	}
	for(i=0;i<len;i++)
	{
		parcela=1;
		for(pot=0;pot<len-i-1;pot++)
		parcela*=16;
		dec+=parcela*hex[i];
	}
	printf("%d",dec);
}
void hex_bin(char shex[256]){
	int len, primeiro;
	for(len=0;shex[len]!='\0';len++);
	int hex[len], i, j;
	int bin[len][4];
	for(i=0;i<len;i++)
	{
		if(shex[i]>=48 && shex[i]<=57)
		hex[i]=shex[i]-48;
		if(shex[i]>=65&&shex[i]<=70)
		hex[i]=shex[i]-55;
		if(shex[i]>=97 && shex[i]<=102)
		hex[i]=shex[i]-87;
	}
	for(i=0;i<len;i++)
	{
		for(j=0;j<4;j++)
		{
			bin[i][3-j] = hex[i]%2;
			hex[i]/=2;
		}
	}
	for(j=0;j<4;j++)
	{
		if(bin[0][j]==1)
		{
			primeiro = j;
			break;
		}
	}
	for(j=primeiro;j<4;j++)
	printf("%d",bin[0][j]);
	for(i=1;i<len;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d",bin[i][j]);
		}
	}
}
void dec_bin(int dec){
	int nb, i;
	for(nb=0;dec>=(1<<nb);nb++);
	int bin[nb];
	for(i=0;nb-1-i>=0;i++)
	{
		bin[nb-1-i]=dec%2;
		dec/=2;
	}
	for(i=0;i<nb;i++)
	printf("%d",bin[i]);
}

int main(){
int op;
char num[256];
scanf("%d", &op);
switch(op){
	case 1: 
		scanf("%s", num);
		bin_dec(num);
		break;
	case 2:
		scanf("%s", num);
		bin_hex(num);
		break;
	case 3:
		scanf("%s", num);
		hex_dec(num);
		break;
	case 4:
		scanf("%s", num);
		hex_bin(num);
		break;
	case 5:
		scanf("%s", num);
		dec_bin(num);
		break;
	case 6:
		scanf("%d",&num);
		printf("%X",num);
		break;
	case 7:
		scanf("%o",&num);
		printf("%d",num);
		break;
	case 8:
		scanf("%d",&num);
		printf("%o",num);
		break;		
}
}

