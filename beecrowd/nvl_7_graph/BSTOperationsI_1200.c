#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodle {
    char element;
    struct Nodle* left,* right;
}Nodle;

Nodle* createNodle(char letter){
    Nodle* new = malloc(sizeof(Nodle));
    new->element = letter;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Nodle* insert(Nodle** root, char ch){
    if(*root == NULL){
        *root = createNodle(ch);
    }else if (ch < (*root)->element){
        (*root)->left = insert(&(*root)->left, ch);
    }else if (ch > (*root)->element){
        (*root)->right = insert(&(*root)->right, ch);
    }
    return *root;
}

void inOrder(Nodle* i){
    if(i != NULL){
        inOrder(i->left);
        printf("%c ", i->element);
        inOrder(i->right);
    }
}

void preOrder(Nodle* i){
    if(i != NULL){
        printf("%c ", i->element);
        preOrder(i->left);
        preOrder(i->right);
    }
}

void posOrder(Nodle* i){
    if(i != NULL){
        posOrder(i->left);
        posOrder(i->right);
        printf("%c ", i->element);
    }
}

int BinarySearch(Nodle* root, char ch){
    if(root == NULL){
        return 0;
    }else if(root->element == ch){
        return 1;
    }else if(ch < root->element){
        return BinarySearch(root->left, ch);
    }else{
        return BinarySearch(root->right, ch);
    }
}

int main() {
    FILE* arq = fopen("C:\\Users\\Pichau\\Desktop\\Algorithm-problems\\beecrowd\\nvl_7_graph\\arqs\\BSTOperationsI.txt", "r");

    if(arq == NULL){
        printf("Error!\n");
        return 1;
    }
    Nodle* root = NULL;

    char line[31];
    while(fgets(line, sizeof(line), arq) != NULL)
    {
        if(line[0] == 'I' && line[1] == ' '){
            root = insert(&root, line[2]);
        }
        else if(line[0] == 'P' && line[1] == ' '){
            if(BinarySearch(root, line[2])){
                printf("%c existe\n", line[2]);
            }else{
                printf("%c nao existe\n", line[2]);
            }
        }
        else if(line[0] == 'I' && line[1] == 'N'){
            inOrder(root);
            printf("\n");
        }
        else if(line[0] == 'P' && line[1] == 'R'){
            preOrder(root);
            printf("\n");
        }
        else if(line[0] == 'P' && line[1] == 'O'){
            posOrder(root);
            printf("\n");
        }
    }
    return 0;
}