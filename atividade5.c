#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char marca[50];
    char modelo[50];
    float preco;
} Veiculo;

void preencheVeiculo(Veiculo *v)
{
    printf("Digite a marca do veículo: ");
    scanf("%s", v->marca);
    printf("Digite o modelo do veículo: ");
    scanf("%s", v->modelo);
    printf("Digite o preço do veículo: ");
    scanf("%f", &v->preco);
}

void atualizaPreco(Veiculo *v, float novoPreco)
{
    v->preco = novoPreco;
}

void novosDadosVeiculo(Veiculo *v)
{
    printf("O preço do veículo %s da marca %s foi alterado para R$%.2f", v->modelo, v->marca, v->preco);
}

int main()
{
    Veiculo veiculo1;
    float novoPreco;

    preencheVeiculo(&veiculo1);

    printf("Digite o novo preço do veículo: ");
    scanf("%f", &novoPreco);

    atualizaPreco(&veiculo1, novoPreco);
    novosDadosVeiculo(&veiculo1);
}