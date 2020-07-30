#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sElemento{
    int placa;
    int qntManobra;
    int manobraSaida;
    struct sElemento *next;
} Elemento;

typedef struct sLista{
    int tamanho;
    struct sElemento *head;
    struct sElemento *tail;
} Lista;

Lista* criaLista();
Elemento* criaElemento(int);
bool listaEstaVazia(Lista*);
void insereLista(Lista*, int, Elemento*);
void escreveLista(Lista*);
void removeLista(Lista*, Elemento*);
void buscaLista(Lista*);
void destroiLista(Lista* lista);

Lista* criaLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    lista->tamanho = 0;
    lista->head = NULL;
    lista->tail = NULL;

    return lista;
}

Elemento* criaElemento(int placa){
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    elemento->placa = placa;
    elemento->qntManobra = 0;
    elemento->next = NULL;
    
    return elemento;
}

bool listaEstaVazia(Lista* lista){
    return (lista->tamanho == 0);
}


void escreveLista(Lista* lista){
    if(listaEstaVazia(lista)){
        printf("Estacionamento vazio\n");
        return;
    }

    Elemento* pointer = lista->head;

    printf("\n->");
    while (pointer!=NULL){
        printf("%i -> ", pointer->placa);
        pointer = pointer->next;
    }
        printf("\n");
    
}

void insereLista(Lista* lista, int placa, Elemento* elementoPivo){
    Elemento* novo_elemento = criaElemento(placa);    
    novo_elemento->placa = placa;

    if(lista->tamanho < 10){
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
            printf("\nO carro de placa %i entrou\n", placa);
    }else{
        printf("\nEstacionamento cheio! O carro de placa %i esta aguardando alguem sair\n", placa);
        removeLista(lista, lista->head);
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
            printf("\nO carro de placa %i entrou\n", placa);
    }
}

void removeLista(Lista* lista, Elemento* elemento){
    if((elemento != NULL) && (!listaEstaVazia(lista))){
        if(elemento==lista->head){
            lista->head = elemento->next;
            if(lista->head == NULL){
                lista->tail = NULL;
            }else{
                elemento->next = NULL;
            }
            elemento->qntManobra++;
        }else{
            elemento->next = elemento->next;
            if(elemento->next == NULL){
                lista->tail = elemento;
            }else{
                elemento->next = elemento;
            }
        }
        lista->head->next->qntManobra++;
        printf("\nO veiculo de placa %i saiu com %i deslocamento!\n", elemento->placa, elemento->qntManobra);
        free(elemento);
        lista->tamanho--;
    }
}

void buscaLista(Lista* lista){
    int elemento;
    printf("Digite o elemento a ser procurado: \n");
    scanf("%d", &elemento);
    
    Elemento* pointer = lista->head;

    while(pointer!=NULL && pointer->placa!=elemento){
         pointer = pointer->next;
    }

    if(pointer==NULL){
        printf("Elemento nao esta na lista\n");
    }else{
        printf("Elemento encontrado: %d\n", pointer->placa);
    }
}

int main(){
    Lista* lista = criaLista();

    insereLista(lista, 1010, lista->tail);
    escreveLista(lista);
    insereLista(lista, 2020, lista->tail);
    escreveLista(lista);
    insereLista(lista, 3030, lista->tail);
    escreveLista(lista);
    insereLista(lista, 4040, lista->tail);
    escreveLista(lista);
    insereLista(lista, 5050, lista->tail);
    escreveLista(lista);
    insereLista(lista, 6060, lista->tail);
    escreveLista(lista);
    insereLista(lista, 7070, lista->tail);
    escreveLista(lista);
    insereLista(lista, 8080, lista->tail);
    escreveLista(lista);
    insereLista(lista, 9090, lista->tail);
    escreveLista(lista);
    insereLista(lista, 1110, lista->tail);
    escreveLista(lista);
    insereLista(lista, 20000, lista->tail);
    escreveLista(lista);

    removeLista(lista, lista->head);
    escreveLista(lista);
    removeLista(lista, lista->head);
    escreveLista(lista);
    removeLista(lista, lista->head);
    escreveLista(lista);
    removeLista(lista, lista->head);
    escreveLista(lista);
    
    return 0;
}

