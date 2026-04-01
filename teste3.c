#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#include<locale.h>
#include<stdbool.h>


typedef int Tipo_Chave;

typedef struct {
    char nome[50];
}Disciplina;

typedef struct Aux_Disciplina{
    Disciplina d;
    struct Aux_Disciplina *proximo;
}Elemento_Disciplina;

typedef Elemento_Disciplina* PONTD;

typedef struct{
    PONTD inicio;
}Lista_Disciplina;

typedef struct {
    int matricula;
    char nome[50];
    Lista_Disciplina disciplina;
}Aluno;

typedef struct{
    Aluno aluno;
}Registro;


typedef struct Aux_Elemento{
    Registro r;
    struct Aux_Elemento *proximo;
}Elemento;

typedef Elemento *PONT; 
typedef struct{
    PONT inicio;
}Lista;

void Iniciar_Lista_Disciplina(Lista_Disciplina *L){
    L->inicio = NULL;
}

void Inicializar_Lista(Lista *L){
    L->inicio=NULL;
}

int Tamanho(Lista *L){
    PONT aux=L->inicio;
    int tam=0;
    while(aux!=NULL){
        tam++;
        aux=aux->proximo;
    }
    return tam;
}

void Imprimir_Disciplinas(Lista_Disciplina *L){
    PONTD aux = L->inicio;
    while (aux != NULL){
        printf(" Disciplina: %s\n", aux->d.nome);
        aux = aux->proximo;
    }
}

void Imprimir_Lista(Lista *L){
    PONT aux=L->inicio;
    while(aux!=NULL){
        printf(" %d ",aux->r.aluno.matricula);
        printf("%s ", aux->r.aluno.nome);

        Imprimir_Disciplinas(&aux->r.aluno.disciplina);
        aux=aux->proximo;
    }
    printf("\n\n");
}

PONT Busca_Sequencial(Lista *L,Tipo_Chave ch){
    PONT posicao=L->inicio;
    while(posicao!=NULL){
        if(posicao->r.aluno.matricula == ch)
            return posicao;
        posicao=posicao->proximo;
    }
    return NULL;
}

PONT Busca_Sequencial_Aux(Lista *L, Tipo_Chave ch, PONT *anterior){
    *anterior=NULL;
    PONT atual=L->inicio;
    while((atual!=NULL)&&(atual->r.aluno.matricula !=ch)){
        *anterior=atual;
        atual=atual->proximo;
    }
    if((atual!=NULL)&&(atual->r.aluno.matricula))
        return atual;
    return NULL;
}

void Buscar_Aluno_Por_Disciplina (Lista *L,  char nomeDisciplina[]){
    PONT aluno = L->inicio;
    bool encontrou = false;

    while(aluno != NULL){
        PONTD disc = aluno->r.aluno.disciplina.inicio;

        while (disc != NULL){
            if(stricmp(disc->d.nome, nomeDisciplina) == 0){
                
                printf("\n Aluno(s) encontrado(s): \n");
                printf("Matricula: %d\n", aluno->r.aluno.matricula);
                printf("Nome: %s\n", aluno->r.aluno.nome);

                encontrou = true;
                break;
            }
            disc= disc->proximo;
        }
        aluno = aluno->proximo;
    }
    if (!encontrou){
        printf("\nNenhum aluno encontrado na disciplina...\n");
    }
}


bool Inserir_Disciplina(Lista_Disciplina *L, Disciplina d){
    PONTD novo = (PONTD) malloc(sizeof(Elemento_Disciplina));
    if (novo == NULL) return false;

    novo ->d = d;
    novo->proximo = L->inicio;
    L->inicio = novo;
    return true;
}


bool Inserir_Elemento_Lista(Lista *L, Registro r){
    Tipo_Chave ch=r.aluno.matricula;
    PONT anterior,i;
    i=Busca_Sequencial_Aux(L,ch,&anterior);
    if(i!=NULL)
        return false;
    i=(PONT)malloc(sizeof(Elemento));
    i->r=r;
    if(anterior==NULL){
        i->proximo=L->inicio;
        L->inicio=i;
    }
    else{
        i->proximo=anterior->proximo;
        anterior->proximo=i;
    }
    return true;
}

bool Excluir_Elemento_Lista(Lista *L,Tipo_Chave ch){
    PONT anterior,i;
    i=Busca_Sequencial_Aux(L,ch,&anterior);
    if(i==NULL)
        return false;
    if(anterior==NULL)
        L->inicio=i->proximo;
    else
        anterior->proximo=i->proximo;
    free(i);
    return true;
}

void Reinicializar_Lista(Lista *L){
    PONT aux=L->inicio;
    while(aux!=NULL){
        PONT limpar=aux;
        aux=aux->proximo;
        free(limpar);
    }
    L->inicio=NULL;
}

