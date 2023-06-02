//
// Created by Yaroslav Mulyk - 2021133850
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"


pLinha MenuLinha(pLinha linhaComboio,Paragem* vetorParagens){
    int escolha=999;
    char qual_linha[4];

    while(1){

        MenuLinhas();
        printf("\n-=}");
        scanf(" %d",&escolha);

        switch (escolha) {
            case 0:
                printf("\nA voltar para o Menu Principal...\n");
                sleep(2);

                return linhaComboio;
                break;

            case 1:
                linhaComboio=InsereFinal(linhaComboio);
                //InsereInicio(l);
                break;

            case 2:
                printf("Case 2\n");
                linhaComboio = MudarSequenciaParagens(linhaComboio);
                break;

            case 3:
                if(ListaVazia(linhaComboio) ==1){
                    printf("Lista vazia!");
                }else{
                    MostraLinhasParagens(linhaComboio);
                }
                    //mostra_linhas(linhaComboio);
                    //MostrarParagens(vetorParagens,50);



                break;
            case 4:
                linhaComboio = AssociaParagem(linhaComboio,vetorParagens);
                break;
            case 5:
                linhaComboio = DesAssociarParagem(linhaComboio,vetorParagens);
                break;
            case 9:
                Autor();
                break;

            default:
                printf("Oops.. Tente de novo\n");
                break;
        }

    }

};

int MenuLinhas(){
    sleep(0.5);
    printf("\n\t\tMENU DAS LINHAS\n");
    printf("1- ADICIONAR\n2- ELIMINAR\n3- Mostrar\n4- Associar Paragem\n5- Desassociar Paragem\n0- Voltar\n");
}

int ListaVazia(pLinha l) {
    if (l == NULL)
        return 1;
    else
        return 0;
}

