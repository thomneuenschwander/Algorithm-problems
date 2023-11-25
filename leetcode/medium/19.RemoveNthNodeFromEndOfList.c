#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    struct Cell* next;
    int element;
}Cell;

Cell* crateCell(int x) {
    Cell* new = malloc(sizeof(Cell));
    new->element = x;
    new->next = NULL;
    return new;
}

void show(Cell* head){
    Cell* i = head->next;
    while (i != NULL)
    {
        printf("%d ", i->element);
        i = i->next;
    }
    printf("\n");
}

void reverseLinkedList(Cell** head) {
    if((*head) == NULL){ return; }

    Cell* i = (*head);
    Cell* j = (*head)->next;

    while(j->next != NULL){
        Cell* current = j->next;
        j->next = current->next;
        current->next = i->next;
        i->next = current;
    }
}

Cell* removeNthFromEnd(Cell** head, int n) {
    reverseLinkedList(head);
    Cell* i = (*head);
    for(int j = 1; j < n; j++, i = i->next);
    Cell* resp = i->next;
    Cell* tmp = i->next;
    i->next = i->next->next;
    tmp->next = NULL;
    reverseLinkedList(head);
    return resp;
}

int main() {
    int N;
    scanf("%d", &N);

    Cell* head = malloc(sizeof(Cell));
    head->next = NULL;
    Cell* tail = head;

    while(N != 0)
    {
        tail->next = crateCell(N);
        tail = tail->next;

        scanf("%d", &N);
    }
    int pos;
    scanf("%d", &pos);
    removeNthFromEnd(&head, pos);
    show(head);

    return 0;
}