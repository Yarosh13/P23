//
// Created by Yaroslav Mulyk - 2021133850
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"
#define MAX_PARAGENS 50

int main(){
    intro();
    int size=50;

    //Criar lista e ED
    pLinha linhaComboio = NULL; //Criar lista ligada (arranjar um ponteiro para a lista)
    Paragem * vetorParagens;
    vetorParagens = malloc(sizeof(Paragem) * MAX_PARAGENS);

    inicializarParagem(vetorParagens, MAX_PARAGENS);

    lista_vazia(linhaComboio);

    int escolha=999;


    while(1){

        menu();
        printf("\n-=}  ");
        scanf(" %d",&escolha);

        switch (escolha) {
            case 0:
                printf("\nA guardar as informacoes...\n");
                sleep(4);
                return 0;
                break;

            case 1:
                //imprimirParagens(LinhaComboio);
                menu_paragem(vetorParagens,MAX_PARAGENS);
                break;

            case 2:
                linhaComboio= menu_linhas(linhaComboio, vetorParagens);
                break;

            case 3:
                printf("Case 3\n");
                break;

            case 9:
                autor();
                break;

            default:
                printf("Oops.. Tente de novo\n");
                break;
        }



    }

//
//    // Libera a memória alocada pela linha de comboio
//    Linha* atual = linhaComboio;
//    while (atual != NULL) {
//        Linha* temp = atual;
//        atual = atual->prox;
//        free(temp);
//    }
    return 0;
};


