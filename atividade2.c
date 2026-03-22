#include <stdio.h>
#include <stdlib.h>

#define MAX_PESSOAS 5

typedef struct
{
    char name[50];
    int idade;
    char endereco[100];
} Pessoa;

Pessoa preenchepessoa(Pessoa *p)
{
    printf("Nome: ");
    scanf(" %49[^\n]", p->name);
    printf("Idade: ");
    scanf("%d", &p->idade);
    printf("Endereco: ");
    scanf(" %99[^\n]", p->endereco);
    return *p;
}

void exibePessoa(Pessoa p)
{
    printf("Nome: %s\n", p.name);
    printf("Idade: %d\n", p.idade);
    printf("Endereco: %s\n", p.endereco);
}

int main()
{
    Pessoa p[MAX_PESSOAS];
    for (int i = 0; i < MAX_PESSOAS; i++)
    {
        printf("Preenchendo dados da pessoa %d:\n", i + 1);
        p[i] = preenchepessoa(&p[i]);
    }

    printf("=- Dados das pessoas =-\n");

    for (int i = 0; i < MAX_PESSOAS; i++)
    {
        printf("Dados da pessoa %d:\n", i + 1);
        exibePessoa(p[i]);
    }

    return 0;
}   