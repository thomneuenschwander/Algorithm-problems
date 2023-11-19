#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Celula
{
    struct Celula* prox;
    char* string;
}Celula;

Celula* criarHead(){
    Celula* new = malloc(sizeof(Celula));
    new->prox = NULL;
    new->string = NULL;
    return new; 
}


Celula* criarCelula(char* str){
    Celula* new = malloc(sizeof(Celula));
    new->prox = NULL;
    new->string = malloc(strlen(str) + 1);
    strcpy(new->string, str);
    return new; 
}

void show(Celula* head){
    Celula* i = head->prox;
    while(i != NULL){
        printf("%s ", i->string);
        i = i->prox;
    }
    printf("\n");
}

void add(Celula** tail, char* str) {
    (*tail)->prox = criarCelula(str);
    *tail = (*tail)->prox;
}

char* LongestCommonPrefix(Celula* head){
    char* commonPrefix = malloc(31*sizeof(char));
    
    char* piv = head->prox->string;
    int j = 0;

    for(Celula* i = head->prox->prox; i != NULL && i->string[j] == piv[j]; i = i->prox, j++){
        commonPrefix[j] = piv[j];
    }
    commonPrefix[j] = '\0';

    return commonPrefix;
}


int main() {
    Celula* head = criarHead();
    Celula* tail = head;

    char input[31];
    scanf("%s", input);

    while(strcmp(input, "FIM") != 0){
        add(&tail, input);
        scanf("%s", input);
    }
    printf("\n Strings input: ");
    show(head);


    char* result = LongestCommonPrefix(head);
    printf("\n Longest Common Prefix:  %s\n\n", result);


    return 0;
}