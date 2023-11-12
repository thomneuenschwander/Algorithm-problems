#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define TAM 3

typedef struct No{
    struct No *esq, *dir;
    int elemento;
}No;

No* criarNo(int x){
    No* new = malloc(sizeof(No));
    new->esq = new->dir = NULL;
    new->elemento = x;
    return new;
}
// ---------------------- BST ------------------------------

typedef struct BST {
    struct No* raiz;
}BST;

BST* criarBST(){
    BST* new = malloc(sizeof(BST));
    new->raiz = NULL;
    return new;
}
// ------------------------------------------------------------
No* inserir(int x, No* i){
    if(i == NULL){
        i = criarNo(x);
    }else if(x < i->elemento){
        i->esq = inserir(x, i->esq);
    }else if(x >= i->elemento){
        i->dir = inserir(x, i->dir);
    }
    return i;
}

void mostrar(No* i){
    if(i != NULL){
        mostrar(i->esq);
        printf("%d ", i->elemento);
        mostrar(i->dir);
    }
}
// --------------------- SAME TREE ---------------------------------------

int sameTree(No* r1, No* r2) {
    if(r1 == NULL && r2 == NULL){
        return 1;
    }else if(r1 == NULL || r2 == NULL){
        return 0;
    }else if(r1->elemento != r2->elemento){
        return 0;
    }else{
        return sameTree(r1->esq, r2->esq) && sameTree(r1->dir, r2->dir);
    }
}

// -----------------------------------------------------------------------

int main(){

    printf("Arvore 1:  \n");
    BST* a1 = criarBST();
    for(int i = 0; i < TAM; i++)
    {
        int num;
        scanf("%d", &num);
        a1->raiz = inserir(num, a1->raiz);
    }

    printf("Arvore 2:  \n");
    BST* a2 = criarBST();
    for(int i = 0; i < TAM; i++)
    {
        int num;
        scanf("%d", &num);
        a2->raiz = inserir(num, a2->raiz);
    }
    No* r1 = a1->raiz;
    No* r2 = a2->raiz;
    if(sameTree(r1, r2)){
        printf("true\n");
    }else{
        printf("false\n");
    }

    return 0;
}