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
Chave* criaChave();
void insereListaChave(ListaChaves*);
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

Chave* criaChave(){
    Chave* chave = (Chave*) malloc(sizeof(Chave));
    chave->id = 0;
    chave->nextChave = NULL;
    chave->nextChave = chave->prevChave = NULL;

    chave->headListaElementos = NULL;

    return chave;
}

void insereListaChave(ListaChaves* listaChaves){
    Chave* novaChave = criaChave(); 
    if(listaChaves->tamanho==0){
        listaChaves->headListaChave = novaChave;
        listaChaves->tailListaChave = novaChave;
    }
    
    
}



// Funções para a lista de elementos
Lista* criaLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    lista->tamanho = 0;
    lista->head = NULL;
    lista->tail = NULL;

    return lista;
}

Elemento* criaElemento(char* dado){
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    strcpy(elemento->dado, dado);
    elemento->next = NULL;
    elemento->next = elemento->prev =NULL;
    
    return elemento;
}


bool listaEstaVazia(Lista* lista){
    return (lista->tamanho == 0);
}

void escreveLista(Lista* lista){
   if(listaEstaVazia(lista)){
        printf("Lista vazia\n");
        return;
    }

    Elemento* pointer = lista->head;

    printf("->");
    while (pointer!=NULL)
    {
        printf("%s -> ", pointer->dado);
        pointer = pointer->next;
    }
    printf("NUUL \n");
    
}

void insereLista(Lista* lista, char* dado, Elemento* elementoPivo){
    Elemento* novo_elemento = criaElemento(dado);    
    strcpy(novo_elemento->dado, dado);   

    if((elementoPivo == NULL) && !listaEstaVazia(lista)){
        printf("So eh aceito pivo nulo na insercao do primeiro elemento");
    }

    if(listaEstaVazia(lista)){
        lista->head = novo_elemento;
        lista->tail = novo_elemento;
    }else{
        novo_elemento->next = elementoPivo->next;
        novo_elemento->prev = elementoPivo;

        if(elementoPivo->next == NULL){
            lista->tail = novo_elemento;
        }else{
            elementoPivo->next->prev = novo_elemento;
        }

        elementoPivo->next = novo_elemento;
    }

    lista->tamanho++;

}

void removeLista(Lista* lista, Elemento* elemento){
    if((elemento != NULL) && (!listaEstaVazia(lista))){
        if(elemento==lista->head){
            lista->head = elemento->next;
            if(lista->head == NULL){
                lista->tail = NULL;
            }else{
                elemento->next->prev = NULL;
            }
        }else{
            elemento->prev->next = elemento->next;
            if(elemento->next == NULL){
                lista->tail = elemento->prev;
            }else{
                elemento->next->prev = elemento->prev;
            }
        }
        
        free(elemento);
        lista->tamanho--;
    }
    
}

void buscaLista(Lista* lista){
    char elemento[25];
    printf("Digite o elemento a ser procurado: \n");
    scanf("%c", elemento);
    
    //percore cabeca-cauda
   Elemento* pointer = lista->head;

    while(pointer!=NULL && pointer->dado != elemento){
         pointer = pointer->next;
    }
    
    //percore cauda-cabeca
    /*
    Elemento* pointer = lista->tail;
    while(pointer!=NULL && pointer->dado != elemento){
         pointer = pointer->prev;
    }
    */
    if(pointer==NULL){
        printf("Elemento nao esta na lista\n");
    }else{
        printf("Elemento encontrado: %s\n", pointer->dado);
    }
}

