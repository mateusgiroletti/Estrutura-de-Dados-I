#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct sElemento
{
    char dado[25];
    struct sElemento *next;
    struct sElemento *prev;
} Elemento;

typedef struct sLista
{
    int tamanho;
    struct sElemento *head;
    struct sElemento *tail;
} Lista;

Lista* criaLista();
Elemento* criaElemento(char*);
bool listaEstaVazia(Lista*);
void insereLista(Lista*, char*, Elemento*);
void escreveLista(Lista*);
void removeLista(Lista*, Elemento*);
void buscaLista(Lista*);

//funcao para criar a lista
Lista* criaLista()
{
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    lista->tamanho = 0;
    lista->head = NULL;
    lista->tail = NULL;

    return lista;
}

Elemento* criaElemento(char* dado)
{
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

int main()
{
    Lista* lista = criaLista();
    printf("Inserindo dados\n");
    insereLista(lista, "teste", NULL);
    insereLista(lista, "teste2", lista->tail);
    insereLista(lista, "teste3", lista->head);
    escreveLista(lista);
    
    printf("Removendo dados\n");
   
    removeLista(lista, lista->tail);
    removeLista(lista, lista->tail);


    escreveLista(lista);

    //buscaLista(lista);

    return 0;
}