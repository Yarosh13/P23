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
                if(ListaVazia(linhaComboio) ==1){
                    printf("Lista vazia!");
                }else{
                    linhaComboio = AssociaParagem(linhaComboio,vetorParagens);
                }
                break;
            case 5:
                if(ListaVazia(linhaComboio) ==1){
                    printf("Lista vazia!");
                }else{
                    linhaComboio = DesAssociarParagem(linhaComboio,vetorParagens);
                }
                break;
            case 6:
                if(ListaVazia(linhaComboio) ==1){
                    printf("Lista vazia!");
                }else{
                    linhaComboio = MudarSequenciaParagens(linhaComboio,vetorParagens);
                }
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
    printf("1- ADICIONAR\n2- ELIMINAR\n3- Mostrar\n4- Associar Paragem\n5- Desassociar Paragem\n6- Mudar Sequencia\n0- Voltar\n");
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

pLinha MudarSequenciaParagens(pLinha l, Paragem* vetor) {
    pLinha curr = l;
    char linhaNome[50];
    int contador1=0, contador2=0,posID=0,aux[curr->numParagens];
    int sizeP=50;
    int jaexiste=-1,Lencontrada=-1, temP=-1;

    printf("\n Introduza o nome da linha para mudar sequencia das paragem:");
    scanf("%s", linhaNome);
    while (curr != NULL){
        if (strcmp(curr->nome, linhaNome) == 0) {
            Lencontrada=0;
            if(curr->numParagens == 0){
                temP=0;
            }
            while(contador1 < curr->numParagens){
                for (int i = 0; i < sizeP; ++i) {
                    if(strcmp(curr->parag[contador1]->id,vetor[i].id)==0){
                        aux[contador1]=i;
                        contador1++;
                    }
                }
            }
            for (int i = 0; i < curr->numParagens; ++i) {
                printf("\n%d - ID: %s",(i+1),vetor[aux[i]].id);

            }
            while(contador2 < curr->numParagens){
                printf("\n Checked!");
                do{
                    printf("\n Introduza a %d posicao: ",contador2+1);
                    scanf("%d",&posID);
                    posID-=1;
                }while(posID > curr->numParagens);


                for (int i = contador2; i >= 0 ; --i) {
                    if(strcmp(curr->parag[contador2]->id,vetor[aux[posID]].id)==0){
                        jaexiste=1;
                    }
                }
                if(jaexiste == -1){
                    curr->parag[contador2]=&vetor[aux[posID]];
                    contador2++;
                }else{
                    printf("\nA paragem que tentou intreoduzir ja se encontra na nova sequencia! ");
                    jaexiste=-1;
                }
            }
        }
        curr = curr->prox;
    }
    if (Lencontrada == -1){
        printf("A linha introduzida nao existe!");
    }
    if(temP==0){
        printf("\nA linha introduzida nao tem paragens associadas!");
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





















