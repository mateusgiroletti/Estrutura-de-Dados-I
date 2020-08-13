#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct sElemento{
    char dado;
    struct sElemento *next;
    struct sElemento *prev;

} Elemento;

typedef struct sPilha{
    int tamanho;
    struct sElemento *head;
    struct sElemento *tail;
} Pilha;

Pilha* criaPilha();
Elemento* criaElemento();
void validaExpressao(Pilha*);
void push(Pilha*, Elemento*);
char pop(Pilha*, char);
void limpaVetor(char []);
char tipoSimbolo(char);
void limpaPilha(Pilha*);
void escrevePilha(Pilha*);

int main(){ 
    int op;

    while (op != 0){
        Pilha* pilha = criaPilha();
        validaExpressao(pilha);
        limpaPilha(pilha);
        escrevePilha(pilha);
        printf("Digite 0 para encerrar ou 1 para continuar:\n");
        scanf("%d", &op);
    }

    return 0;
}

Pilha* criaPilha(){
    Pilha* pilha = malloc(sizeof (Pilha));
    pilha->head = NULL;
    pilha->tail = NULL;
    pilha->tamanho = 0;

    return pilha;
}

Elemento* criaElemento(){
    Elemento* elemento = malloc(sizeof(Elemento));
    elemento->next = NULL;
    elemento->prev = NULL;
    elemento->dado = ' ';

    return elemento;
}

void limpaVetor(char vetor[]){
    int i;
    for (i = 0; i < 25; i++){
        vetor[i] = ' ';
    }
}

void validaExpressao(Pilha* pilha){
    char expressao[25];
    limpaVetor(expressao);
    char deletar;

    printf("Digite a expressao matematica: ");
    scanf(" %[^\n]", expressao);

    int i;
    char tipo;
    for (i = 0; i < 25; i++){
        if(expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{'){
            Elemento* novoElemento = criaElemento();
            novoElemento->dado = expressao[i];
            push(pilha, novoElemento);
        }
        if(expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}'){
            tipo = tipoSimbolo(expressao[i]);
            deletar = pop(pilha, tipo);
            deletar == ' ' ? i = 25 : 0;
        }
    }
    if(pilha->tamanho == 0 && deletar != ' '){
        printf("Expressao valida\n");
    }else{
        printf("Expressao Invalida\n");
    }
}

void push(Pilha* pilha, Elemento* novoElemento){
    Elemento* pivo = pilha->tail;
    if (pilha->tamanho == 0) {
        pilha->head = novoElemento;
        pilha->tail = novoElemento;
    } else {
        novoElemento->next =  pivo->next;
        novoElemento->prev = pivo;

        pilha->tail = novoElemento;
        pivo->next = novoElemento;
    }
    pilha->tamanho++;
}

char pop(Pilha* pilha, char tipo){
    if(pilha->tamanho > 0 && pilha->tail->dado == tipo){
        Elemento* deletar = pilha->tail;
        char dado = pilha->tail->dado;

        if(deletar == pilha->head){
            pilha->head = deletar->next;
            if(pilha->head == NULL){
                pilha->tail = NULL;
            }else{
                deletar->next->prev = NULL;
            }
        }else{
            deletar->prev->next = deletar->next;
            if (deletar->next == NULL) {
                pilha->tail = deletar->prev;
            } else {
                deletar->next->prev = deletar->prev;
            }
        }
        free(deletar);
        deletar = NULL;
        pilha->tamanho--;
        return dado;
    }
    return ' ';
}

void limpaPilha(Pilha* pilha){
    char deletar;

    char tipo = pilha->tail == NULL ? ' ' : pilha->tail->dado;


    if(pilha->tamanho > 0){
        while(pilha->tamanho > 0){
            deletar = pop(pilha, tipo);
            printf("elemento %c foi retirado\n",deletar);
            tipo = pilha->tail == NULL ? ' ' : pilha->tail->dado;
        }
        printf("Tamanho final: %d\n",pilha->tamanho);
        free(pilha);
        pilha = NULL;
    }
}

void escrevePilha(Pilha* pilha){
    Elemento *elemento = pilha->head;

    if (pilha->tamanho > 0) {
        while (elemento != NULL) {
            printf("%c\n", elemento->dado);
            elemento = elemento->next;
        }

    } else {
        printf("Pilha vazia\n");
    }
}

char tipoSimbolo(char simbolo){
    char tipo;
    if (simbolo == ')') {
        tipo = '(';
    } else if (simbolo == ']') {
        tipo = '[';
    } else {
        tipo = '{';
    }
    return tipo;
}