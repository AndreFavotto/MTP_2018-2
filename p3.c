#include <stdio.h>

int num(char str[]){
	int i=0, result=0;
		for(i;str[i]!='\0'; i++){
			if(str[i]>47 && str[i]<58){
			result=result*10 + (str[i]-48);
			}
		}
	return result;
}

int main(){
	char str[256];
	scanf("%s", str);
	printf("%d", num(str));
	return 0;
}

