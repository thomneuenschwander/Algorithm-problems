#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int* arr;
    int n;
}Stack;

Stack* createStack(int size) {
    Stack* new = malloc(sizeof(Stack));
    new->n = 0;
    new->arr = malloc(size*sizeof(int));
    return new;
}
void push(int number, Stack* stack) {
    stack->arr[stack->n++] = number;
}
void pop(Stack* stack){
    stack->n--;
}
int max(Stack* stack){
    int max = 0;
    for(int i = 0; i < stack->n; i++){
        if(stack->arr[i] > max){
            max = stack->arr[i];
        }
    }
    return max;
}
int min(Stack* stack){
    int min = max(stack);
    for(int i = 0; i < stack->n; i++){
        if(stack->arr[i] < min){
            min = stack->arr[i];
        }
    }
    return min;
}

int main(){
    int n;
    scanf("%d", &n);

    Stack* stack = createStack(n);

    while(n--)
    {
        char command[11];
        int v;

        scanf("%s %d", command, &v);

        if(strcmp(command, "PUSH") == 0){
            push(v, stack);
        }else if(strcmp(command, "POP") == 0){
            pop(stack);
        }else if(strcmp(command, "MIN") == 0)
        {
            printf("%d\n", min(stack));

        }else
        {
            printf("Invalid command!");
        }
    }

    free(stack->arr);
    free(stack);
    return 0;
}