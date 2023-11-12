#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct Celula
{
    struct Celula* prox;
    int elemento;
}Celula;

Celula* criarCelula(int x){
    Celula* new = malloc(sizeof(Celula));
    new->prox = NULL;
    new->elemento = x;
    return new;
}

typedef struct LinkedList
{
    struct Celula* primeiro,* ultimo;
    int tamanho;
}LinkedList;

LinkedList* criarLista(){
    LinkedList* new = malloc(sizeof(LinkedList));
    new->primeiro = criarCelula(0);
    new->ultimo = new->primeiro;
    new->tamanho = 0;
    return new;
}

void inserirFim(LinkedList* l, int x){
    l->ultimo->prox = criarCelula(x);
    l->ultimo = l->ultimo->prox;
    l->tamanho++;
}
void mostrar(LinkedList* l){
    Celula* i = l->primeiro->prox;
    while (i != NULL)
    {
        printf("%d ", i->elemento);
        i = i->prox;
    }
    printf("\n");
}
// ----------------------- REMOVE DUPLICATES FROM SORTED LIST --------------------------------
void removeDuplicates(Celula* head){
    Celula* i = head;
    for(; i->prox != NULL; i = i->prox)
    {
        int count = 0;
        Celula* j = head->prox;
        for(; j != NULL; j = j->prox){
            if(i->prox->elemento == j->elemento){
                count++;
            }
        }
        if(count > 1){
            Celula* tmp = i->prox;
            i->prox = i->prox->prox;
            tmp->prox = NULL;
            free(tmp);
        }
    }
}
// -------------------------------------------------------------------------------------------

int main(){

    LinkedList* lista = criarLista();

    printf("Digite a quantidade de numeros para inserir: \n");
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        inserirFim(lista, num);
    }
    removeDuplicates(lista->primeiro);
    mostrar(lista);
    return 0;
}