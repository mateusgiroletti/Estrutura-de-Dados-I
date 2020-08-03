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

    struct sElemento *headListaElementos;

} Chave;



// Funções para a lista de chaves
Lista* criaListaChaves();
Chave* criaChave(int);
void insereListaChave(Lista*, int, Chave*);
void escreveListaChave(Lista*);

// Funções para a lista de elementos
Elemento* criaElemento(char*);
Lista* criaListaElementos();
void insereListaElementos(Lista*, char*, Elemento*, Lista*);
void escreveListaElementos(Lista*);
void removeListaElementos(Lista*, Elemento*);
void buscaListaElementos(Lista*);
int hash(char*);

// Função que inicia o programa
int main(){
    int i;
    Lista* listaChaves = criaListaChaves();

    printf("Inserindo dados\n");

    for(i=0; i<=9; i++){
        insereListaChave(listaChaves, i, listaChaves->tailListaChave);
    }
    
    printf("Imprimindo lista de chaves\n");
    escreveListaChave(listaChaves);

    printf("Adicionando elementos a lista de elementos\n");

    Lista* listaElementos0 = criaListaElementos();
    Lista* listaElementos1 = criaListaElementos();
    Lista* listaElementos2 = criaListaElementos();
    Lista* listaElementos3 = criaListaElementos();
    Lista* listaElementos4 = criaListaElementos();
    Lista* listaElementos5 = criaListaElementos();
    Lista* listaElementos6 = criaListaElementos();
    Lista* listaElementos7 = criaListaElementos();
    Lista* listaElementos8 = criaListaElementos();
    Lista* listaElementos9 = criaListaElementos();


    FILE *file = fopen("nomes.txt", "r");

    char nome[50];

    while(fgets(nome, 50, file)){
        int h = hash(nome);

        switch (h){
        case 0:
            insereListaElementos(listaElementos0, nome, listaElementos0->tailListaElementos, listaChaves);
            break;
        case 1:
            insereListaElementos(listaElementos1, nome, listaElementos1->tailListaElementos, listaChaves);       
            break;
        case 2:
            insereListaElementos(listaElementos2, nome, listaElementos2->tailListaElementos, listaChaves);       
            break;
        case 3:
            insereListaElementos(listaElementos3, nome, listaElementos3->tailListaElementos, listaChaves);       
            break;
        case 4:
            insereListaElementos(listaElementos4, nome, listaElementos4->tailListaElementos, listaChaves);       
            break;
        case 5:
            insereListaElementos(listaElementos5, nome, listaElementos5->tailListaElementos, listaChaves);       
            break;
        case 6:
            insereListaElementos(listaElementos6, nome, listaElementos6->tailListaElementos, listaChaves);       
            break;
        case 7:
            insereListaElementos(listaElementos7, nome, listaElementos7->tailListaElementos, listaChaves);       
            break;
        case 8:
            insereListaElementos(listaElementos8, nome, listaElementos8->tailListaElementos, listaChaves);       
            break;
        case 9:
            insereListaElementos(listaElementos9, nome, listaElementos9->tailListaElementos, listaChaves);       
            break;                    
        default:
            break;
        }

    }
    
    fclose(file);

    escreveListaElementos(listaElementos0);
    printf("tamanho da lista 0: %d\n", listaElementos0->tamanho);
    printf("tamanho da lista 1: %d\n", listaElementos1->tamanho);
    printf("tamanho da lista 2: %d\n", listaElementos2->tamanho);
    printf("tamanho da lista 3: %d\n", listaElementos3->tamanho);
    printf("tamanho da lista 4: %d\n", listaElementos4->tamanho);
    printf("tamanho da lista 5: %d\n", listaElementos5->tamanho);
    printf("tamanho da lista 6: %d\n", listaElementos6->tamanho);
    printf("tamanho da lista 7: %d\n", listaElementos7->tamanho);
    printf("tamanho da lista 8: %d\n", listaElementos8->tamanho);
    printf("tamanho da lista 9: %d\n", listaElementos9->tamanho);

    return 0;
}

// Funções para a lista de chaves

Lista* criaListaChaves(){
    Lista* listaChaves = (Lista*)malloc(sizeof(Lista));

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

Lista* criaListaElementos(){
    Lista* listaElementos = (Lista*)malloc(sizeof(Lista));

    listaElementos->tamanho = 0;
    listaElementos->headListaElementos = NULL;
    listaElementos->headListaElementos = NULL;

    return listaElementos;

}

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

    Chave* pointer = listaChaves->headListaChave;  

    while(pointer != NULL && pointer->id != h){
        pointer = pointer->nextChave;
    }

    if(pointer->id == h){
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

        novoElemento->chave = pointer;
        pointer->headListaElementos = listaElementos->headListaElementos;
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