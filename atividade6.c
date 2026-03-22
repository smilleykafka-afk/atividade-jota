#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} Ponto2D;

Ponto2D criaPonto(float x, float y)
{
    Ponto2D p;
    p.x = x;
    p.y = y;
    return p;
}

void movePonto(Ponto2D *p, float dx, float dy)
{
    p->x += dx;
    p->y += dy;
}

float distanciaEntrePontos(Ponto2D p1, Ponto2D p2)
{
    float distancia;
    distancia = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distancia;
}

void mostrarResultados(Ponto2D p1, Ponto2D p2, float distancia)
{
    printf("A distância entre os pontos \n 'x1 = % .2f e y1 = % .2f'  & 'x2 = % .2f e y2 = % .2f' \n é igual a: %.2f\n",
           p1.x,
           p1.y,
           p2.x,
           p2.y,
           distancia);
}

int main()
{
    Ponto2D p1, p2;
    float x, y, distancia;
    p1 = criaPonto(40, 14);

    p2 = criaPonto(-6, 124);

    movePonto(&p2, -64, 53);
    distancia = distanciaEntrePontos(p1, p2);

    mostrarResultados(p1, p2, distancia);
}