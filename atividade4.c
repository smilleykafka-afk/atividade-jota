#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x;
    float y;
    float z;
} Vetor3D;

Vetor3D recebevetorA(Vetor3D vetorA)
{
    printf("Digite o valor do vetor A (x, y, z): ");
    scanf("%f %f %f", &vetorA.x, &vetorA.y, &vetorA.z);

    return vetorA;
}

Vetor3D recebevetorB(Vetor3D vetorB)
{

    printf("Digite o valor do vetor B (x, y, z): ");
    scanf("%f %f %f", &vetorB.x, &vetorB.y, &vetorB.z);

    return vetorB;
}

Vetor3D somavetores(Vetor3D vetorA, Vetor3D vetorB)
{
    Vetor3D soma;
    soma.x = vetorA.x + vetorB.x;
    soma.y = vetorA.y + vetorB.y;
    soma.z = vetorA.z + vetorB.z;
    return soma;
}

void mostraresultado(Vetor3D soma)
{
    printf("O Resultado das somas do vetores é : %.2f / %.2f / %.2f\n", soma.x, soma.y, soma.z);
}

void acumulaNoPrimeiro(Vetor3D *a, Vetor3D b)
{
    printf("O valor original de A: (%.2f, %.2f, %.2f)\n", a->x, a->y, a->z);
    a->x += b.x;
    a->y += b.y;
    a->z += b.z;
}

void acumulacao(Vetor3D *a)
{
    printf("O novo valor do vetor A após acumulação: (%.2f, %.2f, %.2f)\n", a->x, a->y, a->z);
}

int main()
{
    Vetor3D a, b, soma;
    a = recebevetorA(a);
    b = recebevetorB(b);
    soma = somavetores(a, b);
    mostraresultado(soma);
    acumulaNoPrimeiro(&a, b);
    acumulacao(&a);
    return 0;
}