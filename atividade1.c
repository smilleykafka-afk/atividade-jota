#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int hora;
    int minuto;
    int segundo;
} Horario;

typedef struct
{
    Data data;
    Horario horario;
    char desc[100];
} Compromisso;

Compromisso recebedata(Compromisso);
Compromisso recebehorario(Compromisso);
Compromisso recebedesc(Compromisso);
void imprime(Compromisso);

int main()
{

    Compromisso comp1;

    comp1 = recebedata(comp1);
    comp1 = recebehorario(comp1);
    comp1 = recebedesc(comp1);
    imprime(comp1);
}

Compromisso recebedata(Compromisso d)
{
    printf("Qual o ano do seu compromisso: ");
    scanf("%d", &d.data.ano);
    printf("Qual o mês do seu compromisso: ");
    scanf("%d", &d.data.mes);
    printf("Qual o dia do seu compromisso: ");
    scanf("%d", &d.data.dia);

    return d;
};

Compromisso recebehorario(Compromisso h)
{
    printf("Qual a hora do seu compromisso (hh:mm:ss): ");

    scanf("%d", &h.horario.hora);
    printf(":");

    scanf("%d", &h.horario.minuto);
    printf(":");

    scanf("%d", &h.horario.segundo);

    return h;
}

Compromisso recebedesc(Compromisso desc)
{
    printf("Qual o compromisso? ");
    scanf(" %99[^\n]%*c", desc.desc);

    return desc;
}

void imprime(Compromisso c)
{
    Compromisso *p = &c;

    printf("Data: %02d/%02d/%04d\n",
           p->data.dia,
           p->data.mes,
           p->data.ano);

    printf("Horario: %02d:%02d:%02d\n",
           p->horario.hora,
           p->horario.minuto,
           p->horario.segundo);

    printf("Compromisso: %s\n", p->desc);
}