#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLastWord(char* s) {
    int size = strlen(s);
    int count = 0;
    
    printf("%c\n", s[size-1]);
    int i = size-1;
    for(; s[i] == ' '; i--);
    for(; i >= 0; i--){
        if(s[i] == ' '){
            break;
        }else{
            count++;
        }
    }

    return count;
}

int main(){
    char str[101];
    scanf(" %[^\n]", str);

    printf("%d\n", lengthOfLastWord(str));

    return 0;
}