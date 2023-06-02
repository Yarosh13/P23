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
void Intro();
void Autor();
int MenuPrincipal();

// Funções do ficheiro "paragens.c"
int MenuParagem(Paragem* vetorParagens, int size);
int MenuParagens();

int InicializarParagem(Paragem* vetor, int size);
int AdicionarParagem(Paragem* vetor, int size);

int GeraID(Paragem* vetor,int pos, int size);
int MostrarParagens(Paragem* vetor, int size);
int EliminaParagem(Paragem* vetor, int size);


// Funções do ficheiro "linhas.c"
pLinha MenuLinha(pLinha linhaComboio, Paragem* vetorParagens);
int MenuLinhas();

int ListaVazia(pLinha p);
void PreencheLinha(pLinha l);
pLinha InsereFinal(pLinha l);
pLinha InsereInicio(pLinha l);
void MostraLinhas(pLinha l);

pLinha AssociaParagem(pLinha l,Paragem* vetorParagens);
pLinha DesAssociarParagem(pLinha l, Paragem* vetorParagens);
pLinha MudarSequenciaParagens(pLinha l);

void MostraLinhasParagens(pLinha l);



#endif //UNTITLED3_HEADER_H
