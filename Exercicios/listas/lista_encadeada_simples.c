#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sElemento
{
    int dado;
    struct sElemento *next;
} Elemento;

typedef struct sLista
{
    int tamanho;
    struct sElemento *head;
    struct sElemento *tail;
} Lista;

Lista* criaLista();
Elemento* criaElemento(int);
bool listaEstaVazia(Lista*);
void insereLista(Lista*, int, Elemento*);
void escreveLista(Lista*);
int removeLista(Lista*, Elemento*);
void buscaLista(Lista*);
void destroiLista(Lista* lista);

Lista* criaLista()
{
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    lista->tamanho = 0;
    lista->head = NULL;
    lista->tail = NULL;

    return lista;
}

Elemento* criaElemento(int dado)
{
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    elemento->dado = dado;
    elemento->next = NULL;
    
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
        printf("%i -> ", pointer->dado);
        pointer = pointer->next;
    }
    printf("NUUL \n");
    
}

void insereLista(Lista* lista, int dado, Elemento* elementoPivo){
    Elemento* novo_elemento = criaElemento(dado);    
    novo_elemento->dado = dado;

    if(elementoPivo == NULL){
        if(lista->tamanho == 0){
            lista->tail = novo_elemento;
        }
        
        novo_elemento->next = lista->head;
        lista->head = novo_elemento;
    }else{
        if(elementoPivo->next == NULL){
            lista->tail = novo_elemento;
        }
            novo_elemento->next = elementoPivo->next;
            elementoPivo->next = novo_elemento; 
    }
    lista->tamanho++;
}

int removeLista(Lista* lista, Elemento* elementoPivo){
    int dado_removido;
    Elemento* elemento_antigo;

    if(listaEstaVazia(lista)){
        return printf("Lista vazia\n");
    }

    if(elementoPivo == NULL){
        elemento_antigo = lista->head;
        lista->head = lista->head->next;

        if(lista->head == NULL){
            lista->tail = NULL;
        }
    }else{
        if(elementoPivo->next == NULL){
            return printf("Este eh o fim da lista\n");
        }
        elemento_antigo = elementoPivo->next;
        elementoPivo->next = elementoPivo->next->next;

        if(elementoPivo->next == NULL){
            lista->tail = elementoPivo;
        }
    }

    dado_removido = elemento_antigo->dado;
    free(elemento_antigo);
    lista->tamanho--;

    return dado_removido;
}

void buscaLista(Lista* lista){
    int elemento;
    printf("Digite o elemento a ser procurado: \n");
    scanf("%d", &elemento);
    
    Elemento* pointer = lista->head;

    while(pointer!=NULL && pointer->dado!=elemento){
         pointer = pointer->next;
    }

    if(pointer==NULL){
        printf("Elemento nao esta na lista\n");
    }else{
        printf("Elemento encontrado: %d\n", pointer->dado);
    }
}

void destroiLista(Lista* lista){
    int dado;
    while(!listaEstaVazia(lista)){
        dado = removeLista(lista, NULL);
        printf("Dado excluido: %i - Lista tamanho: %i \n", dado, lista->tamanho);
    }

    free(lista);
}

int main()
{
    Lista* lista = criaLista();
    printf("Inserindo dados\n");
    insereLista(lista, 1, lista->tail);
    insereLista(lista, 2, lista->tail);
    insereLista(lista, 3, lista->tail);
    insereLista(lista, 4, lista->tail);
    insereLista(lista, 5, lista->tail);
    insereLista(lista, 6, lista->tail);
    
    escreveLista(lista);

    printf("Removendo dados\n");
    removeLista(lista, NULL);
    removeLista(lista, lista->tail);

    escreveLista(lista);

    buscaLista(lista);

    destroiLista(lista);

    return 0;
}

