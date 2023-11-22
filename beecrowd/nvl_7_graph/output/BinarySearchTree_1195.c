#include <stdio.h>
#include <stdlib.h>

typedef struct Nodle{
    int element;
    struct Nodle* left, *rigth;
}Nodle;

Nodle* createNodle(int x){
    Nodle* new = malloc(sizeof(Nodle));
    new->left = new->rigth = NULL;
    new->element = x;
    return new;
}

void insertREC(Nodle** father, Nodle** i, int x){
    if(*i == NULL){
        if(x < (*father)->element){
            (*father)->left = createNodle(x);
        }else{
            (*father)->rigth = createNodle(x);
        }
    }else if(x < (*i)->element){
        insertREC(i, &(*i)->left, x);
    }else{
        insertREC(i, &(*i)->rigth, x);
    }
}

void insert(Nodle** root, int x){
    if((*root) == NULL){
        (*root) = createNodle(x);
    }else if(x < (*root)->element){
        insertREC(root, &(*root)->left, x);
    }else{
        insertREC(root, &(*root)->rigth, x);
    }
}

void preOrder(Nodle* i){
    if(i != NULL){
        printf("%d ", i->element);
        preOrder(i->left);
        preOrder(i->rigth);
    }
}

void inOrder(Nodle* i){
    if(i != NULL){
        inOrder(i->left);
        printf("%d ", i->element);
        inOrder(i->rigth);
    }
}

void postOrder(Nodle* i){
    if(i != NULL){
        postOrder(i->left);
        postOrder(i->rigth);
        printf("%d ", i->element);
    }
}


int main(){
    int C, currentCase = 1;
    scanf("%d", &C);

    while (currentCase <= C)
    {
        int N;
        scanf("%d", &N);

        Nodle* root = NULL;

        for(int i = 0; i < N; i++)
        {
            int num;
            scanf("%d", &num);

            insert(&root, num);
        }

        printf("Case %d\n", currentCase);

        printf("Pre.: ");
        preOrder(root);
        printf("\n");
        printf("In..: ");
        inOrder(root);
        printf("\n");
        printf("Post: ");
        postOrder(root);
        printf("\n");

        currentCase++;
    }

    return 0;
}