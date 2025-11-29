#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include <string.h>
#include <stdlib.h>

typedef struct data
{
    int dia,mes,ano;
} Data;

typedef struct vendas
{
    int id;
    char cliente[50],vendedor[50],mat[5];
    Data data;
    float valor;
} vendas;


typedef struct NoArvore
{
    vendas info;
    struct NoArvore *esq;
    struct NoArvore *dir;
} NoArv;

typedef struct Arvore
{
    NoArv *raiz;
} Arv;

Arv* Criar_Arvore()
{
    Arv *aux;
    aux = (Arv*)malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}

int ArvVazia(Arv *base)
{
    if(base->raiz==NULL)
    {
        return 1;
    }
    return 0;
}


NoArv  *aux_insere(NoArv *no, vendas num)
{
    int flag;
    NoArv *Pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->info= num;
    novo->esq = NULL;
    novo->dir = NULL;

    if(no==NULL)
    {
        return novo;
    }

    else
    {
        Pai = no;
        flag = 0;
        while(flag==0)
        {
            if(Pai->info.id<num.id)
            {
                if(Pai->dir == NULL)
                {
                    Pai->dir = novo;
                    flag=1;
                }
                else
                {
                    Pai=Pai->dir;
                }
            }
            else
            {
                if(Pai->info.id>num.id)
                {
                    if(Pai->esq==NULL)
                    {
                        Pai->esq=novo;
                        flag=1;
                    }
                    else
                    {
                        Pai=Pai->esq;
                    }
                }
            }
        }
    }
    return no;
}


void insere(Arv* Arvore,vendas vnd)
{

    Arvore->raiz=aux_insere(Arvore->raiz,vnd);
}




int verifica_existencia(NoArv *no,int id)
{

    if (no != NULL)
    {
        if(no->info.id==id)
    {
        return 1;
    }

    if(id>no->info.id)
        return verifica_existencia(no->dir,id);
    if(id<no->info.id)
        return verifica_existencia(no->esq,id);
    }return 0;


}



void imprimir_arvore(NoArv *no)
{


    if(no!=NULL)
    {

        imprimir_arvore(no->esq);
        printf("%-4d | %-15s | %-10s | %-15s | %02d/%02d/%04d | R$ %-.2f\n",no->info.id,no->info.vendedor,no->info.mat,no->info.cliente,no->info.data.dia,no->info.data.mes,no->info.data.ano,no->info.valor);
        imprimir_arvore(no->dir);
    }
}


    void retorna_nome(NoArv *no,vendas *aux){

        if(no!=NULL){

            if(!strcmp(no->info.mat,aux->mat))
            {
                strcpy(aux->vendedor,no->info.vendedor);
            }

            retorna_nome(no->dir,aux);
            retorna_nome(no->esq,aux);


        }


    }



void BuscarVendas(NoArv *no,char vendedor[])
{

    if(no!=NULL&&vendedor!=NULL)
    {
        if(!strcmp(vendedor,no->info.vendedor)||!strcmp(vendedor,no->info.mat))
           {
                    printf("%-5d | %-50s |  %02d/%02d/%04d  | R$ %-.2f\n",
               no->info.id,
               no->info.cliente,
               no->info.data.dia,
               no->info.data.mes,
               no->info.data.ano,
               no->info.valor);
        }
        BuscarVendas(no->dir,vendedor);
        BuscarVendas(no->esq,vendedor);
    }

}



    float faturamento(NoArv *no){
        if (no == NULL)
            return 0;
        float S = no->info.valor;


        if(no->dir!=NULL)
            S+=faturamento(no->dir);
        if(no->esq!=NULL)
            S+=faturamento(no->esq);
        return S;

    }



    int QntVendas(NoArv *no){
        if(no==NULL)
            return 0;
        int i=1;

        if(no->dir!=NULL)
                 i+=QntVendas(no->dir);
        if(no->esq!=NULL)
                 i+=QntVendas(no->esq);


        return i;
    }




NoArv* remover_aux(NoArv *pai,int id)
{
    if(pai == NULL)
    {
        printf("\n\n ID nao encontrado!!\n");
    }
    else
        {
        if(id > pai->info.id)
        {
            pai->dir = remover_aux(pai->dir,id);
        }
        else
        {
            if(id < pai->info.id)
            {
                pai->esq = remover_aux(pai->esq,id);
            }


            else{

            if(pai->dir == NULL && pai->esq == NULL){
                free(pai);
                pai = NULL;
            }
            else
                {
                    if(pai->esq == NULL){
                    NoArv* aux = pai;
                    pai = pai->dir;
                    free(aux);
                } else {
                    if(pai->dir == NULL){
                        NoArv* aux = pai;
                        pai = pai->esq;
                        free(aux);
                    }
                     else
                      {
                        NoArv *aux;
                        aux = pai->esq;
                        while(aux->dir != NULL){
                            aux = aux->dir;
                        }
                        pai->info = aux->info;

                        pai->esq = remover_aux(pai->esq,id);
                    }
                }
           }
        }
      }
    }

    return pai;
}



    Arv* remover(Arv*RAIZ,int id){



        NoArv *aux=RAIZ->raiz;
        if(aux->info.id==id&&aux->dir==NULL&&aux->esq==NULL){
            free(aux);
            free(RAIZ);
            RAIZ->raiz=NULL;
            return RAIZ;
        }
        RAIZ->raiz=remover_aux(RAIZ->raiz,id);
        return RAIZ;

    }



    void acima(NoArv *no,float valor){

        if(no!=NULL){

            if(no->info.valor>=valor)
            {
                        printf("%-4d | %-15s | %-10s | %-15s | %02d/%02d/%04d | R$ %-.2f\n",no->info.id,no->info.vendedor,no->info.mat,no->info.cliente,no->info.data.dia,no->info.data.mes,no->info.data.ano,no->info.valor);

            }
            acima(no->dir,valor);
            acima(no->esq,valor);
        }


    }
        void abaixo(NoArv *no,float valor){

        if(no!=NULL){

            if(no->info.valor<valor)
            {
                        printf("%-4d | %-15s | %-10s | %-15s | %02d/%02d/%04d | R$ %-.2f\n",no->info.id,no->info.vendedor,no->info.mat,no->info.cliente,no->info.data.dia,no->info.data.mes,no->info.data.ano,no->info.valor);

            }
            abaixo(no->dir,valor);
            abaixo(no->esq,valor);
        }


    }




void liberaArv(NoArv *no)
{

    if(no!=NULL)
    {
        if(no->dir!=NULL)
            liberaArv(no->dir);
        if(no->esq!=NULL)
            liberaArv(no->esq);
        free(no);
    }
}











#endif
