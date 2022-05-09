#include <stdio.h>
#include <stdlib.h>

int elem = -1;

void case1(int *vapontador, int t)
{
    for (int i = 0; i < t; i++)
    {
        printf("Insira o valor que sera armazenado no local %d: ", (i + 1));
        scanf("%d", &vapontador[i]);
    }
}
void case2insercao(int *vapontador, int t)
{
    int i, j, tmp;
    for (i = 1; i < t; i++)
    {
        tmp = vapontador[i];
        for (j = i - 1; j >= 0 && tmp < vapontador[j]; j--)
        {
            vapontador[j + 1] = vapontador[j];
        }
        vapontador[j + 1] = tmp;
    }
}
int buscabinaria(int *vapontador, int t, int elem)
{
    printf("Qual valor deseja procurar ?\n");
    scanf("%d", &elem);
    int i, inicio, meio, final;
    inicio = 0;
    final = t - 1;
    while (inicio <= final)
    {
        meio = (inicio + final) / 2;
        if (elem < vapontador[meio])
            final = meio - 1;
        else if (elem > vapontador[meio])
            inicio = meio + 1;
        else
            return meio;
    }
    return -1;
}

void imprimir(int *vapontador, int t)
{
    if (t == 1)
    {
        printf("%d\n", vapontador[t - 1]);
    }
    else
    {
        imprimir(vapontador, t - 1);
        printf("%d\n", vapontador[t - 1]);
    }
}

int main(void)
{
    int tb = 0;
    int opcao;
    int *vapontador, t;
    printf("      Bem vindo ao menu de opções\n\n");
    printf("Insira o tamanho que você deseja usar ?\n");
    scanf("%d", &t);

    vapontador = malloc(sizeof(int) * t);

    printf("Qual das opções abaixo deseja?\n\n");
    printf("1- Inserir dados\n");
    printf("2- Ordena dados\n");
    printf("3- Imprimir dados\n");
    printf("4- Realizar busca de dados\n");
    printf("0- Sair\n\n");
    scanf("%d", &opcao);
    while (opcao != 0)
    {
        switch (opcao)
        {
        case 1:
            case1(vapontador, t);
            break;
        case 2:
            case2insercao(vapontador, t);
            break;
        case 3:
            imprimir(vapontador, t);
            break;
        case 4:
            tb = buscabinaria(vapontador, t, elem);
            printf("    Iniciando busca\n\n");
            if (tb != -1)
            {
                printf("O numero que voçê procura esta na posição %d.\n", tb + 1);
            }
            else
            {
                printf("Nada foi encontrado.\n");
            }
            break;
        }
        printf("Qual das opções abaixo deseja ?\n\n");
        printf("1- Inserir dados\n");
        printf("2- Ordena dados\n");
        printf("3- Imprimir dados\n");
        printf("4- Realizar busca de dados\n");
        printf("0- Sair\n\n");
        scanf("%d", &opcao);
    }
    printf("VOCE SAIU DO PROGRAMA");
    return 0;
}
