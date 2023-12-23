#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cell{
    int num;
    struct Cell* next;
}Cell;

void rotateRight(struct Cell** head, int k) {
    while(k--){
        Cell* j = (*head);
        for(; j->next->next != NULL; j = j->next);
        Cell* curr = j->next;
        j->next = curr->next;
        curr->next = (*head)->next;
        (*head)->next = curr;

    }
}


int main(){
    int N;
    scanf("%d", &N);
    Cell* head= malloc(sizeof(Cell));
    Cell* tail = head;
    head->next = tail->next = NULL;

    while (N--)
    {
        int num;
        scanf("%d", &num);
        tail->next = malloc(sizeof(Cell));
        tail->next->num = num;
        tail = tail->next;
        tail->next = NULL;
    }
    int k;
    scanf("%d", &k);
    rotateRight(&head, k);
 
    tail = head->next;
    while (tail != NULL)
    {
        printf("%d ", tail->num);
        tail = tail->next;
    }
    

    return 0;
}