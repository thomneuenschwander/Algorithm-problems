#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int element;
    struct Cell* next;
}Cell;

Cell* createCell(int x){
    Cell* cell = malloc(sizeof(Cell));
    cell->element = x;
    cell->next = NULL;
    return cell;
}

typedef struct StackGame_1522
{
    struct Cell* top;
    int size;
}Stack;

Stack* createStack(){
    Stack* stack = malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}
void show(Stack* stack){
    Cell* i = stack->top;
    while(i != NULL){
        printf("%d\n", i->element);
        i = i->next;
    }
}
void push(int x, Stack* stack){
    Cell* tmp = createCell(x);
    tmp->next = stack->top;
    stack->top = tmp;
    tmp = NULL;
    stack->size++;
}

void pop(Stack* stack){
    if(stack->top == NULL){
        return;
    }
    Cell* tmp = stack->top;
    stack->top = stack->top->next;
    tmp->next = NULL;
    free(tmp);
}

int main(){

    int N;
    scanf("%d", &N);

    while(N != 0)
    {
        Stack* s1 = createStack();
        Stack* s2 = createStack();
        Stack* s3 = createStack();

        for(int i = 0; i < N; i++){
            int n1, n2, n3;
            scanf("%d %d %d", &n1, &n2, &n3);
            push(n1, s1);
            push(n2, s2);
            push(n3, s3);
        }
        int can = 1;
       while(s1->top != NULL)
       {
        int total = s1->top->element + s2->top->element + s3->top->element;
        if(total % 3 != 0){
            can = 0;
            break;
        }else{
            pop(s1);
            pop(s2);
            pop(s3);
        } 
       }

        printf("%d\n", can);

        scanf("%d", &N);
    }

    return 0;
}