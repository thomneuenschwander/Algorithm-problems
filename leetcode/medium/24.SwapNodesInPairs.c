#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct Celula {
    struct Celula* prox;
    int elemento;
}Celula;

Celula* criarCelula(int x){
    Celula* new = malloc(sizeof(Celula));
    new->prox = NULL;
    new->elemento = x;
    return new;
}

// ------------------------- LINKED LIST -----------------------------------------------------

typedef struct LinkedList{
    struct Celula* primeiro, *ultimo;
    int tamanho;
}LinkedList;

LinkedList* criarLista(){
    LinkedList* new = malloc(sizeof(LinkedList));
    new->primeiro = criarCelula(0);
    new->ultimo = new->primeiro;
    new->tamanho = 0;
    return new;
}

void mostrar(LinkedList* lista){
    Celula* i = lista->primeiro->prox;
    while (i != NULL)
    {
        printf("%d ", i->elemento);
        i = i->prox;
    }
    printf("\n");
}

void inserirFim(LinkedList* lista, int x){
    lista->ultimo->prox = criarCelula(x);
    lista->ultimo = lista->ultimo->prox;
    lista->tamanho++;
}

int removerFim(LinkedList* lista){
    int resp = lista->ultimo->elemento;
    Celula* j = lista->primeiro;
    for(int i = 0; i < lista->tamanho-1; i++, j = j->prox);
    Celula* tmp = j->prox;
    j->prox = j->prox->prox;
    tmp->prox = NULL;
    j = NULL;
    free(tmp);
    return resp;
}
// ------------------------- SWAP NODES IN PAIRS -----------------------------------------------------
void swapNumbers(Celula* x, Celula* y){
    int tmp = x->elemento;
    x->elemento = y->elemento;
    y->elemento = tmp;
}
void toNodesInPairs(LinkedList* lista){
    Celula* i = lista->primeiro->prox;
    while (i != NULL && i->prox != NULL)
    {
        swapNumbers(i, i->prox);
        i = i->prox->prox;
    }
}

int main(){
    int arr[] = {1, 2, 3, 4};
    int tam = sizeof(arr)/sizeof(arr[0]);

    LinkedList* lista = criarLista();

    for(int i = 0; i < tam; i++){
        inserirFim(lista, arr[i]);
    }
    toNodesInPairs(lista);
    mostrar(lista);

    return 0; 
}