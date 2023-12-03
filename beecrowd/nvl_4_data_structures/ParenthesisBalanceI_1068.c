#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isCorrect(char* str, int size){
    int open = 0, close = 0;

    for(int i = 0; i < size; i++)
    {
        if(str[i] == '(') {
            open++;
        }else if(str[i] == ')'){
            close++;

            if(close > open){
                return 0;
            }
        }
    }
    if(open != close){
        return 0;
    }
    return 1;
}

int main(){

    FILE* file = fopen("C:\\Users\\Pichau\\Desktop\\Algorithm-problems\\beecrowd\\nvl_4_data_structures\\arqs\\ParenthesisBalanceI_1068.txt", "r");
    if(file == NULL){
        printf("cannot open file\n");
        return 1;
    }
    char expression[1001];
    while(fgets(expression, sizeof(expression), file) != NULL)
    {
        int size = strlen(expression);

        if(isCorrect(expression, size)){
            printf("correct\n");
        }else {
            printf("incorrect\n");
        }
    }
    fclose(file);
    return 0;
}