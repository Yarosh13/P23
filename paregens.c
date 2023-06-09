//
// Created by Yaroslav Mulyk - 2021133850
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"
#include <time.h>

Paragem* MenuParagem(Paragem* vetorParagens, int *size){
    int escolha=999;
    int el=0;
    while(1){
        srand(time(0));
        MenuParagens();
        printf("\n-=}");
        fflush(stdin);
        scanf(" %d",&escolha);

        switch (escolha) {
            case 0:
                printf("\nA voltar para o Menu Principal...\n");
                sleep(1);
                return vetorParagens;
                break;

            case 1:
                (*size)++;
                vetorParagens = realloc(vetorParagens, sizeof(Paragem)* (*size));

                AdicionarParagem(vetorParagens, size);

                break;

            case 2:
                el=EliminaParagem(vetorParagens,size);

                if(el != 1){

                    vetorParagens = realloc(vetorParagens, sizeof(Paragem)* (*size));

                }


                break;

            case 3:
                MostrarParagens(vetorParagens,*size);
                break;

            case 9:
                Autor();
                break;

            default:
                printf("Oops.. Tente de novo\n");
                break;
        }

    }
}

int MenuParagens(){
    sleep(0.5);
    printf("\n\n\t\tMENU DAS PARAGENS\n");
    printf("1- ADICIONAR\n2- ELIMINAR\n3- Mostrar Paragens\n0- Voltar\n");
}

/*
int InicializarParagem(Paragem* vetor, int *size){
    //printf("%d",size);
    for (int i = 0; i < size; i++) {
        strcpy(vetor[i].nome, "NULL");
        strcpy(vetor[i].id, "NULL");
        vetor[i].associada = 0;
    }
    return 0;
}
*/

int AdicionarParagem(Paragem* vetor, int *size){
    int pos;

    pos = *size - 1;
    printf("\nIntroduza o nome da paragem: ");
    scanf("%s",vetor[pos].nome);
    vetor[pos].associada=0;
    GeraID(vetor,pos, *size);
}

int MostrarParagens(Paragem* vetor, int size){
    for (int i = 0; i < size; ++i) {
        printf("\n\nID paragem: %s",vetor[i].id);
        printf("\nNome paragem: %s",vetor[i].nome);
        if(vetor[i].associada != 1){
            printf("\nAssociada: NAO");
        }else{
            printf("\nAssociada: SIM");
        }
    }
}

int GeraID(Paragem* vetor,int pos, int size){
    while(1){
        vetor[pos].id[0] = 'A' + rand() % 26;
        vetor[pos].id[1] = '0' + rand() % 10;
        vetor[pos].id[2] = '0' + rand() % 10;
        vetor[pos].id[3] = '0' + rand() % 10;
        vetor[pos].id[4] = '\0';

        for (int i = 0; i < size; ++i) {
            if(strcmp(vetor[i].id,vetor[pos].id)!=0 || size<=1){
                return 1;
            }
        }
    }
}

int EliminaParagem(Paragem* vetor, int *size){
    char ideliminar[5];

    printf("\nParagem a eliminar\n Introduza o ID: ");
    scanf("%s",ideliminar);

    int cont=0;
    int sair=0;
    int eliminado=1;
    char sn;
    printf("\n%d",*size);
    for (int i = 0; i < *size; ++i) {

        if(strcmp(vetor[i].id,ideliminar)==0 && vetor[i].associada==0){
            printf("\nYES SIR!!");

            do {
                printf("\nELIMINACAO DE UMA PARAGEM\n ID %s\n Nome;%s\n\nTem a certeza?(y/n)\n-=}",vetor[cont].id,vetor[cont].nome);
                scanf("%s",&sn);
                if (sn == 'y'){

                    printf("\nA paragem com o ID %s foi eliminada com sucesso!",vetor[cont].id);
                    strcpy(vetor[i].nome, "NULL");
                    strcpy(vetor[i].id, "NULL");
                    vetor[i].associada=0;

                    for (int i = 0; i < *size; i++) {
                        if (strcmp(vetor[i].id, "NULL") == 0) {
                            for (int j = i; j < *size - 1; j++) {
                                strcpy(vetor[j].nome, vetor[j + 1].nome);
                                strcpy(vetor[j].id, vetor[j + 1].id);
                                vetor[j].associada = vetor[j + 1].associada;
                            }
                            strcpy(vetor[*size - 1].nome, "NULL");
                            strcpy(vetor[*size - 1].id, "NULL");
                            vetor[*size - 1].associada = 0;
                            (*size)--;
                            i--;  // Process the new element at index i
                        }
                    }
                    eliminado=0;
                    break;

                }else if(sn == 'n'){
                    printf("\nOperação cancelada!");
                    eliminado=0;
                    break;
                }
            }while (sn != 'y'||sn != 'n');
        }
    }
    if(eliminado == 1){
        printf("\nID nao existe!");
    }

}

void GuardaDadosParagem(Paragem* vetor, int sizeP){
    
}
