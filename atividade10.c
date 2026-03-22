#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char nome[50];
    float preco;
    int quantidadeEstoque;
} Produto;

Produto criaProduto(int id, char *nome, float preco, int estoque)
{
    Produto p;

    p.id = id;
    strcpy(p.nome, nome);
    p.preco = preco;
    p.quantidadeEstoque = estoque;

    return p;
}

void atualizaEstoque(Produto *p, int delta)
{
    p->quantidadeEstoque += delta;
}

void exibeProduto(Produto prod)
{
    printf("\nProduto:\n");
    printf("ID: %d\n", prod.id);
    printf("Nome: %s\n", prod.nome);
    printf("Preço: %.2f\n", prod.preco);
    printf("Quantidade em estoque: %d\n", prod.quantidadeEstoque);
}

int main()
{
    Produto p1;

    p1 = criaProduto(1, "Mouse Gamer", 150.50, 10);

    exibeProduto(p1);

    printf("\nAdicionando 5 unidades ao estoque...\n");
    atualizaEstoque(&p1, 5);
    exibeProduto(p1);

    printf("\nVendendo 3 unidades...\n");
    atualizaEstoque(&p1, -3);
    exibeProduto(p1);

    return 0;
}