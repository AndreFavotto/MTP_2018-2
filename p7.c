/*P7.c*/
/*Andre de Oliveira Aguila Favoto*/
/*11811EAU013*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef
    struct ponto{double x,y;}
ponto;

ponto * gerar_pontos(int N) {
    ponto * coord = (ponto *) calloc(N,sizeof(ponto));
    int i;
    for(i = 0; i < N; i++){
        coord[i].x = cos(i*2.0*M_PI/(N-1));
        coord[i].y = sin(i*2.0*M_PI/(N-1));
    }
    return coord;
}

void generate(ponto*coord, int N){
	int i=0;
	FILE *arquivo;
	arquivo = fopen("pontos.dat","w");
	for(i; i<N; i++)
	fprintf(arquivo, "x: %.3lf, y: %.3lf\n", coord[i].x, coord[i].y );
	fprintf(arquivo,"\n");
	fclose(arquivo);
}

void show(){
	char c;
	FILE*arquivo;
	arquivo=fopen("pontos.dat", "r");
	do{
    c = getc(arquivo);
    printf("%c" , c);    
}while (c != EOF);
}

int main(){
    unsigned int N;
    ponto *coordenadas;
    printf("Digite o número de pontos: ");
    scanf("%u", &N); getchar();
    coordenadas = gerar_pontos(N);
    generate(coordenadas, N);
    show();
    free(coordenadas);
    return 0;
}

