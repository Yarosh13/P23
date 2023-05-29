//
// Created by Yaroslav Mulyk - 2021133850
//

#ifndef UNTITLED3_HEADER_H
#define UNTITLED3_HEADER_H


    typedef struct paragem Paragem;
    struct paragem{
        char id[5]; // único
        char nome[64];
        int associada;
    };

    typedef struct linha Linha, *pLinha;
    struct linha{
        char nome[64];
        Paragem **parag;
        int numParagens;
        pLinha prox;
    };

// Funções do ficheiro "funcoes.c"
void intro();
void autor();
int menu();

// Funções do ficheiro "paragens.c"
int menu_paragem(Paragem* vetorParagens, int size);
int menu1();

int inicializarParagem(Paragem* vetor, int size);
int AdicionarParagem(Paragem* vetor, int size);

int GeraID(Paragem* vetor,int pos, int size);
int MostrarParagens(Paragem* vetor, int size);
int EliminaParagem(Paragem* vetor, int size);


// Funções do ficheiro "linhas.c"
pLinha menu_linhas(pLinha linhaComboio, Paragem* vetorParagens);
int menu2( );

int lista_vazia(pLinha p);
void preenche_linha(pLinha l);
pLinha insere_final(pLinha l);
pLinha insere_inicio(pLinha l);
void mostra_linhas(pLinha l);

pLinha associaParagem(pLinha l,Paragem* vetorParagens);
void MostraLinhasParagens(pLinha l);



#endif //UNTITLED3_HEADER_H
