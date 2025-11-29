#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>




void gerarmatricula(char *dest)
{
    int aux1 = rand() % 900 + 100;
    sprintf(dest, "v%d", aux1);
}


void data(vendas *aux) {
    printf("Digite a data da venda:\n");
    do {
        printf("Dia: ");
        fflush(stdin);
        scanf("%d", &aux->data.dia);

        if(aux->data.dia < 1 || aux->data.dia > 31) {
            printf("Valor incorreto! O dia deve ser entre 1 e 31.\n");
        }

    } while (aux->data.dia < 1 || aux->data.dia > 31);
    do {
        printf("Mes: ");
        fflush(stdin);
        scanf("%d", &aux->data.mes);

        if(aux->data.mes < 1 || aux->data.mes > 12) {
            printf("Valor incorreto! O mes deve ser entre 1 e 12.\n");
        }

    } while (aux->data.mes < 1 || aux->data.mes > 12);
    do {
        printf("Ano: ");
        fflush(stdin);
        scanf("%d", &aux->data.ano);

        if(aux->data.ano < 2020 || aux->data.ano > 2030) {
            printf("Valor incorreto! O ano deve ser entre 2020 e 2030.\n");
        }

    } while (aux->data.ano < 2020 || aux->data.ano > 2030);


    printf("Data valida: %02d/%02d/%04d\n",
           aux->data.dia, aux->data.mes, aux->data.ano);
}




int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao, id;
    Arv *vnd = Criar_Arvore();
    vendas aux;
    char auxVend[50];
    srand(time(NULL));

    printf("\n");
    printf("\t\t\t\t=============================================\n");
    printf("\t\t\t\t      BEM-VINDO(A) AO ESTOQUE DA LOJA        \n");
    printf("\t\t\t\t---------------------------------------------\n");
    printf("\n\t\t\t\t\tRegistro e busca de vendas !\n\n");
    printf("\t\t\t\t=============================================\n");

    printf("\n");

    system("pause");
    fflush(stdin);

    while (1)
    {
        system("cls");
        printf("---------------------------------------------\n");
        printf("                 MENU PRINCIPAL               \n");
        printf("---------------------------------------------\n");
        printf(" 1. Inserir uma nova venda\n");
        printf(" 2. Listar todas as vendas\n");
        printf(" 3. Buscar as vendas de um Vendedor\n");
        printf(" 4. Listar vendas acima ou abaixo de um valor\n");
        printf(" 5. Exibir estatísticas\n");
        printf(" 6. Remoção de uma venda\n");
        printf(" 7. Sair\n");
        printf("---------------------------------------------\n");
        printf("Digite a opção desejada: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            fflush(stdin);
            system("cls");

            id = rand() % 9000 + 1000;

            printf("\t\t\t\t\t=====================================\n");
            printf("\t\t\t\t\t         Registrar Venda:           \n");
            printf("\t\t\t\t\t=====================================\n");

            while (verifica_existencia(vnd->raiz,id))
            {
                id = rand() % 9000 + 1000;

            }
            printf("ID gerado automaticamente: %d\n", id);
            aux.id = id;

            printf("Digite o nome do Cliente: ");
            gets(aux.cliente);
            strlwr(aux.cliente);

            char a, b[4];


            do
            {
                printf("O vendedor já foi cadastrado:\nDigite s ou n: ");
                fflush(stdin);
                scanf(" %c", &a);
                a = tolower(a);

            }
            while (a != 's' && a != 'n');

            if(a == 's')
            {
                printf("Digite a matricula: \n");
                fflush(stdin);
                gets(b);
                strcpy(aux.mat,b);
                retorna_nome(vnd->raiz,&aux);
                printf("Nome do vendedor:%s\n",aux.vendedor);

            }
            else
            {

                printf("Digite o nome do vendedor: ");
                fflush(stdin);
                gets(aux.vendedor);
                strlwr(aux.vendedor);
                gerarmatricula(aux.mat);
                printf("Matricula do vendedor:%s\n",aux.mat);
            }

            data(&aux);

            printf("Digte o valor da venda:");
            scanf("%f",&aux.valor);

            insere(vnd,aux);
            system("pause");
            break;

        case 2:
            fflush(stdin);
            system("cls");
            printf("\t\t\t\t\t=====================================\n");
            printf("\t\t\t\t\t         Listar todas as vendas:           \n");
            printf("\t\t\t\t\t=====================================\n");


            printf("ID   | Vendedor        | Matricula  | Cliente          | Data         | Valor(R$)\n");
            printf("-----+-----------------+------------+------------------+--------------+-----------\n");
            imprimir_arvore(vnd->raiz);

            system("pause");
            break;
        case 3:
            fflush(stdin);
            system("cls");
            printf("\t\t\t\t\t=====================================\n");
            printf("\t\t\t\t\t   Buscar as vendas de um  Vendedor  \n");
            printf("\t\t\t\t\t=====================================\n");
            printf("Digite o nome ou a matricula do vendedor:");
            gets(auxVend);
            strlwr(auxVend);

            printf("ID    | Cliente                                            | Data de Transação | Valor(R$)\n");
            printf("------+----------------------------------------------------+-------------------+----------\n");

            BuscarVendas(vnd->raiz,auxVend);
            system("pause");
            break;

        case 4:

            fflush(stdin);
            system("cls");
            printf("\t\t\t\t\t======================================\n");
            printf("\t\t\t\t\t  vendas acima ou abaixo de um valor  \n");
            printf("\t\t\t\t\t======================================\n");

            float aux_vendas;
            printf("Digite o valor base: ");
            scanf("%f",&aux_vendas);
            char e[7];
            printf("Digite acima ou abaixo\n");
            fflush(stdin);
            gets(e);
            strlwr(e);
            if(!strcmp(e,"acima"))
            {
                acima(vnd->raiz,aux_vendas);
            }
            else
            {
                abaixo(vnd->raiz,aux_vendas);
            }


            system("pause");
            break;

        case 5:
            fflush(stdin);
            system("cls");
            printf("\t\t\t\t\t=====================================\n");
            printf("\t\t\t\t\t            estatísticas             \n");
            printf("\t\t\t\t\t=====================================\n");

            printf("Numero total de venda: %d",QntVendas(vnd->raiz));
            printf("\nFaturamento: R$ %-.2f\n",faturamento(vnd->raiz));

            system("pause");
            break;
        case 6:
            fflush(stdin);
            system("cls");
            printf("\t\t\t\t\t=====================================\n");
            printf("\t\t\t\t\t            Remover Venda            \n");
            printf("\t\t\t\t\t=====================================\n");

            int auxDOid;
            printf("Digite o ID a ser removido:");
            scanf("%d",&auxDOid);
            remover(vnd,auxDOid);


            system("pause");
            break;

        case 7:
            fflush(stdin);
            system("cls");
            printf("\nSaindo do sistema. Até logo!\n");
            liberaArv(vnd->raiz);
            free(vnd);

            return 0;

        default:
            printf("\nOpção inválida! Por favor, tente novamente.\n\n");
            break;
        }
    }
}








