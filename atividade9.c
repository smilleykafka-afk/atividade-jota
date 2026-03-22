#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char titulo[100];
    char autor[50];
    int anoPublicacao;
    int exemplaresDisponiveis;
} Livro;

Livro criaLivro(Livro livro)
{
    printf("Digite o título: ");
    scanf(" %99[^\n]", livro.titulo);

    printf("Digite o autor: ");
    scanf(" %49[^\n]", livro.autor);

    printf("Digite o ano de publicação: ");
    scanf("%d", &livro.anoPublicacao);

    printf("Digite o número de exemplares disponíveis: ");
    scanf("%d", &livro.exemplaresDisponiveis);

    return livro;
}

Livro emprestaLivro(Livro *livro)
{
    if (livro->exemplaresDisponiveis > 0)
    {
        livro->exemplaresDisponiveis--;
        printf("Você emprestou o livro");
    }
    else
    {
        printf("Não foi possível emprestar esse livro");
    }
}
Livro devolveLivro(Livro *livro)
{
    livro->exemplaresDisponiveis++;
    printf("O livro foi devolvido com sucesso");
}

void exibeLivro(Livro livro)
{
    printf("Título: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de publicação: %d\n", livro.anoPublicacao);
    printf("Exemplares disponíveis: %d\n", livro.exemplaresDisponiveis);
}

int main()
{
    Livro livro1;
    int opcao;

    livro1 = criaLivro(livro1);

    printf("\nLivro cadastrado:\n");
    exibeLivro(livro1);

    printf("\nO que deseja fazer?\n");
    printf("1 - Emprestar livro\n");
    printf("2 - Devolver livro\n");
    printf("3 - Exibir livro\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        emprestaLivro(&livro1);
        break;

    case 2:
        devolveLivro(&livro1);
        break;

    case 3:
        exibeLivro(livro1);
        break;

    default:
        printf("Opção inválida\n");
    }

    printf("\n\nEstado final do livro:\n");
    exibeLivro(livro1);

    return 0;
}