//
// Created by Yaroslav Mulyk - 2021133850
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"
#include <time.h>

int MenuParagem(Paragem* vetorParagens, int size){
    int escolha=999;

    while(1){
        srand(time(0));
        MenuParagens();
        printf("\n-=}");
        scanf(" %d",&escolha);

        switch (escolha) {
            case 0:
                printf("\nA voltar para o Menu Principal...\n");
                sleep(2);
                return 0;
                break;

            case 1:
                AdicionarParagem(vetorParagens,size);
                break;

            case 2:
                EliminaParagem(vetorParagens,size);
                break;

            case 3:
                MostrarParagens(vetorParagens,size);
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

int InicializarParagem(Paragem* vetor, int size){
    //printf("%d",size);
    for (int i = 0; i < size; i++) {
        strcpy(vetor[i].nome, "NULL");
        strcpy(vetor[i].id, "NULL");
        vetor[i].associada = 0;
    }
    return 0;
}

int AdicionarParagem(Paragem* vetor, int size){
    int novo;
    for(int i=0; i<size;i++){

        if(strcmp(vetor[i].id,"NULL") == 0){
            novo=i;
        }
    }
    printf("\nIntroduza o nome da paragem: ");
    scanf("%s",vetor[novo].nome);

    GeraID(vetor,novo,size);

}

int MostrarParagens(Paragem* vetor, int size){
    for (int i = 0; i < size; ++i) {
        if(strcmp(vetor[i].id,"NULL")!= 0){
            printf("\nID paragem: %s",vetor[i].id);
            printf("\nNome paragem: %s",vetor[i].nome);
        }
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
            if(strcmp(vetor[i].id,vetor[pos].id)!=0){
                return 1;
            }
        }
    }

}

int EliminaParagem(Paragem* vetor, int size){
    char ideliminar[5];

    printf("\nParagem a eliminar\n Introduza o ID: ");
    scanf("%s",ideliminar);

    int cont=0;
    int sair=0;
    int eliminado=0;
    char sn;
    do{
        if(strcmp(vetor[cont].id,ideliminar)==0 && vetor[cont].associada==0){
            //função elimina
            do {
                printf("\nELIMINACAO DE UMA PARAGEM\n ID %s\n Nome;%s\n\nTem a certeza?(y/n)\n-=}",vetor[cont].id,vetor[cont].nome);
                scanf("%s",&sn);
                if (sn == 'y'){

                    printf("\nA paragem com o ID %s foi eliminada com sucesso!",vetor[cont].id);
                    strcpy(vetor[cont].nome, "NULL");
                    strcpy(vetor[cont].id, "NULL");
                    vetor[cont].associada=0;
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

        if(cont == size){
            sair=1;
            eliminado=1;
        }
        cont++;
    } while (sair !=1);
    if(eliminado == 1){
        printf("\nID nao existe!");

    }


//    while((strcmp(vetor[i].id,"NULL")== 0)){
//
//        if(strcmp(vetor[i].id,"NULL")!= 0){
//            printf("\nID paragem: %s",vetor[i].id);
//            //função elimina
//            printf("\nVou eliminar a paragem com o ID %s ",vetor[i].id);
//            strcpy(vetor[i].nome, "NULL");
//            strcpy(vetor[i].id, "NULL");
//            vetor[i].associada=0;
//
//        }else{
//            if(strcmp(vetor[i].id,ideliminar)==0 && vetor[i].associada != 0)
//           i++;
//        }
//    }

}














