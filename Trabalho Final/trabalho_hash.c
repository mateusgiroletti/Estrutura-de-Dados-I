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
void removeListaElementos(Lista*, char*);
void buscaElementos(Lista*, char*);
int hash(char*);

//Função para ordenar A-Z
void ordenaQuickSort(Lista*, Elemento*, Elemento*);

// Função que inicia o programa
int main(){
    int op;
    int i;
    Lista* listaChaves = criaListaChaves();

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

    do{ 
        printf("\n####MENU####\n\n");
        printf("1 - Inserir os dados do arquivo nomes\n");
        printf("2 - Buscar um elemento\n");
        printf("3 - Quantidade de elementos por chaves\n");
        printf("4 - Remover um elemento\n");
        printf("5 - Ordenar elementos via quick sort\n");
        printf("6 - Fechar programa\n");
        scanf("%i",&op);

        if(op == 6){
            break;
        }else if(op == 1){
            printf("Inserindo chaves\n");

            for(i=0; i<=9; i++){
                insereListaChave(listaChaves, i, listaChaves->tailListaChave);
            }
            printf("Adicionando elementos a lista de elementos\n");

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

        }else if(op == 2){
            char elementoBuscar[50];
            printf("Digite o nome a ser procurado: \n");
            scanf("%s", elementoBuscar);
            int h = hash(elementoBuscar);

            switch (h){
            case 0:
                buscaElementos(listaElementos0, elementoBuscar);
                break;
            case 1:
                buscaElementos(listaElementos1, elementoBuscar);
                break;
            case 2:
                buscaElementos(listaElementos2, elementoBuscar);
                break;
            case 3:
                buscaElementos(listaElementos3, elementoBuscar);
                break;
            case 4:
                buscaElementos(listaElementos4, elementoBuscar);
                break;
            case 5:
                buscaElementos(listaElementos5, elementoBuscar);
                break;
            case 6:
                buscaElementos(listaElementos6, elementoBuscar);
                break;
            case 7:
                buscaElementos(listaElementos7, elementoBuscar);
                break;
            case 8:
                buscaElementos(listaElementos8, elementoBuscar);
                break;
            case 9:
                buscaElementos(listaElementos9, elementoBuscar);
                break;

            default:
                break;
            }
        }else if(op == 3){
            printf("tamanho da chave 0: %d\n", listaElementos0->tamanho);
            printf("tamanho da chave 1: %d\n", listaElementos1->tamanho);
            printf("tamanho da chave 2: %d\n", listaElementos2->tamanho);
            printf("tamanho da chave 3: %d\n", listaElementos3->tamanho);
            printf("tamanho da chave 4: %d\n", listaElementos4->tamanho);
            printf("tamanho da chave 5: %d\n", listaElementos5->tamanho);
            printf("tamanho da chave 6: %d\n", listaElementos6->tamanho);
            printf("tamanho da chave 7: %d\n", listaElementos7->tamanho);
            printf("tamanho da chave 8: %d\n", listaElementos8->tamanho);
            printf("tamanho da chave 9: %d\n", listaElementos9->tamanho);
        }else if(op == 4){
            char elementoRemover[50];
            printf("Digite o nome a ser removido: \n");
            scanf("%s", elementoRemover);
            
            int hRemover = hash(elementoRemover);

            switch (hRemover){
            case 0:
                removeListaElementos(listaElementos0, elementoRemover);
                break;
            case 1:
                removeListaElementos(listaElementos1, elementoRemover);
                break;
            case 2:
                removeListaElementos(listaElementos2, elementoRemover);
                break;
            case 3:
                removeListaElementos(listaElementos3, elementoRemover);
                break;
            case 4:
                removeListaElementos(listaElementos4, elementoRemover);
                break;
            case 5:
                removeListaElementos(listaElementos5, elementoRemover);
                break;
            case 6:
                removeListaElementos(listaElementos6, elementoRemover);
                break;
            case 7:
                removeListaElementos(listaElementos7, elementoRemover);
                break;
            case 8:
                removeListaElementos(listaElementos8, elementoRemover);
                break;
            case 9:
                removeListaElementos(listaElementos9, elementoRemover);
                break;

            default:
                break;
            }   

        }else if(op == 5){
            printf("Antes de ordenar\n");
            escreveListaElementos(listaElementos7);

            ordenaQuickSort(listaElementos7, listaElementos7->headListaElementos, listaElementos7->tailListaElementos);

            printf("Depois de ordenar\n");
            escreveListaElementos(listaElementos7);
    
        }
    }while (op != 6);

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
        printf("ID: %i tamanho: \n", pointer->id);
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
        printf("%s", pointer->dado);
        pointer = pointer->nextElemento;
    }
    //printf("");
}

