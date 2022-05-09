#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char valor[50];
    struct no *proximo;
} fim;

void ffim(fim **contribuintes, char valor[50])
{
    fim *novo = malloc(sizeof(fim));
    strcpy(novo->valor, valor);
    novo->proximo = NULL;
    if (*contribuintes == NULL)
    {
        *contribuintes = novo;
    }
    else
    {
        fim *p = *contribuintes;
        while (p->proximo != NULL)
        {
            p = p->proximo;
        }
        p->proximo = novo;
    }
}

void ppagar(fim **contribuintes)
{
    fim *no = *contribuintes;
    if (no != NULL)
    {
        printf("Quem deve comprar o café é %s\n\n", no->valor);
        ffim(contribuintes, no->valor);
        *contribuintes = no->proximo;
    }
    // caso nao tenha nenhum contribuinte na lista.
    else
    {
        printf("adicione um contribuinte Primeiro.\n\n");
    }
}

void imprimir(fim *contribuintes)
{
    fim *p = contribuintes;
    printf("Lista Atualizada:\n");
    printf("\n");
    while (p != NULL)
    {
        printf("%s\n", p->valor);
        printf("\n");
        p = p->proximo;
    }
}
int main(void)
{

    fim *contribuintes = NULL;
    char valor[50];
    int opcao;

    printf("       CLUBE DO CAFÉ\n");
    printf("Qual das opções abaixo deseja?\n\n");
    printf("1- INSERIR NOVO CONTRIBUINTE\n");
    printf("2- INFORMA PROXIMO MEMBRO A CONTRIBUIR\n");
    printf("3- IMPRIMIR A LISTA\n");
    printf("0- Sair\n\n");
    scanf("%d", &opcao);
    while (opcao != 0)
    {
        switch (opcao)
        {
        case 1:
            printf("\n");
            printf("Digite o nome do contribuinte:\n ");
            scanf("%s", valor);
            printf("\n");
            ffim(&contribuintes, valor);
            break;
        case 2:
            printf("\n");
            ppagar(&contribuintes);
            break;
        case 3:
            printf("\n");
            imprimir(contribuintes);
            break;
        }
        printf("Qual das opções abaixo deseja?\n\n");
        printf("1-INSERIR NOVO CONTRIBUINTE.\n");
        printf("2- INFORMA PROXIMO MEMBRO A CONTRIBUIR.\n");
        printf("3- IMPRIMIR A LISTA.\n");
        printf("0- Sair\n\n");
        scanf("%d", &opcao);
    }
    printf("VOCE ENCERROU A LISTA");

    return 0;
}
