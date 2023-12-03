#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* insert(TreeNode* i, int number) {
    if(i == NULL) {
        i = malloc(sizeof(TreeNode));
        i->left = i->right = NULL;
        i->val = number;

    }else if(number < i->val){
        i->left = insert(i->left, number);
    }else if(number > i->val){
        i->right = insert(i->right, number);
    }

    return i;
}
void show(TreeNode* i){
    if(i != NULL){
        show(i->left);
        printf("%d ", i->val);
        show(i->right);
    }
}
// ----------------------------------------------
typedef struct Cell
{
    struct TreeNode* element;
    struct Cell* next;
}Cell;

Cell* createCel(TreeNode* x){
    Cell* new = malloc(sizeof(Cell));
    new->element = x;
    new->next = NULL;
    return new;
}

typedef struct Queue
{
    struct Cell* head;
    struct Cell* tail;
    int size;
}Queue;

Queue* createQueue(){
    Queue* new = malloc(sizeof(Queue));
    new->head = malloc(sizeof(Cell));
    new->head->next = NULL;
    new->tail = new->head;
    new->size = 0;
    return new;
}

void add(Queue* queue, TreeNode* x){
    queue->tail->next = createCel(x);
    queue->tail = queue->tail->next;
    queue->size++;
}

TreeNode* poll(Queue* queue){
    Cell* tmp = queue->head->next;
    TreeNode* resp = tmp->element;
    queue->head->next = queue->head->next->next;
    tmp->next = NULL;
    free(tmp);
    queue->size--;
    return resp;
}

void showQueue(Queue* queue){
    Cell* i = queue->head->next;
    while (i != NULL)
    {
        printf("%d ", i->element->val);
        i = i->next;
    }
    printf("\n");
}
TreeNode* getLestValue(Queue* queue) {
    Cell* i = queue->head->next;
    for(; i->next != NULL; i = i->next);
    return i->element;
}

void rightSideView(TreeNode* root) {

    Queue* queue = createQueue();

    add(queue, root);
    
    while(queue->size > 0) {
        TreeNode* j = poll(queue);
        
        printf("%d ", j->val);

        if(j->left != NULL) {
            add(queue, j->left);
        }
        
        if(j->right != NULL) {
            add(queue, j->right);
        }
    }
}


int main(){

    TreeNode* root = NULL;

    int num;
    scanf("%d", &num);
    while(num != 0)
    {
        root = insert(root, num);
        scanf("%d", &num);
    }
    printf("\n\n");
    rightSideView(root);
    printf("\n\n");
    show(root);
    return 0;
}