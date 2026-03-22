#include <stdio.h>
#include <stdlib.h>

enum Prioridade
{
    BAIXA,
    MEDIA,
    ALTA
};
enum Status
{
    TO_DO,
    IN_PROGRESS,
    DONE,
    BLOCKED
};

typedef struct
{
    int id;
    char nome[100];
    enum Status status;
    enum Prioridade priority;
} Task;

Task CriaTarefa(Task tarefa)
{
    int status, priority;
    printf("Digite o número da tarefa:");
    scanf("%d", &tarefa.id);

    getchar();

    printf("Digite qual a tarefa: ");
    fgets(tarefa.nome, 100, stdin);
    printf("Qual o status da sua tarefa? Digite: \n 0 - Para fazer \n 1- Em Progresso \n 2 - Finalizada \n 3 - Bloqueada\n");
    scanf("%d", &status);
    printf("Qual a prioridade da tarefa? \n 0 - Baixa \n 1 - Média \n 2 - Alta\n");
    scanf("%d", &priority);

    tarefa.status = status;
    tarefa.priority = priority;
    return tarefa;
}

Task atualizaStatus(Task *t)
{
    int status;

    printf("Qual o novo status da sua tarefa? Digite: \n 0 - Para fazer \n 1- Em Progresso \n 2 - Finalizada \n 3 - Bloqueada\n");
    scanf("%d", &status);
    t->status = status;
}

void tarefaUrgente(Task t)
{
    if (t.priority = 2)
    {
        printf("TAREFA URGENTE!!!");
    }
    else
    {
        printf("Tarefa não urgente");
    }
}

int main()
{
    Task tarefa1;
    tarefa1 = CriaTarefa(tarefa1);
    atualizaStatus(&tarefa1);
    tarefaUrgente(tarefa1);
}