void buscaElementos(Lista* listaElementos, char* nome){
    int tamanhoString;

    Elemento* pointer = listaElementos->headListaElementos;

    tamanhoString = strlen(nome);
    while(pointer != NULL){
        if(strncmp(pointer->dado, nome, tamanhoString)){
            pointer = pointer->nextElemento;
        }else{
            break;
        }
    }

    if(pointer == NULL){
        printf("Elemento nao esta na lista\n");
    }else{
        printf("Elemento %s Esta na chave %d \n", nome, pointer->chave->id);
    }
}

void removeListaElementos(Lista* listaElemento, char* nome){
    int tamanhoString;
    Elemento* elemento = listaElemento->headListaElementos;

    tamanhoString = strlen(nome);
    
    if(listaElemento->tamanho == 0){
        printf("Essa lista esta vazia!\n");
    }else{
        buscaElementos(listaElemento, nome);
        while(elemento != NULL){
            if(strncmp(elemento->dado, nome, tamanhoString)){
                elemento = elemento->nextElemento;
            }else{
                if(elemento == listaElemento->headListaElementos){
                    listaElemento->headListaElementos = elemento->nextElemento;
                    if(listaElemento->headListaElementos == NULL){
                        listaElemento->tailListaElementos = NULL;
                    }else{
                        elemento->nextElemento->prevElemento = NULL;
                    }
                }else{
                    elemento->prevElemento->nextElemento = elemento->nextElemento;
                    if(elemento->nextElemento == NULL){
                        listaElemento->tailListaElementos = elemento->prevElemento;
                    }else{
                        elemento->nextElemento->prevElemento = elemento->prevElemento;
                    }
                }
                printf("Elemento com nome: %s foi removido da chave: %d \n", nome, elemento->chave->id);
                free(elemento);
                listaElemento->tamanho--;
            }
        }
    }
}

void ordenaQuickSort(Lista* listaElemento, Elemento* inicio, Elemento* final){
    int pivo, meio;
    Elemento* esq = inicio;
    Elemento* dir = final;
    Elemento* aux;
    Elemento* aux2;

    meio = (int) (listaElemento->tamanho / 2);

    Elemento* pointer = listaElemento->headListaElementos;

    for (int i = 0; i < meio; i++){
        pointer = pointer->nextElemento;
    }

    while (strcmp(dir->dado, esq->dado) > 0){
        while(strcmp(esq->dado, pointer->dado) < 0){
            esq = esq->nextElemento;
        }

        while(strcmp(dir->dado, pointer->dado) > 0){
            dir = dir->prevElemento;
        }

        if(strcmp(esq->dado, dir->dado) <= 0){
            aux = esq;
            aux2 = esq;
            
            if(aux == listaElemento->headListaElementos){
                listaElemento->headListaElementos = esq->nextElemento = aux2;
            }else{
                esq->nextElemento = aux2;
            }
            if(aux2 == listaElemento->tailListaElementos){
                listaElemento->tailListaElementos = dir->prevElemento = aux;
            }else{
                dir->prevElemento = aux;
            }

            esq = esq->nextElemento;
            dir = dir->prevElemento;
        }
    }    

    if(strcmp(inicio->dado, dir->dado) < 0){
        ordenaQuickSort(listaElemento, inicio, dir);
    }

    if(strcmp(esq->dado, final->dado) < 0){
        ordenaQuickSort(listaElemento, final, esq);
    }
}