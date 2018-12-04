/*P6.c*/
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

void mostrar_pontos(ponto * pbeg, ponto * pend) {
    if(pbeg < pend) {
        printf("x: %.3lf, y: %.3lf\n", pbeg->x, pend->y);
        mostrar_pontos(pbeg+1, pend);
    }
}

int main(){
    unsigned int N;
    ponto *coordenadas;
    printf("Digite o número de pontos: ");
    scanf("%u", &N); getchar();
    coordenadas = gerar_pontos(N);
    mostrar_pontos(coordenadas, coordenadas + N);
    free(coordenadas);
    return 0;
}
