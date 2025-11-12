#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int verificaID(Fila *N, Fila *E, int id, Fila *A)
{
    Nos *aux = N->ini;
    while (aux != NULL)
    {
        if (aux->dados.id == id)
        {
            return 1;
        }
        aux = aux->prox;
    }

    aux = E->ini;
    while (aux != NULL)
    {
        if (aux->dados.id == id)
        {
            return 1;
        }
        aux = aux->prox;
    }
    aux = A->ini;
    while (aux != NULL)
    {
        if (aux->dados.id == id)
        {
            return 1;
        }
        aux = aux->prox;
    }

    return 0;
}







int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao, id;
















    srand(time(NULL));
    printf("\n\n\n\n\t\t\t\t=============================================\n");
    printf("\t\t\t\t        BEM-VINDO(A) À LOJA   \n");
    printf("\t\t\t\t                        JUJU VENDAS                   \n");
    printf("\t\t\t\t=============================================\n");
    printf("\n");
    printf(" \t\t\t\tCuidando do seu pet com amor e dedicação!\n\n\n\n");
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
            Arv vnd = Criar_Arvore();
            id = rand() % 9000 + 1000;
            ;
            printf("=====================================\n");
            printf("         Cadastro do Animal           \n");
            printf("=====================================\n");

            while (verificaID(Arv,id))
            {
                id = rand() % 9000 + 1000;
                ;
            }
            printf("ID gerado automaticamente: %d\n", id);
            vnd.id = id;
            printf("Digite o nome do animal: ");
            gets(cad.nome);

            for (int i = 0; i < strlen(cad.nome); i++)
            {
                cad.nome[i]=tolower(cad.nome[i]);
            }
            printf("Digite a especie do animal: ");
            gets(cad.especie);
            printf("Digite a data de nascimento:\n");
            printf("Dia: ");
            scanf("%d", &cad.nas.dia);
            printf("Mes: ");
            scanf("%d", &cad.nas.mes);
            printf("Ano: ");
            scanf("%d", &cad.nas.ano);
            cad.idade=idade(cad.nas);
            printf("Idade:%d\n",cad.idade);

            printf("Digite a prioridade (0 - Normal | 1 - Urgente): ");
            scanf("%d", &cad.prioridade);
            if (cad.prioridade)
            {
                InsereFila(emer, cad);
                printf("Animal cadastrado com sucesso na emergencia!!\n\n");
            }
            else
            {
                InsereFila(normal, cad);
                printf("Animal cadastrado com sucesso no atendimento normal!!\n\n");
            }
            system("pause");
            break;

        case 2:

            fflush(stdin);
            system("cls");
            printf("\nAtendimento:\n\n");

            if (VaziaFila(emer) && VaziaFila(normal))
            {
                printf("\t\tSem Pacientes!!\n");
            }
            else
            {
                if (!VaziaFila(emer))
                {
                    printf("\t Animal com prioridade atendido:\n");
                    aux = RetiraFila(emer);
                    InsereFila(atendidos, aux);
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           aux.id, aux.nome, aux.especie, aux.idade,
                           aux.nas.dia, aux.nas.mes, aux.nas.ano,
                           aux.prioridade == 1 ? "Urgente" : "Normal");
                }
                else
                {
                    printf("\t Animal sem prioridade atendido:\n");
                    aux = RetiraFila(normal);
                    InsereFila(atendidos, aux);
                    printf("%-5d | %-15s | %-10s | %-5d | %02d/%02d/%04d | %s\n",
                           aux.id, aux.nome, aux.especie, aux.idade,
                           aux.nas.dia, aux.nas.mes, aux.nas.ano,
                           aux.prioridade == 1 ? "Urgente" : "Normal");
                }
            }

            system("pause");
            break;
        case 3:
            printf("\nBuscar um pet pelo nome e/ou ID.\n\n");
            buscaPet(normal, emer, atendidos);
            system("pause");
            break;

        case 4:
            imprimirFilas(normal, emer);
            break;

        case 5:
            fflush(stdin);
            system("cls");
            printf("\nPróximo pet a ser atendido:\n\n");
            if (VaziaFila(emer) && VaziaFila(normal))
            {
                printf("Sem pacientes .\n");
            }
            else
            {
                if (!VaziaFila(emer))
                {
                    printf("%-5d | %-15s | %-10s | %-5d | Urgente\n",
                           emer->ini->dados.id, emer->ini->dados.nome, emer->ini->dados.especie, emer->ini->dados.idade);
                }
                else
                {
                    printf("%-5d | %-15s | %-10s | %-5d | Normal\n",
                           normal->ini->dados.id, normal->ini->dados.nome, normal->ini->dados.especie, normal->ini->dados.idade);
                }
            }

            system("pause");
            break;
        case 6:
            fflush(stdin);
            system("cls");
            printf("\nPets que já foram atendidos:\n\n");
            if (VaziaFila(atendidos))
                printf("Nenhum pet foi atendido ainda.\n");
            else
            {
                imprimeFila(atendidos);
            }

            system("pause");
            break;

        case 7:
            fflush(stdin);
            system("cls");
            printf("\nSaindo do sistema. Até logo!\n");
            liberaFila(normal);
            liberaFila(emer);
            liberaFila(atendidos);
            return 0;

        default:
            printf("\nOpção inválida! Por favor, tente novamente.\n\n");
            break;
        }
    }
}








