//
// Created by Yaroslav Mulyk - 2021133850
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"
#include <time.h>

int MenuParagem(Paragem* vetorParagens, int *size){
    int escolha=999;
    int sizeP=*size;
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
                return 0;
                break;

            case 1:
                (*size)++;
                vetorParagens = realloc(vetorParagens, sizeof(Paragem)* (*size));

                AdicionarParagem(vetorParagens, size);

                break;

            case 2:
                el=EliminaParagem(vetorParagens,size);

                if(el == 1){
                    (*size)--;
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

    GeraID(vetor,pos, *size);
}

int MostrarParagens(Paragem* vetor, int size){

    for (int i = 0; i < size; ++i) {
            printf("\nID paragem: %s",vetor[i].id);
            printf("\nNome paragem: %s",vetor[i].nome);
    }
}

int GeraID(Paragem* vetor,int pos, int size){

    while(1){
        vetor[pos].id[0] = 'A' + rand() % 26;  // Generate random uppercase letter ['A'-'Z']
        vetor[pos].id[1] = '0' + rand() % 10;  // Generate random digit [0-9]
        vetor[pos].id[2] = '0' + rand() % 10;  // Generate random digit [0-9]
        vetor[pos].id[3] = '0' + rand() % 10;  // Generate random digit [0-9]
        vetor[pos].id[4] = '\0';  // Null-terminate the string

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
    int eliminado=0;
    char sn;

    for (int i = 0; i < *size; ++i) {
        if(strcmp(vetor[i].id,ideliminar)==0 && vetor[i].associada==0){
            printf("\nYES SIR!!");
        }
    }


    do{
        if(strcmp(vetor[cont].id,ideliminar)==0 && vetor[cont].associada==0){
            printf("\n OK e igual!");
            //função elimina
            do {
                printf("\nELIMINACAO DE UMA PARAGEM\n ID %s\n Nome;%s\n\nTem a certeza?(y/n)\n-=}",vetor[cont].id,vetor[cont].nome);
                scanf("%s",&sn);
                if (sn == 'y'){

                    printf("\nA paragem com o ID %s foi eliminada com sucesso!",vetor[cont].id);
                    strcpy(vetor[cont].nome, "NULL");
                    strcpy(vetor[cont].id, "NULL");
                    vetor[cont].associada=0;

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

                    sair=1;
                    break;

                }else if(sn == 'n'){
                    printf("\nOperação cancelada!");
                    sair=1;
                    break;
                }
            }while (sn != 'y'||sn != 'n');
        }else if(strcmp(vetor[cont].id,ideliminar)==0 && vetor[cont].associada!=0){
            printf("\nImpossivel realizar esta operacao|\n\t[NOTA]: Esta paragem esta associada a uma linha");

        }

        if(cont == *size){
            sair=1;
            eliminado=1;
        }
        cont++;
    } while (sair !=1);
    if(eliminado == 1){
        printf("\nID nao existe!");
    }

    return eliminado;

}
