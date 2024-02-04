#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

Node* newNode(int x){
    Node* newNode = malloc(sizeof(Node));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}
void showList(Node* i){
    i = i->next; 
    printf("[");
    while (i != NULL)
    {
        printf(" %d", i->val);
        if(i->next != NULL){
            printf(",");
        }
        i = i->next;
    }
    printf(" ]\n");
}

Node* reverseKGroup(Node* head, int k){
    Node* i = head;
    Node* ii = head;
    Node* j = head->next;
    Node* index = head->next;
    int canMove = 1;

    while (j->next != NULL){
        for(int l = 0; l < k; l++){
            if(index == NULL){
                canMove = 0;
                break;
            }else{
                index = index->next;
            }
        }
        if(!canMove) { break; }
        while (j->next != index)
        {
            Node* current = j->next;
            j->next = current->next;
            current->next = ii->next;
            ii->next = current;
        }
        ii = j;
        j = index;
    }
    return i;
}

int main()
{
    Node* head = malloc(sizeof(Node));
    head->next = NULL;
    Node* tail = head;

    printf("Digit list - (enter -1 to stop loop)\n");
    int num;
    scanf("%d", &num);

    while (num >= 0)
    {
        tail->next = newNode(num);
        tail = tail->next;
        scanf("%d", &num);
    }

    int k;
    scanf("%d", &k);

    showList(head);
    printf("\t|\n\t|\n\tV\n");
    Node* reverted = reverseKGroup(head, k);
    showList(reverted); 
    return 0;
}
