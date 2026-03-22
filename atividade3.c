#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 3

typedef struct
{
    int matricula;
    char nome[50];
    float n1, n2, n3;
    float media;
} Aluno;

Aluno cadastroaluno(Aluno *aluno)
{
    printf("Digite a matricula: ");
    scanf("%d", &aluno->matricula);
    printf("Digite o nome: ");
    scanf(" %[^\n]", aluno->nome);
    printf("Digite a nota 1: ");
    scanf("%f", &aluno->n1);
    printf("Digite a nota 2: ");
    scanf("%f", &aluno->n2);
    printf("Digite a nota 3: ");
    scanf("%f", &aluno->n3);
    return *aluno;
}

Aluno maiorPrimeiraProva(Aluno a[], int tam)
{
    Aluno maior = a[0];
    for (int i = 1; i < tam; i++)
    {
        if (a[i].n1 > maior.n1)
        {
            maior = a[i];
        }
    }
    return maior;
}

Aluno mediaGeral(Aluno *a)
{
    a->media = (a->n1 + a->n2 + a->n3) / 3;
    if (a->media >= 7.0)
    {
        printf("Aluno aprovado!\n");
    }
    else
    {
        printf("Aluno reprovado!\n");
    }
}

int main()
{
    Aluno alunos[MAX_ALUNOS];
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        printf("Cadastro do aluno %d:\n", i + 1);
        cadastroaluno(&alunos[i]);
    }

    Aluno maior = maiorPrimeiraProva(alunos, MAX_ALUNOS);
    printf("Aluno com maior nota na primeira prova: %s\n", maior.nome);

    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        mediaGeral(&alunos[i]);
    }

    return 0;
}