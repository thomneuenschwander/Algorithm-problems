#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>


bool isDifficult(char* str, int tam){
    char vogais[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int vogTam = sizeof(vogais)/sizeof(vogais[0]);
    int k = 3;

    for(int i = 0; i <= tam-k-1; i++){
        int count = 0;
        for(int j = i; j < i+k; j++){
            int vezes = 0;
            for(int z = 0; z < vogTam; z++){
                if(str[j] != vogais[z]){
                    vezes++;
                }
            }
            if(vezes == vogTam){
                count++;
            }
        }
        if(count == k){
            return true;
        }
    }
    return false;
}

int main(){

    int N;
    scanf("%d", &N);

    while(N--)
    {
        char* str = malloc(31*sizeof(char));
        scanf("%s", str);

        int tam = strlen(str);
        str = realloc(str, (tam+1)*sizeof(char));

        if(isDifficult(str, tam))
        {
            printf("%s nao eh facil\n", str);
        }else
        {
            printf("%s eh facil\n", str);
        }
        
        free(str);
    }

    return 0;
}