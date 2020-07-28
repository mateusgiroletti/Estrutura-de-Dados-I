#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct sElemento{
    char dado[25];
    struct sElemento *nextElemento;
    struct sElemento *prevElemento;
} Elemento;

typedef struct sListaElementos{
    int tamanho;
    struct sElemento *headListaElementos;
    struct sElemento *tailListaElementos;
} ListaElementos;

typedef struct sChave{
    int id;
    struct sChave *nextChave;
    struct sChave *prevChave;

    struct sListaElementos *headListaElementos;

} Chave;

typedef struct sListaChaves{
    int tamanho;
    struct sChave *headListaChave;
    struct sChave *tailListaChave;

} ListaChaves;

// Funções para a lista de chaves
ListaChaves* criaListaChaves();
Chave* criaChave(int);
void insereListaChave(ListaChaves*, int, Chave*);
void escreveListaChave(ListaChaves*);

// Funções para a lista de elementos
ListaElementos* criaListaElementos();
Elemento* criaElemento(char*);
bool listaElementosEstaVazia(ListaElementos*);
void insereListaElementos(ListaElementos*, char*, Elemento*);
void escreveListaElementos(ListaElementos*);
void removeListaElementos(ListaElementos*, Elemento*);
void buscaListaElementos(ListaElementos*);


// Função que inicia o programa
int main(){
    int i;
    ListaChaves* listaChaves = criaListaChaves();

    printf("Inserindo dados\n");

    for(i=0; i<=10; i++){
        insereListaChave(listaChaves, i, listaChaves->tailListaChave);
    }
    
    printf("Imprimindo lista de chaves\n");
    escreveListaChave(listaChaves);
    return 0;
}

// Funções para a lista de chaves

ListaChaves* criaListaChaves(){
    ListaChaves* listaChaves = (ListaChaves*)malloc(sizeof(ListaChaves));

    listaChaves->tamanho = 0;
    listaChaves->headListaChave = NULL;
    listaChaves->tailListaChave = NULL;

    return listaChaves;
}

Chave* criaChave(int id){
    Chave* chave = (Chave*) malloc(sizeof(Chave));
    chave->id = id;
    chave->nextChave = NULL;
    chave->nextChave = chave->prevChave = NULL;

    chave->headListaElementos = NULL;

    return chave;
}

void insereListaChave(ListaChaves* listaChaves, int id, Chave* chavePivo){
    Chave* novaChave = criaChave(id); 
    if(listaChaves->tamanho == 0){
        listaChaves->headListaChave = novaChave;
        listaChaves->tailListaChave = novaChave;
    }else{
        novaChave->nextChave = chavePivo->nextChave;
        novaChave->prevChave = chavePivo;

        if(chavePivo->nextChave == NULL){
            listaChaves->tailListaChave = novaChave;
        }else{
            chavePivo->nextChave->prevChave = novaChave;
        }

        chavePivo->nextChave = novaChave;
    }

    listaChaves->tamanho++;
    
}

void escreveListaChave(ListaChaves* listaChave){
   if(listaChave->tamanho == 0){
        printf("Lista de chaves esta vazia\n");
        return;
    }

    Chave* pointer = listaChave->headListaChave;
    while (pointer!=NULL)
    {
        printf("%i \n", pointer->id);
        pointer = pointer->nextChave;
    }
    printf("NUUL \n");
    
}


// Funções para a lista de elementos

