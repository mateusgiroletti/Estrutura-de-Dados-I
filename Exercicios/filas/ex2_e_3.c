#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sElemento{
    int dado;
    struct sElemento *next;
    struct sElemento *prev;

} Elemento;

typedef struct sFila{
    int tamanho;
    struct sElemento *front;
    struct sElemento *rear;
} Fila;

Fila* criaFila();
Elemento* criaElemento(int);
bool filaEstaVazia(Fila*);
void insereFila(Fila*, int, Elemento*);
void escreveFila(Fila*);
int removeFila(Fila*, Elemento*);
void removeMinFila(Fila*);


Fila* criaFila(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));

    fila->tamanho = 0;
    fila->front = NULL;
    fila->rear = NULL;

    return fila;
}

Elemento* criaElemento(int dado){
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    elemento->dado = dado;
    elemento->next = NULL;
    elemento->next = elemento->prev =NULL;
  
    return elemento;
}

bool filaEstaVazia(Fila* fila){
    return (fila->tamanho == 0);
}


void escreveFila(Fila* fila){
    if(filaEstaVazia(fila)){
        printf("Fila esta vazia!\n");
        return;
    }

    Elemento* pointer = fila->front;

    printf("->");
    while (pointer!=NULL){
        printf("%i -> ", pointer->dado);
        pointer = pointer->next;
    }
    printf("NUUL \n");
    
}

void insereFila(Fila* fila, int dado, Elemento* elementoPivo){
    Elemento* novo_elemento = criaElemento(dado);    
    novo_elemento->dado = dado;

    if((elementoPivo == NULL) && !filaEstaVazia(fila)){
        printf("So eh aceito pivo nulo na insercao do primeiro elemento");
    }

    if(filaEstaVazia(fila)){
        fila->front = novo_elemento;
        fila->rear = novo_elemento;
    }else{
        novo_elemento->next = elementoPivo->next;
        novo_elemento->prev = elementoPivo;

        if(elementoPivo->next == NULL){
            fila->rear = novo_elemento;
        }else{
            elementoPivo->next->prev = novo_elemento;
        }

        elementoPivo->next = novo_elemento;
    }

    fila->tamanho++;
}

int removeFila(Fila* fila, Elemento* elemento){
     if((elemento != NULL) && (!filaEstaVazia(fila))){
        if(elemento==fila->front){
            fila->front = elemento->next;
            if(fila->front == NULL){
                fila->rear = NULL;
            }else{
                elemento->next->prev = NULL;
            }
        }else{
            elemento->prev->next = elemento->next;
            if(elemento->next == NULL){
                fila->rear = elemento->prev;
            }else{
                elemento->next->prev = elemento->prev;
            }
        }
        
        free(elemento);
        fila->tamanho--;
    }
}

void removeMinFila(Fila* fila){
    Elemento *elemento, *min;
    min = fila->front;

    elemento = fila->front;
    while(elemento != NULL){
        if(elemento->dado < min->dado){
            min = elemento;
        }
        elemento = elemento->next;
    }

    printf("O menor elemento é %i ele esta sendo removido...\n", min->dado);
    removeFila(fila, min);

}

int main(){
    Fila* fila = criaFila();
    printf("Inserindo dados\n");
    insereFila(fila, 15, fila->rear);
    insereFila(fila, 30, fila->rear);
    insereFila(fila, 5, fila->rear);
    insereFila(fila, 3, fila->rear);
    insereFila(fila, 55, fila->rear);

    escreveFila(fila);

    printf("Removendo dados %d\n", fila->tamanho );

    removeMinFila(fila);
    escreveFila(fila); 
    removeMinFila(fila);
    escreveFila(fila); 
    removeMinFila(fila);
    escreveFila(fila); 
    removeMinFila(fila);
    escreveFila(fila); 
    removeMinFila(fila);
    escreveFila(fila); 
    
    
    
    return 0;
}

