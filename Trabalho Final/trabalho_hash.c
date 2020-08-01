#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct sElemento{
    char dado[25];
    struct sElemento *nextElemento;
    struct sElemento *prevElemento;

    struct sChave *chave;
} Elemento;

typedef struct sLista{
    int tamanho;
    struct sElemento *headListaElementos;
    struct sElemento *tailListaElementos;

    struct sChave *headListaChave;
    struct sChave *tailListaChave;
} Lista;

typedef struct sChave{
    int id;
    struct sChave *nextChave;
    struct sChave *prevChave;

    struct sLista *headListaElementos;
} Chave;

Lista* criaLista();

// Funções para a lista de chaves
Chave* criaChave(int);
void insereListaChave(Lista*, int, Chave*);
void escreveListaChave(Lista*);

// Funções para a lista de elementos
Elemento* criaElemento(char*);
void insereListaElementos(Lista*, char*, Elemento*, Lista*);
void escreveListaElementos(Lista*);
void removeListaElementos(Lista*, Elemento*);
void buscaListaElementos(Lista*);
int hash(char*);

// Função que inicia o programa
int main(){
    int i;
    Lista* listaChaves = criaLista();

    printf("Inserindo dados\n");

    for(i=0; i<=9; i++){
        insereListaChave(listaChaves, i, listaChaves->tailListaChave);
    }
    
    printf("Imprimindo lista de chaves\n");
    escreveListaChave(listaChaves);

    printf("Adicionando elementos a lista de elementos\n");

    Lista* listaElementos = criaLista();

    FILE *file = fopen("nomes.txt", "r");

    char nome[50];

    while(fgets(nome, 50, file)){
        insereListaElementos(listaElementos, nome, listaElementos->tailListaElementos, listaChaves);
    }
    
    fclose(file);

    escreveListaElementos(listaElementos);
    
    Elemento* pointer = listaElementos->headListaElementos;  

    printf("head lista %s", pointer->dado);

    int retorno = strcmp(pointer->dado, "MIQUAELI");

    printf("retorno %d", retorno);

    while(pointer != NULL && retorno != 0){
        pointer = pointer->nextElemento;
    }

    if(retorno == 0){
        printf("Nome %s esta na chave %d \n", pointer->dado, pointer->chave->id);
    }else{
        printf("erro no print!\n");
    }

    

    return 0;
}

// Funções para a lista de chaves

Lista* criaLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    lista->tamanho = 0;
    lista->headListaChave = NULL;
    lista->tailListaChave = NULL;

    lista->headListaElementos = NULL;
    lista->tailListaElementos = NULL;

    return lista;
}

Chave* criaChave(int id){
    Chave* chave = (Chave*) malloc(sizeof(Chave));
    chave->id = id;
    chave->nextChave = NULL;
    chave->nextChave = chave->prevChave = NULL;

    return chave;
}

void insereListaChave(Lista* listaChaves, int id, Chave* chavePivo){
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

void escreveListaChave(Lista* listaChave){
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

Elemento* criaElemento(char* nome){
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    strcpy(elemento->dado, nome);
    
    elemento->nextElemento = NULL;
    elemento->nextElemento = elemento->prevElemento = NULL;

    elemento->chave = NULL;

    return elemento;
}

int hash(char* nome){
    int i, key = 0;
    char primeiraLetra;

    for(i = 0; i < 25; i++){
       primeiraLetra = nome[0];
    }

    switch (primeiraLetra){
    case 'A':
        key = 65; 
        break;
    case 'B':
        key = 66; 
        break;
    case 'C':
        key = 67; 
        break;
    case 'D':
        key = 68; 
        break;
    case 'E':
        key = 69; 
        break;
    case 'F':
        key = 70; 
        break;
    case 'G':
        key = 71; 
        break;
    case 'H':
        key = 72; 
        break;
    case 'I':
        key = 73; 
        break;
    case 'J':
        key = 74; 
        break;
    case 'K':
        key = 75; 
        break;
    case 'L':
        key = 76; 
        break;
    case 'M':
        key = 77; 
        break;
    case 'N':
        key = 78; 
        break;
    case 'O':
        key = 79; 
        break;
    case 'P':
        key = 80; 
        break;        
    case 'Q':
        key = 81; 
        break;
    case 'R':
        key = 82; 
        break;
    case 'S':
        key = 83; 
        break;
    case 'T':
        key = 84; 
        break;
    case 'U':
        key = 85; 
        break;
    case 'V':
        key = 86; 
        break;
    case 'W':
        key = 87; 
        break;
    case 'X':
        key = 88; 
        break;
    case 'Y':
        key = 89; 
        break;
    case 'Z':
        key = 90; 
        break;                    
    default:
        break;
    }

    return key % 10;
}

void insereListaElementos(Lista* listaElementos, char* nome, Elemento* elementoPivo, Lista* listaChaves){
    int h;
    Elemento* novoElemento = criaElemento(nome);    
    strcpy(novoElemento->dado, nome);
    
    h = hash(nome);

    if(listaElementos->tamanho == 0){
        listaElementos->headListaElementos = novoElemento;
        listaElementos->tailListaElementos = novoElemento;
    }else{
        novoElemento->nextElemento = elementoPivo->nextElemento;
        novoElemento->prevElemento = elementoPivo;

        if(elementoPivo->nextElemento == NULL){
            listaElementos->tailListaElementos = novoElemento;
        }else{
            elementoPivo->nextElemento->prevElemento = novoElemento;
        }

        elementoPivo->nextElemento = novoElemento;
    }

    listaElementos->tamanho++; 

    Chave* pointer = listaChaves->headListaChave;  

    while(pointer != NULL && pointer->id != h){
        pointer = pointer->nextChave;
    }

    if(pointer->id == h){
        novoElemento->chave = pointer;
    }else{
        printf("erro no insere lista!");
    }
   
}

void escreveListaElementos(Lista* listaElementos){
     if(listaElementos->tamanho == 0){
        printf("Lista de elementos vazia\n");
        return;
    }

    Elemento* pointer = listaElementos->headListaElementos;

    while (pointer!=NULL){
        printf("\n%s  ", pointer->dado);
        pointer = pointer->nextElemento;
    }
    printf("\n");
}