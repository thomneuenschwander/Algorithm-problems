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
typedef struct LinkedList {
    struct Celula* primeiro, *ultimo;
    int tamanho;
}LinkedList;

LinkedList* criarLinkedList(){
    LinkedList* new = malloc(sizeof(LinkedList));
    new->primeiro = criarCelula(0);
    new->ultimo = new->primeiro;
    new->tamanho = 0;
    return new;
}
// -----------------------------------------------------------------------
void mostrar(LinkedList* lista){
    Celula* i = lista->primeiro->prox;
    for(; i != NULL; i = i->prox){
        printf("%d ", i->elemento);
    }
    printf("\n");
}
void mostrarBackwards(LinkedList* lista){
    int ult = (lista->tamanho);
    while (ult--)
    {
        Celula* j = lista->primeiro->prox;
        for(int i = 0; i < ult; i++, j = j->prox);
        printf("%d ", j->elemento);
    }
    
}
void inserir(LinkedList* lista, int x){
    lista->ultimo->prox = criarCelula(x);
    lista->ultimo = lista->ultimo->prox;
    lista->tamanho++;
}
// ------------------- ADD TWO NUMBERS -----------------------------------
LinkedList* addTwoNumbers(LinkedList* l1, LinkedList* l2){

    float soma1 = 0;

    int index = (l1->tamanho);
    while (index--)
    {
        Celula* j = l1->primeiro->prox;
        int i = 0;
        for(; i < index; i++, j = j->prox);

        soma1 += pow(10, i)*j->elemento;
    }

    float soma2 = 0;

    index = (l2->tamanho);
    while (index--)
    {
        Celula* j = l2->primeiro->prox;
        int i = 0;
        for(; i < index; i++, j = j->prox);

        soma2 += pow(10, i)*j->elemento;
    }

    int result = (int)(soma1+soma2);

    LinkedList* new = criarLinkedList();

    while(result > 0){
        int current = result % 10;
        new->ultimo->prox = criarCelula(current);
        new->ultimo = new->ultimo->prox;
        new->tamanho++;
        result /= 10;
    }
    return new;
}

int main()
{
    int arr1[] = {2, 4, 3};
    LinkedList* l1 = criarLinkedList();
    for(int i = 0; i < 3; i++)
    {
        inserir(l1, arr1[i]);
    }
  // -------------------------------------------
    int arr2[] = {5, 6, 4};
    LinkedList* l2 = criarLinkedList();
    for(int i = 0; i < 3; i++)
    {
        inserir(l2, arr2[i]);
    }
  // --------------------------------------------
    LinkedList* new = addTwoNumbers(l1, l2);
    mostrar(new);
    return 0;
}