pLinha InsereFinal(pLinha l){
    pLinha novo,aux;
    novo = malloc(sizeof (Linha));
    if(novo == NULL){ printf("\nErro ao alocar memoria!"); return l;}

    // funcao que preenche lista.
    PreencheLinha(novo);

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

pLinha InsereInicio(pLinha l){
    pLinha novo;
    if((novo = malloc(sizeof (Linha)))== NULL){
        printf("\nErro ao alocar memoria!");
        return l;
    } else{
        PreencheLinha(novo);
        novo->prox=l;
        l=novo;
    }
    return l;
}

void PreencheLinha(pLinha l){
    printf("Inroduza o nome da linha: ");
    scanf("%s",l->nome);
    printf("%s",l->nome);
    l->parag=NULL;
    l->numParagens=0;
    l->prox=NULL;
}

void MostraLinhas(pLinha l){
    if(ListaVazia(l) == 1){
        printf("Lista vazia");
    }
    while (l != NULL){
        printf("\nLinha: %s",l->nome);

        l = l->prox;
    }
}

pLinha AssociaParagem(pLinha l, Paragem* vetorParagens) {
    pLinha curr = l;
    char linhaNome[50], paragID[5];
    int sizeParagem = 50;
    int numParag = -1,numLin = -1;
    char sn;

    printf("\n Introduza o nome da Linha: ");
    scanf("%s", linhaNome);

    while (curr != NULL) {
        if (strcmp(curr->nome, linhaNome) == 0) {
            do {
                printf("Apresentar uma lista com paragem que pode associar?(y/n): ");
                scanf("%s",&sn);
                if (sn == 'y'){
                    printf("\nParagens nao associadas");
                    for (int i = 0; i < sizeParagem; ++i) {
                        if(vetorParagens[i].associada != 1 && strcmp(vetorParagens[i].id, "NULL")!=0){
                            printf("\n - ID: %s", vetorParagens[i].id);
                            printf("\t - Nome: %s", vetorParagens[i].nome);
                        }
                    }
                    break;
                }else if(sn == 'n'){
                    printf("\nOperação cancelada!");
                    break;
                }
            }while (sn != 'y'|| sn != 'n');

            numLin=1;
            printf("\n Introduza o ID da Paragem: ");
            scanf("%s", paragID);

            for (int i = 0; i < sizeParagem; ++i) {
                if (strcmp(vetorParagens[i].id, paragID) == 0 && vetorParagens[i].associada != 1) {
                    numParag = i;
                }
            }

            if (numParag != -1) {
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
    if (numLin == -1){
        printf("A linha introduzida nao existe!");
    }

    return l;
}

pLinha DesAssociarParagem(pLinha l, Paragem* vetorParagens) {
    pLinha curr = l;
    char linhaNome[50], paragID[5];
    int sizeParagem = 50;
    int numParag = 9999,numLin = -1,posicao;

    printf("\n Introduza o nome da linha para desassociar a paragem:  ");
    scanf("%s", linhaNome);

    while(curr != NULL){
        if (strcmp(curr->nome, linhaNome) == 0) {
            numLin=1;
            // Mostrar ao user as paragem que estão associadas a linha
            printf("\nParagen associadas a Linha %s",curr->nome);
            for (int i = 0; i < curr->numParagens; ++i) {
                printf("\n - ID: %s", curr->parag[i]->id);
                printf("\t - Nome: %s", curr->parag[i]->nome);
            }

            // Pedir o ID da paragem e encontrar a posição dela na lista se existir
            printf("\n Introduza o ID da Paragem a desassociar:  ");
            scanf("%s", paragID);
            posicao=-1;
            for (int i = 0; i < curr->numParagens; ++i) {
                if (strcmp(curr->parag[i]->id, paragID) == 0) {
                    posicao=i;
                    break;
                }
            }

            if(posicao != -1){
                //Atualizar a estrutura Paragem com a informação de deassociação
                for (int i = 0; i < sizeParagem; ++i) {
                    if(strcmp(vetorParagens[i].id,curr->parag[posicao]->id)==0){
                        vetorParagens[i].associada=0;
                    }
                }

                // Desaasociar a paragem da linha
                printf("\nA paragem %s ira ser desassociada!", curr->parag[posicao]->id);
                curr->numParagens=curr->numParagens-1;

                for (int i = posicao; i< curr->numParagens; ++i) {
                    curr->parag[i]=curr->parag[i+1];
                }
                curr->parag = (Paragem**)realloc(curr->parag, curr->numParagens * sizeof(Paragem*));
            }else{
                printf("\n A paragem introduzida nao existe ou nao se encontra associada a esta linha");
            }
        }
        curr = curr->prox;
    }
    if (numLin == -1){
        printf("A linha introduzida nao existe!");
    }
    return l;
}

pLinha MudarSequenciaParagens(pLinha l) {
    pLinha curr = l;
    char aux[curr->numParagens][5],linhaNome[50];


    printf("\n Introduza o nome da linha para mudar sequencia das paragem:");
    scanf("%s", linhaNome);
    while (curr != NULL){
        if (strcmp(curr->nome, linhaNome) == 0) {
            for (int i = 0; i < curr->numParagens; ++i) {
                for (int j = 0; j < 5; ++j) {
                    aux[i][j] = curr->parag[i]->id[j];
                }
            }
            for (int i = 0; i < curr->numParagens; ++i) {
                for (int j = 0; j < 5; ++j) {
                    printf("%c", aux[i][j]);
                }
                putchar('\n');
            }

            for (int i = 0; i < curr->numParagens; ++i) {
                printf(" => %d-%s",i, curr->parag[i]->nome);
            }


        }
        curr = curr->prox;
    }

    return  l;
}

void MostraLinhasParagens(pLinha l) {
    pLinha curr = l;

    while (curr != NULL) {
        printf("\nParagens associadas a Linha %s(%d)", curr->nome,curr->numParagens);
        //printf("\nNumero de paragens=%d", );

        //printf("\nParagens associadas\n");
        for (int i = 0; i < curr->numParagens; ++i) {
            printf("\n - ID: %s", curr->parag[i]->id);
            printf("\t - Nome: %s\n", curr->parag[i]->nome);
           // printf(" - Associada: %d\n", curr->parag[i]->associada);
        }
        curr = curr->prox;
    }
}





















