//
// Created by Yaroslav Mulyk - 2021133850
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"

void Intro(){
    printf( "   __  __  __                                        __   __      __   __      \n");
    printf( "| (_  |_  /                                           _)   _)  /   _)   _)     \n");
    printf( "| __) |__ \\__                                        /__  /__ /   /__  __)     \n");
    printf( "                                                                               \n");
    printf( "                                ___  __                                        \n");
    printf( "                                 |  |__)                                       \n");
    printf( "                                 |  |                                          \n");
    printf( "                                                                               \n");
    printf( "\t __   __   __   __   __    _          _    __   _    __\n");
    printf( "\t|__) |__) /  \\ /  _ |__)  /_\\  |\\/|  /_\\  |    /_\\  |  |\n");
    printf( "\t|    |  \\ \\__/ \\__/ |  \\ /   \\ |  | /   \\ |__ /   \\ |__|\n");
    printf( "                                                                               \n");
    printf( "\t\t  Sistema de Mobilidade do Mondego\n");
    printf( "                                                                               \n");
    printf( "                                                                               \n");
    printf( "                \\_/  _   _  _   _ |  _       |\\/|     |    |                   \n");
    printf( "       Autor:    |  (_| |  (_) _) | (_| \\/   |  | |_| | \\/ |(                  \n");
    printf( "                                                        /                      \n");

    printf( "-------------------------------------------------------------------------------\n");
}

void Autor(){
    printf( "                                                                               \n");
    printf( "                \\_/  _   _  _   _ |  _       |\\/|     |    |                   \n");
    printf( "       Autor:    |  (_| |  (_) _) | (_| \\/   |  | |_| | \\/ |(                  \n");
    printf( "                                                        /                      \n");

}

int MenuPrincipal(){
    sleep(0.5);
    printf("\n\t\tMENU\n");
    printf("1- Operacoes com Paragens\n2- Operacoes com Linhas\n3- Calculo de uma viagem\n9-Autor\n0- Sair\n");

}