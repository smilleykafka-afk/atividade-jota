#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[100];
    int tempoPreparoMinutos;
    int porcoes;
} Receita;

void preencheReceita(Receita *r)
{
    printf("Digite o nome da receita: ");
    scanf(" %[^\n]", r->nome);

    printf("Digite o tempo de preparo (minutos): ");
    scanf("%d", &r->tempoPreparoMinutos);

    printf("Digite o numero de porcoes: ");
    scanf("%d", &r->porcoes);
}

void imprimeReceita(Receita r)
{
    printf("\n--- Receita ---\n");
    printf("Nome: %s\n", r.nome);
    printf("Tempo de preparo: %d minutos\n", r.tempoPreparoMinutos);
    printf("Porcoes: %d\n", r.porcoes);
}

void ajustaPorcoes(Receita *r, int novoNumPorcoes)
{
    r->porcoes = novoNumPorcoes;
}

int main()
{
    Receita r;
    int novoValor;

    preencheReceita(&r);

    printf("\nReceita original:\n");
    imprimeReceita(r);

    printf("\nDigite o novo numero de porcoes: ");
    scanf("%d", &novoValor);

    ajustaPorcoes(&r, novoValor);

    printf("\nReceita atualizada:\n");
    imprimeReceita(r);

    return 0;
}