#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicatesSpaces(char* str){
    int size = strlen(str);
    char* newStr = malloc(101*sizeof(char));
    int index = 0;
    for(int i = 0; i < size; i++){
        if(!(str[i] == ' ' && str[i+1] == ' ')){
            newStr[index++] = str[i];
        }
    }
    newStr[index] = '\0';
    return newStr;
}
int numSpaces(char* str, int size){
    int res = 0;
    for(int i = 0; i < size; i++){
        if(str[i] == ' ' && str[i+1] != '\0'){
            res++;
        }
    }
    return res;
}
char** split(char* str, int* newLine, int* newCol){
    int size = strlen(str);
    int spaces = numSpaces(str, size);
    int numWords = spaces+1;

    char** arrStr = malloc(numWords*sizeof(char*));
    for(int i = 0; i < numWords; i++){
        arrStr[i] = malloc(51*sizeof(char));
    }
    int line = 0;
    int col = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' '){
            arrStr[line][col] = '\0';
            col = 0;
            line++;
        }else{
            arrStr[line][col] = str[i]; 
            col++;
        }
    }
    arrStr[line][col] = '\0';
    *newLine = line + 1;
    *newCol = col;
    return arrStr;
}

char* reverseWords(char* s) {
    char* newStr = removeDuplicatesSpaces(s);

    int l = 0;
    int c = 0;
    char** m = split(newStr, &l, &c);
    
    char* str = malloc(101*sizeof(char));
    int index = 0;

    for(int i = l - 1; i >= 0; i--){

        for(int j = 0; m[i][j] != '\0'; j++){
            str[index++] = m[i][j];
        }
        if (i > 0) {
            str[index++] = ' ';
        }
    }
    str[index] = '\0';
    return str;
}


int main(){
    char str[101];
    scanf(" %[^\n]", str);

    char* res = reverseWords(str);
    
    printf("%s\n", res);
    return 0;
}