void Imprimir_Ordenado_Matricula(Lista *L){
    int n = tamanho(L);
    if(n == 0) return;

    Registro vet[n];
    PONT aux = L->inicio;


    for (int i = 0; i< n; i++){
        vet[i] = aux->r;
        aux = aux->proximo;
    }

    for (int i = 0; i< n-1; i++){
        for (int j = 0; j< n-1; j++){
            if (vet[j].aluno.matricula > vet[j+1].aluno.matricula){
                Registro temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++){
        printf("\n Matricula: %d\n", vet[i].aluno.matricula);
        printf("Nome: %s\n", vet[i].aluno.nome);

        Imprimir_Disciplinas(&vet[i].aluno.disciplina);
        
    }
}

void Imprimir_Ordenado_Nome(Lista *L){
 int n = Tamanho(L);
    if(n == 0) return;

    Registro vet[n];
    PONT aux = L->inicio;

    for(int i = 0; i < n; i++){
        vet[i] = aux->r;
        aux = aux->proximo;
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if(stricmp(vet[j].aluno.nome, vet[j+1].aluno.nome) > 0){
                Registro temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("\nMatricula: %d\n", vet[i].aluno.matricula);
        printf("Nome: %s\n", vet[i].aluno.nome);
        Imprimir_Disciplinas(&vet[i].aluno.disciplina);
    }
}

void Buscar_Aluno(Lista *L){
    int opcao;
    printf("1 - Buscar por matricula\n2 - Buscar por nome\n");
    scanf("%d", &opcao);

    PONT aux = L->inicio;

    if(opcao == 1){
        int mat;
        printf("Digite a matricula: ");
        scanf("%d", &mat);

        while(aux != NULL){
            if(aux->r.aluno.matricula == mat){
                printf("\nEncontrado:\n");
                printf("%d - %s\n", aux->r.aluno.matricula, aux->r.aluno.nome);
                Imprimir_Disciplinas(&aux->r.aluno.disciplina);
                return;
            }
            aux = aux->proximo;
        }
    }
    else{
        char nome[50];
        printf("Digite o nome: ");
        scanf(" %[^\n]", nome);

        while(aux != NULL){
            if(stricmp(aux->r.aluno.nome, nome) == 0){
                printf("\nEncontrado:\n");
                printf("%d - %s\n", aux->r.aluno.matricula, aux->r.aluno.nome);
                Imprimir_Disciplinas(&aux->r.aluno.disciplina);
                return;
            }
            aux = aux->proximo;
        }
    }

    printf("\nAluno nao encontrado.\n");
}

void Ordenar_Disciplina(Lista_Disciplina *L){
    if (L->inicio == NULL) return;

    for (PONTD i = L->inicio; i!= NULL; i = i->proximo){
        for (PONTD j = i->proximo; j != NULL; j = j->proximo){
            if (stricmp(i->d.nome, j->d.nome) > 0){
                Disciplina temp = i->d;
                i->d = j->d;
                j->d = temp;
            }
        }
    }
}



int main()
{
    setlocale(LC_ALL,"");
    Lista L;
    char sair,op;
    int opcao=0;
    Tipo_Chave h;
    Registro a;

    Inicializar_Lista(&L);
    do{
        printf("1- Criar Lista de alunos \n");
        printf("2- Inserir aluno na lista \n");
       printf("3- Imprimir a lista \n");
       printf("4- Resetar Lista \n");
       printf("5- Buscar aluno pela disciplina\n");
       printf("6- Imprimir ordenado por matricula\n");
        printf("7- Imprimir ordenado por nome\n");
        printf("8- Buscar aluno (nome ou matricula)\n");
       printf("0- Sair lista\n");
       
        printf("Digite a op��o: \n");
        scanf("%d",&opcao);
        printf("\n==================================\n");
        switch(opcao){
            case 1:
                   Inicializar_Lista(&L);
                   break;
            case 2:
                {
                    Registro a;
                    Disciplina d;
                    char opDisc;

                    printf("\n Digite a matricula: ");
                    scanf("%d", &a.aluno.matricula);

                    printf("\n Digite o nome: ");
                    scanf(" %[^\n]", a.aluno.nome);

                    Iniciar_Lista_Disciplina(&a.aluno.disciplina);

                    do {
                        printf("\n Digite a disciplina: ");
                        scanf(" %[^\n]", d.nome);

                        Inserir_Disciplina(&a.aluno.disciplina, d);

                        printf("Adicionar outra disciplina? (s/n): ");
                        scanf(" %c", &opDisc);
                    
                    }while(opDisc != 'n');

                    Inserir_Elemento_Lista(&L, a);
                    
                }
                break;

            case 3:
                    Imprimir_Lista(&L);
                    break;


            case 4:
                Reinicializar_Lista(&L);
                break;

            case 5:
            {
                char nomeDisciplina[50];
                printf("\nDigite o nome da Disciplina: ");
                scanf(" %s", nomeDisciplina);

                Buscar_Aluno_Por_Disciplina(&L, nomeDisciplina);
            }
            break;

            case 6:
            Imprimir_Ordenado_Matricula(&L);
            break;

            case 7:
            Imprimir_Ordenado_Nome(&L);
            break;

            case 8:
            Buscar_Aluno(&L);
            break;
            
           case 0:
         printf("Saindo...\n");
        sair = 's';
        break;
    }

}   while(sair!='s');
    return 0;
    }
