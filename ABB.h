#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include <string.h>

typedef struct data
{
    int dia,mes,ano;
} Data;

typedef struct vendas{
    int id;
    char cliente[50],vendedor[50],mat[4];
    Data data;
    float valor;
}vendas;


typedef struct NoArvore
{
    vendas info;
    struct NoArvore *esq;
    struct NoArvore *dir;
}NoArv;

typedef struct Arvore{
    NoArv *raiz;
}Arv;

Arv* Criar_Arvore(){
    Arv *aux;
    aux = (Arv*)malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}

int ArvVazia(Arv *base){
    if(base->raiz==NULL){
        return 1;
    }
    return 0;
}

void insere(Arv* Arvore,vendas vnd){

    Arvore->raiz=aux_insere(Arvore->raiz,vnd)
}




NoArv* aux_insere(NoArv *no, vendas num){
    int flag;
    NoArv *Pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->info.id = num.id;
    novo->esq = NULL;
    novo->dir = NULL;

    if(no==NULL){
        return novo;
    }

    else{
            Pai = no;
            flag = 0;
            while(flag==0){
                if(Pai->info.id<num){
                    if(Pai->dir == NULL){
                        Pai->dir = novo;
                        flag=1;
                    }
                    else{
                        Pai=Pai->dir;
                    }
                }
                else{
                    if(Pai->info.id>num){
                        if(pai->esq==NULL){
                            Pai->esq=novo;
                            flag=1;
                        }
                        else{
                            Pai=Pai->esq;
                        }
                    }
                }
            }
    }
    return no;
}






#endif
