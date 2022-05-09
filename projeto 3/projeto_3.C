#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char data[10];
    char entrada1[10];
    char saida1[10];
    char entrada2[10];
    char saida2[10];
    char mes[10];
    struct ponto *proximo;
} ponto;

void inserir(ponto **funcionario, char entrada1[10], char saida1[10], char entrada2[10],
             char saida2[10], char data[10])
{
    ponto *novo = malloc(sizeof(ponto));
    strcpy(novo->data, data);
    strcpy(novo->entrada1, entrada1);
    strcpy(novo->saida1, saida1);
    strcpy(novo->entrada2, entrada2);
    strcpy(novo->saida2, saida2);

    novo->proximo = NULL;
    if (*funcionario == NULL)
    {
        *funcionario = novo;
    }
    else
    {
        ponto *p = *funcionario;
        while (p->proximo != NULL)
        {
            p = p->proximo;
        }
        p->proximo = novo;
    }
}

void imprimir(ponto *funcionario)
{
    ponto *p = funcionario;
    printf("   RELATORIO DE PONTO\n");
    printf("\n");
    while (p != NULL)
    {
        printf("       DATA "
               "%s"
               "\n",
               p->data);
        printf("ENTRADA: "
               "%s\n",
               p->entrada1);
        printf("SAIDA PARA ALMOÇO: "
               "%s\n",
               p->saida1);
        printf("RETORNO DO ALMOÇO: "
               "%s\n",
               p->entrada2);
        printf("SAIDA: "
               "%s\n",
               p->saida2);
        printf("\n");
        p = p->proximo;
    }
}
int main(void)
{

    ponto *funcionario = NULL;

    int opcao;
    char data[10];
    char entrada1[10];
    char saida1[10];
    char entrada2[10];
    char saida2[10];
    printf("        RELOGIO DE PONTO DIGITAL\n\n");
    printf("               BEM VINDO\n\n ");
    printf("     QUAL DAS OPÇOES ABAIXO VOCE DESEJA?\n\n");
    printf("1- INSERIR NOVO PONTO\n");
    printf("2- IMPRIMIR RELATORIO DE PONTO\n");
    printf("0- Sair\n\n");
    scanf("%d", &opcao);
    while (opcao != 0)
    {
        switch (opcao)
        {
        case 1:
            printf("\n");
            printf("DATA: ");
            scanf("%s", data);
            printf("CHEGADA: ");
            scanf("%s", entrada1);
            printf("SAIDA PARA ALOMOÇO: ");
            scanf("%s", saida1);
            printf("RETORNO DO ALMOÇO: ");
            scanf("%s", entrada2);
            printf("SAIDA: ");
            scanf("%s", saida2);
            printf("\n");
            inserir(&funcionario, entrada1, saida1, entrada2, saida2, data);
            break;
        case 2:
            printf("\n");
            imprimir(funcionario);
            break;
        }

        printf("      RELOGIO DE PONTO\n");
        printf("    QUAL DAS OPÇOES ABAIXO VOCE DESEJA?\n\n");
        printf("1- INSERIR NOVO PONTO\n");
        printf("2- IMPRIMIR RELATORIO DE PONTO\n");
        printf("0- Sair\n\n");
        scanf("%d", &opcao);
    }

    printf("VOCE ENCERROU O RELOGIO DE PONTO DIGITAL");

    return 0;
}