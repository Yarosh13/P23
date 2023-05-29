//
// Created by Yaroslav Mulyk - 2021133850
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"


pLinha menu_linhas(pLinha linhaComboio,Paragem* vetorParagens){
    int escolha=999;
    char qual_linha[4];

    while(1){

        menu2();
        printf("\n-=}");
        scanf(" %d",&escolha);

        switch (escolha) {
            case 0:
                printf("\nA voltar para o Menu Principal...\n");
                sleep(2);

                return linhaComboio;
                break;

            case 1:
                linhaComboio=insere_final(linhaComboio);
                //insere_inicio(l);
                break;

            case 2:
                printf("Case 2\n");
                break;

            case 3:
                if(lista_vazia(linhaComboio) ==1){
                    printf("Lista vazia!");
                }
                //mostra_linhas(linhaComboio);
                //MostrarParagens(vetorParagens,50);
                MostraLinhasParagens(linhaComboio);
                    break;
            case 4:
                linhaComboio =associaParagem(linhaComboio,vetorParagens);
                break;
            case 9:
                autor();
                break;

            default:
                printf("Oops.. Tente de novo\n");
                break;
        }

    }

};

int menu2(){
    sleep(0.5);
    printf("\n\t\tMENU DAS LINHAS\n");
    printf("1- ADICIONAR\n2- ELIMINAR\n3- Mostrar\n4- Associar Paragem\n0- Voltar\n");
}


int lista_vazia(pLinha l) {
    if (l == NULL)
        return 1;
    else
        return 0;
}
pLinha insere_final(pLinha l){
    pLinha novo,aux;
    novo = malloc(sizeof (Linha));
    if(novo == NULL){ printf("\nErro ao alocar memoria!"); return l;}

    // funcao que preenche lista.
    preenche_linha(novo);

    if(l == NULL){
        l = novo;
    }else{
        aux = l;
        while(aux->prox != NULL){
            aux=aux->prox;
        }
        aux->prox=novo;
    }
    return l;
}

pLinha insere_inicio(pLinha l){
    pLinha novo;
    if((novo = malloc(sizeof (Linha)))== NULL){
        printf("\nErro ao alocar memoria!");
        return l;
    } else{
        preenche_linha(novo);
        novo->prox=l;
        l=novo;
    }
    return l;
}

void preenche_linha(pLinha l){
    printf("Inroduza o nome da linha: ");
    scanf("%s",l->nome);
    printf("%s",l->nome);
    l->parag=NULL;
    l->numParagens=0;
    l->prox=NULL;
}

void mostra_linhas(pLinha l){
    if(lista_vazia(l) == 1){
        printf("Lista vazia");
    }
    while (l != NULL){
        printf("\nLinha: %s",l->nome);

        l = l->prox;
    }
}
/*
pLinha associaParagem(pLinha l,Paragem* vetorParagens){
    pLinha curr=l;
    char linhaNome[50],paragID[5];
    int sizeParagem=50;
    int numParag=9999;

    printf("\n Introduza o nome da Linha: ");
    scanf("%s",linhaNome);
    printf("\n Introduza o ID da Paragem: ");
    scanf("%s",paragID);


    while (curr != NULL){
        if(strcmp(curr->nome,linhaNome)==0){
            for (int i = 0; i < sizeParagem; ++i) {
                if(strcmp(vetorParagens[i].id,paragID)==0){
                    numParag=i;
                    printf("Paragem encontrada!");
                }
            }

            if (numParag != 9999){
                curr->parag = (Paragem**)realloc(curr->parag, (curr->numParagens+1) * sizeof(Paragem*));

                curr->parag[curr->numParagens+1]=&vetorParagens[numParag];
                printf("\nParagem associada!");
            }
        }
        curr=curr->prox;
    }
    curr->prox=l;
    l=curr;
    return l;
}
*/
pLinha associaParagem(pLinha l, Paragem* vetorParagens) {
    pLinha curr = l;
    char linhaNome[50], paragID[5];
    int sizeParagem = 50;
    int numParag = 9999;

    printf("\n Introduza o nome da Linha: ");
    scanf("%s", linhaNome);
    printf("\n Introduza o ID da Paragem: ");
    scanf("%s", paragID);

    while (curr != NULL) {
        if (strcmp(curr->nome, linhaNome) == 0) {
            for (int i = 0; i < sizeParagem; ++i) {
                if (strcmp(vetorParagens[i].id, paragID) == 0 && vetorParagens[i].associada != 1) {
                    numParag = i;
                    printf("Paragem encontrada!");
                }
            }

            if (numParag != 9999) {
                curr->numParagens=curr->numParagens+1;
                curr->parag = (Paragem**)realloc(curr->parag, curr->numParagens * sizeof(Paragem*));
                curr->parag[curr->numParagens-1] = &vetorParagens[numParag];
                vetorParagens[numParag].associada=1;
                printf("\nParagem associada!");
            }else{
                printf("A paragem nao existe ou ja esta associada a outra linha!");
            }
        }
        curr = curr->prox;
    }
// Pensar melhor nisto!!!
    if (numParag == 9999){
        printf("A linha introduzida nao existe!");
    }

    return l;
}


/*
void MostraLinhasParagens(pLinha l){
    pLinha curr=l;

    while (curr!=NULL){
        printf("\nLinha=%s",curr->nome);
        printf("\nNumero de paragens=%d",curr->numParagens);

        printf("\nParagens associadas\n");
        for (int i = 0; i < curr->numParagens; ++i) {
            printf(" - ID: %s",curr->parag[i]->id);
            printf(" - ID: %s",curr->parag[i]->nome);
            printf(" - ID: %d",curr->parag[i]->associada);
        }
        curr=curr->prox;
    }
}
*/
void MostraLinhasParagens(pLinha l) {
    pLinha curr = l;

    while (curr != NULL) {
        printf("\nLinha=%s", curr->nome);
        printf("\nNumero de paragens=%d", curr->numParagens);

        printf("\nParagens associadas\n");
        for (int i = 0; i < curr->numParagens; ++i) {
            printf(" - ID: %s\n", curr->parag[i]->id);
            printf(" - Nome: %s\n", curr->parag[i]->nome);
            printf(" - Associada: %d\n", curr->parag[i]->associada);
        }
        curr = curr->prox;
    }
}





