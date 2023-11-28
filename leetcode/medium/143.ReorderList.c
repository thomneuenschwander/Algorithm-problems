#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    struct Cell* next;
    int element;
}Cell;

Cell* createCell(int x){
    Cell* new = malloc(sizeof(Cell));
    new->element = x;
    new->next = NULL;
    return new;
}

void insertEnd(Cell** tail, int x){
    (*tail)->next = createCell(x);
    (*tail) = (*tail)->next;
}

void show(Cell* head){
    Cell* i = head->next;
    while(i != NULL)
    {
        printf("%d ", i->element);
        i = i->next;
    }
    printf("\n");
}

void reverse(Cell** cell) {
    Cell* i = (*cell);
    Cell* j = (*cell)->next;

    while (j->next != NULL)
    {
        Cell* current = j->next;
        j->next = current->next;
        current->next = i->next;
        i->next = current;
    }
}
Cell* tortoiseAndHare(Cell* head){
    Cell* tortoise = head,* hare = head; 
    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    return tortoise;
}

void reorderList(Cell** head) {
    Cell* mid = tortoiseAndHare((*head));

    reverse(&mid);

    Cell* i = (*head)->next;
    Cell* j = mid->next;

    while(i != mid){
        mid->next = j->next;
        j->next = i->next;
        i->next = j;
        i = i->next->next;
        j = mid->next;
    }
}

int main () {
    
    Cell* head = malloc(sizeof(Cell));
    head->next = NULL;
    Cell* tail = head;

    int N;
    scanf("%d", &N);

    while(N != 0)
    {
        insertEnd(&tail, N);

        scanf("%d", &N);
    }

    reorderList(&head);

    show(head);
    return 0;
}